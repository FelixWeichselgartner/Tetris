/*
* Tetris in C - header by Matthias Lohberger
*/
#include "Spielfiguren.h"

#define y 4
#define x 4

struct f fig1[4][4];
struct f fig2[4][4];
struct f fig3[4][4];
struct f fig4[4][4];
struct f fig5[4][4];
struct f fig6[4][4];
struct f fig7[4][4];
struct f fig8[4][4];
struct f fig9[4][4];
struct f fig10[4][4];
struct f fig11[4][4];
struct f fig12[4][4];
struct f fig13[4][4];
struct f fig14[4][4];
struct f fig15[4][4];
struct f fig16[4][4];
struct f fig17[4][4];
struct f fig18[4][4];
struct f fig19[4][4];

//zu Farben:
//Stab			Farbe: blau/ Nummer: 153	
//Viereck		Farbe: gelb/ Nummer: 238	
//Blitz			Farbe: rot/ Nummer: 204
//T-Stück		Farbe: pink/ Nummer: 221
//L-Stück		Farbe: grün/ Nummer: 170 


void build_figures(struct f fig[x][x], char fg[x][x], int color, int nr, int l, int r) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			fig[i][j].fgr = fg[i][j];
			fig[i][j].clr = color;
			fig[i][j].spawnnumber = nr;
			fig[i][j].turnl = l;
			fig[i][j].turnr = r;
		}
	}
}



//Stab					
char fg1[y][x] =	{'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' '};


char fg2[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', 'O'};
						
						
//Viereck				
char fg3[y][x] =	{'O', 'O', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' '};
						
						
//Blitz 1						
char fg4[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', 'O', 'O', ' ',
						'O', 'O', ' ', ' '};
											
char fg5[y][x] =	{' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', ' ', ' '};


//Blitz 2				
char fg6[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', 'O', ' '};
						
char fg7[y][x] =	{' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', ' ', ' ',
						'O', ' ', ' ', ' '};


//T-Stück					
char fg8[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', ' ',
						' ', 'O', ' ', ' '};
						
char fg9[y][x] =	{' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						'O', ' ', ' ', ' '};
						
char fg10[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', 'O', ' '};
						
char fg11[y][x] =	{' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', ' ', ' '};
						
						
//L 1		
char fg12[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', 'O', ' '};
						
char fg13[y][x] =	{' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', ' ', ' '};
						
char fg14[y][x] =	{' ', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' '};
						
char fg15[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', ' ',
						' ', ' ', 'O', ' '};
						
						
//L 2					
char fg16[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', ' ', 'O', ' ',
						'O', 'O', 'O', ' '};
						
char fg17[y][x] =	{' ', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', ' ', ' ',
						' ', 'O', ' ', ' '};
								
char fg18[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', ' ',
						'O', ' ', ' ', ' '};
						
char fg19[y][x] =	{' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', ' ', ' '};

void init_figuren() {
	build_figures(fig1, fg1, 153, 1, 2, 2);
	build_figures(fig2, fg2, 153, 2, 1, 1);
	build_figures(fig3, fg3, 238, 3, 3, 3);
	build_figures(fig4, fg4, 204, 4, 5, 5);
	build_figures(fig5, fg5, 204, 5, 4, 4);
	build_figures(fig6, fg6, 204, 6, 7, 7);
	build_figures(fig7, fg7, 204, 7, 6, 6);
	build_figures(fig8, fg8, 221, 8, 9, 11);
	build_figures(fig9, fg9, 221, 9, 10, 8);
	build_figures(fig10, fg10, 221, 10, 11, 9);
	build_figures(fig11, fg11, 221, 11, 8, 10);
	build_figures(fig12, fg12, 170, 12, 13, 14);
<<<<<<< HEAD
	build_figures(fig13, fg13, 170, 13, 15, 12);
=======
	build_figures(fig13, fg13, 170, 13, 15, 11);
>>>>>>> 34e8884e442c9f2a4e45103fddb77005f086e69c
	build_figures(fig14, fg14, 170, 14, 12, 15);
	build_figures(fig15, fg15, 170, 15, 14, 13);
	build_figures(fig16, fg16, 170, 16, 17, 19);
	build_figures(fig17, fg17, 170, 17, 18, 16);
	build_figures(fig18, fg18, 170, 18, 19, 17);
<<<<<<< HEAD
	build_figures(fig19, fg19, 170, 19, 18, 16);
=======
	build_figures(fig19, fg19, 170, 19, 16, 18);
>>>>>>> 34e8884e442c9f2a4e45103fddb77005f086e69c
}