 /* Problem: Merge Two Sorted Linked Lists
 *
 * Problem Statement:
 * -------------------
 * Given the heads of two sorted singly linked lists, L1 and L2, merge them into one sorted linked list L3.
 * Return the head of the merged sorted list L3.
 *
 * Example:
 *   Input: L1 = 1 -> 3 -> 5, L2 = 2 -> 4 -> 6
 *   Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *
 * Important:
 * - You must merge the lists by rearranging the existing nodes’ pointers.
 * - Do not create new nodes for the elements.
 * - The merged list should be sorted.
 *
 * Intuition:
 * ----------
 * 1. Use two pointers, each traversing one list.
 * 2. Compare the current nodes of both lists and link the smaller one to the merged list.
 * 3. Advance the pointer of the list whose node was used.
 * 4. Use a dummy node to simplify linking.
 * 5. After one list is exhausted, link the remaining nodes of the other list.
 *
 * Time Complexity: O(N1 + N2)
 *   - Each node in both lists is visited exactly once.
 *
 * Space Complexity: O(1)
 *   - Only constant extra space for pointers.
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
 * Function: mergeTwoSortedLists
 * -----------------------------
 * Merges two sorted linked lists and returns the head of the merged list.
 */
ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head2) {
    ListNode dummy(-1); // dummy node
    ListNode* temp = &dummy;

    ListNode* T1 = head1;
    ListNode* T2 = head2;

    while (T1 && T2) {
        if (T1->data < T2->data) {
            temp->next = T1;
            T1 = T1->next;
        } else {
            temp->next = T2;
            T2 = T2->next;
        }
        temp = temp->next;
    }

    if (T1) temp->next = T1;
    if (T2) temp->next = T2;

    return dummy.next;
}
