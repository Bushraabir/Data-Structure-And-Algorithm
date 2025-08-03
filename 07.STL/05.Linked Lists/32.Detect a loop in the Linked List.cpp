/*
 * Problem: Detect a Loop or Cycle in a Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list, determine if the linked list contains a loop (cycle).
 * Return true if there is a loop, otherwise return false.
 *
 * Definition of Loop:
 * A loop exists if by following next pointers starting from any node in the loop,
 * you can come back to the same node again.
 *
 * Example:
 *   For list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (back to node with value 3)
 *   Loop exists: true
 *
 * Intuition:
 * ----------
 * 1. Naive approach (Hashing):
 *    - Keep track of visited nodes in a hash set.
 *    - If we visit a node twice, a loop exists.
 *    - Time: O(N), Space: O(N)
 *
 * 2. Optimal approach (Tortoise and Hare):
 *    - Use two pointers moving at different speeds.
 *    - If there's a loop, fast pointer will eventually meet slow pointer.
 *    - Time: O(N), Space: O(1)
 */

#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

/*
 * Approach 1: Detect Loop using Hashing
 * -------------------------------------
 * 1. Traverse the linked list.
 * 2. Store each visited node in a hash set.
 * 3. If a node is revisited (already in set), return true.
 * 4. If end reached (nullptr), return false.
 */
bool detectLoopHashing(Node* head) {
    unordered_set<Node*> visited;
    Node* temp = head;

    while (temp != nullptr) {
        if (visited.find(temp) != visited.end())
            return true; // loop detected
        visited.insert(temp);
        temp = temp->next;
    }
    return false; // no loop
}

/*
 * Approach 2: Detect Loop using Tortoise and Hare Algorithm
 * --------------------------------------------------------
 * 1. Initialize slow and fast pointers at head.
 * 2. Move slow by 1 step, fast by 2 steps.
 * 3. If fast or fast->next becomes nullptr, no loop exists.
 * 4. If slow == fast at any point, loop detected.
 */
bool detectLoopFloyd(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true; // loop detected
    }
    return false; // no loop
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
    // List without loop: 1 -> 2 -> 3 -> 4 -> 5
    Node* list1 = createList({1, 2, 3, 4, 5});
    cout << "List 1: ";
    printList(list1);
    cout << "Loop detected (Hashing): " << (detectLoopHashing(list1) ? "Yes" : "No") << endl;
    cout << "Loop detected (Floyd): " << (detectLoopFloyd(list1) ? "Yes" : "No") << endl;

    // List with loop: 10 -> 20 -> 30 -> 40 -> 50 -> back to 30
    Node* list2 = createList({10, 20, 30, 40, 50});
    // Creating a loop manually
    Node* temp = list2;
    Node* loopStart = nullptr;
    int pos = 3; // loop starting at 3rd node (value 30)
    int count = 1;
    while (temp->next) {
        if (count == pos) loopStart = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopStart; // create loop

    cout << "\nList 2: ";
    printList(list2); // will print limited nodes to avoid infinite loop

    cout << "Loop detected (Hashing): " << (detectLoopHashing(list2) ? "Yes" : "No") << endl;
    cout << "Loop detected (Floyd): " << (detectLoopFloyd(list2) ? "Yes" : "No") << endl;

    return 0;
}
