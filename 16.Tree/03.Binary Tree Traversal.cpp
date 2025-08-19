#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Implement **all common traversals** of a binary tree:  
1. Depth First Search (DFS) – recursive:
   - Inorder  (Left → Root → Right)
   - Preorder (Root → Left → Right)
   - Postorder (Left → Right → Root)

2. Breadth First Search (BFS):
   - Level Order Traversal (process nodes level by level)

Given a binary tree, print or return the nodes according to the traversal rules.

Example Tree:

            1
           / \
          2   3
         / \ / \
        4  5 6  7

Expected Traversal Outputs:
- Inorder   → 4 2 5 1 6 3 7
- Preorder  → 1 2 4 5 3 6 7
- Postorder → 4 5 2 6 7 3 1
- LevelOrder→ 1 2 3 4 5 6 7

================================================================================
Intuition / Approach:
================================================================================
1. DFS Traversals (recursive):
   - Inorder:  Left → Root → Right
   - Preorder: Root → Left → Right
   - Postorder: Left → Right → Root
   Use recursion to traverse the tree following these orders.
   
2. BFS Traversal (Level Order):
   - Use a queue to process nodes level by level (FIFO).
   - Push root first, then pop nodes one by one and enqueue their children.

Time Complexity (DFS & BFS): O(N)
- Each node is visited exactly once.

Space Complexity:
- DFS (recursion stack): O(H) where H = height of tree
    - Best case (balanced): O(log N)
    - Worst case (skewed): O(N)
- BFS (queue): O(N) in worst case for last level of the tree
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
        left = right = NULL;
    }
};

// ---------------------------
// DFS Traversals
// ---------------------------

// Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ---------------------------
// BFS Traversal (Level Order)
// ---------------------------
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the following Binary Tree:

            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal   (Left Root Right): ";
    inorder(root); 
    cout << "\n";

    cout << "Preorder Traversal  (Root Left Right): ";
    preorder(root); 
    cout << "\n";

    cout << "Postorder Traversal (Left Right Root): ";
    postorder(root); 
    cout << "\n";

    cout << "Level Order Traversal (BFS): ";
    levelOrder(root);
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
DFS (Inorder, Preorder, Postorder):
- Time Complexity: O(N)
  - Each node is visited exactly once.
- Space Complexity: O(H)
  - Recursion stack holds nodes along current path from root to leaf.
  - Best case (balanced tree): O(log N)
  - Worst case (skewed tree): O(N)

BFS (Level Order):
- Time Complexity: O(N)
  - Each node is visited exactly once.
- Space Complexity: O(N)
  - Queue may hold up to the number of nodes at the largest level (worst case).
================================================================================
*/
