#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Node structure for Trie
class Node {
public:
    unordered_map<char, Node*> children; // maps character → child node
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

// Trie data structure
class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert word into trie
    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true; // mark end of word
    }

    // Search if word exists in trie
    bool search(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                return false;
            }
            temp = temp->children[key[i]];
        }

        return temp->endOfWord; // only true if it's a complete word
    }
};

class Solution {
public:
    // Helper function → recursively check if string can be segmented
    bool helper(Trie& trie, string key) {
        if (key.size() == 0) {
            return true; // base case: whole string segmented
        }

        // try splitting the string into (first + second)
        for (int i = 0; i < key.size(); i++) {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);

            // if first word is in dictionary, recursively check rest
            if (trie.search(first) && helper(trie, second)) {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;

        // insert all dictionary words into Trie
        for (int i = 0; i < wordDict.size(); i++) {
            trie.insert(wordDict[i]);
        }

        // check segmentation
        return helper(trie, s);
    }
};

int main() {
    Solution sol;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (sol.wordBreak(s, wordDict)) {
        cout << "String can be segmented into dictionary words ✅" << endl;
    } else {
        cout << "String cannot be segmented ❌" << endl;
    }

    return 0;
}
