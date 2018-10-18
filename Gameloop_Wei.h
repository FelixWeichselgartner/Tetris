/*
* Tetris in C - header by Felix Weichselgartner
*/

#ifndef GAMELOOP_WEI_
#define GAMELOOP_WEI_

void init_spielfeld();
void delay();
int gameloop();
void down();
int leftright();
void copyleftright();
int verloren();

#endif