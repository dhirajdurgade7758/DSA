#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
       int lastnum = 0;
        while(!num.empty()){
            lastnum = int(num.back());

            if(lastnum % 2 != 0){
                return num;
            }
            else{
                num.pop_back();
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    string num = "52";
    cout << "Largest odd number from " << num << ": " << sol.largestOddNumber(num) << endl;
    
    string num2 = "4206";
    cout << "Largest odd number from " << num2 << ": " << sol.largestOddNumber(num2) << endl;
    return 0;
}