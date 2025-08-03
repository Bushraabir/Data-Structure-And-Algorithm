#include <iostream>
#include <stack>
using namespace std;

// Same helper function from part 1
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
    // Re-initialize stack with multiple elements
    stack<int> St;
    St.push(10);
    St.push(20);
    St.emplace(30);
    St.push(40);

    // Removing elements using pop() (LIFO behavior)
    cout << "\nDemonstrating LIFO behavior with pop():" << endl;

    cout << "Popping top element (" << St.top() << ")" << endl;
    St.pop(); // Removes 40
    showStackInfo("After first pop()", St);

    cout << "Popping top element (" << St.top() << ")" << endl;
    St.pop(); // Removes 30
    showStackInfo("After second pop()", St);

    cout << "Popping top element (" << St.top() << ")" << endl;
    St.pop(); // Removes 20
    showStackInfo("After third pop()", St);

    cout << "Popping top element (" << St.top() << ")" << endl;
    St.pop(); // Removes 10
    showStackInfo("After fourth pop()", St);

    // Final check after removing all elements
    showStackInfo("Final state of myStack", St);

    return 0;
}
