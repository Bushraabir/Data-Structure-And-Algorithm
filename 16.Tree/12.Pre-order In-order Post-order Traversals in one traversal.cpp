#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Perform **Preorder, Inorder, and Postorder traversals** of a binary tree
in a **single traversal using one stack**.

Traversal Orders:
- Preorder:  Root -> Left -> Right
- Inorder:   Left -> Root -> Right
- Postorder: Left -> Right -> Root

Example Tree:

            1
           / \
          2   3
         / \ / \
        4  5 6  7

Expected Output:
Preorder:   1 2 4 5 3 6 7
Inorder:    4 2 5 1 6 3 7
Postorder:  4 5 2 6 7 3 1

================================================================================
Intuition / Approach:
================================================================================
1. Use a single stack to store pairs of (Node*, state):
   - state = 1 -> first visit (Preorder)
   - state = 2 -> second visit (Inorder)
   - state = 3 -> third visit (Postorder)
2. Initialize:
   a) Stack with (root, 1)
   b) Empty vectors for preorder, inorder, postorder
3. Loop while stack is not empty:
   a) Pop top node and state
   b) If state == 1:
       - Add node->data to Preorder
       - Increment state, push back (node, 2)
       - If left child exists, push (left, 1)
   c) Else if state == 2:
       - Add node->data to Inorder
       - Increment state, push back (node, 3)
       - If right child exists, push (right, 1)
   d) Else if state == 3:
       - Add node->data to Postorder
       - Node processing complete
4. This ensures all three traversals are computed in a single pass.

Time Complexity: O(N)
- Each node is pushed/popped up to 3 times.

Space Complexity: O(N)
- Stack may store up to N nodes in worst case (skewed tree)

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
// Single Traversal for Preorder, Inorder, Postorder
// ---------------------------
void allTraversalsOnePass(Node* root) {
    if (!root) return;

    vector<int> preorder, inorder, postorder;
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto &top = st.top();
        Node* node = top.first;
        int &state = top.second;

        if (state == 1) {
            preorder.push_back(node->data);
            state++;
            if (node->left) st.push({node->left, 1});
        } else if (state == 2) {
            inorder.push_back(node->data);
            state++;
            if (node->right) st.push({node->right, 1});
        } else {
            postorder.push_back(node->data);
            st.pop();
        }
    }

    cout << "Preorder: ";
    for (int val : preorder) cout << val << " ";
    cout << "\nInorder: ";
    for (int val : inorder) cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : postorder) cout << val << " ";
    cout << "\n";
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

    cout << "Traversals in One Pass:\n";
    allTraversalsOnePass(root);

    return 0;
}

/*
================================================================================
Time and Space Complexity Explanation:
================================================================================
Time Complexity: O(N)
- Each node is processed three times (for Preorder, Inorder, Postorder)
- Simplifies to O(N)

Space Complexity: O(N)
- Stack can hold up to N nodes in worst-case skewed tree
- Additional vectors store traversal results: O(N)

================================================================================
*/
