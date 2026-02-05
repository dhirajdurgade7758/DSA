class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // calculating distance
        int n=points.size();
        vector<pair<int, int>> dist;

        for(int i=0; i<n; i++){
            dist.push_back(make_pair(pow(points[i][0], 2) + pow(points[i][1], 2), i));
        }// O(n)


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(dist.begin(), dist.end()); // O(n)

        // getting last k values
        vector<vector<int>> ans;
        while(k>0){//O(K * logn)
            ans.push_back(points[pq.top().second]);
            pq.pop();//O(logn)
            k--;
        }
        return ans;
    }
};