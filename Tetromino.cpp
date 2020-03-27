/*
* Tetris in C - header by Matthias Lohberger
*/
#include "Tetromino.hpp"

Node fig1[y][x];
Node fig2[y][x];
Node fig3[y][x];
Node fig4[y][x];
Node fig5[y][x];
Node fig6[y][x];
Node fig7[y][x];
Node fig8[y][x];
Node fig9[y][x];
Node fig10[y][x];
Node fig11[y][x];
Node fig12[y][x];
Node fig13[y][x];
Node fig14[y][x];
Node fig15[y][x];
Node fig16[y][x];
Node fig17[y][x];
Node fig18[y][x];
Node fig19[y][x];

//zu Farben:
//Stab			Farbe: blau/ Nummer: 153
//Viereck		Farbe: gelb/ Nummer: 238
//Blitz			Farbe: rot/ Nummer: 204
//T-Stück		Farbe: pink/ Nummer: 221
//L-Stück		Farbe: grün/ Nummer: 170

void build_figures(Node fig[x][x], char fg[x][x], int color, int nr, int l, int r)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			fig[i][j].set_figure(fg[j][i]);
			if (fg[j][i] != ' ')
			{
				fig[i][j].set_color(color);
				fig[i][j].set_spawn_number(nr);
				fig[i][j].set_turn_left(l);
				fig[i][j].set_turn_right(r);
			}
			else
			{
				fig[i][j].set_color(0);
				fig[i][j].set_spawn_number(0);
				fig[i][j].set_turn_left(0);
				fig[i][j].set_turn_right(0);
			}
		}
	}
}

// straight polyomino
char fg1[y][x] = {'O', ' ', ' ', ' ',
				  'O', ' ', ' ', ' ',
				  'O', ' ', ' ', ' ',
				  'O', ' ', ' ', ' '};

char fg2[y][x] = {' ', ' ', ' ', ' ',
				  ' ', ' ', ' ', ' ',
				  ' ', ' ', ' ', ' ',
				  'O', 'O', 'O', 'O'};

// square polyomino
char fg3[y][x] = {' ', ' ', ' ', ' ',
				  ' ', ' ', ' ', ' ',
				  'O', 'O', ' ', ' ',
				  'O', 'O', ' ', ' '};

// skew polyominos (S)
char fg4[y][x] = {' ', ' ', ' ', ' ',
				  ' ', ' ', ' ', ' ',
				  ' ', 'O', 'O', ' ',
				  'O', 'O', ' ', ' '};

char fg5[y][x] = {' ', ' ', ' ', ' ',
				  'O', ' ', ' ', ' ',
				  'O', 'O', ' ', ' ',
				  ' ', 'O', ' ', ' '};

// skew polyominos (Z)
char fg6[y][x] = {' ', ' ', ' ', ' ',
				  ' ', ' ', ' ', ' ',
				  'O', 'O', ' ', ' ',
				  ' ', 'O', 'O', ' '};

char fg7[y][x] = {' ', ' ', ' ', ' ',
				  ' ', 'O', ' ', ' ',
				  'O', 'O', ' ', ' ',
				  'O', ' ', ' ', ' '};

// T-polyomino
char fg8[y][x] = {' ', ' ', ' ', ' ',
				  ' ', ' ', ' ', ' ',
				  'O', 'O', 'O', ' ',
				  ' ', 'O', ' ', ' '};

char fg9[y][x] = {' ', ' ', ' ', ' ',
				  'O', ' ', ' ', ' ',
				  'O', 'O', ' ', ' ',
				  'O', ' ', ' ', ' '};

char fg10[y][x] = {' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ',
				   ' ', 'O', ' ', ' ',
				   'O', 'O', 'O', ' '};

char fg11[y][x] = {' ', ' ', ' ', ' ',
				   ' ', 'O', ' ', ' ',
				   'O', 'O', ' ', ' ',
				   ' ', 'O', ' ', ' '};

// J-polyomino
char fg12[y][x] = {' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ',
				   'O', ' ', ' ', ' ',
				   'O', 'O', 'O', ' '};

char fg13[y][x] = {' ', ' ', ' ', ' ',
				   ' ', 'O', ' ', ' ',
				   ' ', 'O', ' ', ' ',
				   'O', 'O', ' ', ' '};

char fg14[y][x] = {' ', ' ', ' ', ' ',
				   'O', 'O', ' ', ' ',
				   'O', ' ', ' ', ' ',
				   'O', ' ', ' ', ' '};

char fg15[y][x] = {' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ',
				   'O', 'O', 'O', ' ',
				   ' ', ' ', 'O', ' '};

// L-polyomino
char fg16[y][x] = {' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ',
				   ' ', ' ', 'O', ' ',
				   'O', 'O', 'O', ' '};

char fg17[y][x] = {' ', ' ', ' ', ' ',
				   'O', 'O', ' ', ' ',
				   ' ', 'O', ' ', ' ',
				   ' ', 'O', ' ', ' '};

char fg18[y][x] = {' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ',
				   'O', 'O', 'O', ' ',
				   'O', ' ', ' ', ' '};

char fg19[y][x] = {' ', ' ', ' ', ' ',
				   'O', ' ', ' ', ' ',
				   'O', ' ', ' ', ' ',
				   'O', 'O', ' ', ' '};

void initialise_pieces()
{
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
	build_figures(fig13, fg13, 170, 13, 15, 12);
	build_figures(fig14, fg14, 170, 14, 12, 15);
	build_figures(fig15, fg15, 170, 15, 14, 13);
	build_figures(fig16, fg16, 170, 16, 17, 19);
	build_figures(fig17, fg17, 170, 17, 18, 16);
	build_figures(fig18, fg18, 170, 18, 19, 17);
	build_figures(fig19, fg19, 170, 19, 16, 18);
}