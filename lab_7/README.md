2. Analog Keyboard Instrument (Lab 7)
Acest proiect evidențiază scrierea unui cod curat, modular și utilizarea eficientă a resurselor hardware.

Descriere

Un instrument muzical de tip claviatură care folosește o scară de rezistențe pentru a citi mai multe butoane printr-un singur pin analogic. Fiecare buton declanșează o notă specifică și un indicator vizual.

Caracteristici Tehnice

Modularitate prin Vectori (Arrays): Pinii LED-urilor sunt gestionați într-un vector pentru a permite iterația și controlul centralizat.

Funcții Personalizate: Implementarea funcției aprindeLed(int index) pentru a reduce duplicarea codului și a gestiona stările LED-urilor într-un mod abstract.

Procesare Semnal Analogic: Interpretarea valorilor discrete primite de la un singur pin analogic pentru a diferenția între multiple intrări (butoane).

Feedback Audio-Vizual: Sincronizarea tonurilor generate de buzzer cu iluminarea LED-ului corespunzător.
