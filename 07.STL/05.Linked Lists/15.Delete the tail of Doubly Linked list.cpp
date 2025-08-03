/*
    Edge Cases:
    - If the list is empty (i.e., head == nullptr):
        • Nothing to delete, simply return nullptr.
    - If the list contains only one node (i.e., head->next == nullptr):
        • Delete that node and return nullptr (list becomes empty).

    General Case (More than One Node):
    - Step 1: Initialize a pointer `tail` to head and traverse to the end (i.e., until tail->next == nullptr).
    - Step 2: Set `newTail = tail->back` → the second last node.
    - Step 3: Disconnect the last node:
        • Set `tail->back = nullptr`.
        • Set `newTail->next = nullptr`.
    - Step 4: Delete the original tail node using `delete tail`.
    - Step 5: Return the unchanged head (since only tail was removed).

    Time Complexity: O(N), since we may need to traverse the entire list.

    Example:
    Before: 10 <-> 20 <-> 30
    After deleting tail: 10 <-> 20
*/

#include <iostream>
using namespace std;

// Node definition for doubly linked list
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

// Function to delete the tail node of a doubly linked list
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;        // Case 1: Empty list

    if (head->next == nullptr) {                // Case 2: Only one node
        delete head;
        return nullptr;
    }

    Node* tail = head;

    // Traverse to the last node
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* newTail = tail->back;     // Second last node
    newTail->next = nullptr;        // Disconnect last node
    tail->back = nullptr;
    delete tail;                    // Free memory of original tail

    return head;                    // Head remains the same
}

// Utility function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a sample doubly linked list: 10 <-> 20 <-> 30
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    head->next = second;
    second->back = head;
    second->next = third;
    third->back = second;

    cout << "Original List: ";
    printList(head);

    head = deleteTail(head);

    cout << "After Deleting Tail: ";
    printList(head);

    return 0;
}
