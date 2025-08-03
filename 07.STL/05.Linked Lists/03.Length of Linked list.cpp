/*
    Finding the Length of a Linked List:

    - Length means the total number of nodes present in the linked list.
    - To count the nodes, we need to traverse the entire list from head to tail.

    Intuition:
    - Just like traversal, we start from the head and move node by node.
    - We maintain a counter (`count`) initialized to 0.
    - For each node we visit, we increment the counter.
    - When we reach the end (`nullptr`), the counter holds the length.

    Time Complexity: O(n)
    - Because we visit each of the n nodes exactly once.

    IMPORTANT:
    - Do not move or modify the actual `head` pointer.
    - Always use a temporary pointer to walk through the list.
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

// Function to calculate the length of the linked list
int getLength(Node* head) {
    int count = 0;           // Counter to track number of nodes
    Node* temp = head;       // Temporary pointer to traverse

    while (temp != nullptr) {
        count++;             // Count current node
        temp = temp->next;   // Move to next node
    }

    return count;            // Return total number of nodes
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

// Utility to convert array into linked list
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
    int arr[] = {5, 15, 25, 35, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert array to linked list
    Node* head = convertArrayToLinkedList(arr, n);

    // Traverse and display the list
    traverseLinkedList(head);

    // Get and print the length
    cout << "Length of Linked List: " << getLength(head) << endl;

    return 0;
}
