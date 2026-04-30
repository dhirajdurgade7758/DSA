class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        // count frequency
        for(char c : s){
            freq[c]++;
        }

        // max heap (frequency, character)
        priority_queue<pair<int, char>> pq;
        for(auto &it : freq){
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(pq.size() > 1){
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            int count1 = top1.first;
            int count2 = top2.first;
            char ch1 = top1.second;
            char ch2 = top2.second;

            // add both characters
            ans += ch1;
            ans += ch2;

            // decrease frequency
            count1--;
            count2--;

            if(count1 > 0) pq.push({count1, ch1});
            if(count2 > 0) pq.push({count2, ch2});
        }

        // if one character left
        if(!pq.empty()){
            if(pq.top().first > 1){
                return ""; // not possible
            }
            ans += pq.top().second;
        }

        return ans;
    }
};