#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_

#include "stdbool.h"
#include "stdint.h"
#include "../../../general/id.h"

uint8_t dataToSend[PACKET_SIZE];

void ProcessingData(const uint8_t Data[], bool toSend);
void SendData(uint8_t Data[], bool toSend);

#endif /* DATAPROCESSING_H_ */
