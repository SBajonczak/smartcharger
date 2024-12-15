/**
 * @file Battery.h
 * @brief Defines the Battery class for managing battery operations.
 */
#ifndef BATTERY_H
#define BATTERY_H
#include <Arduino.h>

/**
 * @class Battery
 * @brief A class to manage battery operations such as measuring voltage and checking battery status.
 */
class Battery
{
public:
    Battery(int inputAnalogPin, int inputMmosfetGatePin);

    void initialize(int inputAnalogPin, int inputMmosfetGatePin);
    /**
     * @brief Measures the current battery voltage.
     * @return The measured battery voltage.
     */
    float measureVoltage();

    /**
     * @brief Checks if the battery status is OK.
     * @return True if the battery is OK, false otherwise.
     */
    bool isBatteryOk();

    /**
     * @brief Prepares the battery for measuring.
     */
    void prepareForMeasuring();

    /**
     * @brief Finalizes the battery measurement process.
     */
    void doneMearuring();

private:
    uint8_t analogPin;     ///< The analog pin used for voltage measurement.
    uint8_t mosfetGatePin; ///< The MOSFET gate pin used to control the measurement circuit.
    float currentVoltage;  ///< The current measured voltage of the battery.
};

#endif // BATTERY_H