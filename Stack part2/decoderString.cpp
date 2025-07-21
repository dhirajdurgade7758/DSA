#include<iostream>
#include<string>
#include<stack>
using namespace std;

string decodeString(string s) {
    stack<int> numst;
    stack<string> strst;
    string ans = "";
    int num = 0;  // Initialize num to accumulate digits

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // Accumulate the number for multi-digit support
        } else if (ch == '[') {
            numst.push(num);  // Push the accumulated number onto the stack
            num = 0;  // Reset num for the next number
            strst.push("[");  // Mark the start of a substring
        } else if (ch == ']') {
            string temp = "";
            // Build the string between the brackets
            while (!strst.empty() && strst.top() != "[") {
                temp = strst.top() + temp;
                strst.pop();
            }
            strst.pop();  // Pop the '['

            // Retrieve the repetition count and repeat the string
            int repeatCount = numst.top();
            numst.pop();
            
            string repeated = "";
            for (int i = 0; i < repeatCount; i++) {
                repeated += temp;
            }
            strst.push(repeated);  // Push the expanded string back to the stack
        } else {
            strst.push(string(1, ch));  // Push the character onto the stack
        }
    }

    // Construct the final result by concatenating all parts in the stack
    while (!strst.empty()) {
        ans = strst.top() + ans;
        strst.pop();
    }

    return ans;
}

int main()
{
    string str = "3[a]2[bc]";
    string decodedstr = decodeString(str);
    cout<<decodedstr<<endl;

return 0;
}





// class Solution {
// public:
//     string decodeString(string s) {
//         stack<int> numst;
//         stack<string> strst;
//         string ans = "";
//         for(char ch : s){
//             if (isdigit(ch)){
//                 numst.push(numst.top() * 10 + (ch - '0'));
//             }
//             else{
//                 if(ch == ']'){
//                     string temp="", temp1="";
//                     while(strst.top() != "["){
//                         temp += strst.top();
//                         strst.pop();
//                     }
//                     strst.pop();
//                     cout<<numst.top()<<"...................";
//                     for(int i=0; i<numst.top(); i++){
//                         temp1 += temp;
//                     }
//                     numst.pop();
//                     reverse(temp1.begin(), temp1.end());
//                     strst.push(temp1);
//                 }

//                 else{
//                     strst.push(string(1, ch)); 
//                 }
//             }
//         }

//         while (!strst.empty()) {
//             ans = strst.top() + ans;
//             strst.pop();
//         }
// return ans;

//     }
// };
