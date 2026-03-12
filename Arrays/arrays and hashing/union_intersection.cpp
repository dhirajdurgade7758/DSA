// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;
    
    for(int i=0; i<arr1.size(); i++){
        s.insert(arr1[i]);
    }
    
    for(int i=0; i<arr2.size(); i++){
        s.insert(arr2[i]);
    }
    
    for(int ele: s){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void printIntersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;
    
    for(int i=0; i<arr1.size(); i++){
        s.insert(arr1[i]);
    }
    
    for(int ele: arr2){
        if(s.find(ele) != s.end()){
            cout<<ele<<" ";
        }
    }
    cout<<endl;
}

int main() {
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};
    
    printUnion(arr1, arr2);
    printIntersection(arr1, arr2);
    return 0;
}