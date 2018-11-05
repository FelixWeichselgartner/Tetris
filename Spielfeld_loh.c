//#include<stdio.h>
//#define ylength 26
//#define xlength 10


void ausgabe(){

	printf("Tetris\n");
	
	int a, b;								//Zählvariable
	int c = xlength + 2;							// Spaltenanzahl rand = 12 --> 12 x _ + Endenull

	char spielfeld[ylength][xlength];					//Spielfelarray
	 

	for (a = 0; a <= ylength -1; a++) {		//Spielfeld befüllen
		for (b = 0; b <= xlength-1; b++) {
			spielfeld[a][b] = ' ';
		}
	}
								 
	//Ausgabe Spielfeld
	for (a = 0; a <=c; a++) {				// Ausgabe oberer Rand    
		printf("_");
	}
	printf("\n");
	for (a = 4; a <= ylength-1; a++) {		// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben
		printf("|");
		for (b = 0; b <= xlength-1; b++) {
			printf("%c", spielfeld[a][b]);
		}
		printf("|\n");
	}
	for (a = 0; a <= c; a++) {				 // Ausgabe unterer Rand
		printf("_");
	}										 
											 
	printf("\n");
	printf("Ende\n");
}



/*int main() {
	ausgabe();
	getch();
} */
