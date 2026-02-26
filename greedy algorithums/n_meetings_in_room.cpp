#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        //your code goes here
        int currend = end[0];
        int count = 1;
        int n=start.size();
        for(int i=1; i<n; i++){
            if(start[i] > currend){
                count++;
                currend=end[i];
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << "Maximum meetings that can be scheduled: " << sol.maxMeetings(start, end) << endl;
    return 0;
}