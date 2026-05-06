//my approch was to try all possible combinations of sticks and check if we can make 4 equal sides. This approach is correct but it is very slow and it will give TLE for large inputs.
// class Solution {
// public:

//     bool helper(vector<int> stick, int partCount,
//                 int partlen, int currPart){

//         if(partCount == 4){
//             return true;
//         }

//         if(stick.size() == 0){
//             return false;
//         }

//         for(int i = 0; i < stick.size(); i++){

//             if(currPart + stick[i] > partlen){
//                 continue;
//             }

//             vector<int> temp = stick;
//             int newPartCount = partCount;
//             int newCurrPart = currPart;

//             if(newCurrPart + stick[i] == partlen){
//                 newPartCount++;
//                 newCurrPart = 0;
//             }
//             else{
//                 newCurrPart += stick[i];
//             }

//             temp.erase(temp.begin() + i);

//             if(helper(temp, newPartCount,
//                       partlen, newCurrPart)){
//                 return true;
//             }
//         }

//         return false;
//     }

//     bool makesquare(vector<int>& matchsticks) {

//         int sum = 0;

//         for(int x : matchsticks){
//             sum += x;
//         }

//         if(sum % 4 != 0){
//             return false;
//         }

//         int part = sum / 4;

//         return helper(matchsticks, 0, part, 0);
//     }
// };

// optimized approch is to sort the sticks in descending order and try to place the largest stick first. This way we can prune the search space more effectively and avoid unnecessary recursive calls. We also use a vector to keep track of the current length of each side and backtrack when necessary.
class Solution {
public:

    bool solve(int idx, vector<int>& matchsticks,
               vector<int>& sides, int target) {

        // all sticks used
        if(idx == matchsticks.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        int val = matchsticks[idx];

        for(int i = 0; i < 4; i++) {

            // cannot place
            if(sides[i] + val > target) {
                continue;
            }

            // place stick
            sides[i] += val;

            if(solve(idx + 1, matchsticks, sides, target)) {
                return true;
            }

            // backtrack
            sides[i] -= val;

            // pruning
            // if one empty side failed,
            // no need to try other empty sides
            if(sides[i] == 0) {
                break;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for(int x : matchsticks) {
            sum += x;
        }

        if(sum % 4 != 0) {
            return false;
        }

        int target = sum / 4;

        // IMPORTANT OPTIMIZATION
        sort(matchsticks.rbegin(), matchsticks.rend());

        // largest stick bigger than side
        if(matchsticks[0] > target) {
            return false;
        }

        vector<int> sides(4, 0);

        return solve(0, matchsticks, sides, target);
    }
};