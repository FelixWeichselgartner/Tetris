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

	void place_piece(Node ptr[4][4], int, int, int, int);
    void vertical_movement_moveable_blocks();
	void spawnturn(int, int, int);
	void figcpy(Node ptr[4][4], Node ptrf[4][4]);
	void update_score(int);
    void input();
    void vertical_movement_up();
	void moveable2solid();
    void clear_line(int);
    void vertical_movement_down(int);
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
    ProtectedInt score;
    ProtectedInt spawn_number;
    Field field;
    int identifier;

    Tetris();
    Tetris(int);
    void insert_competitive_line();
	void run();
};
