#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "i2c.h"
#include "tim.h"
#include "../../../GENERAL/ID.h"

uint8_t dataToReceive[6];
uint8_t dataToSend[6];

uint32_t Period;

uint8_t ActivationThreshold;

uint8_t PWM1, PWM2, PWM3;

uint8_t NewPWM1, NewPWM2, NewPWM3;

void ProcessingData(uint8_t dataToReceive[]);

#endif /* DATAPROCESSING_H_ */
