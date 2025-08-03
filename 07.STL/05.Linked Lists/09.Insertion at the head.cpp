/*
    - Concept:
        Add a new node at the very beginning of the linked list.

    - Process:
        1. Create a new node with the given value.
        2. Set the `next` pointer of this new node to point to the current head of the list.
        3. Update the `head` pointer to point to this new node — making it the new first node.

    - Edge Case:
        If the list is empty (head == nullptr), the new node simply becomes the head, and its `next` remains null.

    - Time Complexity:
        O(1) — because we’re not traversing the list; all operations are constant-time.

    - Return:
        The new head of the linked list.
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

// Function to insert a node at the head of the list
Node* insertAtHead(Node* head, int val) {
    // Step 1: Create a new node
    Node* newNode = new Node(val, nullptr);

    // Step 2: Set newNode->next to current head
    newNode->next = head;

    // Step 3: Update head to newNode
    head = newNode;

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
    int arr[] = {20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

    int valToInsert = 10; // Value to be inserted at the head
    head = insertAtHead(head, valToInsert);

    cout << "After inserting " << valToInsert << " at head:\n";
    traverseLinkedList(head);

    return 0;
}
