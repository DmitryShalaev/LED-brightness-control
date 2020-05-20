#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "stdbool.h"
#include "stdint.h"

void ProcessingData(const uint8_t Data[8], bool toSend);
void SendData(uint8_t Data[8], bool toSend);

#endif /* DATAPROCESSING_H_ */
