#include "DataProcessing.h"

#include "adc.h"
#include "can.h"
#include "i2c.h"
#include "string.h"
#include "usart.h"
#include "../../../general/id.h"

void ProcessingData(const uint8_t Data[8], const bool toSend) {
	memset(dataToSend, 0, sizeof(dataToSend));

	dataToSend[0] = ID & 0x0FF;
	dataToSend[1] = (ID & 0xF00) >> 3;

	switch (Data[1] & 0x1F) {
		case INIT:

			MasterID = (Data[3] << 3) | Data[2];

			dataToSend[1] |= INIT;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10))
				dataToSend[2] |= 0x01;
			else
				dataToSend[2] &= ~0x01;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11))
				dataToSend[2] |= 0x02;
			else
				dataToSend[2] &= ~0x02;

			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
				dataToSend[2] |= 0x04;
			else
				dataToSend[2] &= ~0x04;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2))
				dataToSend[2] |= 0x08;
			else
				dataToSend[2] &= ~0x08;

			dataToSend[3] = 255 - PWM1;
			dataToSend[4] = 255 - PWM2;
			dataToSend[5] = 255 - PWM3;

			SendData(dataToSend, toSend);

			break;

		case OUT_1:

			if (Data[2] == 0x01)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);

			dataToSend[1] |= OUT_1;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10))
				dataToSend[2] = ON;
			else
				dataToSend[2] = OFF;

			SendData(dataToSend, toSend);

			break;

		case OUT_2:

			if (Data[2] == 0x01)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);

			dataToSend[1] |= OUT_2;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11))
				dataToSend[2] = ON;
			else
				dataToSend[2] = OFF;

			SendData(dataToSend, toSend);

			break;

		case OUT_3:

			if (Data[2] == 0x01)
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);

			dataToSend[1] |= OUT_3;

			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
				dataToSend[2] = ON;
			else
				dataToSend[2] = OFF;

			SendData(dataToSend, toSend);

			break;

		case OUT_4:

			if (Data[2] == 0x01)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);

			dataToSend[1] |= OUT_4;

			if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2))
				dataToSend[2] = ON;
			else
				dataToSend[2] = OFF;

			SendData(dataToSend, toSend);

			break;

		case PWM_1:

			NewPWM1 = 255 - Data[2];

			break;

		case PWM_2:

			NewPWM2 = 255 - Data[2];

			break;

		case PWM_3:

			NewPWM3 = 255 - Data[2];

			break;

		case ADC:

			dataToSend[1] |= ADC;

			dataToSend[2] = (ADC_Data[0] & 0x0F00) >> 4;
			dataToSend[3] = ADC_Data[0] & 0x00FF;

			dataToSend[2] |= (ADC_Data[1] & 0x0F00) >> 8;
			dataToSend[4] = ADC_Data[1] & 0x00FF;

			SendData(dataToSend, toSend);

			break;

		case LUX:

			I2C_ReadBH1750();

			dataToSend[1] |= LUX;

			dataToSend[2] = I2C_Buffer[0];
			dataToSend[3] = I2C_Buffer[1];

			SendData(dataToSend, toSend);

			break;

		case TIME:

			PWMSpeed = Data[2] * 60 + Data[3];
			PWMStep = 0;

			break;

		case ALLPWM:

			NewPWM1 = 255 - Data[2];
			NewPWM2 = 255 - Data[2];
			NewPWM3 = 255 - Data[2];

			break;

		case CONNECTED:

			dataToSend[1] |= CONNECTED;
			SendData(dataToSend, toSend);

			break;

		default:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}
}

void SendData(uint8_t Data[8], const bool toSend) {
	if (Master)
		HAL_UART_Transmit_IT(&huart1, Data, 8);
	else if (toSend)
		Send_CAN(Data, MasterID);
}
