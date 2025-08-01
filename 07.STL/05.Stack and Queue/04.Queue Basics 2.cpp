#include <iostream>
#include <queue>
using namespace std;

// Helper function to show info about the queue
void showQueueInfo(const string& message, queue<int> q) {
    cout << message << endl;
    if (!q.empty()) {
        cout << "  Front element: " << q.front() << endl;
        cout << "  Back element: " << q.back() << endl;
    } else {
        cout << "  Queue is empty." << endl;
    }
    cout << "  Queue size: " << q.size() << endl;
    cout << "  Is queue empty? (0 = false, 1 = true): " << q.empty() << endl;
    cout << "-----------------------------------" << endl;
}

int main() {
    // Initialize a queue and add elements
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.emplace(30);  // More efficient than push()
    Q.push(40);

    // Show initial state
    showQueueInfo("Initial queue state:", Q);

    // Demonstrate FIFO behavior
    cout << "\nDemonstrating FIFO behavior with pop():" << endl;

    cout << "Removing front element (" << Q.front() << ")" << endl;
    Q.pop(); // Removes 10
    showQueueInfo("After first pop()", Q);

    cout << "Removing front element (" << Q.front() << ")" << endl;
    Q.pop(); // Removes 20
    showQueueInfo("After second pop()", Q);

    cout << "Removing front element (" << Q.front() << ")" << endl;
    Q.pop(); // Removes 30
    showQueueInfo("After third pop()", Q);

    cout << "Removing front element (" << Q.front() << ")" << endl;
    Q.pop(); // Removes 40
    showQueueInfo("After fourth pop()", Q);

    // Final check after removing all elements
    showQueueInfo("Final state of queue", Q);

    return 0;
}
