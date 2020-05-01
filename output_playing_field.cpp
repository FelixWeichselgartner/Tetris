#include <stdio.h>
#include "Tetris.hpp"
#include <string.h>
#include <QPainter>
#include "output_playing_field.h"
#include <QDebug>
#include <Node.hpp>
#include <Tetromino.hpp>

//-------------------------------------------------------------------------------------------
// Var für Positionsermittlung, Größenermittlung und Formatierung der Ausgabe können angepasst werden

// Koordinaten Singleplayer
    // Spielfeld Singleplayer
#define xBasisCoordPlayFieldSg 400
#define yBasisCoordPlayFieldSg 70
    // NextWidget Singleplayer
#define xBasisCoordNextWidgetSg 230
#define yBasisCoordNextWidgetSg 70
#define xCenterPointNextWidgetSg 300
#define yCenterPointNextWidgetSg 124

// Koordinaten Multiplayer
    // Spielfeld Multiplayer links
#define xBasisCoordPlayFieldMpLeft 177
#define yBasisCoordPlayFieldMpLeft 117
    // NextWidget Multiplayer links
#define xBasisCoordNextWidgetMpLeft 30
#define yBasisCoordNextWidgetMpLeft 117
#define xCenterPointNextWidgetMpLeft 100
#define yCenterPointNextWidgetMpLeft 170
    // Spielfeld Multiplayer rechts
#define xBasisCoordPlayFieldMpRight 637
#define yBasisCoordPlayFieldMpRight 117
    // NextWidget Multiplayer rechts
#define xBasisCoordNextWidgetMpRight 1000
#define yBasisCoordNextWidgetMpRight 117
#define xCenterPointNextWidgetMpRight 1070
#define yCenterPointNextWidgetMpRight 170


//Defines für die Größe der Spielsteine, etc.
    // Rand (Abstand zu gezeichnetem Spielfeldrahmen
#define xGap 0                  //in mehreren Fnk verwendet
#define yGap 0
    //Seitenlänge und Randdicke eines Ausgegebenen Quadrats
#define quadSideLegth 35
#define quadFrameWidth 3

//#define OffsetSecondField 0        // im Singleplayer, im Mp konstanter Wert
//-------------------------------------------------------------------------------------------

/*
void highscore_aufruf() {						//Highscoreausgabe
	char c;												//Hilfsarray
	int a = 0;											//Zählvariable
	FILE *fptr;
	int fehler;

	printf("\nHighscoreliste:\n");
	printf("\n");
									//aus Datei lesen
	fptr = fopen("Highscores.txt", "r");
	if (fptr == NULL) {
		printf("\nDie Datei konnte nicht geoeffnet werden!\n");
		return;
	}
	while (!feof(fptr)) {			//Ausgabe
		c = fgetc(fptr);
		
		if (c == ';' && a <= 7) {
			printf("\t\t");			//für kleinere Namen
		}
		else if (c == ';' && a > 7) {
			printf("\t");				//für größere Namen
		}
		else if (c == '\n') {
			putchar(c);					//a zurücksetzten
			a = 0;
		}
		else {
			putchar(c);					//normale Ausgabe, a wird erhöht
			a++;
		}
	}
	fehler = fclose(fptr);
	if (fehler != 0) {					//Datei schließen
		printf("\nFehler %i beim Schließen der Datei!\n", fehler);
		return;
	}
	getchar();
}

*/

//------------------------------------------------------------------------------------------------------------------------------------------------------



void draw_field(QPainter *painter, Field* field, int xBasisCoordPlayField, int yBasisCoordPlayField) {       //fehlt Übergabe von Farbe als Variable!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden

    int xOffset;                        // sollte 403 sein
    int yOffset;                        // sollte 73 sein

    // Leere Var, werden errrechnet, etc.
    int i, j;                           // Laufvar
    int xCoord, yCoord;                 // tatsächliche Koord der lnke oberen Ecke jedes ausgegebenen Quadrats

    QPen pen;                           // Var für Rahmen
    QBrush brush;                       // Var für Füllung



    xOffset = xBasisCoordPlayField + xGap;                      //kann im vorhinein berechnet werden, bleibt immer konstant
    yOffset = yBasisCoordPlayField + yGap;



    for(i=0; i<22; i++){                                                    // Zeile durchlaufen ^= y
        for(j=0; j<10; j++){                                                // Zeile durchlaufen ^= x
            xCoord = xOffset + (j * quadSideLegth);
            yCoord = yOffset + (i * quadSideLegth);                         // kein Offset notw.

            //qDebug() << "Array (Xpos/Ypos): ( " << i << " / " << j << " )" << "\t||" << "Seitenlänge: " << quadSideLegth << "Randdicke: " << quadFrameWidth << "\t||" << "Reale Koord (x/y): ( " << xCoord << " / " << yCoord << " )" << "\t||" << "\n";


            pen.setColor(Qt::black);                                // Farbe des Rahmens
            //pen.setColor(Qt::red);                                // Farbe des Rahmens
            pen.setWidth(quadFrameWidth);                           // Breite des Rahmens
            painter->setPen(pen);                                   // Setzten des Rahmens

            brush.setStyle(Qt::SolidPattern);                       // Art der Füllung
            brush.setColor(field->get_copy(j, i+4).get_color());    // Farbe der Füllung
            painter->setBrush(brush);                               // Setzten der Füllung

            painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        }
    }
}



//---------------------------------------------------------------------------------------------------------------
//Output des next-Widget




void OutputNextWidget(QPainter *painter, int spawn_number, int xBasisCoordNextWidget, int yBasisCoordNextWidget, int xCenterPointNextWidget, int yCenterPointNextWidget){

    //qDebug() << "Spawnnumber: " << spawn_number << "\n";

    if (spawn_number == 1 || spawn_number == 2 || spawn_number == 23 || spawn_number == 24){               // I-Block / Hero / color: cyan
        OutputNextWidgetIBlock(painter, fig2, xBasisCoordNextWidget, yBasisCoordNextWidget);
    }
    else if (spawn_number == 3 || spawn_number == 20 || spawn_number == 21 || spawn_number == 22){         // O-Block / Smashboy / color: yellow
        OutputNextWidgetOBlock(painter, fig3, xCenterPointNextWidget, yCenterPointNextWidget);
    }
    else if (spawn_number == 4 || spawn_number == 5){                                                       // S-Block / Rhode Island Z / color: green
        OutputNextWidget3x2(painter, fig5, xBasisCoordNextWidget, yBasisCoordNextWidget);
    }
    else if (spawn_number == 6 || spawn_number == 7){                                                       // Z-Block / Cleveland Z / color: red
        OutputNextWidget3x2(painter, fig7, xBasisCoordNextWidget, yBasisCoordNextWidget);
    }
    else if (spawn_number == 8 || spawn_number == 9 || spawn_number == 10 || spawn_number == 11){           // T-Block / Teewee / color: magenta
        OutputNextWidget3x2(painter, fig9, xBasisCoordNextWidget, yBasisCoordNextWidget);
    }
    else if (spawn_number == 12 || spawn_number == 13 || spawn_number == 14 || spawn_number == 15){         // J-Block / Blue Ricky / color: blue
        OutputNextWidget3x2(painter, fig13, xBasisCoordNextWidget, yBasisCoordNextWidget);
    }
    else if (spawn_number == 16 || spawn_number == 17 || spawn_number == 18 || spawn_number == 19){         // L-Block / Orange Ricky / color: orange
        OutputNextWidget3x2(painter, fig19, xBasisCoordNextWidget, yBasisCoordNextWidget);
    }
    else{
        qDebug() << "Fatal!!!Spawnnumber nicht vorhanden: " << spawn_number << "\n";                // in case of failure
    }
}





void OutputNextWidget3x2 (QPainter *painter, Node tempfigure[4][4], int xBasisCoordNextWidget, int yBasisCoordNextWidget){
    // Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden

    int xOffset;                        // sollte 403 sein
    int yOffset;                        // sollte 73 sein

    // Leere Var, werden errrechnet, etc.
    int i, j;                           // Laufvar
    int xCoord, yCoord;                 // tatsächliche Koord der lnke oberen Ecke jedes ausgegebenen Quadrats

    QPen pen;                           // Var für Rahmen
    QBrush brush;                       // Var für Füllung                     // Var für Füllung


    QColor color = QColor(0, 0, 0, 0);

    pen.setColor(Qt::black);                                // Farbe des Rahmens
    pen.setWidth(quadFrameWidth);                           // Breite des Rahmens
    painter->setPen(pen);                                   // Setzten des Rahmens

    brush.setStyle(Qt::SolidPattern);                       // Art der Füllung



    xOffset = xBasisCoordNextWidget + xGap;                      //kann im vorhinein berechnet werden, bleibt immer konstant
    yOffset = yBasisCoordNextWidget + yGap;

    xCoord = xOffset;
    yCoord = yOffset;                         // Zusammenlegen mit dem drüber und in fnk abändern!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    for(i = 1; i <=3; i++){

        brush.setColor(color);                              // Farbe der Füllung
        painter->setBrush(brush);                           // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));

        for (j=0; j<=2; j++){

            xCoord += 35;

            brush.setColor(tempfigure[j][i].get_color());   // Farbe der Füllung
            painter->setBrush(brush);                       // Setzten der Füllung
            painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        }
        yCoord +=35;
        xCoord = xOffset;
    }
}





void OutputNextWidgetIBlock (QPainter *painter, Node tempfigure[4][4], int xBasisCoordNextWidget, int yBasisCoordNextWidget){
    // Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden

    int xOffset;                        // sollte 403 sein
    int yOffset;                        // sollte 73 sein

    // Leere Var, werden errrechnet, etc.
    int i, j;                           // Laufvar
    int xCoord, yCoord;                 // tatsächliche Koord der lnke oberen Ecke jedes ausgegebenen Quadrats

    QPen pen;                           // Var für Rahmen
    QBrush brush;                       // Var für Füllung                     // Var für Füllung

    QColor color = QColor(0, 0, 0, 0);


    pen.setColor(Qt::black);                                // Farbe des Rahmens
    pen.setWidth(quadFrameWidth);                           // Breite des Rahmens
    painter->setPen(pen);                                   // Setzten des Rahmens

    brush.setStyle(Qt::SolidPattern);                       // Art der Füllung

    xOffset = xBasisCoordNextWidget + xGap;                      //kann im vorhinein berechnet werden, bleibt immer konstant
    yOffset = yBasisCoordNextWidget + yGap;

    xCoord = xOffset;
    yCoord = yOffset;                         // Zusammenlegen mit dem drüber und in fnk abändern!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


    for(i = 0; i <=3; i++){                                                             // Ausgabe 4 schwarze Quadrate oben
        brush.setColor(color);                              // Farbe der Füllung
        painter->setBrush(brush);                           // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        xCoord += 35;
    }
    yCoord += 35;
    xCoord = xOffset;

    for (j=0; j<=3; j++){                                                               // Ausgabe Stab mittig
        brush.setColor(tempfigure[j][3].get_color());   // Farbe der Füllung
        painter->setBrush(brush);                       // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        xCoord += 35;
    }
    yCoord += 35;
    xCoord = xOffset;

    for(i = 0; i <=3; i++){                                                             // Ausgabe 4 schwarze Quadrate oben
        brush.setColor(color);                              // Farbe der Füllung
        painter->setBrush(brush);                           // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        xCoord += 35;
    }
    yCoord += 35;
    xCoord = xOffset;
}










void OutputNextWidgetOBlock (QPainter *painter, Node tempfigure[4][4], int xCenterPointNextWidget, int yCenterPointNextWidget){
    // Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden

    int xOffset;                        // sollte 403 sein
    int yOffset;                        // sollte 73 sein

    // Leere Var, werden errrechnet, etc.
    int i, j;                           // Laufvar
    int xCoord, yCoord;                 // tatsächliche Koord der lnke oberen Ecke jedes ausgegebenen Quadrats

    QPen pen;                           // Var für Rahmen
    QBrush brush;                       // Var für Füllung


    xOffset = xCenterPointNextWidget - quadSideLegth;       //linke obere Ecke des 1. Quadrats
    yOffset = yCenterPointNextWidget - quadSideLegth;

    //immer gleich für O-Block
    pen.setColor(Qt::black);                                // Farbe des Rahmens
    pen.setWidth(quadFrameWidth);                           // Breite des Rahmens
    painter->setPen(pen);                                   // Setzten des Rahmens

    brush.setStyle(Qt::SolidPattern);                       // Art der Füllung
    brush.setColor(tempfigure[0][3].get_color());
    //brush.setColor(Qt::yellow);
    painter->setBrush(brush);                               // Setzten der Füllung


    for (i=0; i<=1; i++){
        for(j=0; j<=1; j++){

            xCoord = xOffset + (j * quadSideLegth);
            yCoord = yOffset + (i * quadSideLegth);                         // kein Offset notw.
            //qDebug() << "Koordinaten (x/y): (" << xCoord << " / " << yCoord << ")\n";
            painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
            //qDebug() << "Zeichen erfolgt!\n";
        }
    }
}



//---------------------------------------------------------------------------------------------------------------------------------------


void OutputModeSelection(QPainter *painter, int spawn_number, Field* field, char position){
     //                 für PintEvent       Auswahl in NextWidget  Spielfeld    Position NextWidget und Spielfeld

    int OffsetZero = 0;

    switch (position) {
    case 'm':                                                               //Singleplayer

        draw_field(painter, field, xBasisCoordPlayFieldSg, yBasisCoordPlayFieldSg);
        OutputNextWidget(painter, spawn_number, xBasisCoordNextWidgetSg, yBasisCoordNextWidgetSg, xCenterPointNextWidgetSg, yCenterPointNextWidgetSg);
        break;

    case 'l':                                                               //Multiplayer links

        draw_field(painter,field, xBasisCoordPlayFieldMpLeft, yBasisCoordPlayFieldMpLeft);
        OutputNextWidget(painter,spawn_number, xBasisCoordNextWidgetMpLeft, yBasisCoordNextWidgetMpLeft, xCenterPointNextWidgetMpLeft, yCenterPointNextWidgetMpLeft);
        break;

    case 'r':                                                               //Multiplayer rechts
        draw_field(painter,field, xBasisCoordPlayFieldMpRight, yBasisCoordPlayFieldMpRight);
        OutputNextWidget(painter,spawn_number, xBasisCoordNextWidgetMpRight, yBasisCoordNextWidgetMpRight, xCenterPointNextWidgetMpRight, yCenterPointNextWidgetMpRight);
        break;
    }
}













