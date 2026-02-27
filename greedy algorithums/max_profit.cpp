#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs){
    // STEP 1: Sort jobs by profit in descending order (greedy approach - pick highest profit first)
    sort(jobs.begin(), jobs.end(), compare);
    
    int profit = jobs[0].second;  // Start with first job's profit
    int safeDeadline = 2;  // After first job, next available slot is at position 2
    
    // STEP 2: For each remaining job, check if we can fit it in available time slots
    for(int i=1; i<jobs.size(); i++){
        // If job's deadline allows us to schedule it, include it
        if(jobs[i].first >= safeDeadline){
            profit+=jobs[i].second;  // Add this job's profit
            safeDeadline++;  // Move to next available slot
        }
    }
    
    cout<<"maxProfit from jobs is: "<<profit<<endl;
    return profit;
}

int main()
{
    vector<pair<int, int>> pairs(5, make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);
    
    maxProfit(pairs);
return 0;
}


// Max profit from GFG
// class job {
// public:
//     int indx;
//     int deadline;
//     int profit;
    
//     job(int indx, int deadline, int profit){
//         this->indx = indx;
//         this->deadline = deadline;
//         this->profit = profit;
//     }
// };

// class Solution {
// public:
//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
//         int n = profit.size();
//         vector<job> jobs;

//         for (int i = 0; i < n; i++) {
//             jobs.emplace_back(i, deadline[i], profit[i]);
//         }

//         // Sort by profit descending
//         sort(jobs.begin(), jobs.end(), [](job a, job b) {
//             return a.profit > b.profit;
//         });

//         // Find the maximum deadline
//         int maxDeadline = 0;
//         for (auto &j : jobs) {
//             maxDeadline = max(maxDeadline, j.deadline);
//         }

//         // Slot array to track filled time slots (1-based indexing)
//         vector<int> slots(maxDeadline + 1, -1); // -1 indicates empty

//         int count = 0, income = 0;

//         for (auto &j : jobs) {
//             // Try to find a free slot from j.deadline to 1
//             for (int t = j.deadline; t >= 1; t--) {
//                 if (slots[t] == -1) {
//                     slots[t] = j.indx;
//                     count++;
//                     income += j.profit;
//                     break;
//                 }
//             }
//         }

//         return {count, income};
//     }
// };
