#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;      // Pointer to dynamically allocated array for stack elements
    int capacity;    // Fixed maximum size of the stack
    int top;         // Index of the current top element; -1 indicates the stack is empty

public:
    // Constructor: Initializes the stack with a fixed capacity
    Stack(int size) {
        capacity = size;
        stack = new int[capacity];  // Allocate memory for the stack array
        top = -1;                   // Set top to -1 indicating stack is initially empty
    }

    // Destructor: Releases the allocated memory to prevent memory leaks
    ~Stack() {
        delete[] stack;
    }

    // Push operation: Adds a new element to the top of the stack
    void push(int value) {
        // Check if stack is full to avoid overflow
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        // Increment top index to point to the next free position
        top++;
        // Insert the new value at the top position
        stack[top] = value;
    }

    // Pop operation: Removes the element from the top of the stack
    void pop() {
        // Check if stack is empty to avoid underflow
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return;
        }
        // Simply decrement top to "remove" the top element logically
        // The element still exists in memory but is considered outside the stack
        top--;
    }

    // Top operation (peek): Returns the element at the top without removing it
    int peek() {
        // If stack is empty, indicate there is no top element
        if (top == -1) {
            cout << "Stack is empty. No top element." << endl;
            return -1;  // Could also throw exception depending on design choice
        }
        // Return the element currently at the top index
        return stack[top];
    }

    // Size operation: Returns the number of elements currently in the stack
    int size() {
        // Since top is index, size is top + 1; returns 0 if stack is empty (top == -1)
        return top + 1;
    }

    // Utility function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    // Create a stack of capacity 5
    Stack s(5);

    // Push elements onto the stack
    cout << "Pushing elements: 10, 20, 30" << endl;
    s.push(10);  // top = 0, stack[0] = 10
    s.push(20);  // top = 1, stack[1] = 20
    s.push(30);  // top = 2, stack[2] = 30

    // Check the top element and current size
    cout << "Top element: " << s.peek() << endl; // Expected: 30
    cout << "Stack size: " << s.size() << endl;  // Expected: 3

    // Pop one element
    cout << "Popping top element" << endl;
    s.pop(); // Removes 30, top becomes 1

    cout << "Top element after pop: " << s.peek() << endl; // Expected: 20
    cout << "Stack size after pop: " << s.size() << endl;  // Expected: 2

    // Pop remaining elements
    s.pop(); // Removes 20, top = 0
    s.pop(); // Removes 10, top = -1 (stack empty)

    // Attempt to pop from empty stack (should handle underflow)
    cout << "Attempting to pop from empty stack:" << endl;
    s.pop(); // Should print underflow message

    return 0;
}
