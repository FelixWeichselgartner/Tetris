#include <stdio.h>
#include "Gameloop_Wei.h"
#include <Windows.h>

#define ylength 26
#define xlength 10

struct f {
	char fgr; //figur
	int clr; //color
	int spawnnumber;
};

void spielfeld_ausgabe() {

	CONSOLE_SCREEN_BUFFER_INFO Screen;				//Lokale Variablen
	WORD wOldColAttr;
	HANDLE hStdOut;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);		//Anweisungen
	GetConsoleScreenBufferInfo(hStdOut, &Screen);	//Aktuelle Konsoleninfo und  Textfarbe abspeichern
	wOldColAttr = Screen.wAttributes;
	SetConsoleTitleA("Tetris");						//Bennenung des Konsolenfensters ?ndern |||		SetConsoleTitleA("Name der Konsolenausgabe");
	SetConsoleTextAttribute(hStdOut, wOldColAttr);	//Farbauswahl ?ber Integerwerte

	char vertikaler_Randstein = 186;				//Hochteil									   

	for (int a = 4; a < ylength; a++) {				// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben
		printf("      %c", vertikaler_Randstein);
		for (int b = 0; b < xlength; b++) {
			SetConsoleTextAttribute(hStdOut, (spielfeld[b][a].clr));				//Zahl = Wert für Kombination aus Tabelle | Kombination aus Foreground + Background
			printf("%c", spielfeld[a][b]);
			SetConsoleTextAttribute(hStdOut, wOldColAttr);
		}
		printf("%c\n", vertikaler_Randstein);
	}
	SetConsoleTextAttribute(hStdOut, wOldColAttr);
}


 void ausgabe(){
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
	 
	 
			
	//Ausgabe Elemente über Spielfeld (Next)
	printf("   %c", Ecke_links_oben);
	for (a = 1; a <= 16; a++) {				 
		printf("%c", horizontaler_Baustein);	// Oberster Rand (Rand von next)
	}
	printf("%c\n", Ecke_rechts_oben);


	printf("   %c   Next:        %c\n", vertikaler_Randstein, vertikaler_Randstein);	//NEXT
	for (a = 1; a <= 3; a++) {
		printf("   %c                %c\n", vertikaler_Randstein, vertikaler_Randstein); // Rahmen von Next  
	}
	 

	printf("   %c%c%c%c", Ecke_links_unten, horizontaler_Baustein, horizontaler_Baustein, T_Verbinder_nach_unten);	// linker Teil der Linie zw Next und Spielfeld, 
	for (a = 3; a <=c; a++) {					// Linie zw Next und Spielfeld											da Linie breiter als Spielfeld
		printf("%c", horizontaler_Baustein);
	}
	printf("%c%c%c%c\n", T_Verbinder_nach_unten, horizontaler_Baustein, horizontaler_Baustein, Ecke_rechts_unten);	// rechter Teil der Linie zw Next und Spielfeld 


	//Ausgabe Spielfeld		 
	spielfeld_ausgabe();									//SPIELFELD!!!
	

	//Ausgabe Elemente unter Spielfeld
	printf("   %c%c%c", Ecke_links_oben, horizontaler_Baustein, horizontaler_Baustein); // linker Teil der Linie zw Score und Spielfeld, da Linie breiter als Spielfeld
	printf("%c", T_Verbinder);
	for (a = 3; a <= c; a++) {					// Ausgabe unterer Rand Spielfeld
		printf("%c", horizontaler_Baustein);
	}										 
	printf("%c%c%c%c\n", T_Verbinder, horizontaler_Baustein, horizontaler_Baustein, Ecke_rechts_oben);	// rechter Teil der Linie zw Score und Spielfeld	 


	printf("   %c  Score: %7i%c\n", vertikaler_Randstein, punktestand, vertikaler_Randstein);				//SCORE mit Randsteinen  


	printf("   %c", Ecke_links_unten);
	for (a = 1; a <= 16; a++) {					// Ausgabe unterster Rand (unter aktuellem Score)
		printf("%c", horizontaler_Baustein);
	}
	printf("%c\n", Ecke_rechts_unten); 
}

/* int main() {
	ausgabe();
	getch();
} */