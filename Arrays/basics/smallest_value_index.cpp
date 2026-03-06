#include<iostream>
using namespace std;

int main(){
    int nums[] = {5,15,22,-15,24};
    int size = 5;
    int smallest = INT_MAX;
    int index = 0;

    for(int i = 0; i<size; i++){
        if(nums[i] < smallest){
            smallest = nums[i];
            index = i;
        }
    }

    cout<<"smallest value index: "<<index<<endl;
}