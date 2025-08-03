/*
    Traversal in a Linked List:

    - Traversal means visiting every node in the linked list, starting from the head and moving forward.
    - This is one of the most basic and important operations in a linked list.

    Why Traversal is Needed:
    - To print or process each element.
    - To search for a value.
    - To find the length of the list or perform any analysis on the data.

    Key Intuition:
    - Unlike arrays, we cannot use indexing (like arr[i]) in a linked list.
    - We use a pointer (often called temp or current) to start from the head.
    - We move the pointer one node at a time using `temp = temp->next`.
    - We stop when we reach `nullptr`, which means we've hit the end of the list.

    WARNING:
    - Never modify the original `head` pointer directly during traversal.
    - Use a temporary pointer (`temp`) instead to avoid losing the starting reference of the list.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* temp = head;  // Start from the head

    cout << "Linked List elements: ";

    // Loop until we reach the end of the list
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    /*
       -> is used to Access a member of an object via a pointer.
       
    */

    cout << "-> NULL" << endl;  // End marker for linked list
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
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);

    // Traverse and display the list
    traverseLinkedList(head);

    return 0;
}
