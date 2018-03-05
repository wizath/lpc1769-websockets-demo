#include "http_server.h"

#include "lwip/tcp.h"

static struct tcp_pcb * xConnectedUsers[8] = { 0 };
static uint8_t xConnectionCount = 0;
static QueueHandle_t xMsgQueue;

uint8_t websocket_broadcast(const uint8_t *data, uint16_t len, uint8_t mode)
{
	msg_t pxMessage = {
		.data = data,
		.length = len,
		.mode = mode
	};

	return xQueueSend(xMsgQueue, ( void * ) &pxMessage, 0);
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
    printf("[websocket_callback]:\ndata[%d] %s\n", (int) data_len, (char*) data);

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
    printf("[log] websockets connection open, uri: %s\n", uri);

    if (websocket_user_append(pcb)) {
    	printf("[log] user connected, user count %d\n", xConnectionCount);
    }
}

void websocket_close_cb(struct tcp_pcb *pcb)
{
	printf("[log] websocket close connection\n");
	if (websocket_user_remove(pcb)) {
		printf("[log] user removed from list\n");
	}
}

void httpd_task(void *pvParameters)
{
	msg_t msg;

    /* register handlers and start the server */
	xMsgQueue = xQueueCreate(16, sizeof( msg_t ));
    websocket_register_callbacks((tWsOpenHandler) websocket_open_cb, (tWsCloseHandler) websocket_close_cb, (tWsHandler) websocket_cb);
    httpd_init();

    for (;;) {
    	while (xQueueReceive(xMsgQueue, &msg, portMAX_DELAY)) {
    		for (int i = 0; i < 8; i++) {
				if (xConnectedUsers[i] != NULL)	websocket_write(xConnectedUsers[i], msg.data, msg.length, msg.mode);
			}
    	}
    }
}

err_t httpd_post_begin(void *connection, const char *uri, const char *http_request,
                       u16_t http_request_len, int content_len, char *response_uri,
                       u16_t response_uri_len, u8_t *post_auto_wnd)
{
	return ERR_OK;
}


err_t httpd_post_receive_data(void *connection, struct pbuf *p)
{
	return ERR_OK;
}


void httpd_post_finished(void *connection, char *response_uri, u16_t response_uri_len)
{
}
