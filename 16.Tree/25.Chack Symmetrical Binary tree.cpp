#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Check if a given binary tree is **symmetric**.

Definition:
- A binary tree is symmetric if it forms a mirror image of itself around its center.

Example Symmetric Tree:

            1
           / \
          2   2
         / \ / \
        3  4 4  3

Output: Symmetric (true)

Example Non-Symmetric Tree:

            1
           / \
          2   2
           \    \
            3    3

Output: Not Symmetric (false)

================================================================================
Intuition / Approach:
================================================================================
Recursive Mirror Comparison:

1. Use a helper function isMirror(node1, node2):
   - Base Cases:
     a) If both nodes are NULL: return true
     b) If one node is NULL and the other is not: return false
     c) If node1->data != node2->data: return false
   - Recursive Step:
     - Check left subtree of node1 with right subtree of node2
     - Check right subtree of node1 with left subtree of node2
     - Return true only if both recursive checks return true

2. Call isMirror(root->left, root->right) to determine symmetry.

Time Complexity: O(N)
- Each node is visited once during the recursive check.

Space Complexity: O(H)
- Recursive stack stores up to H nodes (height of tree)
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
// Recursive Function to Check Symmetry
// ---------------------------
bool isMirror(Node* node1, Node* node2) {
    if (!node1 && !node2) return true;          // both null
    if (!node1 || !node2) return false;         // one null
    if (node1->data != node2->data) return false;

    // Check mirrored children
    return isMirror(node1->left, node2->right) &&
           isMirror(node1->right, node2->left);
}

bool isSymmetric(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Symmetric Example Tree:

                1
               / \
              2   2
             / \ / \
            3  4 4  3
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once in the recursive mirror check.

Space Complexity: O(H)
- Recursive stack can hold up to H nodes
- H = height of the tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
================================================================================
*/
