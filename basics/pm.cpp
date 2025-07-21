#include <iostream>
using namespace std;

int main() {
    short int shortVar = 32767;  // Max value for short int
    long int longVar = 2147483647;  // Max value for long int
    unsigned int unsignedVar = 4294967295;  // Max value for unsigned int
    
    cout << "Short Int: " << shortVar << endl;
    cout << "Long Int: " << longVar << endl;
    cout << "Unsigned Int: " << unsignedVar << endl;

    return 0;
}
