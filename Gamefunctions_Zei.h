/*
* Tetris in C - header by Marc Zeitler
*/

#ifndef GAMEFUNCTIONS_ZEI_H
#define GAMEFUNCTIONS_ZEI_H

//void figcpy(char *, char *); //Funktion zum Kopieren von arrays
void figcpy(char ptr[4][4], char ptrf[4][4]);

void change(); //Funktion zur Umwandlung der Steine von beweglich in fest

int score(int); //Volle Reihe bedeutet 1 Punkt-> Aufrufparameter

void spawn(); //Spawnen der neuen Teile im Spawnbereich

int collision(); //Returnwert 1: Kollision, 0: keine Kollision 

void reiheloeschen(); //Wenn eine Reihe voll ist, dann löschen

void highscore(); //Returnwert 0: Fehler beim Speichern, 1: kein Fehler, Parameter ist score

#endif