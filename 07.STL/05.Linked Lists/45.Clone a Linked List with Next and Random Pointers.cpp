/*
 * Problem: Clone a Linked List with Next and Random Pointers
 *
 * Problem Statement:
 * -------------------
 * Given a linked list where each node contains an integer `val`, a `next` pointer,
 * and a `random` pointer that can point to any node in the list or null, 
 * create a deep copy of the list.
 *
 * Example:
 *   Input: A list like 1 -> 2 -> 3 -> 4, where each node also has a random pointer.
 *   Output: A completely new list that replicates both the next and random connections.
 *
 * Intuition:
 * ----------
 * Unlike a regular linked list copy, we must also duplicate arbitrary `random` connections.
 * A simple clone using just the `next` pointer isn't sufficient since the `random` pointer
 * could point anywhere in the list, even ahead or behind in traversal.
 *
 * There are two main approaches:
 *
 * 1. Brute Force Using Hash Map:
 *    - Create a mapping from original nodes to their deep copies.
 *    - Traverse the list twice:
 *        a) Create all nodes and map original to copy.
 *        b) Assign correct `next` and `random` using the map.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(N)
 *
 * 2. Optimal In-Place Interleaving:
 *    - Interweave copied nodes into the original list.
 *    - Assign `random` pointers using this interleaved structure.
 *    - Separate the two lists in a final pass.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(1) auxiliary space
 */

#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

/*
 * Approach 1: Optimal In-Place Interleaving Copy
 */
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // Phase 1: Interleave copy nodes with original nodes
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Phase 2: Assign random pointers for copy nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Phase 3: Separate the interleaved lists
    Node* dummy = new Node(0);
    Node* copyCurr = dummy;
    curr = head;
    while (curr) {
        Node* copy = curr->next;
        copyCurr->next = copy;
        copyCurr = copy;
        curr->next = copy->next;
        curr = curr->next;
    }

    return dummy->next;
}

/*
 * Utility: Print list values with random pointer values
 */
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val;
        if (head->random) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: null";
        }
        cout << endl;
        head = head->next;
    }
}

/*
 * Example Usage
 */
int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2; n2->next = n3; n3->next = n4;
    n1->random = n3;
    n2->random = n1;
    n3->random = nullptr;
    n4->random = n2;

    cout << "Original List:\n";
    printList(n1);

    Node* copiedHead = copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}
