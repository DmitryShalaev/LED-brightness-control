#include "DataProcessing.h"

void ProcessingData(uint8_t dataToReceive[6]) {

	memset(dataToSend, 0, sizeof(dataToSend));

	dataToSend[0] = 0x02;

	switch (dataToReceive[1]) {

		case INIT:

			dataToSend[1] = INIT;

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

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case LED_1:

			if (dataToReceive[2] == 0x01) {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
			}

			dataToSend[1] = LED_1;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) {
				dataToSend[2] = 0x01;
			} else {
				dataToSend[2] = 0x00;
			}

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case LED_2:

			if (dataToReceive[2] == 0x01) {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
			}

			dataToSend[1] = LED_2;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
				dataToSend[2] |= 0x01;
			} else {
				dataToSend[2] &= ~0x01;
			}

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case REL_1:

			if (dataToReceive[2] == 0x01) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
			}

			dataToSend[1] = REL_1;

			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)) {
				dataToSend[2] = 0x01;
			} else {
				dataToSend[2] = 0x00;
			}

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case REL_2:

			if (dataToReceive[2] == 0x01) {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
			}

			dataToSend[1] = REL_2;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
				dataToSend[2] = 0x01;
			} else {
				dataToSend[2] = 0x00;
			}

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case PWM_1:

			NewPWM1 = 255 - dataToReceive[2];

		break;

		case PWM_2:

			NewPWM2 = 255 - dataToReceive[2];

		break;

		case PWM_3:

			NewPWM3 = 255 - dataToReceive[2];

		break;

		case ADC:

			dataToSend[1] = ADC;

			dataToSend[2] = (uint8_t) ((ADC_Data[0] & 0xFF00) >> 8);
			dataToSend[3] = (uint8_t) (ADC_Data[0] & 0x00FF);

			dataToSend[2] = (uint8_t) (((ADC_Data[1] & 0xFF00) >> 4) | dataToSend[2]);
			dataToSend[4] = (uint8_t) (ADC_Data[1] & 0x00FF);

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case LUX:

			dataToSend[1] = LUX;

			I2C_ReadBH1750();

			dataToSend[2] = I2C_Buffer[0];
			dataToSend[3] = I2C_Buffer[1];

			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, dataToSend, 6);

		break;

		case TIME:

			Period = ((dataToReceive[2] * 60 + dataToReceive[3]) / 0.001 / 255) - 1;
			TIM4->CNT = 0;
			TIM4->ARR = Period;

		break;

		case ALLPWM:

			NewPWM1 = 255 - dataToReceive[2];
			NewPWM2 = 255 - dataToReceive[2];
			NewPWM3 = 255 - dataToReceive[2];

		break;


		default:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

	}

}


