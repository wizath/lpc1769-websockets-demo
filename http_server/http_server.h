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

enum {
    SSI_UPTIME,
    SSI_FREE_HEAP,
    SSI_LED_STATE
};

void httpd_task(void *pvParameters);

#endif /* HTTP_SERVER_H_ */
