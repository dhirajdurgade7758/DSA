#include<iostream>
#include<vector>

using namespace std;

// O(m+n) time complexity
// void search_element(vector<vector<int>> mt, int n, int m, int key){
//     int i = 0, j = m-1;

//     while (i < n && j >= 0)
//     {
//         if(mt[i][j] == key){
//             cout<<"Element found at index ("<<i<<") , ("<<j<<")";
//             return;
//         }
//         else if(mt[i][j] > key){
//             j--;
//         }
//         else if(mt[i][j] < key){
//             i++;
//         }
//     }

//     cout<<"given element is not found !";
    
// }

void search_element(vector<vector<int>> mt, int n, int m, int key){
    int i = n-1, j = 0;

    while (i >= 0 && j < m)
    {
        if(mt[i][j] == key){
            cout<<"Element found at index ("<<i<<") , ("<<j<<")";
            return;
        }
        else if(mt[i][j] > key){
            i--;
        }
        else if(mt[i][j] < key){
            j++;
        }
    }

    cout<<"given element is not found !";
    
}


int main(){
    vector<vector<int>> mt = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int n = mt.size(), m = mt[0].size(), key = 9;
    search_element(mt, n, m, key);
return 0;
}