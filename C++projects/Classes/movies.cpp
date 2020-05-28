#include <iostream>
#include <cstring>
#include "Movies.h"

using namespace std;

Movie:: Movie(char* newTitle, char* newDirector, int newYear, float newRating,
 char* newDuration) {

title = newTitle;
director = newDirector;
year = newYear;
rating = newRating;
duration = newDuration;


}

int Movie::getType() {
	return 2;

}

int Movie::getYear() {
	return year;

}

char* Movie::getTitle() {
return title;

}


char* Movie::getDirector() {
	return director;


}



float Movie::getRating() {
return rating;

}


char* Movie::getDuration() {
return duration;

}


Movie::~Movie() {
	delete &title;
	delete &director;
	delete &year;
	delete &rating;	
	delete &duration;
	//delete &type;
	

}
