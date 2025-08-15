#include <iostream>
#include<unordered_map>
using namespace std;

bool validAnagram(string s, string t){
    unordered_map<int, int> m;
    for(int i=0; i<s.size(); i++){
        if(m.count(s[i])){
            m[s[i]]++;
        }
        else{
            m[s[i]] = 1;
        }
    }
    for(int i=0; i<s.size(); i++){
        if(m[t[i]]){
            m[t[i]]--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    string a ="carr";
    string b ="racr";
    cout<<validAnagram(a, b);
}