#include "MQ6.h"

MQ6::MQ6(){}

MQ6::MQ6(uint8_t aPin, uint8_t dPin){
	analogPin = aPin;
	digitalPin = dPin;
	currentValue = 0;
}

float MQ6::takeReading(){
	currentValue = analogRead(analogPin);
	return currentValue;
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