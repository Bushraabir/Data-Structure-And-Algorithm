#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **maximum path sum in a binary tree**.

Definition:
- A path is any sequence of nodes from some starting node to any node in the tree,
  where each node appears at most once.
- The path can start and end at any node (does not need to pass through root).
- Goal: Find the path with the maximum sum of node values.

Example Tree:

            10
           /  \
          2    10
         / \     \
        20  1     -25
                   / \
                  3   4

Expected Output: 42
- Maximum path sum is 20 -> 2 -> 10 -> 10 = 42

================================================================================
Intuition / Approach:
================================================================================
Optimized O(N) Recursive Approach:
1. Use a helper function that returns the maximum path sum **extending upwards** from the current node.
2. At each node:
   a) Recursively get maximum sum from left subtree (left_sum) and right subtree (right_sum)
   b) Ignore negative sums by taking max(0, left_sum) and max(0, right_sum)
   c) Potential maximum path through current node = node->val + left_sum + right_sum
   d) Update global maximum (maxi) if this is larger than current maxi
   e) Return max path sum extending to parent = node->val + max(left_sum, right_sum)
3. Final answer = global maximum after recursion completes.

Dry Run Example:
- Leaf nodes return their own value
- Intermediate nodes compute max(left_sum + node->val + right_sum) and update global maxi
- Return value to parent = node->val + max(left_sum, right_sum)
- This ensures all possible paths are considered

Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(H)
- Recursive stack stores up to H nodes
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
// Recursive Function to Find Maximum Path Sum
// ---------------------------
int maxPathSumUtil(Node* root, int &maxi) {
    if (!root) return 0;

    int left_sum = max(0, maxPathSumUtil(root->left, maxi));
    int right_sum = max(0, maxPathSumUtil(root->right, maxi));

    // Update global maximum including current node
    maxi = max(maxi, root->data + left_sum + right_sum);

    // Return max sum extending to parent
    return root->data + max(left_sum, right_sum);
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    maxPathSumUtil(root, maxi);
    return maxi;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the Binary Tree:

                10
               /  \
              2    10
             / \     \
            20  1     -25
                       / \
                      3   4
    */
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << "Maximum Path Sum of the Tree: " << maxPathSum(root) << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited once to compute sums and update global maximum.

Space Complexity: O(H)
- Stack stores up to H nodes for recursive calls
- H = height of tree
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)

================================================================================
*/
