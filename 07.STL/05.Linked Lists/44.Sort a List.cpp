/*
 * Problem: Sort a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list where each node contains an integer,
 * sort the list in ascending order and return the head of the updated list.
 *
 * Example:
 *   Input: 4 -> 2 -> 1 -> 3
 *   Output: 1 -> 2 -> 3 -> 4
 *
 * Intuition:
 * ----------
 * We need to sort a singly linked list. Since random access is not possible,
 * traditional quicksort or heapsort isn't ideal. Merge Sort fits perfectly
 * due to its linked list-friendly nature.
 *
 * There are two approaches:
 *
 * 1. Brute Force (Extract, Sort, Refill):
 *    - Extract all elements into a vector.
 *    - Sort the vector.
 *    - Reassign values back to the original linked list.
 *    - Time Complexity: O(N log N)
 *    - Space Complexity: O(N)
 *
 * 2. Optimal Using Merge Sort (In-Place):
 *    - Use the divide-and-conquer approach to split and merge the list.
 *    - Perform sorting by recursively dividing and merging sorted halves.
 *    - Uses only constant extra space (apart from recursion stack).
 *    - Time Complexity: O(N log N)
 *    - Space Complexity: O(log N) (recursion stack)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

/*
 * Approach 1: Brute Force (Extract, sort, refill)
 */
ListNode* sortListBrute(ListNode* head) {
    vector<int> vals;
    ListNode* temp = head;
    while (temp) {
        vals.push_back(temp->val);
        temp = temp->next;
    }
    sort(vals.begin(), vals.end());
    temp = head;
    int i = 0;
    while (temp) {
        temp->val = vals[i++];
        temp = temp->next;
    }
    return head;
}

/*
 * Helper: Merge two sorted linked lists
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1), *tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 ? l1 : l2);
    return dummy.next;
}

/*
 * Helper: Find the middle node of the linked list
 */
ListNode* getMiddle(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
 * Approach 2: Optimal Merge Sort
 */
ListNode* sortListOptimal(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* mid = getMiddle(head);
    ListNode* rightHead = mid->next;
    mid->next = nullptr;  // Break the list

    ListNode* leftSorted = sortListOptimal(head);
    ListNode* rightSorted = sortListOptimal(rightHead);

    return mergeTwoLists(leftSorted, rightSorted);
}

/*
 * Utility: Print the linked list
 */
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/*
 * Example Usage
 */
int main() {
    // Create example linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original: ";
    printList(head);

    // Brute Force
    ListNode* sortedBrute = sortListBrute(head);
    cout << "Sorted (Brute Force): ";
    printList(sortedBrute);

    // Rebuild list for optimal test
    head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Optimal Merge Sort
    ListNode* sortedOptimal = sortListOptimal(head);
    cout << "Sorted (Optimal Merge Sort): ";
    printList(sortedOptimal);

    return 0;
}
