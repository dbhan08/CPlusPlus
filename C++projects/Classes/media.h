/*
Following is the header file for the parent class Media
By:Deyvik Bhan
Date: 11/5/19
*/



#include <iostream>
// media.h

#ifndef MEDIA_H
#define MEDIA_H
using namespace std;

class Media {


public:
Media();

virtual char* getTitle();
virtual int getType();
virtual char* getPublisher();
virtual char* getArtist();
virtual char* getDirector(); 

virtual float getRating();
virtual char* getDuration();
virtual int getYear();

private:

	int year;
	char* title;



};

#endif
