#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        // reverse traversal (like your Python slicing [::-1])
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int digit = (num1[i] - '0') * (num2[j] - '0');

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = digit + res[pos2];

                res[pos2] = sum % 10;
                res[pos1] += sum / 10;
            }
        }

        // convert result to string (skip leading zeros)
        string ans = "";
        for (int num : res) {
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution obj;

    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    string result = obj.multiply(num1, num2);

    cout << "Result: " << result << endl;

    return 0;
}