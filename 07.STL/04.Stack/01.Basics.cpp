#include <iostream> 
#include <stack>    // For using stack container

using namespace std;

/*
    What is a Stack?

    A stack is a **container adapter** in C++ STL that follows the **LIFO (Last In First Out)** principle.
    - This means the last element inserted is the first one to be removed.
    - You cannot access elements in the middle directly (no indexing).
    - Only the top of the stack can be accessed.
    - Operations like push, pop, top, size, and empty are supported.
    - All operations are usually performed in O(1) time complexity.

    Internally, `std::stack` uses `deque` by default as its underlying container.
    It can also be configured to use `vector` or `list`.
*/

// Helper function to show current state of the stack
// Note: Stack cannot be directly iterated without modifying it
void showStackInfo(const string& message, const stack<int>& s) {
    cout << message << endl;
    if (!s.empty()) {
        cout << "  Top element: " << s.top() << endl;
    } else {
        cout << "  Stack is empty." << endl;
    }
    cout << "  Stack size: " << s.size() << endl;
    cout << "  Is stack empty? (0 = false, 1 = true): " << s.empty() << endl;
    cout << "-----------------------------------" << endl;
}

int main() {
    // Declaring a stack
    stack<int> myStack;
    cout << "Stack declared as 'myStack'." << endl;
    showStackInfo("Initial state of myStack", myStack);

    // Adding elements to the stack using push() and emplace()
    myStack.push(10);
    showStackInfo("After push(10)", myStack);

    myStack.push(20);
    showStackInfo("After push(20)", myStack);

    myStack.emplace(30); // Preferred over push for efficiency
    showStackInfo("After emplace(30)", myStack);

    myStack.push(40);
    showStackInfo("After push(40)", myStack);

    /*
        Stack structure (top to bottom):

        Top -> 40
               30
               20
        Bottom->10
    */

    // Accessing the top element using top()
    cout << "\nAccessing top element using myStack.top(): " << myStack.top() << endl;
    showStackInfo("State after myStack.top() (no change to stack)", myStack);

    return 0;
}
