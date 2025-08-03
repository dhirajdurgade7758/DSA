class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int maxcount=0;
        int i=0, j=0;
        int count=0;

        while(i<arr.size()){
            if(arr[i]<=dep[j]){
                i++;
                count++;
            }
            else{
                j++;
                count--;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
