/*
 * ProcessingData.h
 *
 *  Created on: 17 џэт. 2019 у.
 *      Author: DimaS
 */

#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "usbd_custom_hid_if.h"
#include "stdint.h"
#include "main.h"

uint8_t dataToReceive[5];
uint8_t dataToSend[5];

uint8_t ActivationThreshold;

uint8_t PWM1;
uint8_t PWM2;
uint8_t PWM3;

extern USBD_HandleTypeDef hUsbDeviceFS;

void ProcessingData(uint8_t dataToReceive[5]);

#endif /* DATAPROCESSING_H_ */
