#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Encode list of strings to single string
    string encode(vector<string>& s) {
        string res = "";

        for(string str : s){
            res += to_string(str.size()) + "#" + str;
        }

        return res;
    }

    // Decode single string back to list
    vector<string> decode(string& s) {

        vector<string> ans;
        int i = 0;

        while(i < s.size()){

            int j = i;

            // find delimiter '#'
            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);

            ans.push_back(word);

            i = j + 1 + len;
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<string> input = {"neet","code","love","you"};

    string encoded = obj.encode(input);

    cout << "Encoded String:\n" << encoded << endl;

    vector<string> decoded = obj.decode(encoded);

    cout << "\nDecoded Strings:\n";

    for(string str : decoded){
        cout << str << " ";
    }

    cout << endl;

    return 0;
}