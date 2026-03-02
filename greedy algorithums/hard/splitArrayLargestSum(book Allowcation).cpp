#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isValid(vector<int>& nums, int n, int k, int maxAllowedPages){
        int students = 1, pages = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > maxAllowedPages){
                return false;
            }

            if(pages + nums[i] <= maxAllowedPages){
                pages += nums[i];
            }
            else{
                students++;
                pages = nums[i];
            }
        }
        return students <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n){
            return -1;
        }

        int st = 0, sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        int end = sum;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isValid(nums, n, k, mid)){
                ans = mid;
                end = mid - 1;   // try smaller maximum
            }
            else{
                st = mid + 1;    // increase limit
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int result = sol.splitArray(nums, k);

    cout << "Minimum largest subarray sum: " << result << endl;

    return 0;
}