/*
* rotate function
*/

#include <stdio.h>
#include <time.h>
#include <windows.h>
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