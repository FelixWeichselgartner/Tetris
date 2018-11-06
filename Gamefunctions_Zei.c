//Ausformulierung der Prototypen aus der Header Datei Zei.h
//Von Marc Zeitler

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
char *gets(char *buffer);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Spielfiguren.h"
#include "Gameloop_Wei.h"
#include "Spielfeld_loh.h"

#define true 1
#define false 0

#define xlength 10
#define ylength 26

//Funktion zum Kopieren von arrays
void figcpy(char ptr[4][4], char ptrf[4][4]) {
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			ptrf[i][j] = ptr[i][j];
		}
	}
}

//Bewegliche arrays in feste umwandeln
void change() {
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<25; j++) {
			if (spielfeld[i][j] == 'O') {
				spielfeld[i][j] = 'X';
			}
		}
	}
}

//Funktion zur Zählung des Scores
int score(int x) {
	punktestand = punktestand + x;
}

//Funktion zum Spawnen der Teile im Feld
void spawn(){
	int x;
	char figur[4][4];
	//Auswählen einer Zufallsfigur für den nächsten Spawn-Array
	srand(time(0));
	x=rand()%18+1;
	//Kopieren der Zufallsfigur in den Figur Array
	switch(x){
		case 1: figcpy(figur, fig1); break;
		case 2: figcpy(figur, fig2); break;
		case 3: figcpy(figur, fig3); break;
		case 4: figcpy(figur, fig4); break;
		case 5: figcpy(figur, fig5); break;
		case 6: figcpy(figur, fig6); break;
		case 7: figcpy(figur, fig7); break;
		case 8: figcpy(figur, fig8); break;
		case 9: figcpy(figur, fig9); break;
		case 10: figcpy(figur, fig10); break;
		case 11: figcpy(figur, fig11); break;
		case 12: figcpy(figur, fig12); break;
		case 13: figcpy(figur, fig13); break;
		case 14: figcpy(figur, fig14); break;
		case 15: figcpy(figur, fig15); break;
		case 16: figcpy(figur, fig16); break;
		case 17: figcpy(figur, fig17); break;
		case 18: figcpy(figur, fig18); break;
		case 19: figcpy(figur, fig19); break;
	}
	//Kopieren des Figur-Arrays in den Spawn-Array
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			spielfeld[i+3][j]=figur[i][j];
		}
	}	
}

//Kollisionsprüfung
int collision(){
	for (int a = 0; a < 10; a++) {
		if(spielfeld[a][15]=='O'){
			change();
			return true;
			break;
		}
	}
	
	for(int i=0; i<10; i++){
		for(int j=0; j<25; j++){
			if(spielfeld[i][j]=='O'&&spielfeld[i][j+1]=='X'){
				change();
				return true;
				break;
			}
		}
	}
	return false;
}

//Funktion zum Löschen der Reihe
void reiheloeschen(){
	int i, j, x;
	i=0;
	j=4;
	do{
		if(i==9){
			for(x=j; x>0; x--){
				for(int a=0; a<10; a++){
					spielfeld[a][j]=spielfeld[a][j-1];
				}
				j--;
			}	
			punktestand=score(10);
		}
		if(spielfeld[i][j]=='X'||i<9){
			i++;
		}else {j++; i=0;}
	}while (j<25);
}

//Speicherung in einer Textdatei 
void highscore(){
	int fehler;
	char name[10];

	//hier würde ich davor erst mal die Datei erstellen -Felix
	//am besten mit w
	FILE *fptr;
	fptr=fopen("Highscores.txt", "a+");
	if(fptr==NULL){
		printf("\nDie Datei konnte nicht geoeffnet werden!\n");
		return;
	}
	
	printf("Name fuer die Highscoreliste eingeben (max 10 Buchstaben): ");
	scanf("%s", name);
	
	fprintf(fptr, "%s; %i;", name, punktestand);
	fprintf(fptr, "\n");
	
	fehler=fclose(fptr);
	if(fehler != 0){
		printf("\nFehler %i beim Schließen der Datei!\n", fehler);
	}
	
}
