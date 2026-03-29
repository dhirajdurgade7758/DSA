#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int> st;
//         unordered_set<int> todel;
//         for(int i=asteroids.size()-1; i>=0; i--){
//             // moving into left
//             if(asteroids[i]<0){
//                 st.push(i);
//             }
//             // moving into right and collision
//             while (!st.empty() && asteroids[i] > 0) {
//                 int ast2 = asteroids[st.top()];
//                 int ast1 = asteroids[i];

//                 if (ast1 < abs(ast2)) {
//                     todel.insert(i);
//                     break;
//                 } 
//                 else if (ast1 > abs(ast2)) {
//                     todel.insert(st.top());
//                     st.pop();
//                 } 
//                 else {
//                     todel.insert(i);
//                     todel.insert(st.top());
//                     st.pop();
//                     break;
//                 }
//             }
//         }

//         //remove exploded asteroids
//         int j=0;
//         int i;
//         for(i=0; i<asteroids.size(); i++){
//             if(!todel.count(i)){
//                 asteroids[j]=asteroids[i];
//                 j++;
//             }
//         }
//         while (asteroids.size() > j) {
//             asteroids.pop_back();
//         }
//         return asteroids;
//     }
// };


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.back() > 0) {
                if (abs(a) > st.back()) {
                    st.pop_back();
                } 
                else if (abs(a) == st.back()) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(a);
            }
        }

        return st;
    }
};

int main() {
    Solution sol;

    // Test case 1: asteroids explode each other
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = sol.asteroidCollision(asteroids1);
    cout << "Test 1: {5, 10, -5} -> ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test case 2: all survive
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = sol.asteroidCollision(asteroids2);
    cout << "Test 2: {8, -8} -> ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    // Test case 3: no collision
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = sol.asteroidCollision(asteroids3);
    cout << "Test 3: {10, 2, -5} -> ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    // Test case 4: all moving same direction
    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> result4 = sol.asteroidCollision(asteroids4);
    cout << "Test 4: {-2, -1, 1, 2} -> ";
    for (int x : result4) cout << x << " ";
    cout << endl;

    // Test case 5: complex collision
    vector<int> asteroids5 = {1, -2, -2, -2};
    vector<int> result5 = sol.asteroidCollision(asteroids5);
    cout << "Test 5: {1, -2, -2, -2} -> ";
    for (int x : result5) cout << x << " ";
    cout << endl;

    return 0;
}