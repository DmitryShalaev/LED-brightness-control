/*
 * ProcessingData.c
 *
 *  Created on: 17 џэт. 2019 у.
 *      Author: DimaS
 */

#include <DataProcessing.h>

void ProcessingData(uint8_t dataToReceive[4]) {

	memset(dataToSend, 0, sizeof(dataToSend));

	dataToSend[0] = 0x02;

	switch (dataToReceive[1] & 0xF0) {

	case 0x00:

		dataToSend[1] = 0x00;

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

		dataToSend[2] = PWM1;
		dataToSend[3] = PWM2;
		dataToSend[4] = PWM3;

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0x10:

		if ((dataToReceive[1] & 0x01) == 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x10;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0x20:

		if ((dataToReceive[1] & 0x01) == 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x20;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0x30:

		if ((dataToReceive[1] & 0x01) == 0x01) {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x30;

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0x40:

		if ((dataToReceive[1] & 0x01) == 0x01) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
		}

		dataToSend[1] = 0x40;

		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0x50:

		PWM1 = dataToReceive[2];
		TIM3->CCR1 = PWM1;

		break;

	case 0x60:

		PWM2 = dataToReceive[2];
		TIM3->CCR2 = PWM2;

		break;

	case 0x70:

		PWM3 = dataToReceive[2];
		TIM3->CCR3 = PWM3;

		break;

	case 0x80:

		dataToSend[1] = 0x80;

		dataToSend[2] = (uint8_t) ((ADC_Data[0] & 0xFF00) >> 8);
		dataToSend[3] = (uint8_t) (ADC_Data[0] & 0x00FF);

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0x90:

		dataToSend[1] = 0x90;

		dataToSend[2] = (uint8_t) ((ADC_Data[1] & 0xFF00) >> 8);
		dataToSend[3] = (uint8_t) (ADC_Data[1] & 0x00FF);

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0xA0:

		dataToSend[1] = 0xA0;

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0xB0:

		dataToSend[1] = 0xB0;

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)) {
			dataToSend[1] |= 0x01;
		} else {
			dataToSend[1] &= ~0x01;
		}

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	case 0xC0:

		//BH1750

		USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 5);

		break;

	default:

		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

	}

}

