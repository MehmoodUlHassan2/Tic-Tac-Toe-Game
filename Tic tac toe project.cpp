 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                           //
 //                                                                                                           //
 //                                          Major Assignment                                                 //
 //                                          Tic Tac Toe Game                                                 //
 //                                                                                                           //
 //                                                                                                           //
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


# include <iostream>
# include <Windows.h>
# include <string>

using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); 

int a, c=0, g;
int quit=0;
int row, column;
int menuchoice, gamechoice, choice;
int score1=0, score2=0;
int lose1=0, lose2=0;
int Draw=0;

bool draw = false;
bool gameover();

string player1,player2;

char exitoption;
char turn='X';


 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                           //
 //                               Declearing and initializing array                                           //
 //                                       For Main Board                                                      //
 //                                                                                                           // 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


char board[3][3] = { { '1', '2', '3' } , { '4', '5', '6' } , { '7', '8', '9' } };
  


 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                           //
 //                                          Code of Colors                                                   //
 //                                                                                                           //
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void color(int y)
{  
 
    SetConsoleTextAttribute(out, y);  

} 


 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                           //
 //                                             Fontsize                                                      //
 //                                                                                                           //
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void fontsize(int a, int b)
{  

   PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
   lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
   GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
   lpConsoleCurrentFontEx->dwFontSize.X = a;  
   lpConsoleCurrentFontEx->dwFontSize.Y = b;  
   SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  

 }

 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                            About                                                        //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void about()
{	
      fontsize(10,18);
      system("cls");
	 
	 color (10); 
	 cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n\n";
	 
	 color(7);
	 cout<<"   <<<<<<Group Project>>>>>>\n\n";
	 
	 color(7);
	 cout<<"Created By\n\n"
		         "    1) Mehmood Ul Hassan\n"
	        	    "    2) Muhammad Haseeb\n";
	 
	 system("pause");
	
} 

 
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                        //
 //                                         Main Menu                                                      //
 //                                                                                                        //
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
void mainmenu(){
     
	 fontsize(10,18);
      system("cls");
     
	 color (10); 
	 cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n";
      
	 color(15);
	 cout<<"\tMain Menu\n\n";
     
	color(15);  
     cout<<"   1) Start Game\n"
           "   2) Game Info\n"
	       "   3) How To Win\n"
	       "   4) Score\n"
	       "   0) Exit \n\n"
	       "       Choice :- ";
     
	cin>>menuchoice;
	    
     while ( menuchoice >= 5 )
     {
     	
	  cout<<"Invalid Choice \n"
	        "Please Select a Valid One\n"
	        "   Choice :- ";
	  cin>>menuchoice;
     
	}
	
}


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                             Exit                                                        //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void exit()
{
	
     system("cls");
  
     cout<<"\n\n\n\t\tAre You Sure You want to Exit\n\n"
 	    "\t\t     (Yes 'Y' or No 'N')\n\n"
	    "\t\t         choice :- ";
     cin>>exitoption;
	      
     if ( exitoption == 'y' || exitoption == 'Y' )
     
	a=0;
     
	else 
	if ( exitoption == 'n' || exitoption == 'N' )
     
	a=1;
     
}


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                   Declearing The Names of User                                          //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void declear_player()
{
	 system("cls");
	 fontsize(10,18);
	 
	 color (10); 
	 cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n\n";
	 
	 color(14);
	 cout<<"\tPlayer Names\n\n";
     
	 color(15);
	 cout<<"Enter the Name of Player 1\n";
	 cin>>player1;
	 
	 color(15);
	 cout<<"Enter the Name of Player 2\n";
	 cin>>player2;

} 


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                           Main Display Board                                            //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void display_board()
{
     system("cls");
    
	 fontsize(10,18);
	
	 color (10); 
	 
	 cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n";
	
	     color (15); 
		
		cout<<"  Player 1";color (8); cout<<" [X]\n";
	
	     color (15); 
		
		cout<<"  Player 2";color (8); cout<<" [0]\n\n";
	
	     color(14);
    
	      cout<<" \t\t          |     |     \n"
          " \t\t       ";color(15);cout<<board[0][0];color(14);cout<<"  |  ";color(15);
		  cout<<board[0][1];color(14);cout<<"  |  ";color(15);cout<<board[0][2];color(14);cout<<"  \n"
          " \t\t     _____|_____|_____\n"
          " \t\t          |     |     \n"
          " \t\t       ";color(15);cout<<board[1][0];color(14);cout<<"  |  ";color(15);
		  cout<<board[1][1];color(14);cout<<"  |  ";color(15);cout<<board[1][2];color(14);cout<<"  \n"
          " \t\t     _____|_____|_____\n"
          " \t\t          |     |     \n"
          " \t\t       ";color(15);cout<<board[2][0];color(14);cout<<"  |  ";color(15);
		  cout<<board[2][1];color(14);cout<<"  |  ";color(15);cout<<board[2][2];color(14);
		  cout<<"  \n"
          " \t\t          |     |     \n\n\n";
		color(15);
     
  }


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                         Player Turns                                                    //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void player_turn()
{
	 
	 /////////////////////Deciding Player Turn Through IF statment/////////////////////////
	 
	 if ( turn == 'X' )
	 {
	 	
	 cout<<" Press 0 to Quit\n";
	 
	 color(15);
	 cout<<" Player 1 :-"<<player1;  color(10);  cout<<" [X]";  color(15);  cout<<" turns :-";
      
	 }
	 else if ( turn == 'O' )
	 {
	 	
	 cout<<" Press 0 to Quit\n";
	 
	 color(15);
	 cout<<" Player 2 :-"<<player2;  color(10);  cout<<" [O]";  color(15);  cout<<" turns :-";
	 
	 }
	 
	 cin>>choice;
	
	 /////////////////////////////////switch statment Body///////////////////////////////
	 //                  Replacing 'X' or 'O' by The Number User Selected              //
	 ////////////////////////////////////////////////////////////////////////////////////
	
	   switch(choice)
	   {
	   	
	   	 case 0:
	   	 	 
		 	quit=1;          break;
		 case 1:
			 
			 row=0;column =0; break;
		 case 2:
		      
			 row=0;column =1; break;
		 case 3:
			 
			 row=0;column =2; break;
		 case 4:
			 
			 row=1;column =0; break;
		 case 5:
			 
			 row=1;column =1; break;
		 case 6:
			 
			 row=1;column =2; break;
		 case 7:
			 
			 row=2;column =0; break; 
		 case 8:
		      
			 row=2;column =1; break;
		 case 9:
			 
			 row=2;column =2; break;
		 default:
		  	 
			cout<<"Invalid choice\nPlease Select Valid Numeric Value\n";
			player_turn();
			break;
		
		}
		
	}

	
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                   Exchanging The turns                                                  //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void turn_change()
{
	
		 if ( quit == 1 )
		 bool gameover();
		 
		 else	
		 if ( turn == 'X' &&  board[row][column] != 'X'  &&  board[row][column] != 'O' )
		 {
			  board[row][column] = 'X' ;
			  turn = 'O' ;
		 }
		 else
		 if ( turn == 'O' &&  board[row][column] != 'X'  &&  board[row][column] != 'O' )
		 {
			  board[row][column] = 'O';
			  turn = 'X';
		 }
		 else 
		 {
			cout<<"Invalid Choice!\nPlease try Again\n\n";
			player_turn();
		 }
		
		  display_board();
		
}
	
	
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                            gameover                                                     //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool gameover()
{
	
	 /////////////////////////////////////////////////////////////////////////////////////////////
	 //                               <<<<<<<<win check>>>>>>>>                                 //
	 /////////////////////////////////////////////////////////////////////////////////////////////
	 
	 //////////////////////////////////// Game Intrupted ///////////////////////////////////////// 
	 
	 if ( quit == 1 )
	 return false;
	
  	 ////////////////////////////////////// Rows check ///////////////////////////////////////////

  	 if ( board [1][0] == board [1][1] && board [1][0]  == board [1][2] )
  	 return false;
  	 
  	 if ( board [0][0] == board [0][1] && board [0][1]  == board [0][2] )
  	 return false;
  	 
  	 if ( board [2][0] == board [2][1] && board [2][0]  == board [2][2] )
  	 return false;

  	 //////////////////////////////////// Diagonals Check ////////////////////////////////////////

  	 if ( board [0][0] == board [1][1] && board [1][1]  == board [2][2] )
  	 return false;
  	 
  	 if ( board [2][0] == board [1][1] && board [1][1]  == board [0][2] )
  	 return false;

  	 /////////////////////////////////// Column Check ///////////////////////////////////////////

  	 if ( board [0][0] == board [1][0] && board [1][0]  == board [2][0] )
  	 return false;
  	 
  	 if ( board [0][1] == board [1][1] && board [1][1]  == board [2][1] )
  	 return false;
  	 
  	 if ( board [0][2] == board [1][2] && board [1][2]  == board [2][2] )
  	 return false;
     
     //////////////////////////////// unfilled Box Check ////////////////////////////////////

     for ( int i=0 ; i<3 ; i++ )
     {
     	
     for ( int j=0 ; j<3 ; j++ )
     {
         if ( board [i][j] != 'X' && board [i][j] != 'O' )
         return true;   
	}
	}
	
     ///////////////////////// When all Boxes Filled and No one wins ///////////////////////
    
     draw = true;
     return false;

}


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                          Start Game                                                     //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void startgame()
{
    declear_player();
   
 do{
 	
    system("cls");	
	 
     while ( gameover() )//when function 'gameover' returns false while body will end 
     {
	
     display_board();
	
     player_turn();  
       
     turn_change();
    
     gameover();

     }        //while loop body Ends
	    
	 /////////////////////////// Player Wins Display /////////////////////////////////
	if ( draw == false && quit == 1 )
     	
		cout<<"\t\t!!Game Intrupted!!\n";
	
	else 
     if ( turn == 'X' && draw == false )
     {
       
	  cout<<"\t<<<<<<Congratulations>>>>>>\n\t\t"<<player2<<" wins\n";
	    	
	  score2++;  //  if player 2 wins then player 2 score will increament
		    
	  lose1++;   //  if player 2 wins then player 1 lose point will increament
       
	} 

     else 
	if ( turn == 'O' && draw == false )
	 {
	  
	   cout<<"\t<<<<<<Congratulations>>>>>>\n\t\t"<<player1<<" wins\n";
		    
        score1++;  //  if player 1 wins then player 1 score point will increament
		    
	   lose2++;   //  if player 1 wins then player 2 lose point will increament
     
	}
     else 
     {
      
	   cout<<"\t\t >>>>>Game Draw<<<<<\n\t\t >>>>>Try Again<<<<<";
       
	   Draw++;   //   Increament in Draw point
     
	}
	
	   //////////////////////////////////Return Option//////////////////////////////////////
	        
	   cout<<"\n\n 1) Play Again\n"
	         " 2) Main Menu\n"
	         " 0) Exit\n  Choice :- ";
	   
	   cin>>gamechoice;
	         
	   ////////////////////////If user Select Wrong Choice//////////////////////
	       
	     while ( gamechoice >= 3 )
	 {
	     
		cout<<"\t!!!Invalid Choice!!!\n"
	       "\tPlease Select a valid one\n"
		  "\t  Choice:-";
	     cin>>gamechoice;
	 
	 }
	         	          
      if ( gamechoice == 2 )
      
	 a=1;  quit=0;   //if user select 2 to main menu loop will end but a will be equal to 1 so the outer loop will return 1
	
	 if ( gamechoice == 0 )
	 
	 a=0;   //if user select 0 to Exit loop will end and a will equal to 0 so the other loop will also end
     
      ////////////////////////////////Asigning Board values//////////////////////////////////////
       
	   int n=49;// assigning 49 because it's ASCII value gives 1
	   
	   draw=false;
        quit = 0;
        
      for ( int i=0 ; i<3 ; i++ )
      { 
    
	   for ( int j=0 ; j<3 ; j++ )
        { 
	
	      board[i][j]=n;// n=49 because again assigning that previous value print their ASCII output
	      n++;//n increament from 49 (1) upto 57 (9)
	
	    } 		
      }
       
	   	turn='X';// To retain Player 1 symbol 'X' and Player 2 symbol 'O'
    
      
     } while ( gamechoice != 0 && gamechoice != 2 );
 
    ///////////////////////////////////Game Ending//////////////////////////////////////////
}
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                           Game Info                                                     //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void game_info()
{
 	 system("cls");
	
 	 fontsize(10,18);
	
 	 color (10);
 	 cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n\n";
	
 	 color(9); 
	 cout<<"\n\t\tRULES OF TIC-TAC-TOE\n\n";

      color(14); 
	 cout<<" 1.";color(15); cout<<" The game is played on a grid that's 3 squares by 3 squares.\n\n";  

      color(14); 
	 cout<<" 2.";color(15); cout<<" You are X, your friend is O. Players take turns putting their"
                                   " \n    marks in any number squares.\n\n";
                   
      color(14); 
	 cout<<" 3.";color(15); cout<<" The player who get 3 of her marks in a row\n"
                                   "    (up, down, across, or diagonally) is the winner.\n\n";
 
     color(14); 
	cout<<" 4.";color(15); cout<<" When all 9 squares are full, the game is over.\n"
                                  "    If no player has 3 marks in a row, the game ends in a tie.\n\n\n";
                                        
   	
	cout<<"\n\n"
	      "   1) Main Menu\n"
		  "   0) Exit\n"
		  "    Choice :- ";
	
	cin>>gamechoice;
	
	while ( gamechoice >= 2 )
	{
		cout<<"Invalid Choice\n"
		      "Please Select a valid one\n";
		cin>>gamechoice;
	}
	if ( gamechoice == 0 )
	{
	
	exit();
	if ( exitoption == 'n' || exitoption == 'N' )
	{
		game_info();
	}
	
	a=0;
	
	}
	else
	
	a=1;

}


 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                                                                                                         //
 //                                      How To Win                                                         //
 //                                                                                                         //
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////


void how_to_win()
{
 	system("cls");
	
 	fontsize(10,18);
	
 	color (10); 
 	cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n\n";

 	color(9);
	cout<<"\t    How To Play Tic Tac Toe\n\n";
 	
	color(15);
 	cout<<"  To beat the Opponent, you need to make use of a little bit of strategy.\n" 
	      "  Strategy means figuring out what you need to do to win.\n"
           "  Part of your strategy is trying to figure out how to get three Xs or Os\n"
		 "  in a row,column or Diagonal.\n" 
		 "  The other part is trying to figure out how to stop the Opponent from\n"
		 "  getting three Os or Xs in a row,column or Diagonal.\n"
           "  After you put an X or O in a square, you start looking ahead. Where's the best"
		 "  place for your next X or O?\n" 
		 "  You look at the empty squares and decide which ones are good choices-which\n"
		 "  ones might let you make three Xs or Os in a row,column or Diagonal.\n"
           "  You also have to watch where the Opponent puts its O or X. That could\n"
		 "  change what you do next.\n" 
		 "  If the Opponent gets two Os or Xs in a row, you have to put your next X or O\n"
		 "  in the last empty square in that row,column or Diagonal otherwise the Opponent  will win.\n"
		 "  You are forced to play in a particular square or lose the game.If you always\n"
		 "  pay attention and look ahead, you'll never lose \n  a game of Tic-Tac-Toe.you may\n"
		 "  not win, but at least you'll tie.\n\n";
	
		 cout<<"\n\n"
		       "   1) Main Menu\n"
			  "   0) Exit\n"
			  "    Choice :- ";
	     cin>>gamechoice;
	
 	while ( gamechoice >= 2 )
 	{
		cout<<" Invalid Choice\n"
		      " Please Select a valid one\n";
		cin>>gamechoice;
 	}
 	if ( gamechoice == 0 )
 	{
		exit();
		if ( exitoption == 'n' || exitoption == 'N' )
		{
			how_to_win();
		}
		
		a=0;
  	
	  }else
		
		a=1;

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                         //
//                                             score                                                       //
//                                                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void score()
{
 	
	system("cls");
 	fontsize(10,18);
 	
 	color (10); 
 	cout<<"\n\t\t\t Tick";color (11); cout<<"  Tac";color (13); cout<<" Toe";color (12); cout<<" Game\n\n";
	
 	color(11); cout<<">>>Scores\n\n";
 	
 	////////////////////  Player 2 Win and Lose Number  ///////////////////
	
 	color(10); 
	 cout<<"  >>Player 1 \n";
	
 	color(15); 
	 cout<<"\n      >>wins :- "<<score1<<endl;
      cout<<"\n      >>Loses :- "<<lose1<<endl;
	
 	////////////////////  Player 2 Win and Lose Number  ///////////////////
 	
 	color(10); 
	 cout<<"\n  >>Player 2 \n\n";
 	
 	color(15);
	 cout<<"      >>wins :- "<<score2;
 	 cout<<"\n\n      >>loses :- "<<lose2<<endl;
	
 	/////////////////////   Number of Draws  //////////////////////////////
	
 	color(10);
	 cout<<"\n  >>Games Draw \n\n";
 	
 	color(15);
	 cout<<"      >>Draws :- "<<Draw<<endl<<endl;
 	
 	cout<<"\n\n   1) Main Menu"
	        "\n   2) Reset Score"
	 	   "\n   0) Exit"
		   "\n    Choice :- ";
  	cin>>gamechoice;
	
	 while ( gamechoice >= 3 )
	 {
	
		cout<<"Invalid Choice\n"
		      "Please Select a valid one\n";
		cin>>gamechoice;
	
	 }
	 
	 if ( gamechoice == 0 ) // if user want to Exit 
	 {
	  
	  exit();
	  
	  if ( exitoption == 'n' || exitoption == 'N' )
	 
	  score();
	  
	 }
	 else if ( gamechoice == 1 ) // if user want to go to main menu 
	 a=1;
	 
	 else if ( gamechoice == 2 ) // if user want to reset Score
	 {
		
     score1=0,score2=0;
	lose1=0,lose2=0;
	Draw=0;
     score();   // To show the updated score
     
    }
    
    }

    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                         //
//                                         Main Body of Program                                            //
//                                                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


main()
{
 
   about();

  do{
	
    mainmenu(); 
   
    switch(menuchoice)
	{
		
	case 1:
	
	startgame();
	break;
	   		
     case 2:		
	
	game_info();
	break;
	   
	case 3:
	
	how_to_win();
	break;
	
	case 4:
	
	score();
	break;
	    
	case 0:
	
	exit();
	break;
    
	} 
  
   }while(a!=0);//loop will end when a equals to 0
   
    system("cls");      
    
     //////////////////////////////////////////////////////////////////////////////////
	//                                 End Note                                     //     
	//////////////////////////////////////////////////////////////////////////////////
	
	cout<<"\n\n\n\n\n\n\n\n\t"<<char(247)<<char(247)<<char(173)<<char(173)<<char(173);
	
	cout<<" Hope You Enjoy The Game ";	
	
	cout<<char(173)<<char(173)<<char(173)<<char(247)<<char(247)<<"\n\n\n\n\n\n\n\n\n\n";
  
  }
    
     //////////////////////////////////////////////////////////////////////////////////
     //                                                                              //
	//                             End Of Program                                   //
	//                                                                              //
	//////////////////////////////////////////////////////////////////////////////////
	
	
