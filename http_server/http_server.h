/*
 * http_server.h
 *
 *  Created on: Nov 13, 2017
 *      Author: wizath
 */

#ifndef HTTP_SERVER_H_
#define HTTP_SERVER_H_

#include "config.h"
#include "httpd.h"

void httpd_task(void *pvParameters);

typedef struct
{
	uint8_t * data;
	uint8_t length;
	uint8_t mode;
} msg_t;


#endif /* HTTP_SERVER_H_ */
