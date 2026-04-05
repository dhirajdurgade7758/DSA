#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        vector<pair<int,int>> dist;

        // calculate squared distance
        for(int i = 0; i < n; i++){
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            dist.push_back({d, i});
        }

        // min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(dist.begin(), dist.end());

        vector<vector<int>> ans;

        while(k > 0){
            ans.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }

        return ans;
    }
};

int main(){

    vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1}};
    int k = 2;

    Solution obj;
    vector<vector<int>> result = obj.kClosest(points, k);

    cout << "K Closest Points:\n";

    for(auto &p : result){
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}