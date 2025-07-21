#include<iostream>
#include<vector>
#include<string>
using namespace std;

  void solve(string digits,vector<string> map, int index, string output, vector<string>& ans){
        if(index >= digits.size() ){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = map[number];
        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(digits, map, index+1, output, ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) { 
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        solve(digits, map, 0, "", ans);
        return ans;
    }

int main()
{
    vector<string> ans = letterCombinations("2345");
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

return 0;
}