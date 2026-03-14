#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& key) {
        Node* temp = root;

        for (char ch : key) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    bool search(const string& key) {
        Node* temp = root;

        for (char ch : key) {
            if (temp->children.count(ch) == 0) {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->endOfWord;
    }
};

class Solution {
public:
    unordered_map<string, bool> dp;

    bool helper(Trie& trie, const string& key) {
        if (key.empty()) return true;

        if (dp.count(key)) return dp[key];

        for (int i = 0; i < key.size(); i++) {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);

            if (trie.search(first) && helper(trie, second)) {
                return dp[key] = true;
            }
        }
        return dp[key] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (const string& word : wordDict) {
            trie.insert(word);
        }
        return helper(trie, s);
    }
};

int main() {
    Solution sol;

    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {
        "a","aa","aaa","aaaa","aaaaa",
        "aaaaaa","aaaaaaa","aaaaaaaa",
        "aaaaaaaaa","aaaaaaaaaa"
    };

    if (sol.wordBreak(s, wordDict)) {
        cout << "Word Break Possible ✅" << endl;
    } else {
        cout << "Word Break NOT Possible ❌" << endl;
    }

    return 0;
}
