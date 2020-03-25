#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tetris.hpp"
#include "Spielfiguren.hpp"

int VK_LEFT, VK_DOWN, VK_RIGHT = 0;
int get_key_state(int a) {
	return 0;
}

//Funktion zum Kopieren von arrays
void Tetris::place_fgr(struct f ptr[4][4], int rows, int columns, int x_start, int y_start) {
	int collision = 0, boarder = 0;
	for (int i = 3; i >= 4 - columns; i--) {
		for (int j = 0; j < rows; j++) {
			if (ptr[j][i].fgr != ' ') {
				if (spielfeld[j + x_start][i + y_start].fgr == 'X') {
					collision = 1;
					break;
				}
			}
		}
	}
	if (collision == 1) {
		return;
	}

	for (int i = 3; i >= 4 - columns; i--) {
		for (int j = 0; j < rows; j++) {
			//gr��er als 10
			//gr��er als 26
			if ((j + x_start) > 9 || (j+x_start) <0) {
				boarder = 1;
				break;
			}
			if ((i + y_start) > 25 || (i + y_start) < 0) {
				boarder = 1;
				break;
			}
		}
	}

	if (boarder == 1) {
		return;
	}

	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;

	for (int i = 0; i<xlength; i++) {
		for (int j = 0; j<ylength; j++) {
			if (spielfeld[i][j].fgr == 'O') {
				spielfeld[i][j] = empty;
			}
		}
	}

	for (int i = 3; i >= 4-columns; i--) {
		for (int j = 0; j < rows; j++) {
			if (ptr[j][i].fgr == 'O') {
				spielfeld[j+x_start][i+y_start] = ptr[j][i];
			//weil andersrum
			}
		}
	}
}

void Tetris::rotate_figure(char rotation) {
	int x_start = -1, y_start = -1, spawnn = -1;
	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;
	//first it shall be checked in how much rows and columns 'O' are
	//here the rows
	int rows = 0;
	int flag = 0;
	for (int k = 0; k < ylength; k++) {
		flag = 0;
		for(int i = 0; i < xlength; i++) {
			if (spielfeld[i][k].fgr == 'O') {
				if (spawnn == -1 && rotation == 'r') {
					spawnn = spielfeld[i][k].turnr;
				}
				if (spawnn == -1 && rotation == 'l') {
					spawnn = spielfeld[i][k].turnl;
				}
				if (x_start == -1) {
					x_start = i;
				}
				if (y_start == -1) {
					y_start = k;
				}
				rows++;
				flag = 1;
				break;
			}
		if (flag == 1)
			break;
		}
	}
	//here for the rows
	int columns = 0;
	for (int k = 0; k < xlength; k++) {
		flag = 0;
		for(int i = 0; i < ylength; i++) {
			if (spielfeld[k][i].fgr == 'O') {
				columns++;
				flag = 1;
				break;
			}
		if (flag == 1)
			break;
		}
	}

	if (spawnn == 3) {
		return;
	}

	switch (spawnn) {
	case 1: place_fgr(fig1, rows, columns, x_start, y_start); break;
	case 2: place_fgr(fig2, rows, columns, x_start, y_start); break;
	case 3: break;
	case 4: place_fgr(fig4, rows, columns, x_start, y_start); break;
	case 5: place_fgr(fig5, rows, columns, x_start, y_start); break;
	case 6: place_fgr(fig6, rows, columns, x_start, y_start); break;
	case 7: place_fgr(fig7, rows, columns, x_start, y_start); break;
	case 8: place_fgr(fig8, rows, columns, x_start, y_start); break;
	case 9: place_fgr(fig9, rows, columns, x_start, y_start); break;
	case 10: place_fgr(fig10, rows, columns, x_start, y_start); break;
	case 11: place_fgr(fig11, rows, columns, x_start, y_start); break;
	case 12: place_fgr(fig12, rows, columns, x_start, y_start); break;
	case 13: place_fgr(fig13, rows, columns, x_start, y_start); break;
	case 14: place_fgr(fig14, rows, columns, x_start, y_start); break;
	case 15: place_fgr(fig15, rows, columns, x_start, y_start); break;
	case 16: place_fgr(fig16, rows, columns, x_start, y_start); break;
	case 17: place_fgr(fig17, rows, columns, x_start, y_start); break;
	case 18: place_fgr(fig18, rows, columns, x_start, y_start); break;
	case 19: place_fgr(fig19, rows, columns, x_start, y_start); break;
	}
}

//Funktion zum Kopieren von arrays
void Tetris::figcpy(struct f ptr[4][4], struct f ptrf[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ptr[i][j] = ptrf[i][j];
			//weil andersrum
		}
	}
}

void Tetris::vertical_movement(int i) {
	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;
	spielfeld[0][i] = spielfeld[1][i] = spielfeld[2][i] = spielfeld[3][i] = spielfeld[4][i] = spielfeld[5][i] = spielfeld[6][i] = spielfeld[7][i] = spielfeld[8][i] = spielfeld[9][i] = empty;
	for (; i > 4; i--) {
		for (int k = 0; k < xlength; k++) {
			spielfeld[k][i] = spielfeld[k][i - 1];
		}
	}
}

//Bewegliche arrays in feste umwandeln
void Tetris::change() {
	for (int i = 0; i<xlength; i++) {
		for (int j = 0; j<ylength; j++) {
			if (spielfeld[i][j].fgr == 'O') {
				spielfeld[i][j].fgr = 'X';
			}
		}
	}
}

//Funktion zur Zählung des Scores
void Tetris::update_score(int x) {
	punktestand = punktestand + x;
}

//Funktion zum Spawnen der Teile im Feld
void Tetris::spawn_new_figure(){
	int x;
	struct f figur[4][4];
	//Auswählen einer Zufallsfigur für den nächsten Spawn-Array
	srand(time(0));
	//x = 7;
	//x = 2;
	x=rand()%23+1;
	//x = 3; //zum testen von reihelöschen
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
	
	for(int i=0; i < 4; i++){
		for(int j=0; j<4; j++){
			spielfeld[i+3][j] = figur[i][j];
		}
	}	
}

//Kollisionsprüfung
int Tetris::check_collision(){
	for (int a = 0; a < xlength; a++) { 
		if(spielfeld[a][ylength-1].fgr == 'O'){
			change();
			return true;
		}
	}
	
	for(int i=0; i<ylength; i++){
		for(int j=0; j<xlength; j++){ 
			if(spielfeld[j][i].fgr == 'O' && spielfeld[j][i+1].fgr == 'X'){
				change();
				return true;
			}
		}
	}
	return false;
}

//Funktion zum Löschen der Reihe
void Tetris::delete_line(){
	for (int i = 25; i >= 0; i--) {
		if (spielfeld[0][i].fgr == 'X' && spielfeld[1][i].fgr == 'X' && spielfeld[2][i].fgr == 'X' && spielfeld[3][i].fgr == 'X' && spielfeld[4][i].fgr == 'X' && spielfeld[5][i].fgr == 'X' && spielfeld[6][i].fgr == 'X' && spielfeld[7][i].fgr == 'X' && spielfeld[8][i].fgr == 'X' && spielfeld[9][i].fgr == 'X') {
			vertical_movement(i);
			punktestand += 10;
			delete_line(); //rekursive funktion
		}
	}
}

//Speicherung in einer Textdatei 
void Tetris::highscore(){
	int fehler;
	char name[10];
	FILE *fptr;
	fptr=fopen("Highscores.txt", "a+");
	if(fptr==NULL){
		printf("\nDie Datei konnte nicht geoeffnet werden!\n");
		return;
	}
	fflush(stdin);
	while (getchar() != '\n');
	//hier virtuelles enter
	//system("cls");
	//ausgabe();
	printf("Name fuer die Highscoreliste eingeben (max 10 Buchstaben): ");
	scanf("%s", name);
	
	fprintf(fptr, "%s; %i;", name, punktestand);
	fprintf(fptr, "\n");
	
	fehler=fclose(fptr);
	if(fehler != 0){
		printf("\nFehler %i beim Schließen der Datei!\n", fehler);
	}
	highscore_aufruf();
}


void Tetris::run() {
    init_spielfeld();
	init_figuren();
	int vorbei = gameloop();
	if(vorbei == true){
		highscore();
	}
}


int abs(int x){
	if (x >= 0)
		return x;
	else return -x;
}

void Tetris::delay(int milli_seconds) {
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void Tetris::init_spielfeld(){
	for(int i=0; i<xlength; i++){
		for(int k=0; k<ylength; k++){
			spielfeld[i][k] = empty;
		}
	}
}

int Tetris::gameloop(){
	int flag_spawn = 1;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;
	int direction, drehenrechts, drehenlinks;
	while(!check_lost()){
		spawn_new_figure();
		flag_spawn = 1;
		while(check_collision() == false){
			if (flag_spawn != 0)
				down();
			input();
		}
		delete_line();
	}
	system("cls");
	ausgabe();
	return true;
}

void Tetris::down(){
	struct f tempfield[xlength][ylength];
	for(int i=0; i < ylength; i++){
		for(int k=0; k < xlength; k++){
			tempfield[k][i] = spielfeld[k][i];
			if (spielfeld[k][i].fgr == 'O') {
				spielfeld[k][i] = empty;
			}
		}
	}
	for(int i=0; i < ylength; i++){
		for(int k=0; k < xlength; k++){
			if (tempfield[k][i].fgr == 'O')
				spielfeld[k][i+1] = tempfield[k][i];
		}
	}
}

void Tetris::input(){
	int flagleft = 0, flagright = 0, flagfast = 0, flagdrehenlinks = 0, flagdrehenrechts = 0;
	int milli_seconds = 1000, drehenrechts = 0, drehenlinks = 0;
	clock_t start_time = clock(); 

    while (clock() < start_time + milli_seconds) {
		system("cls");
		ausgabe();
		//delay nur damit das Spielfeld nicht zu oft aktualisiert wird
		delay(50);

		flagleft = get_key_state(VK_LEFT);
		if (abs(flagleft) > 10000) {
			horizontal_movement('l');
			flagleft = 0;
		}
		flagright = get_key_state(VK_RIGHT);
		if (abs(flagright) > 10000) {
			horizontal_movement('r');
			flagright = 0;
		}
		flagfast = get_key_state(VK_DOWN);
		if (abs(flagfast) > 10000) {
			break;
		}
		flagdrehenrechts = get_key_state(0x44); //0x44 ist d
		if (abs(flagdrehenrechts) > 10000) {
			rotate_figure('r');
			flagdrehenrechts = 0;
		}
		flagdrehenlinks = get_key_state(0x41); //0x41 ist a
		if (abs(flagdrehenlinks) > 10000) {
			rotate_figure('l');
			flagdrehenlinks = 0;
		}
	}
	return;
}

void Tetris::horizontal_movement(char direction){
	int leftboarder = false, rightboarder = false, leftfigur = false, rightfigur = false;
	struct f temp;
	temp.fgr = ' ';
	temp.clr = 0;
	temp.spawnnumber = 0;
	temp.turnr = 0;
	temp.turnl = 0;

	for(int i=0; i < ylength; i++){
		if (spielfeld[0][i].fgr == 'O'){
			leftboarder = true;
		}
	}
	for (int i = 0; i < ylength; i++) {
		if (spielfeld[9][i].fgr == 'O') {
			rightboarder = true;
		}
	}
	for (int i = 0; i < ylength; i++) {
		for (int k = 0; k < xlength; k++) {
			if (spielfeld[k][i].fgr == 'O' && spielfeld[k - 1][i].fgr == 'X') {
				leftfigur = true;
			}
		}
	}
	for (int i = 0; i < ylength; i++) {
		for (int k = 0; k < xlength; k++) {
			if (spielfeld[k][i].fgr == 'O' && spielfeld[k + 1][i].fgr == 'X') {
				rightfigur = true;
			}
		}
	}
	if(direction == 'l' && !leftboarder && !leftfigur){
		for(int i = 0; i < ylength; i++){
			for(int k = 0; k < xlength; k++){
				if (spielfeld[k][i].fgr == 'O') {
					temp = spielfeld[k][i];
					spielfeld[k][i] = empty;
					spielfeld[k - 1][i] = temp;
					
				}
			}
		}
	}
	if (direction == 'r' && !rightboarder && !rightfigur) {
		for (int i = 0; i < ylength; i++) {
			for (int k = xlength; k >= 0; k--) {
				if (spielfeld[k][i].fgr == 'O') {
					temp = spielfeld[k][i];
					spielfeld[k][i] = empty;
					spielfeld[k + 1][i] = temp;
				}
			}
		}
	}
}

int Tetris::check_lost(){
	for(int i=0; i<xlength; i++){
		if (spielfeld[i][4].fgr == 'X') {
			return true;
		}
	}
	return false;
}
