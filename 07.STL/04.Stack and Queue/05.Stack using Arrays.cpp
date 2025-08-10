/*
Stack Implementation Using a Dynamic Array

Intuition:
A stack is a Last-In-First-Out (LIFO) data structure where the last element added is the first one to be removed.
This implementation uses a fixed-size dynamic array to store elements.
- 'top' keeps track of the current top index of the stack.
- When pushing, we add the element at the next available position and increment 'top'.
- When popping, we decrement 'top' to logically remove the top element.
- Peeking returns the element at 'top' without removing it.
- The stack prevents overflow (adding beyond capacity) and underflow (removing when empty).

Time Complexity:
- push(): O(1) — Insert at the top index directly.
- pop(): O(1) — Decrement the top index.
- peek(): O(1) — Access element at top index.
- size(): O(1) — Calculate size from top index.
- isEmpty(): O(1) — Check if top == -1.

Space Complexity:
- O(n) where n is the capacity of the stack (fixed size dynamic array).
*/

#include <iostream>
using namespace std;

class Stack {
private:
    int* stack;      // Pointer to dynamically allocated array for stack elements
    int capacity;    // Fixed maximum size of the stack
    int top;         // Index of the current top element; -1 means stack is empty

public:
    // Constructor: Initializes the stack with fixed capacity
    Stack(int size) {
        capacity = size;
        stack = new int[capacity];  // Allocate memory for stack
        top = -1;                   // Stack is empty initially
    }

    // Destructor: Frees allocated memory
    ~Stack() {
        delete[] stack;
    }

    // Push: Add element to the top of the stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        top++;
        stack[top] = value;
    }

    // Pop: Remove element from the top of the stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return;
        }
        top--;
    }

    // Peek: Return the top element without removing it
    int peek() {
        if (top == -1) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Could throw exception in a different design
        }
        return stack[top];
    }

    // Size: Number of elements currently in the stack
    int size() {
        return top + 1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s(5); // Stack capacity is 5

    cout << "Pushing elements: 10, 20, 30" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;   // 30
    cout << "Stack size: " << s.size() << endl;    // 3

    cout << "Popping top element" << endl;
    s.pop();

    cout << "Top element after pop: " << s.peek() << endl;  // 20
    cout << "Stack size after pop: " << s.size() << endl;   // 2

    s.pop();
    s.pop();

    cout << "Attempting to pop from empty stack:" << endl;
    s.pop();  // Underflow message

    return 0;
}
