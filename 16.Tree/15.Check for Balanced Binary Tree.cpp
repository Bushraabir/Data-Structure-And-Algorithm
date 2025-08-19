#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Check if a given binary tree is **balanced**.

Definition:
- A binary tree is balanced if, for every node, the absolute difference between
  the height of its left subtree and right subtree is <= 1.

Example Trees:

Balanced:

            1
           / \
          2   3
         / \
        4   5

Output: Balanced (true)

Not Balanced:

            1
           / \
          2   3
         /
        4

Output: Not Balanced (false)

================================================================================
Intuition / Approach:
================================================================================
Optimized O(N) Recursive Approach:
1. For each node, calculate height while simultaneously checking balance.
2. Base Case:
   - If node is NULL, height = 0.
3. Recursive Steps:
   a) Get height of left subtree (lh)
      - If lh == -1, propagate -1 upward (subtree unbalanced)
   b) Get height of right subtree (rh)
      - If rh == -1, propagate -1 upward
   c) Check balance at current node:
      - If abs(lh - rh) > 1, return -1 (unbalanced)
   d) Otherwise, return height = 1 + max(lh, rh)
4. Finally, if the initial call returns -1, tree is unbalanced; otherwise, balanced.

Time Complexity: O(N)
- Each node is visited once.

Space Complexity: O(H)
- Recursive call stack stores up to H nodes
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
// Recursive Function to Check Balance
// Returns: height if balanced, -1 if unbalanced
// ---------------------------
int checkHeight(Node* root) {
    if (!root) return 0;

    int lh = checkHeight(root->left);
    if (lh == -1) return -1;  // left subtree unbalanced

    int rh = checkHeight(root->right);
    if (rh == -1) return -1;  // right subtree unbalanced

    if (abs(lh - rh) > 1) return -1; // current node unbalanced

    return 1 + max(lh, rh); // return height if balanced
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
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
         / \
        4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isBalanced(root))
        cout << "The tree is balanced.\n";
    else
        cout << "The tree is not balanced.\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once to compute height and check balance.

Space Complexity: O(H)
- Stack stores up to H nodes for recursive calls
- H = height of tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)

================================================================================
*/
