/*
 * Problem: Find the Length of the Loop in a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list, return the length of the loop if one exists.
 * If no loop exists, return 0.
 *
 * Definition of Loop:
 * A loop exists if there is at least one node from which you can start traversing and eventually reach back to that same node.
 *
 * Example:
 *   For list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (back to node with value 3)
 *   Loop length = 3
 *
 * Intuition:
 * ----------
 * 1. Naive approach (Hashing):
 *    - Store each visited node with a timestamp (step count).
 *    - When a node repeats, loop exists. Subtract timestamps to get loop length.
 *    - Time: O(N), Space: O(N)
 *
 * 2. Optimal approach (Tortoise and Hare):
 *    - Use two pointers to detect the loop.
 *    - Once detected, keep one pointer fixed, move the other until they meet again to count loop length.
 *    - Time: O(N), Space: O(1)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/*
 * Approach 1: Find Loop Length using Hashing
 * ------------------------------------------
 * 1. Traverse and store each visited node with a step index in a map.
 * 2. When revisiting a node, subtract the previous step count to get loop length.
 */
int loopLengthHashing(Node* head) {
    unordered_map<Node*, int> visited;
    Node* temp = head;
    int timer = 1;

    while (temp != nullptr) {
        if (visited.count(temp)) {
            return timer - visited[temp];  // Loop length
        }
        visited[temp] = timer++;
        temp = temp->next;
    }
    return 0; // No loop
}

/*
 * Helper for Floyd’s Algorithm: Count loop length from collision node
 */
int countLoopLength(Node* meetNode) {
    Node* temp = meetNode->next;
    int count = 1;
    while (temp != meetNode) {
        temp = temp->next;
        count++;
    }
    return count;
}

/*
 * Approach 2: Find Loop Length using Floyd's Tortoise and Hare
 * -------------------------------------------------------------
 * 1. Use slow and fast pointers to detect loop.
 * 2. On collision, call helper to count length of the loop.
 */
int loopLengthFloyd(Node* head) {
    if (!head) return 0;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return countLoopLength(slow);  // Loop length
        }
    }
    return 0; // No loop
}

// Utility: Create linked list from initializer list (no loop)
Node* createList(initializer_list<int> vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }
    return head;
}

// Utility: Print linked list (up to limit to avoid infinite print if loop exists)
void printList(Node* head, int limit = 20) {
    Node* temp = head;
    int count = 0;
    while (temp && count < limit) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
        count++;
    }
    if (temp) cout << " -> ... (loop suspected)";
    cout << endl;
}

int main() {
    // List without loop
    Node* list1 = createList({1, 2, 3, 4, 5});
    cout << "List 1: ";
    printList(list1);
    cout << "Loop length (Hashing): " << loopLengthHashing(list1) << endl;
    cout << "Loop length (Floyd): " << loopLengthFloyd(list1) << endl;

    // List with loop: 10 -> 20 -> 30 -> 40 -> 50 -> back to 30
    Node* list2 = createList({10, 20, 30, 40, 50});
    Node* temp = list2;
    Node* loopStart = nullptr;
    int pos = 3, count = 1;
    while (temp->next) {
        if (count == pos) loopStart = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopStart; // create loop

    cout << "\nList 2 (with loop): ";
    printList(list2); // will print limited nodes
    cout << "Loop length (Hashing): " << loopLengthHashing(list2) << endl;
    cout << "Loop length (Floyd): " << loopLengthFloyd(list2) << endl;

    return 0;
}
