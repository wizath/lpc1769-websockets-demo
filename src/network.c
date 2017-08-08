/*
 * network.c
 *
 *  Created on: Aug 8, 2017
 *      Author: rst
 */

#include "lwipopts.h"
#include "network.h"
#include "lpc17xx_emac.h"

extern err_t ethernetif_init(struct netif *xNetIf);
extern int32_t EMAC_CheckPHYStatus(uint32_t ulPHYState);
struct netif net_iface;

static void iface_callback(struct netif *iface)
{
	char ip[16] = {0}, gw[16] = {0}, mask[16] = {0};

	strcpy(ip, inet_ntoa(iface->ip_addr));
	strcpy(gw, inet_ntoa(iface->gw));
	strcpy(mask, inet_ntoa(iface->netmask));

	DEBUGSTR("Network interface is up, ip = %s, gw = %s, mask = %s\n", ip, gw, mask);
}

/* Called from the TCP/IP thread */
static void network_init(void *arg)
{
	ip_addr_t ipaddr, netmask, gw;

	/* Tell main thread TCP/IP init is done */
	*(s32_t *) arg = 1;

	uint32_t serial[4] = {3464378u, 346225u,75278765u, 43565432u};
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
