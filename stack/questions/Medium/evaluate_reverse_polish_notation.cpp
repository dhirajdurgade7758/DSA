#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string t : tokens) {
            // If operator found
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int second = st.top();  // second operand
                st.pop();
                int first = st.top();   // first operand
                st.pop();

                int exp;
                if (t == "+") {
                    exp = first + second;
                } else if (t == "-") {
                    exp = first - second;
                } else if (t == "*") {
                    exp = first * second;
                } else { // "/"
                    exp = first / second; // integer division
                }

                st.push(exp); // push result back
            } 
            // If operand found
            else {
                st.push(stoi(t));
            }
        }

        return st.top(); // final result
    }
};

int main() {
    Solution obj;

    // Example input: ["2","1","+","3","*"]
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    int result = obj.evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}