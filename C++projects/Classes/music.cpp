#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;


music:: music(char* newTitle, char* newArtist, int newYear, char* newDuration, char* newPublisher) {

	title = newTitle;
	artist = newArtist;
	year = newYear;
	duration = newDuration;
	publisher = newPublisher;

}

int music:: getType() {

	return 3;
}


int music::getYear() {

	return year;
}


char* music::getTitle() {

	return title;
}


char* music::getArtist() {

return artist;
}






char* music::getDuration() {

	return duration;
}




char* music:: getPublisher() {

return publisher;

}



music::~music() {
delete &title;
delete &artist;
delete &year;
delete &duration;
delete &publisher;
// delete &type;

}
