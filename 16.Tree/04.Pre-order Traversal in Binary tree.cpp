#include <bits/stdc++.h>
using namespace std;

// -------------------------------
// Definition of a Node in Binary Tree
// -------------------------------
struct Node {
    int data;        // stores the value of the node
    Node* left;      // pointer to the left child
    Node* right;     // pointer to the right child
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = right = NULL; // initially no children
    }
};

// -------------------------------
// Preorder Traversal Function
// Rule: Root -> Left -> Right
// -------------------------------
void preorder(Node* root) {
    // Base Case: if the current node is NULL,
    // it means we have reached the end of a branch.
    if (root == NULL) return;

    // Step 1: Process the "Root" first (print its data)
    cout << root->data << " ";

    // Step 2: Recursively traverse the "Left Subtree"
    preorder(root->left);

    // Step 3: Recursively traverse the "Right Subtree"
    preorder(root->right);
}

// -------------------------------
// Main Function
// -------------------------------
int main() {
    /* 
        Constructing the Binary Tree for dry run:

                 1
                / \
               2   3
              / \   \
             4   5   8
                /   / \
               6   9  10
                  /
                 7

        Expected Preorder Traversal: 
        Root -> Left -> Right
        Sequence = 1 2 4 5 6 3 7 8 9 10
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(8);

    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    // Perform Preorder Traversal
    cout << "Preorder Traversal of the Binary Tree is:\n";
    preorder(root);

    return 0;
}

/*
-------------------------------
🔹 NOTES / EXPLANATION
-------------------------------
1. Preorder Traversal follows the rule:
   "Root -> Left -> Right"

2. The recursion stack works as:
   - Visit the root
   - Move left (keep going recursively)
   - When left is done, go right

3. Dry Run Example:
   For the above tree:
   Visit 1 → (root)
   Then go left → 2
   Then go left → 4
   Backtrack → go right of 2 → 5
   Then left of 5 → 6
   Backtrack fully → go right of 1 → 3
   Then left → 7
   Backtrack → right of 3 → 8
   Then left of 8 → 9
   Then right of 8 → 10

   ✅ Final Sequence: 1 2 4 5 6 3 7 8 9 10

4. Time Complexity: O(N) 
   - Each node is visited exactly once.

5. Space Complexity: O(H)
   - Due to recursion stack, where H = height of tree.
   - Worst case (skewed tree): O(N).
   - Best case (balanced tree): O(log N).
-------------------------------
*/
