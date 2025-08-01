#include <iostream>
using namespace std;

class Stack {
private:
    // Node structure for linked list
    struct Node {
        int data;    // Value stored in the node
        Node* next;  // Pointer to the next node in the stack
    };

    Node* top;    // Pointer to the top node of the stack
    int size;     // Number of elements currently in the stack

public:
    // Constructor: Initialize an empty stack
    Stack() {
        top = nullptr;  // top points to null meaning stack is empty
        size = 0;       // size is 0 initially
    }

    // Destructor: Free all nodes to prevent memory leak
    ~Stack() {
        while (top != nullptr) {
            pop();  // Pop all elements to free memory
        }
    }

    // Push operation: Add element to the top of the stack
    void push(int value) {
        // Create a new node dynamically
        Node* newNode = new Node();
        newNode->data = value;

        // Link new node to the current top
        newNode->next = top;

        // Update top pointer to new node
        top = newNode;

        // Increment size
        size++;
    }

    // Pop operation: Remove the top element from the stack
    void pop() {
        // Check if stack is empty to avoid underflow
        if (top == nullptr) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return;
        }

        // Store pointer to current top node
        Node* temp = top;

        // Move top to the next node in the list
        top = top->next;

        // Delete old top node to free memory
        delete temp;

        // Decrement size
        size--;
    }

    // Top operation (peek): Return the value of the top element
    int peek() {
        // Check if stack is empty
        if (top == nullptr) {
            cout << "Stack is empty. No top element." << endl;
            return -1;  // Or handle error as preferred
        }
        return top->data;
    }

    // Size operation: Return number of elements in the stack
    int getSize() {
        return size;
    }

    // Utility function: Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;

    cout << "Pushing elements: 10, 20, 30" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;    // Expected: 30
    cout << "Stack size: " << s.getSize() << endl;  // Expected: 3

    cout << "Popping top element" << endl;
    s.pop();

    cout << "Top element after pop: " << s.peek() << endl;  // Expected: 20
    cout << "Stack size after pop: " << s.getSize() << endl; // Expected: 2

    // Pop remaining elements
    s.pop();
    s.pop();

    cout << "Attempting to pop from empty stack:" << endl;
    s.pop();  // Should print underflow message

    return 0;
}
