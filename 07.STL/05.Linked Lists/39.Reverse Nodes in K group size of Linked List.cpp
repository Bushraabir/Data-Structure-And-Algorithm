/*
 * Problem: Reverse Nodes in K-Group Size of Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list and an integer `K`, reverse the nodes of the list in groups of size K.
 * If the number of nodes is not a multiple of K, the remaining nodes at the end should remain as-is.
 * Return the new head of the modified list.
 *
 * Example:
 *   Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, K = 3
 *   Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> 10
 *
 * Important:
 * - Only complete groups of size K should be reversed.
 * - Remaining nodes (less than K) should be left untouched.
 * - You must reverse the list **in-place** using constant extra space.
 *
 * Intuition:
 * ----------
 * 1. Use a helper function to find the Kth node from the current start.
 * 2. If a K-sized group exists, isolate and reverse that group.
 * 3. Reconnect the reversed group with the previous and next parts of the list.
 * 4. Repeat until the list ends or no full group remains.
 *
 * Key Functions:
 * - getKthNode(start, k): Returns the Kth node from start (or NULL if fewer than K nodes exist).
 * - reverseGroup(start): Reverses a linked list group and returns the new head.
 *
 * Time Complexity: O(N)
 *   - Each node is visited a constant number of times.
 *
 * Space Complexity: O(1)
 *   - In-place pointer manipulation with no extra space.
 */

#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Helper: Get K-th node from the current node
ListNode* getKthNode(ListNode* curr, int k) {
    while (curr && --k) {
        curr = curr->next;
    }
    return curr;
}

// Helper: Reverse a group of nodes and return new head
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

/*
 * Function: reverseKGroup
 * -----------------------
 * Reverses nodes in K-sized groups and returns new head of list.
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* groupPrev = dummy;
    ListNode* temp = head;

    while (temp) {
        // Step 1: Find Kth node
        ListNode* kth = getKthNode(temp, k);
        if (!kth) break;

        ListNode* groupNext = kth->next;

        // Step 2: Isolate current K-group
        kth->next = nullptr;

        // Step 3: Reverse isolated group
        ListNode* reversedHead = reverse(temp);

        // Step 4: Connect previous group to reversed head
        groupPrev->next = reversedHead;

        // Step 5: Connect tail of reversed group to groupNext
        temp->next = groupNext;

        // Step 6: Move pointers to next group
        groupPrev = temp;
        temp = groupNext;
    }

    ListNode* newHead = dummy->next;
    delete dummy;
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
    // Test Case
    ListNode* head = createList({1,2,3,4,5,6,7,8,9,10});
    int k = 3;

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(head);

    freeList(head);
    return 0;
}
