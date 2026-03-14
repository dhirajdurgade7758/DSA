#include<iostream>
using namespace std;

int clearRangeOfBits(int n, int i, int j){
    int bitM1 = ~0 << (j + 1);
    // int bitM2 = ~0>>(8-i); // this will not work becuse Undefined Behavior: Shifting a 32-bit integer by 32 or more bits is undefined in C++ according to the standard.
    int bitM2 = (1 << i) - 1;
    int bitMask = bitM1|bitM2;
    int ans = n&bitMask;

    return ans;
}

int main()
{
    cout<<clearRangeOfBits(15,1,3);
return 0;
}