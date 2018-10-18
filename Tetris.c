#include <stdio.h>
#include <time.h>
#include "Gameloop_Wei.h"
#include "Gamefunctions_Zei.h"
#include "Spielfeld_loh.h"
#include "Spielfiguren.h"

#define true 1
#define false 0

const int xlength = 10;
const int ylength = 26;

int punktestand = 0;

char spielfeld[xlength][ylength];

void main() {
	int vorbei;
	init_spielfeld();
	vorbei = gameloop();
	if(vorbei == true){
		highscore();
	}
}