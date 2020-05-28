
#include <iostream>
#include "node.h"

using namespace std;


class edge {
public:
    edge(char label);
    ~edge();
    void setFirst(node* first);
    void setSecond(node* second);
    node* getFirst();
    node* getSecond();
    
    int getValue();
    void setValue(int value);
    
    
private:
    char label;
    node* first;
    node* second;
    int value;
    
    
    
};

