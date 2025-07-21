// #include<iostream>
// using namespace std;

// int main(){
//     int n = 5;
//     int i,j;
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             if(j<=i){
//                 cout<<" ";
//             }
//             else{
//                 cout<<i+1;
//             }
//         }
//         cout<<endl;
//     }
// }

#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            cout<<" ";
        }
        for(int k=0;k<n-i;k++){
            cout<<i+1;

        }
        cout<<endl;
        }
        cout<<endl;
    }
