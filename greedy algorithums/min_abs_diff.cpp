#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size()-1;
        int min_diff=INT_MAX;

        for(int i=0; i<n; i++){
            int abs_diff = abs(arr[i+1]-arr[i]);
            min_diff = min(min_diff, abs_diff);
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(arr[i+1]-arr[i] == min_diff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 1, 3};
    vector<vector<int>> result = sol.minimumAbsDifference(arr);
    cout << "Pairs with minimum abs difference: ";
    for(auto pair : result) {
        cout << "[" << pair[0] << "," << pair[1] << "] ";
    }
    cout << endl;
    return 0;
}

