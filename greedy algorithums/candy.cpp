#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // Initialize sum with 1 candy for the first person
        int sum=1;
        int i=1;
        int n=ratings.size();

        // Traverse through all ratings and handle different cases
        while(i<n){

            // CASE 1: Flat surface - same rating as previous, give minimum 1 candy
            if(ratings[i] == ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }

            // CASE 2: Increasing surface - ratings going up, increase candy count
            int peak=1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++; sum+=peak; i++;
            }

            // CASE 3: Decreasing surface - ratings going down, add decreasing candy counts
            int down=1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum+=down; down++; i++;
            }

            // CASE 4: Handle peak adjustment - ensure peak has max of both increasing and decreasing counts
            if(down > peak){
                sum += down-peak;
            }

        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << "Number of candies needed: " << sol.candy(ratings) << endl;
    return 0;
}