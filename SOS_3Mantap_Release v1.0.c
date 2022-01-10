#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

/*  Modul Utama  */
void drawBoard();
void drawBoard2();
void createNickname();
void createNicknameComp();
void mainmenu();
void selectBoard();
void selectOpponent();
void selectLevel();
void howToPlay();
void gameEnd();

/*  Modul Operasi  */
void fillBoard();
void fillBoard2();
void selectBox();
void selectBox2();
void boxUnavailable();
void addScore();
void selectChoice();
int checkSOS();
int checkSOS2();
int checkEnd();
int checkEnd2();

/*  Modul Computer  */
void fillBoardComp();
void fillBoardComp2();
void searchOSHard();
void searchOSNormal();
void searchOS2Hard();
void searchOS2Normal();
void searchSSHard();
void searchSSNormal();
void searchSS2Hard();
void searchSS2Normal();
void botRandom();
void botRandom2();

/*	Modul Tampilan */
void gotoxy(int x, int y);
void fontsize(int,int);

/*  Modul Timer  */
int startTime();
int endTime();

/*  Variabel Global  */
char player1[10];		// variabel untuk menampung nama/nickname player 1
char player2[10];		// variabel untuk menampung nama/nickname player 2
int turn;				// variabel untuk menentukan giliran player saat bermain
int score1=0;			// variabel untuk menampung score yang dimiliki oleh player 1
int score2=0;			// variabel untuk menampung score yang dimiliki oleh player 2
char pilihMenu,pilihBoard,pilihOpponent,pilihLevel,pilihContinue;		// variabel untuk menampung pilihan ketentuan permainan yang akan dimainkan oleh player
int timer;				// variabel untuk menampung waktu awal penginputan

char Array1[7][7] =
{
  {'x','x','x','x','x','x','x'},
  {'x',' ',' ',' ',' ',' ','x'},
  {'x',' ',' ',' ',' ',' ','x'},
  {'x',' ',' ',' ',' ',' ','x'},
  {'x',' ',' ',' ',' ',' ','x'},
  {'x',' ',' ',' ',' ',' ','x'},
  {'x','x','x','x','x','x','x'},
};

char Array2[9][9]=
{
	{'x','x','x','x','x','x','x','x','x'},
  	{'x',' ',' ',' ',' ',' ',' ',' ','x'},
  	{'x',' ',' ',' ',' ',' ',' ',' ','x'}, 
  	{'x',' ',' ',' ',' ',' ',' ',' ','x'},
 	{'x',' ',' ',' ',' ',' ',' ',' ','x'}, 
 	{'x',' ',' ',' ',' ',' ',' ',' ','x'},
  	{'x',' ',' ',' ',' ',' ',' ',' ','x'},
  	{'x',' ',' ',' ',' ',' ',' ',' ','x'}, 
	{'x','x','x','x','x','x','x','x','x'},
};



int main(){
	int pilihValid;
	fontsize(10, 20); 
	system("COLOR 09");
	
	menu:
		score1=0;			
		score2=0;		
		mainmenu();
		switch(pilihMenu){
			case '1': selectBoard();break;
			case '2': howToPlay();goto menu;
			case '3': return 0;
			default : goto menu;
		}
		selectOpponent();
		switch(pilihOpponent){
			case '1': createNickname();break;
			case '2': createNicknameComp();break;
			default : goto menu;		
		}
		switch(pilihOpponent){
			case '1': switch(pilihBoard){
				case '1': fillBoard();goto menu;
				case '2': fillBoard2();goto menu;
				default : goto menu;
				}
			case '2': switch(pilihBoard){
				case '1': selectLevel();fillBoardComp();break;
				case '2': selectLevel();fillBoardComp2();break;
				default : goto menu;
				}
			default : goto menu;
		}
		if (pilihContinue=='1'){
			goto menu;
		}		
		return 0;
}


void drawBoard(){
	/*  Modul untuk menampilkan papan berukuran 5x5 ke layar  */
	
    printf("\n     1   2   3   4   5");
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("\n 1 %c %c %c %c %c %c %c %c %c %c %c  Score %s = %d",186,Array1[1][1],186,Array1[1][2],186,Array1[1][3],186,Array1[1][4],186,Array1[1][5],186,player1,score1);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 2 %c %c %c %c %c %c %c %c %c %c %c  Score %s = %d",186,Array1[2][1],186,Array1[2][2],186,Array1[2][3],186,Array1[2][4],186,Array1[2][5],186,player2,score2);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 3 %c %c %c %c %c %c %c %c %c %c %c",186,Array1[3][1],186,Array1[3][2],186,Array1[3][3],186,Array1[3][4],186,Array1[3][5],186);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 4 %c %c %c %c %c %c %c %c %c %c %c",186,Array1[4][1],186,Array1[4][2],186,Array1[4][3],186,Array1[4][4],186,Array1[4][5],186);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 5 %c %c %c %c %c %c %c %c %c %c %c",186,Array1[5][1],186,Array1[5][2],186,Array1[5][3],186,Array1[5][4],186,Array1[5][5],186);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,188);
}

void drawBoard2(){
	/*  Modul untuk menampilkan papan berukuran 7x7 ke layar  */
	
	printf("\n     1   2   3   4   5   6   7  ");
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("\n 1 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c  Score %s = %d",186,Array2[1][1],186,Array2[1][2],186,Array2[1][3],186,Array2[1][4],186,Array2[1][5],186,Array2[1][6],186,Array2[1][7],186,player1,score1);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 2 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c  Score %s = %d",186,Array2[2][1],186,Array2[2][2],186,Array2[2][3],186,Array2[2][4],186,Array2[2][5],186,Array2[2][6],186,Array2[2][7],186,player2,score2);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 3 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",186,Array2[3][1],186,Array2[3][2],186,Array2[3][3],186,Array2[3][4],186,Array2[3][5],186,Array2[3][6],186,Array2[3][7],186);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 4 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",186,Array2[4][1],186,Array2[4][2],186,Array2[4][3],186,Array2[4][4],186,Array2[4][5],186,Array2[4][6],186,Array2[4][7],186);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 5 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",186,Array2[5][1],186,Array2[5][2],186,Array2[5][3],186,Array2[5][4],186,Array2[5][5],186,Array2[5][6],186,Array2[5][7],186);
    printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 6 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",186,Array2[6][1],186,Array2[6][2],186,Array2[6][3],186,Array2[6][4],186,Array2[6][5],186,Array2[6][6],186,Array2[6][7],186);
    printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("\n 7 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",186,Array2[7][1],186,Array2[7][2],186,Array2[7][3],186,Array2[7][4],186,Array2[7][5],186,Array2[7][6],186,Array2[7][7],186);
	printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,188);
}

void selectChoice(char *xchoice,int *xchoiceValid){
	/*  Modul untuk menginputkan pilihan player apakah S/O  */
	
	timer = startTime(); // assignment untuk menentukan waktu awal penginputan													
	printf("\n   Masukkan Pilihan S/O : "); scanf(" %c",&*xchoice);
	
	/*	pengkondisian agar inputan hanya bisa S/O, 
		dan menjadikan s dan o kecil menjadi kapital
	*/
	switch(*xchoice){													
		case 'S' : *xchoice='S';*xchoiceValid=1;break;
		case 's' : *xchoice='S';*xchoiceValid=1;break;
		case 'O' : *xchoice='O';*xchoiceValid=1;break;
		case 'o' : *xchoice='O';*xchoiceValid=1;break;
		default : 	printf("\n   Hanya bisa S/O!");
					turn=turn-1;
					*xchoiceValid=0;
					getch();
					break;
	}	
	return;
}

/*----------------------------------------Player vs Player----------------------------------------*/

void fillBoard(){ 
	/* 	Modul untuk memulai permainan dengan papan 
		berukuran 5x5 dan mode Player vs Player  
	*/
	turn=0;
    char choice;		// variable untuk menampung pilihan S/O
    int choiceValid;	// variable untuk memvalidasi apakah inputan pilihan valid
    int row=1;		// variable untuk menampung posisi baris (indeks)
	int col=1;		// variable untuk menampung posisi kolom (indeks)
    
    // perulangan untuk memeriksa apakah permainan sudah berakhir atau belum
    while(!checkEnd()){
        
        if(turn%2==0){
			printf("\n   Giliran %s\n",player1);
		}
		else{
			printf("\n   Giliran %s\n",player2);	
		}	
		       
        choiceValid=0;
		drawBoard(); 
    	selectChoice(&choice,&choiceValid);
				
        if (choiceValid==1){	
           	selectBox(choice,&row,&col);	// pengisian pilihan yang telah dipilih oleh player ke dalam papan
            addScore(checkSOS(choice,row,col));		// pemeriksaan apakah input player membentuk pola sos atau tidak
		}
          
		turn ++;  
		system("cls"); 
		  
		if (checkEnd()){	// memeriksa apakah permainan sudah berakhir atau belum
			gameEnd();
		}
    }                   	
}

void fillBoard2(){
	/* 	Modul untuk memulai permainan dengan papan 
		berukuran 7x7 dan mode Player vs Player  
	*/
	turn=0;
    char choice;		// variable untuk menampung pilihan S/O
    int choiceValid;	// variable untuk memvalidasi apakah inputan pilihan valid
    int row=1;		// variable untuk menampung posisi baris (indeks)
	int col=1;		// variable untuk menampung posisi kolom (indeks)
    
    // perulangan untuk memeriksa apakah permainan sudah berakhir atau belum
    while(!checkEnd2()){
    	
    	if(turn%2==0){
			printf("\n   Giliran %s\n",player1);
		}
		else{
			printf("\n   Giliran %s\n",player2);	
		}	
        
        choiceValid=0;
		drawBoard2();
		selectChoice(&choice,&choiceValid);
                       
        if (choiceValid==1){
           	selectBox2(choice,&row,&col);	// pengisian pilihan yang telah dipilih oleh player ke dalam papan
            addScore(checkSOS2(choice,row,col));	// pemeriksaan apakah input player membentuk pola sos atau tidak	
		}
			
		turn++;
		system("cls"); 
            
		if (checkEnd2()){	// memeriksa apakah permainan sudah berakhir atau belum
			gameEnd();
		}
    }             
}

/*----------------------------------------Player vs Computer----------------------------------------*/

void fillBoardComp(){
	/*  Modul untuk memulai permainan dengan papan berukuran
		5x5 dan mode permainan Player vs Computer
	*/
	turn=0;	
	char choice;		// variabel untuk membalikkan input pilihan S/O
	int choiceValid;	// variabel untuk memvalidasi apakah inputan pilihan valid
	int row,col;		// variabel untuk membalikkan posisi baris dan kolom untuk di cek oleh computer
	int botValid;		// variabel untuk memvalidasi apakah computer menemukan pola SOS yang dapat dibentuk
	
	strcpy(player2, "Computer");
	
	int loopValid;		
	int checkValid;
	/*	kedua variabel di atas digunakan untuk memvalidasi apakah pola   
	   	SOS yang dapat dibentuk oleh computer sudah habis atau belum
	*/
	
	// perulangan untuk memeriksa apakah permainan sudah berakhir atau belum
	while(!checkEnd()){		
		printf("\n   Giliran %s\n",player1);				
		choiceValid=0;
		drawBoard();
		
		if (turn%2==1){
			botValid=0;
			loopValid=0;
			checkValid=0;
			system("cls");
			
			while(checkValid==0){
			/*	perulangan untuk mencari apakah ada pola SOS 
			  	yang bisa dibentuk oleh computer
			*/	
				checkValid=1;
						
				while(loopValid==0){
					switch(pilihLevel){
					case '1' :searchOSNormal(&choice,&row,&col,&botValid);break;
					case '2' :searchOSHard(&choice,&row,&col,&botValid);break;
					}
											
					if(botValid==1){
						addScore(checkSOS(choice,row,col));
						printf("\n   %s mengisi kotak baris %d, dan kolom %d dengan pilihan %c\n",player2,row,col,choice);		
						drawBoard();
						system("pause");
						system("cls");											
						botValid=0;
						checkValid=0;
						turn++;
					}
					else{
						loopValid=1;
					}		
				}
							
				while(loopValid==1){
					switch(pilihLevel){
					case '1' :searchSSNormal(&choice,&row,&col,&botValid);break;
					case '2' :searchSSHard(&choice,&row,&col,&botValid);break; 
					}	
					
					if(botValid==2){
						addScore(checkSOS(choice,row,col));	
						printf("\n   %s mengisi kotak baris %d, dan kolom %d dengan pilihan %c\n",player2,row,col,choice);	
						drawBoard();
						system("pause");
						system("cls");										
						botValid=0;
						checkValid=0;
						turn++;
					}
					else{
						loopValid=0;						
					}	
				}									
			}
			
			// pemeriksaan apakah game sudah selesai atau belum
			if(checkEnd()){
				system("cls");
			gameEnd();
			return;
			}
						
			/* untuk mengisi kotak secara acak dengan huruf S/O apabila 
			   tidak ada lagi kemungkinan pola SOS yang dapat dibentuk
			*/
			botRandom(&choice,&row,&col);
			addScore(checkSOS(choice,row,col));				
			printf("\n   %s mengisi kotak baris %d, dan kolom %d dengan pilihan %c\n",player2,row,col,choice);	
			drawBoard();
			system("pause");												
			system("cls");	
			drawBoard();
		}
		// pemeriksaan apakah game sudah selesai atau belum
		if(checkEnd()){
			system("cls");
			gameEnd();
			return;
		}
		
		// giliran player menginputkan pilihannya	
		if (turn%2==0){			
			selectChoice(&choice,&choiceValid);
						
			if (choiceValid==1){
				selectBox(choice,&row,&col);
				addScore(checkSOS(choice,row,col));				
			}	
		}		
		turn++;	
		system("cls");
		
		// pemeriksaan apakah game sudah selesai atau belum
		if(checkEnd()){
			system("cls");
			gameEnd();
			return;
		}			
	}
}

void fillBoardComp2(){
	/*  Modul untuk memulai permainan dengan papan berukuran
		7x7 dan mode permainan Player vs Computer
	*/
	turn=0;
	char choice;		// variabel untuk membalikkan input pilihan S/O
	int choiceValid;	// variabel untuk memvalidasi apakah inputan pilihan valid	
	int row,col;		// variabel untuk membalikkan posisi baris dan kolom untuk di cek oleh computer											
	int botValid;		// variabel untuk memvalidasi apakah computer menemukan pola SOS yang dapat dibentuk
	
	strcpy(player2, "Computer");
	
	int loopValid;
	int checkValid;
	/* kedua variabel di atas digunakan untuk memvalidasi apakah pola   
	   SOS yang dapat dibentuk oleh computer sudah habis atau belum
	*/
	
	// perulangan untuk memeriksa apakah permainan sudah berakhir atau belum
	while(!checkEnd2()){		
		printf("\n   Giliran %s\n",player1);						
		choiceValid=0;
		drawBoard2();		
		
		if (turn%2==1){
			botValid=0;
			loopValid=0;
			checkValid=0;
			system("cls");
			
			while(checkValid==0){
			/*perulangan untuk mencari apakah ada pola SOS 
			  yang bisa dibentuk oleh computer
			*/
				checkValid=1;
						
				while(loopValid==0){
					switch(pilihLevel){
					case '1' :searchOS2Normal(&choice,&row,&col,&botValid);break;
					case '2' :searchOS2Hard(&choice,&row,&col,&botValid);break;
					}	
					
					if(botValid==1){
						addScore(checkSOS2(choice,row,col));
						printf("\n   %s mengisi kotak baris %d, dan kolom %d dengan pilihan %c\n",player2,row,col,choice);		
						drawBoard2();
						system("pause");
						system("cls");											
						botValid=0;
						checkValid=0;
						turn++;
					}
					else{
						loopValid=1;
					}		
				}
							
				while(loopValid==1){
					switch(pilihLevel){
					case '1' :searchSS2Normal(&choice,&row,&col,&botValid);break;
					case '2' :searchSS2Hard(&choice,&row,&col,&botValid);break;
					}
						
					if(botValid==2){
						addScore(checkSOS2(choice,row,col));
						printf("\n   %s mengisi kotak baris %d, dan kolom %d dengan pilihan %c\n",player2,row,col,choice);		
						drawBoard2();
						system("pause");
						system("cls");					
						botValid=0;
						checkValid=0;
						turn++;
					}
					else{
						loopValid=0;						
					}	
				}				
			}
			// pemeriksaan apakah game sudah selesai atau belum
			if(checkEnd2()){
				system("cls");
				gameEnd();
				return;
			}
								
			/* untuk mengisi kotak secara acak dengan huruf O apabila 
			   tidak ada lagi kemungkinan pola SOS yang dapat dibentuk
			*/
			botRandom2(&choice,&row,&col);
			addScore(checkSOS2(choice,row,col));	
			printf("\n   %s mengisi kotak baris %d, dan kolom %d dengan pilihan %c\n",player2,row,col,choice);	
			drawBoard2();
			system("pause");															
			system("cls");
			drawBoard2();
		}
		// pemeriksaan apakah game sudah selesai atau belum
		if(checkEnd2()){
			system("cls");
			gameEnd();
			return;
		}
		
		// giliran player menginputkan pilihannya
		if (turn%2==0){
			selectChoice(&choice,&choiceValid);
			
			if (choiceValid==1 || turn%2==0){
				selectBox2(choice,&row,&col);
				addScore(checkSOS2(choice,row,col));				
			}	
		}	
		turn++;	
		system("cls");
		
		// pemeriksaan apakah game sudah selesai atau belum
		if(checkEnd2()){
			system("cls");
			gameEnd();
			return;
		}			
	}
}

void botRandom(char *xchoice, int *xrow, int *xcol){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 5x5 dengan 
		huruf S secara acak apabila sudah tidak ada lagi pola SOS yang bisa dibentuk 
	*/
	if(*xchoice=='S'){
		for(int row=1; row<6; row++){
	        	
	        for(int col=1; col<6; col++){
	    				
	            if(Array1[row][col]=='S'){
	
	                if((Array1[row][col+1]!='S') && (Array1[row][col+1] != 'O') && (Array1[row][col+1] != 'x')){
	            		Array1[row][col+1]='S'; *xchoice='S';*xrow=row;*xcol=col+1;return;
	                }
	                       
	                if((Array1[row+1][col+1] != 'S') && (Array1[row+1][col+1] != 'O') && (Array1[row+1][col+1] != 'x')){
	                    Array1[row+1][col+1]='S';*xchoice='S';*xrow=row+1;*xcol=col+1; return;
					}
	                   		
					if((Array1[row+1][col] != 'S') && (Array1[row+1][col] != 'O') && (Array1[row+1][col] != 'x')){
	                    Array1[row+1][col]='S'; *xchoice='S';*xrow=row+1;*xcol=col;return;
	                }
	                        
	                if((Array1[row-1][col] != 'S') && (Array1[row-1][col] !='O') && (Array1[row-1][col] != 'x')){
	                    Array1[row-1][col]='S'; *xchoice='S';*xrow=row-1;*xcol=col;return;
	                }
	                        
	                if((Array1[row-1][col-1] != 'S') && (Array1[row-1][col-1] != 'O')&& (Array1[row-1][col-1] != 'x') ){
	                    Array1[row-1][col-1]='S'; *xchoice='S';*xrow=row-1;*xcol=col-1;return;
	                }
	                        
	                if((Array1[row+1][col-1] != 'S') && (Array1[row+1][col-1] != 'O') && (Array1[row+1][col-1] != 'x') ){
	                    Array1[row+1][col-1]='S';*xchoice='S';*xrow=row+1;*xcol=col-1; return;
	                }
	                        
	                if((Array1[row-1][col+1] != 'S') && (Array1[row-1][col+1] != 'O') && (Array1[row-1][col+1] != 'x')){
	                    Array1[row-1][col+1]='S'; *xchoice='S';*xrow=row-1;*xcol=col+1;return;
	                }
	                        
	                if((Array1[row][col-1] != 'S') && (Array1[row][col-1] != 'O') && (Array1[row][col-1] != 'x')){
	                    Array1[row][col-1]='S'; *xchoice='S';*xrow=row;*xcol=col-1;return;
	                }
	        	}           	
	        }
	    }
		for (int row=1; row<6; row++){
    	
	        for(int col=1; col<6; col++){
	    				
	            if(Array1[row][col]=='O'){
	
	                if((Array1[row][col+1]!='S') && (Array1[row][col+1] != 'O') && (Array1[row][col+1] != 'x')){
	                    Array1[row][col+1]='O';*xchoice='O';*xrow=row;*xcol=col+1; return;
	                }
	                
	            	if((Array1[row+1][col+1] != 'S') && (Array1[row+1][col+1] != 'O') && (Array1[row+1][col+1] != 'x')){
	                    Array1[row+1][col+1]='O';*xchoice='O';*xrow=row+1;*xcol=col+1; return;
	                }
	                
	                if((Array1[row+1][col] != 'S') && (Array1[row+1][col] != 'O') && (Array1[row+1][col] != 'x')){
	                    Array1[row+1][col]='O'; *xchoice='O';*xrow=row+1;*xcol=col;return;
	                }
	                
	                if((Array1[row-1][col] != 'S') && (Array1[row-1][col] !='O') && (Array1[row-1][col] != 'x')){
	                    Array1[row-1][col]='O'; *xchoice='O';*xrow=row-1;*xcol=col;return;
	                }
	                
	            	if((Array1[row-1][col-1] != 'S') && (Array1[row-1][col-1] != 'O')&& (Array1[row-1][col-1] != 'x') ){
	                    Array1[row-1][col-1]='O'; *xchoice='O';*xrow=row-1;*xcol=col-1;return;
	                }
	                
	                if((Array1[row+1][col-1] != 'S') && (Array1[row+1][col-1] != 'O') && (Array1[row+1][col-1] != 'x') ){
	                    Array1[row+1][col-1]='O'; *xchoice='O';*xrow=row+1;*xcol=col-1;return;
	                }
	                
	                if((Array1[row-1][col+1] != 'S') && (Array1[row-1][col+1] != 'O') && (Array1[row-1][col+1] != 'x')){
	                    Array1[row-1][col+1]='O'; *xchoice='O';*xrow=row-1;*xcol=col+1;return;
	                }
	                
	                if((Array1[row][col-1] != 'S') && (Array1[row][col-1] != 'O') && (Array1[row][col-1] != 'x')){
	                    Array1[row][col-1]='O';*xchoice='O';*xrow=row;*xcol=col-1; return;
	                }
	        	}
	        }
	    }	
	}
	else{
		for (int row=1; row<6; row++){
    	
	        for(int col=1; col<6; col++){
	    				
	            if(Array1[row][col]=='O'){
	
	                if((Array1[row][col+1]!='S') && (Array1[row][col+1] != 'O') && (Array1[row][col+1] != 'x')){
	                    Array1[row][col+1]='O';*xchoice='O';*xrow=row;*xcol=col+1; return;
	                }
	                
	            	if((Array1[row+1][col+1] != 'S') && (Array1[row+1][col+1] != 'O') && (Array1[row+1][col+1] != 'x')){
	                    Array1[row+1][col+1]='O';*xchoice='O';*xrow=row+1;*xcol=col+1; return;
	                }
	                
	                if((Array1[row+1][col] != 'S') && (Array1[row+1][col] != 'O') && (Array1[row+1][col] != 'x')){
	                    Array1[row+1][col]='O'; *xchoice='O';*xrow=row+1;*xcol=col;return;
	                }
	                
	                if((Array1[row-1][col] != 'S') && (Array1[row-1][col] !='O') && (Array1[row-1][col] != 'x')){
	                    Array1[row-1][col]='O'; *xchoice='O';*xrow=row-1;*xcol=col;return;
	                }
	                
	            	if((Array1[row-1][col-1] != 'S') && (Array1[row-1][col-1] != 'O')&& (Array1[row-1][col-1] != 'x') ){
	                    Array1[row-1][col-1]='O'; *xchoice='O';*xrow=row-1;*xcol=col-1;return;
	                }
	                
	                if((Array1[row+1][col-1] != 'S') && (Array1[row+1][col-1] != 'O') && (Array1[row+1][col-1] != 'x') ){
	                    Array1[row+1][col-1]='O'; *xchoice='O';*xrow=row+1;*xcol=col-1;return;
	                }
	                
	                if((Array1[row-1][col+1] != 'S') && (Array1[row-1][col+1] != 'O') && (Array1[row-1][col+1] != 'x')){
	                    Array1[row-1][col+1]='O'; *xchoice='O';*xrow=row-1;*xcol=col+1;return;
	                }
	                
	                if((Array1[row][col-1] != 'S') && (Array1[row][col-1] != 'O') && (Array1[row][col-1] != 'x')){
	                    Array1[row][col-1]='O';*xchoice='O';*xrow=row;*xcol=col-1; return;
	                }
	        	}
	        }
	    }
	    for(int row=1; row<6; row++){
	        	
	        for(int col=1; col<6; col++){
	    				
	            if(Array1[row][col]=='S'){
	
	                if((Array1[row][col+1]!='S') && (Array1[row][col+1] != 'O') && (Array1[row][col+1] != 'x')){
	            		Array1[row][col+1]='S'; *xchoice='S';*xrow=row;*xcol=col+1;return;
	                }
	                       
	                if((Array1[row+1][col+1] != 'S') && (Array1[row+1][col+1] != 'O') && (Array1[row+1][col+1] != 'x')){
	                    Array1[row+1][col+1]='S';*xchoice='S';*xrow=row+1;*xcol=col+1; return;
					}
	                   		
					if((Array1[row+1][col] != 'S') && (Array1[row+1][col] != 'O') && (Array1[row+1][col] != 'x')){
	                    Array1[row+1][col]='S'; *xchoice='S';*xrow=row+1;*xcol=col;return;
	                }
	                        
	                if((Array1[row-1][col] != 'S') && (Array1[row-1][col] !='O') && (Array1[row-1][col] != 'x')){
	                    Array1[row-1][col]='S'; *xchoice='S';*xrow=row-1;*xcol=col;return;
	                }
	                        
	                if((Array1[row-1][col-1] != 'S') && (Array1[row-1][col-1] != 'O')&& (Array1[row-1][col-1] != 'x') ){
	                    Array1[row-1][col-1]='S'; *xchoice='S';*xrow=row-1;*xcol=col-1;return;
	                }
	                        
	                if((Array1[row+1][col-1] != 'S') && (Array1[row+1][col-1] != 'O') && (Array1[row+1][col-1] != 'x') ){
	                    Array1[row+1][col-1]='S';*xchoice='S';*xrow=row+1;*xcol=col-1; return;
	                }
	                        
	                if((Array1[row-1][col+1] != 'S') && (Array1[row-1][col+1] != 'O') && (Array1[row-1][col+1] != 'x')){
	                    Array1[row-1][col+1]='S'; *xchoice='S';*xrow=row-1;*xcol=col+1;return;
	                }
	                        
	                if((Array1[row][col-1] != 'S') && (Array1[row][col-1] != 'O') && (Array1[row][col-1] != 'x')){
	                    Array1[row][col-1]='S'; *xchoice='S';*xrow=row;*xcol=col-1;return;
	                }
	        	}           	
	        }
	    }
	}
	    
}

void botRandom2(char *xchoice, int *xrow, int *xcol){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 7x7 dengan 
		huruf S secara acak apabila sudah tidak ada lagi pola SOS yang bisa dibentuk 
	*/
	
	if(*xchoice=='S'){
		for (int row=1; row<8; row++){
    	
	        for(int col=1; col<8; col++){
	    				
	            if(Array2[row][col]=='S'){
	
	                if((Array2[row][col+1]!='S') && (Array2[row][col+1] != 'O') && (Array2[row][col+1] != 'x')){
	                    Array2[row][col+1]='S'; *xchoice='S';*xrow=row;*xcol=col+1;return;
	        		}
	                        
	                if((Array2[row+1][col+1] != 'S') && (Array2[row+1][col+1] != 'O') && (Array2[row+1][col+1] != 'x')){
	                    Array2[row+1][col+1]='S';*xchoice='S';*xrow=row+1;*xcol=col+1; return;
	                }
	                
	                if((Array2[row+1][col] != 'S') && (Array2[row+1][col] != 'O') && (Array2[row+1][col] != 'x')){
	                    Array2[row+1][col]='S'; *xchoice='S';*xrow=row+1;*xcol=col;return;
	                }
	                
	                if((Array2[row-1][col] != 'S') && (Array2[row-1][col] !='O') && (Array2[row-1][col] != 'x')){
	                    Array2[row-1][col]='S'; *xchoice='S';*xrow=row-1;*xcol=col;return;
	                }
	                
	                if((Array2[row-1][col-1] != 'S') && (Array2[row-1][col-1] != 'O')&& (Array2[row-1][col-1] != 'x') ){
	                    Array2[row-1][col-1]='S'; *xchoice='S';*xrow=row-1;*xcol=col-1;return;
	                }
	                        
					if((Array2[row+1][col-1] != 'S') && (Array2[row+1][col-1] != 'O') && (Array2[row+1][col-1] != 'x') ){
	                    Array2[row+1][col-1]='S';*xchoice='S';*xrow=row+1;*xcol=col-1; return;
	                }
	                
	                if((Array2[row-1][col+1] != 'S') && (Array2[row-1][col+1] != 'O') && (Array2[row-1][col+1] != 'x')){
	                    Array2[row-1][col+1]='S'; *xchoice='S';*xrow=row-1;*xcol=col+1;return;
	                }
	                
	                if((Array2[row][col-1] != 'S') && (Array2[row][col-1] != 'O') && (Array2[row][col-1] != 'x')){
	                    Array2[row][col-1]='S'; *xchoice='S';*xrow=row;*xcol=col-1;return;
	                }	            	                
				}
			}
		}
		for (int row=1; row<8; row++){
    	
	        for(int col=1; col<8; col++){
	    				
	            if(Array2[row][col]=='O'){
	
	                if((Array2[row][col+1]!='S') && (Array2[row][col+1] != 'O') && (Array2[row][col+1] != 'x')){
	                    Array2[row][col+1]='O';*xchoice='O';*xrow=row;*xcol=col+1; return;
	                }
	                
	                if((Array2[row+1][col+1] != 'S') && (Array2[row+1][col+1] != 'O') && (Array2[row+1][col+1] != 'x')){
	                    Array2[row+1][col+1]='O';*xchoice='O';*xrow=row+1;*xcol=col+1; return;
	                }
	                
	                if((Array2[row+1][col] != 'S') && (Array2[row+1][col] != 'O') && (Array2[row+1][col] != 'x')){
	                    Array2[row+1][col]='O'; *xchoice='O';*xrow=row+1;*xcol=col;return;
	                }
	                        
	                if ((Array2[row-1][col] != 'S') && (Array2[row-1][col] !='O') && (Array2[row-1][col] != 'x')){
	                    Array2[row-1][col]='O'; *xchoice='O';*xrow=row-1;*xcol=col;return;
	        		}
	                        
	                if((Array2[row-1][col-1] != 'S') && (Array2[row-1][col-1] != 'O')&& (Array2[row-1][col-1] != 'x') ){
	                    Array2[row-1][col-1]='O'; *xchoice='O';*xrow=row-1;*xcol=col-1;return;
	                }
	                        
	                if((Array2[row+1][col-1] != 'S') && (Array2[row+1][col-1] != 'O') && (Array2[row+1][col-1] != 'x') ){
	                    Array2[row+1][col-1]='O'; *xchoice='O';*xrow=row+1;*xcol=col-1;return;
	                }
	                        
	                if((Array2[row-1][col+1] != 'S') && (Array2[row-1][col+1] != 'O') && (Array2[row-1][col+1] != 'x')){
	                    Array2[row-1][col+1]='O'; *xchoice='O';*xrow=row-1;*xcol=col+1;return;
	                }
	                        
	                if((Array2[row][col-1] != 'S') && (Array2[row][col-1] != 'O') && (Array2[row][col-1] != 'x')){
	                    Array2[row][col-1]='O';*xchoice='O';*xrow=row;*xcol=col-1; return;
	                }
	            }
	        }
	    }
	}
	else{
		for (int row=1; row<8; row++){
    	
	        for(int col=1; col<8; col++){
	    				
	            if(Array2[row][col]=='O'){
	
	                if((Array2[row][col+1]!='S') && (Array2[row][col+1] != 'O') && (Array2[row][col+1] != 'x')){
	                    Array2[row][col+1]='O';*xchoice='O';*xrow=row;*xcol=col+1; return;
	                }
	                
	                if((Array2[row+1][col+1] != 'S') && (Array2[row+1][col+1] != 'O') && (Array2[row+1][col+1] != 'x')){
	                    Array2[row+1][col+1]='O';*xchoice='O';*xrow=row+1;*xcol=col+1; return;
	                }
	                
	                if((Array2[row+1][col] != 'S') && (Array2[row+1][col] != 'O') && (Array2[row+1][col] != 'x')){
	                    Array2[row+1][col]='O'; *xchoice='O';*xrow=row+1;*xcol=col;return;
	                }
	                        
	                if ((Array2[row-1][col] != 'S') && (Array2[row-1][col] !='O') && (Array2[row-1][col] != 'x')){
	                    Array2[row-1][col]='O'; *xchoice='O';*xrow=row-1;*xcol=col;return;
	        		}
	                        
	                if((Array2[row-1][col-1] != 'S') && (Array2[row-1][col-1] != 'O')&& (Array2[row-1][col-1] != 'x') ){
	                    Array2[row-1][col-1]='O'; *xchoice='O';*xrow=row-1;*xcol=col-1;return;
	                }
	                        
	                if((Array2[row+1][col-1] != 'S') && (Array2[row+1][col-1] != 'O') && (Array2[row+1][col-1] != 'x') ){
	                    Array2[row+1][col-1]='O'; *xchoice='O';*xrow=row+1;*xcol=col-1;return;
	                }
	                        
	                if((Array2[row-1][col+1] != 'S') && (Array2[row-1][col+1] != 'O') && (Array2[row-1][col+1] != 'x')){
	                    Array2[row-1][col+1]='O'; *xchoice='O';*xrow=row-1;*xcol=col+1;return;
	                }
	                        
	                if((Array2[row][col-1] != 'S') && (Array2[row][col-1] != 'O') && (Array2[row][col-1] != 'x')){
	                    Array2[row][col-1]='O';*xchoice='O';*xrow=row;*xcol=col-1; return;
	                }
	            }
	        }
	    }
		for (int row=1; row<8; row++){
    	
	        for(int col=1; col<8; col++){
	    				
	            if(Array2[row][col]=='S'){
	
	                if((Array2[row][col+1]!='S') && (Array2[row][col+1] != 'O') && (Array2[row][col+1] != 'x')){
	                    Array2[row][col+1]='S'; *xchoice='S';*xrow=row;*xcol=col+1;return;
	        		}
	                        
	                if((Array2[row+1][col+1] != 'S') && (Array2[row+1][col+1] != 'O') && (Array2[row+1][col+1] != 'x')){
	                    Array2[row+1][col+1]='S';*xchoice='S';*xrow=row+1;*xcol=col+1; return;
	                }
	                
	                if((Array2[row+1][col] != 'S') && (Array2[row+1][col] != 'O') && (Array2[row+1][col] != 'x')){
	                    Array2[row+1][col]='S'; *xchoice='S';*xrow=row+1;*xcol=col;return;
	                }
	                
	                if((Array2[row-1][col] != 'S') && (Array2[row-1][col] !='O') && (Array2[row-1][col] != 'x')){
	                    Array2[row-1][col]='S'; *xchoice='S';*xrow=row-1;*xcol=col;return;
	                }
	                
	                if((Array2[row-1][col-1] != 'S') && (Array2[row-1][col-1] != 'O')&& (Array2[row-1][col-1] != 'x') ){
	                    Array2[row-1][col-1]='S'; *xchoice='S';*xrow=row-1;*xcol=col-1;return;
	                }
	                        
					if((Array2[row+1][col-1] != 'S') && (Array2[row+1][col-1] != 'O') && (Array2[row+1][col-1] != 'x') ){
	                    Array2[row+1][col-1]='S';*xchoice='S';*xrow=row+1;*xcol=col-1; return;
	                }
	                
	                if((Array2[row-1][col+1] != 'S') && (Array2[row-1][col+1] != 'O') && (Array2[row-1][col+1] != 'x')){
	                    Array2[row-1][col+1]='S'; *xchoice='S';*xrow=row-1;*xcol=col+1;return;
	                }
	                
	                if((Array2[row][col-1] != 'S') && (Array2[row][col-1] != 'O') && (Array2[row][col-1] != 'x')){
	                    Array2[row][col-1]='S'; *xchoice='S';*xrow=row;*xcol=col-1;return;
	                }	            	                
				}
			}
		}	                
	}                               
}


void searchOSHard(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 5x5 dengan huruf S
		apabila ada pola SO ataupun OS yang tersedia secara vertikal, horizontal, dan diagonal
	*/
	for (int row=1; row<6; row++){
		
        for(int col=1; col<6; col++){
        	
            if(Array1[row][col]!='O' && Array1[row][col]!='S'){
            	
                if((Array1[row][col+1]=='O') && (Array1[row][col+2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
               	if((Array1[row][col-1]=='O') && (Array1[row][col-2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row+1][col] == 'O') && (Array1[row+2][col] =='S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row-1][col] == 'O') && (Array1[row-2][col] =='S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row+1][col+1] == 'O') && (Array1[row+2][col+2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row-1][col-1] == 'O') && (Array1[row-2][col-2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row+1][col-1] == 'O') && (Array1[row+2][col-2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row-1][col+1] == 'O') && (Array1[row-2][col+2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
            }
        }
    }
    
    if(*xbotValid==1){
    	*xbotValid=1;
	}
	else{
		*xbotValid=0;
	}
    
	return;
}



void searchOSNormal(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 5x5 dengan huruf S
		apabila ada pola SO ataupun OS yang tersedia secara vertikal dan horizontal
	*/
    for (int row=1; row<6; row++){
    	
        for(int col=1; col<6; col++){
        	
           if(Array1[row][col]!='O' && Array1[row][col]!='S'){
           	
                if((Array1[row][col+1]=='O') && (Array1[row][col+2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row][col-1]=='O') && (Array1[row][col-2] == 'S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row+1][col] == 'O') && (Array1[row+2][col] =='S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array1[row-1][col] == 'O') && (Array1[row-2][col] =='S')){
                    Array1[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
        	}
        }
    }
    
    if(*xbotValid==1){
    	*xbotValid=1;
	}
	else{
		*xbotValid=0;
	}
    
	return;
}

void searchOS2Hard(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 7x7 dengan huruf S
		apabila ada pola SO ataupun OS yang tersedia secara vertikal, horizontal, dan diagonal
	*/
    for (int row=1; row<8; row++){
    	
        for(int col=1; col<8; col++){
        	
           if(Array2[row][col]!='O' && Array2[row][col]!='S'){
           	
                if((Array2[row][col+1]=='O') && (Array2[row][col+2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
               	if((Array2[row][col-1]=='O') && (Array2[row][col-2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row+1][col] == 'O') && (Array2[row+2][col] =='S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row-1][col] == 'O') && (Array2[row-2][col] =='S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row+1][col+1] == 'O') && (Array2[row+2][col+2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row-1][col-1] == 'O') && (Array2[row-2][col-2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row+1][col-1] == 'O') && (Array2[row+2][col-2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row-1][col+1] == 'O') && (Array2[row-2][col+2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
        	}
        }
    }
    
    if(*xbotValid==1){
    	*xbotValid=1;
	}
	else{
		*xbotValid=0;
	}
    
	return;
}


void searchOS2Normal(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 7x7 dengan huruf S
		apabila ada pola SO ataupun OS yang tersedia secara vertikal dan horizontal
	*/
    for (int row=1; row<8; row++){
    	
        for(int col=1; col<8; col++){
        	
           if(Array2[row][col]!='O' && Array2[row][col]!='S'){
           	
            	if((Array2[row][col+1]=='O') && (Array2[row][col+2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
            	if((Array2[row][col-1]=='O') && (Array2[row][col-2] == 'S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
        		if((Array2[row+1][col] == 'O') && (Array2[row+2][col] =='S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
                
                if((Array2[row-1][col] == 'O') && (Array2[row-2][col] =='S')){
                    Array2[row][col]='S';*xchoice='S';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=1;
                }
          	}
        }
    }
    
    if(*xbotValid==1){
    	*xbotValid=1;
	}
	else{
		*xbotValid=0;
	}
    
	return;
}

void searchSSHard(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 5x5 dengan huruf O
		apabila ada pola SS yang tersedia secara vertikal, horizontal, dan diagonal
	*/
    for (int row=1; row<6; row++){
    	
        for(int col=1; col<6; col++){
        	
           if(Array1[row][col]!='O' && Array1[row][col]!='S'){
           	
                if((Array1[row][col+1]=='S') && (Array1[row][col-1] == 'S')){
                    Array1[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if((Array1[row+1][col] == 'S') && (Array1[row-1][col] =='S')){
                    Array1[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if((Array1[row+1][col+1] == 'S') && (Array1[row-1][col-1] == 'S')){
                    Array1[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if((Array1[row+1][col-1] == 'S') && (Array1[row-1][col+1] == 'S')){
                    Array1[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
          	}
        }
    }
    
    if(*xbotValid==2){
    	*xbotValid=2;
	}
	else{
		*xbotValid=0;
	}
	
	return;
}


void searchSSNormal(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 5x5 dengan huruf O
		apabila ada pola SS yang tersedia secara vertikal dan diagonal
	*/
    for (int row=1; row<6; row++){
    	
        for(int col=1; col<6; col++){
        	
           if(Array1[row][col]!='O' && Array1[row][col]!='S'){
           	
                if((Array1[row][col+1]=='S') && (Array1[row][col-1] == 'S')){
                    Array1[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if((Array1[row+1][col] == 'S') && (Array1[row-1][col] =='S')){
                    Array1[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
          	}
        }
    }
    
    if(*xbotValid==2){
    	*xbotValid=2;
	}
	else{
		*xbotValid=0;
	}
	
	return;
}

void searchSS2Hard(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 7x7 dengan huruf O
		apabila ada pola SS yang tersedia secara vertikal, horizontal, dan diagonal
	*/
    for (int row=1; row<8; row++){
    	
        for(int col=1; col<8; col++){
        	
           if(Array2[row][col]!='O' && Array2[row][col]!='S'){
           	
                if((Array2[row][col+1]=='S') && (Array2[row][col-1] == 'S')){
                    Array2[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if ((Array2[row+1][col] == 'S') && (Array2[row-1][col] =='S')){
                    Array2[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if((Array2[row+1][col+1] == 'S') && (Array2[row-1][col-1] == 'S')){
                    Array2[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if((Array2[row+1][col-1] == 'S') && (Array2[row-1][col+1] == 'S')){
                    Array2[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
        	}
        }
    }
    
    if(*xbotValid==2){
    	*xbotValid=2;
	}
	else{
		*xbotValid=0;
	}
	
	return;
}


void searchSS2Normal(char *xchoice, int *xrow, int *xcol, int *xbotValid){
	/*	Modul yang digunakan oleh computer untuk mengisi papan berukuran 7x7 dengan huruf O
		apabila ada pola SS yang tersedia secara vertikal dan diagonal
	*/
    for (int row=1; row<8; row++){
    	
        for(int col=1; col<8; col++){
        	
           if(Array2[row][col]!='O' && Array2[row][col]!='S'){
           	
                if((Array2[row][col+1]=='S') && (Array2[row][col-1] == 'S')){
                    Array2[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
                
                if ((Array2[row+1][col] == 'S') && (Array2[row-1][col] =='S')){
                    Array2[row][col]='O';*xchoice='O';*xrow=row;*xcol=col;row=7;col=7;*xbotValid=2;
                }
        	}
        }
    }
    
    if(*xbotValid==2){
    	*xbotValid=2;
	}
	else{
		*xbotValid=0;
	}
	
	return;
}

void selectBox(int xchoice, int *xrow, int *xcol){
	/*	Modul yang digunakan oleh player untuk menginputkan pilihan baris dan kolom
		pada kotak yang terdapat pada papan berukuran 5x5 oleh pilihan 'S' atau 'O' 
	*/
    int row,col;
    char rowCharacter,colCharacter;
    double inputTime;
    int rowValid=1;
    int colValid=1;
    
	printf("\n   Masukkan lokasi baris : "); scanf(" %s",&rowCharacter);
	switch(rowCharacter){
	    case '1' : row = 1;break;
	    case '2' : row = 2;break;
	    case '3' : row = 3;break;
	    case '4' : row = 4;break;
	    case '5' : row = 5;break;
	    default : printf("\n   Silahkan masukan baris yang sesuai!");*xrow=0;*xcol=0;rowValid=0;turn=turn-1;getch();break;
	}	

    if (rowValid==1){
    	printf("\n   Masukkan lokasi kolom : "); scanf(" %s",&colCharacter);
    	switch(colCharacter){
	    case '1' : col = 1;break;
	    case '2' : col = 2;break;
	    case '3' : col = 3;break;
	    case '4' : col = 4;break;
	    case '5' : col = 5;break;
	    default : printf("\n   Silahkan masukan kolom yang sesuai!");*xrow=0;*xcol=0;colValid=0;turn=turn-1;getch();break;
		}
	}
    
    timer = endTime() - timer;
	inputTime = ((double)timer)/CLOCKS_PER_SEC;
    
    if(pilihOpponent=='1'){
	    if(inputTime<=10){
			if (rowValid==1&&colValid==1){
		    	if(Array1[row][col]==79||Array1[row][col]==83){
		        boxUnavailable(&*xrow,&*xcol);
		   		}
		    	else{
		        Array1[row][col]=xchoice;*xrow=row;*xcol=col;
		  		}  	
			}			
		}
		else{
			printf("\n   Waktu penginputan habis, kamu kehilangan giliran!\n\n");
			*xrow=0;*xcol=0;
			system("pause");
		}		
	}
	else{
		if (rowValid==1&&colValid==1){
		    	if(Array1[row][col]==79||Array1[row][col]==83){
		        boxUnavailable();
		   		}
		    	else{
		        Array1[row][col]=xchoice;*xrow=row;*xcol=col;
		  		}  	
		}
	}
	
    
	return;
    
}

void selectBox2(int xchoice, int *xrow, int *xcol){
	/*	Modul yang digunakan oleh player untuk menginputkan pilihan baris dan kolom
		pada kotak yang terdapat pada papan berukuran 7x7 oleh pilihan 'S' atau 'O' 
	*/
    int row,col;
    char rowCharacter,colCharacter;
    double inputTime;
    int rowValid=1;
    int colValid=1;
    
	printf("\n   Masukkan lokasi baris : "); scanf(" %s",&rowCharacter);
	switch(rowCharacter){
	    case '1' : row = 1;break;
	    case '2' : row = 2;break;
	    case '3' : row = 3;break;
	    case '4' : row = 4;break;
	    case '5' : row = 5;break;
	    case '6' : row = 6;break;
	    case '7' : row = 7;break;
	    default : printf("\n   Silahkan masukan baris yang sesuai!");*xrow=0;*xcol=0;rowValid=0;turn=turn-1;getch();break;
	}	

    if (rowValid==1){
    	printf("\n   Masukkan lokasi kolom : "); scanf(" %s",&colCharacter);
    	switch(colCharacter){
	    case '1' : col = 1;break;
	    case '2' : col = 2;break;
	    case '3' : col = 3;break;
	    case '4' : col = 4;break;
	    case '5' : col = 5;break;
	    case '6' : col = 6;break;
	    case '7' : col = 7;break;
	    default : printf("\n   Silahkan masukan kolom yang sesuai!");*xrow=0;*xcol=0;colValid=0;turn=turn-1;getch();break;
		}
	}
    
    timer = endTime() - timer;
	inputTime =((double)timer)/CLOCKS_PER_SEC;
    
    if(pilihOpponent=='1'){
	    if(inputTime<=10){
			if (rowValid==1&&colValid==1){
		    	if(Array2[row][col]==79||Array2[row][col]==83){
		        boxUnavailable(&*xrow,&*xcol);
		   		}
		    	else{
		        Array2[row][col]=xchoice;*xrow=row;*xcol=col;
		  		}  	
			}			
		}
		else{
			printf("\n   Waktu penginputan habis, kamu kehilangan giliran!\n");
			*xrow=0;*xcol=0;
			system("pause");
		}		
	}
	else{
		if (rowValid==1&&colValid==1){
		    	if(Array2[row][col]==79||Array2[row][col]==83){
		        boxUnavailable();
		   		}
		    	else{
		        Array2[row][col]=xchoice;*xrow=row;*xcol=col;
		  		}  	
		}
	}

	return;    
}


void boxUnavailable(int *xrow, int *xcol){
	/*	Modul yang digunakan untuk memeriksa apakah kotak yang dipilih
		oleh player sudah terisi atau belum
	*/
	printf("Kotak sudah terisi, silahkan pilih kotak yang lain!");
	turn=turn-1;
	*xrow=0;
	*xcol=0;	
	getch();
}

int checkSOS(int choice,int row, int col){
	/*	Modul yang digunakan untuk memeriksa banyak pola SOS pada papan berukuran 5x5 
		yang terbentuk setelah player ataupun computer menginputkan pilihannya
	*/
	int sos=0;
	
	if(choice == 'S'){
		if ((Array1[row][col-2] == 'S') && (Array1[row][col-1] == 'O')){
			sos++;
		}
		if ((Array1[row][col+1]== 'O') && (Array1[row][col+2] == 'S')){
			sos++;
		}	
		if((Array1[row+1][col] == 'O') && (Array1[row+2][col] == 'S')){
			sos++;
		}
		if((Array1[row-1][col] == 'O') && (Array1[row-2][col] == 'S')){
			sos++;
		}
		if((Array1[row+1][col+1] == 'O') && (Array1[row+2][col+2] == 'S')){
			sos++;
		}
		if((Array1[row-1][col-1] == 'O') && (Array1[row-2][col-2] == 'S')){
			sos++;
		}
		if((Array1[row+1][col-1] == 'O') && (Array1[row+2][col-2] == 'S')){
			sos++;
		}
		if((Array1[row-1][col+1] == 'O') && (Array1[row-2][col+2] == 'S')){
			sos++;
		}
	}
	else if(choice == 'O'){
		if((Array1[row+1][col] == 'S') && (Array1[row-1][col] == 'S')){
			sos++;
		}
		if((Array1[row][col+1] == 'S') && (Array1[row][col-1] == 'S')){
			sos++;
		}
		if((Array1[row+1][col+1] == 'S') && (Array1[row-1][col-1] == 'S')){
			sos++;
		}
		if((Array1[row+1][col-1] == 'S') && (Array1[row-1][col+1] == 'S')){
			sos++;
		}
  	}
  	return sos;
  	
}

int checkSOS2(int choice,int row, int col){
	/*	Modul yang digunakan untuk memeriksa banyak pola SOS pada papan berukuran 7x7 
		yang terbentuk setelah player ataupun computer menginputkan pilihannya
	*/
	int sos=0;
	
	if(choice == 'S'){
		if ((Array2[row][col-2] == 'S') && (Array2[row][col-1] == 'O')){
			sos++;
		}
		if ((Array2[row][col+1]== 'O') && (Array2[row][col+2] == 'S')){
			sos++;
		}	
		if((Array2[row+1][col] == 'O') && (Array2[row+2][col] == 'S')){
			sos++;
		}
		if((Array2[row-1][col] == 'O') && (Array2[row-2][col] == 'S')){
			sos++;
		}
		if((Array2[row+1][col+1] == 'O') && (Array2[row+2][col+2] == 'S')){
			sos++;
		}
		if((Array2[row-1][col-1] == 'O') && (Array2[row-2][col-2] == 'S')){
			sos++;
		}
		if((Array2[row+1][col-1] == 'O') && (Array2[row+2][col-2] == 'S')){
			sos++;
		}
		if((Array2[row-1][col+1] == 'O') && (Array2[row-2][col+2] == 'S')){
			sos++;
		}
	}
	else if(choice == 'O'){
		if((Array2[row+1][col] == 'S') && (Array2[row-1][col] == 'S')){
			sos++;
		}
		if((Array2[row][col+1] == 'S') && (Array2[row][col-1] == 'S')){
			sos++;
		}
		if((Array2[row+1][col+1] == 'S') && (Array2[row-1][col-1] == 'S')){
			sos++;
		}
		if((Array2[row+1][col-1] == 'S') && (Array2[row-1][col+1] == 'S')){
			sos++;
		}
  	}
  	return sos;
}

void addScore(int xsos){	
	/*	Modul yang digunakan untuk menambahkan score kepada player
		sesuai giliran dan banyaknya pola SOS yang terbentuk
	*/
	if(turn%2==0){
		score1 = score1 + xsos;	
	}
	else{
		score2 = score2 + xsos;
	}
	
	if (xsos>0){
		turn = turn-1;
	}

}

int checkEnd(){
	/*	Modul yang digunakan untuk memeriksa apakah semua kotak pada
		papan berukuran 5x5 sudah terisi atau belum
	*/
	int row, col;
	
    for (row=1; row<6; row++){
    	
        for(col=1; col<6; col++){
        	
            if (Array1[row][col] == ' '){
                return 0;
            }
        }
    }

    return 1;
		
}

int checkEnd2(){
	/*	Modul yang digunakan untuk memeriksa apakah semua kotak pada
		papan berukuran 7x7 sudah terisi atau belum
	*/
	int row, col;
	
    for (row=1; row<8; row++){
    	
        for(col=1; col<8; col++){
        	
            if (Array2[row][col] == ' '){
                return 0;
            }
        }
    }

    return 1;	
        
}



void createNickname(){
	/*	Modul untuk menginputkan nickname pemain
		pada mode Player vs Player
	*/
	
	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<8;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
			
	//Batas Bawah
	    gotoxy(41, 13); printf("%c",200);
	    gotoxy(42, 13); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
	
	//Menu Teks
	    gotoxy(46,7); printf("          Input Nickname");
	    gotoxy(46,8); printf("         Player vs Player");
	    gotoxy(46, 11); printf("Nickname Player 1 : ");
		_flushall();
		scanf("%[^\n]%*c", player1);
		gotoxy(46, 12); printf("Nickname Player 2 : ");
		_flushall();
		scanf("%[^\n]%*c", player2);
		system("cls");	
}

void createNicknameComp(){
	/*	Modul untuk menginputkan nickname pemain
		pada mode Player vs Computer
	*/
	
	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<7;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
			
	//Batas Bawah
	    gotoxy(41, 12); printf("%c",200);
	    gotoxy(42, 12); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
	
	//Menu Teks
	    gotoxy(46,7); printf("          Input Nickname");
	    gotoxy(46,8); printf("        Player vs Computer");
	    gotoxy(46, 11); printf("Nickname Kamu : ");
		_flushall();
		scanf("%[^\n]%*c", player1);
		system("cls");	
}

void mainmenu(){
	/*	Modul untuk menampilkan menu utama program
		dan juga menerima input pilihan player
	*/

	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<11;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
		
	
	//Batas Bawah
	    gotoxy(41, 17); printf("%c",200);
	    gotoxy(42, 17); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
    
    //Menu Teks
	    gotoxy(49, 7); printf("Selamat Datang di Game SOS!");
	    gotoxy(57, 8); printf("by 3Mantap");
	    gotoxy(46, 11); printf("Silahkan Pilih Menu di Bawah Ini");
	    gotoxy(46, 13); printf("[1] Play             ");
	    gotoxy(46, 14); printf("[2] How to play      ");
	    gotoxy(46, 15); printf("[3] Exit             ");
    
    //Input Batas Atas
	    gotoxy(41,18); printf("%c",201);
	    gotoxy(42,18); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Input Batas Pinggir
    	gotoxy(41, 19); printf("%c                                         %c",186,186);
    
    //Input Batas Bawah
	    gotoxy(41, 20); printf("%c",200);
	    gotoxy(42, 20); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    
    //Input User
	    gotoxy(43,19); printf("Pilihan Kamu : ");
		scanf(" %c",&pilihMenu);
		system("cls");
		}
	
	
void selectBoard(){
	/*	Modul untuk menampilkan menu pilih ukuran papan
		dan juga menerima input pilihan player
	*/
	
	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<10;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
			
	//Batas Bawah
	    gotoxy(41, 16); printf("%c",200);
	    gotoxy(42, 16); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
    
    //Menu Teks
	    gotoxy(47, 7); printf("  Silahkan Pilih Ukuran Papan");
	    gotoxy(47, 8); printf("      Yang Akan Dimainkan    ");
	    gotoxy(46, 11); printf("Pilihan :");
	    gotoxy(46, 13); printf("[1] 5x5");
	    gotoxy(46, 14); printf("[2] 7x7");
    
    //Input Batas Atas
	    gotoxy(41,17); printf("%c",201);
	    gotoxy(42,17); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Input Batas Pinggir
    	gotoxy(41, 18); printf("%c                                         %c",186,186);
    
    //Input Batas Bawah
	    gotoxy(41, 19); printf("%c",200);
	    gotoxy(42, 19); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    
    //Input User
	    gotoxy(43,18); printf("Pilihan Kamu : ");
		scanf(" %c",&pilihBoard);
		system("cls");
}

void selectOpponent(){
	/*	Modul untuk menampilkan menu pilih lawan
		dan juga menerima input pilihan player
	*/
	
	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<10;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
		
	
	//Batas Bawah
	    gotoxy(41, 16); printf("%c",200);
	    gotoxy(42, 16); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
    
    //Menu Teks
	    gotoxy(47, 7); printf("      Silahkan Pilih Mode");
	    gotoxy(47, 8); printf("      Yang Akan Dimainkan    ");
	    gotoxy(46, 11); printf("Pilihan :");
	    gotoxy(46, 13); printf("[1] Player vs Player");
	    gotoxy(46, 14); printf("[2] Player vs Computer");
    
    //Input Batas Atas
	    gotoxy(41,17); printf("%c",201);
	    gotoxy(42,17); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Input Batas Pinggir
    	gotoxy(41, 18); printf("%c                                         %c",186,186);
    
    //Input Batas Bawah
	    gotoxy(41, 19); printf("%c",200);
	    gotoxy(42, 19); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    
    //Input User
	    gotoxy(43,18); printf("Pilihan Kamu : ");
		scanf(" %c",&pilihOpponent);
		system("cls");
}

void selectLevel(){
	/*	Modul untuk menampilkan menu pilih tingkat kesulitan
		dan juga menerima input pilihan player
	*/
	
	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<10;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
		
	
	//Batas Bawah
	    gotoxy(41, 16); printf("%c",200);
	    gotoxy(42, 16); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
    
    //Menu Teks
	    gotoxy(43, 7); printf("   Silahkan Pilih Tingkat Kesulitan");
	    gotoxy(43, 8); printf("     Komputer Yang Akan Dimainkan");
	    gotoxy(46, 11); printf("Pilihan :");
	    gotoxy(46, 13); printf("[1] Normal");
	    gotoxy(46, 14); printf("[2] Hard");
    
    //Input Batas Atas
	    gotoxy(41,17); printf("%c",201);
	    gotoxy(42,17); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Input Batas Pinggir
    	gotoxy(41, 18); printf("%c                                         %c",186,186);
    
    //Input Batas Bawah
	    gotoxy(41, 19); printf("%c",200);
	    gotoxy(42, 19); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    
    //Input User
	    gotoxy(43,18); printf("Pilihan Kamu : ");
		scanf(" %c", &pilihLevel);
		system("cls");
}

void gameEnd(){
	/*	Modul untuk menampilkan menu tampilan akhir
		dan juga menerima input pilihan player
	*/
	
	//Batas Atas
		gotoxy(41, 5); printf("%c",201);
	    gotoxy(42, 5); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Batas Pinggir
	    int j=6;
	    for (int i = 0;i<10;i++){
	    	gotoxy(41, j); printf("%c                                         %c",186,186);
	    	j++;
		}
			
	//Batas Bawah
	    gotoxy(41, 16); printf("%c",200);
	    gotoxy(42, 16); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    //Garis Tengah
	    gotoxy(41, 10); printf("%c",204);
	    gotoxy(42, 10); for (int i=1;i<=41;i++){
	        printf("%c",205);
		}
		gotoxy(83,10); printf("%c",185);
    
    //Menu Teks
	    if(pilihOpponent=='1'){
	    	if(score1>score2){
	    		gotoxy(43, 6); printf("======= Permainan Telah Selesai =======");
	    		gotoxy(43, 7); printf("Pemenangnya Adalah %s",player1);
	    		gotoxy(43, 8); printf("Dengan Total Skor %d",score1);
	    		gotoxy(43, 9); printf("Selamat Kepada %s!",player1);
			}
			else if(score2>score1){
				gotoxy(43, 6); printf("======= Permainan Telah Selesai =======");
	    		gotoxy(43, 7); printf("Pemenangnya Adalah %s",player2);
	    		gotoxy(43, 8); printf("Dengan Total Skor %d",score2);
	    		gotoxy(43, 9); printf("Selamat Kepada %s!",player2);
			}
	    	else{
	    		gotoxy(43, 7); printf("======= Permainan Berakhir Seri =======");
	    		gotoxy(43, 8); printf("      Dengan Skor Masing-masing %d     ",score1);
			}
	    		}
		else{
			if(score1>score2){
				gotoxy(43, 7); printf("   Hebat! Kamu Memenangkan Permainan   ");
		    	gotoxy(43, 8); printf("         Dengan Total Skor %d          ",score1);
			}
			else if(score2>score1){
				gotoxy(43, 7); printf("          Yahh :( Kamu Kalah           ");
		    	gotoxy(43, 8); printf("  Tetap Menyerah dan Jangan Semangat!! ");
			}
			else{
				gotoxy(43, 7); printf("        Permainan Berakhir Seri        ");
				gotoxy(43, 8); printf("       Kamu Sudah Cukup Hebat :)       ");
			}
		}
	    
	    gotoxy(46, 11); printf("Apakah ingin lanjut bermain?");
	    gotoxy(46, 13); printf("[1] Ya");
	    gotoxy(46, 14); printf("[2] Tidak");
    
    //Input Batas Atas
	    gotoxy(41,17); printf("%c",201);
	    gotoxy(42,17); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",187);
    
    //Input Batas Pinggir
    	gotoxy(41, 18); printf("%c                                         %c",186,186);
    
    //Input Batas Bawah
	    gotoxy(41, 19); printf("%c",200);
	    gotoxy(42, 19); for (int i=1;i<=41;i++){
	        printf("%c",205);
	    }
	    printf("%c",188);
    
    
    //Input User
	    pilihContinue=0;
	    while(pilihContinue!=1 || pilihContinue!=2){
	    	gotoxy(43,18); printf("Pilihan Kamu : ");
	    	scanf(" %c", &pilihContinue);
			switch(pilihContinue){
				case '1' : system("cls");return;
				case '2' : gotoxy(43,20);printf ("Terima Kasih telah Bermain!");getch();exit(1);
				default : gotoxy(43,20);printf ("Silahkan Masukan Input yang Sesuai!");getch();gotoxy(43,20);printf("                                   ");
			}	
		}
}


//Modul untuk menentukan waktu awal peninputan saat bermain
int startTime(){
    clock_t t;
    t = clock();
    return t;
}

//Modul untuk menentukan waktu akhir peninputan saat bermain
int endTime(){
    clock_t t;
    t = clock();
    return t;
}

void gotoxy(int x, int y) {
	//Mencari posisi suatu koordinat pada layar	
  	COORD coord;
  	coord.X = x;
  	coord.Y = y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fontsize(int a, int b) {        
       HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);        
       CONSOLE_FONT_INFOEX font = {}; font.cbSize = sizeof(font);   
       GetCurrentConsoleFontEx(out, 0, &font);   
       font.dwFontSize.X = a;   
       font.dwFontSize.Y = b;   
       SetCurrentConsoleFontEx(out, 0, &font);   
}

void howToPlay(){
	/*	Modul untuk menampilkan tutorial dari file	*/
	
	system("cls");
 	FILE*the_file = fopen("caraberamin.txt", "r");
 	if(the_file == NULL){
  		perror("tidak ada file");
  		exit(1);
 	}
 
 	char line[100];
 	while(fgets(line, sizeof(line), the_file)){
  		printf("%s", line);
 	}
 	system("pause");
 	system("cls");
}
