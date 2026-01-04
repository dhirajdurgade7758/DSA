#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int posindx = 0;
        int negindx = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negindx] = nums[i];
                negindx += 2;
            } else {
                ans[posindx] = nums[i];
                posindx += 2;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (equal +ve and -ve): ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
