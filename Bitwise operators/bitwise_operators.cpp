#include <iostream>
using namespace std;

int main() {
    // Declare two integers
    int a = 5;  // Binary: 0101
    int b = 3;  // Binary: 0011

    // Bitwise AND
    int andResult = a & b;  // 0101 & 0011 = 0001
    cout << "Bitwise AND (5 & 3): " << andResult << endl;  // Output: 1

    // Bitwise OR
    int orResult = a | b;  // 0101 | 0011 = 0111
    cout << "Bitwise OR (5 | 3): " << orResult << endl;  // Output: 7

    // Bitwise XOR
    int xorResult = a ^ b;  // 0101 ^ 0011 = 0110
    cout << "Bitwise XOR (5 ^ 3): " << xorResult << endl;  // Output: 6

    // Bitwise NOT
    int notResult = ~a;  // ~0101 = 1010 (in 32-bit, it's -6)
    cout << "Bitwise NOT (~5): " << notResult << endl;  // Output: -6 (because of two's complement)

    // Left shift
    int leftShiftResult = a << 1;  // 0101 << 1 = 1010
    cout << "Left shift (5 << 1): " << leftShiftResult << endl;  // Output: 10

    // Right shift
    int rightShiftResult = a >> 1;  // 0101 >> 1 = 0010
    cout << "Right shift (5 >> 1): " << rightShiftResult << endl;  // Output: 2

    return 0;
}
