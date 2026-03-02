#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // STEP 1: Check digits from right to left (from least significant to most)
        int lastnum = 0;
        while(!num.empty()){
            lastnum = int(num.back());  // Get the last digit

            // STEP 2: If digit is odd, we found the largest odd number
            if(lastnum % 2 != 0){
                return num;
            }
            // STEP 3: Remove even digits from the right until we find an odd digit
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