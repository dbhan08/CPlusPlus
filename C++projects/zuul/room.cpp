#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

Room::Room(char* newDescription) {
	description = newDescription;
}

char* Room::getDescription() {
	return description;
}

void Room::setId(int newId) {
	id = newId;

}

int Room::getId() {
	return id;
}

void Room::setExits(map<int, char*> newExits) {

	exits = newExits;
}

map<int, char*>* Room::getExits() {

	return &exits;
}



