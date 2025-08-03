/*
    A Doubly Linked List is a linear data structure similar to a Singly Linked List,
    but it allows movement in **both forward and backward directions**.

    Structure of a node in Doubly Linked List:
    - Each node has 3 parts:
        1. `data` — the value stored in the node
        2. `next` — pointer to the next node
        3. `back` — pointer to the previous node

    Why use Doubly Linked List over Singly Linked List?
    - In a singly linked list, you can only move forward.
    - In a doubly linked list, you can go forward and backward, which helps in scenarios like:
        - Browser history navigation
        - Undo/Redo functionality
        - Efficient deletion of nodes in both directions

    Key Concepts:
    - Convert an array into a doubly linked list
    - Traverse forward and backward
    - Visualize each node as having both “next” and “back” arrows

    The first node is called the head.
    The last node is called the tail.
    The tail’s `next` pointer is set to nullptr.
    The head’s `back` pointer is set to nullptr.
*/

#include <iostream>
using namespace std;

// Definition of a Node in a Doubly Linked List
struct Node {
    int data;         // Value in the node
    Node* next;       // Points to the next node
    Node* back;       // Points to the previous node

    // Constructor to initialize data and pointers
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

/*
    Explanation of Pointer Use:
    - node.next and node.back are just normal pointer variables inside an object.
    - nodePtr->next and nodePtr->back are used when you're accessing members via a pointer.
    - Use `.` with object, and `->` with pointer to object.
*/

// Convert an array into a doubly linked list
Node* convertArrayToDLL(int arr[], int n) {
    if (n == 0) return nullptr;

    // Step 1: Create head node using first array element
    Node* head = new Node(arr[0]);
    Node* prev = head;  // Keeps track of last created node

    // Step 2: Loop through remaining elements
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);  // New node
        temp->back = prev;              // Link temp to previous node
        prev->next = temp;              // Link previous node to temp
        prev = temp;                    // Move prev to temp
    }

    return head;  // Return pointer to head of DLL
}

// Print the doubly linked list forward
void printForward(Node* head) {
    cout << "Doubly Linked List (forward): ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Print the doubly linked list backward from tail
void printBackward(Node* tail) {
    cout << "Doubly Linked List (backward): ";
    while (tail) {
        cout << tail->data << " ";
        tail = tail->back;
    }
    cout << "\n";
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert array to doubly linked list
    Node* head = convertArrayToDLL(arr, n);
    cout << "Doubly Linked List created from array.\n";

    // Print forward
    printForward(head);

    // Move to tail
    Node* tail = head;
    while (tail->next) tail = tail->next;

    // Print backward
    printBackward(tail);

    return 0;
}

// Note: Always free the memory after use to prevent memory leaks in real applications.
