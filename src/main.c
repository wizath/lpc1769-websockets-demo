#include <cr_section_macros.h>

#include "config.h"
#include "network.h"
#include "utils.h"

#include "lpc17xx_gpio.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_pinsel.h"

void prvSetupHardware( void )
{
	SystemCoreClockUpdate();
	UART_CFG_Type 	UARTConfigStruct;
	PINSEL_CFG_Type PinCfg;

	/*
	 * Initialize UART2 pin connect
	 * DEBUG PORT
	 */
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 2;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	PinCfg.Pinnum = 3;
	PINSEL_ConfigPin(&PinCfg);

	gpio_pin_cfg_output(BOARD_LED1);
	gpio_pin_cfg_output(BOARD_LED2);
	gpio_pin_cfg_output(BOARD_LED3);

	UART_ConfigStructInit(&UARTConfigStruct);
	/* Re-configure baudrate to 115200bps */
	UARTConfigStruct.Baud_rate = 115200;
	/* Initialize DEBUG_UART_PORT peripheral with given to corresponding parameter */
	UART_Init( ( LPC_UART_TypeDef * ) LPC_UART0, &UARTConfigStruct);
	/* Enable UART Transmit */
	UART_TxCmd( ( LPC_UART_TypeDef * ) LPC_UART0, ENABLE);
}


void vLedTask( void *pvParameters )
{
	for (;;)
	{
		gpio_pin_set(BOARD_LED2);
		vTaskDelay(configTICK_RATE_HZ / 6);
		gpio_pin_clear(BOARD_LED2);
		vTaskDelay(configTICK_RATE_HZ / 6);
	}
}

void vLedTask2( void *pvParameters )
{
	for (;;)
	{
		gpio_pin_set(BOARD_LED1);
		vTaskDelay(configTICK_RATE_HZ / 4);
		gpio_pin_clear(BOARD_LED1);
		vTaskDelay(configTICK_RATE_HZ / 4);
	}
}

int main(void)
{
	prvSetupHardware();

	printf("[log] device boot\n");
	xTaskCreate( vLedTask, "Led Toggle", configMINIMAL_STACK_SIZE, ( void * ) NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( vLedTask2, "Led Toggle2", configMINIMAL_STACK_SIZE, ( void * ) NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( vSetupIFTask, "SetupIFx", configMINIMAL_STACK_SIZE + 512UL, NULL, tskIDLE_PRIORITY + 2UL, NULL );

	vTaskStartScheduler();

    return 1;
}
