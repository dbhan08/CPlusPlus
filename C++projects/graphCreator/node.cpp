#include "node.h"

#include <iostream>

using namespace std;


node::node(char newLabel) {
    label = newLabel;
    
    
}



char node::getLabel() {
    return label;
    
    
}


node::~node() {
    delete &label;
    
}


void node::setLabel(char newLabel) {
    
    label = newLabel;
    
    
}