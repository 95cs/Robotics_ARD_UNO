NTC Temperature Monitor (Lab 3)
This project demonstrates the capability to work with analog sensors and apply engineering mathematics to software.

Description

A temperature monitoring system using an NTC thermistor. The device calculates the real-time temperature in Celsius and provides progressive visual feedback via LEDs based on specific thermal thresholds.

Technical Features

Mathematical Modeling: Implementation of the Steinhart-Hart equation to convert the thermistor's variable resistance into accurate temperature units.

Resistance Calculation: Uses a formula based on a 10-bit analog reading and a fixed resistor value to deduce the NTC resistance.

Progressive Control Logic: The system sequentially activates LEDs (pins 2, 3, and 4) as the temperature rises above a defined baseline (25.0°C).

Serial Debugging: Real-time monitoring of both raw sensor values and converted Celsius degrees through the Serial interface.
