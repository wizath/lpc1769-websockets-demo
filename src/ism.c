/*
 * ism.c
 *
 *  Created on: Aug 30, 2017
 *      Author: rst
 */

#include "ism.h"
#include "utils.h"
#include "tcpecho.h"

#include "lpc17xx_uart.h"
#include "lpc17xx_pinsel.h"

QueueHandle_t xUartRxQueue;

void ism_enable(void)
{
	gpio_pin_clear(ISM_PWR);
}

void ism_disable(void)
{
	gpio_pin_set(ISM_PWR);
}

void ism_init(void)
{
	UART_FIFO_CFG_Type 	UARTFIFOConfigStruct;
	UART_CFG_Type 		UARTConfigStruct;
	PINSEL_CFG_Type 	PinCfg;

	gpio_pin_cfg_output(ISM_PWR);
	ism_enable();

	/*
	 * Initialize UART3 pin connect
	 * ISM RXTX
	 */
	PinCfg.Funcnum = 3;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 28;
	PinCfg.Portnum = 4;
	PINSEL_ConfigPin(&PinCfg);

	PinCfg.Pinnum = 29;
	PINSEL_ConfigPin(&PinCfg);

	UART_ConfigStructInit(&UARTConfigStruct);
	UARTConfigStruct.Baud_rate = 115200;
	UART_Init( ( LPC_UART_TypeDef * ) ISM_UART, &UARTConfigStruct);

	UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);
	UART_FIFOConfig(ISM_UART, &UARTFIFOConfigStruct);

	UART_TxCmd( ( LPC_UART_TypeDef * ) ISM_UART, ENABLE);

	xUartRxQueue = xQueueCreate(5, sizeof( msg_t ));

	UART_IntConfig(ISM_UART, UART_INTCFG_RBR, ENABLE);
	UART_IntConfig(ISM_UART, UART_INTCFG_RLS, ENABLE);
	NVIC_EnableIRQ(UART3_IRQn);
}

#define MAX_LENGTH 40

static void uart_api_handler(uint8_t * data, uint8_t length, portBASE_TYPE xHigherPriorityTaskWoken)
{
	uint8_t cmd[3];
	uint8_t payload[40];

	sscanf((char*) data, "%s:%s", cmd, payload);

	printf("payload %s\n", payload);

	msg_t pxMessage = {
		.data = payload,
		.length = 10
	};

	xQueueSendFromISR( xUartRxQueue, ( void * ) &pxMessage, &xHigherPriorityTaskWoken );
}

void UART3_IRQHandler(void)
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
	uint32_t intsrc, tmp;
	intsrc = UART_GetIntId(ISM_UART);
	tmp = intsrc & UART_IIR_INTID_MASK;

	uint8_t tmpc;
	uint32_t rLen;
	static uint8_t data_array[MAX_LENGTH];
	static uint8_t index = 0;

	// Receive Data Available or Character time-out
	if ((tmp == UART_IIR_INTID_RDA) || (tmp == UART_IIR_INTID_CTI))
	{
		while (1)
		{
			// Call UART read function in UART driver
			rLen = UART_Receive(( LPC_UART_TypeDef * ) ISM_UART, &tmpc, 1, NONE_BLOCKING);
			// If data received
			if (rLen)
			{
				data_array[index] = tmpc;
				index++;

				if ((data_array[index - 1] == '\n') || (index >= (MAX_LENGTH)))
				{
					uart_api_handler(data_array, index, xHigherPriorityTaskWoken);
					index = 0;
				}
			}
			else
				break; // no more data
		}
	}

	NVIC_ClearPendingIRQ(UART3_IRQn);
	if( xHigherPriorityTaskWoken != pdFALSE )
	{
		taskYIELD();
	}
}
