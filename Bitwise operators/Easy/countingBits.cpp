#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            int x = i;
            int countBits = 0;

            while(x > 0) {
                int lastDig = x & 1;   // get last bit
                countBits += lastDig;  // add if 1
                x = x >> 1;            // right shift
            }

            ans.push_back(countBits);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    vector<int> result = obj.countBits(n);

    cout << "Output: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}