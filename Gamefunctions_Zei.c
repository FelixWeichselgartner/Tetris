//Ausformulierung der Prototypen aus der Header Datei
//Von Marc Zeitler

//Funktion zum Spawnen der Teile im Feld
void spawn(){
	int x;
	char figur[4][4];
	//Auswählen einer Zufallsfigur für den nächsten Spawn-Array
	srand(time(0));
	x=rand(18)+1;
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

//Funktion zum Kopieren von arrays
void figcpy(char *ptr, char *ptrf){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			ptrf[i][j]=ptr[i][j];
		}
	}
}

//Kollisionsprüfung
int collision(){
	
	for(int a=0; a<10, a++){
		if(spielfeld[a][15]=='O'){
			change();
		}
	}
	
	for(int i=0; i<10; i++){
		for(int j=0; j<25; j++){
			if(spielfeld[i][j]=='O'&&spielfeld[i][j+1]=='X'){
				change();
			}
		}
	}
}

//Bewegliche arrays in feste umwandeln
void change(){
	for(int i=0; i<10; i++){
		for(int j=0; j<25; j++){
			if(spielfeld[i][j]=='O'){
				spielfeld[i][j]='X';
			}
		}
	}
}
