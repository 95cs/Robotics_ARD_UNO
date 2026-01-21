1. Smart Digital Hourglass (Lab 8)
Acest proiect demonstrează abilitatea de a gestiona timpul și stările sistemului fără a bloca execuția codului.

Descriere

Un cronometru digital care aprinde LED-uri la intervale regulate de timp. Proiectul include o logică de resetare bazată pe un senzor de înclinare (tilt sensor) și o animație complexă la finalizarea intervalului.


Caracteristici Tehnice

Non-blocking Timing: Utilizarea funcției millis() pentru a măsura trecerea timpului fără a opri procesorul, permițând monitorizarea continuă a senzorilor.

State Change Detection: Sistemul detectează schimbarea stării senzorului de înclinare pentru a reseta cronometrul.

Algoritm de Animație: Include o secvență de tip "Christmas Tree" care generează efecte vizuale aleatorii folosind funcția random() la finalul ciclului de timp.

Gestionare Hardware: Controlul eficient al unei matrice de 6 LED-uri (pinii 2-7).
