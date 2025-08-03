/*
 * Problem: Flatten a Linked List (with next and child pointers)
 *
 * Problem Statement:
 * -------------------
 * Given a linked list where each node has two pointers:
 *   - `next`: points to the next node in the main horizontal list
 *   - `child`: points to the head of a vertically sorted sublist
 *
 * Each node and its child list are already sorted.
 * The goal is to flatten this multi-level list into a single, sorted list 
 * using only `child` pointers. All `next` pointers in the result should be null.
 *
 * Example:
 *   Input:
 *     5 -> 10 -> 19 -> 28
 *     |     |     |     |
 *     7     20    22    35
 *     |           |     |
 *     8           50    40
 *     |                 |
 *     30                45
 *
 *   Output (flattened vertical list using `child` pointer):
 *     5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50
 *
 * Intuition:
 * ----------
 * We treat each vertical list as a sorted list.
 * The idea is to recursively flatten the right-side list and merge the current list into it,
 * similar to how merge sort works.
 *
 * There are 2 approaches:
 *
 * 1. Brute Force (Using Array + Sort):
 *    - Traverse the full list and collect all values into an array.
 *    - Sort the array and rebuild a new linked list using child pointers.
 *    - Time Complexity: O(N*M log(N*M)) (where N is horizontal and M avg vertical length)
 *    - Space Complexity: O(N*M)
 *
 * 2. Optimal Recursive (Merge Sort-style):
 *    - Recursively flatten from right to left and merge each list in-place using child pointers.
 *    - Time Complexity: O(N*M)
 *    - Space Complexity: O(N) (recursion stack)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure with next and child
struct Node {
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

/*
 * Approach 1: Brute Force (Array + Sort)
 * --------------------------------------
 */
void collectValues(Node* head, vector<int>& vals) {
    while (head) {
        Node* temp = head;
        while (temp) {
            vals.push_back(temp->data);
            temp = temp->child;
        }
        head = head->next;
    }
}

Node* buildList(const vector<int>& vals) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    for (int val : vals) {
        curr->child = new Node(val);
        curr = curr->child;
    }
    return dummy->child;
}

Node* flattenList_Brute(Node* head) {
    vector<int> vals;
    collectValues(head, vals);
    sort(vals.begin(), vals.end());
    return buildList(vals);
}

/*
 * Approach 2: Optimal Recursive (Merge Sorted Lists)
 * --------------------------------------------------
 */

// Merge two sorted vertical lists using child pointers
Node* mergeTwoLists(Node* a, Node* b) {
    Node dummy(-1);
    Node* tail = &dummy;

    while (a && b) {
        if (a->data < b->data) {
            tail->child = a;
            a = a->child;
        } else {
            tail->child = b;
            b = b->child;
        }
        tail = tail->child;
        tail->next = nullptr;  // ensure flattened list only uses child
    }

    if (a) tail->child = a;
    if (b) tail->child = b;

    return dummy.child;
}

// Recursively flatten the linked list
Node* flattenList_Recursive(Node* head) {
    if (!head || !head->next) return head;

    head->next = flattenList_Recursive(head->next);
    head = mergeTwoLists(head, head->next);
    return head;
}

/*
 * Utility: Print child-based list
 */
void printFlattened(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

/*
 * Example Usage:
 */
int main() {
    // Construct linked list manually for demonstration
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    cout << "Flattened List (Brute Force): ";
    Node* brute = flattenList_Brute(head);
    printFlattened(brute);

    cout << "Flattened List (Optimized Recursive): ";
    Node* optimal = flattenList_Recursive(head);
    printFlattened(optimal);

    return 0;
}
