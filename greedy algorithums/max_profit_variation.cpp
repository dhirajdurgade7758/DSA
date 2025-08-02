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
    
    vector<job> jobs;
    
    for(int i=0; i<pairs.size(); i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }
    
    sort(jobs.begin(), jobs.end(), [](job a, job b){
        return a.profit > b.profit;
    });
    
    cout<<"job A"<<jobs[0].indx<<endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;
    
    for(int i=1; i<jobs.size(); i++){
        if(jobs[i].deadline >= safeDeadline){
            cout<<"job A"<<jobs[i].indx<<endl;
            profit+=jobs[i].profit;
            safeDeadline++;
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