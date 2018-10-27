Tetris in C
===========

*************************************************
Copyright (c) 2018 	
- Felix Weichselgartner
- Marc Zeitler
- Matthias Lohberger

further information on the end of the file
*************************************************

Aufteilung der Dateien und Funktionen:

- Matthias:
	- Spielfiguren.c
	- Spielfeld_loh.c
		- spielfeldausgabe()
		- figuren
		- farbliche Gestaltung

- Marc:
	- Gamefunctions_Zei.c
		- spawn()
		- collision() //Returnwert 1: kollision, 0: keine kollision
		- reiheloeschen()
		- score()

- Felix:
	- Gameloop_Wei.c
	- Tetris.c
		- main()
		- gameloop()
		- down()
		- leftright()
        - verloren()

*************************************************

Usage of Github:

If you want to clone the repository:
```
git clone https://github.com/FelixWeichselgartner/Tetris.git
```

For developers:

You can pull files with this:
```
git pull origin master
```

After editing files:
```
git commit -am "Here your comment"
git push origin master
```

Adding files to the repository:
```
git add filename.fileending
git status
git commit -am ""
git push origin master
```

*************************************************

Here the information on Copyright:

All files and all lines of code are owned by the
persons named in the beginning of the file.
All rights are reserved.

If you want to use our code please contact:
    e-mail: fwei3012@gmail.com

*************************************************