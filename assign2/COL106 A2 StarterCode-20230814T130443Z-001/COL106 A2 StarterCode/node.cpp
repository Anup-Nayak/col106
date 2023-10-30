#include "node.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Node::Node(bool sentinel){

};   

// Use to construct a regular node
Node::Node(int v, Node* nxt, Node* prv){

};

// Return whether a node is a sentinel node 
// Use it to check if we are at the ends of a list
bool Node::is_sentinel_node(){
    return true;
};

// Return the value of a node
int Node::get_value(){
    return 1;
};