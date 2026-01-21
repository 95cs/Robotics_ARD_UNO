3. NTC Temperature Monitor (Lab 3)
Acest proiect demonstrează capacitatea de a lucra cu senzori analogici și de a aplica formule matematice complexe în software.

Descriere

Un sistem de monitorizare a temperaturii care utilizează un termistor NTC. Dispozitivul calculează temperatura reală în grade Celsius și oferă feedback vizual progresiv prin LED-uri în funcție de pragurile de căldură stabilite.

Caracteristici Tehnice

Modelare Matematică: Implementarea ecuației Steinhart-Hart pentru a converti rezistența variabilă a termistorului în unități de temperatură precise.

Calcul de Rezistență: Utilizarea legii lui Ohm pentru a deduce rezistența NTC dintr-o rețea de divizor de tensiune citită analogic.

Logică de Control Progresivă: Sistemul activează secvențial LED-urile pe măsură ce temperatura depășește un prag de bază (baseline), oferind o reprezentare vizuală a creșterii termice.

Debug Serial: Monitorizarea în timp real a valorilor brute ale senzorului și a temperaturii convertite prin interfața Serial.
