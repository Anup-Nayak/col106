/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include<iostream> // YAAD SE HATANA HAI !!!!
#include "ulimitedint.h"

//checked.. sign ke bina hona chaiye string
int* GETARRAY(string s){
    int w = s.size();
    int* ans = new int[w];
    for (int i = 0; i < w; i++){
            ans[i] = (int)s[i] - 48;
        }
    return ans;
}

//checked
string reverseString(string str){
    string ans = "";
    int len = str.length();
    int n = len;
    while(n--)
        ans+=str[n];
    return ans;
}

//checked
void REVERSE(int* arr, int size) {
    if (size <= 1) {
        return; 
    }

    int* start = arr;         
    int* end = arr + size - 1; 
    while (start < end) {
        
        int temp = *start;
        *start = *end;
        *end = temp;

        
        start++;
        end--;
    }
}

//if a1>a2 returns 1 
//if a1<a2 returns -1
//if they are equal returns 0
//compares magnitude

//checked
int compare(int* a1, int* a2, int s1, int s2){
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

//storing digits in actual order


//s1>=s2(assumption)
//checked
string ADD(int* a1, int* a2, int s1, int s2){

    int carry = 0;
    string ansRev = "";

    REVERSE(a1,s1);
    REVERSE(a2,s2);

    for(int i=0;i<s1;i++){
        if(i<s2){
            int a = a1[i] + a2[i] + carry;
            carry = a/10;
            int sum = a%10;
            ansRev += std::to_string(sum);
        }else{
            int a = a1[i] + carry;
            carry = a/10;
            int sum = a%10;
            ansRev += std::to_string(sum);
        }

    }
    if(carry!=0){
        ansRev += std::to_string(carry);
    }
    string ans = reverseString(ansRev);
    return ans;

};

//s1>=s2(assumption)
//(a1-a2) kar rahe hai

//CHECKED
string SUBTRACT(int* a1, int* a2, int s1, int s2){

    int borrow = 0;
    string ansRev = "";

    REVERSE(a1,s1);
    REVERSE(a2,s2);

    for(int i=0;i<s1;i++){
        if(i<s2){
            int a = a1[i] - a2[i] - borrow ;
            if(a<0){
                a+=10;
                borrow=1;
            }else{
                borrow=0;
            }
            ansRev += std::to_string(a);
        }else{
            int a = a1[i] - borrow;
            if(a<0){
                a+=10;
                borrow=1;
            }else{
                borrow=0;
            }
            ansRev += std::to_string(a);
        }

    }
    
    string unstrippedAns = reverseString(ansRev);
    int n=0;
    int w = ansRev.length();
    while(n<w and unstrippedAns[n] == '0'){
        n++;
    }

    string ans="";
    

    for(int i=n;i<w;i++){
        ans+=unstrippedAns[i];
    }

    if(ans.length()==0){
        return "0";
    }

    return ans;

};

string MULTIPLY(int* a1, int* a2, int s1, int s2){

    int ans[s1+s2] = {0};



    for (int i = s1 - 1; i >= 0; i--) {
        int carry = 0;
        int digit1 = a1[i];

        for (int j = s2 - 1; j >= 0; j--) {
            int digit2 = a2[j];
            int product = digit1 * digit2 + ans[i+j+1] + carry;

            carry = product / 10;
            ans[i+j+1] = product % 10;
        }

        ans[i] += carry;
    }

    // Remove leading zeros
    int i = 0;
    while (i < s1+s2-1 && ans[i] == 0) {
        i++;
    }
    
    string product= "";
    for(int j=i;j<s1+s2;j++){
        product += std::to_string(ans[j]);
    }
    if(product == "-0"){
        return "0";
    }
    return product;
}


UnlimitedInt::UnlimitedInt(){
    size = 1;
    capacity = 1;
    sign = 0;
    
    unlimited_int = new int[1];
    unlimited_int[0] = 0;
};

UnlimitedInt::UnlimitedInt(string s){

    if(s.size()==1 and s[0]=='0'){
        unlimited_int = new int[0];
        unlimited_int[0] = 0;
        sign = 0;
        size = 1;
        capacity = 1;
    }

    else if (s[0] == '-'){
        sign = -1;
        size = s.size() - 1;
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 0; i < size; i++){
            unlimited_int[i] = (int)s[i+1] - 48;
        }
    }
    else{
        sign = 1;
        size = s.size();
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 0; i < size; i++){
            unlimited_int[i] = (int)s[i] - 48;
        }
        
    }

}; // Create from string 

UnlimitedInt::UnlimitedInt(int i){

    string s = std::to_string(i); 

    if(s.size()==1 and s[0]=='0'){
        unlimited_int = new int[0];
        unlimited_int[0] = 0;
        sign = 0;
        size = 1;
        capacity = 1;
    }

    if (s[0] == '-'){
        sign = -1;
        size = s.size() - 1;
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 0; i < size; i++){
            unlimited_int[i] = (int)s[i+1] - 48;
        }
    }
    else{
        sign = 1;
        size = s.size();
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 0; i < size; i++){
            unlimited_int[i] = (int)s[i] - 48;
        }
        
    }
    

}; // Create from int

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
    capacity = cap;
    size = sz;
    sign = sgn;
    unlimited_int = new int[size];

    for (int i = 0; i < size; i++){
        unlimited_int[i] = ulimited_int[i];
    }
}; // Complete constructor

UnlimitedInt::~UnlimitedInt(){
    
    delete unlimited_int;
};

// Return the size of the unlimited int
int UnlimitedInt::get_size(){
    return size;
};

// Return the unlimited_int array
int* UnlimitedInt::get_array(){
    return unlimited_int;
}; 

// Get sign
int UnlimitedInt::get_sign(){
    return sign;
};

// Get capacity 
int UnlimitedInt::get_capacity(){
    return capacity;
};

// Implement these integer operations as they are defined for integers in mathematics
// (Since there are no size restrictions)

UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){

    int size1 = i1->get_size();
    int size2 = i2->get_size();

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    UnlimitedInt *a1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), sign1, size1);
    UnlimitedInt *a2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), sign2, size2);

    int* arr1 = a1->get_array();
    int* arr2 = a2->get_array();


    
    int comparison = compare(arr1, arr2, size1, size2);

    if(sign1==0 and sign2==0){
        UnlimitedInt *ad = new UnlimitedInt("0");
        return ad;
    }

    if(comparison == 0){
        if((sign1 == 1 and sign2 == -1) or (sign1 == -1 and sign2 == 1)){
            UnlimitedInt *ad = new UnlimitedInt("0");
            return ad;
        }

    }
    if(comparison == 1){  //magnitude of arr1 > arr2

        if(sign1 == 1 and sign2 == 1){
            //addition
            string ans = ADD (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;


        }else if(sign1 == -1 and sign2 == -1){
            //addition
            string ans = ADD (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;

        }else if(sign1 == 1 and sign2 == -1){
            //subtraction
            string ans = SUBTRACT (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;

        }else if(sign1 == -1 and sign2 == 1){
            //subtraction
            string ans = SUBTRACT (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;
            
        }else if(sign1 ==0){
            //return a2
            return i2;
        }else if(sign2==0){
            // return a1
            return i1;
        }

    }else{

        if(sign1 == 1 and sign2 == 1){
            //addition
            string ans = ADD (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;


        }else if(sign1 == -1 and sign2 == -1){
            //addition
            string ans = ADD (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;

        }else if(sign1 == 1 and sign2 == -1){
            //subtraction
            string ans = SUBTRACT (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;

        }else if(sign1 == -1 and sign2 == 1){
            //subtraction
            string ans = SUBTRACT (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;
            
        }else if(sign1 == 0){
            //return a2
            return i2;
        }else if(sign2 == 0){
            // return a1
            return i1;
        }

    }

    UnlimitedInt *ad = new UnlimitedInt("0");
    return ad;
    



};

UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){

    int size1 = i1->get_size();
    int size2 = i2->get_size();

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    UnlimitedInt *a1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), sign1, size1);
    UnlimitedInt *a2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), sign2, size2);

    int* arr1 = a1->get_array();
    int* arr2 = a2->get_array();


    if(sign1==0 and sign2==0){
        UnlimitedInt *ad = new UnlimitedInt("0");
        return ad;
    }

    int comparison = compare(arr1, arr2, size1, size2);

    if(comparison == 0){
        UnlimitedInt *ad = new UnlimitedInt("0");
        return ad;
    }

    else if(comparison == 1){  //magnitude of arr1 > arr2

        if(sign1 == 1 and sign2 == 1){
            //addition
            string ans = SUBTRACT (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;

        }else if(sign1 == -1 and sign2 == -1){
            //addition
            string ans = SUBTRACT (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;

        }else if(sign1 == 1 and sign2 == -1){
            //subtraction
            string ans = ADD (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;

        }else if(sign1 == -1 and sign2 == 1){
            //subtraction
            string ans = ADD (arr1,arr2,size1,size2);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;
            
        }else if(sign1 == 0 and sign2 == 1){
            //return a2
            UnlimitedInt *ad = new UnlimitedInt(arr2, size2, -1, size2);
            return ad;

        }else if(sign1 == 0 and sign2 == -1){
            //return a2
            UnlimitedInt *ad = new UnlimitedInt(arr2, size2, 1, size2);
            return ad;

        }else if(sign2==0){
            // return a1
            return i1;
        }

    }else{

        if(sign1 == 1 and sign2 == 1){
            //addition
            string ans = SUBTRACT (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;


        }else if(sign1 == -1 and sign2 == -1){
            //addition
            string ans = SUBTRACT (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;

        }else if(sign1 == 1 and sign2 == -1){
            //subtraction
            string ans = ADD (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
            return ad;

        }else if(sign1 == -1 and sign2 == 1){
            //subtraction
            string ans = ADD (arr2,arr1,size2,size1);
            int size = ans.size();
            int * answer = GETARRAY(ans);
            UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
            return ad;
            
        }else if(sign1 == 0 and sign2 == 1){
            //return a2
            UnlimitedInt *ad = new UnlimitedInt(arr2, size2, -1, size2);
            return ad;

        }else if(sign1 == 0 and sign2 == -1){
            //return a2
            UnlimitedInt *ad = new UnlimitedInt(arr2, size2, 1, size2);
            return ad;
        }else if(sign2 == 0){
            // return a1
            return i1;
        }

    }
    UnlimitedInt *ad = new UnlimitedInt("0");
    return ad;
};

UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){

    int size1 = i1->get_size();
    int size2 = i2->get_size();

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    UnlimitedInt *a1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), sign1, size1);
    UnlimitedInt *a2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), sign2, size2);

    int* arr1 = a1->get_array();
    int* arr2 = a2->get_array();


    if(sign1==0 or sign2==0){
        UnlimitedInt *ad = new UnlimitedInt("0");
        return ad;

    }else if((sign1==1 and sign2==1) or (sign1==-1 and sign2==-1)){
        string ans = MULTIPLY(arr1,arr2,size1,size2);
        int size = ans.size();
        int * answer = GETARRAY(ans);
        UnlimitedInt *ad = new UnlimitedInt(answer, size, 1, size);
        return ad;

    }else if((sign1== -1 and sign2 ==1)or (sign1 == 1 and sign2 == -1)){
        string ans = MULTIPLY(arr1,arr2,size1,size2);
        int size = ans.size();
        int * answer = GETARRAY(ans);
        UnlimitedInt *ad = new UnlimitedInt(answer, size, -1, size);
        return ad;
    }
    UnlimitedInt *ad = new UnlimitedInt("0");
    return ad;

};

// UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){

//     int s1= i1->get_size();
//     int s2= i2->get_size();

//     int* arr1 = i1->get_array();
//     int* arr2 = i2->get_array();

//     int sign1 = i1->get_sign();
//     int sign2 = i2->get_sign();

//     if(sign2 == 0){
//         UnlimitedInt *zero = new UnlimitedInt(0);
//         return zero;
//     }

//     if (sign1 == 0 && sign2 == 0){
//         UnlimitedInt *zero = new UnlimitedInt(0);
//         return zero;
//     }
//     UnlimitedInt *one = new UnlimitedInt(1);
//     if (compare(arr2, arr1,s2,s1) == 1){
//         if ((i1->get_sign()) * (i2->get_sign()) != -1){
//             UnlimitedInt *zero = new UnlimitedInt(0);
//             return zero;
//         }
//         else{
//             UnlimitedInt *minus_one = new UnlimitedInt(-1);
//             return minus_one;
//         }
//     }
//     else if (compare(arr2, arr1,s2,s1) == 0){
//         UnlimitedInt *result = one;
//         result->sign = (i1->get_sign() * i2->get_sign());
//         return result;
//     }
//     UnlimitedInt *result = new UnlimitedInt();
//     UnlimitedInt *dividend = new UnlimitedInt(i1->unlimited_int, i1->capacity, 1, i1->size);
//     UnlimitedInt *divisor = new UnlimitedInt(i2->unlimited_int, i2->capacity, 1, i2->size);
    

//     while (sub(dividend, divisor)->sign > 0){
//         dividend = sub(dividend, divisor);
//         result = add(result, one);
//     }

//     if ((sign1) * (sign2) == -1 && sub(dividend, divisor)->sign == -1){
//         result = add(result, one);
//     }

//     if (sub(dividend, divisor)->sign == 0){
//         result = add(result, one);
//     }

//     result->sign = sign1*sign2;
//     return result;
// };

UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){

    int s1= i1->get_size();
    int s2= i2->get_size();

    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();

    int sign1 = i1->get_sign();
    int sign2 = i2->get_sign();

    if(sign2 == 0){
        UnlimitedInt *zero = new UnlimitedInt(0);
        return zero;
    }
    if(sign1 == -1 and s1==1 and arr1[0]==0 ){
        UnlimitedInt *zero = new UnlimitedInt(0);
        return zero;
    }
    if (sign1 == 0 && sign2 == 0){
        UnlimitedInt *zero = new UnlimitedInt(0);
        return zero;
    }
    UnlimitedInt *one = new UnlimitedInt(1);
    if (compare(arr2, arr1,s2,s1) == 1){
        if ((i1->get_sign()) * (i2->get_sign()) != -1){
            UnlimitedInt *zero = new UnlimitedInt(0);
            return zero;
        }
        else{
            UnlimitedInt *minus_one = new UnlimitedInt(-1);
            return minus_one;
        }
    }
    else if (compare(arr2, arr1,s2,s1) == 0){
        UnlimitedInt *result = one;
        result->sign = (i1->get_sign() * i2->get_sign());
        return result;
    }

    UnlimitedInt *result = new UnlimitedInt();
    UnlimitedInt *dividend = new UnlimitedInt(i1->unlimited_int, i1->capacity, 1, i1->size);
    UnlimitedInt *divisor = new UnlimitedInt(i2->unlimited_int, i2->capacity, 1, i2->size);
    

    int ss1 = dividend->get_size();
    int ss2 = divisor ->get_size();

    string dv = divisor->to_string();
    UnlimitedInt *ten = new UnlimitedInt(10);
    string po =  one->to_string();
    for(int i =0; i< ss1-ss2-1; i++){
        dv+="0";
        po+="0";
    }
    UnlimitedInt* DV = new UnlimitedInt(dv);
    UnlimitedInt* POWER = new UnlimitedInt(po);


    while(sub(POWER,one)->sign >= 0){

        while(sub(dividend,DV)->sign >=0 ){
        dividend = sub(dividend,DV);
        result = add(result,POWER);
        }

        dv.pop_back();
        po.pop_back();

        UnlimitedInt* DV1 = new UnlimitedInt(dv);
        DV = DV1;
        UnlimitedInt* POWER1 = new UnlimitedInt(po);
        POWER = POWER1;


    }

    if ((sign1) * (sign2) == -1 && dividend->get_sign() !=0  && sub(dividend, divisor)->sign == -1){
        result = add(result, one);
    }

    if (sub(dividend, divisor)->sign == 0){
        result = add(result, one);
    }

    result->sign = sign1*sign2;
    delete DV;
    delete POWER;
    delete one;
    delete ten;
    delete dividend;
    delete divisor;

    return result;
};

UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){

    UnlimitedInt *a1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), i1->get_sign(), i1->get_size());
    UnlimitedInt *a2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), i2->get_sign(), i2->get_size());

    if(i2->get_sign()==0){
        UnlimitedInt *mod = new UnlimitedInt(i1->get_array(), i1->get_capacity(), 1, i1->get_size());
        return mod;
    }

    UnlimitedInt *quotient = div(a1, a2);
    UnlimitedInt *product = mul(quotient, a2);
    UnlimitedInt *mod = sub(a1, product); 

    delete a1;
    delete a2;
    delete quotient;
    delete product;

    return mod;
};

// Conversion Functions 
// most important
string UnlimitedInt::to_string(){
    string result = "";
    if(sign==0){
        return "0";
    }
    else if(sign== -1 and size==1 and unlimited_int[0]==0){
        return "0";
    
    }else if(sign == -1){
        result += "-";
    }

    for(int i=0;i<size;i++){
        result+= std::to_string(unlimited_int[i]);
    }
    return result;
};

int main(){
    UnlimitedInt a("-2");
    UnlimitedInt b("10");
    UnlimitedInt* c = UnlimitedInt::mod(&a,&b);
    cout << c->to_string();
}
    // string s1 = "6";
    // string s2 = "3";
    // int size1 = s1.size();
    // int size2 = s2.size();
    // int *arr1 = GETARRAY(s1);
    // int *arr2 = GETARRAY(s2);

    // REVERSE(arr,size);
    // for(int i=0;i<s1.size();i++){
    //     cout<< arr1[i] << " ";
    // }
    // cout<< endl;
    // for(int i=0;i<s2.size();i++){
    //     cout<< arr2[i] << " ";
    // }
    // cout<<endl;
    // int a = compare(arr1,arr2,size1,size2);
    // cout<< a;

    // string ans = MULTIPLY(arr1,arr2,size1,size2);
    // cout<< ans;

    // string a = reverseString(s);
    // cout<< a;
// }
