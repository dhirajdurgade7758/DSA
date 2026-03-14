#include<iostream>
using namespace std;

int fastExponentiation(int x, int n){
    int ans = 1;
    while(n>0){
        int lastBit = n&1;
        if(lastBit){
            ans *= x;
        }
        x *= x;

        n = n>>1;
    }
    return ans;

}

int main()
{
    cout<<fastExponentiation(3,5);

return 0;
}