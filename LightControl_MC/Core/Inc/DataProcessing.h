#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "adc.h"
#include "../../../GENERAL/ID.h"

uint32_t Period;

uint8_t ActivationThreshold;

uint8_t PWM1, PWM2, PWM3;

uint8_t NewPWM1, NewPWM2, NewPWM3;

uint8_t dataToSend[8];

void ProcessingData(uint8_t Data[]);
void SendData(uint8_t Data[]);

#endif /* DATAPROCESSING_H_ */
