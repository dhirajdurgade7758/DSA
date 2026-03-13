#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int i,j;
    char ch = 'A';
    for(i=0;i<n;i++){
        for(j=0;j<i+1;j++){
            cout<<ch;
        }
        ch = ch+1;
        cout<<endl;
    }
}