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
#define KEYSTATE 0

int punktestand = 0, farbe_formen = 0;

char spielfeld[xlength][ylength];

int abs(int x){
	if (x >= 0)
		return x;
	else return -x;
}

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

void delay(int milli_seconds) { //in milli_seconds
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int gameloop(){
	int direction;
	while(!verloren()){
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
	system("cls");
	ausgabe(farbe_formen);
	return true;
}

void down(){
	char tempfield[xlength][ylength];
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
	int time = 300000; //1000
	int delaytime = 0; //10
	int max = time;//delaytime time/delaytime/2
	int flagleft, flagright, flagfast, moveleft = false, moveright = false;

	for(int i=0; i<=max; i++){
		flagleft = GetAsyncKeyState(VK_LEFT);
		if (abs(flagleft) > 10000){
			moveleft = true;
			//break;
		}
		/*
		else {
			moveleft = false;
		}
		*/
		delay(delaytime);
		flagright = GetAsyncKeyState(VK_RIGHT);
		if (abs(flagright) > 10000){
			moveright = true;
			//break;
		}
		/*
		else {
			moveright = false;
		}
		*/
		
		flagfast = GetAsyncKeyState(VK_DOWN);
		if (abs(flagfast) > 10000)
			break;

		delay(delaytime);
	}

	if (moveleft == true && moveright == true) {
		moveleft = moveright = 0;
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
	#if KEYSTATE
		printf("direction = %i", direction);
		getch();
	#endif

	int leftboarder = false, rightboarder = false;

	//auch X steine werden als fehler interpretiert
	for(int i=0; i < ylength; i++){
		if (spielfeld[0][i] == 'O'){
			leftboarder = true;
		}
	}
	for (int i = 0; i < ylength; i++) {
		if (spielfeld[9][i] == 'O') {
			rightboarder = true;
		}
	}
	
	//1=left, 2=right
	if(direction == 1 && !leftboarder){
		for(int i = 0; i < ylength; i++){
			for(int k = 0; k < xlength; k++){
				if (spielfeld[k][i] == 'O') {
					spielfeld[k][i] = ' ';
					spielfeld[k - 1][i] = 'O';
				}
			}
		}
	}
	if (direction == 2 && !rightboarder) {
		for (int i = 0; i < ylength; i++) {
			for (int k = xlength; k >= 0; k--) {
				if (spielfeld[k][i] == 'O') {
					spielfeld[k][i] = ' ';
					spielfeld[k + 1][i] = 'O';
				}
			}
		}
	}
}

int verloren(){
	for(int i=0; i<xlength; i++){
		if (spielfeld[i][4] == 'X') {
			return true;
		}
	}
	return false;
}