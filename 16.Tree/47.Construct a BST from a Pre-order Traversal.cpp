// Construct BST from Preorder Traversal
// ----------------------------------------------------------
// Problem: Given a preorder traversal array of a BST,
// construct and return the Binary Search Tree.
// Preorder Traversal = [Root, Left, Right]
// In a BST, left < root < right. We use this property + preorder order.

// ----------------------------------------------------------
// Approach: Range Constraints (Efficient O(N))
// ----------------------------------------------------------
// - Use a global/index pointer to track current element in preorder.
// - Each recursive call checks if current value lies in valid (min, max).
// - If yes → create node, increment index, build left & right subtrees.
// - Left subtree range = (min, root->data)
// - Right subtree range = (root->data, max)

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
// Recursive Helper Function
// ---------------------------
Node* constructBSTUtil(vector<int>& preorder, int& index, int minVal, int maxVal) {
    // Base case: index out of bounds
    if (index >= preorder.size()) return nullptr;

    int val = preorder[index];

    // If value not in range, can't be placed here
    if (val < minVal || val > maxVal) return nullptr;

    // Create node for this value
    Node* root = new Node(val);
    index++; // Move to next element

    // Build left subtree (values < root)
    root->left = constructBSTUtil(preorder, index, minVal, val);

    // Build right subtree (values > root)
    root->right = constructBSTUtil(preorder, index, val, maxVal);

    return root;
}

// ---------------------------
// Main Function to Construct BST
// ---------------------------
Node* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return constructBSTUtil(preorder, index, INT_MIN, INT_MAX);
}

// ---------------------------
// Utility: Inorder Traversal (should be sorted for BST)
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
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node* root = bstFromPreorder(preorder);

    cout << "Inorder Traversal of Constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- BST Property:
  -> Left < Node < Right for every node.
  -> Ensures unique construction from preorder.
- Preorder Property:
  -> Root comes first, then left subtree, then right subtree.
- Algorithm:
  -> Use index + valid range (min, max).
  -> Only place node if value lies in [min, max].
  -> Recursively build left & right subtrees.
- Time Complexity:
  -> O(N), each node processed once.
- Space Complexity:
  -> O(H) recursion stack (H = tree height).
  -> Balanced BST: O(log N), Skewed BST: O(N).
================================================================================
*/
