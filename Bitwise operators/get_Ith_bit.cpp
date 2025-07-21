#include<iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = 1<<i;
    if(!(n&mask)){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    cout<<getIthBit(6, 2);

return 0;
}