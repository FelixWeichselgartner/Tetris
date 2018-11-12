/*
* Tetris in C - header by Felix Weichselgartner
*/

#ifndef GAMELOOP_WEI_
#define GAMELOOP_WEI_

extern char spielfeld[10][26];
extern int punktestand;
extern int farbe_formen;

void init_spielfeld();
void init_tempfield();
void delay(int);
int gameloop();
void down();
int leftright();
void copyleftright(int);
int verloren();

#endif