#include <iostream>
#include<vector>
using namespace std;

// Function to print unique elements in an array
void linear_search(vector<int> vec, int ele) {
    for (int i = 0; i<vec.size(); i++) {
        if(vec[i] == ele){
            cout<<"element found at index "<<i<<endl;
        }
    }
}

int main() {
    vector<int> vec = {10,20,30,40,50,60,70,80};
    linear_search(vec, 30);

    return 0;
}
