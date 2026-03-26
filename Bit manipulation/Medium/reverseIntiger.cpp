#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int MIN = INT_MIN;
        int MAX = INT_MAX;

        int res = 0; 
        while (x != 0) {
            int digit = x % 10;
            x = x / 10;

            if (res > (MAX / 10) || (res == (MAX / 10) && digit >= (MAX % 10))) {
                return 0;
            }

            if (res < (MIN / 10) || (res == (MIN / 10) && digit <= (MIN % 10))) {
                return 0;
            }

            res = (res * 10) + digit;
        }
        return res;
    }
};

int main() {
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    Solution obj;
    int result = obj.reverse(x);

    cout << "Reversed integer: " << result << endl;

    return 0;
}