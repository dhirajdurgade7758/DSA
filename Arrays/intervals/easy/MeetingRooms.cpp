#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAttend(vector<vector<int>> &arr) {
    if(arr.empty()) return true;

    sort(arr.begin(), arr.end());

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i][0] < arr[i-1][1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    cout << "Enter meetings (start end):\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    if(canAttend(arr)) {
        cout << "Yes, you can attend all meetings." << endl;
    } else {
        cout << "No, meetings overlap." << endl;
    }

    return 0;
}