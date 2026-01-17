#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    // Map to store:
    // key -> vector of {value, timestamp}
    unordered_map<string, vector<pair<string, int>>> mp;

    // Constructor
    TimeMap() {
        // Nothing to initialize
    }
    
    // Stores the key with value and timestamp
    void set(string key, string value, int timestamp) {
        // Push value and timestamp into the vector for this key
        mp[key].push_back({value, timestamp});
    }
    
    // Returns the value with the largest timestamp <= given timestamp
    string get(string key, int timestamp) {

        // If key does not exist, return empty string
        if (mp.find(key) == mp.end()) {
            return "";
        }

        // Reference to vector of {value, timestamp}
        vector<pair<string, int>>& values = mp[key];

        int start = 0;
        int end = values.size() - 1;
        string ans = "";

        // Binary search on timestamps
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // If timestamp at mid is <= given timestamp
            // it is a valid candidate
            if (values[mid].second <= timestamp) {
                ans = values[mid].first; // store possible answer
                start = mid + 1;         // try to find a later timestamp
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};

// -------------------
// Main function for testing in VS Code
// -------------------
int main() {
    TimeMap tm;

    // Setting values
    tm.set("foo", "bar", 1);
    tm.set("foo", "bar2", 4);

    // Getting values
    cout << tm.get("foo", 1) << endl; // bar
    cout << tm.get("foo", 3) << endl; // bar
    cout << tm.get("foo", 4) << endl; // bar2
    cout << tm.get("foo", 5) << endl; // bar2
    cout << tm.get("baz", 1) << endl; // "" (empty)

    return 0;
}
