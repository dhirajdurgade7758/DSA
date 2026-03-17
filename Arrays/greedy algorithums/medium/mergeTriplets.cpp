

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false;
        bool b=false;
        bool c=false;
        for(auto s:triplets){
            if(s[0] <= target[0] && s[1] <= target[1] && s[2] <= target[2]){
                if(s[0] == target[0]) a=true;
                if(s[1] == target[1]) b=true;
                if(s[2] == target[2]) c=true;
            }
        }
        return a && b && c;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> triplets = {
        {2,5,3},
        {1,8,4},
        {1,7,5}
    };

    vector<int> target = {2,7,5};

    bool ans = obj.mergeTriplets(triplets, target);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}