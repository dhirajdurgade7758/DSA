#include<iostream>
#include<string.h>
using namespace std;

void reverse(char arr[], int n){
    int st=0, end=n-1;
    while (st<end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
    
}

int main()
{
    char arr[] = "code";
    cout<<"orignal string: "<<arr<<endl;
    reverse(arr, strlen(arr));
    cout<<"string after reversing: "<<arr;

return 0;
}