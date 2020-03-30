#include <QDebug>
#include <time.h>
#include "Node.hpp"
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
			if (ptr[j][i].get_figure() != ' ')
			{
				if (field[j + x_start][i + y_start].get_figure() == 'X')
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
			//gr��er als 10
			//gr��er als 26
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
			if (field[i][j].get_figure() == 'O')
			{
				field[i][j] = empty;
			}
		}
	}

	for (int i = 3; i >= 4 - columns; i--)
	{
		for (int j = 0; j < rows; j++)
		{
			if (ptr[j][i].get_figure() == 'O')
			{
				field[j + x_start][i + y_start] = ptr[j][i];
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
			if (field[i][k].get_figure() == 'O')
			{
				if (spawnn == -1 && rotation == 'r')
				{
					spawnn = field[i][k].get_turn_right();
				}
				if (spawnn == -1 && rotation == 'l')
				{
					spawnn = field[i][k].get_turn_left();
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
			if (field[k][i].get_figure() == 'O')
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
void Tetris::figcpy(Node ptr[4][4], Node ptrf[4][4])
{
	for (int i = 0; i < 4; i++)
	{
        for (int j = 0; j < 4; j++)
		{
			ptr[i][j] = ptrf[i][j];
			//weil andersrum
		}
	}
}

void Tetris::vertical_movement(int i)
{
    for (int k = 0; k < xlength; k++) {
        field[k][i] = empty;
    }

	for (; i > 4; i--)
	{
		for (int k = 0; k < xlength; k++)
		{
			field[k][i] = field[k][i - 1];
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
			if (field[i][j].get_figure() == 'O')
			{
				field[i][j].set_figure('X');
			}
		}
	}
}

//Funktion zur Zählung des Scores
void Tetris::update_score(int a)
{
	score += a;
}

//Funktion zum Spawnen der Teile im Feld
void Tetris::spawn_new_piece()
{
	int a;
	Node piece[4][4];
	//Auswählen einer Zufallsfigur für den nächsten Spawn-Array
	srand(time(0));
	//x = 7;
	//x = 2;
	a = rand() % 23 + 1;
	//x = 3; //zum testen von reihelöschen
	//Kopieren der Zufallsfigur in den Figur Array
	switch (a)
	{
	case 1:
		figcpy(piece, fig1);
		break;
	case 2:
		figcpy(piece, fig2);
		break;
	case 3:
		figcpy(piece, fig3);
		break;
	case 4:
		figcpy(piece, fig4);
		break;
	case 5:
		figcpy(piece, fig5);
		break;
	case 6:
		figcpy(piece, fig6);
		break;
	case 7:
		figcpy(piece, fig7);
		break;
	case 8:
		figcpy(piece, fig8);
		break;
	case 9:
		figcpy(piece, fig9);
		break;
	case 10:
		figcpy(piece, fig10);
		break;
	case 11:
		figcpy(piece, fig11);
		break;
	case 12:
		figcpy(piece, fig12);
		break;
	case 13:
		figcpy(piece, fig13);
		break;
	case 14:
		figcpy(piece, fig14);
		break;
	case 15:
		figcpy(piece, fig15);
		break;
	case 16:
		figcpy(piece, fig16);
		break;
	case 17:
		figcpy(piece, fig17);
		break;
	case 18:
		figcpy(piece, fig18);
		break;
	case 19:
		figcpy(piece, fig19);
		break;
	case 20:
		figcpy(piece, fig3);
		break;
	case 21:
		figcpy(piece, fig3);
		break;
	case 22:
		figcpy(piece, fig3);
		break;
	case 23:
		figcpy(piece, fig1);
		break;
	case 24:
		figcpy(piece, fig2);
		break;
	}
	//Kopieren des Figur-Arrays in den Spawn-Array

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			field[i + 3][j] = piece[i][j];
		}
	}
}

//Kollisionsprüfung
int Tetris::check_collision()
{
	for (int a = 0; a < xlength; a++)
	{
		if (field[a][ylength - 1].get_figure() == 'O')
		{
			moveable2solid();
			return true;
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int j = 0; j < xlength; j++)
		{
			if (field[j][i].get_figure() == 'O' && field[j][i + 1].get_figure() == 'X')
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
		if (field[0][i].get_figure() == 'X' && field[1][i].get_figure() == 'X' && field[2][i].get_figure() == 'X' && field[3][i].get_figure() == 'X' && field[4][i].get_figure() == 'X' && field[5][i].get_figure() == 'X' && field[6][i].get_figure() == 'X' && field[7][i].get_figure() == 'X' && field[8][i].get_figure() == 'X' && field[9][i].get_figure() == 'X')
		{
			vertical_movement(i);
			score += 1;
			delete_line(); //rekursive funktion
		}
	}
}

//Speicherung in einer Textdatei
void Tetris::highscore()
{
	int fehler;
	char name[10];
	FILE *fptr;
	fptr = fopen("Highscores.txt", "a+");
	if (fptr == NULL)
	{
		printf("\nDie Datei konnte nicht geoeffnet werden!\n");
		return;
	}
	fflush(stdin);
	while (getchar() != '\n')
		;
	//hier virtuelles enter
	//system("cls");
	//ausgabe();
	printf("Name fuer die Highscoreliste eingeben (max 10 Buchstaben): ");
	scanf("%s", name);

	fprintf(fptr, "%s; %i;", name, score);
	fprintf(fptr, "\n");

	fehler = fclose(fptr);
	if (fehler != 0)
	{
		printf("\nFehler %i beim Schließen der Datei!\n", fehler);
	}
	highscore_aufruf();
}

int abs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

void Tetris::delay(int milli_seconds)
{
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void Tetris::initialise_field()
{
	for (int i = 0; i < xlength; i++)
	{
		for (int k = 0; k < ylength; k++)
		{
			field[i][k] = empty;
		}
	}
}

int Tetris::gameloop()
{
	int flag_spawn = 1;

	while (!check_lost())
	{
		spawn_new_piece();
		flag_spawn = 1;

        while (!check_collision())
		{
            if (flag_spawn != 0) {
				down();
            }
			input();
		}
		delete_line();
	}
	return true;
}

void Tetris::down()
{
	Node tempfield[xlength][ylength];
	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
			tempfield[k][i] = field[k][i];
			if (field[k][i].get_figure() == 'O')
			{
				field[k][i] = empty;
			}
		}
	}
	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
			if (tempfield[k][i].get_figure() == 'O')
				field[k][i + 1] = tempfield[k][i];
		}
	}
}

void Tetris::input()
{
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

    if (this->pressed_down.is_set())
    {
        this->pressed_down.clear();
        return;
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

    QThread::msleep(1000);

	return;
}

void Tetris::horizontal_movement(char direction)
{
	int leftboarder = false, rightboarder = false, leftfigur = false, rightfigur = false;
	Node temp = Node();

	for (int i = 0; i < ylength; i++)
	{
		if (field[0][i].get_figure() == 'O')
		{
			leftboarder = true;
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		if (field[9][i].get_figure() == 'O')
		{
			rightboarder = true;
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
			if (field[k][i].get_figure() == 'O' && field[k - 1][i].get_figure() == 'X')
			{
				leftfigur = true;
			}
		}
	}

	for (int i = 0; i < ylength; i++)
	{
		for (int k = 0; k < xlength; k++)
		{
			if (field[k][i].get_figure() == 'O' && field[k + 1][i].get_figure() == 'X')
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
				if (field[k][i].get_figure() == 'O')
				{
					temp = field[k][i];
					field[k][i] = empty;
					field[k - 1][i] = temp;
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
				if (field[k][i].get_figure() == 'O')
				{
					temp = field[k][i];
					field[k][i] = empty;
					field[k + 1][i] = temp;
				}
			}
		}
	}
}

int Tetris::check_lost()
{
	for (int i = 0; i < xlength; i++)
	{
		if (field[i][4].get_figure() == 'X')
		{
			return true;
		}
	}
	return false;
}

Tetris::Tetris()
{
    initialise_field();
    initialise_pieces();
}

void Tetris::run()
{
    if (gameloop())
	{
		highscore();
	}
}
