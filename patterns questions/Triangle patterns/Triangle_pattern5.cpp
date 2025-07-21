#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int i,j;
    int num = 1;
    for(i=0;i<n;i++){
        for(j=0;j<i+1;j++){
            cout<<num;
            num++;
        }
        cout<<endl;
    }
}