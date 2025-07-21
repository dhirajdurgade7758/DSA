#include<iostream>
using namespace std;

int countSub(string str,int count, int i, int j){
    int n=str.size();
    if(j==n){
        i++;
        j=i;
        return 0;
    }
    if(str[i] == str[j]){
        count++;
    }
    int ans = count + countSub(str, count, i, j+1);
    return ans; 
}

int main()
{
    string str = "abcabab";
    cout<<countSub(str, 0, 0, 0);
return 0;
}