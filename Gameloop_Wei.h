/*
* Tetris in C - header by Felix Weichselgartner
*/

#ifndef GAMELOOP_WEI_
#define GAMELOOP_WEI_

struct f {
	char fgr; //figur
	int clr; //color
	int spawnnumber;
};

extern struct f spielfeld[10][26];

extern int punktestand;

void init_spielfeld();
void delay(int);
int gameloop();
void down();
void input();
void copyleftright(char);
int verloren();

#endif