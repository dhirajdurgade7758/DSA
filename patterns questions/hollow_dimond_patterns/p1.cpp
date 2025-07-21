#include<iostream>
using namespace std;

int main(){
    int n = 4;
    int i,j;
    for(i=0;i<n;i++){
        for(j=1;j<=n-i-1;j++){
            cout<<" ";           
        }
        cout<<"*";
        if(i!=0){
            for(j=1;j<=2*i-1;j++){
                cout<<" ";
             }
        }
        if(i>0){
            cout<<"*";
        }
        cout<<endl;
    }

//Bottom
    for(i=0;i<n-1;i++){
        //space
        for(j=1;j<=i+1;j++){
            cout<<" ";           
        }
        cout<<"*";

        if(i != n-2){
            //space
        for(j=0;j<2*(n-2-i)-1;j++){
            cout<<" ";
        }
        cout<<"*";
        }
        cout<<endl;
    }
}