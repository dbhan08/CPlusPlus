/*
Following is the header file for the music class
By: Deyvik Bhan
Date: 11/5/19
*/


#include <iostream>
#include <cstring>
#include "Media.h"
class music : public Media {

	public:
music(char* title, char* artist, int year, char* duration, char* publisher);

virtual int getType();
 int getYear();
 char* getTitle();
char* getArtist();
 char* getDuration();
 char* getPublisher();
~music();

private:


char* artist;
char* duration;
char* publisher;
int year;
char* title;

};
