#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        vector<int> &A = nums1;
        vector<int> &B = nums2;

        int n = A.size();
        int m = B.size();

        int total = n + m;
        int half = total / 2;

        // Binary search boundaries on A
        int left = 0;
        int right = n;

        while (left <= right) {

            // Partition index for A
            int i = (left + right) / 2 - 1;

            // Partition index for B
            int j = half - i - 2;

            // Edge-safe values
            int Aleft  = (i >= 0) ? A[i] : INT_MIN;
            int Aright = (i + 1 < n) ? A[i + 1] : INT_MAX;
            int Bleft  = (j >= 0) ? B[j] : INT_MIN;
            int Bright = (j + 1 < m) ? B[j + 1] : INT_MAX;

            // Correct partition found
            if (Aleft <= Bright && Bleft <= Aright) {

                // If total length is odd
                if (total % 2 == 1) {
                    return min(Aright, Bright);
                }

                // If total length is even
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            // Move partition left in A
            else if (Aleft > Bright) {
                right = i;
            }
            // Move partition right in A
            else {
                left = i + 2;
            }
        }

        return 0.0; // will never be reached
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << median << endl;

    return 0;
}
