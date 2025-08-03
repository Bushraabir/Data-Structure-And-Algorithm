/*
   - Concept:
        Insert a new node at a specified position K.

    - Valid Range for K:
        K can range from 1 to N+1, where N is the current length of the list.
        Example:
            - K = 1 → Insert at the head.
            - K = N+1 → Insert at the tail (after the last element).

    - Edge Cases Handled:
        ▪ If the list is empty (head == nullptr):
            - A new node can only be inserted if K == 1 (making it the head).
            - If K > 1, it's an invalid position.

        ▪ If K == 1:
            - Handled by "Insert at Head" logic.

        ▪ If K > N+1:
            - Invalid position → Do nothing (or optionally show an error).

    - General Process (for K > 1 and K <= N+1):
        1. Initialize `temp` to head and a counter (e.g., `cnt = 0`).
        2. Traverse the list until counter reaches K-2 (1-based index),
           so `temp` points to the (K-1)th node.
        3. Create a new node with the given value.
        4. Set `newNode->next` to `temp->next`.
        5. Set `temp->next` to `newNode`.

    - Time Complexity:
        O(K), since in the worst case (inserting at the tail), we traverse up to K-1 nodes.
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

// Function to insert at the head (used if K == 1)
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val, head);
    return newNode;
}

// Function to insert at K-th position (1-based indexing)
Node* insertAtPosition(Node* head, int k, int val) {
    // Case 1: Invalid position for empty list
    if (head == nullptr) {
        if (k == 1) return new Node(val, nullptr); // Insert as head
        else return head; // Invalid, do nothing
    }

    // Case 2: Insert at head
    if (k == 1) {
        return insertAtHead(head, val);
    }

    // Traverse to (k-1)th node
    Node* temp = head;
    int cnt = 1;

    while (temp != nullptr && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }

    // If temp is null, it means k is out of bounds
    if (temp == nullptr) return head;

    // Create new node and link it
    Node* newNode = new Node(val, temp->next);
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

// Utility: Traverse and print linked list
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
    int arr[] = {1, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

    int k = 3;
    int val = 99;

    head = insertAtPosition(head, k, val);
    cout << "After inserting " << val << " at position " << k << ":\n";
    traverseLinkedList(head);

    return 0;
}
