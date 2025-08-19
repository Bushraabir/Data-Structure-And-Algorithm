#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------
🔹 Binary Tree Traversals (DFS & BFS)
------------------------------------------------------
We will implement:
1. Depth First Search (DFS)
   - Inorder (Left → Root → Right)
   - Preorder (Root → Left → Right)
   - Postorder (Left → Right → Root)

2. Breadth First Search (BFS)
   - Level Order (process level by level)

Mnemonic to remember DFS:
- Preorder  -> "Pre" means root comes first
- Postorder -> "Post" means root comes last
- Inorder   -> "In" means root comes in between
------------------------------------------------------
*/

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
------------------------------------------------------
🔹 DFS TRAVERSALS
------------------------------------------------------
They are recursive → we call function on left/right
subtrees following a particular "rule".
*/

// Inorder Traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);          // 1. Go Left
    cout << root->data << " ";    // 2. Visit Root
    inorder(root->right);         // 3. Go Right
}

// Preorder Traversal (Root → Left → Right)
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";    // 1. Visit Root
    preorder(root->left);         // 2. Go Left
    preorder(root->right);        // 3. Go Right
}

// Postorder Traversal (Left → Right → Root)
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);        // 1. Go Left
    postorder(root->right);       // 2. Go Right
    cout << root->data << " ";    // 3. Visit Root
}

/*
------------------------------------------------------
🔹 BFS (Level Order Traversal)
------------------------------------------------------
We use a queue:
1. Push root in queue
2. Pop one by one
3. Push its children back to queue
This ensures level-by-level traversal.
------------------------------------------------------
*/
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " "; // Visit node

        // Push children (left first, then right)
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }
}

/*
------------------------------------------------------
🔹 MAIN FUNCTION
------------------------------------------------------
We’ll build this tree (same as video’s first example):

            1
           / \
          2   3
         / \ / \
        4  5 6  7

Traversals should give:
- Inorder   → 4 2 5 1 6 3 7
- Preorder  → 1 2 4 5 3 6 7
- Postorder → 4 5 2 6 7 3 1
- LevelOrder→ 1 2 3 4 5 6 7
------------------------------------------------------
*/
int main() {
    // Step 1: Build the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Step 2: Print all traversals
    cout << "Inorder Traversal   (Left Root Right): ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal  (Root Left Right): ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal (Left Right Root): ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal (BFS): ";
    levelOrder(root);
    cout << endl;

    return 0;
}
