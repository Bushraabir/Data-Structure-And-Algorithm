/*
 * Problem: Delete All Occurrences of a Key in a Doubly Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a doubly linked list and a key (integer),
 * delete **all nodes** that contain this key.
 * Return the updated head of the doubly linked list.
 *
 * Important:
 * - The head pointer must be updated if the head node(s) are deleted.
 * - All pointers must be properly re-linked to preserve list integrity.
 * - Don't forget to free/delete memory of the removed nodes.
 *
 * Example:
 *   Input: 10 <-> 4 <-> 10 <-> 8 <-> 10, key = 10
 *   Output: 4 <-> 8
 *
 *   Input: 5 <-> 5 <-> 5, key = 5
 *   Output: nullptr (entire list deleted)
 *
 * Intuition:
 * ----------
 * Traverse the list using a `temp` pointer.
 * For every node with value == key:
 *   - If it's the head → update head.
 *   - If it's a middle node → rewire previous and next.
 *   - If it's the tail → update previous node's next to nullptr.
 * Always delete the node after re-linking.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

/*
 * Function: deleteAllOccurrences
 * -------------------------------
 * Deletes all nodes in the DLL having value equal to 'key'.
 * Returns the updated head of the DLL.
 */
Node* deleteAllOccurrences(Node* head, int key) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == key) {
            Node* nextNode = temp->next;

            // Case 1: Deleting head
            if (temp == head) {
                head = head->next;
                if (head) head->prev = nullptr;
                delete temp;
                temp = head;
            }
            // Case 2: Deleting middle node
            else if (temp->next != nullptr) {
                Node* prevNode = temp->prev;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                delete temp;
                temp = nextNode;
            }
            // Case 3: Deleting tail
            else {
                Node* prevNode = temp->prev;
                prevNode->next = nullptr;
                delete temp;
                temp = nullptr;
            }
        } else {
            temp = temp->next;
        }
    }

    return head;
}

// Create a Doubly Linked List from initializer list
Node* createDLL(initializer_list<int> vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

// Print DLL
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    // Test Case 1
    Node* head1 = createDLL({10, 4, 10, 8, 10});
    cout << "Original List: ";
    printDLL(head1);
    head1 = deleteAllOccurrences(head1, 10);
    cout << "After Deleting 10s: ";
    printDLL(head1);

    // Test Case 2: Entire list to be deleted
    Node* head2 = createDLL({5, 5, 5});
    cout << "\nOriginal List: ";
    printDLL(head2);
    head2 = deleteAllOccurrences(head2, 5);
    cout << "After Deleting 5s: ";
    printDLL(head2);  // Should print nothing

    // Test Case 3: No deletions
    Node* head3 = createDLL({1, 2, 3, 4});
    cout << "\nOriginal List: ";
    printDLL(head3);
    head3 = deleteAllOccurrences(head3, 9);
    cout << "After Deleting 9s (not present): ";
    printDLL(head3);

    return 0;
}
