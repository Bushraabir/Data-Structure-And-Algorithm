#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Find the **maximum width** of a binary tree.

Definition:
- The width of a binary tree at a given level is defined as the number of nodes 
  between the leftmost and rightmost non-null nodes at that level, 
  considering the "hypothetical" null nodes in between (as if the tree were 
  a complete binary tree).

- The maximum width is the maximum such width across all levels of the tree.

Example:

Tree:
                1
               / \
              2   3
             /     \
            4       5
           / \     / \
          6   7   8   9

Widths:
- Level 1: [1] → width = 1
- Level 2: [2, 3] → width = 2
- Level 3: [4, null, null, 5] → width = 4
- Level 4: [6, 7, 8, 9] → width = 4

Answer: Maximum width = 4

================================================================================
Intuition / Approach:
================================================================================
Approach: Level Order Traversal (BFS) with Indexed Nodes

1. Since width is a level-based property, we use **Level Order Traversal**.

2. Assign indices to nodes similar to a complete binary tree:
   - For a node at index i:
     - Left child → 2*i + 1
     - Right child → 2*i + 2

3. Problem: Direct indexing causes **overflow** for skewed trees 
   (indices grow ~2^height).

4. Solution: Use **relative indexing per level**:
   - At the start of each level, store the index of the first node = `min_index`.
   - For each node in this level, compute:
       normalized_index = current_index - min_index
   - Use `normalized_index` to compute children indices safely.

5. At each level:
   - Record the first and last indices.
   - Width = (last_index - first_index + 1).
   - Update `max_width`.

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
// Function to Find Maximum Width
// ---------------------------
int maxWidth(Node* root) {
    if (!root) return 0;

    long long max_width = 0;

    // Queue stores pair<Node*, index>
    queue<pair<Node*, long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        long long min_index = q.front().second;  // smallest index at this level
        long long first, last;

        for (int i = 0; i < size; i++) {
            auto [node, index] = q.front();
            q.pop();

            // normalize index to avoid overflow
            long long curr_index = index - min_index;

            if (i == 0) first = curr_index;
            if (i == size - 1) last = curr_index;

            if (node->left) 
                q.push({node->left, curr_index * 2 + 1});
            if (node->right) 
                q.push({node->right, curr_index * 2 + 2});
        }

        max_width = max(max_width, last - first + 1);
    }

    return (int)max_width;
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
             /     \
            4       5
           / \     / \
          6   7   8   9

        Expected Maximum Width = 4
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Maximum Width of the Tree = " << maxWidth(root) << endl;

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(N)
- Queue stores at most all nodes at the largest level (up to N/2).
================================================================================
*/
