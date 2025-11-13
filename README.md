# Centralized-Fan-Control-in-real-time
Centralized Fan Control using ESP32 and DHT11
This project controls a centralized fan system based on the average temperature of multiple rooms. It uses an ESP32 and a DHT11 sensor to read the local temperature. The fan speed and buzzer are controlled automatically according to the temperature range.
This system saves energy by running the fan only when needed and increases the reliability of the centralized cooling system.
Components Used
•	ESP32
•	DHT11 Temperature Sensor
•	DC Fan
•	NPN Transistor (for fan control)
•	Buzzer
•	12V Power Supply
•	Jumper Wires
How It Works
The ESP32 reads temperature from the DHT11 sensors.
Values are averaged.
Based on the average:
•	10–25°C → Low speed
•	26–30°C → Medium speed
•	31–35°C → High speed
•	35°C → Full speed + Buzzer ON
•	<10°C → Fan OFF
Features
•	Automatic fan speed control
•	Buzzer alert for high temperature
•	Serial monitor display for readings
•	Real-time average temperature calculation
•	Saves energy by running fan efficiently
•	Improves reliability of centralized cooling system
