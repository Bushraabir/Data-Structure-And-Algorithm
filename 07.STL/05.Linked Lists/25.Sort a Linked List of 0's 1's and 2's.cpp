/*
 * Problem: Sort a Linked List of 0s, 1s and 2s
 *
 * Problem Statement:
 * -------------------
 * You are given the head of a singly linked list where each node’s data is either 0, 1, or 2.
 * Sort the list in ascending order so that all 0s come first, then all 1s, and finally all 2s.
 *
 * Example:
 *   Input:  1 -> 0 -> 2 -> 1 -> 0
 *   Output: 0 -> 0 -> 1 -> 1 -> 2
 *
 * Intuition:
 * ----------
 * 1. **Naive (Brute Force) Solution**:
 *    - Count how many 0s, 1s, and 2s there are in one pass.
 *    - Overwrite the node data in a second pass according to those counts.
 *    - Time O(N), constant extra space for counters.
 *
 * 2. **Optimal (In-Place Link Manipulation)**:
 *    - Partition the list into three sub-lists (for 0s, 1s, and 2s) in one pass.
 *    - Stitch the three sub-lists together without using extra arrays or re-writing data.
 *    - Time O(N), O(1) extra space.
 */

/*
 * Approach 1: Naive Solution (Counting and Data Replacement)
 * ---------------------------------------------------------
 * 1. Handle empty list or single node → return head.
 * 2. Traverse once to count zeros, ones, twos.
 * 3. Traverse again and overwrite node->data:
 *    – First countZero nodes become 0,
 *    – Next countOne nodes become 1,
 *    – Remaining countTwo nodes become 2.
 * 4. Return head.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Brute-force: count and overwrite
Node* sortList_Counting(Node* head) {
    if (!head || !head->next) return head;

    int countZero = 0, countOne = 0, countTwo = 0;
    Node* temp = head;

    // Count occurrences
    while (temp) {
        if (temp->data == 0) ++countZero;
        else if (temp->data == 1) ++countOne;
        else ++countTwo;
        temp = temp->next;
    }

    // Overwrite data
    temp = head;
    while (temp) {
        if (countZero > 0) {
            temp->data = 0;
            --countZero;
        }
        else if (countOne > 0) {
            temp->data = 1;
            --countOne;
        }
        else {
            temp->data = 2;
            --countTwo;
        }
        temp = temp->next;
    }

    return head;
}

/*
 * Approach 2: Optimal Solution (In-Place Link Manipulation)
 * ---------------------------------------------------------
 * 1. Handle empty or single-node list → return head.
 * 2. Create three dummy heads: zeroHead, oneHead, twoHead.
 *    Maintain tails: zeroTail, oneTail, twoTail.
 * 3. Traverse original list once, detach each node and append to its bucket:
 *    – If node->data == 0: zeroTail->next = node; zeroTail = node;
 *    – If node->data == 1: oneTail->next  = node; oneTail  = node;
 *    – If node->data == 2: twoTail->next  = node; twoTail  = node;
 *    – Advance temp before modifying node->next.
 * 4. Connect sub-lists:
 *    – zeroTail->next = (oneHead.next ? oneHead.next : twoHead.next);
 *    – oneTail->next  = twoHead.next;
 *    – twoTail->next  = nullptr;
 * 5. Head of sorted list = zeroHead.next (or oneHead.next/twoHead.next if earlier lists empty).
 * 6. Delete dummy nodes if desired.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

Node* sortList_Partition(Node* head) {
    if (!head || !head->next) return head;

    // Step 1: Create dummy heads and tails
    Node zeroDummy( -1 ), oneDummy( -1 ), twoDummy( -1 );
    Node *zeroTail = &zeroDummy, *oneTail = &oneDummy, *twoTail = &twoDummy;

    // Step 2: Partition into three lists
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next;  // save next
        temp->next = nullptr;         // detach
        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        }
        else {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = nextNode;
    }

    // Step 3: Stitch lists together
    zeroTail->next = (oneDummy.next ? oneDummy.next : twoDummy.next);
    oneTail ->next = twoDummy.next;
    twoTail ->next = nullptr;

    return zeroDummy.next;
}

// Utilities for testing
Node* createList(const vector<int>& vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int v : vals) {
        Node* n = new Node(v);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 0, 2, 1, 0};
    Node* l1 = createList(vals);
    Node* l2 = createList(vals);

    cout << "Original:      ";
    printList(l1);

    cout << "Brute-Force:   ";
    printList(sortList_Counting(l1));

    cout << "Partitioning:  ";
    printList(sortList_Partition(l2));

    return 0;
}
