/*
 * Problem: Find the Middle Element of a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given a singly linked list, return the middle node.
 * 
 * Definition of Middle:
 * - If the list length is odd, return the exact middle node.
 * - If the list length is even, return the second middle node.
 *
 * Example:
 *   For list: 1 -> 2 -> 3 -> 4 -> 5
 *   Middle node: 3 (3rd node)
 *
 *   For list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *   Middle node: 4 (4th node, second middle)
 *
 * Intuition:
 * ----------
 * 1. Two-pass approach:
 *    - First pass: count total nodes N.
 *    - Second pass: traverse to (N/2 + 1)-th node.
 *    - Time: O(N), Space: O(1)
 *
 * 2. Optimal one-pass approach (Tortoise and Hare):
 *    - Use two pointers: slow (1 step) and fast (2 steps).
 *    - When fast reaches end, slow is at middle.
 *    - Time: O(N), Space: O(1)
 */

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/*
 * Approach 1: Two-pass (Naive)
 * ----------------------------
 * 1. Traverse list to count total nodes N.
 * 2. Traverse again to (N/2 + 1)-th node.
 */
Node* findMiddleTwoPass(Node* head) {
    if (!head) return nullptr;

    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    int midPos = count / 2 + 1;
    temp = head;
    for (int i = 1; i < midPos; i++) {
        temp = temp->next;
    }
    return temp;
}

/*
 * Approach 2: Optimal One-pass (Tortoise and Hare)
 * ------------------------------------------------
 * 1. Initialize slow and fast pointers at head.
 * 2. Move slow by 1 step, fast by 2 steps in loop.
 * 3. When fast reaches null or fast->next is null,
 *    slow will be at middle node.
 */
Node* findMiddleOptimal(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Utility: Create linked list from initializer list
Node* createList(initializer_list<int> vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }
    return head;
}

// Utility: Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main: Test both approaches
int main() {
    Node* list1 = createList({1, 2, 3, 4, 5});
    Node* list2 = createList({1, 2, 3, 4, 5, 6});

    cout << "List 1: ";
    printList(list1);
    cout << "Middle (Two-pass): " << findMiddleTwoPass(list1)->data << endl;
    cout << "Middle (Optimal): " << findMiddleOptimal(list1)->data << endl;

    cout << "\nList 2: ";
    printList(list2);
    cout << "Middle (Two-pass): " << findMiddleTwoPass(list2)->data << endl;
    cout << "Middle (Optimal): " << findMiddleOptimal(list2)->data << endl;

    return 0;
}
