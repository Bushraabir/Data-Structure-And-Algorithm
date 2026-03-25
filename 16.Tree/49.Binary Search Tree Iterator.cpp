// BST Iterator
// ----------------------------------------------------------
// Problem: Design an iterator over a BST that returns elements
// in sorted (inorder) order using two functions:
//   -> next()    : Returns the next smallest element
//   -> hasNext() : Returns true if there are more elements
//
// Example:
// Inorder traversal: 3 7 9 15 20
// Calls sequence: 
// next() → 3
// next() → 7
// hasNext() → true
// next() → 9
// ...
// hasNext() → false (after 20)
//
// ----------------------------------------------------------
// Approach 1: Brute Force (O(N) space)
// ----------------------------------------------------------
// - Perform full inorder traversal in constructor.
// - Store elements in a vector.
// - Maintain index pointer.
// - next() → return arr[index++].
// - hasNext() → check index < arr.size().
// - Limitation: O(N) space (not optimal).
//
// ----------------------------------------------------------
// Approach 2: Optimal Stack-based Iterator (O(H) space)
// ----------------------------------------------------------
// - Use stack to simulate inorder traversal iteratively.
// - Constructor:
//   -> Push all left nodes from root into stack.
//   -> Top of stack = smallest element.
// - next():
//   -> Pop top of stack (that is the next smallest).
//   -> If popped node has a right child:
//        push all its left descendants into stack.
//   -> Return popped value.
// - hasNext():
//   -> Return true if stack is not empty.
// - Complexity:
//   -> Time: O(1) amortized per operation.
//   -> Space: O(H), where H = height of tree.

#include <bits/stdc++.h>
using namespace std;

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
// BST Iterator Class
// ---------------------------
class BSTIterator {
private:
    stack<Node*> st;

    // Push all left children of given node into stack
    void pushAll(Node* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    BSTIterator(Node* root) {
        pushAll(root);
    }

    // Return next smallest element
    int next() {
        Node* topNode = st.top();
        st.pop();
        if (topNode->right) {
            pushAll(topNode->right);
        }
        return topNode->data;
    }

    // Check if more elements exist
    bool hasNext() {
        return !st.empty();
    }
};

// ---------------------------
// Insert into BST (utility for testing)
// ---------------------------
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Node* root = nullptr;
    vector<int> values = {7, 3, 15, 9, 20};
    for (int v : values) root = insert(root, v);

    cout << "BST Iterator Output: ";
    BSTIterator it(root);
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Brute Force Method:
  -> Store full inorder in vector (O(N) space).
  -> Simple but not optimal.

- Optimal Method (Stack-based):
  -> Uses stack to mimic recursive inorder traversal.
  -> Push all left nodes in constructor.
  -> next(): pop stack, process right child (if exists).
  -> hasNext(): check stack emptiness.
  -> Each node pushed and popped at most once.

- Time Complexity:
  -> next() / hasNext(): O(1) amortized.
  -> Total for N operations = O(N).

- Space Complexity:
  -> O(H) stack, where H = height of BST.
  -> Balanced tree: O(log N).
  -> Skewed tree: O(N).

- Edge Cases:
  -> Empty tree → hasNext() = false.
  -> Single node → one call to next(), then hasNext() = false.
================================================================================
*/
