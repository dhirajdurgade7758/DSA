// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<string>
// using namespace std;

// /*
//  Node class represents each node in the Trie.
//  Each node contains:
//   - children: map of character -> Node*
//   - endOfWord: marks the end of a complete word (for normal Trie use)
// */
// class Node {
// public:
//     unordered_map<char, Node*> children; // to store references to child nodes
//     bool endOfWord;

//     Node() {
//         endOfWord = false;
//     }
// };

// /*
//  Trie class:
//  - Provides word insertion into the Trie (insert)
//  - Provides method to count distinct substrings of a given string (countDistinctSubstrings)
// */
// class Trie {
    
// public:
//     Node* root;
//     Trie() {
//         root = new Node(); // root node of the Trie
//     }

//     // Function to insert a word into the Trie (used for dictionary words)
//     void insert(string key) {
//         Node* temp = root;

//         // Traverse each character of the word
//         for (int i = 0; i < key.size(); i++) {
//             // If the character does not exist, create a new node
//             if (temp->children.count(key[i]) == 0) {
//                 temp->children[key[i]] = new Node();
//             }
//             // Move to the next node
//             temp = temp->children[key[i]];
//         }

//         // Mark the last node as end of word
//         temp->endOfWord = true;
//     }

//     void countNodes(Node* temp, int& count){
//         count += temp->children.size();
//         for(auto curr: temp->children){
//             countNodes(curr.second, count);
//         }
//     }
// };

// int main() {
//     // Example test string for distinct substrings
//     string test = "ababa";

//     Trie t;
//     for(int i=0; i<test.size(); i++){
//         t.insert(test.substr(i));
//     }
//     int count=0;
//     t.countNodes(t.root, count);
//     cout<<"number of unique substrings count is: "<<count;
//     return 0;
// }

/// this above approch is also good but we dont need countNodes function 

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
};

/*
 Trie class:
 - Provides word insertion into the Trie (insert)
 - Provides method to count distinct substrings of a given string (countDistinctSubstrings)
*/
class Trie {
    Node* root;
public:
    int count;
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
                count++;
            }
            // Move to the next node
            temp = temp->children[key[i]];
        }

        // Mark the last node as end of word
        temp->endOfWord = true;
    }

   
};

int main() {
    // Example test string for distinct substrings
    string test = "ababa";

    Trie t;
    for(int i=0; i<test.size(); i++){
        t.insert(test.substr(i));
    }
    cout<<"number of unique substrings count is: "<<t.count;
    return 0;
}

