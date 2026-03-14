#include<iostream>
using namespace std;

int setBit(int n, int i){
    int bitMass = 1<<i;
    return (n || bitMass);
}

int main()
{
    cout<<setBit(6,3);

return 0;
}