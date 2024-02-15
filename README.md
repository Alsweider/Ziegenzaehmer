# Ziegenzaehmer
Eine automatische Überprüfung des [Ziegenproblems](https://de.wikipedia.org/wiki/Ziegenproblem). 

![2024-02-15 12_33_27-Ziegenzaehmer v0 0 1](https://github.com/Alsweider/Ziegenzaehmer/assets/30653982/191e32aa-ebb2-42ae-bbf7-d787b5218dfc)


Programmablauf:
1. Der Computer wählt zufällig eines der drei Tore aus.
2. Er sortiert ein Ziegentor (Niete) aus, das nicht im ersten Zug gewählt wurde.
3. Er setzt seine zweite Wahl auf das verbleibende der drei Tore.
4. Es wird überprüft, ob er im ersten Zug gewonnen hätte oder erst nach dem Wechsel seiner Wahl. Beide Fälle für jede Runde werden aufgezeichnet.

Mögliche Fälle:
1. Er gewinnt im ersten Zug. (Nicht gewechselt + Gewonnen)
2. Er verliert im ersten Zug. (Nicht gewechselt + Verloren)
3. Er hätte im ersten Zug gewonnen, wechselt dann aber und erhält die verbleibende Ziege, die nicht aussortiert wurde. (Gewechselt + Verloren)
4. Er hätte im ersten Zug verloren, wechselt und gewinnt, da die letzte Ziege aussortiert wurde. (Gewechselt + Gewonnen)


