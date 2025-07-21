#include<iostream>
using namespace std;
//by using and operation 
// int clearIthBIt(int n, int i){
//     int bitMask =  ~(1<<i);
//     return (n&bitMask);
// }

//m by doing exor operation
int clearIthBIt(int n, int i){
    int bitMask =  1<<i;
    return (n^bitMask);
}

int main()
{
    cout<<clearIthBIt(6,1);

return 0;
}