#include<vector>
#include<iostream>
#include<fstream>
#include<chrono>
#include<string>
#include<cmath>

using namespace std;
#define M 300007
#define ull unsigned long long int

int power(int x, int n){
    int ans = 1;
    while (n > 0) {
        if (n%2 == 1) 
        {
            ans = ans * x;
        }
        x *=x;
        n/=2; 
    }
    return ans;
}

int hash_(std::string id){
    
    // int sum =0;
    // for(int i=0;i< id.length();i++){
    //     if(id[i]=='_'){
    //         continue;
    //     }else{
    //         sum = sum+ id[i];
    //     }
    // }
    // double k=sum;
    // double a= (sqrt(5)-1)/2;
    // double l = floor(202067* (fmod((k*a),1)));
    // int val = l;
    // return val;

    unsigned long long h =0;
    for(int i=0;i<id.size();i++){
        unsigned long long a=int(id[i]);
        ull g=i%5;
        ull t=i%3;
        unsigned long long b= a*(power(11,g))+power(a,t);
        h+= b;


    }
    return h%202067;

    
    // std::string str2 = id.substr(16,6); 
    // int a=stoi(str2);
    // int hash_value=a%100003;
    // return hash_value;
}


int main(){

    ifstream f;
    f.open("test_ids.txt");
    string id;
    vector<bool> reached(M,false);
    unsigned long long cols=0;
    // auto start = chrono::high_resolution_clock::now();
    while(f>>id){
        int i = hash_(id);
        unsigned long long c=0;
        while(reached[(i+c*c*c)%M]){
            cols++;
            c++;
        }
        reached[(i+c*c*c)%M]=true;
    }
    f.close();
        // auto end=chrono::high_resolution_clock::now();
        // auto time = chrono::duration_cast<chrono::microseconds>(end-start);
        // cout<<flush<<"Prime: "<<p<<endl<<"Collisions: "<<cols<<endl<<"Time: "<<time.count();}
    cout<<cols<<endl;

    
    return 0;
}
