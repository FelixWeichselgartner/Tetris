/*
* Tetris in C - header by Felix Weichselgartner
*/

#ifndef GAMELOOP_WEI_
#define GAMELOOP_WEI_

extern char spielfeld[10][26];
extern int punktestand;
extern int farbe_formen;

void init_spielfeld();
void delay(int);
int gameloop();
void down();
int input(int *, int *);
void copyleftright(int);
int verloren();

#endif