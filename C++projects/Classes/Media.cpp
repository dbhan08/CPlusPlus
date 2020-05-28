/*
Following is the Media cpp file which defines functions used
By: Deyvik Bhan
Date: 11/5/19

*/


#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

// Following are definitions of constructors and other functions used
Media:: Media() {


}

char* Media:: getTitle() {
	return title;

}

int Media:: getYear() {
	return year;

} 


 int Media:: getType() {

return 0;

}

char* Media::getPublisher() {
return NULL;

}


float Media::getRating() {
return 0;

}

char* Media::getDuration() {
return NULL;

}


char* Media::getArtist() {
return NULL;

}


char* Media::getDirector() {
return NULL;

}
