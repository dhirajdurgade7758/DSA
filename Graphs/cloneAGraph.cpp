#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/* Definition for Node */
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldTONew){
        if(oldTONew.count(node)){
            return oldTONew[node];
        }

        Node* newNode = new Node(node->val);
        oldTONew[node] = newNode;

        for(Node* neighbor : node->neighbors){
            newNode->neighbors.push_back(dfs(neighbor, oldTONew));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> oldTONew;
        return dfs(node, oldTONew);
    }
};

// Function to print graph using BFS
void printGraph(Node* node) {
    if (!node) return;

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << " neighbors: ";

        for(Node* neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
}

int main() {

    // Creating sample graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original Graph:\n";
    printGraph(node1);

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1);

    cout << "\nCloned Graph:\n";
    printGraph(clonedGraph);

    return 0;
}
