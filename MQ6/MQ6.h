#ifndef _MQ6_H_
#define _MQ6_H_
#endif

#include "Arduino.h"


class MQ6 {
private:
	uint8_t analogPin;
	uint8_t digitalPin;
	float currentValue;
	float mCoef;
	float R0;
	float bCoef;
public:
	MQ6();
	MQ6(uint8_t, uint8_t);
	double takeReading();
	void setAnalogPin(uint8_t);
	void setDigitalPin(uint8_t);
	uint8_t getAnalogPin(void);
	uint8_t getDigitalPin(void);
	float getCurrentValue(void);
};