/*
 * Problem: Delete the Nth Node from the End of a Linked List
 *
 * Problem Statement:
 * -------------------
 * You are given the head of a singly linked list and an integer n.
 * Your task is to delete the nth node from the end of the list and return the modified list's head.
 *
 * Example:
 *   Input:  head = 1 -> 2 -> 3 -> 4 -> 5,  n = 2
 *   Output: 1 -> 2 -> 3 -> 5
 *
 * Intuition:
 * ----------
 * The key idea is to locate the (Length - N)th node from the beginning,
 * which is the node just before the one that needs to be deleted.
 * There are two approaches:
 *
 * 1. Brute Force (Two Passes):
 *    - First, count the number of nodes in the list.
 *    - Then, go to (Length - N)th node and delete the next node.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(1)
 *
 * 2. Optimal Solution (One Pass using Two Pointers):
 *    - Maintain a gap of N between two pointers: fast and slow.
 *    - Move fast pointer N steps ahead.
 *    - Then move both fast and slow one step at a time.
 *    - When fast reaches the end, slow will be just before the target node.
 *    - Update links to delete the node in one pass.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/*
 * Approach 1: Brute Force (Two-Pass)
 * ----------------------------------
 * 1. Traverse the entire list to calculate the total length.
 * 2. If (length == n), the head itself needs to be removed.
 * 3. Otherwise, go to the (length - n)th node and update its next pointer.
 */
Node* deleteNthFromEnd_Brute(Node* head, int n) {
    if (!head) return nullptr;

    // Step 1: Count total number of nodes
    int count = 0;
    Node* temp = head;
    while (temp) {
        ++count;
        temp = temp->next;
    }

    // Step 2: Check if we need to delete the head
    if (count == n) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Step 3: Traverse again to reach node before the target
    temp = head;
    for (int i = 1; i < count - n; ++i) {
        temp = temp->next;
    }

    // Step 4: Delete the node
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    return head;
}

/*
 * Approach 2: Optimal (One-Pass using Two Pointers)
 * -------------------------------------------------
 * 1. Move the fast pointer n steps ahead.
 * 2. If fast becomes null, we need to delete the head.
 * 3. Otherwise, move fast and slow together until fast reaches end.
 * 4. Slow will be just before the target node. Update its next pointer.
 */
Node* deleteNthFromEnd_Optimal(Node* head, int n) {
    if (!head) return nullptr;

    Node* fast = head;
    Node* slow = head;

    // Step 1: Move fast n steps ahead
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // Step 2: If fast is null, delete the head node
    if (!fast) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Step 3: Move both pointers until fast reaches the last node
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 4: Delete the target node
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    return head;
}

// Utility: Create a linked list from vector
Node* createList(initializer_list<int> vals) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }
    return head;
}

// Utility: Print the linked list
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
    Node* list2 = createList({1, 2, 3, 4, 5});

    cout << "Original:            ";
    printList(list1);

    list1 = deleteNthFromEnd_Brute(list1, 2);
    cout << "Brute Force Delete:  ";
    printList(list1);

    list2 = deleteNthFromEnd_Optimal(list2, 2);
    cout << "Optimal Delete:      ";
    printList(list2);

    return 0;
}
