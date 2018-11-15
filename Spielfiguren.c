#define y 4
#define x 4

struct f {
	char fgr; //figur
	int clr; //color
	int spawnnumber;
};

fig1.clr = fig2.clr = 153; 					//Stab			Farbe: blau/ Nummer: 153	
fig3.clr = 238;								//Viereck		Farbe: gelb/ Nummer: 238	
fig4.clr = fig5.clr = fig6.clr = fig7.clr = 204; 	//Blitz	Farbe: rot/ Nummer: 204
fig8.clr = fig9.clr = fig10.clr = fig11.clr = 221; 	//T-Stück  Farbe: pink/ Nummer: 221	
fig12.clr = fig13.clr = fig14.clr = fig15.clr = fig16.clr = fig17.clr = fig18.clr = fig19.clr = 170; 	//L-Stück  Farbe: grün/ Nummer: 170 

//Stab					
char fig1[y][x] =	{'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' '};
						
char fig2[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', 'O'};
						
						
//Viereck				
char fig3[y][x] =	{'O', 'O', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' '};
						
						
//Blitz 1						
char fig4[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', 'O', 'O', ' ',
						'O', 'O', ' ', ' '};
											
char fig5[y][x] =	{' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', ' ', ' '};


//Blitz 2				
char fig6[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', 'O', ' '};
						
char fig7[y][x] =	{' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', ' ', ' ',
						'O', ' ', ' ', ' '};


//T-Stück					
char fig8[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', ' ',
						' ', 'O', ' ', ' '};
						
char fig9[y][x] =	{' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						'O', ' ', ' ', ' '};
						
char fig10[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', 'O', ' '};
						
char fig11[y][x] =	{' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', ' ', ' '};
						
						
//L 1		
char fig12[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', 'O', ' '};
						
char fig13[y][x] =	{' ', ' ', ' ', ' ',
						' ', 'O', ' ', ' ',
						' ', 'O', ' ', ' ',
						'O', 'O', ' ', ' '};
						
char fig14[y][x] =	{' ', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' '};
						
char fig15[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', ' ',
						' ', ' ', 'O', ' '};
						
						
//L 2					
char fig16[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						' ', ' ', 'O', ' ',
						'O', 'O', 'O', ' '};
						
char fig17[y][x] =	{' ', ' ', ' ', ' ',
						'O', 'O', ' ', ' ',
						' ', 'O', ' ', ' ',
						' ', 'O', ' ', ' '};
								
char fig18[y][x] =	{' ', ' ', ' ', ' ',
						' ', ' ', ' ', ' ',
						'O', 'O', 'O', ' ',
						'O', ' ', ' ', ' '};
						
char fig19[y][x] =	{' ', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', ' ', ' ', ' ',
						'O', 'O', ' ', ' '};
 