#include<iostream>
using namespace std;

void updateIthBit(int n, int i, int val){
    //clear Ith bit
    int num = n & (~(1<<i));

    //set Ith bitwith val
    num = num | (val<<i);
    cout<<num;
}

int main()
{
    updateIthBit(7,2,0);

return 0;
}