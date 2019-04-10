#ifndef _MQ4_H_
#define _MQ4_H_
#endif

#include "Arduino.h"


class MQ4 {
private:
	uint8_t analogPin;
	uint8_t digitalPin;
	float currentValue;
	float mCoef;
	float R0;
	float bCoef;
public:
	MQ4();
	MQ4(uint8_t, uint8_t);
	double takeReading();
	void setAnalogPin(uint8_t);
	void setDigitalPin(uint8_t);
	uint8_t getAnalogPin(void);
	uint8_t getDigitalPin(void);
	float getCurrentValue(void);
};