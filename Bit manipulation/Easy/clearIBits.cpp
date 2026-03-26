#include<iostream>
using namespace std;

int clearIBits(int n, int i){
    int bitMask = ~0<<i;
    return n&bitMask;
}

int main()
{
cout<<clearIBits(15,2);
return 0;
}