/*
 * ProcessingData.h
 *
 *  Created on: 17 ���. 2019 �.
 *      Author: DimaS
 */

#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "usbd_customhid.h"
#include "i2c.h"

uint8_t dataToReceive[6];
uint8_t dataToSend[6];

uint8_t ActivationThreshold;

uint8_t PWM1, PWM2, PWM3;

uint8_t NewPWM1, NewPWM2, NewPWM3;

extern USBD_HandleTypeDef hUsbDeviceFS;

void ProcessingData(uint8_t dataToReceive[6]);

#endif /* DATAPROCESSING_H_ */
