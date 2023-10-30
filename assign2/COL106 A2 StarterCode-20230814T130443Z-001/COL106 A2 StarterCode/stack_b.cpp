#include "stack_b.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_B::Stack_B(){
    size=0;
    capacity=1024;
    int* stk[capacity]; 
};



// Destructor
Stack_B::~Stack_B(){
    
}


void Stack_B::push(int data){
    if(size==capacity){
        capacity=capacity*2;
    }
    
    stk[size]=data;
    size+=1;

};

int Stack_B::pop(){
    if(size==0){
        throw runtime_error("Empty Stack");
    }
    int a= stk[size-1];
    size-=1;
    return a;
    if(size==capacity/4){
        capacity=capacity/2;
    }
};

int Stack_B::get_element_from_top(int idx){
    if(size-idx<=0){
        throw runtime_error("Index out of range");
    }
    return stk[size-1-idx];
};

int Stack_B::get_element_from_bottom(int idx){
    if(idx>size-1){
        throw runtime_error("Index out of range");
    }
    return stk[idx];
};

void Stack_B::print_stack(bool top_or_bottom){
    if (size==0){
        
    }else{
        if(top_or_bottom==true){
            for(int j=size-1;j>=0;j--){
                cout<<stk[j]<<endl;
            }
        }else{
            for(int j=0;j<size;j++){
                cout<<stk[j]<<endl;
            }
        }
    }

};

int Stack_B::add(){
    if(size<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk[size-1];
        int b=stk[size-2];
        int c=a+b;
        stk[size-2]=c;
        size-=1;
        return c;
    }
};
int Stack_B::subtract(){
    if(size<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk[size-1];
        int b=stk[size-2];
        stk[size-2]=b-a;
        size-=1;
        return b-a;
    }
};
int Stack_B::multiply(){
    if(size<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk[size-1];
        int b=stk[size-2];
        stk[size-2]=b*a;
        size-=1;
        return b*a;
    }
};
int Stack_B::divide(){
    if(size<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk[size-1];
        int b=stk[size-2];
        if(a==0){
            throw runtime_error("Divide by Zero Error");
        }else{
            if(a*b>=0){
                stk[size-2]=int(b/a);
                size-=1;
                return int(b/a);
            }else{
                stk[size-2]=int(b/a)-1;
                size-=1;
                return int(b/a)-1;
            }
            
        }
        
        
    }
}; 

int* Stack_B::get_stack(){

    return stk;
}; 
int Stack_B::get_size(){
    return size;
};