#include<iostream>
using namespace std;

int countSetBits(int n){
    int count = 0;
    while(n > 0){
        // find last digit
        int lastDigit = n&1;
        count += lastDigit;
        n = n>>1;
    }
    return count;
}

int main()
{
    cout<<countSetBits(12);

return 0;
}