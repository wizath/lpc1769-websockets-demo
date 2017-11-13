#include "http_server.h"

#include "lwip/tcp.h"

static struct tcp_pcb * xConnectedUsers[8] = { 0 };
static uint8_t xConnectionCount = 0;

uint8_t websocket_broadcast(const uint8_t *data, uint16_t len, uint8_t mode)
{
	uint8_t send_count = 0;
	err_t err;

	for (int i = 0; i < 8; i++) {
		if (xConnectedUsers[i] != NULL) {
			err = websocket_write(xConnectedUsers[i], data, len, mode);
			if (err == ERR_OK) send_count++;
		}
	}

	return send_count;
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
	data[data_len] = '\0';
    printf("[websocket_callback]:\n %d - %s\n", (int) data_len, (char*) data);

	char response[64];
    if (!strcmp((char*) data, "ping")) {
    	int len = snprintf(response, sizeof (response), "{\"response\" : \"%s\"}", "pong");
    	if (len < sizeof (response))
    		websocket_write(pcb, (unsigned char *) response, len, WS_TEXT_MODE);
    } else if (!strcmp((char*) data, "bcast")) {
    	int len = snprintf(response, sizeof (response), "{\"response\" : \"%s\"}", "broadcast");
    	if (len < sizeof (response))
    		websocket_broadcast((uint8_t*)response, len, WS_TEXT_MODE);
    }
}

bool websocket_user_append(struct tcp_pcb * pcb)
{
	if (xConnectionCount < 8) {
		for (int i = 0; i < 8; i++) {
			if (xConnectedUsers[i] == NULL) {
				xConnectedUsers[i] = pcb;
				xConnectionCount++;
				return true;
			}
		}
	}

	return false;
}

bool websocket_user_remove(struct tcp_pcb * pcb)
{
	for (int i = 0; i < 8; i++) {
		if (xConnectedUsers[i] == pcb) {
			xConnectedUsers[i] = NULL;
			xConnectionCount--;
			printf("removed user %d\n", i+1);
			return true;
		}
	}

	return false;
}

/**
 * This function is called when new websocket is open and
 * creates a new websocket_task if requested URI equals '/stream'.
 */
void websocket_open_cb(struct tcp_pcb *pcb, const char *uri)
{
    printf("WS URI: %s\n", uri);

    if (websocket_user_append(pcb)) {
    	printf("[log] connected userd = %d\n", xConnectionCount);
    }

    if (!strcmp(uri, "/stream")) {
        printf("request for streaming\n");
        xTaskCreate(&websocket_task, "websocket_task", 256, (void *) pcb, 2, NULL);
    }
}

void websocket_close_cb(struct tcp_pcb *pcb)
{
	printf("websocket close conn\n");
	if (websocket_user_remove(pcb)) {
		printf("remove ok\n");
	}
}

void httpd_task(void *pvParameters)
{
    /* register handlers and start the server */
    websocket_register_callbacks((tWsOpenHandler) websocket_open_cb, (tWsCloseHandler) websocket_close_cb, (tWsHandler) websocket_cb);
    httpd_init();

    for (;;) {
    	vTaskDelay(configTICK_RATE_HZ);
    }
}
