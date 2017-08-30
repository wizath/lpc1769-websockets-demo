/*
 * utils.c
 *
 *  Created on: Aug 30, 2017
 *      Author: rst
 */

#include "utils.h"
#include "lpc17xx_gpio.h"

uint8_t gpio_pin_read(uint8_t port, uint8_t pin)
{
	uint32_t value = GPIO_ReadValue(port);
	return (value >> pin) & 0x01;
}

void gpio_pin_set(uint8_t port, uint8_t pin)
{
	GPIO_SetValue(port, 1 << pin);
}

void gpio_pin_clear(uint8_t port, uint8_t pin)
{
	GPIO_ClearValue(port, 1 << pin);
}

void gpio_pin_cfg_output(uint8_t port, uint8_t pin)
{
	GPIO_SetDir(port, 1 << pin, 1);
}

void gpio_pin_cfg_input(uint8_t port, uint8_t pin)
{
	GPIO_SetDir(port, 1 << pin, 0);
}
