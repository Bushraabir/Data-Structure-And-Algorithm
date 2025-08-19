#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Count the total number of nodes in a **Complete Binary Tree**.

Definition:
- A complete binary tree is one where every level, except possibly the last, 
  is completely filled, and all nodes in the last level are as far left as possible.

Goal:
- Design an algorithm to count nodes in **less than O(N)** time.

Example:
Input Tree:
          1
         / \
        2   3
       / \  /
      4  5 6

Output: 6

================================================================================
Intuition / Approach:
================================================================================
Brute Force:
- Traverse the entire tree (inorder/preorder/postorder/level order).
- Maintain a counter of visited nodes.
- Time Complexity = O(N).

Optimized Approach: O(log^2 N)
- Use properties of Complete Binary Trees.
- If a subtree is a **Full Binary Tree**, its node count can be directly computed 
  using the formula: 2^height - 1.
- Otherwise, recursively calculate for left and right subtrees.

Steps:
1. For a given node, compute:
   - Left Height → by traversing leftmost path.
   - Right Height → by traversing rightmost path.
2. If (leftHeight == rightHeight):
   - Subtree is full → return (2^height - 1).
3. Else:
   - Recurse into left and right subtrees.
   - Return 1 (root) + count(left subtree) + count(right subtree).

================================================================================
Time and Space Complexity:
================================================================================
Time Complexity: O(log^2 N)
- For each level (log N levels), we compute height in O(log N).
- Total = O(log N * log N) = O(log^2 N).

Space Complexity: O(log N)
- Due to recursion depth (height of tree).
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
// Helper Function: Find Left Height
// ---------------------------
int leftHeight(Node* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

// ---------------------------
// Helper Function: Find Right Height
// ---------------------------
int rightHeight(Node* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}

// ---------------------------
// Main Function: Count Nodes in Complete Binary Tree
// ---------------------------
int countNodes(Node* root) {
    if (!root) return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh) {
        // Full binary tree: apply formula
        return (1 << lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Example Tree:
        
                1
               / \
              2   3
             / \  /
            4  5 6

        Expected Output: 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Total nodes in the complete binary tree: " 
         << countNodes(root) << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity:
- Each recursive step computes left and right heights: O(log N).
- We do this for log N levels.
- Total = O(log^2 N).

Space Complexity:
- Recursion depth = height of tree = O(log N).
================================================================================
*/
