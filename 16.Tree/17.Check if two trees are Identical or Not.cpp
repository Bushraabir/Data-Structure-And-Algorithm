#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Check if two given binary trees are **identical**.

Definition:
- Two binary trees are identical if they have the exact same structure and
  the same node values at corresponding positions.

Example Trees:

Tree 1:

        1
       / \
      2   3

Tree 2:

        1
       / \
      2   3

Output: Identical (true)

Tree 1:

        1
       / \
      2   3

Tree 2:

        1
       /
      2

Output: Not Identical (false)

================================================================================
Intuition / Approach:
================================================================================
Recursive Approach (Simultaneous Traversal):
1. Base Cases:
   a) If both nodes are NULL: return true (matching null structure)
   b) If one node is NULL and the other is not: return false
2. If both nodes are non-NULL:
   a) Check if current node values are equal
   b) Recursively check left subtrees
   c) Recursively check right subtrees
   d) Return true only if both left and right subtree checks return true

Time Complexity: O(N)
- Each node of both trees is visited once.

Space Complexity: O(H)
- Stack stores up to H nodes for recursive calls
- H = height of the tree
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
// Recursive Function to Check Identical Trees
// ---------------------------
bool isIdentical(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;   // both null
    if (!root1 || !root2) return false;  // one null, one not
    if (root1->data != root2->data) return false; // value mismatch

    // Recursively check left and right subtrees
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Tree 1:

            1
           / \
          2   3
    */
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    /*
        Constructing Tree 2:

            1
           / \
          2   3
    */
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (isIdentical(root1, root2))
        cout << "The trees are identical.\n";
    else
        cout << "The trees are not identical.\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node of both trees is visited once.

Space Complexity: O(H)
- Stack stores up to H nodes for recursive calls
- H = height of the tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)

================================================================================
*/
