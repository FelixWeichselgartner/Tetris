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

void rotate(char rotation) {
	int spawnn = 1000;
	//first it shall be checked in how much rows and columns 'O' are
	//here the rows
	int rows = 0;
	int flag = 0;
	for (int k = 0; k < ylength; k++) {
		flag = 0;
		for(int i = 0; i < xlength; i++) {
			if (spielfeld[i][k].fgr == 'O') {
				//löschen der alten figur
				if (spawnn == 1000) {
					spawnn = spielfeld[i][k].turnr;
					/*
					printf("turnr = %i", spielfeld[i][k].turnr);
					getchar();
					*/
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
	
	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;

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
	for (int i = 0; i < rows; i++) {
		for (int k = 3; k > 3-columns; k--) {
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

	printf("spawnn = %i\n", spawnn);
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