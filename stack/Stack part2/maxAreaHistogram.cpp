#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void maxAreaHistogram(vector<int> heights){

    int n = heights.size();
    //next smaller left
    stack<int> s;
    vector<int> nsl(n);
    vector<int> nsr(n);

    s.push(0);
    nsl[0] = -1;

    for (int i = 1; i < heights.size(); i++)
    {
        int curr = heights[i];
        while (!s.empty() && curr <= heights[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            nsl[i] = -1;
        }
        else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    //next smaller right
    s.push(n-1);
    nsr[n-1] = n;

    for(int i=n-2; i>=0; i--){
        int curr = heights[i];
         while (!s.empty() && curr <= heights[s.top()])
         {
            s.pop();
         }

         if (s.empty())
         {
            nsr[i] = n;
         }
         else{
            nsr[i] = s.top();
         }
         s.push(i);  
    }

    int maxArea=0;
    for (int i = 0; i < heights.size(); i++)
    {
        int ht = heights[i];
        int wd = nsr[i] - nsl[i] - 1;

        int area = ht*wd;

        maxArea = max(maxArea, area);
    }

    cout<<"the maximum are of histogram is: "<<maxArea<<endl;
    
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    maxAreaHistogram(heights);


return 0;
}