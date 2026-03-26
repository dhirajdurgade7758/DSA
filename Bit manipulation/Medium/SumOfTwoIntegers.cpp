#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int temp = (a & b) << 1; // carry
            a = a ^ b;               // sum without carry
            b = temp;                // carry becomes new b
        }
        return a;
    }
};

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    Solution obj;
    int result = obj.getSum(a, b);

    cout << "Sum is: " << result << endl;

    return 0;
}