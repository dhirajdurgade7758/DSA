#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class WordDictionary {
    Node* root;

public:
    WordDictionary(){
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++){
            if(temp->children.count(word[i]) == 0){
                temp->children[word[i]] = new Node();
            }
            temp = temp->children[word[i]];
        }
        temp->endOfWord = true;
    }

    bool searchHelper(Node* node, string& key, int indx){
        Node* temp = node;

        for(int i = indx; i < key.size(); i++){

            if(key[i] == '.'){
                for(auto child : temp->children){
                    if(searchHelper(child.second, key, i + 1)){
                        return true;
                    }
                }
                return false;
            }

            if(temp->children.count(key[i]) == 0){
                return false;
            }

            temp = temp->children[key[i]];
        }

        return temp->endOfWord;
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};

int main() {

    WordDictionary obj;

    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");

    cout << boolalpha;  // prints true/false instead of 1/0

    cout << "search(\"pad\") -> " << obj.search("pad") << endl; // false
    cout << "search(\"bad\") -> " << obj.search("bad") << endl; // true
    cout << "search(\".ad\") -> " << obj.search(".ad") << endl; // true
    cout << "search(\"b..\") -> " << obj.search("b..") << endl; // true

    return 0;
}
