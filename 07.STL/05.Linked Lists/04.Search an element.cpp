/*
    Searching for an Element in a Linked List:

    - Searching means checking if a particular value exists in the list.
    - If the value is found in any node, return true (or 1).
    - If we reach the end without finding it, return false (or 0).

    Intuition:
    - Start from the head and traverse node by node.
    - Compare the `data` of each node with the target value.
    - If a match is found, we can return immediately (early exit).
    - Otherwise, continue until the end of the list.

    Time Complexity:
    - Best Case: O(1) → if the element is at the head.
    - Worst Case: O(n) → if the element is at the end or not present.

    Note:
    - Always use a temporary pointer to traverse.
    - The original head must not be modified.
*/

#include <iostream>
using namespace std;

// Definition of a node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Function to search for a given value in the list
bool searchElement(Node* head, int target) {
    Node* temp = head;  // Temporary pointer for traversal

    while (temp != nullptr) {
        if (temp->data == target) {
            return true;  // Element found
        }
        temp = temp->next;  // Move to the next node
    }

    return false;  // Element not found after full traversal
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
    int arr[] = {3, 8, 12, 17, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);

    traverseLinkedList(head);

    int target1 = 12;
    int target2 = 25;

    cout << "Is " << target1 << " in the list? " 
         << (searchElement(head, target1) ? "Yes" : "No") << endl;

    cout << "Is " << target2 << " in the list? " 
         << (searchElement(head, target2) ? "Yes" : "No") << endl;

    return 0;
}
