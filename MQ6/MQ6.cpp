#include "MQ6.h"

MQ6::MQ6(){}

MQ6::MQ6(uint8_t aPin, uint8_t dPin){
	analogPin = aPin;
	digitalPin = dPin;
	currentValue = 0;
	mCoef = -2.43;
	bCoef = 7.29;
	R0 = 1.0;
}

double MQ6::takeReading(){
	for (int i = 0; i < 20; i++){
		currentValue += analogRead(analogPin);
		delay(10);
	}
	currentValue /= 20;
	float sensorVolts = currentValue*(5.0/1023.0);
	float RSGas = ((50.0)/sensorVolts) - 10.0;
	float ratio = RSGas/ R0;
	double PPMLog = (log10(ratio)-bCoef)/mCoef;
	double PPM = pow(10, PPMLog);
	return PPM;
}

void MQ6::setAnalogPin(uint8_t aPin){
	analogPin = aPin;
}

void MQ6::setDigitalPin(uint8_t dPin){
	digitalPin = dPin;
}

float MQ6::getCurrentValue(){
	return currentValue;
}

uint8_t  MQ6::getAnalogPin(){
	return analogPin;
}

uint8_t  MQ6::getDigitalPin(){
	return digitalPin;
}