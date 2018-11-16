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

void rotate_f(char rotation) {
	int spawnn = -1;
	//first it shall be checked in how much rows and columns 'O' are
	//here the rows
	int rows = 0;
	int flag = 0;
	for (int k = 0; k < ylength; k++) {
		flag = 0;
		for(int i = 0; i < xlength; i++) {
			if (spielfeld[i][k].fgr == 'O') {
				if (spawnn == -1) {
					spawnn = spielfeld[i][k].spawnnumber;
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
	//printf("columns = %i, rows = %i", columns, rows);
	//next the 'O' are copied in a malloc array with the size of columns, rows
	
	struct f spass[4][4];
	/*
	struct f **spass;
	if (( spass = malloc(columns * sizeof(struct f *))) == NULL ) {
		return;
	}
	for (int i = 0; i < columns; i++ ) {
		if (( spass[i] = malloc( rows * sizeof(struct f) )) == NULL ) {
			return;
		}
	}
	*/

	/*
	 * access matrix elements: c[i] give you a pointer
	 * to the row array, c[i][j] indexes an element
	 * initialise all elements with empty
	*/


	struct f empty;
	empty.fgr = ' ';
	empty.clr = 0;
	empty.spawnnumber = 0;
	empty.turnr = 0;
	empty.turnl = 0;
	for(int i = 0; i < columns; i++)
		for(int k = 0; k < rows; k++)
			spass[i][k] = empty;

	for(int i = 0; i < columns; i++) {
		for(int k = 0; k < rows; k++) {
			printf("%c", (**spass).fgr);
		}
		printf("\n");
	}

	for(int i = 0; i < columns; i++) {
		for(int k = 3; k >= 0 /*3 - rows*/ ; k--){
			switch (spawnn) {
				case 1: spass[i][k] = fig1[i][k]; break;
				case 2: spass[i][k] = fig2[i][k]; break;
				case 3: spass[i][k] = fig3[i][k]; break;
				case 4: spass[i][k] = fig4[i][k]; break;
				case 5: spass[i][k] = fig5[i][k]; break;
				case 6: spass[i][k] = fig6[i][k]; break;
				case 7: spass[i][k] = fig7[i][k]; break;
				case 8: spass[i][k] = fig8[i][k]; break;
				case 9: spass[i][k] = fig9[i][k]; break;
				case 10: spass[i][k] = fig10[i][k]; break;
				case 11: spass[i][k] = fig11[i][k]; break;
				case 12: spass[i][k] = fig12[i][k]; break;
				case 13: spass[i][k] = fig13[i][k]; break;
				case 14: spass[i][k] = fig14[i][k]; break;
				case 15: spass[i][k] = fig15[i][k]; break;
				case 16: spass[i][k] = fig16[i][k]; break;
				case 17: spass[i][k] = fig17[i][k]; break;
				case 18: spass[i][k] = fig18[i][k]; break;
				case 19: spass[i][k] = fig19[i][k]; break;
			}
		}
	}

	for(int i = 0; i < columns; i++) {
		for(int k = 0; k < rows; k++) {
			printf("%c", spass[i][k].fgr);
		}
		printf("\n");
	}
}

void rotate(char rotation) {
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
					spielfeld[j][i].fgr == ' ';
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
	getch();
	//Kopieren des Figur-Arrays an die position des alten teils
	for (int a=i; a<i+4; a++) {
		for (int b = j; b < j + 4; b++) {
			spielfeld[a][b] = figur[a][b];
		}
	}
}