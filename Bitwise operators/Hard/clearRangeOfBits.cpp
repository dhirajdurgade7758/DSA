#include<iostream>
using namespace std;

int clearRangeOfBits(int n, int i, int j){
    int bitM1 = ~0 << (j + 1);// shifting -1 to the left by j+1 will give us a number with all bits set to 1 except the bits from 0 to j which will be set to 0
    int bitM2 = (1 << i) - 1; //substracting 1 from 2^i will give us a number with i bits set to 1 and the rest to 0
    int bitMask = bitM1|bitM2;
    int ans = n&bitMask;

    return ans;
}

int main()
{
    cout<<clearRangeOfBits(15,1,3);
return 0;
}