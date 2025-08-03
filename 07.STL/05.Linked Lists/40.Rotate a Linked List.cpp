/*
 * Problem: Rotate a Linked List by K Places
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list and an integer `K`, rotate the list to the right by K positions.
 * Each rotation moves the last element of the list to the front.
 *
 * Example:
 *   Input: 1 -> 2 -> 3 -> 4 -> 5, K = 2
 *   Output: 4 -> 5 -> 1 -> 2 -> 3
 *
 * Important:
 * - If K is 0 or the list is empty, return the head unchanged.
 * - If K >= length of list, rotate only (K % length) times.
 * - Modify the list in-place with O(1) space.
 *
 * Intuition:
 * ----------
 * 1. Traverse the list to find its length and last node.
 * 2. Link the last node to the head to form a circular list.
 * 3. Find the new tail (at position length - K).
 * 4. Set new head = newTail->next and break the link after newTail.
 *
 * Time Complexity: O(N)
 *   - One pass to find length and another to find new tail.
 *
 * Space Complexity: O(1)
 *   - Constant space used for pointer manipulation.
 */

#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

/*
 * Function: rotateRight
 * ---------------------
 * Rotates the linked list to the right by K places.
 * Returns the new head after rotation.
 */
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) return head;

    // Step 1: Compute the length and locate the tail
    int length = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Adjust k to within range
    k = k % length;
    if (k == 0) return head;

    // Step 3: Make the list circular
    tail->next = head;

    // Step 4: Find the new tail (length - k) and new head
    int stepsToNewTail = length - k;
    ListNode* newTail = head;
    while (--stepsToNewTail) {
        newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;

    // Step 5: Break the circle
    newTail->next = nullptr;

    return newHead;
}

// Utility: Create a Singly Linked List from initializer list
ListNode* createList(initializer_list<int> vals) {
    ListNode* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Utility: Print Singly Linked List
void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility: Free the list (for good memory hygiene)
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test Driver
int main() {
    // Test Case 1
    ListNode* head = createList({1, 2, 3, 4, 5});
    int k = 2;

    cout << "Original List: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "After Rotating by " << k << ": ";
    printList(head);

    freeList(head);
    return 0;
}
