#include<iostream>
using namespace std; 

int friends_paring(int n){
    if(n==1 || n==2){
        return n;
    }

    return friends_paring(n-1) + (n-1) * friends_paring(n-2);
}

int main()
{
    cout<<friends_paring(4);

return 0;
}