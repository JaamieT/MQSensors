#ifndef _MQ4_H_
#define _MQ4_H_
#endif

#include "Arduino.h"

#define coefficiet_A 19.32
#define coefficient_B -0.64

class MQ4 {
private:
	uint8_t analogPin;
	uint8_t digitalPin;
	float currentValue;
public:
	MQ4();
	MQ4(uint8_t, uint8_t);
	float takeReading();
	void setAnalogPin(uint8_t);
	void setDigitalPin(uint8_t);
	uint8_t getAnalogPin(void);
	uint8_t getDigitalPin(void);
	float getCurrentValue(void);
};