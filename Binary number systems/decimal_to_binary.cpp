#include<iostream>
using namespace std;

// Function to convert a decimal number to binary
int decimal_to_binary(int decimal) {
    int pow = 1;   // To keep track of powers of 10 for binary representation
    int rem = 0;   // To store remainder when dividing by 2 (binary digit)
    int ans = 0;   // Final binary result

    // Loop until the decimal number becomes 0
    while (decimal > 0) {
        rem = decimal % 2;       // Get the binary digit (remainder of decimal / 2)
        decimal = decimal / 2;   // Divide the decimal number by 2 for the next step
        ans += rem * pow;        // Add the current binary digit to the final result
        pow = pow * 10;          // Multiply power of 10 to place next binary digit correctly
    }
    return ans;  // Return the final binary number
}

int main() {
    // Test the function with decimal number 50
    cout << decimal_to_binary(50);

}
