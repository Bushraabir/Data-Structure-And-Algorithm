#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Construct a **unique binary tree** from given Postorder and Inorder traversals.

Definition:
- Postorder Traversal: Left → Right → Root
- Inorder Traversal : Left → Root → Right

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
Postorder = [40, 50, 20, 60, 30, 10]

================================================================================
Intuition / Approach:
================================================================================
1. Last element in Postorder is always the ROOT of the tree.
   - Example: postorder[last] = 10 → root = 10

2. Find this root in the Inorder array:
   - Elements to LEFT of root in Inorder = Left Subtree
   - Elements to RIGHT of root in Inorder = Right Subtree

3. Knowing size of left subtree → split Postorder accordingly:
   - First X nodes in postorder = left subtree
   - Next Y nodes in postorder = right subtree
   - Last node = root

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
Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                      vector<int>& postorder, int postStart, int postEnd,
                      unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;

    // Root value is last element in postorder
    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);

    // Find root in inorder
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart; // size of left subtree

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                 postorder, postStart, postStart + numsLeft - 1, inMap);

    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                  postorder, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

// ---------------------------
// Main Build Tree Function
// ---------------------------
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, inMap);
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
    vector<int> inorder   = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    Node* root = buildTree(inorder, postorder);

    cout << "Constructed Tree (Inorder Traversal): ";
    printInorder(root);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Postorder + Inorder → guarantees unique binary tree construction.
- Postorder identifies root, Inorder separates left/right subtrees.
- Recursive approach + hashmap = efficient O(N) solution.
================================================================================
*/
