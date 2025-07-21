#include<iostream>
using namespace std;

int sumArr(int arr[], int size){
    int sum = 0;
    for(int i = 0; i<size; i++){
        sum += arr[i];
    }
    return sum;
}

int productArr(int arr[], int size){
    int product = 1;
     for(int i = 0; i<size; i++){
        product *= arr[i];
    }
    return product;
}

int main(){
    int nums[] = {1,2,3,4,5};
    int size = 5;
    
    cout<<"sum of all elements is : "<<sumArr(nums, size)<<endl;
    cout<<"product of all elements : "<<productArr(nums,size)<<endl;
    return 0; 
}
