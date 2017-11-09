/*
 * network.h
 *
 *  Created on: Aug 8, 2017
 *      Author: rst
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include "config.h"

/* lwIP core includes */
#include "lwip/opt.h"
#include "lwip/tcpip.h"

/* lwIP netif includes */
#include "netif/etharp.h"
#include "lwip/netif.h"
#include "lwip/dhcp.h"
#include "lwip/inet.h"
#include "lwip/dns.h"

/* LWIP kickoff and PHY link monitor thread */
void vSetupIFTask(void *pvParameters);
void httpd_task(void *pvParameters);

#endif /* NETWORK_H_ */
