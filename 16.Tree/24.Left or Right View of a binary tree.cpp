#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **right side view** of a binary tree.

Definition:
- The right side view of a binary tree is the set of nodes visible when looking 
  at the tree from the right side.

Example Tree:

            1
           / \
          2   3
           \   \
            5   7
           /
          6

Right Side View Output: 1, 3, 7, 6

Left Side View Output: 1, 2, 5, 6

================================================================================
Intuition / Approach:
================================================================================
Recursive Reverse Pre-order Traversal (Root -> Right -> Left):

1. Maintain a vector DS to store nodes of the right view.
2. Recursive function parameters: node (current node), level (current depth)
3. Base Case: if node is NULL, return.
4. Check if current level is visited for the first time:
   - if(level == DS.size()) DS.push_back(node->data);
   - This ensures the first node encountered at a new level is added.
5. Recurse on right child first, then left child.

Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(H)
- Stack stores up to H nodes for recursion.
- H = height of tree
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
// Recursive Function to Find Right Side View
// ---------------------------
void rightSideViewUtil(Node* root, int level, vector<int>& view) {
    if (!root) return;

    // If this is the first node at current level
    if (level == view.size()) {
        view.push_back(root->data);
    }

    // Recurse right first to ensure rightmost nodes are visited first
    rightSideViewUtil(root->right, level + 1, view);
    rightSideViewUtil(root->left, level + 1, view);
}

vector<int> rightSideView(Node* root) {
    vector<int> view;
    rightSideViewUtil(root, 0, view);
    return view;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Example Tree:

                1
               / \
              2   3
               \   \
                5   7
               /
              6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->left->right->left = new Node(6);

    vector<int> rightView = rightSideView(root);

    cout << "Right Side View: ";
    for (int val : rightView) cout << val << " ";
    cout << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node of the tree is visited once.

Space Complexity: O(H)
- Recursion stack can go up to the height H of the tree.
- H = height of tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
================================================================================
*/
