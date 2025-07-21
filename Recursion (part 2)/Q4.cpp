#include<iostream>
using namespace std;

int towerOfHanoi(int n) {
    if (n == 0) {
        return 0; // No moves needed for zero disks
    }
    return 2 * towerOfHanoi(n - 1) + 1; // Recursive relation
}

int main() {
    cout << "Number of moves required for 3 disks: " << towerOfHanoi(3) << endl;
    return 0;
}
