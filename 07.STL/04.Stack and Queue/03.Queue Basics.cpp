/*
    A queue is a **container adapter** in C++ STL that follows the **FIFO (First In First Out)** principle.
    - This means the first element inserted is the first one to be removed.
    - You cannot access elements in the middle directly (no indexing).
    - Only the front and back of the queue can be accessed.
    - Operations like push, emplace, pop, front, back, size, and empty are supported.
    - All operations are usually performed in O(1) time complexity.

    Internally, `std::queue` uses `deque` by default as its underlying container.
    It can also be configured to use `list`.
*/

// Helper function to show current state of the queue
//  ***** Note: queue cannot be directly iterated without modifying it *****

#include <iostream>
#include <queue>    // For using queue container

using namespace std;

void showQueueInfo(const string& message, const queue<int>& q) {
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
    // Declaring a queue
    queue<int> myQueue;
    cout << "Queue declared as 'myQueue'." << endl;
    showQueueInfo("Initial state of myQueue", myQueue);

    // Adding elements to the queue using push() and emplace()
    myQueue.push(10);
    showQueueInfo("After push(10)", myQueue);

    myQueue.push(20);
    showQueueInfo("After push(20)", myQueue);

    myQueue.emplace(30); // Preferred over push for efficiency
    showQueueInfo("After emplace(30)", myQueue);

    myQueue.push(40);
    showQueueInfo("After push(40)", myQueue);

    /*
        Queue structure (front to back):

        Front -> 10
                  20
                  30
        Back  ->  40
    */

    // Accessing the front and back elements
    cout << "\nAccessing front element using myQueue.front(): " << myQueue.front() << endl;
    cout << "Accessing back element using myQueue.back(): " << myQueue.back() << endl;
    showQueueInfo("State after front() and back() (no change to queue)", myQueue);

    return 0;
}
