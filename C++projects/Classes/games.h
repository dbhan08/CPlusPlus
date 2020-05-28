/*
Following is the header file for the Games class
By: Deyvik Bhan
Date: 11/5/19
*/
// Games.h

#ifndef Games_H
#define Games_H


#include <iostream>
#include <cstring>
#include "Media.h"
// Follwing defines the game class
class Games : public Media {

	public:
	Games(char* title, int year, float rating, char* publisher);
	
	virtual int  getType();
	
	
	float getRating();
	char* getPublisher();
	char* getTitle();
	int getYear();	
	~Games();
	private:
	char* title;
	int year;	
	float rating;
	char* publisher;
	

};

#endif
