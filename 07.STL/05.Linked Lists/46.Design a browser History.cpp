/*
 * Problem: Design a Browser History
 *
 * Problem Statement:
 * -------------------
 * Implement a `BrowserHistory` class that simulates the back and forward navigation
 * of a web browser.
 * 
 * Class Functions:
 * - `BrowserHistory(string homepage)`: Initializes the browser with a homepage.
 * - `void visit(string url)`: Visits a new URL, clearing all forward history.
 * - `string back(int steps)`: Moves back in history up to `steps` times or until homepage.
 * - `string forward(int steps)`: Moves forward in history up to `steps` times or until the latest page.
 * 
 * Intuition:
 * ----------
 * We need a structure that allows:
 * - Insertion of new pages dynamically.
 * - Traversal both backward and forward (back and forward navigation).
 * 
 * A Doubly Linked List is perfect:
 * - Each node represents a webpage (stores a URL).
 * - `prev` pointer allows going back.
 * - `next` pointer allows moving forward.
 * - On `visit()`, we create a new node and remove all nodes ahead (i.e., clear forward history).
 * 
 * Complexity Analysis:
 * ---------------------
 * - Constructor: O(1)
 * - visit(): O(1)
 * - back(steps): O(steps)
 * - forward(steps): O(steps)
 */

#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string url) {
        this->url = url;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    Node* current; // pointer to the current page

public:
    // Constructor
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    // Visit a new page and clear forward history
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = nullptr;       // clear forward history
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    // Move back up to 'steps' pages
    string back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    // Move forward up to 'steps' pages
    string forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

/*
 * Example Usage
 */
int main() {
    BrowserHistory bh("takeuforward.org");
    bh.visit("google.com");
    bh.visit("instagram.com");
    bh.visit("facebook.com");

    cout << bh.back(1) << endl;       // instagram.com
    cout << bh.back(1) << endl;       // google.com
    cout << bh.forward(1) << endl;    // instagram.com
    bh.visit("takeuforward.com");     // clears forward history
    cout << bh.forward(2) << endl;    // takeuforward.com
    cout << bh.back(2) << endl;       // google.com
    cout << bh.back(7) << endl;       // takeuforward.org

    return 0;
}
