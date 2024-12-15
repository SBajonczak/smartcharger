/**
 * @file main.cpp
 * @brief Battery Charger Control Program
 * 
 * This program is designed to control the charging process of a battery using an Arduino-based microcontroller.
 * It monitors the battery voltage and controls a P-channel MOSFET to enable or disable charging based on the voltage level.
 * 
 * The program includes the following key components:
 * - Battery: A class to handle battery voltage measurement and control of the MOSFET.
 * - StateManager: A class to manage the charging process based on the battery voltage.
 * 
 * The main loop function continuously monitors the battery voltage, prints the voltage to the serial monitor, 
 * and controls the MOSFET to enable or disable charging.
 * 
 * @note Adjust the LOW_VOLTAGE_THRESHOLD and delay in the loop function as needed to suit your specific requirements.
 * 
 * @author 
 * Sascha Bajonczak (xbeejayx@hotmail.com)
 * http://blog.bajonczak.com
 * 
 * @disclaimer
 * This code is provided as-is without any warranty. Use it at your own risk. Contributions are welcome.
 */
#include <Arduino.h>
#include <Battery.h>
#include <StateManager.h>
// Define the GPIO pin to control the P-channel MOSFET
const uint8_t MOSFET_GATE_PIN = D1; // Example GPIO pin to control the MOSFET
const uint8_t BATTERY_PIN = A0;     // Analog pin to read the battery voltage

// Threshold for battery voltage (e.g., to detect if the voltage drops below 1V)
const float LOW_VOLTAGE_THRESHOLD = 1.0; // 1.0V (adjust this value based on your needs)

Battery battery(BATTERY_PIN, MOSFET_GATE_PIN);

// State Manager will manage the charging process
StateManager stateManager(battery);

void setup()
{
  // Initialize the serial communication for debugging
  Serial.begin(115200);
}

/**
 * @brief Main loop function that continuously monitors the battery voltage and controls the charging process.
 *
 * This function reads the analog value from the battery pin, converts it to a voltage, and prints the voltage
 * for monitoring purposes. It then checks if the battery voltage is below a predefined threshold. If the voltage
 * is below the threshold, it disables the charging by turning off the MOSFET. Otherwise, it enables charging.
 * The function includes a delay to avoid too frequent readings.
 *
 * @details
 * - Reads the analog value from the battery pin (A0).
 * - Converts the analog reading to voltage assuming a 3.3V reference for Wemos D1 Mini.
 * - Prints the battery voltage to the serial monitor.
 * - Checks if the battery voltage is below the threshold (e.g., 1V).
 * - Disables charging by turning off the MOSFET if the voltage is low.
 * - Enables charging by turning on the MOSFET if the voltage is above the threshold.
 * - Adds a delay of 1 second between readings.
 *
 * @note Adjust the delay as needed to balance between responsiveness and power consumption.
 */
/**
 * @brief Main loop function that continuously runs.
 * 
 * This function performs the following tasks in a loop:
 * 1. Starts the loading process using the state manager.
 * 2. Measures and prints the current battery voltage to the serial monitor.
 * 3. Adds a delay of 1 second to avoid too frequent readings.
 */
void loop()
{

  stateManager.startLoading();
  Serial.printf("Current Volatage: %f", battery.measureVoltage());

  // Add a delay to avoid too frequent readings (adjust the delay as needed)
  delay(1000); // Delay in milliseconds (1 second)
}
