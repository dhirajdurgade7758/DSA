#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;

        for(int i = 0; i < gas.size(); i++) {
            gasSum += gas[i];
            costSum += cost[i];
        }

        // Check if solution exists
        if(gasSum < costSum) {
            return -1;
        }

        int start = 0;
        int total = 0;

        for(int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;

            if(total < 0) {
                start = i + 1;
                total = 0;
            }
        }

        return start;
    }
};

int main() {
    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    vector<int> gas(n), cost(n);

    cout << "Enter gas values:\n";
    for(int i = 0; i < n; i++) {
        cin >> gas[i];
    }

    cout << "Enter cost values:\n";
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    Solution obj;
    int result = obj.canCompleteCircuit(gas, cost);

    cout << "Starting station index: " << result << endl;

    return 0;
}