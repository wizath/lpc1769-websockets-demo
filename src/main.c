#include <cr_section_macros.h>

#include "config.h"

#include "lpc17xx_gpio.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_pinsel.h"

#define DEBUGSTR(...) taskENTER_CRITICAL(); \
					printf(__VA_ARGS__); \
					taskEXIT_CRITICAL()



void prvSetupHardware( void )
{
	SystemCoreClockUpdate();
	UART_CFG_Type UARTConfigStruct;
	PINSEL_CFG_Type PinCfg;

	LPC_GPIO0->FIODIR |= (1 << 22);
	LPC_GPIO3->FIODIR |= (1 << 26);
	LPC_GPIO3->FIODIR |= (1 << 25);

	LPC_GPIO0->FIOSET |= (1 << 22);
	LPC_GPIO3->FIOSET |= (1 << 26);
	LPC_GPIO3->FIOSET |= (1 << 25);

	/*
	 * Initialize UART0 pin connect
	 */
	PinCfg.Funcnum = 2;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 0;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	PinCfg.Pinnum = 2;
	PINSEL_ConfigPin(&PinCfg);

	UART_ConfigStructInit(&UARTConfigStruct);
	// Re-configure baudrate to 115200bps
	UARTConfigStruct.Baud_rate = 115200;
	// Initialize DEBUG_UART_PORT peripheral with given to corresponding parameter
	UART_Init( ( LPC_UART_TypeDef * ) LPC_UART3, &UARTConfigStruct);
	// Enable UART Transmit
	UART_TxCmd( ( LPC_UART_TypeDef * ) LPC_UART3, ENABLE);
}

void vLedTask( void *pvParameters )
{
	for (;;)
	{
		LPC_GPIO0->FIOSET = (1 << 22);
		vTaskDelay(configTICK_RATE_HZ / 2);
		LPC_GPIO0->FIOCLR = (1 << 22);
		vTaskDelay(configTICK_RATE_HZ / 2);
	}
}

void vLedTask2( void *pvParameters )
{
	for (;;)
	{
		LPC_GPIO3->FIOSET = (1 << 26);
		vTaskDelay(configTICK_RATE_HZ / 4);
		LPC_GPIO3->FIOCLR = (1 << 26);
		vTaskDelay(configTICK_RATE_HZ / 4);
	}
}

int main(void)
{
	prvSetupHardware();

	printf("OPTOGENETIC MODULE v0.1\n");

	xTaskCreate( vLedTask, "Led Toggle", configMINIMAL_STACK_SIZE, ( void * ) NULL, tskIDLE_PRIORITY + 5, NULL );
	xTaskCreate( vLedTask2, "Led Toggle3", configMINIMAL_STACK_SIZE, ( void * ) NULL, tskIDLE_PRIORITY, NULL );

	vTaskStartScheduler();

    return 1;
}
