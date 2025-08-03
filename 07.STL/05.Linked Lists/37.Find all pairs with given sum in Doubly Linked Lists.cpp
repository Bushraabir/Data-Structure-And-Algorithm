/*
 * Problem: Find All Pairs with Given Sum in Doubly Linked List
 *
 * Problem Statement:
 * -------------------
 * Given the head of a **sorted** doubly linked list and an integer `target`,
 * return all pairs of nodes whose values sum up to the target.
 *
 * Important:
 * - The doubly linked list is sorted in ascending order.
 * - The list should not be modified.
 * - You must return **all unique pairs** where sum = target.
 * - A node cannot be paired with itself.
 *
 * Example:
 *   Input: 1 <-> 2 <-> 3 <-> 4 <-> 9, target = 5
 *   Output: (1, 4), (2, 3)
 *
 *   Input: 1 <-> 2 <-> 3, target = 6
 *   Output: []
 *
 * Intuition:
 * ----------
 * Since the list is sorted, we can use the two-pointer approach.
 * Place one pointer at the head (left), and one at the tail (right).
 * At each step:
 *   - If the sum of the two pointers equals target → store the pair.
 *   - If the sum is less than target → move left forward.
 *   - If the sum is greater than target → move right backward.
 *
 * The loop stops when left meets or crosses right.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1) (excluding space used to store result pairs)
 */

#include <iostream>
#include <vector>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

/*
 * Function: findPairsWithSum
 * ----------------------------
 * Finds all unique pairs in the DLL that sum up to the target.
 * Returns a vector of pairs (each pair is a vector of 2 integers).
 */
vector<vector<int>> findPairsWithSum(Node* head, int target) {
    vector<vector<int>> result;
    if (!head) return result;

    // Step 1: Find tail
    Node* left = head;
    Node* right = head;
    while (right->next != nullptr)
        right = right->next;

    // Step 2: Two-pointer approach
    while (left != right && left->prev != right) {
        int sum = left->data + right->data;

        if (sum == target) {
            result.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else { // sum > target
            right = right->prev;
        }
    }

    return result;
}

// Utility: Create a Doubly Linked List from initializer list
Node* createDLL(initializer_list<int> vals) {
    Node* head = nullptr, *tail = nullptr;
    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

// Utility: Print DLL
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility: Print result pairs
void printPairs(const vector<vector<int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p[0] << ", " << p[1] << ") ";
    }
    cout << endl;
}

// Test Driver
int main() {
    // Test Case 1
    Node* head1 = createDLL({1, 2, 3, 4, 9});
    cout << "Original List: ";
    printDLL(head1);
    int target1 = 5;
    vector<vector<int>> result1 = findPairsWithSum(head1, target1);
    cout << "Pairs with sum = " << target1 << ": ";
    printPairs(result1);

    // Test Case 2
    Node* head2 = createDLL({1, 2, 3});
    cout << "\nOriginal List: ";
    printDLL(head2);
    int target2 = 6;
    vector<vector<int>> result2 = findPairsWithSum(head2, target2);
    cout << "Pairs with sum = " << target2 << ": ";
    printPairs(result2);

    // Test Case 3
    Node* head3 = createDLL({1, 2, 3, 4, 5, 6});
    cout << "\nOriginal List: ";
    printDLL(head3);
    int target3 = 7;
    vector<vector<int>> result3 = findPairsWithSum(head3, target3);
    cout << "Pairs with sum = " << target3 << ": ";
    printPairs(result3);

    return 0;
}
