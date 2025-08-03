/*
 * Problem: Reverse a Doubly Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a doubly linked list (DLL), reverse the list.
 * You must reverse the actual links between nodes—not just the data.
 *
 * Example:
 * Input: 4 <-> 2 <-> 3 <-> 1
 * Output: 1 <-> 3 <-> 2 <-> 4
 *
 * Intuition:
 * ----------
 * 1. Naive Solution (Two-Pass, Using Stack):
 *    - Instead of modifying pointers, reverse the data inside the nodes.
 *
 *    Step 1: Push All Data to Stack
 *      • Traverse the DLL from head to tail.
 *      • Push each node’s data to a stack.
 *      • At the end, the stack has elements in reverse order.
 *
 *    Step 2: Replace Node Data with Stack Elements
 *      • Re-traverse the list from head to tail.
 *      • Replace each node’s data with top of the stack (pop).
 *      • This reverses the data, not the structure.
 *
 *    Time Complexity: O(N)
 *    Space Complexity: O(N) (extra space for stack)
 *
 * 2. Optimal Solution (One-Pass, In-Place Link Reversal):
 *    - Reverse the DLL by swapping the `next` and `back` pointers in one traversal.
 *
 *    Core Idea:
 *      • For each node:
 *          - Swap its next and back pointers.
 *          - Move to the next original node using updated `back` pointer.
 *
 *    Traversal Logic:
 *      • If `curr` is the current node:
 *          - Save `curr->back` as temp.
 *          - Set `curr->back = curr->next`.
 *          - Set `curr->next = temp`.
 *          - Move: `curr = curr->back`.
 *
 *    After traversal:
 *      • The last node processed (tail) becomes the new head.
 *
 *    Time Complexity: O(N)
 *    Space Complexity: O(1)
 */

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int val) {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

// 1. Naive Approach: Reverse by data using a stack
Node* reverseByStack(Node* head) {
    if (!head || !head->next) return head;

    stack<int> s;
    Node* temp = head;

    // Step 1: Push all data into stack
    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }

    // Step 2: Replace node data with stack elements
    temp = head;
    while (temp) {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }

    return head;
}

// 2. Optimal Approach: Reverse by changing links
Node* reverseDLL(Node* head) {
    if (!head || !head->next) return head;

    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        // Swap the next and back pointers
        Node* temp = curr->back;
        curr->back = curr->next;
        curr->next = temp;

        // Move to next node using updated back pointer
        prev = curr;
        curr = curr->back;
    }

    // prev is now pointing to the new head (original tail)
    return prev;
}

// Utility function to print the DLL
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(4);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(1);

    head->next = node2;
    node2->back = head;
    node2->next = node3;
    node3->back = node2;
    node3->next = node4;
    node4->back = node3;

    cout << "Original List: ";
    printList(head);

    // Naive solution
    Node* byStack = reverseByStack(head);
    cout << "Reversed (by stack/data): ";
    printList(byStack);

    // Reverse again to restore original before optimal reversal
    head = reverseByStack(byStack);

    // Optimal solution
    Node* optimal = reverseDLL(head);
    cout << "Reversed (by links): ";
    printList(optimal);

    return 0;
}
