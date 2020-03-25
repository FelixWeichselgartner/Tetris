#pragma once

#define xlength 10
#define ylength 26

struct f {
	char fgr; //figur
	int clr; //color
	int spawnnumber;
	int turnl;
	int turnr;
};

class Tetris {

private:

int punktestand = 0;
struct f spielfeld[xlength][ylength];
struct f empty;

void ausgabe();
void highscore_aufruf();
void titel();
void spielfeld_ausgabe();
void unterer_Teil();

void place_fgr(struct f ptr[4][4], int, int, int, int);
void down();

void spawnturn(int, int, int);
void figcpy(struct f ptr[4][4], struct f ptrf[4][4]);
void change();
void update_score(int);



void highscore();
void init_spielfeld();
void delay(int);
void input();

void vertical_movement(int);
void horizontal_movement(char);
int check_collision();
void rotate_figure(char);
void spawn_new_figure();
void delete_line();
int gameloop();
int check_lost();

public:

void run();

};
