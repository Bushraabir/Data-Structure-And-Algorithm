/*
 * Problem: Add 1 to a Number Represented by a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given a singly linked list where each node represents a digit of a number,
 * add 1 to the number and return the new head of the list.
 *
 * Example:
 *   Input:  head = 1 -> 5 -> 9
 *   Output:         1 -> 6 -> 0
 *
 *   Input:  head = 9 -> 9 -> 9 -> 9
 *   Output:         1 -> 0 -> 0 -> 0 -> 0
 *
 * Intuition:
 * ----------
 * Addition begins from the least significant digit (right), but linked lists
 * only support forward traversal (left to right). So we use two approaches:
 *
 * 1. Brute Force (Using Reversal):
 *    - Reverse the list to access the least significant digit first.
 *    - Add 1 to the number, propagate carry as needed.
 *    - Reverse the list back to restore order.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(1)
 *
 * 2. Optimal (Using Recursion):
 *    - Recursively reach the last node (rightmost digit).
 *    - Add 1 and propagate the carry during backtracking.
 *    - Create a new head if final carry is still 1.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(N) due to recursion stack
 * 
 * 
 * 
 */

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Utility: Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

/*
 * Approach 1: Iterative Reversal Method
 * -------------------------------------
 * 1. Reverse the list
 * 2. Add 1 and handle carry
 * 3. If carry remains, add new node
 * 4. Reverse the list again
 */
Node* addOne_Iterative(Node* head) {
    head = reverseList(head);  // Step 1: Reverse

    Node* temp = head;
    int carry = 1;

    // Step 2: Add 1 with carry propagation
    while (temp) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (!carry) break;
        if (!temp->next && carry) {
            temp->next = new Node(0);  // Add dummy if needed
        }
        temp = temp->next;
    }

    // Step 3 & 4: Reverse back and return
    return reverseList(head);
}

/*
 * Approach 2: Recursive Method
 * ----------------------------
 * 1. Use recursion to go to the end
 * 2. Add 1 and propagate carry
 * 3. Add new node if carry remains after recursion
 */
int addRecursive(Node* node) {
    if (!node) return 1;  // Base case: initial carry is 1

    int carry = addRecursive(node->next);
    int sum = node->data + carry;
    node->data = sum % 10;
    return sum / 10;
}

Node* addOne_Recursive(Node* head) {
    int carry = addRecursive(head);
    if (carry) {
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

// Utility: Create list from initializer list
Node* createList(initializer_list<int> vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }
    return head;
}

// Utility: Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main: Test both methods
int main() {
    Node* list1 = createList({1, 5, 9});
    Node* list2 = createList({9, 9, 9, 9});

    cout << "Original List 1: ";
    printList(list1);
    cout << "After Add One (Iterative): ";
    printList(addOne_Iterative(list1));

    cout << "\nOriginal List 2: ";
    printList(list2);
    cout << "After Add One (Recursive): ";
    printList(addOne_Recursive(list2));

    return 0;
}
