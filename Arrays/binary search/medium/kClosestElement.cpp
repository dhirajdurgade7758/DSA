
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare distances of window edges
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 4;
    int x1 = 3;
    vector<int> result1 = sol.findClosestElements(arr1, k1, x1);
    cout << "Test 1: arr = [1,2,3,4,5], k = 4, x = 3" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 4;
    int x2 = -1;
    vector<int> result2 = sol.findClosestElements(arr2, k2, x2);
    cout << "Test 2: arr = [1,2,3,4,5], k = 4, x = -1" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl << endl;
    
    // Test case 3
    vector<int> arr3 = {1, 1, 1, 10, 10, 10};
    int k3 = 1;
    int x3 = 9;
    vector<int> result3 = sol.findClosestElements(arr3, k3, x3);
    cout << "Test 3: arr = [1,1,1,10,10,10], k = 1, x = 9" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}