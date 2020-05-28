/*
The Program below checks if the user input is a palindrome.
By: Deyvik Bhan
Date: 09/23/19
*/


#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


int main() {
	char wordInput[80];
	char word[80];

	int j = 0;
	char backward[80];
	char ch;
	// Initializes variables
	cout << "Enter a set of letters to see if it is a palindrome: ";
	cin.getline(wordInput, 80);
	// Gets input
	cout << "\n";
	
	// For loop below removes everything but characters between a and z
	for(int i = 0; wordInput[i] != '\0'; i++) {
	
	if((wordInput[i] >= 'a' && wordInput[i] <= 'z') ||(wordInput[i] >= 'A' && wordInput[i] <= 'Z')) {
	ch = wordInput[i];
	word[j++] = ch;	
	}	
		
}

	word[j] = '\0';
	// Loop beow converts all of the uppercase to lowercase
	for(int i = 0; word[i] != '\0'; i++) {
		if(word[i] >= 'A' && word[i] <= 'Z') {
			
			word[i] = word[i] + 32;
		}

	}
	
		// Loop below puts the input into another char array backward
	for(int i = 0; word[i] != '\0'; ++i) {
		ch = word[i];
		backward[strlen(word)-i-1] = ch;
		
	}
	
	// Compares the normal char array and backward char array to see if they're equal
	if(strcmp(word, backward) == 0) {
		cout << "Palindrome\n";
	} else {
		cout << "Not a palindomre\n";
	}

}
