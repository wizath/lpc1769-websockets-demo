/*
 * ism.h
 *
 *  Created on: Aug 30, 2017
 *      Author: rst
 */

#ifndef ISM_H_
#define ISM_H_

#include "config.h"

typedef struct
{
	void * data;
	uint8_t length;
} msg_t;

void ism_enable(void);
void ism_disable(void);
void ism_init(void);

#endif /* ISM_H_ */
