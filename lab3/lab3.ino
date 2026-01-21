#include "arduino_secrets.h"

const int sensorPin = A0;
float baselineTemp = 25.0; 

void setup() {
  Serial.begin(9600); 
  
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  
  // --- FORMULA CORECTATÄ PENTRU CIRCUITUL TÄU ---
  // Pentru cÄ ai pus termistorul la 5V (sus), formula este:
  // R_termistor = R_fixa * (1023 / sensorVal - 1)
  double R_NTC = 10000.0 * (1023.0 / (float)sensorVal - 1.0); 
  
  // Formula Steinhart-Hart pentru temperaturÄ
  float temperature = 1 / (log(R_NTC / 10000.0) / 3950.0 + 1 / (25.0 + 273.15)) - 273.15;
  // ---------------------------------------------

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Grade C: ");
  Serial.println(temperature); 

  // Logica LED-urilor
  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } 
  else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  delay(500); 
}