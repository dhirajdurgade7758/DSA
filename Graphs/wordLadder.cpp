#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Check if endWord exists
        bool found = false;
        for (string &word : wordList) {
            if (word == endWord) {
                found = true;
                break;
            }
        }
        if (!found) return 0;

        // Build pattern map
        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);

        for (string &word : wordList) {
            for (int j = 0; j < word.length(); j++) {
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                nei[pattern].push_back(word);
            }
        }

        // BFS
        unordered_set<string> visit;
        queue<string> q;

        visit.insert(beginWord);
        q.push(beginWord);

        int res = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return res;

                for (int j = 0; j < word.length(); j++) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);

                    for (string &neiWord : nei[pattern]) {
                        if (visit.find(neiWord) == visit.end()) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};

int main() {
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);

    cout << "Shortest transformation length: " << result << endl;

    return 0;
}