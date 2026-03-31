#include <iostream>
#include <vector>
using namespace std;

// class MyHashSet {
// private:
//     int size = 1000;
//     vector<list<int>> table;

// public:
//     MyHashSet() {
//         table.resize(size);
//     }
    
//     void add(int key) {
//         int i = key % size;
//         for (int val : table[i]) {
//             if (val == key) return;
//         }
//         table[i].push_back(key);
//     }
    
//     void remove(int key) {
//         int i = key % size;
//         table[i].remove(key);
//     }
    
//     bool contains(int key) {
//         int i = key % size;
//         for (int val : table[i]) {
//             if (val == key) return true;
//         }
//         return false;
//     }
// };

class MyHashSet {
private:
    struct Node {
        int key;
        Node* next;
        Node(int k) : key(k), next(NULL) {}
    };

    int size = 1000;
    vector<Node*> table;

public:
    MyHashSet() {
        table.resize(size, NULL);
    }
    
    void add(int key) {
        int i = key % size;
        Node* head = table[i];
        
        // Check if already exists
        Node* curr = head;
        while (curr) {
            if (curr->key == key) return;
            curr = curr->next;
        }
        
        // Insert at head
        Node* newNode = new Node(key);
        newNode->next = head;
        table[i] = newNode;
    }
    
    void remove(int key) {
        int i = key % size;
        Node* curr = table[i];
        Node* prev = NULL;
        
        while (curr) {
            if (curr->key == key) {
                if (prev == NULL) {
                    table[i] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        int i = key % size;
        Node* curr = table[i];
        
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }
};

int main() {
    cout << "===== Design HashSet - LeetCode 705 =====" << endl << endl;
    
    MyHashSet* obj = new MyHashSet();
    
    // Test Case 1: Basic add and contains operations
    cout << "Test Case 1: Basic Operations" << endl;
    obj->add(1);
    obj->add(2);
    cout << "After adding 1 and 2:" << endl;
    cout << "Contains 1? " << (obj->contains(1) ? "true" : "false") << endl;
    cout << "Contains 2? " << (obj->contains(2) ? "true" : "false") << endl;
    cout << "Contains 3? " << (obj->contains(3) ? "true" : "false") << endl << endl;
    
    // Test Case 2: Adding duplicate element
    cout << "Test Case 2: Adding Duplicate" << endl;
    obj->add(2);  // Add 2 again (should not cause issues)
    cout << "After adding 2 again:" << endl;
    cout << "Contains 2? " << (obj->contains(2) ? "true" : "false") << endl << endl;
    
    // Test Case 3: Removing elements
    cout << "Test Case 3: Remove Operations" << endl;
    obj->remove(2);
    cout << "After removing 2:" << endl;
    cout << "Contains 2? " << (obj->contains(2) ? "true" : "false") << endl;
    cout << "Contains 1? " << (obj->contains(1) ? "true" : "false") << endl << endl;
    
    // Test Case 4: Add and remove with larger numbers
    cout << "Test Case 4: Larger Numbers & Hash Collision" << endl;
    obj->add(100);
    obj->add(1000);
    obj->add(1001);  // Could collide with 1 due to modulo
    cout << "After adding 100, 1000, 1001:" << endl;
    cout << "Contains 100? " << (obj->contains(100) ? "true" : "false") << endl;
    cout << "Contains 1000? " << (obj->contains(1000) ? "true" : "false") << endl;
    cout << "Contains 1001? " << (obj->contains(1001) ? "true" : "false") << endl;
    cout << "Contains 1? " << (obj->contains(1) ? "true" : "false") << endl << endl;
    
    // Test Case 5: Remove non-existent element
    cout << "Test Case 5: Remove Non-existent Element" << endl;
    obj->remove(999);
    cout << "After trying to remove 999 (doesn't exist):" << endl;
    cout << "Contains 100? " << (obj->contains(100) ? "true" : "false") << endl << endl;
    
    cout << "===== All Tests Completed =====" << endl;
    
    delete obj;
    return 0;
}