#include<iostream>
using namespace std;

// int pow(int x, int n){
//     //base case
//     if(n == 1){
//         return x;
//     }
//     return x*pow(x, n-1);
// }

// optimal approch O(n) time comlexity

int pow(int x, int n){
    //base case 
    if(n == 0){
        return 1;
    }

    int halfpow = pow(x, n/2);
    int halfPowSqare = halfpow * halfpow;

    if (n%2 != 0){
        return halfPowSqare * x;
    }
    return halfPowSqare;
    
}
int main()
{
    cout<<pow(2,10);

    return 0;
}