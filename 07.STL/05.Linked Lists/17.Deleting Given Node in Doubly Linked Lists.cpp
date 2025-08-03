/*
    Constraint:
    - The given node will never be the head, so no need to update the head pointer.

    Logic:
    - Step 1: Let the node to be deleted be `temp`.
    - Step 2: Identify its previous node: `previous = temp->back`
             Identify its next node: `front = temp->next`

    - Edge Case (If `temp` is the tail node, i.e., front == nullptr):
        • Set `previous->next = nullptr` (disconnect from the list)
        • Set `temp->back = nullptr`

    - General Case (temp is in the middle of the list):
        • Set `previous->next = front`
        • Set `front->back = previous`

    - Step 3: Disconnect the temp node:
        • Set `temp->next = nullptr`
        • Set `temp->back = nullptr`

    - Step 4: Delete the temp node using `delete temp`

    - This function is void because the head remains unchanged.

    Time Complexity: O(1), as no traversal is needed.

    Example:
    Before: 10 <-> 20 <-> 30 <-> 40
    Delete: 30
    After: 10 <-> 20 <-> 40
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

// Function to delete a given node (not the head)
void deleteGivenNode(Node* temp) {
    if (temp == nullptr || temp->back == nullptr) return; // Invalid operation if temp is null or head

    Node* previous = temp->back;
    Node* front = temp->next;

    if (front == nullptr) {
        // Case: temp is the tail node
        previous->next = nullptr;
    } else {
        // Case: temp is a middle node
        previous->next = front;
        front->back = previous;
    }

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
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
    // Create sample doubly linked list: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    head->next = second;
    second->back = head;
    second->next = third;
    third->back = second;
    third->next = fourth;
    fourth->back = third;

    cout << "Original List: ";
    printList(head);

    // Delete node with value 30
    deleteGivenNode(third);

    cout << "After Deleting 30: ";
    printList(head);

    return 0;
}
