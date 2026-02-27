#include<iostream>
#include<vector>
using namespace std;

int MaxActivities(vector<int> start, vector<int> end){
    // STEP 1: Initialize with first activity (assuming input is pre-sorted by end time)
    int count = 1;
    int currEnd = end[0];  // Track the end time of last selected activity
    cout<<"selecting A0"<<endl;
    
    // STEP 2: Greedy approach - select activities that start after previous one ends
    for(int i=1; i<start.size(); i++){
        // If activity starts after or when current one ends, we can select it
        if(start[i] >= currEnd){
            cout<<"selecting A"<<i<<endl;
            count++;  // Increment activity count
            currEnd = end[i];  // Update the end time of last selected activity
        }
    }
    return count;
}

int main()
{
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    
    cout<<MaxActivities(start, end);

return 0;
}