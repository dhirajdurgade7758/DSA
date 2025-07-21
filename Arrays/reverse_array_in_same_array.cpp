#include<iostream>
using namespace std;

int main(){
    int nums[] = {1,2,3,4,5};
    int size = sizeof(nums) / sizeof(nums[0]);  // Calculate size dynamically
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
    
    for(int i = 0; i < size; i++) {
        cout << nums[i] << std::endl;  
    }
    return 0; 
}
