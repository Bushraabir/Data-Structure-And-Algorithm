/*
 * Problem: Rearranging a Linked List by Odd and Even Indices
 *
 * Problem Statement:
 * -------------------
 * You are given the head of a singly linked list. Reorder the list so that:
 *   - All odd-indexed nodes (1-based) appear first
 *   - Followed by all even-indexed nodes
 *   - The relative order of nodes in both groups remains the same
 *
 * Example:
 *   Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6
 *   Output: 1 -> 3 -> 5 -> 2 -> 4 -> 6
 *
 * Intuition:
 * ----------
 * 1. **Naive (Brute Force) Solution**:
 *    - Store the data of odd-indexed and even-indexed nodes separately in a list
 *    - Overwrite original list nodes using this combined list
 *    - Space inefficient (O(N) extra space)
 *
 * 2. **Optimal (In-Place Link Manipulation)**:
 *    - Use two pointers to separate odd and even indexed nodes while traversing
 *    - Reconnect the tail of odd list to the head of even list
 *    - Achieves O(1) space with a single traversal
 *
 * Approach 1: Naive Solution (Data Replacement)
 * ---------------------------------------------
 * 1. Handle edge cases: return head if list is empty or has one node
 * 2. Collect odd-indexed data:
 *    - Start at head, move by 2 steps at a time
 *    - Store each odd-indexed node’s data in an array
 *    - Include last odd node if loop missed it
 * 3. Collect even-indexed data:
 *    - Start at head->next, move by 2 steps
 *    - Append each even-indexed node’s data to the array
 * 4. Overwrite the linked list using the array
 * 5. Return head
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Brute force method using extra space to rearrange list
Node* rearrangeOddEven_BruteForce(Node* head) {
    if (!head || !head->next) return head;

    vector<int> vals;

    // Collect odd-indexed nodes
    Node* temp = head;
    while (temp && temp->next) {
        vals.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp) vals.push_back(temp->data);  // Last odd node

    // Collect even-indexed nodes
    temp = head->next;
    while (temp && temp->next) {
        vals.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp) vals.push_back(temp->data);  // Last even node

    // Overwrite data in the list
    temp = head;
    int i = 0;
    while (temp) {
        temp->data = vals[i++];
        temp = temp->next;
    }

    return head;
}

/*
 * Approach 2: Optimal Solution (In-Place Pointer Manipulation)
 * ------------------------------------------------------------
 * 1. Handle edge cases: return head if list is empty or has one node
 * 2. Initialize:
 *    - odd = head
 *    - even = head->next
 *    - evenHead = even (needed to reconnect later)
 * 3. Traverse and modify pointers:
 *    - Loop until even or even->next is null
 *    - odd->next = even->next
 *    - odd = odd->next
 *    - even->next = odd->next
 *    - even = even->next
 * 4. Connect last odd node to evenHead
 * 5. Return original head
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

// Optimal method using pointer manipulation
Node* rearrangeOddEven_Optimal(Node* head) {
    if (!head || !head->next) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

// Utility: Create linked list from array
Node* createList(const vector<int>& arr) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : arr) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
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

// Example usage
int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6};
    Node* head1 = createList(values);
    Node* head2 = createList(values);

    cout << "Original List: ";
    printList(head1);

    head1 = rearrangeOddEven_BruteForce(head1);
    cout << "After Brute Force Rearrangement: ";
    printList(head1);

    head2 = rearrangeOddEven_Optimal(head2);
    cout << "After Optimal Rearrangement: ";
    printList(head2);

    return 0;
}
