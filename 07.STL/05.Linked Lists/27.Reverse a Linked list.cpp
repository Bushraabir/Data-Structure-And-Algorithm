/*
 * Problem: Reverse a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list, reverse the list and return the new head.
 *
 * Example:
 *   Input:  head = 1 -> 3 -> 2 -> 5
 *   Output: head = 5 -> 2 -> 3 -> 1
 *
 * Intuition:
 * ----------
 * The goal is to reverse the direction of the links between the nodes, so that the head becomes the tail,
 * and the tail becomes the head.
 *
 * There are 3 approaches:
 *
 * 1. Brute Force (Using Stack):
 *    - Traverse the list and push node data into a stack.
 *    - Traverse again and pop from the stack to update the data in nodes.
 *    - Reverses the list "by value", not by changing links.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(N)
 *
 * 2. Optimal Iterative (Pointer Manipulation):
 *    - Traverse the list once while adjusting the links in-place using three pointers.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(1)
 *
 * 3. Optimal Recursive:
 *    - Recursively reverse the sublist and link the current node to its previous node on the return path.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(N) (due to recursion stack)
 */

#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/*
 * Approach 1: Brute Force (Using Stack)
 * -------------------------------------
 * 1. Traverse the list and store node values into a stack.
 * 2. Traverse again and overwrite each node's data with the top of the stack.
 */
Node* reverseList_Brute(Node* head) {
    if (!head) return nullptr;

    stack<int> st;
    Node* temp = head;

    // First Pass: Push all node data into stack
    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Second Pass: Pop and replace data
    temp = head;
    while (temp) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

/*
 * Approach 2: Optimal Iterative (Pointer Manipulation)
 * -----------------------------------------------------
 * 1. Use three pointers: prev, curr, front.
 * 2. Traverse the list, and reverse links as you go.
 * 3. When done, prev will be the new head.
 */
Node* reverseList_Iterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* front = curr->next;  // save next node
        curr->next = prev;         // reverse current node's pointer
        prev = curr;               // move prev forward
        curr = front;              // move curr forward
    }

    return prev;
}

/*
 * Approach 3: Optimal Recursive
 * -----------------------------
 * 1. Base Case: If head is null or single node, return head.
 * 2. Recursive Call: Reverse the rest of the list.
 * 3. On return, set next node's next to current node and current node's next to null.
 * 4. Return new head.
 */
Node* reverseList_Recursive(Node* head) {
    if (!head || !head->next) return head;

    Node* newHead = reverseList_Recursive(head->next); // Reverse rest
    head->next->next = head; // Point next node back to current
    head->next = nullptr;    // Set current's next to null

    return newHead;
}

// Utility: Create linked list from initializer list
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

// Utility: Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main: Test all 3 approaches
int main() {
    Node* list1 = createList({1, 3, 2, 5});
    Node* list2 = createList({1, 3, 2, 5});
    Node* list3 = createList({1, 3, 2, 5});

    cout << "Original:            ";
    printList(list1);

    list1 = reverseList_Brute(list1);
    cout << "Brute Force Reverse: ";
    printList(list1);

    list2 = reverseList_Iterative(list2);
    cout << "Iterative Reverse:   ";
    printList(list2);

    list3 = reverseList_Recursive(list3);
    cout << "Recursive Reverse:   ";
    printList(list3);

    return 0;
}
