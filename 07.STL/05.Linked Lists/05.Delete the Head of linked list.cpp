/*
    - Concept:
        To delete the head, we need to make the second node the new head.

    - Steps:
        1. If the list is empty (head == nullptr), there's nothing to delete — return nullptr.
        2. Store the current head in a temporary pointer.
        3. Move the head pointer to the second node (head = head->next).
        4. Free the memory of the old head node using `delete` (important in C++).

    - Edge Case:
        - If the list is already empty, no operation should be done.
    
    - Return:
        - The new head of the modified list.

    - Time Complexity:
        O(1) — Deletion of head is done in constant time.
*/

#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Function to delete the head node of a linked list
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        // List is already empty
        return nullptr;
    }

    Node* temp = head;       // Store current head
    head = head->next;       // Move head to the next node
    delete temp;             // Free memory of the original head

    return head;             // Return new head
}

// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* temp = head;

    cout << "Linked List elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "-> NULL" << endl;
}

// Utility function to convert array into a linked list
Node* convertArrayToLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

   
    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

   
    head = deleteHead(head);
    cout << "After deleting head:\n";
    traverseLinkedList(head);

    return 0;
}
