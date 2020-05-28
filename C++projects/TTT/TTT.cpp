/* The following is a program for a Tic Tac Toe game
By: Deyvik Bhan
Date: 10/02/19
*/


#include <iostream>
#include <cstring>

using namespace std;

// Following function draws the board
void drawBoard(int board[3][3]) {
	 int BLANK = 0;
	int X_MOVE = 1;
	int O_MOVE = 2;
	int X_TURN = 0;
	int O_TURN = 1;
	int X_WINS = 0;
	int O_WINS = 0;

	
	std::cout << "\t1\t2\t3\n";

	for(int i = 0; i < 3; i++) {
		char out = (char)('a' + i );
		cout << out << "\t";
		for(int j = 0; j < 3; j++) {
			if(board[i][j] == BLANK) {
				cout << "\t";
			} else if(board[i][j] == X_MOVE) {
				cout << "X\t";
			} else if(board[i][j] == O_MOVE) {
				cout << "O\t";
			}
			 
		} 
	cout << "\n";	
	}
	
}
// Following function clears the board
void clearBoard(int board[3][3]) {
	int BLANK = 0;
// Following code makes all the spots on the board a blank
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			board[row][column] = BLANK;
			// Resets turn back to X
		}
}
}
// Following function checks if the game is atie
bool checkTie(int board[3][3]) {
	int BLANK = 0;
		//Checks if all the possible spots are taken then  declares it a tie
		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				if(board[row][column] == BLANK) {
					return false;
				}
			}
		}
		return true;		
	}

// Following function checks if a player has won
bool checkWin(int player, int board[3][3]) {
		// Checks all the possible kinds of wins
		if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
			drawBoard(board);
			return true;
		}		
		if(board[1][0] == player && board[1][1] == player && board[1][2] == player) {
			drawBoard(board);
			return true;
		}		
		if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
			drawBoard(board);
			return true;
		}		
		if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
			drawBoard(board);
			return true;
		}		
		if(board[0][1] == player && board[1][1] == player && board[2][1] == player) {
			drawBoard(board);
			return true;
		}		
		if(board[0][2] == player && board[1][2] == player && board[2][2] == player) {
			drawBoard(board);
			return true;
		}		
		if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
			drawBoard(board);
			return true;
		}
		if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
			drawBoard(board);
			return true;
		}
		return false;
	}


int main() {

	char inp[10];
	int board[3][3];
	int BLANK = 0;
	int X_MOVE = 1;
	int O_MOVE = 2;
	int X_TURN = 0;
	int O_TURN = 1;
	int X_WINS = 0;
	int O_WINS = 0;
	int TIE = 0;
	int turn = X_TURN;
	bool playing = true;
	board[2][2] = BLANK;
	board[0][0] = BLANK;
	clearBoard(board);
	while(playing) {
	drawBoard(board);
	cout << "\n";
	cout << "Enter an input of a row and column(for example a1): ";
	cin >> inp;
	cout << "\n";
	
	// Following series of if statements makes sure the input is in the correct format	
	if(strlen(inp) != 2) {

		cout << "Enter a input two characers long:\n";

	}

	else if(inp[0] == '1') {

		playing = false;

	}

	 else if(inp[0] != 'a' && inp[0] != 'b' && inp[0] != 'c') {
		cout << "First character must be 'a','b, or 'c'\n";

	}

	 else if(inp[1] != '1' && inp[1] != '2' && inp[1] != '3') {

		cout << "Second character must be '1','2, or '3\n";

		

	} else {

		int row = (char)(inp[0] -  'a');
		
		int column = (char)( inp[1] - '1');
		// If the spot already doesn't have piece
		if(board[row][column] == BLANK) {
			// IF it is X's move
			if(turn == X_TURN) {
			// Put a x there
				board[row][column] = X_MOVE;
				turn = O_TURN;
			} else {
				// Put an O there
				board[row][column] = O_MOVE;
				turn = X_TURN;

			}
						
		} else {
		cout << "There is a piece there!\n" << row << "," << column;
		}
	}

	if(checkWin(X_MOVE,board)) {
		// If x has won
		clearBoard(board);
		X_WINS++;
		turn = X_TURN;
		cout << "\nX Won!\n";
		cout << "\nX Wins: " << X_WINS << "\tO Wins: " << O_WINS << "\tTies: " << TIE << "\n\n"; 
		
	} else if(checkWin(O_MOVE, board)) {

	// If O has won
		clearBoard(board);
		O_WINS++;
		turn = X_TURN;
		cout << "\nO Won!\n";
		cout << "\nX Wins: " << X_WINS << "\tO Wins: " << O_WINS << "\tTies: " << TIE << "\n\n"; 		
	
	} else if(checkTie(board)) {
		// If theres a tie
		TIE++;
		clearBoard(board);
			turn = X_TURN;
		cout << "\nIt is a tie!\n";
		cout << "\nX Wins: " << X_WINS << "\tO Wins: " << O_WINS << "\tTies: " << TIE << "\n\n"; 
	}
	}
}	
