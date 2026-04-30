class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1){
            return true;
        }

        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        for(int i = 1; i < words.size(); i++){
            string first = words[i - 1];
            string second = words[i];

            int len = min(first.size(), second.size());
            bool foundDiff = false;

            for(int j = 0; j < len; j++){
                if(first[j] != second[j]){
                    foundDiff = true;

                    if(mp[first[j]] > mp[second[j]]){
                        return false;
                    }
                    else{
                        break; // ✅ stop at first valid difference
                    }
                }
            }

            // ✅ prefix case
            if(!foundDiff && first.size() > second.size()){
                return false;
            }
        }

        return true;
    }
};