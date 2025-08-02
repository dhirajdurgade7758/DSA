class Solution {
public:
    string largestOddNumber(string num) {
       int lastnum = 0;
        while(!num.empty()){
            lastnum = int(num.back());

            if(lastnum % 2 != 0){
                return num;
            }
            else{
                num.pop_back();
            }
        }
        return "";
    }
};