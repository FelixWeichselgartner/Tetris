#include <stdio.h>
#include "Tetris.hpp"
#include <string.h>
#include <QPainter>
#include "output_playing_field.h"
#include <QDebug>


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


void draw_field(QMainWindow *window, Node field[xlength][ylength]) {       //fehlt Übergabe von Farbe als Variable!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // Var für Positionsermittlung/ Formatierung der Ausgabe können angepasst werden
    int xBasisCoord = 400;
    int yBasisCoord = 70;

    int xGap = 0;
    int yGap = 0;

    int xOffset;                        // sollte 403 sein
    int yOffset;                        // sollte 73 sein

    int quadSideLegth = 35;
    int quadFrameWidth = 2;

    int OffsetSecondField = 0;          // im Singleplayer, im Mp konstanter Wert


    // Leere Var, werden errrechnet, etc.
    int i, j;                           // Laufvar
    int xCoord, yCoord;                 // tatsächliche Koord der lnke oberen Ecke jedes ausgegebenen Quadrats

    qInfo() << window << endl;
    return;
    QPainter painter(window);
    QPen pen;                           // Var für Rahmen
    QBrush brush;                       // Var für Füllung


    xOffset = xBasisCoord + xGap;                      //kann im vorhinein berechnet werden, bleibt immer konstant
    yOffset = yBasisCoord + yGap;



    for(i=0; i<22; i++){                                                    // Zeile durchlaufen ^= y
        for(j=0; j<10; j++){                                                // Zeile durchlaufen ^= x
            xCoord = xOffset + (j * quadSideLegth) + OffsetSecondField;
            yCoord = yOffset + (i * quadSideLegth);                         // kein Offset notw.

            pen.setColor(Qt::black);                // Farbe des Rahmens
            pen.setWidth(quadFrameWidth);                        // Breite des Rahmens
            painter.setPen(pen);                    // Setzten des Rahmens

            brush.setStyle(Qt::SolidPattern);       // Art der Füllung
            brush.setColor(Qt::red);                // Farbe der Füllung
            painter.setBrush(brush);                // Setzten der Füllung

            painter.drawRect(QRect(xCoord, yCoord, quadSideLegth, quadSideLegth));
        }
        }
    }












 
