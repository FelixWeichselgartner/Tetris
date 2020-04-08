#pragma once
#include <QMainWindow>
#include "Field.hpp"
#include "Tetris.hpp"

void draw_field(QPainter *, Field* field);

void OutputNextWidget3x2 (QPainter *painter, Node tempfigure[4][4]);
void OutputNextWidgetIBlock (QPainter *painter, Node tempfigure[4][4]);
void OutputNextWidgetOBlock (QPainter *painter, Node tempfigure[4][4]);
void OutputNextWidget(QPainter *painter, int spawn_number);
