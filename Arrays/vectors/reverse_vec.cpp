#include <iostream>
#include<vector>
using namespace std;

// Function to print unique elements in an array
void reverse_vec(vector<int> &vec) {
    int start = 0;
    int end = vec.size() - 1;
    
    while (start < end)
    {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
    
}

int main() {
    vector<int> vec = {10,20,30,40,50,60,70,80};
    reverse_vec(vec);

    for(int val:vec){
        cout<<val<<endl;
    }

    return 0;
}
