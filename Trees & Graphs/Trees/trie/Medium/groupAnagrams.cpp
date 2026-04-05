#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// Node structure for Trie
class Node {
public:
    unordered_map<char, Node*> children; // children map for characters
    bool endOfWord;                      // marks end of a word
    vector<string> words;                // stores original words (for anagram grouping)

    Node() {
        endOfWord = false;
    }
};

// Trie structure
class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    // Insert word into Trie (sorted characters determine the path)
    void insert(string key) {
        Node* temp = root;

        // Sort the word → ensures all anagrams follow the same path
        string sortedKey = key;
        sort(sortedKey.begin(), sortedKey.end());

        // Traverse or create nodes based on sortedKey
        for (int i = 0; i < sortedKey.size(); i++) {
            if (temp->children.count(sortedKey[i]) == 0) {
                temp->children[sortedKey[i]] = new Node();
            }
            temp = temp->children[sortedKey[i]];
        }

        // Mark end of word and store original word
        temp->endOfWord = true;
        temp->words.push_back(key);
    }

    // Collect grouped anagrams from Trie
    void getAnagrams(Node* node, vector<vector<string>>& ans) {
        // If node represents end of word(s), add its words to result
        if (node->endOfWord) {
            ans.push_back(node->words);
        }

        // Recurse into all children
        for (pair<const char, Node*> child : node->children) {
            getAnagrams(child.second, ans);
        }
    }
};

// Solution class
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        Trie trie;

        // Insert all words into Trie
        for (int i = 0; i < strs.size(); i++) {
            trie.insert(strs[i]);
        }

        // Collect anagram groups
        vector<vector<string>> ans;
        trie.getAnagrams(trie.root, ans);
        return ans;
    }
};

// ---------------- MAIN DRIVER ----------------
int main() {
    Solution sol;

    // Example input
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Get grouped anagrams
    vector<vector<string>> result = sol.groupAnagrams(words);

    // Print result
    cout << "Grouped Anagrams:" << endl;
    for (auto group : result) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
