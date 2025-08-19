#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **maximum depth (height) of a binary tree**.

Definition:
- Maximum depth (height) = number of nodes along the longest path from root to leaf.
- A single node tree has height = 1.

Example Tree:

            1
           / \
          2   3
         / \   \
        4   5   6

Expected Output: 3
(The longest path is 1 -> 3 -> 6 or 1 -> 2 -> 4/5)

================================================================================
Intuition / Approach:
================================================================================
1. Recursive approach:
   - Base case: if node is NULL, return 0.
   - Otherwise, height = 1 + max(height(left subtree), height(right subtree))
   - The '+1' accounts for the current node.
2. Dry run example:
   - Leaf nodes return 1 (1 + max(0,0)).
   - Heights propagate upward, always taking the maximum of left and right subtree.
3. This ensures the final value returned at the root is the maximum depth of the tree.

Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(H)
- Recursive call stack stores up to H nodes (height of tree)
- Worst case skewed tree: O(N)
- Balanced tree: O(log N)

================================================================================
*/

// ---------------------------
// Definition of a Node in Binary Tree
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
// Recursive Function to Find Maximum Depth
// ---------------------------
int maxDepth(Node* root) {
    if (!root) return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the Binary Tree:

            1
           / \
          2   3
         / \   \
        4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Maximum Depth (Height) of Tree: " << maxDepth(root) << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once to calculate height.

Space Complexity: O(H)
- Stack stores up to H nodes for recursive calls
- H = height of tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)

================================================================================
*/
