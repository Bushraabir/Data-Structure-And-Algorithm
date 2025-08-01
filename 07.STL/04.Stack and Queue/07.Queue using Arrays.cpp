#include <iostream>
using namespace std;

class Queue {
private:
    int* queue;        // Pointer to array holding queue elements
    int capacity;      // Fixed maximum size of the queue
    int start;         // Index of the front element
    int end;           // Index of the rear element
    int current_size;  // Number of elements currently in the queue

public:
    // Constructor: Initialize queue with fixed capacity and pointers
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        start = -1;          // Queue initially empty, so start = -1
        end = -1;            // Queue initially empty, so end = -1
        current_size = 0;    // No elements at the start
    }

    // Destructor: Free allocated memory
    ~Queue() {
        delete[] queue;
    }

    // Push operation: Add element to the rear of the queue
    void push(int value) {
        // Check if queue is full (capacity reached)
        if (current_size == capacity) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }

        // If this is the first element to enqueue, initialize start and end to 0
        if (current_size == 0) {
            start = 0;
            end = 0;
        } else {
            // Move end pointer in circular fashion
            end = (end + 1) % capacity;
        }

        // Insert new element at end position
        queue[end] = value;

        // Increment current size
        current_size++;
    }

    // Pop operation: Remove element from the front of the queue
    void pop() {
        // Check if queue is empty to avoid underflow
        if (current_size == 0) {
            cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
            return;
        }

        // If there is only one element, reset queue to empty state
        if (current_size == 1) {
            start = -1;
            end = -1;
            current_size = 0;
        } else {
            // Move start pointer in circular fashion
            start = (start + 1) % capacity;
            current_size--;
        }
    }

    // Top operation (peek): Return element at the front of the queue
    int front() {
        if (current_size == 0) {
            cout << "Queue is empty. No front element." << endl;
            return -1; // Or throw exception based on design
        }
        return queue[start];
    }

    // Size operation: Return number of elements in the queue
    int size() {
        return current_size;
    }

    // Utility function: Check if the queue is empty
    bool isEmpty() {
        return current_size == 0;
    }
};

int main() {
    Queue q(5);  // Create queue with capacity 5

    cout << "Enqueue elements: 10, 20, 30" << endl;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Expected: 10
    cout << "Queue size: " << q.size() << endl;     // Expected: 3

    cout << "Dequeue an element" << endl;
    q.pop();

    cout << "Front element after dequeue: " << q.front() << endl; // Expected: 20
    cout << "Queue size after dequeue: " << q.size() << endl;     // Expected: 2

    // Dequeue remaining elements
    q.pop();
    q.pop();

    cout << "Attempt to dequeue from empty queue:" << endl;
    q.pop();  // Should print underflow warning

    return 0;
}
