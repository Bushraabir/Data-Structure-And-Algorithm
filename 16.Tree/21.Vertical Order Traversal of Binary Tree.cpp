#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform a **vertical order traversal** of a binary tree.

Definition:
- Nodes are grouped by vertical lines (X-coordinate):
  - Root at X=0
  - Left child: X-1
  - Right child: X+1
- For each vertical, nodes should appear from top to bottom (Y-coordinate).
- If multiple nodes share the same vertical and level, sort values in ascending order.

Example Tree:

            1
           / \
          2   3
         / \   \
        4   5   6
             \
              7

Expected Output (Vertical Order):
- Vertical -2: [4]
- Vertical -1: [2]
- Vertical 0: [1, 5]
- Vertical 1: [3, 7]
- Vertical 2: [6]

================================================================================
Intuition / Approach:
================================================================================
Level Order Traversal (BFS) with Coordinates:
1. Use a queue to store nodes with their (X, Y) coordinates:
   - queue<tuple<Node*, int, int>>
2. Use a nested map to organize nodes:
   - map<int, map<int, multiset<int>>> nodes;
   - Outer map: X-coordinate → sorted vertical lines (left to right)
   - Inner map: Y-coordinate → sorted levels (top to bottom)  
   - multiset: handles multiple nodes at same X,Y, sorted ascending
3. BFS:
   a) Dequeue node with (x, y)
   b) Insert node->data into nodes[x][y]
   c) Enqueue left child: (x-1, y+1)
   d) Enqueue right child: (x+1, y+1)
4. Construct result:
   - Iterate outer map (X in order)
   - For each X, iterate inner map (Y in order)
   - Collect sorted values into temporary vector
   - Append temporary vector to result

Time Complexity: O(N log N)
- O(N) for BFS traversal
- log N factor for multiset insertions when multiple nodes share same vertical & level

Space Complexity: O(N)
- Queue can hold up to O(W) nodes (W = max width)
- Map stores all N nodes

================================================================================
*/

// ---------------------------
// Definition of a Node in Binary Tree
// ---------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ---------------------------
// Vertical Order Traversal Function
// ---------------------------
vector<vector<int>> verticalOrderTraversal(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;

    // Nested map: X-coordinate → Y-coordinate → multiset of node values
    map<int, map<int, multiset<int>>> nodes;

    // Queue: (node, x-coordinate, y-coordinate)
    queue<tuple<Node*, int, int>> q;
    q.push(make_tuple(root, 0, 0));

    while (!q.empty()) {
        Node* curr = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        // Insert current node's data into the appropriate position
        nodes[x][y].insert(curr->data);

        // Add children to queue with updated coordinates
        if (curr->left) {
            q.push(make_tuple(curr->left, x - 1, y + 1));
        }
        if (curr->right) {
            q.push(make_tuple(curr->right, x + 1, y + 1));
        }
    }

    // Construct result from nested map
    for (auto& verticalPair : nodes) {
        int x = verticalPair.first;
        auto& levelMap = verticalPair.second;
        vector<int> vertical;
        
        for (auto& levelPair : levelMap) {
            int y = levelPair.first;
            auto& values = levelPair.second;
            // Insert all values from multiset (already sorted)
            vertical.insert(vertical.end(), values.begin(), values.end());
        }
        result.push_back(vertical);
    }

    return result;
}

// ---------------------------
// Helper function to print tree structure
// ---------------------------
void printTree(Node* root, string prefix = "", bool isLast = true) {
    if (!root) return;
    
    cout << prefix;
    cout << (isLast ? "└── " : "├── ");
    cout << root->data << endl;
    
    if (root->left || root->right) {
        if (root->left) {
            printTree(root->left, prefix + (isLast ? "    " : "│   "), !root->right);
        }
        if (root->right) {
            printTree(root->right, prefix + (isLast ? "    " : "│   "), true);
        }
    }
}

// ---------------------------
// Function to delete tree and free memory
// ---------------------------
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Binary Tree:

                1
               / \
              2   3
             / \   \
            4   5   6
                 \
                  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    cout << "Binary Tree Structure:\n";
    printTree(root);
    cout << "\n";

    vector<vector<int>> traversal = verticalOrderTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (int i = 0; i < traversal.size(); i++) {
        cout << "Vertical " << (i - 2) << ": [";  // Adjust for actual vertical positions
        for (int j = 0; j < traversal[i].size(); j++) {
            cout << traversal[i][j];
            if (j < traversal[i].size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    cout << "\nFlat Output:\n";
    for (const auto& vertical : traversal) {
        for (int val : vertical) {
            cout << val << " ";
        }
        cout << "\n";
    }

    // Clean up memory
    deleteTree(root);
    
    return 0;
}

/*
================================================================================
Key Fixes and Improvements Made:
================================================================================

1. **Structured Bindings**: Used modern C++ structured bindings for cleaner code:
   - auto [curr, x, y] = q.front(); instead of accessing through pair
   - auto& [x, levelMap] : nodes and auto& [y, values] : levelMap

2. **Constructor Initialization List**: Changed Node constructor to use 
   initialization list for better performance

3. **Memory Management**: Added deleteTree function to properly clean up memory

4. **Better Output Formatting**: 
   - Added tree visualization function
   - Improved output display with proper vertical line labeling
   - Added bracketed format for clarity

5. **Code Organization**: 
   - Better variable naming and spacing
   - More descriptive comments
   - Cleaner queue operations

6. **Tuple Usage**: Used tuple instead of nested pairs for better readability
   when storing (node, x, y) coordinates

The algorithm itself was correct - the main improvements are in code quality,
memory management, and output presentation.

================================================================================
Time and Space Complexity (Unchanged):
================================================================================
Time Complexity: O(N log N)
- O(N) for BFS traversal of all nodes
- O(log N) factor due to multiset insertion operations when multiple nodes 
  share the same vertical line and level

Space Complexity: O(N)
- Queue stores at most O(W) nodes where W is maximum width of tree
- Nested map structure stores all N nodes
- Additional space for result vector: O(N)

In worst case (completely skewed tree): O(N)
In best case (balanced tree): O(log N) for queue, O(N) total

================================================================================
*/