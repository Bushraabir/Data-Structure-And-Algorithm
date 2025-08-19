#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **diameter of a binary tree**.

Definition:
- Diameter = the length of the longest path between any two nodes in the tree.
- The path may or may not pass through the root node.

Example Tree:

            1
           / \
          2   3
         / \     
        4   5   

Expected Output: 3
- The longest path is 4 -> 2 -> 1 -> 3 (length = 3 edges)

================================================================================
Intuition / Approach:
================================================================================
Optimized O(N) Recursive Approach:
1. Use a helper function that calculates height of the subtree.
2. At each node:
   a) Recursively calculate left subtree height (lh)
   b) Recursively calculate right subtree height (rh)
   c) Diameter passing through current node = lh + rh
   d) Maintain a global variable (maxi) to track maximum diameter so far.
   e) Return height = 1 + max(lh, rh) to parent node
3. Final diameter = global variable value after recursion completes.

Dry Run Example:
- Leaf nodes return height = 1 (1 + max(0,0))
- Intermediate nodes update global diameter with lh + rh
- Height propagates upward for parent node calculations

Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(H)
- Recursive stack stores up to H nodes
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
// Recursive Function to Calculate Height and Update Diameter
// ---------------------------
int calcDiameter(Node* root, int &maxi) {
    if (!root) return 0;

    int lh = calcDiameter(root->left, maxi);
    int rh = calcDiameter(root->right, maxi);

    // Update diameter at current node
    maxi = max(maxi, lh + rh);

    // Return height to parent
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node* root) {
    int maxi = 0;
    calcDiameter(root, maxi);
    return maxi; // Diameter in terms of edges
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

    cout << "Diameter of the Tree: " << diameterOfBinaryTree(root) << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once to compute height and update diameter.

Space Complexity: O(H)
- Stack stores up to H nodes for recursive calls
- H = height of tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)

================================================================================
*/
