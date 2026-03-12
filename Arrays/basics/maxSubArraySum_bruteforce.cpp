#include<iostream>
using namespace std;

void maxSubArraySum1(int *arr, int n){
    int maxSum=INT_MIN;
    for(int start=0; start<n; start++){
        int currSum=0;
        for(int end=start; end<n; end++){
            currSum+=arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout<<"maximum subarray sum is: "<<maxSum<<endl;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n=5;

    maxSubArraySum1(arr, n);


return 0;
}