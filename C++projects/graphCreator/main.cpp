#include <iostream>

#include "edge.h"
#include <vector>


using namespace std;

void addVertex(vector<node*> &nodes, char label) {
    
 
    node* temp = new node(label);
    bool there = false;
    vector<node*>:: iterator i;
    for(i=nodes.begin(); i != nodes.end(); i++) {
        
        
        if((*i)->getLabel() == label) {
            
            there = true;
        }
        
    }
    if(!there) {
        nodes.push_back(temp);
        
    } else {
                temp = NULL;
        delete temp;
    }
    
    
}



void addEdge(vector<node*> &nodes,vector<edge*> &edges,char firstLabel, char secondLabel ,char label) {
    edge* temp = new edge(label);
    node* first = NULL;
    node* second = NULL;
    bool there = false;
    
    vector<node*>:: iterator i;
    for(i= nodes.begin(); i != nodes.end(); i++) {
        
        
        if((*i)->getLabel()==firstLabel) {
            first = *i;
            
        } else if((*i)->getLabel()==secondLabel) {
            second = *i;
        }
        
        
    }
    
    if(first != second) {
        vector<edge*>::iterator j;
        for(j=edges.begin(); j != edges.end(); j++) {
            if((*j)->getFirst() == first && (*j)->getSecond() == second) {
                there = true;
            }
        }
        
        if(there) {
            cout << "The edge already exists";
        } else if(first != NULL && second != NULL) {
            temp->setFirst(first);
            temp->setSecond(second);
            edges.push_back(temp);
            
        } else {
            cout << "Some node or nodes don't exist" << endl;
            first = NULL;
            second = NULL;
            temp = NULL;
            delete first;
            delete second;
            delete temp;
        }
        
        
    } else {
        cout <<  "Can't have edge between the same nodes" << endl;
        
        return;
    }
    
    
 
    
    
}


void removeEdge(vector<node*> &nodes,vector<edge*> &edges,char firstLabel, char secondLabel) {
    node* first = NULL;
    node* second = NULL;
    bool exist = false;
    if(edges.empty()) {
        cout << "There are no edges!" << endl;
        return;
    }
    
    vector<node*>:: iterator i;
    for(i= nodes.begin(); i != nodes.end(); i++) {
        
        
        if((*i)->getLabel()==firstLabel) {
            first = *i;
            
        } else if((*i)->getLabel()==secondLabel) {
            second = *i;
        }
        
        
    }

    if(first != second) {
        
        
        vector<edge*>::iterator j;
        for(j=edges.begin(); j != edges.end(); j++) {
            if(((*j)->getFirst() == first && (*j)->getSecond() == second) || ((*j)->getFirst() == second && (*j)->getSecond() == first)) {
                exist = true;
                edges.erase(j);
                first = NULL;
                second = NULL;
                delete first;
                delete second;
                break;
               
             
              
               
            }
        }
        if(!exist) {
            cout << "Some node does not exist!" << endl;
        }
        
    } else {
        
        cout << "They are the same two nodes" << endl;
        
    }
    
   
    
    
    
}

void removeVert(vector<node*> &nodes,vector<edge*> &edges,char label) {
    bool there = false;
    bool hasEdge = false;
    if(nodes.empty()) {
        cout << "No nodes!" << endl;
        return;
    }
    vector<node*>::iterator i;
    vector<edge*>:: iterator k;
    for(i=nodes.begin(); i != nodes.end(); i++) {
        if((*i)->getLabel() == label) {
            there = true;
            for(k=edges.begin(); k!= edges.end(); k++) {
                if((*k)->getFirst() == *i || (*k)->getSecond() == *i) {
                    hasEdge = true;
                    break;
                }
            }
        }
        if(hasEdge && there) {
            removeEdge(nodes,edges,(*k) -> getFirst() -> getLabel(), (*k) -> getSecond() -> getLabel());
            nodes.erase(i);
        } else if(there && !hasEdge) {
            
            nodes.erase(i);
            return;
            

            
        } else{
            cout << "Couldn't find node" << endl;
        }
    }
    
 
    
}

void printadj(vector<node*> &nodes,vector<edge*> &edges) {
    
    
    if(nodes.empty()) {
        cout << "No nodes!" << endl;
        return;
    }
     vector<node*>::iterator i;
    cout << "\t";
    for(i=nodes.begin(); i != nodes.end(); i++) {
        cout << (*i)->getLabel() << "\t";
        
    }
    
    cout << endl;
    vector<node*>::iterator j;
    vector<node*>::iterator k;
    for(j=nodes.begin(); j != nodes.end(); j++) {
        cout<< (*j)->getLabel();
        for(k=nodes.begin(); k != nodes.end(); k++) {
            bool edged = false;
            vector<edge*>:: iterator n;
            for(n=edges.begin(); n!=edges.end(); n++) {
                
                if(((*n)->getFirst() == (*k) && (*n)->getSecond() == (*j)) || ((*n)->getFirst() == (*j) && (*n)->getSecond() == (*k))){
                    edged = true;
                    break;
                }
                
            }
            
            if(edged) {
                cout << "\t1";
            } else {
                cout << "\t0";
            }
            
            
            
        }
        cout << endl;
    }
    
    
    
    
}
                        





int main() {
    bool run = true;
    vector<node*> vertices;
    vector<edge*> edges;
    
    char inp[50];
    char inp2;
    char inp3;
    char inp4;
    
    
    
    while(run) {/*
        cout << "This is a graph creator!" << endl;
        cout << "Enter '1' to add a vertex!" << endl;
        cout << "Enter '2' to add an edge!" << endl;
        cout << "Enter '3' to delete a vertex!" << endl;
        cout << "Enter '4' to delete an edge!" << endl;
        cout << "Enter '5' to  print shortest path!" << endl;
        cout << "Enter 'q' to quit" << endl;
                 */
        cin >> inp;
        cin.clear();
        cin.ignore(100000,'\n');
        if(strcmp("1",inp) == 0) {
            cout << "What value would you like to assign?" << endl;
            cin >> inp2;
            cin.clear();
            cin.ignore(100000,'\n');
           
           // char* label = new char[inp2];
            addVertex(vertices,inp2);
            printadj(vertices,edges);
            
            
        } else if(strcmp("2",inp) == 0) {
            cout << "What is the label of the first vertex" << endl;
            cin >> inp2;
            cin.clear();
            cin.ignore(100000,'\n');
            cout << "What is the label of the second vertex" << endl;
            cin >> inp3;
            cin.clear();
            cout << "What is the label of the edge?" << endl;
            cin >> inp4;
            cin.clear();
            cin.ignore(100000,'\n');
            /*
            char*firstLabel = new char[inp2];
            char*secondLabel = new char[inp3];
            char*label = new char[inp4];
            */
            addEdge(vertices,edges,inp2,inp3,inp4);
            printadj(vertices,edges);
            
        } else if(strcmp("3",inp) == 0) {
            cout << "What vertex would you liike to delete?" << endl;
            cin >> inp2;
            cin.clear();
            cin.ignore(100000,'\n');
           // char* label = new char[inp2];
            removeVert(vertices,edges,inp2);
            printadj(vertices,edges);
            
        } else if(strcmp("4",inp) == 0) {
            cout << "What is the label of the first vertex" << endl;
            cin >> inp2;
            cin.clear();
            cin.ignore(100000,'\n');
            cout << "What is the label of the second vertex" << endl;
            cin >> inp3;
            cin.clear();
           // char* firstLabel = new char[inp2];
           // char* secondLabel = new char[inp3];
            
           removeEdge(vertices,edges,inp2,inp3);
            printadj(vertices,edges);
            
        } else if(strcmp("5",inp) == 0)  {
            // shortest path
            
        } else if(strcmp("q",inp) == 0) {
            run = false;
            
        } else {
            cout << "Enter a valid option!" << endl;
        }
        
    }
    
    
}


