#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Traverse a binary tree in **Inorder** or **Preorder** without using recursion 
or a stack, achieving **O(1) auxiliary space**.

Definitions:
- Morris Traversal: Temporarily modifies the tree to create "threads" (backward 
  pointers) that allow traversal without extra memory. Original tree is restored 
  after traversal.

================================================================================
Example:
================================================================================
Tree:

        1
       / \
      2   3
     / \
    4   5

Inorder Traversal (Left, Root, Right): 4 2 5 1 3
Preorder Traversal (Root, Left, Right): 1 2 4 5 3

================================================================================
Intuition / Approach:
================================================================================
**Morris Inorder Traversal (Left, Root, Right)**
1. Start at root (`curr`).
2. If `curr` has no left child:
   - Print/process `curr`'s value.
   - Move to right child (`curr = curr->right`).
3. If `curr` has a left child:
   - Find the rightmost node (`prev`) in `curr`'s left subtree.
   - If `prev->right == null`:
     - Create thread: `prev->right = curr`.
     - Move to left child (`curr = curr->left`).
   - If `prev->right == curr`:
     - Remove thread: `prev->right = null`.
     - Print/process `curr`'s value.
     - Move to right child (`curr = curr->right`).

**Morris Preorder Traversal (Root, Left, Right)**
- Same logic as inorder, but print `curr` **before** going to left subtree:
  - If `prev->right == null`, print `curr`'s value before creating thread.

--------------------------------------------------------------------------------
Optimization:
- No recursion or stack → O(1) auxiliary space.
- Only modifies tree temporarily → tree restored after traversal.

================================================================================
Time and Space Complexity:
================================================================================
Time Complexity: O(N) amortized
- Each edge visited at most twice.

Space Complexity: O(1) auxiliary
- Only uses pointers, no extra stack or recursion.
================================================================================
*/

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
// Morris Inorder Traversal
// ---------------------------
void morrisInorder(Node* root) {
    Node* curr = root;

    while (curr) {
        if (!curr->left) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (!prev->right) {
                prev->right = curr; // create thread
                curr = curr->left;
            } else {
                prev->right = nullptr; // remove thread
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

// ---------------------------
// Morris Preorder Traversal
// ---------------------------
void morrisPreorder(Node* root) {
    Node* curr = root;

    while (curr) {
        if (!curr->left) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (!prev->right) {
                cout << curr->data << " "; // print before threading
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr; // remove thread
                curr = curr->right;
            }
        }
    }
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Inorder Traversal: ";
    morrisInorder(root);
    cout << endl;

    cout << "Morris Preorder Traversal: ";
    morrisPreorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Morris Traversal allows O(N) time traversal with O(1) auxiliary space.
- Works for Inorder and Preorder.
- Temporarily modifies tree structure (threads) and restores it.
================================================================================
*/
