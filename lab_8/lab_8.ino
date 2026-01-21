#include "arduino_secrets.h"

const int switchPin = 8;
unsigned long previousTime = 0;
unsigned long currentTime = 0; 
long interval = 1000; // 1 secunda pentru test

int switchState = 0;
int prevSwitchState = 0;
int led = 2; // Ãncepem cu pinul 2

void setup() {
  Serial.begin(9600);
  for (int x = 2; x <= 7; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  currentTime = millis();

  // --- LOGICA TIMERULUI ---
  if (currentTime - previousTime > interval) {
    previousTime = currentTime; // ResetÄm ceasul pentru urmÄtorul interval

    // Aprindem DOAR led-ul curent, nu pe toate
    digitalWrite(led, HIGH);
    
    // Trecem la urmÄtorul led
    led++;

    // SiguranÈÄ: DacÄ am aprins deja ultimul LED (pin 7),
    // nu vrem sÄ Ã®ncercÄm sÄ aprindem pinul 8 (care e senzorul!)
    if (led > 7) {
      // TIMPUL A EXPIRAT - Ãncepe spectacolul "Pom de CrÄciun"
      
      // Facem un "dans" al luminilor de 100 de paÈi
      for (int i = 0; i < 100; i++) {
        
        // Pasul 1: Alegem un LED la Ã®ntÃ¢mplare (Ã®ntre pinul 2 Èi 8-exclusiv, deci 7)
        int pinAleatoriu = random(2, 8); 
        
        // Pasul 2: Alegem o stare la Ã®ntÃ¢mplare (0 = stins, 1 = aprins)
        int stareAleatorie = random(0, 2); 
        
        // Pasul 3: ExecutÄm
        digitalWrite(pinAleatoriu, stareAleatorie);
        
        // Pasul 4: AÈteptÄm foarte puÈin (50ms) pentru efectul de tremurat
        delay(5); 
      }

      // DUPÄ ce s-a terminat spectacolul (aprox 5 secunde), resetÄm totul automat
      
      // Stingem totul curat
      for (int x = 2; x <= 7; x++) {
        digitalWrite(x, LOW);
      }
      
      // ResetÄm variabilele de timp Èi poziÈie
      led = 2;
      previousTime = millis();
    }
  }

  // --- LOGICA DE RESETARE (TILT) ---
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    // 1. Stingem toate LED-urile fizic
    for (int x = 2; x <= 7; x++) {
      digitalWrite(x, LOW);
    }
    
    // 2. ResetÄm logica
    led = 2; // FÄRÄ 'int' Ã®n faÈÄ! ResetÄm variabila globalÄ.
    previousTime = currentTime; // ResetÄm Èi cronometrul
  }

  prevSwitchState = switchState;
}