#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }
    
    void insert(string key){
        Node* temp = root;

        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    // 🔥 LCP FUNCTION
    string getLCP(){
        string prefix = "";
        Node* temp = root;

        while(true){
            // stop if:
            // 1. more than 1 child (branching)
            // 2. or end of any word
            if(temp->children.size() != 1 || temp->endOfWord){
                break;
            }

            // get the only child
            auto it = temp->children.begin();
            char ch = it->first;
            temp = it->second;

            prefix += ch;
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        // insert all strings
        for(string s : strs){
            trie.insert(s);
        }

        // get LCP from trie
        return trie.getLCP();
    }
};

int main(){
    Solution sol;

    // Test case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Test 1: " << sol.longestCommonPrefix(strs1) << endl; // Expected: "fl"

    // Test case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test 2: " << sol.longestCommonPrefix(strs2) << endl; // Expected: ""

    // Test case 3
    vector<string> strs3 = {"interspecies", "interstellar", "interstate"};
    cout << "Test 3: " << sol.longestCommonPrefix(strs3) << endl; // Expected: "inters"

    // Test case 4
    vector<string> strs4 = {"a"};
    cout << "Test 4: " << sol.longestCommonPrefix(strs4) << endl; // Expected: "a"

    return 0;
}