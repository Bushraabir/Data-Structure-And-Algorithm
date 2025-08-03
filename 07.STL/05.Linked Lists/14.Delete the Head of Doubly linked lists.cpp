/*
    Edge Cases:
    - If the list is empty (i.e., head == nullptr):
        • Nothing to delete, simply return nullptr.
    - If the list contains only one node (i.e., head->next == nullptr):
        • Delete that node and return nullptr (list becomes empty).

    General Case (More than One Node):
    - Step 1: Store the current head in a temporary pointer called `prev`.
    - Step 2: Move `head` to the next node → `head = head->next`.
    - Step 3: Set `head->back = nullptr` → this is necessary because head has changed.
    - Step 4: Disconnect the previous head by setting `prev->next = nullptr`.
    - Step 5: Free the memory of the previous head using `delete prev`.
    - Step 6: Return the updated `head`.

    This operation deletes the first node in the doubly linked list and adjusts the pointers accordingly.
    - It's a constant time O(1) operation.

    Example:
    Before: 10 <-> 20 <-> 30
    After deleting head: 20 <-> 30
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

// Function to delete the head node of a doubly linked list
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;        // Case 1: Empty list

    if (head->next == nullptr) {                // Case 2: Only one node
        delete head;
        return nullptr;
    }

    Node* prev = head;          // Store old head
    head = head->next;          // Move head forward
    head->back = nullptr;       // Remove back reference
    prev->next = nullptr;       // Disconnect old head
    delete prev;                // Free memory of old head

    return head;                // Return new head
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

    head = deleteHead(head);

    cout << "After Deleting Head: ";
    printList(head);

    return 0;
}
