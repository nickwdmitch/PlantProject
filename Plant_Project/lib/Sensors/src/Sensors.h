#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

int AverageOf100Samples(int pin);

void PrintSensorValues(int MoistureSensorValue, int LightDependentResistorValue);

#endif