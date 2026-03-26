#include <iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;        // extract i-th bit
            res = res | (bit << (31 - i)); // place at reversed position
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    Solution obj;
    int result = obj.reverseBits(n);

    cout << "Reversed bits result: " << result << endl;

    return 0;
}