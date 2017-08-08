/*
 * hooks.c
 *
 *  Created on: Aug 8, 2017
 *      Author: rst
 */

#include "config.h"

void vApplicationTickHook( void )
{}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	/* This function will get called if a task overflows its stack. */
	( void ) pxTask;
	( void ) pcTaskName;

	for( ;; );
}

void vApplicationMallocFailedHook( void )
{

}

void vConfigureTimerForRunTimeStats( void )
{

}

void HardFault_Handler(void)
{
	/* Very bad thing =( Print some useful info and reboot */
	for (;;);
}

void NMI_Handler(void)
{
	for (;;);
}

void MemManage_Handler(void)
{
	for (;;);
}

void BusFault_Handler(void)
{
	for (;;);
}

void UsageFault_Handler(void)
{
	for (;;);
}


void DebugMon_Handler(void)
{
	for (;;);
}
