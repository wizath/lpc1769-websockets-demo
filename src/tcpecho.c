/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#include "tcpecho.h"

#include "lwip/opt.h"

#if LWIP_NETCONN

#include "lwip/sys.h"
#include "lwip/api.h"

server_state_t server = {
	.conn = NULL,
	.state = STATE_IDLE
};

static void api_handler(struct netconn * newconn, void * data, uint16_t length)
{
	err_t err;

	err = netconn_write(newconn, data, length, NETCONN_COPY);
	if (err != ERR_OK)
		printf("tcp_server: netconn_write: error \"%s\"\n", lwip_strerr(err));
}

static void tcpecho_thread(void *arg)
{
	struct netconn *conn, *newconn;
	err_t err;
	LWIP_UNUSED_ARG(arg);

	/* Create a new connection identifier. */
	conn = netconn_new(NETCONN_TCP);

	/* Bind connection to well known port number 7. */
	netconn_bind(conn, NULL, 7777);

	/* Tell connection to go into listening mode. */
	netconn_listen(conn);

	while (1) {

		/* Grab new connection. */
		err = netconn_accept(conn, &newconn);

		server.state = STATE_CONNECTED;
		server.conn = newconn;

		printf("[log] accepted new connection %p\n", newconn);

		/* Process the new connection. */
		if (err == ERR_OK)
		{
			struct netbuf *buf;
			void *data;
			u16_t len;

			while ((err = netconn_recv(newconn, &buf)) == ERR_OK) {
				do {
					netbuf_data(buf, &data, &len);
					api_handler(newconn, data, len);

				} while (netbuf_next(buf) >= 0);
					netbuf_delete(buf);
			}

			server.state = STATE_IDLE;
			server.conn = NULL;

			printf("[log] connection dropped\n");

			/* Close connection and discard connection identifier. */
			netconn_close(newconn);
			netconn_delete(newconn);
		}
	}
}


void tcpecho_init(void)
{
	sys_thread_new("tcp_thread", tcpecho_thread, NULL, DEFAULT_THREAD_STACKSIZE + 512UL, DEFAULT_THREAD_PRIO + 4);
}

#endif /* LWIP_NETCONN */
