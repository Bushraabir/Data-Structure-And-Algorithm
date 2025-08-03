/*
    ▪ Edge Cases:
        • If K is 1: it means inserting before the head,
          so we call the "insert before head" function.
        • If K is equal to the length of the list + 1 (inserting before tail),
          the same logic applies, but we focus on the general case where 1 < K < n.

    ▪ General Case:
        • Traverse the list while counting nodes to find the Kth node (temp).
        • Keep track of the previous node (temp->back).
        • Create a new node with the given value.
        • Set newNode->next = temp and newNode->back = prev.
        • Update prev->next to newNode.
        • Update temp->back to newNode.
        • Return the head.

    ▪ Time Complexity: O(n), since traversal may go up to K.

    ▪ Example:
        List: 10 <-> 20 <-> 30 <-> 40
        Insert 25 before position 3 (i.e., before 30)
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

// Insert before head helper
Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val);
    newHead->next = head;
    newHead->back = nullptr;

    if (head != nullptr) {
        head->back = newHead;
    }

    return newHead;
}

// Function to insert before Kth node
Node* insertBeforeKth(Node* head, int k, int val) {
    // Edge case: inserting before head
    if (k == 1) return insertBeforeHead(head, val);

    Node* temp = head;
    int count = 1;

    // Traverse to the Kth node
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    // If k is more than length, we do nothing
    if (temp == nullptr) return head;

    // Get previous node
    Node* prev = temp->back;

    // Create new node
    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->back = prev;

    // Update links
    if (prev != nullptr) prev->next = newNode;
    temp->back = newNode;

    return head;
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

    // Insert 25 before position 3
    head = insertBeforeKth(head, 3, 25);

    cout << "After inserting 25 before 3rd node: ";
    printList(head);

    return 0;
}
