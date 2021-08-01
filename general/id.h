#ifndef ID_H
#define ID_H

constexpr auto ON						= 0x01;
constexpr auto OFF					= 0x00;

constexpr auto INIT					= 0x00;
constexpr auto OUT_1				= 0x01;
constexpr auto OUT_2				= 0x02;
constexpr auto OUT_3				= 0x03;
constexpr auto OUT_4				= 0x04;
constexpr auto PWM_1				= 0x05;
constexpr auto PWM_2				= 0x06;
constexpr auto PWM_3				= 0x07;
constexpr auto ADC					= 0x08;
constexpr auto IN_1					= 0x09;
constexpr auto IN_2					= 0x0A;
constexpr auto LUX					= 0x0B;
constexpr auto TIME					= 0x0C;
constexpr auto ALLPWM				= 0x0D;
constexpr auto IN_3					= 0x0E;
constexpr auto PWMConfirm		= 0x0F;

constexpr auto  CONNECTED		= 0x1F;

constexpr auto  PACKET_SIZE	= 6;

#endif // ID_H
