#pragma once

#include "Tetris.hpp"

#define y 4
#define x 4

extern Node fig1[y][x];
extern Node fig2[y][x];
extern Node fig3[y][x];
extern Node fig4[y][x];
extern Node fig5[y][x];
extern Node fig6[y][x];
extern Node fig7[y][x];
extern Node fig8[y][x];
extern Node fig9[y][x];
extern Node fig10[y][x];
extern Node fig11[y][x];
extern Node fig12[y][x];
extern Node fig13[y][x];
extern Node fig14[y][x];
extern Node fig15[y][x];
extern Node fig16[y][x];
extern Node fig17[y][x];
extern Node fig18[y][x];
extern Node fig19[y][x];

void initialise_pieces();
void build_figures(Node fig[4][4], char fg[4][4], int color, int nr, int l, int r);
