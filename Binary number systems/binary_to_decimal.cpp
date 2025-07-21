#include<iostream>
using namespace std;

// Function to convert a binary number to decimal
int binary_to_decimal(int binaryNum) {
    int rem, ans = 0, pow = 1; // Initialize remainder, final answer, and power of 2

    // Loop until the binary number becomes 0
    while (binaryNum > 0) {
        rem = binaryNum % 10;   // Get the last digit of the binary number (0 or 1)
        ans += rem * pow;       // Add the binary digit times the corresponding power of 2 to the result
        binaryNum /= 10;        // Remove the last digit of the binary number
        pow *= 2;               // Increase the power of 2 for the next binary digit
    }
    return ans; // Return the final decimal number
}

int main() {
    // Test the function with binary number 1101 (which is 13 in decimal)
    cout << binary_to_decimal(1101);
}
