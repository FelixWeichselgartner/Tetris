/*
* Tetris in C - header by Felix Weichselgartner
*/

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Gamefunctions_Zei.h"
#include "Spielfeld_loh.h"
#include "Spielfiguren.h"
#include "Gameloop_Wei.h"

#define true 1
#define false 0

#define xlength 10
#define ylength 26

#define DEBUG 0

int punktestand = 0;

int farbe_formen = 0;

char spielfeld[xlength][ylength];

char tempfield[xlength][ylength];

void debug_s() {
	system("cls");
	ausgabe(0);
}

void init_spielfeld(){
	for(int i=0; i<xlength; i++){
		for(int k=0; k<ylength; k++){
			spielfeld[i][k] = ' ';
		}
	}
}

void init_tempfield() {
	for (int i = 0; i<xlength; i++) {
		for (int k = 0; k<ylength; k++) {
			tempfield[i][k] = ' ';
		}
	}
}

void delay(int milli_seconds) { //in milli_seconds
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int gameloop(){
	int direction;
	while(verloren() != false){
		spawn();
		while(collision() == false){
			system("cls");

			#if DEBUG == 0
				ausgabe(farbe_formen);
			#endif

			#if DEBUG
			debug_s();
			printf("start");
				getch();
			#endif

			direction = leftright();
			#if DEBUG
				debug_s();
				printf("leftright");
				getch();
			#endif

			copyleftright(direction);
			#if DEBUG
				debug_s();
				printf("cpy leftright");
				getch();
			#endif

			down();
			#if DEBUG
				debug_s();
				printf("down");
				getch();
			#endif
		}
		reiheloeschen(); //reiheloeschen() -> score()
	}
	return true;
}

void down(){
	init_tempfield();
	for(int i=0; i < ylength; i++){
		for(int k=0; k < xlength; k++){
			tempfield[k][i] = spielfeld[k][i];
			if (spielfeld[k][i] == 'O')
				spielfeld[k][i] = ' ';
		}
	}
	for(int i=0; i < ylength; i++){
		for(int k=0; k < xlength; k++){
			if (tempfield[k][i] == 'O')
				spielfeld[k][i+1] = 'O';
		}
	}
}

int leftright(){
	int left = 'a', right = 'd';
	int time = 1000;
	int delaytime = 1000; //10
	int max = time/2/delaytime;
	int flagleft, flagright;
	int moveleft, moveright;
	for(int i=0; i<=max; i++){
		flagleft = GetAsyncKeyState('a');
		if (flagleft == true){
			moveleft = true;
		}
		else {
			moveleft = false;
		}
		delay(delaytime);
		flagright = GetAsyncKeyState('d');
		if (flagright == true){
			moveright = true;
		}
		else {
			moveright = false;
		}
		delay(delaytime);
	}
	if (moveleft == true && moveright == true){ //moveleft used without being initialized
		return 0;
	}
	if (moveleft == true){
		return 1;
	}
	if (moveright == true){
		return 2;
	}
}

void copyleftright(int direction){
	int flag;
	for(int i=0; i<ylength; i++){
		if (spielfeld[0][i] != ' ' || spielfeld[10][i] != ' '){ //zweites kein plan ob des stimmt
			flag = true;
		}
	}
	if (flag == true)
		return;
	//1=left, 2=right
	char temp_field[xlength][ylength];
	if(direction == 1){
		for(int i=0; i<xlength; i++){
			for(int k=0; k<ylength; k++){
				spielfeld[i][k] = temp_field[i][k];
				if (spielfeld[i][k] == 'O')
					spielfeld[i][k] = ' ';
			}
		}
		for(int i=0; i<xlength; i++){
			for(int k=0; k<ylength; k++){
				if (tempfield[i][k] == 'O')
					spielfeld[i-1][k] = 'O';
				temp_field[i][k] = temp_field[i][k];
			}
		}
	}
	if(direction == 2){
		for(int i=0; i<xlength; i++){
			for(int k=0; k<ylength; k++){
				spielfeld[i][k] = temp_field[i][k];
				if (spielfeld[i][k] == 'O')
					spielfeld[i][k] = ' ';
			}
		}
		for(int i=0; i<xlength; i++){
			for(int k=0; k<ylength; k++){
				if (tempfield[i][k] == 'O')
					spielfeld[i+1][k] = 'O';
				temp_field[i][k] = temp_field[i][k];
			}
		}
	}
}

int verloren(){
	for(int i=0; i<xlength; i++){
		if (spielfeld[i][4] == 'X')
			return true;
	}
}
