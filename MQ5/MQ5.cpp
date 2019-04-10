#include "MQ5.h"

MQ5::MQ5(){}

MQ5::MQ5(uint8_t aPin, uint8_t dPin){
	analogPin = aPin;
	digitalPin = dPin;
	currentValue = 0;
	mCoef = -2.42;
	bCoef = 7.62;
	R0 = 1.54;
}

double MQ5::takeReading(){
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

void MQ5::setAnalogPin(uint8_t aPin){
	analogPin = aPin;
}

void MQ5::setDigitalPin(uint8_t dPin){
	digitalPin = dPin;
}

float MQ5::getCurrentValue(){
	return currentValue;
}

uint8_t  MQ5::getAnalogPin(){
	return analogPin;
}

uint8_t  MQ5::getDigitalPin(){
	return digitalPin;
}