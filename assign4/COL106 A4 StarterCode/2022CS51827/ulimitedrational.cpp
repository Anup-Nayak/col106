/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
// #include<iostream> //REMOVE!!!!!!
#include "ulimitedrational.h"

//checked
int Compare(int* a1, int* a2, int s1, int s2){
    if(s1>s2){
        return 1;
    }else if(s2>s1){
        return -1;
    }else{
        for(int i=0;i<s1;i++){
            if(a1[i]>a2[i]){
                return 1;
            }else if(a1[i]<a2[i]){
                return -1;
            }
        }

    }
    return 0;
}

//checked
UnlimitedInt* HCF (UnlimitedInt* num, UnlimitedInt* denom){
    while (denom->get_sign() != 0){
        UnlimitedInt* temp = denom;
        denom = UnlimitedInt::mod(num, denom);
        num = temp;
    }
    return num;
}


UnlimitedRational::UnlimitedRational(){
    p = new UnlimitedInt();
    q = new UnlimitedInt("1");
};

UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
    p = new UnlimitedInt(num->get_array(), num->get_capacity(), num->get_sign(), num->get_size());
    q = new UnlimitedInt(den->get_array(), den->get_capacity(), den->get_sign(), den->get_size());

    int size1 = p->UnlimitedInt::get_size();
    int size2 = q->UnlimitedInt::get_size();

    int *arr1 = p->UnlimitedInt::get_array();
    int *arr2 = q->UnlimitedInt::get_array();


    if ((size1 == 1 && arr1[0] == 0) && (size2 == 1 && arr2[0] == 0)){
        //do nothing
    }
    else{
        UnlimitedInt *u = HCF(p, q);
        p = p->UnlimitedInt::div(p, u);
        q = q->UnlimitedInt::div(q, u);
        delete u;
    }
};

UnlimitedRational::~UnlimitedRational(){
    delete p;
    delete q;

};

UnlimitedInt* UnlimitedRational::get_p(){
    return p;
};

UnlimitedInt* UnlimitedRational::get_q(){
    return q;
};

string UnlimitedRational::get_p_str(){
    return p->UnlimitedInt::to_string();
}; // Return the numerator as a string

string UnlimitedRational::get_q_str(){
    return q->UnlimitedInt::to_string();
}; // Return the denominator as a string

string UnlimitedRational::get_frac_str(){
    string frac = p->UnlimitedInt::to_string() + "/"+ q->UnlimitedInt::to_string();
    return frac;
}; // Return the rational as "p/q"

// Rational arithmetic operations
UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt *numerator = new UnlimitedInt();
    UnlimitedInt *n1 = new UnlimitedInt();
    UnlimitedInt *n2 = new UnlimitedInt();

    n1 = n1->UnlimitedInt::mul(i1->get_p(), i2->get_q());
    n2 = n2->UnlimitedInt::mul(i1->get_q(), i2->get_p());
    numerator = numerator->UnlimitedInt::add(n1, n2);
    delete n1;
    delete n2;

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->UnlimitedInt::mul(i1->get_q(), i2->get_q());

    UnlimitedRational *sum = new UnlimitedRational(numerator, denominator);
    delete numerator;
    delete denominator;

    return sum;
};

UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt *numerator = new UnlimitedInt();
    UnlimitedInt *n1 = new UnlimitedInt();
    UnlimitedInt *n2 = new UnlimitedInt();

    n1 = n1->UnlimitedInt::mul(i1->get_p(), i2->get_q());
    n2 = n2->UnlimitedInt::mul(i1->get_q(), i2->get_p());
    numerator = numerator->UnlimitedInt::sub(n1, n2);
    delete n1;
    delete n2;

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->UnlimitedInt::mul(i1->get_q(), i2->get_q());

    UnlimitedRational *diff = new UnlimitedRational(numerator, denominator); 

    delete numerator;
    delete denominator;

    return diff;
};

UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->UnlimitedInt::mul(i1->get_q(), i2->get_q());
    UnlimitedInt *numerator = new UnlimitedInt();
    numerator = numerator->UnlimitedInt::mul(i1->get_p(), i2->get_p());

    UnlimitedRational *product = new UnlimitedRational(numerator, denominator);

    delete denominator;
    delete numerator;
    

    return product;
};

UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){

    UnlimitedInt *denominator = new UnlimitedInt();
    denominator = denominator->UnlimitedInt::mul(i1->get_q(), i2->get_p());
    UnlimitedInt *numerator = new UnlimitedInt();
    numerator = numerator->UnlimitedInt::mul(i1->get_p(), i2->get_q());

    UnlimitedRational *quotient = new UnlimitedRational(numerator, denominator);

    delete denominator;
    delete numerator;

    return quotient;
};

// int main(){

//     UnlimitedInt *five = new UnlimitedInt(125);
//     UnlimitedInt *ten = new UnlimitedInt(17);

//     UnlimitedInt *six = new UnlimitedInt(0);
//     UnlimitedInt *seven = new UnlimitedInt(5);

//     UnlimitedRational *num1 = new UnlimitedRational(five, ten);
//     UnlimitedRational *num2 = new UnlimitedRational(six, seven);

//     UnlimitedRational *add = num1->mul(num1, num2);
//     cout << add->get_frac_str() << endl;


//     return 0;
// }