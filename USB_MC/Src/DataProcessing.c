/*
 * ProcessingData.c
 *
 *  Created on: 17 џэт. 2019 у.
 *      Author: DimaS
 */

#include "DataProcessing.h"
#include "tim.h"

void ProcessingData(uint8_t dataToReceive[6]) {

	memset(dataToSend, 0, sizeof(dataToSend));

	dataToSend[0] = 0x02;

	switch (dataToReceive[1]) {

	case 0x00:

		dataToSend[1] = 0x00;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) {
			dataToSend[2] |= 0x01;
		} else {
			dataToSend[2] &= ~0x01;
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
			dataToSend[2] |= 0x02;
		} else {
			dataToSend[2] &= ~0x02;
		}

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)) {
			dataToSend[2] |= 0x04;
		} else {
			dataToSend[2] &= ~0x04;
		}

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
			dataToSend[2] |= 0x08;
		} else {
			dataToSend[2] &= ~0x08;
		}

		dataToSend[3] = 255 - PWM1;
		dataToSend[4] = 255 - PWM2;
		dataToSend[5] = 255 - PWM3;

		I2C_launchBH1750();

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x01:

		if (dataToReceive[2] == 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x01;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) {
			dataToSend[2] = 0x01;
		} else {
			dataToSend[2] = 0x00;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x02:

		if (dataToReceive[2] == 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x02;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
			dataToSend[2] |= 0x01;
		} else {
			dataToSend[2] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x03:

		if (dataToReceive[2] == 0x01) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x03;

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)) {
			dataToSend[2] = 0x01;
		} else {
			dataToSend[2] = 0x00;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x04:

		if (dataToReceive[2] == 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x04;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
			dataToSend[2] = 0x01;
		} else {
			dataToSend[2] = 0x00;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x05:

		NewPWM1 = 255 - dataToReceive[2];

		break;

	case 0x06:

		NewPWM2 = 255 - dataToReceive[2];

		break;

	case 0x07:

		NewPWM3 = 255 - dataToReceive[2];

		break;

	case 0x08:

		dataToSend[1] = 0x08;

		dataToSend[2] = (uint8_t) ((ADC_Data[0] & 0xFF00) >> 8);
		dataToSend[3] = (uint8_t) (ADC_Data[0] & 0x00FF);

		dataToSend[2] = (uint8_t) (((ADC_Data[1] & 0xFF00) >> 4) | dataToSend[2]);
		dataToSend[4] = (uint8_t) (ADC_Data[1] & 0x00FF);

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x0B:

		dataToSend[1] = 0x0B;

		I2C_ReadBH1750();

		dataToSend[2] = I2C_Buffer[0];
		dataToSend[3] = I2C_Buffer[1];

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

	case 0x0C:

		Period = ((dataToReceive[2] * 60 + dataToReceive[3]) / 0.001 / 255) - 1;
		TIM4->CNT = 0;
		TIM4->ARR = Period;

		break;

	case 0x0D:

		NewPWM1 = 255 - dataToReceive[2];
		NewPWM2 = 255 - dataToReceive[2];
		NewPWM3 = 255 - dataToReceive[2];

		break;


	default:

		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

	}

}


