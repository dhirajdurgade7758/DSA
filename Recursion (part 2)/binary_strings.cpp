#include<iostream>
using namespace std;

void binary_string(int n,int lastbit, string ans){
    if(n == 0){
        cout<<ans<<endl;
        return;
    }
    if (lastbit != 1) // we can't check with n==0 because the string is empty at the first time
    {
        binary_string(n-1,0, ans+'0');
        binary_string(n-1,1, ans+'1');
    }
    else{
        binary_string(n-1,0, ans+'0');
    }
}

int main()
{
    string ans="";
    binary_string(3,0,ans);
return 0;
}