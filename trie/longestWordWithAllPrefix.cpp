#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

// Node class represents a single character in the Trie
class Node{
    public:
        unordered_map<char, Node*> children; // Map of child nodes for each character
        bool endOfWord; // Marks whether this node completes a valid word

        Node(){
            endOfWord = false; // By default, not the end of a word
        }
};

class Trie{
    Node* root; // Root node of the Trie

    public:
        Trie(){
            root = new Node(); // Initialize root node
        }
        
        // Insert a word into the Trie
        void insert(string key){
            Node* temp = root;

            // Traverse through each character in the word
            for(int i=0; i<key.size(); i++){
                // If the current character does not exist, create a new node
                if(temp->children.count(key[i]) == 0){
                    temp->children[key[i]] = new Node();
                }
                // Move to the next node
                temp = temp->children[key[i]];
            }
            // Mark the last node as the end of the word
            temp->endOfWord = true;
        }

        // Helper function to find the longest word with all prefixes present
        void longestStringHelper(Node* root, string &ans, string temp){
            // Traverse through all children of the current node
            for (pair<char, Node*> child: root->children)
            {
                // Only continue if the child node marks the end of a word
                if (child.second->endOfWord)
                {
                    // Add the character to the temporary string
                    temp += child.first;

                    // Update answer if:
                    // 1. Current word is longer than the previous longest, OR
                    // 2. Word length is equal but lexicographically smaller
                    if ((temp.size() > ans.size()) || ((temp.size() == ans.size()) && (temp < ans)))
                    {
                        ans = temp;
                    }

                    // Recursively explore further characters
                    longestStringHelper(child.second, ans, temp);

                    // Backtrack: remove last character to explore other paths
                    temp = temp.substr(0, temp.size()-1);
                }
            }
        }

        // Returns the longest word in the Trie such that all prefixes are also valid words
        string longestStringWithEOW(){
            string ans="";
            longestStringHelper(root, ans, "");
            return ans;
        }
};

// Wrapper function: inserts all words into Trie and returns the longest valid word
string longestWord(vector<string> dict){
    Trie trie;

    // Insert each word into the Trie
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
        cout<<"Inserted word: "<<dict[i]<<endl;
    }

    // Get the longest word with all prefixes present
    return trie.longestStringWithEOW();
}

int main()
{
    // Input dictionary of words
    vector<string> dict = {"a", "ap", "app", "appl","apple", "apply", "banana"};

    // Print the longest valid word
    cout<<longestWord(dict)<<endl;
    
    return 0;
}
