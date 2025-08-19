#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------
🔹 Binary Tree Representation in C++
------------------------------------------------------
Core building block = Node

Each Node has:
1. int data    -> value stored in the node
2. Node* left  -> pointer to left child
3. Node* right -> pointer to right child

⚡ If a child does not exist, its pointer = NULL.
This NULL marks the "end" of a branch.

Example (Tree we will build):

            1   <- root
           / \
          2   3
         / \
        4   5

Explanation:
- Root has value 1
- Left child of root = 2
- Right child of root = 3
- Node 2 has two children: 4 (left), 5 (right)
- Nodes 3, 4, 5 have no children → their pointers = NULL
------------------------------------------------------
*/

// Definition of a Node
struct Node {
    int data;       // Value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor: initializes data, sets children to NULL
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
------------------------------------------------------
🔹 Building the Tree
------------------------------------------------------
We use pointers and the "new" keyword to create nodes.

Step 1: Node* root = new Node(1);
        -> creates root with value 1

Step 2: root->left = new Node(2);
        root->right = new Node(3);

Step 3: root->left->left = new Node(4);
        root->left->right = new Node(5);
------------------------------------------------------
*/

// A simple Preorder Traversal (Root → Left → Right)
// just to verify that the tree was built correctly.
void preorder(Node* root) {
    if (root == NULL) return; // base case
    cout << root->data << " "; // print root
    preorder(root->left);      // go left
    preorder(root->right);     // go right
}

int main() {
    // Step 1: Create Root
    Node* root = new Node(1);

    // Step 2: Create children of root
    root->left = new Node(2);
    root->right = new Node(3);

    // Step 3: Create children of node 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Preorder Traversal Output should be: 1 2 4 5 3
    cout << "Preorder Traversal of Tree: ";
    preorder(root);

    return 0;
}
