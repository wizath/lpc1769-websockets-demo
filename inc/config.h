/*
 * config.h
 *
 *  Created on: Aug 8, 2017
 *      Author: rst
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Standard includes. */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

/* FreeRTOS includes. */
#include "timers.h"
#include "queue.h"
#include "semphr.h"

#define DEBUGSTR(...) 	taskENTER_CRITICAL(); \
						printf(__VA_ARGS__); \
						taskEXIT_CRITICAL()

#define BOARD_LED0	0, 6
#define BOARD_LED1	0, 7
#define BOARD_LED2	0, 8
#define BOARD_LED3	0, 9

#define ISM_PWR		2, 10
#define ISM_UART	LPC_UART3


#endif /* CONFIG_H_ */
