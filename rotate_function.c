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
	int collision, boarder;
	for (int i = 3; i >= 4 - columns; i--) {
		for (int j = 0; j < rows; j++) {
			if (ptr[j][i].fgr != ' ') {
				if (spielfeld[j + x_start][i + y_start].fgr == 'X') {
					collision = 1;
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
				if (spawnn == -1) {
					spawnn = spielfeld[i][k].turnr;
					/*
					printf("turnr = %i", spielfeld[i][k].turnr);
					getchar();
					*/
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
	/*
	printf("columns = %i, rows = %i", columns, rows);
	getchar();
	*/

	for (int i = 0; i<xlength; i++) {
		for (int j = 0; j<ylength; j++) {
			if (spielfeld[i][j].fgr == 'O') {
				spielfeld[i][j] = empty;
			}
		}
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
	
	/*
	int fall = 0;

	//platzhalter[columns][rows]
	struct f platzhalter14[1][4];
	struct f platzhalter41[4][1];
	struct f platzhalter22[2][2];
	struct f platzhalter23[2][3];
	struct f platzhalter32[3][2];
	if (columns == 1 && rows == 4) {
		fall = 14;
	}
	if (columns == 4 && rows == 1) {
		fall = 41;
	}
	if (columns == 2 && rows == 2) {
		fall = 22;
	}
	if (columns == 2 && rows == 3) {
		fall = 23;
	}
	if (columns == 3 && rows == 2) {
		fall = 32;
	}

	for (int i = 0; i < columns; i++) {
		for (int k = 0; k < rows; k++) {
			switch (fall) {
			case 14: platzhalter14[i][k] = empty; break;
			case 41: platzhalter41[i][k] = empty; break;
			case 22: platzhalter22[i][k] = empty; break;
			case 23: platzhalter23[i][k] = empty; break;
			case 32: platzhalter32[i][k] = empty; break;
			}
		}
	}
	//hier rows und columns vertauscht, da zielfigur nicht ausgangsfigur
	//funktioniert nicht -> ist nach dem kopieren immernoch leer
	for (int k = 3; k > 3 - columns; k--) {
		for (int i = 0; i < rows; i++) {
			switch (spawnn) {
			case 1: platzhalter14[i][k] = fig1[i][k]; break;
			case 2: platzhalter41[i][k] = fig2[i][k]; break;
			case 3: break;
			case 4: platzhalter32[i][k] = fig4[i][k]; break;
			case 5: platzhalter23[i][k] = fig5[i][k]; break;
			case 6: platzhalter32[i][k] = fig6[i][k]; break;
			case 7: platzhalter23[i][k] = fig7[i][k]; break;
			case 8: platzhalter32[i][k] = fig8[i][k]; break;
			case 9: platzhalter23[i][k] = fig9[i][k]; break;
			case 10: platzhalter32[i][k] = fig10[i][k]; break;
			case 11: platzhalter23[i][k] = fig11[i][k]; break;
			case 12: platzhalter32[i][k] = fig12[i][k]; break;
			case 13: platzhalter23[i][k] = fig13[i][k]; break;
			case 14: platzhalter23[i][k] = fig14[i][k]; break;
			case 15: platzhalter32[i][k] = fig15[i][k]; break;
			case 16: platzhalter32[i][k] = fig16[i][k]; break;
			case 17: platzhalter23[i][k] = fig17[i][k]; break;
			case 18: platzhalter32[i][k] = fig18[i][k]; break;
			case 19: platzhalter23[i][k] = fig19[i][k]; break;
			}
		}
	}
	
	for (int k = 3; k > 3 - columns; k--) {
		for (int i = 0; i < rows; i++) {
			putchar(fig6[i][k].fgr);
		}
		putchar('\n');
	}
	getchar();
	for (int k = 4-columns; k <= 3; k++) {
		for (int i = 0; i < rows; i++) {
			putchar(platzhalter32[i][k].fgr);

		}
		putchar('\n');
	}
	getchar();

	printf("spawnn = %i\nfall = %i\n", spawnn, fall);
	for (int i = 0; i < columns; i++) {
		for (int k = 0; k < rows; k++) {
			switch (fall) {
			case 14: printf("%c", platzhalter14[i][k].fgr); break;
			case 41: printf("%c", platzhalter41[i][k].fgr); break;
			case 22: printf("%c", platzhalter22[i][k].fgr); break;
			case 23: printf("%c", platzhalter23[i][k].fgr); break;
			case 32: printf("%c", platzhalter32[i][k].fgr); break;
			}
		}
	}
	getchar();
	*/
}

void rotate_f(char rotation) {
	int xturn, yturn; //Speicherung der Position der Figur
	int v; //Speicherung der Nummer der zu rotierenden figur
	if (rotation == 'r') {
		for (int i = 4; i<ylength; i++) {
			for (int j = 4; j<xlength; j++) {
				if (spielfeld[j][i].fgr == 'O') {
					xturn = j;
					yturn = i;
					v=spielfeld[j][i].turnr;
					break;
					break;
				}
			}
		}
		for (int i = 4; i<ylength; i++) {
			for (int j = 0; j<xlength; j++) {
				if (spielfeld[j][i].fgr == 'O') {
					spielfeld[j][i].fgr = ' ';
					spielfeld[j][i].clr = 0;
					spielfeld[j][i].spawnnumber = 0;
				}
			}
		}
		spawnturn(spielfeld[yturn][xturn].turnr, yturn, xturn);
	 }
	if (rotation == 'l') {
		for (int i = 0; i<ylength; i++) {
			for (int j = 0; j<xlength; j++) {
				if (spielfeld[j][i].fgr == 'O') {
					spielfeld[j][i].fgr = ' ';
				}
				spawnturn(v, j, i);
			}
		}
	 }
    return;
}

void spawnturn(int v, int j, int i) {
	struct f figur[4][4];
	switch (v) {
	case 1: figcpy(figur, fig1); break;
	case 2: figcpy(figur, fig2); break;
	case 3: figcpy(figur, fig3); break;
	case 4: figcpy(figur, fig4); break;
	case 5: figcpy(figur, fig5); break;
	case 6: figcpy(figur, fig6); break;
	case 7: figcpy(figur, fig7); break;
	case 8: figcpy(figur, fig8); break;
	case 9: figcpy(figur, fig9); break;
	case 10: figcpy(figur, fig10); break;
	case 11: figcpy(figur, fig11); break;
	case 12: figcpy(figur, fig12); break;
	case 13: figcpy(figur, fig13); break;
	case 14: figcpy(figur, fig14); break;
	case 15: figcpy(figur, fig15); break;
	case 16: figcpy(figur, fig16); break;
	case 17: figcpy(figur, fig17); break;
	case 18: figcpy(figur, fig18); break;
	case 19: figcpy(figur, fig19); break;
	case 20: figcpy(figur, fig3); break;
	case 21: figcpy(figur, fig3); break;
	case 22: figcpy(figur, fig3); break;
	case 23: figcpy(figur, fig1); break;
	case 24: figcpy(figur, fig2); break;
	}
	printf("%i", v);
	//getch();
	//Kopieren des Figur-Arrays an die position des alten teils
	for (int a=i; a<i+4; a++) {
		for (int b = j; b < j + 4; b++) {
			spielfeld[a][b] = figur[a][b];
		}
	}
}