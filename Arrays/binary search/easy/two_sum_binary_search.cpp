#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& arr, int left, int right, int key) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binarySearch(arr, left, mid - 1, key);
        }
        else {
            return binarySearch(arr, mid + 1, right, key);
        }
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);

        for (int i = 1; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            int indx1 = binarySearch(numbers, 0, i - 1, complement);

            if (indx1 != -1) {
                ans[0] = indx1 + 1; // 1-based index
                ans[1] = i + 1;
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> result = obj.twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
