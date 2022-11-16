#include "Sensors.h"

void SensorSample(int enablePin, int writePin, int *pValue) {
    int tempValue = 0.; 
    
    // Enable sensor
    digitalWrite(enablePin, HIGH);

    // Wait for voltage to settle
    delay(100);
    
    for (int i = 0; i <= 100; i++) 
    { 
        tempValue = tempValue + analogRead(writePin); 
        delay(1); 
    } 
    
    // Write the averaged value to the pointer
    *pValue = tempValue/100.0; 

    // Disable the LDR sensor
    digitalWrite(enablePin, LOW);

    // Wait for voltage to settle
    delay(100);
}

/* Print values for each sensor to the serial montior
 * format: Moisture Value: X; Light Value: Y
 */
void PrintSensorValues(int MoistureSensorValue, int LightDependentResistorValue) {
    Serial.print("Moisture Value: "); 
    Serial.print(MoistureSensorValue); 
    Serial.print("; ");
    Serial.print("Light Value: ");
    Serial.println(LightDependentResistorValue); 
}