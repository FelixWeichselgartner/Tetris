#include<stdio.h>
#define y 26
#define x 10


int main()

{
	int a, b;				//Zählvariable
	char spielfeld[y][x];		//Spielfelarray

	for (a=0; a=y-1; a++){		//Spielfeld befüllen
		for (b=0; b=x-1; b++){
		spielfeld[a][b]	= " ";
		}
	}





							//Ausgabe Spielfeld
	char rand[12];
	for (a=0; a=12; a++){
		rand[c] = "_";
	}

	for (c=0; c=12; c++){		// Ausgabe oberer Rand
		printf(%c, rand[c]);
	}

	for (a=3; a=y-1; a++){		// Ausgabe Mittelteil, 4 obere Zeilen = Spawn -> werden nicht ausgegeben

		printf("|");
	
		for (b=0; b=x-1; b++){
		printf(%c, spielfeld[a][b]);
	
		printf("|");
	}
	

	for (c=0; c=12; c++){		// Ausgabe unterer Rand
		printf(%c, rand[c]);
	}
}