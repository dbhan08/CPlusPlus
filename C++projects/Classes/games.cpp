#include <iostream>
#include <cstring>
#include "Games.h"

using namespace std;

Games :: Games(char* newTitle, int newYear, float newRating, char* newPublisher) {
	title = newTitle;
	year = newYear;
	rating = newRating;
	publisher = newPublisher;

}


int Games::getType() {

	return 1;

}



char* Games::getTitle() {
return title;

}

int Games::getYear() {
return year;

}



float Games::getRating() {
	return rating;

}

char* Games::getPublisher() {
	return publisher;

}
 
 
Games::~Games() {
	delete &title;
	delete &year;
	delete &rating;
	delete &publisher;
// 	delete &type;


}




