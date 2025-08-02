// my approch 
// class Solution {
// public:
//     string getSmallestString(int n, int k) {
//         vector<char> alphabets = {
//         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
//         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
//         'u', 'v', 'w', 'x', 'y', 'z'
//         };
//         string ans ="";
//         for(int i=n; i>0; i--){
//             if(k>(26+(n-1))){
//                 ans.push_back('z');
//                 k-=26;
//             }
//             else{
//                 int indx = abs(k-(i-1));
//                 indx--;
//                 if(indx<0){
//                     indx=0;
//                 }
//                 k=i-1;
//                 // ans.insert(ans.begin(), alphabets[indx]);
//                 ans = alphabets[indx] + ans;  
//             }
//         }
//         return ans;
        
//     }
// }; 

class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> alphabets = {
       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
       'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
       'u', 'v', 'w', 'x', 'y', 'z'
        };
        string res(n, 'a');
        k-=n;

        while(k > 0){
            res[n-1] = alphabets[min(25, k)];
            k -= min(25, k);
            n--;
        }
        return res;
        
    }
}; 