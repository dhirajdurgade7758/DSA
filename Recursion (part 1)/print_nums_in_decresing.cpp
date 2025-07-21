#include<iostream>
using namespace std;
// for decresing order printing 
// void print(int n){
//     if(n == 0){
//         return;
//     }
//     cout<<n<<" ";
//     print(n-1);
// }

// for incresing order printing
void print(int n){
    if(n == 0){
        return;
    }
    print(n-1);
    cout<<n<<" ";
    
}

int main()
{
    print(20);

    return 0;
}