#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform an **Iterative Postorder Traversal** of a binary tree using **one stack**.  
In **Postorder Traversal**, nodes are visited in the order:
    Left Subtree -> Right Subtree -> Root

Instead of recursion, use a single stack to simulate the recursive traversal order.

Example Tree:

            1
           / \
          2   3
         / \ / \
        4  5 6  7

Expected Postorder Output: 4 5 2 6 7 3 1

================================================================================
Intuition / Approach:
================================================================================
1. Use a single stack to track nodes.
2. Initialize:
    a) curr pointer at root.
    b) Empty stack to store nodes.
    c) lastVisited pointer to track last processed node.
3. Iterative Steps:
    a) Traverse left as far as possible, pushing nodes onto the stack.
    b) Peek top of stack:
        - If right child exists and was not last visited, move curr to right child.
        - Otherwise, pop from stack, process node, and update lastVisited.
    c) Repeat until stack is empty and curr is NULL.
4. This ensures each node is processed only after both its left and right children.

Time Complexity: O(N)
- Each node is pushed and popped at most twice.

Space Complexity: O(H)
- Stack stores nodes along the path from root to leaf.
- Worst case (skewed tree): O(N)

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
// Iterative Postorder Traversal Using 1 Stack
// LEFT -> RIGHT -> ROOT
// ---------------------------
void iterativePostorderOneStack(Node* root) {
    if (!root) return;

    stack<Node*> st;
    Node* curr = root;
    Node* lastVisited = nullptr;

    while (curr != nullptr || !st.empty()) {
        // Traverse left subtree
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        Node* topNode = st.top();
        // If right child exists and not yet visited, move to right child
        if (topNode->right != nullptr && lastVisited != topNode->right) {
            curr = topNode->right;
        } else {
            // Process node
            cout << topNode->data << " ";
            lastVisited = topNode;
            st.pop();
        }
    }
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing the Binary Tree:

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

    cout << "Iterative Postorder Traversal (1 Stack) of Tree: ";
    iterativePostorderOneStack(root);
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is visited, pushed, and popped at most twice.
- Total operations = O(N).

Space Complexity: O(H)
- Stack stores nodes along current path from root to leaf.
- H = height of tree.
- Best case (balanced tree): O(log N)
- Worst case (skewed tree): O(N)

================================================================================
*/
