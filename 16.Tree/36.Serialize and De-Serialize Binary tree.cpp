#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Serialize a binary tree into a string and then deserialize it back into the 
original tree.

Definitions:
- Serialize: Convert a binary tree into a string representation including 
  null nodes.
- Deserialize: Convert the string back to reconstruct the original tree.

================================================================================
Example:
================================================================================
Tree:

        1
       / \
      2   13
         /  \
        4    5

Serialized string (level-order): "1,2,13,#,#,4,5,#,#,#,#,"

================================================================================
Intuition / Approach:
================================================================================
1. **Serialization (Level-order)**
   - Use a queue for BFS.
   - Traverse the tree level by level.
   - Append node values to a string with a delimiter (comma or space).
   - For null nodes, append a placeholder (e.g., "#" or "n").
   - Push both left and right children into the queue, even if null.

2. **Deserialization (Level-order)**
   - Split the serialized string into values.
   - The first value becomes the root.
   - Use a queue to track parents.
   - For each parent, assign left and right children using next two values:
     - If value is a placeholder → child = null
     - Else → create new TreeNode and enqueue it.
   - Repeat until all values are processed.

--------------------------------------------------------------------------------
Optimization:
- Level-order ensures original structure is preserved including nulls.
- Using queue ensures O(N) processing.

================================================================================
Time and Space Complexity:
================================================================================
Time Complexity: O(N)
- Each node is visited exactly once for both serialize and deserialize.

Space Complexity: O(N)
- Queue stores up to O(N) nodes at one time (max width of tree).
- String stores all node values including null placeholders.
================================================================================
*/

// ---------------------------
// Definition of a Tree Node
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
// Serialize Function (Level-order)
// ---------------------------
string serialize(Node* root) {
    if (!root) return "";

    string s = "";
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (!node) {
            s += "#,";
            continue;
        }

        s += to_string(node->data) + ",";
        q.push(node->left);
        q.push(node->right);
    }
    return s;
}

// ---------------------------
// Deserialize Function (Level-order)
// ---------------------------
Node* deserialize(const string& data) {
    if (data.empty()) return nullptr;

    stringstream ss(data);
    string str;
    getline(ss, str, ','); // first value is root

    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        // Left child
        if (!getline(ss, str, ',')) break;
        if (str != "#") {
            node->left = new Node(stoi(str));
            q.push(node->left);
        }

        // Right child
        if (!getline(ss, str, ',')) break;
        if (str != "#") {
            node->right = new Node(stoi(str));
            q.push(node->right);
        }
    }
    return root;
}

// ---------------------------
// Utility: Print Inorder Traversal
// ---------------------------
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(13);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string s = serialize(root);
    cout << "Serialized Tree: " << s << endl;

    Node* newRoot = deserialize(s);
    cout << "Deserialized Tree (Inorder Traversal): ";
    printInorder(newRoot);
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Serialize + Deserialize preserves structure including null nodes.
- Level-order traversal ensures accurate reconstruction.
- BFS + queue → O(N) efficient solution.
================================================================================
*/
