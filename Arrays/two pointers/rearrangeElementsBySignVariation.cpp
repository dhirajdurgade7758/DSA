#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Variation: positives and negatives may NOT be equal
        int n = nums.size();
        vector<int> pos, neg;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        if(pos.size() > neg.size()){
            for(int i = 0; i < neg.size(); i++){
                nums[i*2] = pos[i];
                nums[i*2 + 1] = neg[i];
            }
            int indx = neg.size() * 2;
            for(int i = neg.size(); i < pos.size(); i++){
                nums[indx++] = pos[i];
            }
        }
        else {
            for(int i = 0; i < pos.size(); i++){
                nums[i*2] = pos[i];
                nums[i*2 + 1] = neg[i];
            }
            int indx = pos.size() * 2;
            for(int i = pos.size(); i < neg.size(); i++){
                nums[indx++] = neg[i];
            }
        }
        return nums;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
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
