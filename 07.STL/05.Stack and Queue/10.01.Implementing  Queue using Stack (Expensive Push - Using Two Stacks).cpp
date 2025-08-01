#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> S1;  // Primary stack holding queue elements in correct order
    stack<int> S2;  // Auxiliary stack used during push operation to reorder elements

public:
    // Push operation: Adds an element to the rear of the queue
    void push(int x) {
        // Step 1: Move all elements from S1 to S2
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }

        // Step 2: Push the new element onto S1
        S1.push(x);

        // Step 3: Move all elements back from S2 to S1
        while (!S2.empty()) {
            S1.push(S2.top());
            S2.pop();
        }

        // Logic:
        // This rearrangement ensures the oldest element is at the top of S1,
        // simulating the front of the queue (FIFO).
        // So when we pop from S1, it's like dequeueing from the queue.
    }

    // Pop operation: Removes the front element of the queue
    void pop() {
        if (S1.empty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
            return;
        }
        S1.pop();
    }

    // Front operation: Returns the front element of the queue
    int front() {
        if (S1.empty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;  // Or handle error differently
        }
        return S1.top();
    }

    // Size operation: Returns the number of elements in the queue
    int size() {
        return S1.size();
    }

    // Utility function: Checks if the queue is empty
    bool isEmpty() {
        return S1.empty();
    }
};

int main() {
    Queue q;

    cout << "Enqueue elements: 10, 20, 30" << endl;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;    // Expected: 10
    cout << "Queue size: " << q.size() << endl;        // Expected: 3

    cout << "Dequeue an element" << endl;
    q.pop();

    cout << "Front element after dequeue: " << q.front() << endl;  // Expected: 20
    cout << "Queue size after dequeue: " << q.size() << endl;      // Expected: 2

    return 0;
}
