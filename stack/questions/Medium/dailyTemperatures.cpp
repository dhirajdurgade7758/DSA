#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> result = obj.dailyTemperatures(temperatures);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}