/*

    - Concept:
        To delete the tail node, we must find the second-to-last node and make it the new tail.


    - Steps:
        1. If the list is empty (head == nullptr), return nullptr (nothing to delete).
        2. If the list has only one node (head->next == nullptr), delete it and return nullptr.
        3. Use a temporary pointer to traverse the list until temp->next->next == nullptr.
           This ensures temp stops at the second-to-last node.
        4. Delete the last node (temp->next) to free memory.
        5. Set temp->next = nullptr to make the second-to-last node the new tail.

    - Edge Cases:
        - Empty list: return nullptr.
        - Single-node list: delete and return nullptr.

    - Return:
        - New head of the modified list (could be nullptr if list becomes empty).

    - Time Complexity:
        O(n) — because we have to traverse to the end of the list.
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

// Function to delete the tail node of a linked list
Node* deleteTail(Node* head) {
    if (head == nullptr) {
        // Case 1: Empty list
        return nullptr;
    }

    if (head->next == nullptr) {
        // Case 2: Only one node
        delete head;
        return nullptr;
    }

    Node* temp = head;
    // Traverse to the second-to-last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // temp is now the second-to-last node
    delete temp->next;     // Free the last node
    temp->next = nullptr;  // Detach the last node

    return head;
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

    head = deleteTail(head);
    cout << "After deleting tail:\n";
    traverseLinkedList(head);

    return 0;
}
