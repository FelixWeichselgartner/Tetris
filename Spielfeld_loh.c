<<<<<<< HEAD
 #include<stdio.h>
#define ylength 26
#define xlenght 10
=======
#include<stdio.h>
#define y 26
#define x 10
>>>>>>> 63964b961a18af0d55f39f6f0679122e5ea32c8b


int main()

{
<<<<<<< HEAD
	printf("Tetris\n");
	

	int a, b;								//Zählvariable
	int c = xlenght + 2;					// Spaltenanzahl rand = 12 --> 12 x _ + Endenull

	char spielfeld[ylength][xlenght];		//Spielfelarray
	//char rand[c];

	for (a = 0; a <= ylength-1; a++) {		//Spielfeld befüllen
		for (b = 0; b <= xlenght-1; b++) {
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

		for (b = 0; b <= xlenght-1; b++) {
			printf("%c", spielfeld[a][b]);
		}
		printf("|\n");
	}

	for (a = 0; a <= c; a++) {				 // Ausgabe unterer Rand
		printf("_");
	}										 
											 
	printf("\n");
	 
	printf("Ende\n");
	
	getch();

=======
	printf("Geben Sie ein Zeichen ein");
	getch();
	
	int a, b;					//Zählvariable
	char spielfeld[y][x];		//Spielfelarray
	char rand[11];

	for (a=0; a<=y-1; a++){		//Spielfeld befüllen
		for (b=0; b=x-1; b++){
		spielfeld[a][b]	= ' ';
		}
	}

	//Ausgabe Spielfeld

	for (a=0; a<11; a++){
		rand[a] = "_";
	}

	for (a=0; a<11; a++){		// Ausgabe oberer Rand
		printf("%c", rand[a]);
	}

	for (a=4; a<=y-1; a++){		// Ausgabe Zeile 4, 4 obere Zeilen = Spawn -> werden nicht ausgegeben

		printf("|");
	
		for (b=0; b<=x-1; b++){
			printf("%c", spielfeld[a][b]);
		}
		printf("|");
	}
	

	for (a=0; a<11; a++){		// Ausgabe unterer Rand
		printf("%c", rand[a]);
	}
	
	getch();
	
>>>>>>> 63964b961a18af0d55f39f6f0679122e5ea32c8b
}
