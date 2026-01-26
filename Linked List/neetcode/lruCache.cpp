#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* left;
    Node* right;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* left = nullptr;   // Least Recently Used
    Node* right = nullptr;  // Most Recently Used
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Remove a node from doubly linked list
    void remove(Node* node) {
        if (node == nullptr) return;

        if (node->left != nullptr) {
            node->left->right = node->right;
        } else {
            // node is LRU (head)
            left = node->right;
        }

        if (node->right != nullptr) {
            node->right->left = node->left;
        } else {
            // node is MRU (tail)
            right = node->left;
        }

        node->left = nullptr;
        node->right = nullptr;
    }

    // Add node to the right (MRU position)
    void add(Node* node) {
        if (right == nullptr) {
            left = right = node;
        } else {
            right->right = node;
            node->left = right;
            right = node;
        }
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            add(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update existing key
            Node* node = mp[key];
            remove(node);
            node->val = value;
            add(node);
        }
        else if (mp.size() < capacity) {
            Node* node = new Node(key, value);
            mp[key] = node;
            add(node);
        }
        else {
            // Evict LRU
            mp.erase(left->key);
            remove(left);

            Node* node = new Node(key, value);
            mp[key] = node;
            add(node);
        }
    }
};

// ---------- Testing ----------
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1

    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // -1

    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}
