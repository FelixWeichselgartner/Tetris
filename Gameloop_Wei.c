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

int punktestand = 0, farbe_formen = 0;
char spielfeld[xlength][ylength];

int abs(int x){
	if (x >= 0)
		return x;
	else return -x;
}

void init_spielfeld(){
	for(int i=0; i<xlength; i++){
		for(int k=0; k<ylength; k++){
			spielfeld[i][k] = ' ';
		}
	}
}

void delay(int milli_seconds) {
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int gameloop(){
	int direction;
	while(!verloren()){
		spawn();
		while(collision() == false){
			down();
			system("cls");
			ausgabe(farbe_formen);
			direction = leftright();
			copyleftright(direction);
		}
		reiheloeschen();
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
	int delaytime = 0; //10 - a bit fine-tuning might be a good idea here
	int max = time;//delaytime time/delaytime/2
	int flagleft, flagright, flagfast, moveleft = false, moveright = false;

	for(int i=0; i<=max; i++){
		flagleft = GetAsyncKeyState(VK_LEFT);
		if (abs(flagleft) > 10000){
			moveleft = true;
		}

		delay(delaytime);
		flagright = GetAsyncKeyState(VK_RIGHT);
		if (abs(flagright) > 10000){
			moveright = true;
		}
		
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
	int leftboarder = false, rightboarder = false, leftfigur = false, rightfigur = false;

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
	
	for (int i = 0; i < ylength; i++) {
		for (int k = 0; k < xlength; k++) {
			if (spielfeld[k][i] == 'O' && spielfeld[k - 1][i] == 'X') {
				leftfigur = true;
			}
		}
	}

	for (int i = 0; i < ylength; i++) {
		for (int k = 0; k < xlength; k++) {
			if (spielfeld[k][i] == 'O' && spielfeld[k + 1][i] == 'X') {
				rightfigur = true;
			}
		}
	}

	//1=left, 2=right
	if(direction == 1 && !leftboarder && !leftfigur){
		for(int i = 0; i < ylength; i++){
			for(int k = 0; k < xlength; k++){
				if (spielfeld[k][i] == 'O') {
					spielfeld[k][i] = ' ';
					spielfeld[k - 1][i] = 'O';
				}
			}
		}
	}
	if (direction == 2 && !rightboarder && !rightfigur) {
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