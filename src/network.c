/*
 * network.c
 *
 *  Created on: Aug 8, 2017
 *      Author: rst
 */

#include "lwipopts.h"
#include "network.h"
#include "lpc17xx_emac.h"
#include "httpd.h"

extern err_t ethernetif_init(struct netif *xNetIf);
extern int32_t EMAC_CheckPHYStatus(uint32_t ulPHYState);
struct netif net_iface;

static void iface_callback(struct netif *iface)
{
	char ip[16] = {0}, gw[16] = {0}, mask[16] = {0};

	strcpy(ip, inet_ntoa(iface->ip_addr));
	strcpy(gw, inet_ntoa(iface->gw));
	strcpy(mask, inet_ntoa(iface->netmask));

	printf("Network interface is up, ip = %s, gw = %s, mask = %s\n", ip, gw, mask);
}

/* Called from the TCP/IP thread */
static void network_init(void *arg)
{
	ip_addr_t ipaddr, netmask, gw;

	/* Tell main thread TCP/IP init is done */
	*(s32_t *) arg = 1;

	uint32_t serial[4] = {3411378u, 346225u,75338765u, 43565432u};
	// XXX 0 and 1 bits are important, see wikipedia and don't spend hours for it again, stupid
	net_iface.hwaddr[0] = (serial[0] ^ serial[1] ^ (serial[2] >> 8u)) & 0xFC;
	net_iface.hwaddr[1] = (serial[1] ^ serial[2] ^ (serial[3] >> 16u)) & 0xFF;
	net_iface.hwaddr[2] = (serial[2] ^ serial[3] ^ (serial[1] >> 24u)) & 0xFF;
	net_iface.hwaddr[3] = (serial[3] ^ serial[0] ^ (serial[2] >> 8u)) & 0xFF;
	net_iface.hwaddr[4] = (serial[3] ^ serial[1] ^ (serial[0] >> 16u)) & 0xFF;
	net_iface.hwaddr[5] = (serial[2] ^ serial[0] ^ (serial[1] >> 24u)) & 0xFF;

#if LWIP_DHCP
	IP4_ADDR(&gw, 0, 0, 0, 0);
	IP4_ADDR(&ipaddr, 0, 0, 0, 0);
	IP4_ADDR(&netmask, 0, 0, 0, 0);
#else
	IP4_ADDR(&gw, 10, 1, 10, 1);
	IP4_ADDR(&ipaddr, 10, 1, 10, 234);
	IP4_ADDR(&netmask, 255, 255, 255, 0);
#endif

	netif_set_default(netif_add(&net_iface, &ipaddr, &netmask, &gw, NULL, ethernetif_init, tcpip_input));
	netif_set_status_callback(&net_iface, iface_callback);

#if LWIP_DHCP
	dhcp_start(&net_iface);
#else
	netif_set_up(&net_iface);
#endif
}

enum {
    SSI_UPTIME,
    SSI_FREE_HEAP,
    SSI_LED_STATE
};

int32_t ssi_handler(int32_t iIndex, char *pcInsert, int32_t iInsertLen)
{
    switch (iIndex) {
        case SSI_UPTIME:
            snprintf(pcInsert, iInsertLen, "%d",
                    xTaskGetTickCount() * portTICK_PERIOD_MS / 1000);
            break;
        case SSI_FREE_HEAP:
            snprintf(pcInsert, iInsertLen, "%d", (int) xPortGetFreeHeapSize());
            break;
        default:
            snprintf(pcInsert, iInsertLen, "N/A");
            break;
    }

    /* Tell the server how many characters to insert */
    return (strlen(pcInsert));
}

char *gpio_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
//    for (int i = 0; i < iNumParams; i++) {
//        if (strcmp(pcParam[i], "on") == 0) {
//            uint8_t gpio_num = atoi(pcValue[i]);
////            gpio_enable(gpio_num, GPIO_OUTPUT);
////            gpio_write(gpio_num, true);
//        } else if (strcmp(pcParam[i], "off") == 0) {
//            uint8_t gpio_num = atoi(pcValue[i]);
//            gpio_enable(gpio_num, GPIO_OUTPUT);
//            gpio_write(gpio_num, false);
//        } else if (strcmp(pcParam[i], "toggle") == 0) {
//            uint8_t gpio_num = atoi(pcValue[i]);
//            gpio_enable(gpio_num, GPIO_OUTPUT);
//            gpio_toggle(gpio_num);
//        }
//    }
    return "/index.ssi";
}

char *about_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    return "/about.html";
}

char *websocket_cgi_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    return "/websockets.html";
}

void websocket_task(void *pvParameter)
{
    struct tcp_pcb *pcb = (struct tcp_pcb *) pvParameter;

    for (;;) {
        if (pcb == NULL || pcb->state != ESTABLISHED) {
            printf("Connection closed, deleting task\n");
            break;
        }

        int uptime = xTaskGetTickCount() * portTICK_PERIOD_MS / 1000;
        int heap = (int) xPortGetFreeHeapSize();
        int led = 0;

        /* Generate response in JSON format */
        char response[64];
        int len = snprintf(response, sizeof (response),
                "{\"uptime\" : \"%d\","
                " \"heap\" : \"%d\","
                " \"led\" : \"%d\"}", uptime, heap, led);
        if (len < sizeof (response))
            websocket_write(pcb, (unsigned char *) response, len, WS_TEXT_MODE);

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

/**
 * This function is called when websocket frame is received.
 *
 * Note: this function is executed on TCP thread and should return as soon
 * as possible.
 */
void websocket_cb(struct tcp_pcb *pcb, uint8_t *data, u16_t data_len, uint8_t mode)
{
    printf("[websocket_callback]:\n%.*s\n", (int) data_len, (char*) data);

    uint8_t response[2];
    uint16_t val;

    switch (data[0]) {
        case 'A': // ADC
            /* This should be done on a separate thread in 'real' applications */
//            val = sdk_system_adc_read();
            break;
        case 'D': // Disable LED
//            gpio_write(LED_PIN, true);
            val = 0xDEAD;
            break;
        case 'E': // Enable LED
//            gpio_write(LED_PIN, false);
            val = 0xBEEF;
            break;
        default:
            printf("Unknown command\n");
            val = 0;
            break;
    }

    response[1] = (uint8_t) val;
    response[0] = val >> 8;

    websocket_write(pcb, response, 2, WS_BIN_MODE);
}

/**
 * This function is called when new websocket is open and
 * creates a new websocket_task if requested URI equals '/stream'.
 */
void websocket_open_cb(struct tcp_pcb *pcb, const char *uri)
{
    printf("WS URI: %s\n", uri);
    if (!strcmp(uri, "/stream")) {
        printf("request for streaming\n");
        xTaskCreate(&websocket_task, "websocket_task", 256, (void *) pcb, 2, NULL);
    }
}

void httpd_task(void *pvParameters)
{
    tCGI pCGIs[] = {
        {"/gpio", (tCGIHandler) gpio_cgi_handler},
        {"/about", (tCGIHandler) about_cgi_handler},
        {"/websockets", (tCGIHandler) websocket_cgi_handler},
    };

    const char *pcConfigSSITags[] = {
        "uptime", // SSI_UPTIME
        "heap",   // SSI_FREE_HEAP
        "led"     // SSI_LED_STATE
    };

    /* register handlers and start the server */
    http_set_cgi_handlers(pCGIs, sizeof (pCGIs) / sizeof (pCGIs[0]));
    http_set_ssi_handler((tSSIHandler) ssi_handler, pcConfigSSITags,
            sizeof (pcConfigSSITags) / sizeof (pcConfigSSITags[0]));
    websocket_register_callbacks((tWsOpenHandler) websocket_open_cb,
            (tWsHandler) websocket_cb);
    httpd_init();

    for (;;) {
    	vTaskDelay(configTICK_RATE_HZ);
    }
}

/* LWIP kickoff and PHY link monitor thread */
void vSetupIFTask(void *pvParameters)
{
	volatile s32_t tcpipdone = 0;
	int32_t physts, phystsprev;

	DEBUGSTR("LWIP TCP Server FreeRTOS Demo...\r\n");

	/* Wait until the TCP/IP thread is finished before
	   continuing or wierd things may happen */
	DEBUGSTR("Waiting for TCPIP thread to initialize...\r\n");
	tcpip_init(network_init, (void *) &tcpipdone);

	while (!tcpipdone)
	{
		vTaskDelay(configTICK_RATE_HZ / 1000);
	}

	xTaskCreate( httpd_task, "HTTP Daemon", configMINIMAL_STACK_SIZE + 128UL, NULL, tskIDLE_PRIORITY + 2UL, NULL );

	/* This loop monitors the PHY link and will handle cable events
	   via the PHY driver. */
	phystsprev = 0;
	while (1)
	{
		physts = EMAC_CheckPHYStatus(EMAC_PHY_STAT_LINK);

		if (physts != phystsprev)
		{
			phystsprev = physts;
 			if (physts == 1)
			{
				DEBUGSTR("Net up\n");
				tcpip_callback_with_block((tcpip_callback_fn) netif_set_link_up,
														  (void *) &net_iface, 1);
			} else {
				DEBUGSTR("Net down\n");
				tcpip_callback_with_block((tcpip_callback_fn) netif_set_link_down,
														  (void *) &net_iface, 1);
			}
		}

		vTaskDelay(configTICK_RATE_HZ / 4);
	}
}
