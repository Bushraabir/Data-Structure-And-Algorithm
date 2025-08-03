/*
 * Problem: Merge K Sorted Linked Lists
 *
 * Problem Statement:
 * -------------------
 * Given K sorted singly linked lists of integers, merge them into one sorted linked list.
 * Return the head of the final merged list.
 *
 * Example:
 *   Input: lists = [[1->4->5], [1->3->4], [2->6]]
 *   Output: 1->1->2->3->4->4->5->6
 *
 * Intuition:
 * ----------
 * We need to merge multiple sorted lists efficiently.
 *
 * There are three approaches:
 *
 * 1. Brute Force (Extract, Sort, Rebuild):
 *    - Collect all values into a single array.
 *    - Sort the array.
 *    - Build a new linked list from sorted values.
 *    - Time Complexity: O(N*K log(N*K))
 *    - Space Complexity: O(N*K)
 *
 * 2. Iterative Pairwise Merge:
 *    - Start with the first list as the merged list.
 *    - Repeatedly merge the current merged list with the next list.
 *    - Uses in-place merging function for two sorted lists.
 *    - Time Complexity: O(N * K^2)
 *    - Space Complexity: O(1)
 *
 * 3. Optimal Using Min‑Heap (Priority Queue):
 *    - Use a min-heap to always pick the smallest head among the K lists.
 *    - Extract, attach it, and push its next node into the heap.
 *    - Time Complexity: O(N*K log K)
 *    - Space Complexity: O(K)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Node structure for singly linked list
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

/*
 * Approach 1: Brute Force (Collect, sort, rebuild)
 */
ListNode* mergeKListsBrute(vector<ListNode*>& lists) {
    vector<int> vals;
    for (auto head : lists) {
        ListNode* curr = head;
        while (curr) {
            vals.push_back(curr->data);
            curr = curr->next;
        }
    }
    if (vals.empty()) return nullptr;
    sort(vals.begin(), vals.end());
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy->next;
}

/*
 * Helper: Merge two sorted lists in-place
 */
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode dummy(-1), *tail = &dummy;
    while (a && b) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

/*
 * Approach 2: Iterative Pairwise Merge
 */
ListNode* mergeKListsIterative(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    ListNode* merged = lists[0];
    for (size_t i = 1; i < lists.size(); ++i) {
        merged = mergeTwoLists(merged, lists[i]);
    }
    return merged;
}

/*
 * Approach 3: Optimal Using Min‑Heap (Priority Queue)
 */
struct PQNode {
    int val;
    ListNode* node;
    bool operator>(const PQNode& other) const {
        return val > other.val;
    }
};

ListNode* mergeKListsOptimal(vector<ListNode*>& lists) {
    priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
    for (auto head : lists) {
        if (head) pq.push({head->data, head});
    }
    ListNode dummy(-1), *tail = &dummy;
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        tail->next = top.node;
        tail = tail->next;
        if (top.node->next) {
            pq.push({top.node->next->data, top.node->next});
        }
    }
    return dummy.next;
}

/*
 * Utility: Print the linked list
 */
void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    // Example: [[1->4->5], [1->3->4], [2->6]]
    ListNode* l1 = new ListNode(1); l1->next = new ListNode(4); l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1); l2->next = new ListNode(3); l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2); l3->next = new ListNode(6);
    vector<ListNode*> lists = {l1, l2, l3};

    cout << "Brute Force Merge: ";
    ListNode* res1 = mergeKListsBrute(lists);
    printList(res1);

    // Reconstruct for next approach
    lists = {l1, l2, l3};
    cout << "Iterative Merge: ";
    ListNode* res2 = mergeKListsIterative(lists);
    printList(res2);

    // Reconstruct for heap approach
    lists = {l1, l2, l3};
    cout << "Optimal Merge (Min‑Heap): ";
    ListNode* res3 = mergeKListsOptimal(lists);
    printList(res3);

    return 0;
}
