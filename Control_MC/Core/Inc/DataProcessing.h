#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "stdbool.h"
#include "stdint.h"

uint8_t PWM1, PWM2, PWM3;

uint8_t NewPWM1, NewPWM2, NewPWM3;

uint8_t dataToSend[8];

uint16_t PWMSpeed, PWMStep;

void ProcessingData(const uint8_t Data[8], bool toSend);
void SendData(uint8_t Data[8], bool toSend);

#endif /* DATAPROCESSING_H_ */
