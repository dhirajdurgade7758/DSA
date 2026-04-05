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
    int count;

    Trie() {
        root = new Node();
        count = 0;  // FIXED
    }

    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {

            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
                count++;   // count new substring
            }

            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie t;

    for (int i = 0; i < s.size(); i++) {
        t.insert(s.substr(i));
    }

    return t.count + 1;  // +1 for empty substring
}

int main() {
    vector<string> test = {"sds", "abc", "aa", "abab"};

    for (auto s : test) {
        cout << countDistinctSubstrings(s) << endl;
    }
}
