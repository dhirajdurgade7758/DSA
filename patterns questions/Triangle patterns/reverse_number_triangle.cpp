#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}