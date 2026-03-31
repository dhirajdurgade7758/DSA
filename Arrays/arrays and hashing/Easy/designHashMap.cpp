#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
private:
    int size = 1000;

    // Each bucket stores (key, value)
    vector<list<pair<int, int>>> table;

public:
    MyHashMap() {
        table.resize(size);
    }
    
    void put(int key, int value) {
        int i = key % size;

        // Check if key already exists → update
        for (auto &p : table[i]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        // If not found → insert new pair
        table[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = key % size;

        for (auto &p : table[i]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1; // not found
    }
    
    void remove(int key) {
        int i = key % size;

        for (auto it = table[i].begin(); it != table[i].end(); it++) {
            if (it->first == key) {
                table[i].erase(it);
                return;
            }
        }
    }
};

int main() {
    cout << "===== Design HashMap - LeetCode 706 =====" << endl << endl;
    
    MyHashMap* obj = new MyHashMap();
    
    // Test Case 1: Basic put and get operations
    cout << "Test Case 1: Basic Put and Get Operations" << endl;
    obj->put(1, 1);
    obj->put(2, 2);
    cout << "After putting (1,1) and (2,2):" << endl;
    cout << "Get 1? " << obj->get(1) << endl;
    cout << "Get 2? " << obj->get(2) << endl;
    cout << "Get 3? " << obj->get(3) << " (not found)" << endl << endl;
    
    // Test Case 2: Update existing key
    cout << "Test Case 2: Update Existing Key" << endl;
    obj->put(2, 1);
    cout << "After updating key 2 with value 1:" << endl;
    cout << "Get 2? " << obj->get(2) << endl << endl;
    
    // Test Case 3: Remove operations
    cout << "Test Case 3: Remove Operations" << endl;
    obj->remove(2);
    cout << "After removing key 2:" << endl;
    cout << "Get 2? " << obj->get(2) << " (not found)" << endl;
    cout << "Get 1? " << obj->get(1) << endl << endl;
    
    // Test Case 4: Multiple operations with hash collisions
    cout << "Test Case 4: Hash Collisions (keys that hash to same bucket)" << endl;
    obj->put(1000, 100);
    obj->put(1001, 101);
    obj->put(2000, 200);
    cout << "After putting (1000,100), (1001,101), (2000,200):" << endl;
    cout << "Get 1000? " << obj->get(1000) << endl;
    cout << "Get 1001? " << obj->get(1001) << endl;
    cout << "Get 2000? " << obj->get(2000) << endl << endl;
    
    // Test Case 5: Update and remove with collisions
    cout << "Test Case 5: Update and Remove with Collisions" << endl;
    obj->put(1001, 999);
    cout << "After updating (1001) to 999:" << endl;
    cout << "Get 1001? " << obj->get(1001) << endl;
    obj->remove(1001);
    cout << "After removing 1001:" << endl;
    cout << "Get 1001? " << obj->get(1001) << " (not found)" << endl;
    cout << "Get 1000? " << obj->get(1000) << " (should still exist)" << endl << endl;
    
    // Test Case 6: Remove non-existent key
    cout << "Test Case 6: Remove Non-existent Key" << endl;
    obj->remove(9999);
    cout << "After trying to remove non-existent key 9999:" << endl;
    cout << "Get 1000? " << obj->get(1000) << " (should still exist)" << endl << endl;
    
    // Test Case 7: Large key and value
    cout << "Test Case 7: Large Key and Value" << endl;
    obj->put(1000000, 999999);
    cout << "After putting (1000000, 999999):" << endl;
    cout << "Get 1000000? " << obj->get(1000000) << endl << endl;
    
    cout << "===== All Tests Completed =====" << endl;
    
    delete obj;
    return 0;
}