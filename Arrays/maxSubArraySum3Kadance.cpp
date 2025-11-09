#include<iostream>
using namespace std;

void maxSubArraySum3(int *arr, int n){
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0; i<n; i++){
        currSum+=arr[i];
        maxSum = max(maxSum, currSum);

        if(currSum < 0){
            currSum = 0;
        }
    }
    cout<<"maximum subarray sum is: "<<maxSum<<endl;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n=5;

    maxSubArraySum3(arr, n);


return 0;
}