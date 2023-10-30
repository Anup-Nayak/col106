#include <iostream>
#include <stdexcept>
#include "stack_c.h"
using namespace std;

Stack_C::Stack_C(){
    stk = new List();
    stk=stk;
}

Stack_C::~Stack_C(){
    delete stk;

}

void Stack_C::push(int data){
    stk->insert(data);
}

int Stack_C::pop(){
    return stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx){
    if (stk->get_size()<idx+1){
        throw std::runtime_error("Index out of range");
    }
    else{
        Node * temp = stk->get_head();
        Node * y;
        for(int i=0;i<stk->get_size()-idx;i++){
            y = temp->next;
            temp=temp->next;
        }
        return y->get_value();
    }
    

}


int Stack_C::get_element_from_bottom(int idx){
    if(idx+1>stk->get_size()){
        throw std::runtime_error("Index out of range");
    }
    else{
        Node * temp = stk->get_head()->next;
        while(idx!=0){
            temp = temp->next;
            idx--;
        }
        return temp->get_value();
    }
    
    
}

void Stack_C::print_stack(bool top_or_bottom){
    Node * temp = stk->get_head();
    Node * y;
    if(top_or_bottom){
        for(int i=0;i<stk->get_size();i++){
        y = temp->next;
        cout<< y->get_value()<<endl;
        temp=y;

    }
    }
    
}

int Stack_C::add(){
    
    if(stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk->delete_tail();
        int b=stk->delete_tail();
        int c=a+b;
        stk->insert(c);
        return c;
    }
    
}

int Stack_C::subtract(){
    

    if(stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk->delete_tail();
        int b=stk->delete_tail();
        int c=b-a;
        stk->insert(c);
        return c;
    }
}

int Stack_C::multiply(){
    if(stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk->delete_tail();
        int b=stk->delete_tail();
        int c=a*b;
        stk->insert(c);
        return c;
    }
    
}

int Stack_C::divide(){
    
    

    if(stk->get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }else{
        int a=stk->delete_tail();
        int b=stk->delete_tail();
        if(a==0){
            throw runtime_error("Divide by Zero Error");
        }else{
            int c;
            if(a*b<0){
                c=b/a-1;
            }else{
                c=b/a;
            }
            
            stk->insert(c);
            return c;
            
        }
        
        
    }
}

List* Stack_C::get_stack(){
    return stk;
}

int Stack_C::get_size(){
    return stk->get_size();
}