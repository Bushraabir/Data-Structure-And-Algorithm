/*
 * Problem: Delete the Middle Node of a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list, delete its middle node.
 *
 * Definition of Middle Node:
 * - If the list has odd length → Delete the single middle node.
 * - If the list has even length → Delete the second middle node (M2).
 *
 * Return the head of the modified linked list.
 *
 * Example:
 *   Input: 1 -> 2 -> 3 -> 4 -> 5
 *   Output: 1 -> 2 -> 4 -> 5  (deleted node = 3)
 *
 *   Input: 1 -> 2 -> 3 -> 4
 *   Output: 1 -> 2 -> 4      (deleted node = 3, the second middle)
 *
 * Intuition:
 * ----------
 * 1. Naive approach (Two-pass):
 *    - Pass 1: Count the total number of nodes (N).
 *    - Pass 2: Reach the (N/2 - 1)th node and delete its next.
 *    - Time: O(N), Space: O(1)
 *
 * 2. Optimal approach (Tortoise and Hare - Slow & Fast Pointers):
 *    - Use fast and slow pointers to find the node before the middle.
 *    - Crucially, move only the fast pointer at the start to adjust slow.
 *    - When fast reaches end, slow will be just before the middle node.
 *    - Delete slow->next.
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
 * Approach 1: Two-pass (Brute Force)
 * -----------------------------------
 * 1. First traverse to find length of the list.
 * 2. Second traverse to reach the node before the middle.
 * 3. Delete middle node and return updated head.
 */
Node* deleteMiddleBrute(Node* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    // Step 1: Count length
    int length = 0;
    Node* temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    // Step 2: Reach node before middle
    int mid = length / 2;
    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    // Delete middle node
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;
}

/*
 * Approach 2: Optimal (Tortoise & Hare - Single Pass)
 * -----------------------------------------------------
 * 1. Use fast pointer to skip ahead first.
 * 2. Then move slow and fast together.
 * 3. Slow will land just before the middle node to delete.
 */
Node* deleteMiddleOptimal(Node* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete slow->next (the middle node)
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
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
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Main driver
int main() {
    // Test 1: Odd number of nodes
    Node* list1 = createList({1, 2, 3, 4, 5});
    cout << "Original List 1: ";
    printList(list1);
    list1 = deleteMiddleOptimal(list1);
    cout << "After Deleting Middle: ";
    printList(list1);

    // Test 2: Even number of nodes
    Node* list2 = createList({10, 20, 30, 40});
    cout << "\nOriginal List 2: ";
    printList(list2);
    list2 = deleteMiddleOptimal(list2);
    cout << "After Deleting Middle: ";
    printList(list2);

    // Test 3: Single node list
    Node* list3 = createList({99});
    cout << "\nOriginal List 3: ";
    printList(list3);
    list3 = deleteMiddleOptimal(list3);
    cout << "After Deleting Middle: ";
    printList(list3);

    return 0;
}
