/*
 * ProcessingData.c
 *
 *  Created on: 17 џэт. 2019 у.
 *      Author: DimaS
 */

#include "ProcessingData.h"

void ProcessingReceivedData(uint8_t dataToReceive[10])
{
	if (dataToReceive[1] == 0xFF) {

		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		if ((dataToReceive[2] & 0x01) == 1) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
		}

		if ((dataToReceive[2] & 0x02) == 2) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
		}

		if ((dataToReceive[2] & 0x04) == 4) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
		}

		if ((dataToReceive[2] & 0x08) == 8) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
		}

		TIM3->CCR1=dataToReceive[3];
		TIM3->CCR2=dataToReceive[4];
		TIM3->CCR3=dataToReceive[5];

	} else if (dataToReceive[1] == 0xF) {

		dataToSend[0] = 0x02;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
			dataToSend[1] |= 0x02;
		} else {
			dataToSend[1] &= ~0x02;
		}

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)) {
			dataToSend[1] |= 0x04;
		} else {
			dataToSend[1] &= ~0x04;
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
			dataToSend[1] |= 0x08;
		} else {
			dataToSend[1] &= ~0x08;
		}

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
			dataToSend[1] |= 0x10;
		} else {
			dataToSend[1] &= ~0x10;
		}

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)) {
			dataToSend[1] |= 0x20;
		} else {
			dataToSend[1] &= ~0x20;
		}

		dataToSend[2] = (uint8_t)((ADC_Data[0] & 0xFF00) >> 8);
		dataToSend[3] = (uint8_t)(ADC_Data[0] & 0x00FF);

		dataToSend[2] = (uint8_t)(((ADC_Data[1] & 0xFF00) >> 4) | dataToSend[2]) ;
		dataToSend[4] = (uint8_t)(ADC_Data[1] & 0x00FF);


		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 11);
	}
}

