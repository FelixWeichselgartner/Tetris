/*
* rotate function
*/

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Gamefunctions_Zei.h"
#include "Spielfeld_loh.h"
#include "Spielfiguren.h"
#include "Gameloop_Wei.h"
#include "Gamefunctions_Zei.h"
#include "rotate_function.h"

#define true 1
#define false 0

#define x 4

#define xlength 10
#define ylength 26

//Funktion zum Kopieren von arrays
void drecksfunktion(struct f ptr[4][4], int rows, int columns, int x_start, int y_start) {
	int collision = 0, boarder = 0;
	for (int i = 3; i >= 4 - columns; i--) {
		for (int j = 0; j < rows; j++) {
			if (ptr[j][i].fgr != ' ') {
				if (spielfeld[j + x_start][i + y_start].fgr == 'X') {
					collision = 1;
					break;
				}
			}
		}
	}
	if (collision == 1) {
		return;
	}

	for (int i = 3; i >= 4 - columns; i--) {
		for (int j = 0; j < rows; j++) {
			//größer als 10
			//größer als 26
			if ((j + x_start) > 9 || (j+x_start) <0) {
				boarder = 1;
				break;
			}
			if ((i + y_start) > 25 || (i + y_start) < 0) {
				boarder = 1;
				break;
			}
		}
	}

	if (boarder == 1) {
		return;
	}

	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;

	for (int i = 0; i<xlength; i++) {
		for (int j = 0; j<ylength; j++) {
			if (spielfeld[i][j].fgr == 'O') {
				spielfeld[i][j] = empty;
			}
		}
	}

	for (int i = 3; i >= 4-columns; i--) {
		for (int j = 0; j < rows; j++) {
			if (ptr[j][i].fgr == 'O') {
				spielfeld[j+x_start][i+y_start] = ptr[j][i];
			//weil andersrum
			}
		}
	}
	/*
	ausgabe();
	putchar('\n');
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			putchar(ptr[k][i].fgr);
		}
		putchar('\n');
	}
	getchar();
	*/
}

void rotate(char rotation) {
	int x_start = -1, y_start = -1, spawnn = -1;
	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;
	//first it shall be checked in how much rows and columns 'O' are
	//here the rows
	int rows = 0;
	int flag = 0;
	for (int k = 0; k < ylength; k++) {
		flag = 0;
		for(int i = 0; i < xlength; i++) {
			if (spielfeld[i][k].fgr == 'O') {
				if (spawnn == -1 && rotation == 'r') {
					spawnn = spielfeld[i][k].turnr;
				}
				if (spawnn == -1 && rotation == 'l') {
					spawnn = spielfeld[i][k].turnl;
				}
				if (x_start == -1) {
					x_start = i;
				}
				if (y_start == -1) {
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
	for (int k = 0; k < xlength; k++) {
		flag = 0;
		for(int i = 0; i < ylength; i++) {
			if (spielfeld[k][i].fgr == 'O') {
				columns++;
				flag = 1;
				break;
			}
		if (flag == 1)
			break;
		}
	}

	if (spawnn == 3) {
		return;
	}

	switch (spawnn) {
	case 1: drecksfunktion(fig1, rows, columns, x_start, y_start); break;
	case 2: drecksfunktion(fig2, rows, columns, x_start, y_start); break;
	case 3: break;
	case 4: drecksfunktion(fig4, rows, columns, x_start, y_start); break;
	case 5: drecksfunktion(fig5, rows, columns, x_start, y_start); break;
	case 6: drecksfunktion(fig6, rows, columns, x_start, y_start); break;
	case 7: drecksfunktion(fig7, rows, columns, x_start, y_start); break;
	case 8: drecksfunktion(fig8, rows, columns, x_start, y_start); break;
	case 9: drecksfunktion(fig9, rows, columns, x_start, y_start); break;
	case 10: drecksfunktion(fig10, rows, columns, x_start, y_start); break;
	case 11: drecksfunktion(fig11, rows, columns, x_start, y_start); break;
	case 12: drecksfunktion(fig12, rows, columns, x_start, y_start); break;
	case 13: drecksfunktion(fig13, rows, columns, x_start, y_start); break;
	case 14: drecksfunktion(fig14, rows, columns, x_start, y_start); break;
	case 15: drecksfunktion(fig15, rows, columns, x_start, y_start); break;
	case 16: drecksfunktion(fig16, rows, columns, x_start, y_start); break;
	case 17: drecksfunktion(fig17, rows, columns, x_start, y_start); break;
	case 18: drecksfunktion(fig18, rows, columns, x_start, y_start); break;
	case 19: drecksfunktion(fig19, rows, columns, x_start, y_start); break;
	}
}