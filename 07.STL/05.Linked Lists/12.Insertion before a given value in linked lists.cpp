/*
    - Concept:
        Insert a new node containing a specific element before the first occurrence of a target value (val) in the linked list.

    - Process:
        Similar to "insert at K-th position", but instead of using an index (position), it’s driven by the node’s value.

    - Edge Cases and Steps:

        ▪ Head Check:
            - If the head node itself contains the target value, insert the new node before it by calling "insert at head".

        ▪ Traversal:
            1. Use a temporary pointer `temp` to traverse the list.
            2. Instead of using a counter, we check:
                   temp->next->data == val
               so that `temp` stops at the node just before the target value.
            3. Once the condition is met:
                - Create a new node with the given `element`.
                - Set `newNode->next = temp->next` (point to the target node).
                - Set `temp->next = newNode` (link the node before it to the new node).

    - Assumption:
        The target value is guaranteed to exist in the list.

    - Time Complexity:
        O(N), where N is the number of nodes before the target value.
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Insert at head utility
Node* insertAtHead(Node* head, int element) {
    Node* newNode = new Node(element, head);
    return newNode;
}

// Insert before a specific value in the list
Node* insertBeforeValue(Node* head, int targetValue, int element) {
    // Case 1: Insert before head
    if (head == nullptr) return head;

    if (head->data == targetValue) {
        return insertAtHead(head, element);
    }

    // Traverse to node before the target value
    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != targetValue) {
        temp = temp->next;
    }

    // Edge: Just in case value not found (shouldn't happen if value is guaranteed)
    if (temp->next == nullptr) {
        cout << "Target value not found in the list.\n";
        return head;
    }

    // Create and insert the new node
    Node* newNode = new Node(element, temp->next);
    temp->next = newNode;

    return head;
}

// Utility: Convert array to linked list
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

// Utility: Traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* temp = head;

    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "-> NULL" << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

    int targetValue = 30;
    int element = 99;

    head = insertBeforeValue(head, targetValue, element);
    cout << "After inserting " << element << " before value " << targetValue << ":\n";
    traverseLinkedList(head);

    return 0;
}
