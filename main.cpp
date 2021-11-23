#include <iostream>
using namespace std;

struct Player
{
	char name[100];
	char id;
};

int PlayerInput(char board[][10], Player active)
{
	int choice;
	do
	{
		cout<<active.name << "'s Turn "<<endl;
		cout<<"Enter column number between 1 and 7: ";
		cin>>choice;

		while(board[1][choice] == 'R' || board[1][choice] == 'Y')
		{
			cout<<"Row is full, please enter a new row: ";
			cin>>choice;
		}
	}while(choice < 1 || choice > 7);

return choice;
}

void CheckTurn(char board[][10], Player active, int choice)
{
	int length = 6, turn = 0;

	while(turn != 1)
	{
		if(board[length][choice] != 'R' && board[length][choice] != 'Y')
		{
			board[length][choice] = active.id;
			turn = 1;
		}
		else
		{
			length--;
		}
	}
}

void PrintBoard(char board[][10])
{
	int rows = 6, cols = 7;
	for(int i = 1; i <= rows; i++)
	{
		for(int j = 1; j <= cols; j++)
		{
			if(board[i][j] != 'R' && board[i][j] != 'Y')
			{
				board[i][j] = '_';
			}
			cout<<"|";
			cout<<board[i][j];		
		}
		cout<<"|"<<endl;
	}
	cout<<endl;
}

int CheckFour(char board[][10], Player active)
{
	char activeID = active.id;
	int win = 0;

	for(int i = 8; i >= 1; i--)
	{
		for(int j = 9; j >= 1; j--)
		{
			if(board[i][j] == activeID && board[i-1][j-1] == activeID && 
				board[i-2][j-2] == activeID && board[i-3][j-3] == activeID)
			{
				win = 1;
			}

			if(board[i][j] == activeID && board[i][j-1] == activeID &&
				board[i][j-2] == activeID && board[i][j-3] == activeID)
			{
				win = 1;
			}
					
			if(board[i][j] == activeID && board[i-1][j] == activeID &&
				board[i-2][j] == activeID && board[i-3][j] == activeID)
			{	
				win = 1;
			}
					
			if(board[i][j] == activeID && board[i-1][j+1] == activeID &&
				board[i-2][j+2] == activeID && board[i-3][j+3] == activeID)
			{
				win = 1;
			}
						
			if(board[i][j] == activeID && board[i][j+1] == activeID &&
				 board[i][j+2] == activeID && board[i][j+3] == activeID)
			{
				win = 1;
			}
		}
	}
	return win;
}

int FullBoard(char board[][10])
{
	int full = 0;
	for(int i = 1; i <= 7; i++)
	{
		if(board[1][i] != '_')
		{
			full++;
		}
	}
	return full;
}

void Winner(Player active)
{
	cout<<active.name<<" Connected Four!"<<endl;
	cout<<active.name<<" is the WINNER!"<<endl;
}

int main()
{
	Player playerOne, playerTwo;
	char board[9][10]; 
	int trueWidth = 7; 
	int trueLength = 6; 
	int choice, win, full, again;

	cout<<"Let's Play Connect 4"<<endl<<endl;

	cout<<"Player One(RED): "<<endl;
	cout<<"Please Enter Your Name: ";
	cin>>playerOne.name;
	playerOne.id = 'R';
	cout<<endl;

	cout<<"Player Two(Yellow): "<<endl;
	cout<<"Please Enter Your Name: ";
	cin>>playerTwo.name;
	playerTwo.id = 'Y';
	cout<<endl;

	full = 0;
	win = 0;
	PrintBoard(board);
	do
	{
		choice = PlayerInput(board, playerOne);
		CheckTurn(board, playerOne, choice);
		cout<<endl;
		PrintBoard(board);
		win = CheckFour(board, playerOne);
		if(win == 1)
		{
			Winner(playerOne);
			break;
		}

		choice = PlayerInput(board, playerTwo);
		CheckTurn(board, playerTwo, choice);
		cout<<endl;
		PrintBoard(board);
		win = CheckFour(board, playerTwo);
		if(win == 1)
		{
			Winner(playerTwo);
			break;
		}
		full = FullBoard(board);
		if(full == 7)
		{
			cout<<"The board is full, GAME DRAW!" << endl;
			break;
		}
	}while(win != 1 || full != 7);

return 0;
}