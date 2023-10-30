#include "list.h"
#include <iostream>
#include <stdexcept>
using namespace std;


List::List(){

};

List::~List(){
    
};

// Insert an element at the tail of the linked list 
void List::insert(int v){

};

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail(){
    return 1;
};

// Return the size of the linked list 
// Do not count the sentinel elements
int List::get_size(){
    return 1;
}; 

// Return a pointer to the sentinel head of the linked list 
Node* List::get_head(){
    return sentinel_head;
};