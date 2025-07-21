#include<iostream>
using namespace std;

void swap_min_max(int arr[], int size){
    int min_no = INT_MAX;
    int max_no = INT_MIN;
    int min_index = 0;
    int max_index = 0;

    for(int i = 0; i<size; i++){
        if(arr[i]<min_no){
            min_no = arr[i];
            min_index = i;
        }
    }

     for(int i = 0; i<size; i++){
        if(arr[i]>max_no){
            max_no = arr[i];
            max_index = i;
        }
    }

    swap(arr[min_index], arr[max_index]);

}


int main(){
    int nums[] = {1,2,3,4,5};
    int size = 5;

    swap_min_max(nums, size);

        for(int i = 0; i < size; i++) {
        cout << nums[i] << endl;  
    }
    
    return 0; 
}
