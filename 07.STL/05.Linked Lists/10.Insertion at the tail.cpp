/*
    - Concept:
        Add a new node at the very end of the linked list.

    - Process:
        ▪ Edge Case (Empty List):
            - If the list is empty (head == nullptr), create a new node.
            - Make it the head of the list.
            - Its `next` will naturally be null.

        ▪ Non-Empty List:
            1. Initialize a pointer `temp` to the head.
            2. Traverse the list until `temp->next` is null.
               This means `temp` now points to the last node.
            3. Create a new node with the given value and `next` as null.
            4. Set `temp->next` to point to the newly created node.

    - Return Value:
        The head of the linked list (important in case the list was empty originally).

    - Time Complexity:
        O(N) — where N is the number of nodes in the list (since we may need to go till the last node).
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

// Function to insert a node at the tail
Node* insertAtTail(Node* head, int val) {
    // Step 1: Create a new node with the given value
    Node* newNode = new Node(val, nullptr);

    // Edge Case: If the list is empty, return newNode as head
    if (head == nullptr) {
        return newNode;
    }

    // Step 2: Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Step 3: Attach the new node at the end
    temp->next = newNode;

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
    int arr[] = {10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

    int valToInsert = 40; // Value to be inserted at the tail
    head = insertAtTail(head, valToInsert);

    cout << "After inserting " << valToInsert << " at tail:\n";
    traverseLinkedList(head);

    return 0;
}
