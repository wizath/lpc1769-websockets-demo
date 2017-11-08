/*
 * utils.h
 *
 *  Created on: Aug 30, 2017
 *      Author: rst
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "config.h"

uint8_t gpio_pin_read(uint8_t port, uint8_t pin);
void gpio_pin_set(uint8_t port, uint8_t pin);
void gpio_pin_clear(uint8_t port, uint8_t pin);
void gpio_pin_cfg_output(uint8_t port, uint8_t pin);
void gpio_pin_cfg_input(uint8_t port, uint8_t pin);

#endif /* UTILS_H_ */
