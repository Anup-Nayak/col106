#include <iostream>
#include <string>
using namespace std;

// string reverseString(string str)
// {
//     string ans = "";
//     int len = str.length();
//     int n = len;
//     while(n--)
//         ans+=str[n];
//     return ans;
// }

// string ADD(int *a1, int* a2, int s1, int s2){

//     int borrow = 0;
//     string ansRev = "";

//     for(int i=0;i<s1;i++){
//         if(i<s2){
//             int a = a1[i] - a2[i] - borrow ;
//             if(a<0){
//                 a+=10;
//                 borrow=1;
//             }else{
//                 borrow=0;
//             }
//             ansRev += std::to_string(a);
//         }else{
//             int a = a1[i] - borrow;
//             if(a<0){
//                 a+=10;
//                 borrow=1;
//             }else{
//                 borrow=0;
//             }
//             ansRev += std::to_string(a);
//         }

//     }

//     string unstrippedAns = reverseString(ansRev);

//     int n=0;
//     while(n<ansRev.length() and unstrippedAns[n] == '0'){
//         n++;
//     }

//     string ans="";

//     for(int i=n;i<ansRev.length();i++){
//         ans+=unstrippedAns[i];
//     }
//     if(ans.length()==0){
//         return "0";
//     }
//     return ans;

// };

#include <iostream>

using namespace std;

int *divide_arrays(int arr1[], int arr2[], int size1, int size2)
{
    int *quotient = new int[size1];

    // Initialize the quotient to 0.
    for (int i = 0; i < size1; i++)
    {
        quotient[i] = 0;
    }

    // Divide the dividend array by the divisor array.
    int remainder = 0;
    for (int i = size1 - 1; i >= 0; i--)
    {
        remainder = remainder * 10 + arr1[i];
        for (int j = size2 - 1; j >= 0; j--)
        {
            int quotient_digit = remainder / arr2[j];
            remainder %= arr2[j];
            quotient[i] += quotient_digit;
        }
    }

    // Remove leading zeros from the quotient.
    while (size1 > 0 && quotient[0] == 0)
    {
        size1--;
        for (int i = 0; i < size1; i++)
        {
            quotient[i] = quotient[i + 1];
        }
    }

    return quotient;
}
#include<cmath>
int main()
{

    // string a = "puppy000";
    // a.pop_back();
    // cout<< a;

    int a = -3;
    int b = 4;
    cout<< floor(-19.5);

    // int arr1[] = {1, 2, 3, 4};
    // int arr2[] = {5, 2};
    // int size1 = sizeof(arr1) / sizeof(arr1[0]);
    // int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // int *quotient = divide_arrays(arr1, arr2, size1, size2);

    // for (int i = 0; i < size1; i++)
    // {
    //     cout << quotient[i] << " ";
    // }
    // cout << endl;

    // delete[] quotient;

    // return 0;
}

// int main()
// {

// int arr1[5] = {4,6,5,8,9};
// int arr2[5] = {4,6,5,8,9};

// string ans = ADD(arr1,arr2,5,5);
// string a = "0234";
// cout << (int)a[0]- 48;

//     string s = "467";
//     string a(1, s[1]);

//     cout << stoi(a) + 2;

//     return 0;
// }