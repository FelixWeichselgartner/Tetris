#pragma once

#include "Node.hpp"
#include <QMainWindow>

#define xlength 10
#define ylength 26

class Tetris
{

private:
    QMainWindow *window;
	int score = 0;
	Node field[xlength][ylength];
	Node empty = Node(' ', 0, 0, 0, 0);

	void ausgabe();
	void highscore_aufruf();
	void titel();
	void spielfeld_ausgabe();
	void unterer_Teil();

	void place_piece(Node ptr[4][4], int, int, int, int);
	void down();
	void spawnturn(int, int, int);
	void figcpy(Node ptr[4][4], Node ptrf[4][4]);
	void update_score(int);
	void highscore();
	void delay(int);
	void input();

	void initialise_field();
	void moveable2solid();
	void vertical_movement(int);
	void horizontal_movement(char);
	int check_collision();
	void rotate_piece(char);
	void spawn_new_piece();
	void delete_line();
	int gameloop();
	int check_lost();

public:
    Tetris();
    Tetris(QMainWindow *window);
	void run();
};
