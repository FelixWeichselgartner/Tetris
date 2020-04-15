#include <QTime>
#include <QDebug>
#include "Tetris.hpp"
#include "Tetromino.hpp"
#include <QThread>


//Funktion zum Kopieren von arrays
void Tetris::place_piece(Node ptr[4][4], int rows, int columns, int x_start, int y_start)
{
	int collision = 0, boarder = 0;
	for (int i = 3; i >= 4 - columns; i--)
	{
		for (int j = 0; j < rows; j++)
		{
            if (!ptr[j][i].is_empty())
			{
                if (field.get_copy(j + x_start, i + y_start).is_solid())
				{
					collision = 1;
					break;
				}
			}
		}
	}
	if (collision == 1)
	{
		return;
	}

	for (int i = 3; i >= 4 - columns; i--)
	{
		for (int j = 0; j < rows; j++)
		{
            // bigger than 10 and 26
			if ((j + x_start) > 9 || (j + x_start) < 0)
			{
				boarder = 1;
				break;
			}
			if ((i + y_start) > 25 || (i + y_start) < 0)
			{
				boarder = 1;
				break;
			}
		}
	}

	if (boarder == 1)
	{
		return;
	}

	for (int i = 0; i < xlength; i++)
	{
		for (int j = 0; j < ylength; j++)
		{
            if (field.get_copy(i, j).is_moveable())
			{
                field.set(empty, i, j);
			}
		}
	}

	for (int i = 3; i >= 4 - columns; i--)
	{
		for (int j = 0; j < rows; j++)
		{
            if (ptr[j][i].is_moveable())
			{
                field.set(ptr[j][i], j + x_start, i + y_start);
				//weil andersrum
			}
		}
	}
}

void Tetris::rotate_piece(char rotation)
{
	int x_start = -1, y_start = -1, spawnn = -1;

	//first it shall be checked in how much rows and columns 'O' are
	//here the rows
	int rows = 0;
	int flag = 0;
	for (int k = 0; k < ylength; k++)
	{
		flag = 0;
		for (int i = 0; i < xlength; i++)
		{
            if (field.get_copy(i, k).is_moveable())
			{
				if (spawnn == -1 && rotation == 'r')
				{
                    spawnn = field.get_copy(i, k).get_turn_right();
				}
				if (spawnn == -1 && rotation == 'l')
				{
                    spawnn = field.get_copy(i, k).get_turn_left();
				}
				if (x_start == -1)
				{
					x_start = i;
				}
				if (y_start == -1)
				{
					y_start = k;
				}
				rows++;
				flag = 1;
				break;
			}
			if (flag == 1)
				break;
		}
	}
	//here for the rows
	int columns = 0;
	for (int k = 0; k < xlength; k++)
	{
		flag = 0;
		for (int i = 0; i < ylength; i++)
		{
            if (field.get_copy(k, i).is_moveable())
			{
				columns++;
				flag = 1;
				break;
			}
			if (flag == 1)
				break;
		}
	}

	if (spawnn == 3)
	{
		return;
	}

	switch (spawnn)
	{
	case 1:
		place_piece(fig1, rows, columns, x_start, y_start);
		break;
	case 2:
		place_piece(fig2, rows, columns, x_start, y_start);
		break;
	case 3:
		break;
	case 4:
		place_piece(fig4, rows, columns, x_start, y_start);
		break;
	case 5:
		place_piece(fig5, rows, columns, x_start, y_start);
		break;
	case 6:
		place_piece(fig6, rows, columns, x_start, y_start);
		break;
	case 7:
		place_piece(fig7, rows, columns, x_start, y_start);
		break;
	case 8:
		place_piece(fig8, rows, columns, x_start, y_start);
		break;
	case 9:
		place_piece(fig9, rows, columns, x_start, y_start);
		break;
	case 10:
		place_piece(fig10, rows, columns, x_start, y_start);
		break;
	case 11:
		place_piece(fig11, rows, columns, x_start, y_start);
		break;
	case 12:
		place_piece(fig12, rows, columns, x_start, y_start);
		break;
	case 13:
		place_piece(fig13, rows, columns, x_start, y_start);
		break;
	case 14:
		place_piece(fig14, rows, columns, x_start, y_start);
		break;
	case 15:
		place_piece(fig15, rows, columns, x_start, y_start);
		break;
	case 16:
		place_piece(fig16, rows, columns, x_start, y_start);
		break;
	case 17:
		place_piece(fig17, rows, columns, x_start, y_start);
		break;
	case 18:
		place_piece(fig18, rows, columns, x_start, y_start);
		break;
	case 19:
		place_piece(fig19, rows, columns, x_start, y_start);
		break;
	}
}

//Funktion zum Kopieren von arrays
void Tetris::figcpy(Node target[4][4], Node ptr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
        for (int j = 0; j < 4; j++)
		{
            target[i][j] = ptr[i][j];
			//weil andersrum
		}
	}
}

void Tetris::clear_line(int i) {
    for (int k = 0; k < xlength; k++) {
        field.set(empty, k, i);
    }
}

void Tetris::vertical_movement_down(int i)
{
	for (; i > 4; i--)
	{
		for (int k = 0; k < xlength; k++)
		{
            field.set(field.get_copy(k, i - 1), k, i);
		}
	}
}

//Bewegliche arrays in feste umwandeln
void Tetris::moveable2solid()
{
	for (int i = 0; i < xlength; i++)
	{
		for (int j = 0; j < ylength; j++)
		{
            if (field.get_copy(i, j).is_moveable())
			{
                Node tmp = field.get_copy(i, j);
                tmp.set_figure('X');
                field.set(tmp, i, j);
			}
		}
	}
}

//Funktion zur Zählung des Scores
void Tetris::update_score(int a)
{
    score.set(score.get() + a);
}

void Tetris::generate_new_piece() {
    QTime now = QTime::currentTime();
    qsrand((unsigned int)now.msec() * identifier);
    spawn_number.set(qrand() % 23 + 1);
    switch (spawn_number.get())
    {
    case 1:
        figcpy(next_piece, fig1);
        break;
    case 2:
        figcpy(next_piece, fig2);
        break;
    case 3:
        figcpy(next_piece, fig3);
        break;
    case 4:
        figcpy(next_piece, fig4);
        break;
    case 5:
        figcpy(next_piece, fig5);
        break;
    case 6:
        figcpy(next_piece, fig6);
        break;
    case 7:
        figcpy(next_piece, fig7);
        break;
    case 8:
        figcpy(next_piece, fig8);
        break;
    case 9:
        figcpy(next_piece, fig9);
        break;
    case 10:
        figcpy(next_piece, fig10);
        break;
    case 11:
        figcpy(next_piece, fig11);
        break;
    case 12:
        figcpy(next_piece, fig12);
        break;
    case 13:
        figcpy(next_piece, fig13);
        break;
    case 14:
        figcpy(next_piece, fig14);
        break;
    case 15:
        figcpy(next_piece, fig15);
        break;
    case 16:
        figcpy(next_piece, fig16);
        break;
    case 17:
        figcpy(next_piece, fig17);
        break;
    case 18:
        figcpy(next_piece, fig18);
        break;
    case 19:
        figcpy(next_piece, fig19);
        break;
    case 20:
        figcpy(next_piece, fig3);
        break;
    case 21:
        figcpy(next_piece, fig3);
        break;
    case 22:
        figcpy(next_piece, fig3);
        break;
    case 23:
        figcpy(next_piece, fig1);
        break;
    case 24:
        figcpy(next_piece, fig2);
        break;
    }
}

//Funktion zum Spawnen der Teile im Feld
void Tetris::spawn_new_piece()
{
    Node current_piece[4][4];
    figcpy(current_piece, next_piece);

    generate_new_piece();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
            field.set(current_piece[i][j], i + 3, j);
		}
	}
}

//Kollisionsprüfung
int Tetris::check_collision()
{
	for (int a = 0; a < xlength; a++)
	{
        if (field.get_copy(a, ylength - 1).is_moveable())
		{
			moveable2solid();
			return true;
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int j = 0; j < xlength; j++)
		{
            if (field.get_copy(j, i).is_moveable() && field.get_copy(j ,i + 1).is_solid())
			{
				moveable2solid();
				return true;
			}
		}
	}
	return false;
}

//Funktion zum Löschen der Reihe
void Tetris::delete_line()
{
	for (int i = 25; i >= 0; i--)
	{
        bool condition = true;

        for (int k = 0; k < 10; k++) {
            condition = (field.get_copy(k, i).is_solid()) && condition;
        }

        if (condition)
		{
            clear_line(i);
            vertical_movement_down(i);
            score.inc();
			delete_line(); //rekursive funktion
		}
	}
}



int abs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

void Tetris::vertical_movement_moveable_blocks()
{
	Node tempfield[xlength][ylength];

	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
            tempfield[k][i] = field.get_copy(k, i);
            if (field.get_copy(k, i).is_moveable())
			{
                field.set(empty, k, i);
			}
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
            if (tempfield[k][i].is_moveable())
                field.set(tempfield[k][i], k, i + 1);
		}
	}
}

void Tetris::input()
{
    QThread::msleep(100);

    if (this->pressed_left.is_set())
    {
        this->pressed_left.clear();
        horizontal_movement('l');
    }

    if (this->pressed_right.is_set())
    {
        this->pressed_right.clear();
        horizontal_movement('r');
    }

    if (this->pressed_rotate_right.is_set())
    {
        this->pressed_rotate_right.clear();
        rotate_piece('r');
    }

    if (this->pressed_rotate_left.is_set())
    {
        this->pressed_rotate_left.clear();
        rotate_piece('l');
    }

    if (this->pressed_down.is_set())
    {
        //this->pressed_down.clear();
        return;
    }

    QThread::msleep(900);

	return;
}

void Tetris::vertical_movement_up() {
    for (int i = 4; i < ylength; i++)
    {
        for (int k = 0; k < xlength; k++)
        {
            field.set(field.get_copy(k, i + 1), k, i);
        }
    }
}

void Tetris::insert_competitive_line() {
    vertical_movement_up();

    int empty_slot = qrand() % 10;

    for (int k = 0; k < xlength; k++) {
        if (k != empty_slot) {
            field.set(Node('X', QColor(42, 141, 7), rand() % 23, 0, 0), k, ylength - 1);
        }
    }
}

void Tetris::horizontal_movement(char direction)
{
	int leftboarder = false, rightboarder = false, leftfigur = false, rightfigur = false;
	Node temp = Node();

	for (int i = 0; i < ylength; i++)
	{
        if (field.get_copy(0 ,i).is_moveable())
		{
			leftboarder = true;
		}
	}

	for (int i = 0; i < ylength; i++)
	{
        if (field.get_copy(9, i).is_moveable())
		{
			rightboarder = true;
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
            if (field.get_copy(k, i).is_moveable() && field.get_copy(k - 1, i).is_solid())
			{
				leftfigur = true;
			}
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
            if (field.get_copy(k, i).is_moveable() && field.get_copy(k + 1, i).is_solid())
			{
				rightfigur = true;
			}
		}
	}

	if (direction == 'l' && !leftboarder && !leftfigur)
	{
		for (int i = 0; i < ylength; i++)
		{
			for (int k = 0; k < xlength; k++)
			{
                if (field.get_copy(k, i).is_moveable())
				{
                    temp = field.get_copy(k, i);
                    field.set(empty, k, i);
                    field.set(temp, k - 1, i);
				}
			}
		}
	}

	if (direction == 'r' && !rightboarder && !rightfigur)
	{
		for (int i = 0; i < ylength; i++)
		{
			for (int k = xlength; k >= 0; k--)
			{
                if (field.get_copy(k, i).is_moveable())
				{
                    temp = field.get_copy(k, i);
                    field.set(empty, k, i);
                    field.set(temp, k + 1, i);
				}
			}
		}
	}
}

int Tetris::check_lost()
{
	for (int i = 0; i < xlength; i++)
	{
        if (field.get_copy(i, 4).is_solid())
		{
			return true;
		}
	}
	return false;
}

int Tetris::gameloop()
{
    int flag_spawn = 1;

    while (!check_lost() && !quit.is_set())
    {
        while(pause.is_set());
        spawn_new_piece();
        flag_spawn = 1;

        while (!check_collision() && !quit.is_set())
        {
            while(pause.is_set());
            if (flag_spawn != 0) {
                vertical_movement_moveable_blocks();
            }
            input();
        }
        delete_line();
    }
    quit.set();
    return true;
}

Tetris::Tetris()
{
    this->identifier = 0;
    generate_new_piece();
    initialise_pieces();
}

Tetris::Tetris(int identifier)
{
    this->identifier = identifier;
    generate_new_piece();
    initialise_pieces();
}

void Tetris::run()
{
    if (gameloop())
	{
        //highscore();
	}
}
