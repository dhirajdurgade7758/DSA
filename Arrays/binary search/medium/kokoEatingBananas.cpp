#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    Given banana piles and total hours h,
    find the minimum eating speed (bananas/hour)
    so that all bananas are eaten within h hours.
*/

class Solution {
public:
    // This function calculates total hours needed
    // if Koko eats at speed = k bananas per hour
    int findHoursToEat(vector<int>& piles, int k) {
        int hours = 0;

        for (int i = 0; i < piles.size(); i++) {
            /*
                Ceiling division:
                Example:
                piles[i] = 7, k = 3
                7/3 = 2.33 → needs 3 hours
            */
            hours += (piles[i] + k - 1) / k;
        }
        return hours;
    }

    // Binary Search to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;  // minimum possible speed
        int right = *max_element(piles.begin(), piles.end()); // max pile size

        while (left < right) {
            int mid = left + (right - left) / 2; // avoid overflow
            int hours = findHoursToEat(piles, mid);

            /*
                If Koko can eat all bananas in <= h hours,
                then try a smaller speed (optimize).
            */
            if (hours <= h) {
                right = mid;
            }
            /*
                If it takes more than h hours,
                speed is too slow → increase it.
            */
            else {
                left = mid + 1;
            }
        }

        // left == right → minimum valid eating speed
        return left;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    // Function call
    int result = obj.minEatingSpeed(piles, h);

    // Output result
    cout << "Minimum eating speed: " << result << " bananas/hour" << endl;

    return 0;
}
