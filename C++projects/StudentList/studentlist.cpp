/* The following program is a student list which stores information such as the students name, id and gpa. This program can add, remove, and print items in this list
By: Deyvik BHan
Date: 10/21/19
 */



#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Struct for student
struct student {
	char firstName[80];
	char lastName[80];
	int id;
	float gpa;
};


// Function that adds student
void addStudent(vector<student*> &Students) {
	float x;
	int i;
	Students.push_back(new student());
	int size = Students.size()-1;
	 cout << "Enter first name: ";
	 cin >> Students.back() -> firstName;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "\n";
	cout << "Enter a last name: ";
	cin >> Students.back() -> lastName;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "\n";
	cout << "Enter id: ";
	cin >> Students.back() -> id;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "\n";
	cout << "Enter their gpa: ";
	cin >> Students.back() -> gpa;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "\n";
	

	
	
}

// Function that prints student info from list
void printStudent(vector<student*> Students) {
	std::vector<student*>:: iterator i;
	for(i = Students.begin(); i != Students.end(); i++) {
		cout << (*i) -> firstName << " " << (*i) -> lastName << ", " <<
		fixed << setprecision(2) << (*i) -> gpa << ", " << (*i)  -> id << "\n";


        }

}

// Function that removes students from the list
void rmvStudent(vector<student*> &Students) {
	int rmvID;
	cout << "Enter the I.D of the student you would like to remove: ";
	cin >> rmvID;
	std::vector<student*>:: iterator i;
	for(i = Students.begin(); i != Students.end(); ++i) {
		int position = i - Students.begin();
		 if(rmvID == Students[position] -> id) {
			cout << "Deleting " << (*i) -> firstName << "\n";
			
			
			delete Students[position];
			Students.erase(Students.begin() + position);
			break;
			

		} 
		

		
	}
}



int main() {
// Main function


// Vector with student pointers
vector<student*> structStudents;

bool running = true;
char input[10];
char add[10] = "ADD";
char rmv[10] = "DELETE";
char print[10] = "PRINT";
char quit[10] = "QUIT";


cout <<"Welcome to Student List! You can add, delete and print from the database\n\n";

cout << "To add type 'ADD', to delete type 'DELETE' and to Print type 'Print'.\n\n";

while(running) {

cout << "Enter what you would like to do. To quit the program type 'QUIT'\n\n";

cin >> input;
// Gets input

// Based on the input runs the various functions
if(strcmp(input, quit) == 0) {
	cout << "Quitting\n";
	running = false;
} else if(strcmp(input, add) == 0) {
	addStudent(structStudents);
	cout << "Adding\n\n";
	
} else if(strcmp(input, rmv) == 0) {
	rmvStudent(structStudents);
	
	
} else if(strcmp(input, print) == 0) {
	
	printStudent(structStudents);
	

} else {
	cout << "Enter a valid option\n\n";

}
}
return 0;
}
