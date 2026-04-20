//better solution is to use binary search and find the starting point of the k elements

#include <iostream>
#include <vector>   
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> a, pair<int, int> b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

        for(int i=0; i<arr.size(); i++){
            pq.push({abs(arr[i]-x), arr[i]});
        }
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;

    Solution obj;
    vector<int> result = obj.findClosestElements(arr, k, x);

    cout << "K Closest Elements: ";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}