// Largest BST in a Binary Tree
// ----------------------------------------------------------
// Problem: You are given the root of a Binary Tree (not
// necessarily a BST). Find the size (number of nodes) of the
// largest Binary Search Tree (BST) present within it.
//
// Example:
// Input Binary Tree:
//          10
//         /  \
//        5   15
//       / \    \
//      1   8    7
//
// Largest BST Subtree:
//        5
//       / \
//      1   8
// Size = 3
//
// ----------------------------------------------------------
// Approach 1: Brute Force (Check every subtree)
// ----------------------------------------------------------
// - For each node, check if the subtree rooted at that node is a BST.
// - To check BST, do a traversal with min/max constraints.
// - If valid, count nodes and update max size.
// - Otherwise, recurse left & right.
// - Complexity:
//     Time: O(N^2) (every node → validate subtree O(N))
//     Space: O(H) recursion stack
// - Limitation: Quadratic, not optimal.
//
// ----------------------------------------------------------
// Approach 2: Optimal Post-order Traversal (O(N))
// ----------------------------------------------------------
// - Idea: Use bottom-up postorder traversal.
// - At each node, gather info from left & right subtrees:
//     * Minimum value in subtree
//     * Maximum value in subtree
//     * Size of largest BST in that subtree
// - A node forms a BST if:
//     node->data > left.max && node->data < right.min
// - If valid → size = 1 + left.size + right.size
// - If not valid → propagate max size found in children
// - Maintain global maxSize variable updated during recursion.
// - Complexity:
//     Time: O(N) (each node visited once)
//     Space: O(H) recursion stack
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
// Struct to store subtree info
// ---------------------------
struct NodeValue {
    int minVal;
    int maxVal;
    int size;
    NodeValue(int minVal, int maxVal, int size) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->size = size;
    }
};

// ---------------------------
// Helper Function
// ---------------------------
class LargestBST {
private:
    int maxSize;

    NodeValue helper(Node* root) {
        // Base case: null node → valid BST of size 0
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if current node forms BST with children
        if (root->data > left.maxVal && root->data < right.minVal) {
            int size = 1 + left.size + right.size;
            maxSize = max(maxSize, size);
            return NodeValue(min(root->data, left.minVal),
                             max(root->data, right.maxVal),
                             size);
        }

        // If not BST, return invalid range to break chain
        return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
    }

public:
    int largestBSTSubtree(Node* root) {
        maxSize = 0;
        helper(root);
        return maxSize;
    }
};

// ---------------------------
// Utility: Build Tree (for testing)
// ---------------------------
Node* newNode(int val) {
    return new Node(val);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
            10
           /  \
          5   15
         / \    \
        1   8    7
    */
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(1);
    root->left->right = newNode(8);
    root->right->right = newNode(7);

    LargestBST solver;
    cout << "Size of Largest BST is: " << solver.largestBSTSubtree(root) << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Brute Force:
  -> For each node, validate subtree as BST.
  -> Time: O(N^2), Space: O(H).

- Optimal Post-order:
  -> Gather (min, max, size) from children.
  -> Check if parent forms BST.
  -> Maintain global max size.
  -> Time: O(N), Space: O(H).

- Edge Cases:
  -> Empty tree → size = 0
  -> Single node → size = 1
  -> Entire tree itself is a BST → size = N
================================================================================
*/
