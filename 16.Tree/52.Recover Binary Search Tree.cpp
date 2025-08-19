// Recover BST
// ----------------------------------------------------------
// Problem: You are given the root of a Binary Search Tree (BST)
// where exactly two nodes have been swapped by mistake.
// Recover the BST without changing its structure.
//
// Example:
// Input BST (corrupted):
//        3
//       / \
//      1   4
//         /
//        2
// Inorder (wrong): 1, 3, 2, 4
//
// Correct BST:
//        2
//       / \
//      1   4
//         /
//        3
// Inorder (fixed): 1, 2, 3, 4
//
// ----------------------------------------------------------
// Approach 1: Brute Force (Inorder + Sorting) - O(N log N)
// ----------------------------------------------------------
// - Do inorder traversal → get array of node values.
// - Sort the array → gives correct inorder sequence.
// - Do another inorder traversal, assign sorted values back.
// - Complexity:
//     Time: O(N log N) (due to sorting)
//     Space: O(N) (store inorder values)
// - Limitation: Not optimal, uses extra memory.
//
// ----------------------------------------------------------
// Approach 2: Optimal Inorder Traversal (O(H) space)
// ----------------------------------------------------------
// - Idea: Inorder of BST should be strictly increasing.
// - When two nodes are swapped, we see "violations":
//     Case 1 (Non-adjacent swap): Two violations → first & last
//     Case 2 (Adjacent swap): One violation → first & middle
// - Maintain 4 pointers: prev, first, middle, last
// - During inorder traversal:
//     if (prev != null && current->data < prev->data):
//         if (first == null):
//             first = prev, middle = current
//         else:
//             last = current
// - After traversal:
//     if (last) swap(first->data, last->data)
//     else swap(first->data, middle->data)
// - Complexity:
//     Time: O(N) (each node visited once)
//     Space: O(H) (recursion stack), Morris traversal → O(1)
//
// ----------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Definition of a Tree Node
// ---------------------------
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ---------------------------
// Recover BST Class
// ---------------------------
class RecoverBST {
private:
    Node* first;
    Node* middle;
    Node* last;
    Node* prev;

    // Inorder traversal to detect swapped nodes
    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->data < prev->data) {
            // First violation
            if (!first) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    RecoverBST() {
        first = middle = last = prev = nullptr;
    }

    void recoverTree(Node* root) {
        inorder(root);

        // Fix swapped nodes
        if (first && last) swap(first->data, last->data);
        else if (first && middle) swap(first->data, middle->data);
    }
};

// ---------------------------
// Insert into BST (utility for testing)
// ---------------------------
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Inorder print (utility)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    // Build BST with swapped nodes
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2); // swapped with 3

    cout << "Inorder before fix: ";
    printInorder(root);
    cout << endl;

    RecoverBST solver;
    solver.recoverTree(root);

    cout << "Inorder after fix: ";
    printInorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Brute Force Method:
  -> Inorder + sort + reassign values.
  -> Time: O(N log N), Space: O(N).

- Optimal Method (Inorder with pointers):
  -> Detect violations in sorted order.
  -> Either swap (first, last) OR (first, middle).
  -> Time: O(N), Space: O(H).

- Edge Cases:
  -> Tree empty → nothing to fix.
  -> Tree with 2 nodes → simple swap.
  -> Swapped nodes adjacent or non-adjacent.

- Advanced:
  -> Can reduce recursion stack O(H) → O(1) using Morris traversal.
================================================================================
*/
