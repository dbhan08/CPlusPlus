/*
Following program has the ability to add, delete and search a database of different types of media
By:Deyvik Bhan
Date:11/5/19
*/




#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <ctsdlib>
#include "Media.h"
#include "Games.h"
#include "music.h"
#include "Movies.h"
// main


using namespace std;
// Follwing are functions used to search delete and add to the database
void addMedia(vector<Media*> &database);
void deleteMedia(vector<Media*> &databse);
void searchMedia(vector<Media*> database);

int main() {

bool playing = true; 
vector<Media*> database;
// Media vector
char inp[100];

// While the player is till playing
while(playing) {
cout << "Do you want to \"ADD\", \"SEARCH\", or \"DELETE\" media?" << endl;
cout << "If you would like to QUIT type \"QUIT\"" << endl;
cin >> inp;


// What the player wants to do

if(strcmp(inp, "ADD") == 0) {
	addMedia(database);
	
	cout << "Adding" << endl;

} else if(strcmp(inp, "SEARCH") == 0) {
	searchMedia(database);
	
	
} else if(strcmp(inp, "DELETE") == 0) {
	 deleteMedia(database);

} else if(strcmp(inp, "QUIT") == 0) {
	cout << "Quitting" << endl;
	playing = false;

} else {
	cout << "Enter a valid option << endl";


}

}
return 0;
}


// Function that adds certain types of media to the main media vector
void addMedia(vector<Media*> &database) {
	int year;
	char inp[20];
	char* title;
	title = new char[100];
	cout << "Enter the title of the Media" << endl;
	cin >> title;
	cout << "Enter the year the Media was created" << endl;
	cin >> year;
	cout << "Enter the the type of media. Is it a \"GAME\" or \"MUSIC\" or a \"MOVIE\"? " << endl; 
	cin >> inp;
	
	if(strcmp(inp, "MOVIE") == 0) {
		cout << "What is the movie's rating?" << endl;
		float rating;
		cin >> rating;
		cout << "How long is it?" << endl;
		char* duration;
		duration = new char[100];
		cin >> duration;
		cout << "Who is the director?";
		char* director;
		director = new char[100];
		cin >> director;
		database.push_back(new Movie(title, director ,year,rating,duration)); 
		

	} else if(strcmp(inp, "GAME") == 0) {


	 cout << "What is the Game's rating?" << endl;
                float rating;
                cin >> rating;
                cout << "Who is the publisher" << endl;
                char* publisher;
		publisher = new char[100];
		cin >> publisher;

                database.push_back(new Games(title,year,rating,publisher));



	} else if(strcmp(inp, "MUSIC") == 0) {
		char* artist;
		artist = new char[100];
		cout << "Who is the artist?" << endl;
                cin >> artist;
                cout << "Who is the publisher" << endl;
                char* publisher;
		publisher = new char[100];
		cin >> publisher;
		cout << "What is the duration?";
		char* duration;
                duration = new char[100];
                cin >> duration;
                database.push_back(new music(title,artist,year,duration,publisher));




	} else {
		cout << "Enter a valid option";
		delete title;
	}

	

}





// Function that searches the media vector by title and year
void searchMedia(vector<Media*> database) {
	cout << "Would you like to search by \"YEAR\" or by \"TITLE\"?" << endl;	
	char inp[20];
	cin >> inp;
	bool match;

	if(strcmp(inp, "YEAR") == 0) {
		cout << "Enter the year you will be searching for: ";
		int year;
		cin >> year;
		vector<Media*>:: iterator i;
		for(i = database.begin(); i != database.end(); i++) {
			
			int position = i - database.begin();
			if(database[position] -> getYear() == year) {
				match = true;
			if(database[position]->getType() == 1) {
				cout << "Found a game" << endl;
				cout << "Title: "<< database[position]->getTitle() << endl;	
				cout << "Year: " << database[position]->getYear() << endl;
				cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
				cout << "Publisher: " << database[position] -> getPublisher() << endl;
			} else if(database[position]->getType() == 2) {
				 cout << "Found a Movie" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;   
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Director: " << database[position] -> getDirector() << endl;
				cout << "Duration: " << database[position] -> getDuration() << endl;

			} else if(database[position]->getType() == 3) {
				 cout << "Found Music" << endl;
                     cout << "Title: "<< database[position]->getTitle() << endl;
                     cout << "Year: " << database[position]->getYear() << endl;
                   cout << "Artist: " << database[position]->getArtist() << endl;
                     cout << "Publisher: " << database[position] -> getPublisher() << endl;
                     cout << "Duration: " << database[position] -> getDuration() << endl;

	
			}
	
			

		} 


	} 
	} else if(strcmp(inp, "TITLE") == 0) {
		char* name;
		name = new char[100];
		cout << "Enter the title of the media you are looking for:";
		//cin.get(tile,20);
		cin >> name;
		

		    vector<Media*>:: iterator i;
		
                for(i = database.begin(); i != database.end(); i++) {
			
			int position = i - database.begin();
			
                        if(strcmp(database[position] -> getTitle(),name) == 0) {
			match = true;
                        if(database[position]->getType() == 1) {
                                cout << "Found a game" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Publisher: " << database[position] -> getPublisher() << endl;
                        } else if(database[position]->getType() == 2) {
                                 cout << "Found a Movie" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Director: " << database[position] -> getDirector() << endl;
                                cout << "Duration: " << database[position] -> getDuration() << endl;

                        } else if(database[position]->getType() == 3) {
                                 cout << "Found Music" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Artist: " << database[position]->getArtist() << endl;
                                cout << "Publisher: " << database[position] -> getPublisher() << endl;
                                cout << "Duration: " << database[position] -> getDuration() << endl;


                        }

                        } 


                } 
		

	} else {

	cout << "Enter a valid option";
	}

	if(!match) {
		cout << "No media found" << endl;

	}


}


// Function that deltes from vector. Implements search function
void deleteMedia(vector<Media*> &database) {
    cout << "Would you like to delete  by \"YEAR\" or by \"TITLE\"?" << endl;
        char inp[20];
        cin >> inp;
        bool match;

        if(strcmp(inp, "YEAR") == 0) {
                cout << "Enter the year: ";
                int year;
                cin >> year;
                vector<Media*>:: iterator i;
                for(i = database.begin(); i != database.end(); i++) {

                        int position = i - database.begin();
                        if(database[position] -> getYear() == year) {
                                match = true;
                        if(database[position]->getType() == 1) {
                                cout << "Found a game" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Publisher: " << database[position] -> getPublisher() << endl;
                        } else if(database[position]->getType() == 2) {
                                 cout << "Found a Movie" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Director: " << database[position] -> getDirector() << endl;
                                cout << "Duration: " << database[position] -> getDuration() << endl;

                        } else if(database[position]->getType() == 3) {
                                 cout << "Found Music" << endl;
                     cout << "Title: "<< database[position]->getTitle() << endl;
                     cout << "Year: " << database[position]->getYear() << endl;
                   cout << "Artist: " << database[position]->getArtist() << endl;
                     cout << "Publisher: " << database[position] -> getPublisher() << endl;
                     cout << "Duration: " << database[position] -> getDuration() << endl;


                        }
				 
			     cout << "Would you like to delete this media? Enter y or n" << endl;
                                char ans[20];
                                cin >> ans;
                                cout << endl;
                                if(strcmp(ans,"y") == 0) {
                                delete database[position];
                                database.erase(database.begin() + position);
				break;
				 } else if(strcmp(ans,"n") == 0) {


                        } else {
                                cout << "Enter a valid response" << endl;
                        }

		

                }


        }
        } else if(strcmp(inp, "TITLE") == 0) {
                char* name;
                name = new char[100];
                cout << "Enter the title of the media you are looking to delete:";
                //cin.get(tile,20);
                cin >> name;
 vector<Media*>:: iterator i;
                cout << name;
                for(i = database.begin(); i != database.end(); i++) {

                        int position = i - database.begin();
    
                        if(strcmp(database[position] -> getTitle(),name) == 0) {
                        match = true;
                        if(database[position]->getType() == 1) {
                                cout << "Found a game" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Publisher: " << database[position] -> getPublisher() << endl;
                        } else if(database[position]->getType() == 2) {
                                 cout << "Found a Movie" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Rating: " << setprecision(2) << fixed << database[position]->getRating() << endl;
                                cout << "Director: " << database[position] -> getDirector() << endl;
                                cout << "Duration: " << database[position] -> getDuration() << endl;

                        } else if(database[position]->getType() == 3) {
                                 cout << "Found Music" << endl;
                                cout << "Title: "<< database[position]->getTitle() << endl;
                                cout << "Year: " << database[position]->getYear() << endl;
                                cout << "Artist: " << database[position]->getArtist() << endl;
                                cout << "Publisher: " << database[position] -> getPublisher() << endl;
                                cout << "Duration: " << database[position] -> getDuration() << endl;


                        }

			   
				cout << "Would you like to delete this media? Enter y or n" << endl;
				char ans[20];
				cin >> ans;
				cout << endl;
				if(strcmp(ans,"y") == 0) {
				delete database[position];
				database.erase(database.begin() + position);
				break;

			} else if(strcmp(ans,"n") == 0) {
				

			} else {
				cout << "Enter a valid response" << endl;
			}
			
                        }   
			

                }   
    

        } else {

        cout << "Enter a valid option";
        }   

        if(!match) {
                cout << "No media found" << endl;

        }   

}

