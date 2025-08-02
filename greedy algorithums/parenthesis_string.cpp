//bruteforce approach
// class Solution {
// public:

//     bool helper(string s, int indx, int count){
//         if(count<0){return false;}
//         if(indx==s.length()){return count==0;}
//         if(s[indx] == '('){
//             return helper(s, indx+1, count+1);
//         }
//         if(s[indx] == ')'){
//             return helper(s, indx+1, count-1);
//         }
//         return(helper(s,indx+1,count) ||
//             helper(s,indx+1, count+1) ||
//             helper(s,indx+1, count-1) );
//     }

//     bool checkValidString(string s) {
//         int indx=0;
//         int count=0;
//         return helper(s, indx, count);

//     }
// };


// Optimized solution

class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0){
                min=0;
            }
            if(max<0){
                return false;
            }
        }
        return min==0;
    }
};