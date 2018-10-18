#ifndef GAMEFUNCTIONS_ZEI_H
#define GAMEFUNCTIONS_ZEI_H

void spawn(); //Spawnen der neuen Teile im Spawnbereich
void figcpy(char*, char*); //Funktion zum Kopieren von arrays
int collision(); //Returnwert 1: Kollision, 0: keine Kollision 
void change(); //Funktion zur Umwandlung der Steine von beweglich in fest
void reiheloeschen(); //Wenn eine Reihe voll ist, dann löschen
int score(int); //Volle Reihe bedeutet 1 Punkt-> Aufrufparameter
int highscore(int); //Returnwert 0: Fehler beim Speichern, 1: kein Fehler, Parameter ist score

#endif