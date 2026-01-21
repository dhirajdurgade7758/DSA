#include <iostream>
using namespace std;

class Stack {
private:
    int top;        // Index of the top element
    int capacity;   // Maximum size of stack
    int* arr;       // Array to store elements

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Stack is initially empty
    }

    // Push operation
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    // Pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! No elements to pop" << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek operation (get top element)
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);  // Creating a stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element is " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
