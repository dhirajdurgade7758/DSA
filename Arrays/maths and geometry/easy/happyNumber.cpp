#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool helper(int n, unordered_set<int>& seen) {
        if(n == 1) return true;

        if(seen.count(n)) return false; // cycle detected

        seen.insert(n);

        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return helper(sum, seen);
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        return helper(n, seen);
    }
};

int main() {
    Solution obj;
    
    int n;
    cout << "Enter number: ";
    cin >> n;

    if(obj.isHappy(n)) {
        cout << "Happy Number" << endl;
    } else {
        cout << "Not a Happy Number" << endl;
    }

    return 0;
}