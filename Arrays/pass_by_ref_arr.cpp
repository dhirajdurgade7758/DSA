#include<iostream>
using namespace std;

void change_arr(int arr[],int size ){
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] * 2;
    }
    
}

int main(){
    int nums[] = {5,15,22,-15,24};
    int size = 5;
    change_arr(nums,size);

    for(int i = 0; i<size; i++){
        cout<<nums[i]<<endl;
    }
}