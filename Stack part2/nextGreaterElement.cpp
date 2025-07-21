#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void findNextGreater(vector<int>& arr, vector<int>& ans){
    stack<int> s;
    int n=arr.size();
    s.push(arr[n-1]);
    ans[n-1] = -1;

    for (int i = n-2; i >= 0; i--)
    {
        while (!s.empty() && arr[i]>=s.top())
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
        
    }
    
}

int main()
{
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(5,0);
    findNextGreater(arr, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

return 0;
}