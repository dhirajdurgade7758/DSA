#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string str1, string str2, vector<vector<int>> &dp){ //O(n*m)
    if(str1.size() == 0 || str2.size() == 0){
        return 0;
    }
    int n=str1.size();
    int m=str2.size();
    if(str1[n-1] == str2[n-1]){
        return 1 + lcs(str1.substr(0, n-1), str2.substr(0, m-1),dp);
    }
    else{
        int ans1 = lcs(str1.substr(0,n-1), str2,dp);
        int ans2 = lcs(str1, str2.substr(0, m-1),dp);
        return max(ans1, ans2);
    }
}

int main()
{
    string str1 = "abcdge";
    string str2 = "abedg";
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    cout<<lcs(str1, str2,dp);

return 0;
}