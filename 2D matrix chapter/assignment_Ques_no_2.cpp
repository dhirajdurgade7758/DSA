//Question 2 : Print out the sum of the numbers in the second row of the “nums” array. 
// Example : 
// Input - int nums[ ][ ] = { {1,4,9}, {11,4,3}, {2,2,3} }; 
// Output - 18 

#include<iostream>
#include<vector>

using namespace std;

int main(){

int arr[][3] = { {1,4,9}, {11,4,3}, {2,2,3} };
int  n = 2, m = 3 ;
int *ptr = (int *)(arr + 1);
int sum = 0;

// O(n) time complexity
for(int i=0; i<m; i++){
    sum += *ptr;
    ptr++;
}

cout<<"the number of element in second row is : "<<sum<<endl;

    return 0;
}