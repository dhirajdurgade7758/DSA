#include <iostream>
using namespace std;

// Global variable
int globalVar = 10;

void myFunction() {
    // Local variable
    int localVar = 20;
    cout << "Inside myFunction:" << endl;
    cout << "Local variable (localVar): " << localVar << endl; // Accessible
    cout << "Global variable (globalVar): " << globalVar << endl; // Accessible
}

int main() {
    cout << "Inside main:" << endl;
    cout << "Global variable (globalVar): " << globalVar << endl; // Accessible
    // cout << "Local variable (localVar): " << localVar << endl; // Error: localVar is not accessible here

    myFunction();

    // Uncommenting the line below will cause an error because localVar is not accessible here
    // cout << "Local variable (localVar): " << localVar << endl; // Error: localVar is not defined

    return 0;
}
