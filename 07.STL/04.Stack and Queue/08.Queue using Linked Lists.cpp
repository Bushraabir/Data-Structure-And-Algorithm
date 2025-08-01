#include <iostream>
using namespace std;

class Queue {
private:
    // Node structure for linked list
    struct Node {
        int data;     // Value stored in the node
        Node* next;   // Pointer to the next node in the queue
    };

    Node* start;    // Pointer to the front node of the queue
    Node* end;      // Pointer to the rear node of the queue
    int size;       // Number of elements currently in the queue

public:
    // Constructor: Initialize empty queue
    Queue() {
        start = nullptr;  // start points to null indicating empty queue
        end = nullptr;    // end points to null indicating empty queue
        size = 0;         // size initialized to 0
    }

    // Destructor: Free all nodes to prevent memory leak
    ~Queue() {
        while (start != nullptr) {
            pop();  // Pop all elements to free memory
        }
    }

    // Push operation: Add element to the rear of the queue
    void push(int value) {
        // Create new node dynamically
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;  // New node will be at end, so next is null

        if (start == nullptr) {
            // If queue is empty, start and end both point to new node
            start = newNode;
            end = newNode;
        } else {
            // Link the new node at the end of the queue
            end->next = newNode;
            end = newNode;  // Update end to new node
        }

        size++;  // Increment size
    }

    // Pop operation: Remove element from the front of the queue
    void pop() {
        // Check if queue is empty to avoid underflow
        if (start == nullptr) {
            cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
            return;
        }

        // Store pointer to current front node
        Node* temp = start;

        // Move start to next node
        start = start->next;

        // If queue became empty, set end to nullptr as well
        if (start == nullptr) {
            end = nullptr;
        }

        // Delete old front node to free memory
        delete temp;

        size--;  // Decrement size
    }

    // Top operation (peek): Return element at the front of the queue
    int front() {
        if (start == nullptr) {
            cout << "Queue is empty. No front element." << endl;
            return -1;  // Or handle error differently
        }
        return start->data;
    }

    // Size operation: Return number of elements in the queue
    int getSize() {
        return size;
    }

    // Utility function: Check if the queue is empty
    bool isEmpty() {
        return start == nullptr;
    }
};

int main() {
    Queue q;

    cout << "Enqueue elements: 10, 20, 30" << endl;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;   // Expected: 10
    cout << "Queue size: " << q.getSize() << endl;    // Expected: 3

    cout << "Dequeue an element" << endl;
    q.pop();

    cout << "Front element after dequeue: " << q.front() << endl;  // Expected: 20
    cout << "Queue size after dequeue: " << q.getSize() << endl;   // Expected: 2

    // Dequeue remaining elements
    q.pop();
    q.pop();

    cout << "Attempt to dequeue from empty queue:" << endl;
    q.pop();  // Should print underflow warning

    return 0;
}
