#include<iostream>
#include<vector>
using namespace std;

int cantRect(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans =0;

    for(int i=0; i<n; i++){
        ans+=cantRect(i)*cantRect(n-i-1);
    }
    return ans;
}

int main()
{
    for (int i=0; i<6; i++)
    {
        cout<<cantRect(i)<<endl;
    }
    

return 0;
}