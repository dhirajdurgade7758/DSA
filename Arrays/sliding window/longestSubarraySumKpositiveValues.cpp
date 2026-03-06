class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        int left = 0, currSum = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (currSum > k && left <= right) {
                currSum -= nums[left];
                left++;
            }

            if (currSum == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};
