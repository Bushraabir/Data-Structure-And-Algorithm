/*
 * Problem: Find Intersection Point of Two Linked Lists (Y Shaped)
 *
 * Problem Statement:
 * -------------------
 * Given two singly linked lists head1 and head2 that merge at some node,
 * find and return the first common node where the intersection happens.
 * If the linked lists do not intersect, return nullptr.
 *
 * Important:
 * You must compare the node references (addresses), not their values,
 * since nodes can have the same value but be different objects.
 *
 * Example:
 *   List1: A -> B -> C -> D -> E
 *   List2: X -> Y -> C -> D -> E
 *   Intersection point: Node with value C
 *
 * Intuition:
 * ----------
 * We want to identify the first node where the two lists merge.
 * Three common approaches:
 *
 * 1. Brute Force (Hashing):
 *    - Store nodes of first list in a hash set.
 *    - Traverse second list and check for first node already in set.
 *    - Time: O(N1 + N2), Space: O(N1)
 *
 * 2. Using Length Difference:
 *    - Calculate lengths of both lists.
 *    - Advance pointer of longer list by difference in lengths.
 *    - Then move both pointers together until they meet or end.
 *    - Time: O(N1 + N2), Space: O(1)
 *
 * 3. Optimal Two Pointer Redirection:
 *    - Use two pointers starting at heads of lists.
 *    - When a pointer reaches end, redirect it to other list's head.
 *    - Eventually, they align and meet at intersection or nullptr.
 *    - Time: O(N1 + N2), Space: O(1)
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
 * Approach 1: Brute Force using Hashing
 * -------------------------------------
 * 1. Traverse first list and insert all nodes in a hash set.
 * 2. Traverse second list and check if any node is present in the set.
 * 3. Return the first matching node.
 */
Node* intersectionHashing(Node* head1, Node* head2) {
    unordered_set<Node*> nodesSet;
    Node* curr = head1;
    while (curr) {
        nodesSet.insert(curr);
        curr = curr->next;
    }
    curr = head2;
    while (curr) {
        if (nodesSet.find(curr) != nodesSet.end()) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

/*
 * Utility: Find length of linked list
 */
int getLength(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

/*
 * Approach 2: Using Length Difference
 * -----------------------------------
 * 1. Calculate lengths of both lists.
 * 2. Move pointer of longer list forward by difference.
 * 3. Traverse both lists simultaneously to find intersection.
 */
Node* intersectionLengthDiff(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node* longer = (len1 >= len2) ? head1 : head2;
    Node* shorter = (len1 < len2) ? head1 : head2;

    // Move longer list pointer ahead by diff steps
    for (int i = 0; i < diff; i++) {
        longer = longer->next;
    }

    // Move both pointers until they meet or reach end
    while (longer && shorter) {
        if (longer == shorter) return longer;
        longer = longer->next;
        shorter = shorter->next;
    }
    return nullptr;
}

/*
 * Approach 3: Optimal Two Pointer Redirection
 * -------------------------------------------
 * 1. Initialize two pointers at heads.
 * 2. Traverse each list; when reaching end, switch to other list's head.
 * 3. They will either meet at intersection or both reach nullptr.
 */
Node* intersectionTwoPointers(Node* head1, Node* head2) {
    if (!head1 || !head2) return nullptr;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        ptr1 = (ptr1) ? ptr1->next : head2;
        ptr2 = (ptr2) ? ptr2->next : head1;
    }

    return ptr1; // either intersection node or nullptr
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

// Helper to join two lists at given node
void joinListsAt(Node* head1, Node* head2, Node* joinNode) {
    if (!head1 || !head2 || !joinNode) return;

    Node* curr = head1;
    while (curr->next) curr = curr->next;
    curr->next = joinNode;

    curr = head2;
    while (curr->next) curr = curr->next;
    curr->next = joinNode;
}

// Main: Test all approaches
int main() {
    // Create two lists:
    // List1: 1 -> 2 -> 3 -> 4 -> 5
    // List2: 9 -> 10
    // Intersection at node with value 3
    Node* common = createList({3, 4, 5});
    Node* list1 = createList({1, 2});
    Node* list2 = createList({9, 10});

    // Connect lists to common intersection
    Node* tail1 = list1;
    while (tail1->next) tail1 = tail1->next;
    tail1->next = common;

    Node* tail2 = list2;
    while (tail2->next) tail2 = tail2->next;
    tail2->next = common;

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* intersectNode;

    intersectNode = intersectionHashing(list1, list2);
    cout << "Intersection (Hashing): ";
    cout << (intersectNode ? to_string(intersectNode->data) : "No Intersection") << endl;

    intersectNode = intersectionLengthDiff(list1, list2);
    cout << "Intersection (Length Diff): ";
    cout << (intersectNode ? to_string(intersectNode->data) : "No Intersection") << endl;

    intersectNode = intersectionTwoPointers(list1, list2);
    cout << "Intersection (Two Pointers): ";
    cout << (intersectNode ? to_string(intersectNode->data) : "No Intersection") << endl;

    return 0;
}
