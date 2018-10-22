#include<stdio.h>
#define y 26
#define x 10


int main()

{
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
	
}
