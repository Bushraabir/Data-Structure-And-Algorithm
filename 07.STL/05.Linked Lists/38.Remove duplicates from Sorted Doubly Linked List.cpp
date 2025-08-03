/*
 * Problem: Remove Duplicates from Sorted Doubly Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a **sorted** doubly linked list, remove all duplicate nodes
 * so that each element appears only once. Return the head of the modified list.
 *
 * Important:
 * - The list is sorted in non-decreasing order.
 * - You must remove duplicate nodes **in-place**.
 * - The first occurrence of each value is always preserved.
 *
 * Example:
 *   Input: 1 <-> 1 <-> 1 <-> 2 <-> 3 <-> 3 <-> 4
 *   Output: 1 <-> 2 <-> 3 <-> 4
 *
 *   Input: 1 <-> 1 <-> 1 <-> 1
 *   Output: 1
 *
 * Intuition:
 * ----------
 * Since the list is sorted, any duplicate elements will be adjacent.
 * We can use a single pointer (`temp`) to scan the list and skip all duplicates.
 * For each node, traverse all nodes with the same value and delete them.
 * Relink temp to the next unique node and continue.
 *
 * Deletion Notes:
 * - Always store a temporary pointer before deleting to avoid dangling access.
 * - Adjust both `next` and `prev` pointers properly to maintain DLL integrity.
 *
 * Time Complexity: O(N)
 *   - Each node is visited at most once.
 *
 * Space Complexity: O(1)
 *   - Only a constant number of pointers used.
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
 * Function: removeDuplicates
 * --------------------------
 * Removes all duplicate elements from a sorted DLL in-place.
 * Returns the head of the modified list.
 */
Node* removeDuplicates(Node* head) {
    if (!head || !head->next) return head;

    Node* temp = head;
    while (temp && temp->next) {
        Node* nextNode = temp->next;

        // Skip and delete all nodes with same value as temp
        while (nextNode && nextNode->data == temp->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;

            // Free memory (important in C++)
            delete duplicate;
        }

        // Relink temp with the next unique node
        temp->next = nextNode;
        if (nextNode) nextNode->prev = temp;

        // Move to next unique node
        temp = nextNode;
    }

    return head;
}

// Utility: Create a Doubly Linked List from initializer list
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

// Utility: Print Doubly Linked List
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility: Free the list (for good memory hygiene in C++)
void freeDLL(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test Driver
int main() {
    // Test Case 1
    Node* head1 = createDLL({1, 1, 1, 2, 3, 3, 4});
    cout << "Original List: ";
    printDLL(head1);
    head1 = removeDuplicates(head1);
    cout << "After Removing Duplicates: ";
    printDLL(head1);
    freeDLL(head1);

    // Test Case 2
    Node* head2 = createDLL({1, 1, 1, 1});
    cout << "\nOriginal List: ";
    printDLL(head2);
    head2 = removeDuplicates(head2);
    cout << "After Removing Duplicates: ";
    printDLL(head2);
    freeDLL(head2);

    // Test Case 3
    Node* head3 = createDLL({1, 2, 3, 4});
    cout << "\nOriginal List: ";
    printDLL(head3);
    head3 = removeDuplicates(head3);
    cout << "After Removing Duplicates: ";
    printDLL(head3);
    freeDLL(head3);

    return 0;
}
