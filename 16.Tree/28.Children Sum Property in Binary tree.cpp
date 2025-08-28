#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Convert a given binary tree so that it satisfies the **Children Sum Property**.

Definition:
- For every non-leaf node of the tree, the value of the node must be equal to 
  the sum of the values of its left and right children.
- Allowed Operation: You can **only increment** a node's value by 1 any number 
  of times.
- You cannot decrement values or change the tree structure.

Example Tree:

            50
           /  \
         7     2
        / \   / \
       3  5  1   30

After Conversion (Children Sum Property satisfied):

            100
           /   \
         50     50
        / \    /  \
       25 25  1    49

================================================================================
Intuition / Approach:
================================================================================
Approach: Recursive Traversal (Top-Down + Bottom-Up adjustments)

1. Base Case:
   - If node is NULL or a leaf, return.

2. Going Down (Top-Down adjustment):
   - Compute sum of left and right child values.
   - If this sum is >= parent’s value → update parent = sum.
   - If this sum is < parent’s value → increment children to match parent.

3. Recurse on left and right children.

4. Coming Back Up (Bottom-Up adjustment):
   - After recursive calls, recompute sum of children.
   - Update current node’s value = sum of children.

This ensures:
- While going down, children are never smaller than parent.
- While coming back, parent is always updated to the exact sum of children.

================================================================================
Time and Space Complexity:
================================================================================
Time Complexity: O(N)
- Each node is visited once.

Space Complexity: O(H)
- Recursion stack takes O(H), where H = height of tree.
- Worst case (skewed tree): O(N)
- Best case (balanced tree): O(log N)

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
// Recursive Function to Convert Tree
// ---------------------------
void convertTree(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) return;  // leaf node

    // Step 1: Calculate children sum
    int child = 0;
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    // Step 2: Top-down adjustment
    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    // Step 3: Recurse for children
    convertTree(root->left);
    convertTree(root->right);

    // Step 4: Bottom-up adjustment
    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;

    if (root->left || root->right) root->data = total;
}

// ---------------------------
// Helper Function: Inorder Traversal
// ---------------------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Example Tree:

                50
               /  \
             7     2
            / \   / \
           3  5  1   30

        After conversion, tree will satisfy Children Sum Property
    */

    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    convertTree(root);

    cout << "Inorder Traversal After Conversion: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once during recursion.

Space Complexity: O(H)
- Extra recursion stack space is proportional to the height of the tree.
- Balanced tree: O(log N)
- Skewed tree: O(N)
================================================================================
*/
