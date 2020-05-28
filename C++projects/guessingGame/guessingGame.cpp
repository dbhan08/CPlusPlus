/* This is guesing game. The computer will generate a number between 1 and 100
and the user will try to guess it.
By: Deyvik Bhan
Date: 09/15/19


*/


#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;
// Function that contains code for the actual game
void game() {
	int guesses = 0;
	// Amount of guesses
	char ans[1];
	// Char array which is used to determine if player wants to continue playing
	
	bool inGame = true;
	// Boolean for while true the game will play
	srand (time(NULL));
	// Generates seed
	int random = rand() % 101;
	// Random number between 1 and 100
	int guess;
	// User's guess

	cout<< "Welcome to guessing game. In this game you are trying to guess a number between 1 and 100!\n";

	while(inGame) {
		cout << "Guess a number:";
		cin >> guess;
		// Reads in guess
		cout << "\n";
		guesses++;
		// Increase amount of gueeses
		if(guess == random) {
		// If user guessed the right number
			cout << "You guessed the number! It took you " << guesses << " guesses! If you would like to play again type in 'y', if not type in 'n'";
			cin >> ans;
			if(strcmp(ans, "y") == 0) {
			// If the user wants to keep plaing
				cout << "Number genrated!\n";
				random = rand() % 101;
				guesses = 0;
			} 
			if(strcmp(ans, "n") == 0) {
			// If the user wants to quit
				cout << "Thanks for playing!\n";
				inGame = false;	
			}

		} else if(guess > random) {
			// If the user guessed to high
			cout << "Your guess is too high!\n";
		} else if(guess < random) {
			// If the user guessed to low
			cout << "Your guess is too low!\n";
		} 

		

	}

}

int main() {
	game();
}
