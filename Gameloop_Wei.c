#include <stdio.h>
#include <time.h>
#include <windows.h>

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
	while(verloren() == false){
		spawn();
		while(collision() == false){
			direction = leftright();
			copyrightleft(direction);
			down();
		}
		reiheloeschen(); //reiheloeschen() -> score()
	}
	return true;
}

void down(){
	char temp_field[xlength][ylength];
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
				spielfeld[i][k+1] = 'O';
			temp_field[i][k] = temp_field[i][k];
		}
	}
}

int leftright(){
	int left = 'a', right = 'd';
	int time = 1000;
	int delaytime = 10;
	int max = time/2/delaytime;
	int flagleft, flagright;
	int moveleft, moveright;
	for(int i=0; i<=max; i++){
		flagleft = GetAsyncKeyState('a');
		if (flagleft == true){
			moveleft = true;
		}
		delay(delaytime);
		flagright = GetAsyncKeyState('d');
		if (flagright == true){
			moveright = true;
		}
		delay(delaytime);
	}
	if (moveleft == true && moveright == true){
		return 0;
	}
	if (moveleft == true){
		return 1;
	}
	if (moveright == true){
		return 2;
	}
}