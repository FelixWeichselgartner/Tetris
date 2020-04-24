#pragma once
#include <QMainWindow>
#include "Field.hpp"
#include "Tetris.hpp"

void draw_field(QPainter *, Field* field, int xBasisCoordPlayField, int yBasisCoordPlayField);

void OutputNextWidget3x2 (QPainter *painter, Node tempfigure[4][4], int xBasisCoordNextWidget, int yBasisCoordNextWidget);
void OutputNextWidgetIBlock (QPainter *painter, Node tempfigure[4][4], int xBasisCoordNextWidget, int yBasisCoordNextWidget);
void OutputNextWidgetOBlock (QPainter *painter, Node tempfigure[4][4], int xCenterPointNextWidget, int yCenterPointNextWidget);

void OutputNextWidget(QPainter *painter, int spawn_number, int xBasisCoordNextWidget, int yBasisCoordNextWidget, int xCenterPointNextWidget, int yCenterPointNextWidget);

void OutputModeSelection(QPainter *painter, int spawn_number, Field* field, char position);




