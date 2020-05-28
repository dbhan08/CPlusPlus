/*
Following is the header file for the child class Movie
By: Deyvik Bhan
Date: 11/5/19

*/


#include <iostream>
#include <cstring>
#include "Media.h"


class Movie : public Media {

public:
Movie(char* title, char* director, int year, float rating, char* duration);
char* getDirector();
float getRating();
char* getDuration();
virtual int getType();
char* getTitle();
int getYear();
~Movie();

private:
char* title;
char* director;
float rating;
char* duration;
int year;



};

