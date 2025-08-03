/*
    - Concept:
        Deletes the first node in the linked list that contains a specified value.

    - Problem Adaptation:
        This is a variation of the "delete K-th node" problem — instead of deleting by position, we delete by matching a node's value.

    - Process:
        1. Head Check:
            - If the value to delete is in the head node (head->data == target), then perform head deletion.
        2. Traversal:
            - Initialize a pointer `temp` starting from the head.
            - Traverse the list to find the node whose next node holds the value to delete.
            - Check: `temp->next->data == target`.
            - Once found, update: `temp->next = temp->next->next`, effectively skipping the matched node.
        3. Memory Management:
            - Delete the matched node to free memory.

    - Edge Cases:
        • The value is in the head node.
        • The value is somewhere in the middle or at the end.
        • The value is not present (assumed **guaranteed to be present**, but can optionally handle "not found").

    - Time Complexity:
        O(N), where N is the number of nodes — because we may need to traverse the entire list.

    - Return:
        Modified head pointer of the list after deletion.
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

// Function to delete a node by value (first occurrence)
Node* deleteByValue(Node* head, int val) {
    if (head == nullptr) {
        // Empty list
        return nullptr;
    }

    // Case 1: Value is in the head node
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    // Traverse to find the node before the one to delete
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        // Value not found — OPTIONAL handling
        cout << "Value " << val << " not found in the list.\n";
        return head;
    }

    // Case 2: Value found → delete the node
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
}

// Function to print the linked list
void traverseLinkedList(Node* head) {
    Node* temp = head;

    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "-> NULL" << endl;
}

// Utility function to convert array to linked list
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
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

    int valToDelete = 30; // Delete the node with value 30
    head = deleteByValue(head, valToDelete);

    cout << "After deleting value " << valToDelete << ":\n";
    traverseLinkedList(head);

    return 0;
}
