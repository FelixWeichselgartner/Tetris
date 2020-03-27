/*
* Tetris in C - header by Matthias Lohberger
*/

#include <stdio.h>
#include "Tetris.hpp"
#include <string.h>



//Bausteine für die Umrandung
char vertikaler_Randstein = 186;		//vertikaler_Randstein
char Ecke_rechts_oben = 187;			//Eckteil rechts oben
char Ecke_rechts_unten = 188;			//Eckteil rechts unten
char Ecke_links_unten = 200;			//Eckteil links unten
char Ecke_links_oben = 201;				//Eckteil links oben
char T_Verbinder = 202;					//_|_ Verbinder
char T_Verbinder_nach_unten = 203;		//anderer Verbinder
char horizontaler_Baustein = 205;		//Querteil
char T_Verbinder_rechte_Seite = 185;	//Verbinder rechte Seite
char T_Verbinder_linke_Seite = 204;		//Verbinder linke Seite
 

void Tetris::spielfeld_ausgabe() {

	//CONSOLE_SCREEN_BUFFER_INFO Screen;				//Lokale Variablen
	//WORD wOldColAttr;
	//HANDLE hStdOut;

	//hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);		//Anweisungen
	//GetConsoleScreenBufferInfo(hStdOut, &Screen);	//Aktuelle Konsoleninfo und  Textfarbe abspeichern
	//wOldColAttr = Screen.wAttributes;
	//SetConsoleTitleA("Tetris");						//Bennenung des Konsolenfensters ?ndern |||		SetConsoleTitleA("Name der Konsolenausgabe");
	//SetConsoleTextAttribute(hStdOut, wOldColAttr);	//Farbauswahl ?ber Integerwerte
								   

	for (int a = 4; a < ylength; a++) {		// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben
		printf("      %c", vertikaler_Randstein);
		for (int b = 0; b < xlength; b++) {
			//SetConsoleTextAttribute(hStdOut, field[b][a].clr); 	//Zahl = Wert für Kombination aus Tabelle | Kombination aus Foreground + Background
			printf("%c", field[b][a].fgr);
			//SetConsoleTextAttribute(hStdOut, wOldColAttr);
		}
		printf("%c\n", vertikaler_Randstein);
	}

	//SetConsoleTextAttribute(hStdOut, wOldColAttr);
}


void oberer_Teil() {
	int a;
	int c = xlength + 2;					// Spaltenanzahl rand = 12 --> 12 x _ + Endenull
	
	printf("   %c", Ecke_links_oben);
	for (a = 1; a <= 16; a++) {
		printf("%c", horizontaler_Baustein);	// Oberster Rand (Rand von Titel)
	}
	printf("%c\n", Ecke_rechts_oben);

	printf("   %c                %c\n", vertikaler_Randstein, vertikaler_Randstein); // Rahmen von Titel

	printf("   %c     ", vertikaler_Randstein, vertikaler_Randstein);	//TITEL
	printf("Tetris");
	printf("     %c\n", vertikaler_Randstein, vertikaler_Randstein);		//TITEL

	for (a = 1; a <= 2; a++) {
		printf("   %c                %c\n", vertikaler_Randstein, vertikaler_Randstein); // Rahmen von Titel  
	}


	printf("   %c%c%c%c", Ecke_links_unten, horizontaler_Baustein, horizontaler_Baustein, T_Verbinder_nach_unten);	// linker Teil der Linie zw Titel und field, 
	for (a = 3; a <= c; a++) {					// Linie zw Next und field											da Linie breiter als field
		printf("%c", horizontaler_Baustein);
	}
	printf("%c%c%c%c\n", T_Verbinder_nach_unten, horizontaler_Baustein, horizontaler_Baustein, Ecke_rechts_unten);	// rechter Teil der Linie zw Titel und field 
}


void Tetris::unterer_Teil() {
	int a;
	int c = xlength + 2;					// Spaltenanzahl rand = 12 --> 12 x _ + Endenull

	printf("   %c%c%c", Ecke_links_oben, horizontaler_Baustein, horizontaler_Baustein); // linker Teil der Linie zw Score und field, da Linie breiter als field
	printf("%c", T_Verbinder);
	for (a = 3; a <= c; a++) {					// Ausgabe unterer Rand field
		printf("%c", horizontaler_Baustein);
	}
	printf("%c%c%c%c\n", T_Verbinder, horizontaler_Baustein, horizontaler_Baustein, Ecke_rechts_oben);	// rechter Teil der Linie zw Score und field	 


	printf("   %c  Score: %7i%c\n", vertikaler_Randstein, score, vertikaler_Randstein);				//SCORE mit Randsteinen  


	printf("   %c", Ecke_links_unten);
	for (a = 1; a <= 16; a++) {					// Ausgabe unterster Rand (unter aktuellem Score)
		printf("%c", horizontaler_Baustein);
	}
	printf("%c\n", Ecke_rechts_unten);
}


void Tetris::highscore_aufruf() {						//Highscoreausgabe
	char c;												//Hilfsarray
	int a = 0;											//Zählvariable
	FILE *fptr;
	int fehler;

	printf("\nHighscoreliste:\n");
	printf("\n");
									//aus Datei lesen
	fptr = fopen("Highscores.txt", "r");
	if (fptr == NULL) {
		printf("\nDie Datei konnte nicht geoeffnet werden!\n");
		return;
	}
	while (!feof(fptr)) {			//Ausgabe
		c = fgetc(fptr);
		
		if (c == ';' && a <= 7) {
			printf("\t\t");			//für kleinere Namen
		}
		else if (c == ';' && a > 7) {
			printf("\t");				//für größere Namen
		}
		else if (c == '\n') {
			putchar(c);					//a zurücksetzten
			a = 0;
		}
		else {
			putchar(c);					//normale Ausgabe, a wird erhöht
			a++;
		}
	}
	fehler = fclose(fptr);
	if (fehler != 0) {					//Datei schließen
		printf("\nFehler %i beim Schließen der Datei!\n", fehler);
		return;
	}
	getchar();
}



void Tetris::ausgabe() {
	 
	int a;									//Zählvariable
	int c = xlength + 2;					// Spaltenanzahl rand = 12 --> 12 x _ + Endenull
		 
	printf("\n\n");
	 
	//Ausgabe Elemente über field (Next) 
	oberer_Teil(); 

	//Ausgabe field		 
	spielfeld_ausgabe();									//field!!!
	
	//Ausgabe Elemente unter field
	unterer_Teil();
}

 