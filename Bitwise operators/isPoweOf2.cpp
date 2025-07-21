#include<iostream>
using namespace std;

void isPowerOf2(int num){
    if(num & (num-1)){
        cout<<num<<" is not a power of 2";
    }
    else{
        cout<<num<<" is a power of 2";                  
    }
}

int main()
{
    isPowerOf2(32);
return 0;
}