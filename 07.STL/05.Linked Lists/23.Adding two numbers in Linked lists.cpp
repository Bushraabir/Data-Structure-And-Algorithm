/*
 * Problem: Add Two Numbers Represented by Reversed Linked Lists
 *
 * Problem Statement:
 * -------------------
 * You are given two singly linked lists, L1 and L2, where each node contains a single digit of a number.
 * The numbers are given in reversed order:
 *   - The head node represents the unit's place, the next represents the tens, etc.
 *
 * Example 1:
 *   Input: L1 = 2 -> 4 -> 6 (represents 642), L2 = 3 -> 8 -> 7 (represents 783)
 *   Output: 5 -> 2 -> 4 -> 1 (represents 1425)
 *
 * Example 2:
 *   Input: L1 = 5 -> 3 (represents 35), L2 = 4 -> 5 -> 9 -> 9 (represents 9954)
 *   Output: 9 -> 8 -> 9 -> 9 (represents 9989)
 *
 * Intuition:
 * ----------
 * - Since numbers are stored in reverse order, the head node represents the least significant digit.
 * - We can simulate manual addition from right to left:
 *     • Add digits from corresponding nodes in both lists
 *     • Handle carry over if the sum exceeds 9
 * - Continue until both lists are fully traversed
 * - Use a dummy node to simplify head insertion
 *
 * Detailed Algorithm (Dummy Node Approach):
 * -----------------------------------------
 * 1. Initialization:
 *    - Create a dummy node with dummy value (-1) as a placeholder for the new list
 *    - Use `current` pointer to build the result list starting from dummy
 *    - Use T1 and T2 to traverse L1 and L2 respectively
 *    - Carry is initialized to 0
 *
 * 2. Traverse and Add:
 *    - While T1 or T2 is not null:
 *      • Start sum = carry
 *      • If T1 exists: add T1->data to sum, move T1 = T1->next
 *      • If T2 exists: add T2->data to sum, move T2 = T2->next
 *      • Create new node with sum % 10, attach to current->next
 *      • Update carry = sum / 10
 *      • Move current = current->next
 *
 * 3. Handle Leftover Carry:
 *    - After loop, if carry > 0:
 *      • Create new node with carry, attach to result list
 *
 * 4. Return Result:
 *    - Return dummy->next (first real node in the result list)
 *
 * Time Complexity: O(max(N1, N2))
 * Space Complexity: O(max(N1, N2)) — space used to store result list
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

// Function to add two reversed linked lists
Node* addTwoNumbers(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);  // Dummy head to simplify list creation
    Node* current = dummy;

    Node* T1 = head1;
    Node* T2 = head2;

    int carry = 0;

    while (T1 || T2) {
        int sum = carry;

        if (T1) {
            sum += T1->data;
            T1 = T1->next;
        }

        if (T2) {
            sum += T2->data;
            T2 = T2->next;
        }

        carry = sum / 10;
        Node* newNode = new Node(sum % 10);
        current->next = newNode;
        current = current->next;
    }

    // If there is leftover carry, create an extra node
    if (carry > 0) {
        current->next = new Node(carry);
    }

    return dummy->next;  // The actual head of the result list
}

// Utility function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from an array (in reversed order)
Node* createReversedList(const vector<int>& digits) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int digit : digits) {
        Node* newNode = new Node(digit);
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

// Example usage
int main() {
    // Example 1: 642 + 783 = 1425 -> 5 -> 2 -> 4 -> 1
    vector<int> l1_digits = {2, 4, 6};  // represents 642
    vector<int> l2_digits = {3, 8, 7};  // represents 783

    Node* L1 = createReversedList(l1_digits);
    Node* L2 = createReversedList(l2_digits);

    Node* result = addTwoNumbers(L1, L2);

    cout << "Sum List: ";
    printList(result);

    return 0;
}
