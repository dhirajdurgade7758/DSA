#include <iostream>
 
using namespace std;

int main(){
    int i,j,num=3;
    int number = 1;

    for ( i = 0; i < num; i++)
    {
        // char ch = 'A';
        for(j=0;j<num;j++){
            cout<<number;
            number++;

            // cout<<ch;
            // ch = ch + 1; //65 + 1 = 66 = B
        }
        cout<<endl;
    }
    return 0;
    
}