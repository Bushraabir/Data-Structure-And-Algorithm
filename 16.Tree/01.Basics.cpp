// Trees are hierarchical data structures
// where each node has a value and pointers to its children.


#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------
//  Definition of a Tree Node
// ----------------------------------------------------
struct TreeNode {
    int val;            // Value of the node
    TreeNode* left;     // Pointer to left child
    TreeNode* right;    // Pointer to right child

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

/*
------------------------------------------------------
# Key Terminology in Trees:
------------------------------------------------------
1. Root       -> The topmost node of the tree.
2. Children   -> Nodes directly connected below a parent.
3. Leaf Node  -> A node with NO children.
4. Subtree    -> Any node with all its descendants.
5. Ancestors  -> All nodes on the path from root to the node.
------------------------------------------------------
*/

// ----------------------------------------------------
// # Types of Binary Trees (Explained with Notes)
// ----------------------------------------------------

/*
1. Full Binary Tree:
   - Every node has either 0 or 2 children.
   - If a node has only 1 child → NOT a full binary tree.
   Example:
            1
           / \
          2   3
         / \   
        4   5
*/
bool isFullBinary(TreeNode* root) {
    if (root == NULL) return true;
    if (!root->left && !root->right) return true;  // leaf node
    if (root->left && root->right)
        return isFullBinary(root->left) && isFullBinary(root->right);
    return false;
}

/*
2. Complete Binary Tree:
   - All levels must be completely filled
      except possibly the last.
   - The last level must be filled from LEFT to RIGHT.
   Example:
            1
           / \
          2   3
         / \  /
        4  5 6     ✅ Complete
*/
bool isCompleteBinary(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool nullFound = false;

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();

        if (node == NULL) {
            nullFound = true;
        } else {
            if (nullFound) return false; // if NULL found earlier → must not have more nodes
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}

/*
3. Perfect Binary Tree:
   - All internal nodes have 2 children
   - All leaf nodes are at the SAME LEVEL
   Example:
            1
           / \
          2   3
         / \ / \
        4  5 6  7   ✅ Perfect
*/
int depth(TreeNode* node) {
    int d = 0;
    while (node) {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfectBinary(TreeNode* root, int d, int level = 1) {
    if (!root) return true;
    if (!root->left && !root->right) return (d == level); // leaf at same depth
    if (!root->left || !root->right) return false; // must have 2 children
    return isPerfectBinary(root->left, d, level+1) && isPerfectBinary(root->right, d, level+1);
}

/*
4. Balanced Binary Tree:
   - Height of tree should be O(logN)
   - Helps in efficient searching
   Example: AVL Tree, Red-Black Tree
*/
int checkHeight(TreeNode* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    if (lh == -1) return -1;
    int rh = checkHeight(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1; // not balanced
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

/*
5. Degenerate (Skewed) Tree:
   - Each parent has only ONE child.
   - Looks like a Linked List.
   Example:
          1
           \
            2
             \
              3
               \
                4
*/
bool isSkewed(TreeNode* root) {
    if (!root) return true;
    if (root->left && root->right) return false;
    return isSkewed(root->left) || isSkewed(root->right);
}

// ----------------------------------------------------
// 🔹 Main Function to Test
// ----------------------------------------------------
int main() {
    /*
       Example Tree:
               1
              / \
             2   3
            / \   
           4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Is Full Binary Tree? " << (isFullBinary(root) ? "Yes" : "No") << endl;
    cout << "Is Complete Binary Tree? " << (isCompleteBinary(root) ? "Yes" : "No") << endl;
    cout << "Is Perfect Binary Tree? " << (isPerfectBinary(root, depth(root)) ? "Yes" : "No") << endl;
    cout << "Is Balanced Binary Tree? " << (isBalanced(root) ? "Yes" : "No") << endl;
    cout << "Is Skewed Tree? " << (isSkewed(root) ? "Yes" : "No") << endl;

    return 0;
}
