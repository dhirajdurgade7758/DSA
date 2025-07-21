#include<iostream>
using namespace std;

void permutations(string str, string ans){
    int n=str.size();
    if(n==0){
        cout<<ans<<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        char ch = str[i];
        string nexStr = str.substr(0,i)+str.substr(i+1, n-i-1);
        permutations(nexStr, ans+ch);
    }
   
}

int main()
{
permutations("abc", "");

return 0;
}