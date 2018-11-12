#include <stdio.h>
#include "Gameloop_Wei.h"

#define ylength 26
#define xlength 10

void single_ausgabe() {
	for (int i = 0; i < ylength; i++) {
		for (int k = 0; k < xlength; k++) {
			printf("%c", spielfeld[k][i]);
		}
		printf("\n");
	}
	printf("\n");
}

void ausgabe(int farbe_formen){
	printf("\n\n         TETRIS\n\n");
	
	int a, b;								//Zählvariable
	int c = xlength + 2;					// Spaltenanzahl rand = 12 --> 12 x _ + Endenull

	char d = 186;		//Hochteil
	char e = 187;		//Eckteil rechts oben
	char f = 188;		//Eckteil rechts unten
	char g = 200;		//Eckteil links unten
	char h = 201;		//Eckteil links oben
	char k = 202;		//_|_ Verbinder
	char l = 203;		//anderer Verbinder
	char m = 205;		//Querteil
	char n = 185;		//Verbinder rechte Seite
	char p = 204;		//Verbinder linke Seite
	 
	/*
	for (a = 0; a <= ylength -1; a++) {		//Spielfeld befüllen
		for (b = 0; b <= xlength-1; b++) {
			spielfeld[a][b] = ' ';
		}
	}
	*/
			
	//Ausgabe Spielfeld

	printf("   %c", h);
	for (a = 1; a <= 16; a++) {				// Ausgabe oberer Rand next
		printf("%c", m);
	}
	printf("%c\n", e);
	printf("   %c   Next:        %c\n", d, d);	//Next Teil
	for (a = 1; a <= 3; a++) {
		printf("   %c                %c\n", d, d);
	}
	 
	printf("   %c%c%c%c", g, m, m, l);
	for (a = 3; a <=c; a++) {				// Ausgabe oberer Rand Spielfeld    
		printf("%c", m);
	}
	printf("%c%c%c%c\n", l, m, m, f);

	
	for (a = 4; a < ylength; a++) {		// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben
		printf("      %c", d);
		for (b = 0; b < xlength; b++) {
			printf("%c", spielfeld[b][a]);
		}
		printf("%c\n", d);
	}
	

	printf("   %c%c%c", h, m, m);
	printf("%c", k);
	for (a = 3; a <= c; a++) {				 // Ausgabe unterer Rand Spielfeld
		printf("%c", m);
	}										 
	printf("%c%c%c%c\n", k, m, m, e);		//Score Teil
	printf("   %c  Score:        %c\n", d, d);
	printf("   %c                %c\n", d, d);
	printf("   %cHighscore:      %c\n", d, d);
	printf("   %c", p);						//unterer Rand Score Teil
	for (a = 1; a <= 16; a++) {				// Ausgabe oberer Rand next
		printf("%c", m);
	}
	printf("%c\n", n);
	printf("   %cName:           %c\n", d, d);	//Spielername
	printf("   %c", g);
	for (a = 1; a <= 16; a++) {				// Ausgabe unterer Rand Name
		printf("%c", m);
	}
	printf("%c\n", f); 
}

/* int main() {
	ausgabe();
	getch();
} */