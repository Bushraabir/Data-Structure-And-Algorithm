#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;  // Single queue used to simulate stack behavior

public:
    // Push operation: Adds an element to the stack
    void push(int x) {
        // Step 1: Enqueue the new element at the back of the queue
        q.push(x);

        // Step 2: Reorder the queue so that the new element is at the front
        // This is done by dequeuing all elements before the newly pushed element
        // and enqueueing them back. This effectively moves the new element to the front.
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            int frontElem = q.front();
            q.pop();
            q.push(frontElem);
        }
        // Logic:  
        // We do this to ensure the last pushed element is always at the front of the queue,
        // simulating the "top" of the stack (LIFO). Without this step, queue would behave FIFO.
    }

    // Pop operation: Removes the element from the top of the stack
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return;
        }
        // Since the last pushed element is always at the front after push,
        // popping from the queue simulates popping from the stack
        q.pop();
    }

    // Top operation: Returns the top element of the stack without removing it
    int top() {
        if (q.empty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Or handle error differently
        }
        // The front of the queue is the logical top of the stack
        return q.front();
    }

    // Size operation: Returns the current size of the stack
    int size() {
        return q.size();
    }

    // Utility function: Check if the stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Stack s;

    cout << "Pushing elements: 10, 20, 30" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;    // Expected: 30
    cout << "Stack size: " << s.size() << endl;    // Expected: 3

    cout << "Popping top element" << endl;
    s.pop();

    cout << "Top element after pop: " << s.top() << endl;  // Expected: 20
    cout << "Stack size after pop: " << s.size() << endl;  // Expected: 2

    return 0;
}
