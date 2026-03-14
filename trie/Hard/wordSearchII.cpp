#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    string word;

    Node(){
        endOfWord = false;
        word = "";
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
        temp->word = key;
    }
};

class Solution {
public:

    void helper(vector<vector<char>>& board, Node* node,
                vector<string>& ans, int row, int col) {

        int n = board.size();
        int m = board[0].size();

        // boundary check
        if(row < 0 || col < 0 || row >= n || col >= m)
            return;

        char ch = board[row][col];

        // visited or no matching child
        if(ch == '#' || node->children.count(ch) == 0)
            return;

        Node* nextNode = node->children[ch];

        // word found
        if(nextNode->endOfWord){
            ans.push_back(nextNode->word);
            nextNode->endOfWord = false; // avoid duplicates
        }

        // mark visited
        board[row][col] = '#';

        // explore 4 directions
        helper(board, nextNode, ans, row-1, col);
        helper(board, nextNode, ans, row+1, col);
        helper(board, nextNode, ans, row, col-1);
        helper(board, nextNode, ans, row, col+1);

        // backtrack
        board[row][col] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Trie t;

        // build Trie
        for(string word : words){
            t.insert(word);
        }

        vector<string> ans;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                helper(board, t.root, ans, i, j);
            }
        }

        return ans;
    }
};

int main(){

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    vector<string> words = {"oath","pea","eat","rain"};

    Solution sol;
    vector<string> result = sol.findWords(board, words);

    cout << "Words Found:\n";
    for(string word : result){
        cout << word << endl;
    }

    return 0;
}
