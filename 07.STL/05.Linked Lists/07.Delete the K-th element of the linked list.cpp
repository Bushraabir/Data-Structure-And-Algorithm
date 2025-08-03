/*
    - Concept:
        Deletes the node located at a specific position K (1-based index).

    - Edge Cases Handled:
        1. If the list is empty (head == nullptr), return nullptr.
        2. If K == 1, this is equivalent to deleting the head node.
        3. If K > length of the list, there is no K-th element — return original head.
        4. If K == length of the list, it becomes deletion of the tail node.

    - General Process (for K > 1 and K < length):
        1. Initialize two pointers:
            - temp → used to traverse the list
            - prev → tracks the node before temp
        2. Use a counter to count positions.
        3. Traverse the list until the counter reaches K.
        4. At that point:
            - prev points to (K−1)-th node
            - temp points to K-th node (the one to delete)
        5. Reassign: prev->next = temp->next
        6. Delete temp to free memory.

    - Time Complexity:
        O(K) — linear traversal up to the K-th node.

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

// Function to delete the K-th node in the linked list
Node* deleteKthNode(Node* head, int K) {
    if (head == nullptr) {
        // Case 1: Empty list
        return nullptr;
    }

    if (K == 1) {
        // Case 2: Delete head node
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    int count = 1;

    // Traverse until we reach the K-th node
    while (temp != nullptr && count < K) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        // Case 3: K > length of list → no deletion
        return head;
    }

    // Case 4: General case — delete the K-th node
    prev->next = temp->next;
    delete temp;

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
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = convertArrayToLinkedList(arr, n);
    traverseLinkedList(head);

    int K = 3; // Delete the 3rd node (value 15)
    head = deleteKthNode(head, K);
    cout << "After deleting " << K << "-th node:\n";
    traverseLinkedList(head);

    return 0;
}
