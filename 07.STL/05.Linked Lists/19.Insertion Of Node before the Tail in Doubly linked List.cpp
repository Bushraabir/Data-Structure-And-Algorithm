/*
    ▪ Edge Case:
        • If the list has only one node (head != null and head->next == null),
          that node is both the head and tail.
        • In that case, we simply reuse the "insert before head" logic.

    ▪ General Case (more than one element):
        • Traverse the list to find the current tail (node where next == null).
        • Identify the node just before the tail (tail->back).
        • Create a new node with the given value.
        • Set newNode->next to point to the current tail.
        • Set newNode->back to point to the previous node.
        • Update previous->next to point to newNode.
        • Update tail->back to point to newNode.
        • Return the unchanged head pointer.

    ▪ Time Complexity: O(n) due to traversal to the end.

    ▪ Example:
        Before: 10 <-> 20 <-> 30
        Insert 25 before tail (30)
        After: 10 <-> 20 <-> 25 <-> 30
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

// Helper function to insert before head
Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val);
    newHead->next = head;
    newHead->back = nullptr;

    if (head != nullptr) {
        head->back = newHead;
    }

    return newHead;
}

// Function to insert before tail
Node* insertBeforeTail(Node* head, int val) {
    // Edge case: list has only one node
    if (head == nullptr || head->next == nullptr) {
        return insertBeforeHead(head, val);
    }

    // Traverse to the tail node
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Get the previous node
    Node* prev = tail->back;

    // Create new node
    Node* newNode = new Node(val);
    newNode->next = tail;
    newNode->back = prev;

    // Update links
    prev->next = newNode;
    tail->back = newNode;

    return head;
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

    // Insert 25 before the tail
    head = insertBeforeTail(head, 25);

    cout << "After inserting 25 before tail: ";
    printList(head);

    return 0;
}
