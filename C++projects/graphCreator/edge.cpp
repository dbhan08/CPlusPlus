#include "edge.h"

#include <iostream>

using namespace std;



edge::edge(char newLabel) {
    
    label = newLabel;
    value = label -'0';
    first = NULL;
    second = NULL;
    
    
    
}


edge::~edge() {
    
    
    first = NULL;
    second = NULL;
    delete &label;
}



void edge::setFirst(node* newFirst) {
    first = newFirst;
}



void edge::setSecond(node* newSecond) {
    second = newSecond;
}

node* edge::getFirst() {
    return first;
}


node* edge::getSecond() {
    return second;
}




void edge::setValue(int newValue) {
    value = newValue;
}



int edge::getValue() {
    return value;
}