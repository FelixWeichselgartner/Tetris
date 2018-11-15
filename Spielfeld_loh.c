#include <stdio.h>
#include "Gameloop_Wei.h"
#include <Windows.h>

#define ylength 26
#define xlength 10

void single_ausgabe() {
	for (int i = 0; i < ylength; i++) {
		for (int k = 0; k < xlength; k++) {
			printf("%c", spielfeld[k][i].fgr);
		}
		printf("\n");
	}
	printf("\n");
}

void ausgabe(int farbe_formen){
	printf("\n\n         TETRIS\n\n");
	
	int a, b;								//Zählvariablen
	int c = xlength + 2;					// Spaltenanzahl rand = 12 --> 12 x _ + Endenull
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
	 
	 
			
	//Ausgabe über Spielfeld

	printf("   %c", Ecke_links_oben);
	for (a = 1; a <= 16; a++) {				// Ausgabe oberer Rand next
		printf("%c", horizontaler_Baustein);
	}
	printf("%c\n", Ecke_rechts_oben);
	printf("   %c   Next:        %c\n", vertikaler_Randstein, vertikaler_Randstein);	//Next Teil
	for (a = 1; a <= 3; a++) {
		printf("   %c                %c\n", vertikaler_Randstein, vertikaler_Randstein);
	}
	 
	printf("   %c%c%c%c", Ecke_links_unten, horizontaler_Baustein, horizontaler_Baustein, T_Verbinder_nach_unten);
	for (a = 3; a <=c; a++) {				// Ausgabe oberer Rand Spielfeld    
		printf("%c", horizontaler_Baustein);
	}
	printf("%c%c%c%c\n", T_Verbinder_nach_unten, horizontaler_Baustein, horizontaler_Baustein, Ecke_rechts_unten);

	//Ausgabe Spielfeld
	
	
	 for (a = 4; a < ylength; a++) {			// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben
		printf("      %c", vertikaler_Randstein);				
		for (b = 0; b < xlength; b++) {		
			printf("%c", spielfeld[b][a].fgr);	
		}									
		printf("%c\n", vertikaler_Randstein);					
	} 
	
	//Ausgabe_mit_Farbzuweisung(Kennziffer_Teilchen); //Kennziffer von Mark übergeben
	

	//Ausgabe  unter eSpielfeld
	printf("   %c%c%c", Ecke_links_oben, horizontaler_Baustein, horizontaler_Baustein);
	printf("%c", T_Verbinder);
	for (a = 3; a <= c; a++) {				 // Ausgabe unterer Rand Spielfeld
		printf("%c", horizontaler_Baustein);
	}										 
	printf("%c%c%c%c\n", T_Verbinder, horizontaler_Baustein, horizontaler_Baustein, Ecke_rechts_oben);		//Score Teil
	printf("   %c  Score:        %c\n", vertikaler_Randstein, vertikaler_Randstein);
	printf("   %c                %c\n", vertikaler_Randstein, vertikaler_Randstein);
	printf("   %cHighscore:      %c\n", vertikaler_Randstein, vertikaler_Randstein);
	printf("   %c", T_Verbinder_linke_Seite);						//unterer Rand Score Teil
	for (a = 1; a <= 16; a++) {				// Ausgabe oberer Rand next
		printf("%c", horizontaler_Baustein);
	}
	printf("%c\n", T_Verbinder_rechte_Seite);
	printf("   %cName:           %c\n", vertikaler_Randstein, vertikaler_Randstein);	//Spielername
	printf("   %c", Ecke_links_unten);
	for (a = 1; a <= 16; a++) {				// Ausgabe unterer Rand Name
		printf("%c", horizontaler_Baustein);
	}
	printf("%c\n", Ecke_rechts_unten); 
}

void farbige_Ausgabe(int color) {		//xlength und y length (nein, da global) sowie Farbwert für O's übergeben!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	CONSOLE_SCREEN_BUFFER_INFO Screen;	//Lokale Variablen
	WORD wOldColAttr;
	HANDLE hStdOut;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);	//Anweisungen
	GetConsoleScreenBufferInfo(hStdOut, &Screen);	//Aktuelle Konsoleninfo und  Textfarbe abspeichern
	wOldColAttr = Screen.wAttributes;
	SetConsoleTitleA("Tetris");					//Bennenung des Konsolenfensters ?ndern |||		SetConsoleTitleA("Name der Konsolenausgabe");
	SetConsoleTextAttribute(hStdOut, wOldColAttr); //Farbauswahl ?ber Integerwerte

	char vertikaler_Randstein = 186;		//Hochteil									   
	int var;								 //spielfeldgröße 10 26!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	for (int a = 4; a < ylength; a++) {		// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben
		printf("      %c", vertikaler_Randstein);
		for (int b = 0; b < xlength; b++) {

			switch (spielfeld[b][a].fgr) {
			case 'O': var = color; break;		//Variabel für jew Teilchen;!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			case 'X': var = 136; break;			//feste Kästchen unten werden grau/ Wert 136
			default: var = 0; break;
			}
			SetConsoleTextAttribute(hStdOut, (var));				//Zahl = Wert für Kombination aus Tabelle | Kombination aus Foreground + Background
			printf("%c", spielfeld[a][b]);
			SetConsoleTextAttribute(hStdOut, wOldColAttr);
		}
		printf("%c\n", vertikaler_Randstein);
	}
	SetConsoleTextAttribute(hStdOut, wOldColAttr);
}
 
 

/* int main() {
	ausgabe();
	getch();
} */