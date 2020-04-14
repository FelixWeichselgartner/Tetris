#pragma once

#include "ProtectedInt.hpp"
#include "Node.hpp"
#include "Field.hpp"
#include "Event.hpp"
#include <QMainWindow>
#include <QColor>


class Tetris
{

private:
    QMainWindow *window;
    Node next_piece[4][4], empty;

	void highscore_aufruf();

	void place_piece(Node ptr[4][4], int, int, int, int);
	void down();
	void spawnturn(int, int, int);
	void figcpy(Node ptr[4][4], Node ptrf[4][4]);
	void update_score(int);
	void delay(int);
    void input();

	void moveable2solid();
	void vertical_movement(int);
	void horizontal_movement(char);
	int check_collision();
	void rotate_piece(char);
    void generate_new_piece();
	void spawn_new_piece();
	void delete_line();
	int gameloop();
	int check_lost();

public:
    Event pressed_left, pressed_right, pressed_down, pressed_rotate_left, pressed_rotate_right;
    Event quit, pause;
    Tetris();
    ProtectedInt score;
    ProtectedInt spawn_number;
    Field field;
	void run();
};
