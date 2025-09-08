#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

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

            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    temp->children[key[i]] = new Node();
                }
                temp = temp->children[key[i]];
            }
            temp->endOfWord = true;
        }

        bool search(string key){
             Node* temp = root;

            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    return false;
                }
                temp = temp->children[key[i]];
            }

            if (temp->endOfWord == true)
            {
                return true;
            }
            return false;

        }
};

int main()
{
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
        cout<<"inserted word: "<<words[i]<<endl;
    }
    
    if(trie.search("any")){
        cout<<"any is found";
    }
    else{
        cout<<"any is not found";
    }
    

return 0;
}