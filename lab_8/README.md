Smart Digital Hourglass (Lab 8)
This project demonstrates the ability to manage time and system states without blocking code execution.

Description

A digital timer that lights up LEDs at regular intervals. The project features a reset logic based on a tilt sensor (switch) and a complex random animation once the time interval expires.

Technical Features

Non-blocking Timing: Utilizes the millis() function to measure elapsed time without halting the processor, allowing for continuous sensor monitoring.

State Change Detection: The system detects changes in the tilt sensor's state (connected to pin 8) to reset the logic and the timer.

Animation Algorithm: Includes a "Christmas Tree" light show that generates random visual effects using the random() function across pins 2 through 7.

Hardware Management: Efficiently controls a sequence of 6 LEDs using a for loop to initialize and reset pins 2 to 7
