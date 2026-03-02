
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0)
            return false;

        // Count frequency of each card
        unordered_map<int, int> count;
        for (int n : hand) {
            count[n]++;
        }

        // Min heap to always get smallest available number
        priority_queue<int, vector<int>, greater<int>> minH;
        for (auto& it : count) {
            minH.push(it.first);
        }

        while (!minH.empty()) {
            int first = minH.top();

            // Try to form a group starting from 'first'
            for (int i = first; i < first + groupSize; i++) {

                if (count.find(i) == count.end())
                    return false;

                count[i]--;

                if (count[i] == 0) {
                    // If the smallest element isn't i, invalid
                    if (i != minH.top())
                        return false;

                    minH.pop();
                    count.erase(i);
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << "Test case 1: hand = {1, 2, 3, 6, 2, 3, 4, 7, 8}, groupSize = " << groupSize1 << endl;
    cout << "Result: " << (sol.isNStraightHand(hand1, groupSize1) ? "true" : "false") << endl;
    cout << "Expected: true (groups: [1,2,3], [2,3,4], [6,7,8])" << endl << endl;
    
    // Test case 2
    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 2;
    cout << "Test case 2: hand = {1, 2, 3, 4, 5}, groupSize = " << groupSize2 << endl;
    cout << "Result: " << (sol.isNStraightHand(hand2, groupSize2) ? "true" : "false") << endl;
    cout << "Expected: false (5 cards cannot be divided equally into groups of 2)" << endl << endl;
    
    // Test case 3
    vector<int> hand3 = {1, 2, 3, 4, 5, 6};
    int groupSize3 = 2;
    cout << "Test case 3: hand = {1, 2, 3, 4, 5, 6}, groupSize = " << groupSize3 << endl;
    cout << "Result: " << (sol.isNStraightHand(hand3, groupSize3) ? "true" : "false") << endl;
    cout << "Expected: false (consecutive groups of 2 impossible from this hand)" << endl << endl;
    
    // Test case 4
    vector<int> hand4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int groupSize4 = 3;
    cout << "Test case 4: hand = {1, 2, 3, 4, 5, 6, 7, 8, 9}, groupSize = " << groupSize4 << endl;
    cout << "Result: " << (sol.isNStraightHand(hand4, groupSize4) ? "true" : "false") << endl;
    cout << "Expected: true (groups: [1,2,3], [4,5,6], [7,8,9])" << endl;

    return 0;
}