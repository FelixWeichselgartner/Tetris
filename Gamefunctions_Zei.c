/*
* Tetris in C - header by Marc Zeitler
*/

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

struct f {
	char fgr; //figur
	int clr; //color
	int spawnnumber;
};

//Funktion zum Kopieren von arrays
void figcpy(struct f ptr[4][4], struct f ptrf[4][4]) {
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			ptr[i][j] = ptrf[i][j];
		}
	}
}

void dwn(int i) {
	spielfeld[0][i].fgr = spielfeld[1][i].fgr = spielfeld[2][i].fgr = spielfeld[3][i].fgr = spielfeld[4][i].fgr = spielfeld[5][i].fgr = spielfeld[6][i].fgr = spielfeld[7][i].fgr = spielfeld[8][i].fgr = spielfeld[9][i].fgr = ' ';
	for (; i >= 4; i--) {
		for (int k = 0; k < xlength; k++) {
			spielfeld[k][i] = spielfeld[k][i - 1];
		}
	}
}

//Bewegliche arrays in feste umwandeln
void change() {
	for (int i = 0; i<xlength; i++) {
		for (int j = 0; j<ylength; j++) {
			if (spielfeld[i][j].fgr == 'O') {
				spielfeld[i][j].fgr = 'X';
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
	struct f figur[4][4];
	//Auswählen einer Zufallsfigur für den nächsten Spawn-Array
	srand(time(0));
	x=rand()%23+1;
	//x = 3; zum testen von reihelöschen
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
		case 20: figcpy(figur, fig3); break;
		case 21: figcpy(figur, fig3); break;
		case 22: figcpy(figur, fig3); break;
		case 23: figcpy(figur, fig1); break;
		case 24: figcpy(figur, fig2); break;
	}
	//Kopieren des Figur-Arrays in den Spawn-Array
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			spielfeld[i+3][j] = figur[i][j];
		}
	}	
}

//Kollisionsprüfung
int collision(){
	for (int a = 0; a < xlength; a++) { 
		if(spielfeld[a][ylength-1].fgr =='O'){
			change();
			return true;
		}
	}
	
	for(int i=0; i<ylength; i++){
		for(int j=0; j<xlength; j++){ 
			if(spielfeld[j][i].fgr =='O'&&spielfeld[j][i+1].fgr =='X'){
				change();
				return true;
			}
		}
	}
	return false;
}

//Funktion zum Löschen der Reihe
void reiheloeschen(){
	for (int i = 25; i >= 0; i--) {
		if (spielfeld[0][i].fgr == 'X' && spielfeld[1][i].fgr == 'X' && spielfeld[2][i].fgr == 'X' && spielfeld[3][i].fgr == 'X' && spielfeld[4][i].fgr == 'X' && spielfeld[5][i].fgr == 'X' && spielfeld[6][i].fgr == 'X' && spielfeld[7][i].fgr == 'X' && spielfeld[8][i].fgr == 'X' && spielfeld[9][i].fgr == 'X') {
			dwn(i);
			punktestand += 10;
			reiheloeschen(); //rekursive funktion
		}
	}
}

//Speicherung in einer Textdatei 
void highscore(){
	int fehler;
	char name[10];
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
