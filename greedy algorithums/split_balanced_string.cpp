class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int temp = 0;
        
        for(int i=0; i<s.size(); i++){
            if(temp == 0){
                count++;
            }

            if(s[i]=='R'){
            temp++;
            }
            else{
                temp--;
            }
        }
        return count;
    }
};