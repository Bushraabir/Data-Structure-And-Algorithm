#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the path from the root of a binary tree to a given target node.

Definition:
- Given a binary tree and a target value, return the path (sequence of nodes) 
  from the root node to the target node.

Example:

Tree:
            1
           / \
          2   3
         / \
        4   5
             \
              7

Target = 7
Output Path: 1 -> 2 -> 5 -> 7

================================================================================
Intuition / Approach:
================================================================================
Recursive DFS with Backtracking:

1. Start from the root node and use recursion to traverse the tree.
2. Maintain a path vector passed by reference to store the current path.
3. At each node:
   - Add the current node's value to the path.
   - If the current node == target, return true (path found).
   - Otherwise, recursively search in the left and right subtrees.
   - If either returns true, propagate true upwards.
   - If both return false:
       - Remove the current node from path (backtracking).
       - Return false.
4. When recursion finishes, the path vector will contain the path from root 
   to the target node if it exists.

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
// Recursive Function to Get Path
// ---------------------------
bool getPath(Node* root, vector<int>& path, int target) {
    if (!root) return false;

    // Step 1: Add current node to path
    path.push_back(root->data);

    // Step 2: If target found, return true
    if (root->data == target) return true;

    // Step 3: Search left and right subtrees
    if (getPath(root->left, path, target) || getPath(root->right, path, target))
        return true;

    // Step 4: Backtracking - remove if not in path
    path.pop_back();
    return false;
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
             / \
            4   5
                 \
                  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(7);

    int target = 7;
    vector<int> path;

    if (getPath(root, path, target)) {
        cout << "Path from root to node " << target << ": ";
        for (int val : path) cout << val << " ";
        cout << endl;
    } else {
        cout << "Target node not found in the tree." << endl;
    }

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited at most once until the target is found.

Space Complexity: O(H)
- Path vector stores up to H nodes (height of tree).
- Recursive stack also stores up to H nodes.
- Best case (balanced tree): O(log N)
- Worst case (skewed tree): O(N)
================================================================================
*/
