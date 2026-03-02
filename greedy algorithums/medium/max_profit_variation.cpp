#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


class job{
public:
    int indx;
    int deadline;
    int profit;
    
    job(int indx, int deadline, int profit){
        this->indx = indx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs){
    // STEP 1: Convert pairs (deadline, profit) into job objects with index tracking
    vector<job> jobs;
    
    for(int i=0; i<pairs.size(); i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }
    
    // STEP 2: Sort jobs by profit in descending order (greedy - highest profit first)
    sort(jobs.begin(), jobs.end(), [](job a, job b){
        return a.profit > b.profit;
    });
    
    cout<<"job A"<<jobs[0].indx<<endl;
    int profit = jobs[0].profit;  // Start with first job's profit
    int safeDeadline = 2;  // Next available time slot
    
    // STEP 3: Greedily select remaining jobs that meet deadline constraints
    for(int i=1; i<jobs.size(); i++){
        // If job deadline allows scheduling at or before nextslot, select it
        if(jobs[i].deadline >= safeDeadline){
            cout<<"job A"<<jobs[i].indx<<endl;
            profit+=jobs[i].profit;  // Add profit of this job
            safeDeadline++;  // Move to next available time slot
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