#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

/*
 Node class represents each node in the Trie.
 Each node contains:
  - children: map of character -> Node*
  - endOfWord: marks the end of a complete word (for normal Trie use)
*/
class Node {
public:
    unordered_map<char, Node*> children; // to store references to child nodes
    bool endOfWord;

    Node() {
        endOfWord = false;
    }

    // Checks if a node already has a child for character 'ch'
    bool containsKey(char ch) {
        return children.count(ch) > 0;
    }

    // Returns the child node corresponding to character 'ch'
    Node* get(char ch) {
        return children[ch];
    }

    // Creates/assigns a new child node for character 'ch'
    void put(char ch, Node* node) {
        children[ch] = node;
    }
};

/*
 Trie class:
 - Provides word insertion into the Trie (insert)
 - Provides method to count distinct substrings of a given string (countDistinctSubstrings)
*/
class Trie {
    Node* root;

public:
    Trie() {
        root = new Node(); // root node of the Trie
    }

    // Function to insert a word into the Trie (used for dictionary words)
    void insert(string key) {
        Node* temp = root;

        // Traverse each character of the word
        for (int i = 0; i < key.size(); i++) {
            // If the character does not exist, create a new node
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            // Move to the next node
            temp = temp->children[key[i]];
        }

        // Mark the last node as end of word
        temp->endOfWord = true;
    }

    /*
     Function to count distinct substrings of a given string.
     Approach:
       - For each starting index i, create substrings s[i...j]
       - Insert each substring into a Trie
       - If a character path is new, it means a new substring is found
       - Count all new substrings
       - At the end, return total count + 1 (for the empty substring)
    */
    int countDistinctSubstrings(string s) {
        int cnt = 0;           // counter for distinct substrings
        Node* root = new Node(); // fresh Trie root for this function

        // Outer loop for starting index of substring
        for (int i = 0; i < s.size(); i++) {
            Node* node = root;

            // Inner loop for ending index of substring
            for (int j = i; j < s.size(); j++) {
                // If current character path does not exist in Trie
                if (!node->containsKey(s[j])) {
                    cnt++; // found a new distinct substring
                    node->put(s[j], new Node()); // create new node
                }

                // Move to next node in Trie
                node = node->get(s[j]);
            }
        }

        return cnt + 1; // +1 for the empty substring
    }
};

int main() {
    // Words to insert into the Trie
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    // Insert words and display confirmation
    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
        cout << "Inserted word: " << words[i] << endl;
    }

    // Example test string for distinct substrings
    string test = "ababa";

    // Call function and print result
    cout << "\nNumber of distinct substrings in \"" << test << "\": "
         << trie.countDistinctSubstrings(test) << endl;

    return 0;
}
