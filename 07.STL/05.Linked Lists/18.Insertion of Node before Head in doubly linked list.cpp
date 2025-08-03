/*
    ▪ Purpose: Insert a new node at the very beginning of the doubly linked list.

    ▪ Step-by-Step Logic:
        • A new node is created with the given value using the constructor.
        • The new node’s `next` pointer is set to point to the current head (so it comes before the old head).
        • The new node’s `back` pointer is set to `nullptr`, since it will become the first node.
        • If the head is not null, set the current head’s `back` pointer to point to the new node.
        • The new node becomes the new head, so return it.

    ▪ Time Complexity: O(1), since no traversal is required.

    ▪ Example:
        Before: 10 <-> 20 <-> 30
        Insert 5 before head
        After: 5 <-> 10 <-> 20 <-> 30
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to insert before the head
Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val);
    newHead->next = head;
    newHead->back = nullptr;

    if (head != nullptr) {
        head->back = newHead;
    }

    return newHead;
}

// Utility function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create initial list: 10 <-> 20 <-> 30
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    head->next = second;
    second->back = head;
    second->next = third;
    third->back = second;

    cout << "Original list: ";
    printList(head);

    // Insert 5 before the head
    head = insertBeforeHead(head, 5);

    cout << "After inserting 5 before head: ";
    printList(head);

    return 0;
}
