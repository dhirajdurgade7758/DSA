#include<iostream>
#include<vector>
using namespace std;

    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rightMax(20000,-1);
        vector<int> leftMax(20000,-1);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        int waterTrapped=0;

        for(int i=0; i<n; i++){
            int currwater = min(leftMax[i], rightMax[i]) - height[i];

            if(currwater > 0){
                waterTrapped+=currwater;
            }
        }

        return waterTrapped;
    }

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"maximum water can be trapped is: "<<trap(height)<<endl;

return 0;
}