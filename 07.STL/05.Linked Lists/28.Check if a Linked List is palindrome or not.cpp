/*
 * Problem: Check if a Linked List is a Palindrome
 *
 * Problem Statement:
 * -------------------
 * Given the head of a singly linked list, determine whether the list is a palindrome.
 *
 * Example:
 *   Input:  head = 1 -> 2 -> 3 -> 2 -> 1
 *   Output: true
 *   Input:  head = 1 -> 2 -> 3 -> 4
 *   Output: false
 *
 * Intuition:
 * ----------
 * A palindrome reads the same forwards and backwards. In a linked list, this means the first half
 * should match the reversed second half. We have two approaches:
 *
 * 1. Brute Force (Using Stack):
 *    - Store all node values in a stack (which reverses order).
 *    - Traverse the list again and compare each node's value with the top of the stack.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(N)
 *
 * 2. Optimal (Reverse Second Half In-Place):
 *    - Use slow and fast pointers to find the middle.
 *    - Reverse the second half of the list.
 *    - Compare first half and reversed second half.
 *    - Restore the original list before returning.
 *    - Time Complexity: O(N)
 *    - Space Complexity: O(1)
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

// Utility: Reverse a linked list iteratively
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

/*
 * Approach 1: Brute Force using Stack
 * -----------------------------------
 * 1. Traverse and push all node values into a stack.
 * 2. Traverse again and compare with stack top.
 */
bool isPalindrome_Stack(Node* head) {
    stack<int> st;
    Node* temp = head;

    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp) {
        if (temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}

/*
 * Approach 2: Optimal Approach (In-place Reversal)
 * ------------------------------------------------
 * 1. Use slow/fast pointers to reach middle.
 * 2. Reverse second half of list.
 * 3. Compare first and second halves.
 * 4. Restore the second half before returning.
 */
bool isPalindrome_Optimal(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* secondHead = reverseList(slow->next);
    Node* first = head;
    Node* second = secondHead;

    // Step 3: Compare
    bool isPalin = true;
    while (second) {
        if (first->data != second->data) {
            isPalin = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore second half
    slow->next = reverseList(secondHead);

    return isPalin;
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

// Main: Test both approaches
int main() {
    Node* list1 = createList({1, 2, 3, 2, 1});
    Node* list2 = createList({1, 2, 2, 1});
    Node* list3 = createList({1, 2, 3, 4, 5});

    cout << "List 1: ";
    printList(list1);
    cout << "Palindrome (Stack)?   " << (isPalindrome_Stack(list1) ? "Yes" : "No") << endl;
    cout << "Palindrome (Optimal)? " << (isPalindrome_Optimal(list1) ? "Yes" : "No") << endl << endl;

    cout << "List 2: ";
    printList(list2);
    cout << "Palindrome (Stack)?   " << (isPalindrome_Stack(list2) ? "Yes" : "No") << endl;
    cout << "Palindrome (Optimal)? " << (isPalindrome_Optimal(list2) ? "Yes" : "No") << endl << endl;

    cout << "List 3: ";
    printList(list3);
    cout << "Palindrome (Stack)?   " << (isPalindrome_Stack(list3) ? "Yes" : "No") << endl;
    cout << "Palindrome (Optimal)? " << (isPalindrome_Optimal(list3) ? "Yes" : "No") << endl;

    return 0;
}
