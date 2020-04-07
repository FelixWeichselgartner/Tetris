#include <stdio.h>
#include "Tetris.hpp"
#include <string.h>
#include <QPainter>
#include "output_playing_field.h"
#include <QDebug>
#include <Node.hpp>
#include <Tetromino.hpp>


// Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden
#define xBasisCoordPlayField 400
#define yBasisCoordPlayField 70

#define xBasisCoordNextWidget 230
#define yBasisCoordNextWidget 67

#define xOBlockCoordNextWidget 355
#define yOBlockCoordNextWidget 124

#define xGap 0
#define yGap 0

#define quadSideLegth 35
#define quadFrameWidth 3

#define OffsetSecondField 0        // im Singleplayer, im Mp konstanter Wert

#define CenterPointNextWidget 0
//-------------------------------------------------------------------------------------------


void Tetris::highscore_aufruf() {						//Highscoreausgabe
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

int i = 0;

void draw_field(QPainter *painter, Field* field) {       //fehlt Übergabe von Farbe als Variable!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
            xCoord = xOffset + (j * quadSideLegth) + OffsetSecondField;
            yCoord = yOffset + (i * quadSideLegth);                         // kein Offset notw.

            //qDebug() << "Array (Xpos/Ypos): ( " << i << " / " << j << " )" << "\t||" << "Seitenlänge: " << quadSideLegth << "Randdicke: " << quadFrameWidth << "\t||" << "Reale Koord (x/y): ( " << xCoord << " / " << yCoord << " )" << "\t||" << "\n";


            pen.setColor(Qt::black);                                // Farbe des Rahmens
            pen.setWidth(quadFrameWidth);                           // Breite des Rahmens
            painter->setPen(pen);                                   // Setzten des Rahmens

            brush.setStyle(Qt::SolidPattern);                       // Art der Füllung
            brush.setColor(field->get_copy(j, i+4).get_color());    // Farbe der Füllung
            painter->setBrush(brush);                               // Setzten der Füllung

            painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        }
    }
}









void OutputNextWidget(QPainter *painter, int spawn_number){

    qDebug() << "Spawnnumber: " << spawn_number << "\n";

    if (spawn_number == 1 || spawn_number == 2){            // I-Block / Hero / color: cyan
        OutputNextWidgetIBlock(painter, fig2);
    }
    else if (spawn_number == 3){                            // O-Block / Smashboy / color: yellow

    }
    else if (spawn_number == 4 || spawn_number == 5){       // S-Block / Rhode Island Z / color: green
        OutputNextWidget3x2(painter, fig5);
    }
    else if (spawn_number == 6 || spawn_number == 7){       // Z-Block / Cleveland Z / color: red
        OutputNextWidget3x2(painter, fig7);
    }
    else if (spawn_number == 8 || spawn_number == 9 || spawn_number == 10 || spawn_number == 11){           // T-Block / Teewee / color: magenta
        OutputNextWidget3x2(painter, fig9);
    }
    else if (spawn_number == 12 || spawn_number == 13 || spawn_number == 14 || spawn_number == 15){         // J-Block / Blue Ricky / color: blue
        OutputNextWidget3x2(painter, fig13);
    }
    else if (spawn_number == 16 || spawn_number == 17 || spawn_number == 18 || spawn_number == 19){         // L-Block / Orange Ricky / color: orange
        OutputNextWidget3x2(painter, fig19);
    }
    else{
        qDebug() << "Spawnnumber nicht vorhanden: " << spawn_number << "\n";                // in case of failure
    }
}





void OutputNextWidget3x2 (QPainter *painter, Node tempfigure[4][4]){
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

    xCoord = xOffset + OffsetSecondField;
    yCoord = yOffset;                         // kein Offset notw.


    for(i = 4; i <=2; i--){

        brush.setColor(color);                              // Farbe der Füllung
        painter->setBrush(brush);                               // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));

        for (j=0; j<=2; j++){

            xCoord += 35;

            brush.setColor(tempfigure[j][i].get_color());   // Farbe der Füllung
            painter->setBrush(brush);                       // Setzten der Füllung
            painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        }
        yCoord +=35;
    }
}





void OutputNextWidgetIBlock (QPainter *painter, Node tempfigure[4][4]){
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

    xCoord = xOffset + OffsetSecondField;
    yCoord = yOffset;                         // kein Offset notw.


    for(i = 0; i <=3; i++){                                                             // Ausgabe 4 schwarze Quadrate oben
        brush.setColor(color);                              // Farbe der Füllung
        painter->setBrush(brush);                           // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        xCoord += 35;
    }
    yCoord += 35;
    xCoord = xOffset + OffsetSecondField;

    for (j=0; j<=3; j++){                                                               // Ausgabe Stab mittig
        brush.setColor(tempfigure[j][3].get_color());   // Farbe der Füllung
        painter->setBrush(brush);                       // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        xCoord += 35;
    }
    yCoord += 35;
    xCoord = xOffset + OffsetSecondField;

    for(i = 0; i <=3; i++){                                                             // Ausgabe 4 schwarze Quadrate oben
        brush.setColor(color);                              // Farbe der Füllung
        painter->setBrush(brush);                           // Setzten der Füllung
        painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        xCoord += 35;
    }
    yCoord += 35;
    xCoord = xOffset + OffsetSecondField;
}










void OutputNextWidgetOBlock (QPainter *painter, Node tempfigure[4][4]){
    // Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden

    int xOffset;                        // sollte 403 sein
    int yOffset;                        // sollte 73 sein

    // Leere Var, werden errrechnet, etc.
    int i, j;                           // Laufvar
    int xCoord, yCoord;                 // tatsächliche Koord der lnke oberen Ecke jedes ausgegebenen Quadrats

    QPen pen;                           // Var für Rahmen
    QBrush brush;                       // Var für Füllung

    xOffset = xOBlockCoordNextWidget + xGap;                      //kann im vorhinein berechnet werden, bleibt immer konstant
    yOffset = yOBlockCoordNextWidget + yGap;

    for (i=0; i<=1; i++){
        for(j=0; j<=1; j++){

            xCoord = xOffset + (j * quadSideLegth) + OffsetSecondField;
            yCoord = yOffset + (i * quadSideLegth);                         // kein Offset notw.

            pen.setColor(Qt::black);                                // Farbe des Rahmens
            pen.setWidth(quadFrameWidth);                           // Breite des Rahmens
            painter->setPen(pen);                                   // Setzten des Rahmens

            brush.setStyle(Qt::SolidPattern);                       // Art der Füllung
            brush.setColor(tempfigure[3][3].get_color());
            painter->setBrush(brush);                               // Setzten der Füllung

            painter->drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        }
    }
}


















