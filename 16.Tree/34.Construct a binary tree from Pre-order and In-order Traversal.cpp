#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Construct a **unique binary tree** from given Preorder and Inorder traversals.

Definition:
- Preorder Traversal: Root → Left → Right
- Inorder Traversal:  Left → Root → Right

Given these two traversals, return the root of the constructed binary tree.

================================================================================
Example:
================================================================================
Tree:

            10
           /  \
         20    30
        / \    /
      40  50  60

Inorder   = [40, 20, 50, 10, 60, 30]
Preorder  = [10, 20, 40, 50, 30, 60]

================================================================================
Intuition / Approach:
================================================================================
1. First element in Preorder is always the ROOT of the tree.
   - Example: preorder[0] = 10 → root = 10

2. Find this root in the Inorder array:
   - Elements to LEFT of root in Inorder = Left Subtree
   - Elements to RIGHT of root in Inorder = Right Subtree

3. Knowing size of left subtree → split Preorder accordingly:
   - Next X nodes in preorder = left subtree
   - Remaining nodes = right subtree

4. Recursively repeat for left and right subtrees.

--------------------------------------------------------------------------------
Optimization:
- Use a HashMap (value → index in Inorder) for O(1) lookup.
- Pass array indices instead of creating subarrays → O(1) extra space.

================================================================================
Time and Space Complexity:
================================================================================
Time Complexity: O(N)
- Each node is created once.
- Hashmap lookup = O(1).
- Total = O(N).

Space Complexity: O(N)
- Hashmap stores N values.
- Recursion stack = O(H), worst case O(N) (skewed tree).

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
// Recursive Helper Function
// ---------------------------
Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                      vector<int>& inorder, int inStart, int inEnd,
                      unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    // Root value is first element in preorder
    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);

    // Find root in inorder
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart; // size of left subtree

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);

    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// ---------------------------
// Main Build Tree Function
// ---------------------------
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

// ---------------------------
// Utility: Print Inorder Traversal
// ---------------------------
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    vector<int> inorder  = {40, 20, 50, 10, 60, 30};

    Node* root = buildTree(preorder, inorder);

    cout << "Constructed Tree (Inorder Traversal): ";
    printInorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Preorder + Inorder → guarantees unique binary tree construction.
- Preorder identifies root, Inorder separates left/right subtrees.
- Recursive approach + hashmap = efficient O(N) solution.
================================================================================
*/
