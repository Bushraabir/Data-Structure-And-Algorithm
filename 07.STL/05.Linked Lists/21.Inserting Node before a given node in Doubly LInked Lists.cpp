/*
    ▪ Constraint:
        • It's guaranteed that the given node is never the head.
        • This means the head of the linked list will not change.

    ▪ Logic:
        • Given the node (before which to insert), identify its previous node (node->back).
        • Create a new node with the given value.
        • Set newNode->next = node.
        • Set newNode->back = prev.
        • Update prev->next = newNode.
        • Update node->back = newNode.
        • Since head remains unchanged, this function returns void.

    ▪ Time Complexity: O(1), since no traversal is required when node is already known.

    ▪ Example:
        List: 10 <-> 20 <-> 30 <-> 40
        Insert 25 before node 30
        Result: 10 <-> 20 <-> 25 <-> 30 <-> 40
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

// Function to insert before a given node (not head)
void insertBeforeGivenNode(Node* node, int val) {
    if (node == nullptr || node->back == nullptr) return;  // Safety check

    Node* prev = node->back;
    Node* newNode = new Node(val);

    newNode->next = node;
    newNode->back = prev;
    prev->next = newNode;
    node->back = newNode;
}

// Utility function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Initial list: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    head->next = second;
    second->back = head;
    second->next = third;
    third->back = second;
    third->next = fourth;
    fourth->back = third;

    cout << "Original list: ";
    printList(head);

    // Insert 25 before node 30
    insertBeforeGivenNode(third, 25);

    cout << "After inserting 25 before node 30: ";
    printList(head);

    return 0;
}
