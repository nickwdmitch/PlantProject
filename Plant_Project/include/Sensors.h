#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

void SensorSample(int enablePin, int writePin, int *pValue); 

void PrintSensorValues(int MoistureSensorValue, int LightDependentResistorValue);

#endif