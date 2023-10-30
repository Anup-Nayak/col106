#include "list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

List::List(){
	size=0;
	sentinel_head = new Node(true);
	sentinel_tail = new Node(true);
	sentinel_head->next = sentinel_tail;
	sentinel_tail->prev = sentinel_head;
	sentinel_head->prev = nullptr;
	sentinel_tail->next = nullptr;
};

List::~List(){
	Node * temp = sentinel_head->next;
	Node * temp2;
	while (temp->is_sentinel_node()==false){
		temp2 = temp->next;
		free(temp);
		temp=temp2;
	}
	delete[] sentinel_head;
	sentinel_head=nullptr;
	delete[] sentinel_tail;
	sentinel_tail=nullptr;
};

// Insert an element at the tail of the linked list 
void List::insert(int v){
	
	Node * temp = sentinel_tail->prev;
	Node * n = new Node(v,sentinel_tail,temp);
	if(!n){
		throw runtime_error("Out of Memory");
	}else{
		temp->next = n;
		sentinel_tail->prev = n;
		size++;
	}
	
};

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail(){
	if(size==0){
		throw std::runtime_error("Empty Stack");
	}
	else{
		Node * temp = sentinel_tail->prev;
		int a = temp->get_value();
		Node * temp2 = temp->prev;
		temp2->next = sentinel_tail;
		sentinel_tail->prev = temp2;
		// delete[] temp;
		size--;
		delete temp;
		return a;
	}
	
};

// Return the size of the linked list 
// Do not count the sentinel elements
int List::get_size(){
    return size;
}; 

// Return a pointer to the sentinel head of the linked list 
Node* List::get_head(){
    return sentinel_head;
};
