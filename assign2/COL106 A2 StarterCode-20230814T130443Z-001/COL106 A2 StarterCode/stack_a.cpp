#include "stack_a.h"
#include <iostream>
#include <stdexcept>
using namespace std;




Stack_A::Stack_A(){
    size=0;
}
void Stack_A::push(int data){
    if(size==1024){
        throw runtime_error("Stack Full");
    }
    else{
        stk[size]=data;
        size+=1;

    }
    
};

int Stack_A::pop(){
    if(size==0){
        throw runtime_error("Empty Stack");
    }
    int a= stk[size-1];
    size-=1;
    return a;
};

int Stack_A::get_element_from_top(int idx){
    if(size-idx<=0){
        throw runtime_error("Index out of range");
    }
    return stk[size-1-idx];
};

int Stack_A::get_element_from_bottom(int idx){
    if(idx>size-1){
        throw runtime_error("Index out of range");
    }
    return stk[idx];
};

void Stack_A::print_stack(bool top_or_bottom){
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

int Stack_A::add(){
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

int Stack_A::subtract(){
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

int Stack_A::multiply(){
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

int Stack_A::divide(){
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

int* Stack_A::get_stack(){
    return stk;
}; 

int Stack_A::get_size(){
    return size;
}; 

// int main(){
//     Stack_A o;
//     o.push(1);
//     o.push(2);
//     o.push(4);
//     o.add();
//     o.print_stack(true);
//     o.pop();
//     o.pop();
//     o.pop();
// }