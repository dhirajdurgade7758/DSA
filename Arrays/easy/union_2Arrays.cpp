#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k]) {
                k++;
                nums[k] = nums[i];
            }
        }
        nums.resize(k + 1); // important
        return k + 1;
    }

    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> ans;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++; 
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) ans.push_back(nums1[i++]);
        while (j < nums2.size()) ans.push_back(nums2[j++]);

        removeDuplicates(ans);
        return ans;
    }
};

int main() {
    int n1, n2;

    cout << "Enter size of first sorted array: ";
    cin >> n1;
    vector<int> nums1(n1);

    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of second sorted array: ";
    cin >> n2;
    vector<int> nums2(n2);

    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    Solution sol;
    vector<int> result = sol.unionArray(nums1, nums2);

    cout << "Union of both arrays: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
