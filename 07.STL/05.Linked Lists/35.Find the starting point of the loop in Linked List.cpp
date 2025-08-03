/*
 * Problem: Find the Starting Point of the Loop in a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list, return the **starting node** of the loop if a cycle exists.
 * If there is no cycle, return `nullptr`.
 *
 * Important:
 * - The function should return the **node object**, not just its value.
 * - Multiple nodes may have the same value, so identifying by value is incorrect.
 *
 * Example:
 *   Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *                       ^         |
 *                       |_________|
 *   Output: Node with value 3 (the loop starts here)
 *
 *   Input: 1 -> 2 -> 3 -> 4 -> nullptr
 *   Output: nullptr (no loop)
 *
 * Intuition:
 * ----------
 * Two Approaches:
 *
 * 1. Brute Force (Hashing):
 *    - Traverse the list and store visited nodes in a hash map.
 *    - If you visit a node already present in the map, it is the starting node of the loop.
 *    - Time: O(N), Space: O(N)
 *
 * 2. Optimal (Floyd's Cycle Detection - Tortoise & Hare):
 *    - Step 1: Use slow and fast pointers to detect if a loop exists.
 *    - Step 2: Once a collision occurs, reset one pointer to the head.
 *    - Move both pointers one step at a time until they meet again → loop start.
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
 * Approach 1: Brute Force using Hash Map
 * ---------------------------------------
 * - Traverse the list and store node addresses in a map.
 * - If a node is already in the map, return it (start of the loop).
 */
Node* detectCycleHashing(Node* head) {
    unordered_map<Node*, bool> visited;
    Node* temp = head;

    while (temp) {
        if (visited[temp]) return temp;
        visited[temp] = true;
        temp = temp->next;
    }

    return nullptr;  // No cycle
}

/*
 * Approach 2: Optimal using Floyd's Cycle Detection Algorithm
 * ------------------------------------------------------------
 * Step 1: Detect if a loop exists using slow and fast pointers.
 * Step 2: If a loop is detected, reset one pointer to the head.
 *         Move both pointers one step at a time. Where they meet is the start of the loop.
 */
Node* detectCycleFloyd(Node* head) {
    if (!head || !head->next) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect collision
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find entry point
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;  // No cycle
}

// Utility: Create a linked list from initializer list
Node* createList(initializer_list<int> vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
    }
    return head;
}

// Utility: Print linked list (safe for small cycles only)
void printList(Node* head, int maxNodes = 20) {
    Node* temp = head;
    int count = 0;
    while (temp && count < maxNodes) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << (temp ? "..." : "nullptr") << endl;
}

// Test Driver
int main() {
    // Create a linked list with a loop: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    //                                            ^              |
    //                                            |______________|
    Node* head = createList({1, 2, 3, 4, 5, 6});
    Node* tail = head;
    while (tail->next) tail = tail->next;

    // Create loop manually (6 -> 3)
    Node* loopStart = head;
    while (loopStart->data != 3) loopStart = loopStart->next;
    tail->next = loopStart;

    // Detect cycle using Floyd's algorithm
    Node* startNode = detectCycleFloyd(head);
    if (startNode)
        cout << "Cycle detected at node with value: " << startNode->data << endl;
    else
        cout << "No cycle found." << endl;

    // Detect cycle using Hashing
    Node* startNodeHash = detectCycleHashing(head);
    if (startNodeHash)
        cout << "Cycle detected (Hashing) at node with value: " << startNodeHash->data << endl;
    else
        cout << "No cycle found (Hashing)." << endl;

    return 0;
}
