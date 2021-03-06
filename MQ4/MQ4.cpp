#include "MQ4.h"

MQ4::MQ4(){}

MQ4::MQ4(uint8_t aPin, uint8_t dPin){
	analogPin = aPin;
	digitalPin = dPin;
	currentValue = 0;
	mCoef = -2.88;
	bCoef = 8.40;
	R0 = 2.25;
}

double MQ4::takeReading(){
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

void MQ4::setAnalogPin(uint8_t aPin){
	analogPin = aPin;
}

void MQ4::setDigitalPin(uint8_t dPin){
	digitalPin = dPin;
}

float MQ4::getCurrentValue(){
	return currentValue;
}

uint8_t  MQ4::getAnalogPin(){
	return analogPin;
}

uint8_t  MQ4::getDigitalPin(){
	return digitalPin;
}