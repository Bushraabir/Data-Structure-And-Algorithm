#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform an **anti-clockwise boundary traversal** of a binary tree.

Definition:
- Boundary traversal includes nodes along:
  1. Left boundary (excluding leaves)
  2. All leaf nodes (left to right)
  3. Right boundary in reverse (excluding leaves)
- Start traversal from root node.

Example Tree:

            1
           / \
          2   7
         / \   \
        3   4   8
       /         \
      5           9
                   \
                   10

Expected Output: 1 2 3 5 4 10 9 8 7
- Left boundary: 1 2 3
- Leaves: 5 4 10
- Right boundary reversed: 9 8 7

================================================================================
Intuition / Approach:
================================================================================
Iterative + Recursive Approach:
1. Include the root node if it's not a leaf.
2. Left Boundary Traversal (excluding leaves):
   - Start from root->left
   - Move down preferring left child, then right
   - Add nodes that are not leaves to result
3. Leaf Nodes Traversal:
   - Use in-order traversal of entire tree
   - Add nodes with no left/right children to result
4. Right Boundary Traversal (excluding leaves):
   - Start from root->right
   - Move down preferring right child, then left
   - Add nodes that are not leaves to a temporary list
   - Reverse temporary list and append to result
5. Return result vector containing anti-clockwise boundary

Time Complexity: O(N)
- Each node visited at most a few times.

Space Complexity: O(N)
- Result vector stores all N node values
- Recursion stack can go up to O(H) for leaf traversal

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
// Helper Function to Check Leaf Node
// ---------------------------
bool isLeaf(Node* node) {
    return !node->left && !node->right;
}

// ---------------------------
// Left Boundary (excluding leaves)
// ---------------------------
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) res.push_back(curr->data);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// ---------------------------
// Leaf Nodes Traversal (in-order)
// ---------------------------
void addLeaves(Node* root, vector<int>& res) {
    if (!root) return;
    addLeaves(root->left, res);
    if (isLeaf(root)) res.push_back(root->data);
    addLeaves(root->right, res);
}

// ---------------------------
// Right Boundary (excluding leaves, reversed)
// ---------------------------
void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr)) temp.push_back(curr->data);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

// ---------------------------
// Boundary Traversal Function
// ---------------------------
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    if (!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Binary Tree:

                1
               / \
              2   7
             / \   \
            3   4   8
           /         \
          5           9
                       \
                       10
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->left->left = new Node(5);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);

    vector<int> traversal = boundaryTraversal(root);

    cout << "Boundary Traversal (Anti-Clockwise): ";
    for (int val : traversal)
        cout << val << " ";
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node visited at most a few times (left boundary, leaves, right boundary).

Space Complexity: O(N)
- Result stores all N node values
- Recursion stack can go up to O(H)
- Worst case skewed tree: O(N)
- Balanced tree: O(log N)

================================================================================
*/
