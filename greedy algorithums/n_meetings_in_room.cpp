class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
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