#include "Battery.h"
#include <Arduino.h>
/**
 * @file Battery.c
 * @brief This file contains the implementation for battery-related functionalities.
 *
 * @details
 * This file is part of the Battery Charger project and includes functions and
 * variables related to battery management.
 */

/**
 * @var faultyBatteryVoltage
 * @brief Voltage level indicating a faulty battery.
 *
 * @details
 * This variable holds the voltage level that is considered to indicate a faulty
 * battery. The default value is set to 1.0V, but it can be adjusted based on
 * specific requirements.
 */
const float LOW_VOLTAGE_THRESHOLD = 1.0f; // 1.0V (adjust this value based on your needs)
Battery::Battery(int inputAnalogPin, int inputMmosfetGatePin) : currentVoltage(0.0)
{
    this->analogPin = inputAnalogPin;
    this->mosfetGatePin = inputMmosfetGatePin;
    // set default value
    this->currentVoltage = 0.0f;
    this->initialize(this->analogPin, this->mosfetGatePin);
}

void Battery::initialize(int inputAnalogPin, int inputMmosfetGatePin)
{
    this->analogPin = inputAnalogPin;
    this->mosfetGatePin = inputMmosfetGatePin;
    //  the MOSFET gate pin as an output
    pinMode(mosfetGatePin, OUTPUT);
    // Ensure the MOSFET is turned off initially (gate HIGH means off, and LOW means ON)
    digitalWrite(mosfetGatePin, 0);
}

float Battery::measureVoltage()
{
    this->prepareForMeasuring();
    // Print the battery voltage for monitoring
    Serial.print("Battery Voltage: ");
    Serial.println(this->currentVoltage);

    // Read the analog value from the battery pin (A0)
    int sensorValue = analogRead(this->analogPin);

    this->doneMearuring();
    // Convert the analog reading to voltage (assuming 3.3V reference for Wemos D1 Mini)
    float voltage = sensorValue * (3.3 / 1023.0);
    this->currentVoltage = voltage;
    // Placeholder for actual voltage measurement logic
    return voltage;
}

void Battery::doneMearuring()
{
    // Disable charging by turning off the MOSFET (set gate HIGH)
    digitalWrite(mosfetGatePin, 0); // Turn off the charging MOSFET
}

bool Battery::isBatteryOk()
{
    this->measureVoltage();
    // Check if the battery voltage is below the threshold (e.g., 1V)
    if (this->currentVoltage < LOW_VOLTAGE_THRESHOLD)
    {

        return false;
    }
    else
    {
        return true;
    }
}