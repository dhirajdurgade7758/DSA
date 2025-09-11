#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Node of Trie
class Node {
public:
    unordered_map<char, Node*> children; // store children nodes
    bool endOfWord;                      // true if word ends here

    Node() {
        endOfWord = false;
    }
};

// Trie class
class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert word into Trie
    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    // Check if given prefix exists in Trie
    bool startsWith(string prefix) {
        Node* temp = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children.count(prefix[i]) == 0) {
                return false; // prefix path not found
            }
            temp = temp->children[prefix[i]];
        }
        return true; // successfully traversed all prefix chars
    }

    // Check if full word exists in Trie
    bool search(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                return false;
            }
            temp = temp->children[key[i]];
        }
        return temp->endOfWord; // must end at a valid word
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie trie;

    // Insert words into Trie
    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
        cout << "Inserted word: " << words[i] << endl;
    }

    // Example check for prefix
    string prefix = "th";
    if (trie.startsWith(prefix)) {
        cout << "Yes, a word starts with prefix: " << prefix << endl;
    } else {
        cout << "No word starts with prefix: " << prefix << endl;
    }

    // Example check for full word
    string word = "any";
    if (trie.search(word)) {
        cout << "Yes, the word '" << word << "' exists in the Trie" << endl;
    } else {
        cout << "The word '" << word << "' does NOT exist in the Trie" << endl;
    }

    return 0;
}
