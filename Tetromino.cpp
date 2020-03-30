/*
* Tetris in C - header by Matthias Lohberger
*/
#include "Tetromino.hpp"

Node fig1[y][x];    // I-Block / Hero / color: cyan
Node fig2[y][x];
Node fig3[y][x];    // O-Block / Smashboy / color: yellow
Node fig4[y][x];    // S-Block / Rhode Island Z / color: green
Node fig5[y][x];
Node fig6[y][x];    // Z-Block / Cleveland Z / color: red
Node fig7[y][x];
Node fig8[y][x];    // T-Block / Teewee / color: magenta
Node fig9[y][x];
Node fig10[y][x];
Node fig11[y][x];
Node fig12[y][x];   // J-Block / Blue Ricky / color: blue
Node fig13[y][x];
Node fig14[y][x];
Node fig15[y][x];
Node fig16[y][x];   // L-Block / Orange Ricky / color: orange
Node fig18[y][x];
Node fig19[y][x];

//zu Farben:
//Stab			Farbe: blau/ Nummer: 153
//Viereck		Farbe: gelb/ Nummer: 238
//Blitz			Farbe: rot/ Nummer: 204
//T-Stück		Farbe: pink/ Nummer: 221
//L-Stück		Farbe: grün/ Nummer: 170

void build_figures(Node fig[x][x], char fg[x][x], QColor color, int nr, int l, int r)
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
                fig[i][j].set_color(QColor(0, 0, 0, 255));      // color: black (background)
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
    build_figures(fig1, fg1, QColor(0, 255, 255, 255), 1, 2, 2);        // cyan
    build_figures(fig2, fg2, QColor(0, 255, 255, 255), 2, 1, 1);
    build_figures(fig3, fg3, QColor(255, 255, 0, 255), 3, 3, 3);        // yellow
    build_figures(fig4, fg4, QColor(0, 255, 0, 255), 4, 5, 5);          // green
    build_figures(fig5, fg5, QColor(0, 255, 0, 255), 5, 4, 4);
    build_figures(fig6, fg6, QColor(255, 0, 0, 255), 6, 7, 7);          // red
    build_figures(fig7, fg7, QColor(255, 0, 0, 255), 7, 6, 6);
    build_figures(fig8, fg8, QColor(255, 0, 255, 255), 8, 9, 11);       // magenta
    build_figures(fig9, fg9, QColor(255, 0, 255, 255), 9, 10, 8);
    build_figures(fig10, fg10, QColor(255, 0, 255, 255), 10, 11, 9);
    build_figures(fig11, fg11, QColor(255, 0, 255, 255), 11, 8, 10);
    build_figures(fig12, fg12, QColor(0, 0, 255, 255), 12, 13, 14);     // blue
    build_figures(fig13, fg13, QColor(0, 0, 255, 255), 13, 15, 12);
    build_figures(fig14, fg14, QColor(0, 0, 255, 255), 14, 12, 15);
    build_figures(fig15, fg15, QColor(0, 0, 255, 255), 15, 14, 13);
    build_figures(fig16, fg16, QColor(255, 129, 0, 255), 16, 17, 19);   // orange
    build_figures(fig17, fg17, QColor(255, 129, 0, 255), 17, 18, 16);
    build_figures(fig18, fg18, QColor(255, 129, 0, 255), 18, 19, 17);
    build_figures(fig19, fg19, QColor(255, 129, 0, 255), 19, 16, 18);
}

