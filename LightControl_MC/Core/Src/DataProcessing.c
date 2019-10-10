#include "DataProcessing.h"

void ProcessingData(uint8_t dataToReceive[]) {

	memset(dataToSend, 0, sizeof(dataToSend));

	switch (dataToReceive[0]) {

		case INIT:

			dataToSend[0] = INIT;

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

			dataToSend[2] = 255 - PWM1;
			dataToSend[3] = 255 - PWM2;
			dataToSend[4] = 255 - PWM3;

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		case LED_1:

			if (dataToReceive[1] == 0x01) {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
			}

			dataToSend[0] = LED_1;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)) {
				dataToSend[1] = ON;
			} else {
				dataToSend[1] = OFF;
			}
			
			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		case LED_2:

			if (dataToReceive[1] == 0x01) {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
			}

			dataToSend[0] = LED_2;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11)) {
				dataToSend[1] = ON;
			} else {
				dataToSend[1] = OFF;
			}

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		case REL_1:

			if (dataToReceive[1] == 0x01) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
			}

			dataToSend[0] = REL_1;

			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)) {
				dataToSend[1] = ON;
			} else {
				dataToSend[1] = OFF;
			}

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		case REL_2:

			if (dataToReceive[1] == 0x01) {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			} else {
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
			}

			dataToSend[0] = REL_2;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) {
				dataToSend[1] = ON;
			} else {
				dataToSend[1] = OFF;
			}

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		case PWM_1:

			NewPWM1 = 255 - dataToReceive[1];

		break;

		case PWM_2:

			NewPWM2 = 255 - dataToReceive[1];

		break;

		case PWM_3:

			NewPWM3 = 255 - dataToReceive[1];

		break;

		case ADC:

			dataToSend[0] = ADC;

			dataToSend[1] = (ADC_Data[0] & 0xFF00) >> 4;
			dataToSend[2] = ADC_Data[0] & 0x00FF;

			dataToSend[1] = dataToSend[1] | ((ADC_Data[1] & 0xFF00) >> 8);
			dataToSend[3] = ADC_Data[1] & 0x00FF;

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		

		case LUX:

			dataToSend[0] = LUX;

			I2C_ReadBH1750();

			dataToSend[1] = I2C_Buffer[0];
			dataToSend[2] = I2C_Buffer[1];

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		case TIME:

			Period = ((dataToReceive[1] * 60 + dataToReceive[2]) / 0.001 / 255) - 1;
			TIM4->CNT = 0;
			TIM4->ARR = Period;

		break;

		case ALLPWM:

			NewPWM1 = 255 - dataToReceive[1];
			NewPWM2 = 255 - dataToReceive[1];
			NewPWM3 = 255 - dataToReceive[1];

		break;
		
		case CONNECTED:

			dataToSend[0] = dataToSend[1] = CONNECTED;

			HAL_UART_Transmit_IT(&huart1, (uint8_t*)dataToSend, 8);

		break;

		default:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

	}

}


