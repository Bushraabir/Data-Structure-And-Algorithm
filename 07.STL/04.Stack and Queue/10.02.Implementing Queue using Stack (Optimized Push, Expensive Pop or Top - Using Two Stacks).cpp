#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> S1;  // Stack for push operations (input stack)
    stack<int> S2;  // Stack for pop/top operations (output stack)

    // Helper function to transfer elements from S1 to S2
    void transferS1toS2() {
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }
    }

public:
    // Push operation: Add element to the rear of the queue
    void push(int x) {
        // Simply push onto S1
        S1.push(x);
        // Logic:
        // Push is O(1) because we just add to S1 without rearranging elements
    }

    // Pop operation: Remove element from the front of the queue
    void pop() {
        // If S2 is empty, transfer all elements from S1 to S2
        if (S2.empty()) {
            if (S1.empty()) {
                cout << "Queue Underflow! Cannot dequeue from empty queue." << endl;
                return;
            }
            transferS1toS2();
        }
        // Pop from S2, which represents the front of the queue
        S2.pop();
    }

    // Front operation: Return the front element of the queue
    int front() {
        // If S2 is empty, transfer elements from S1 to S2
        if (S2.empty()) {
            if (S1.empty()) {
                cout << "Queue is empty. No front element." << endl;
                return -1; // Or handle error differently
            }
            transferS1toS2();
        }
        // Top of S2 is the front element of the queue
        return S2.top();
    }

    // Size operation: Return number of elements in the queue
    int size() {
        return S1.size() + S2.size();
    }

    // Utility function: Check if the queue is empty
    bool isEmpty() {
        return S1.empty() && S2.empty();
    }
};

int main() {
    Queue q;

    cout << "Enqueue elements: 10, 20, 30" << endl;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;   // Expected: 10
    cout << "Queue size: " << q.size() << endl;       // Expected: 3

    cout << "Dequeue an element" << endl;
    q.pop();

    cout << "Front element after dequeue: " << q.front() << endl;  // Expected: 20
    cout << "Queue size after dequeue: " << q.size() << endl;      // Expected: 2

    return 0;
}
