#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform an **Iterative Inorder Traversal** of a binary tree using a stack.  
In **Inorder Traversal**, nodes are visited in the order:
    Left Subtree -> Root -> Right Subtree

Instead of recursion, use an explicit stack to simulate the recursive calls.

Example Tree:

            1
           / \
          2   3
         / \ / \
        4  5 6  7

Expected Inorder Output: 4 2 5 1 6 3 7

================================================================================
Intuition / Approach:
================================================================================
1. Use a stack to simulate the recursion call stack.
2. Initialize:
    a) Empty stack to store nodes.
    b) Pointer "curr" starting at root.
3. Iterative Steps:
    a) While curr is not NULL, push curr to stack and move to left child.
    b) If curr is NULL, pop a node from stack (let’s call it temp), process it (print/add to result), then set curr = temp->right.
    c) Repeat until both curr is NULL and stack is empty.
4. This mimics the recursive traversal without using function call stack.

Time Complexity: O(N)
- Each node is pushed and popped exactly once.

Space Complexity: O(H)
- Stack can hold up to H nodes at a time, where H = height of the tree.
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
// Iterative Inorder Traversal
// LEFT -> ROOT -> RIGHT
// ---------------------------
void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        // Reach the leftmost node of current subtree
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // Process node at top of stack
        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // Move to right subtree
        curr = curr->right;
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

    cout << "Iterative Inorder Traversal of Tree: ";
    iterativeInorder(root);
    cout << "\n";

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is pushed onto the stack once and popped once.
- Each operation (push/pop/print) takes O(1) time.
- Total = O(N), where N = number of nodes.

Space Complexity: O(H)
- Stack stores nodes along the current path from root to leaf.
- H = height of the tree.
- Best case (balanced tree): O(log N)
- Worst case (skewed tree): O(N)
================================================================================
*/
