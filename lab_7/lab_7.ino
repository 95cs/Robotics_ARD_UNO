#include "arduino_secrets.h"

// --- CONFIGURARE ---
// FrecvenÈele notelor (Hz)
int nota_DO = 262;
int nota_RE = 294;
int nota_MI = 330;
int nota_FA = 349;

// VECTORI (ARRAYS)
// Lista cu pinii unde am legat LED-urile.
// Ordinea conteazÄ: {LED pt DO, LED pt RE, LED pt MI, LED pt FA}
// Indexul lor este:   0          1          2          3
int piniLed[] = {2, 3, 4, 5};

// Pinul Buzzerului
const int pinBuzzer = 8;

// --- FUNCÈII AJUTÄTOARE ---

// AceastÄ funcÈie face "munca murdarÄ" de a stinge tot Èi a aprinde doar ce trebuie.
// Parametrul 'index' ne spune care LED din listÄ sÄ se aprindÄ (0, 1, 2 sau 3).
// DacÄ primim -1, Ã®nseamnÄ cÄ stingem tot.
void aprindeLed(int index) {
  // 1. Stingem TOATE LED-urile (Reset)
  // Folosim un 'for' care numÄrÄ de la 0 la 3
  for (int i = 0; i < 4; i++) {
    digitalWrite(piniLed[i], LOW);
  }

  // 2. Aprindem doar LED-ul cerut, dacÄ indexul este valid (nu e -1)
  if (index != -1) {
    digitalWrite(piniLed[index], HIGH);
  }
}

// --- SETUP ---
void setup() {
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);

  // ConfigurÄm toÈi pinii LED-urilor ca OUTPUT folosind o buclÄ
  // Asta Ã®nlocuieÈte cele 4 linii pinMode scrise manual
  for (int i = 0; i < 4; i++) {
    pinMode(piniLed[i], OUTPUT);
  }
}

// --- LOOP ---
void loop() {
  int valoare = analogRead(A0);
  
  // Debug
  Serial.println(valoare);

  // --- LOGICA PRINCIPALÄ ---
  // ObservÄ cÃ¢t de curat este codul acum. 
  // Doar o linie pentru sunet Èi o linie pentru luminÄ.

  // BUTON 1 (DO) -> LED index 0 (Pin 2)
  if (valoare > 1015) {
    tone(pinBuzzer, nota_DO);
    aprindeLed(0); 
  }

  // BUTON 2 (RE) -> LED index 1 (Pin 3)
  else if (valoare >= 990 && valoare <= 1010) {
    tone(pinBuzzer, nota_RE);
    aprindeLed(1);
  }

  // BUTON 3 (MI) -> LED index 2 (Pin 4)
  else if (valoare >= 480 && valoare <= 515) {
    tone(pinBuzzer, nota_MI);
    aprindeLed(2);
  }

  // BUTON 4 (FA) -> LED index 3 (Pin 5)
  else if (valoare >= 85 && valoare <= 115) {
    tone(pinBuzzer, nota_FA);
    aprindeLed(3);
  }

  // NIMIC APÄSAT
  else {
    noTone(pinBuzzer);
    aprindeLed(-1); // -1 este codul nostru secret pentru "stinge tot"
  }
}