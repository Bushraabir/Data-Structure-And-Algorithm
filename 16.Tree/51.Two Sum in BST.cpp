// Two Sum in BST
// ----------------------------------------------------------
// Problem: Given the root of a Binary Search Tree (BST) and an
// integer k, return true if there exist two elements in the BST
// such that their sum equals k, else return false.
//
// Example:
// Input: BST = [5,3,6,2,4,null,7], k = 9
// Output: true   (because 2 + 7 = 9)
// 
// Input: BST = [5,3,6,2,4,null,7], k = 28
// Output: false
//
// ----------------------------------------------------------
// Approach 1: Brute Force using Inorder Traversal + Two Pointers
// ----------------------------------------------------------
// - Perform inorder traversal → gives sorted array of all elements.
// - Use two-pointer approach (i = 0, j = n-1):
//     while (i < j):
//       if arr[i] + arr[j] == k → return true
//       else if arr[i] + arr[j] < k → i++
//       else j--
// - Complexity:
//     Time: O(N) for inorder + O(N) for two-pointer → O(N)
//     Space: O(N) (store inorder in vector)
//
// ----------------------------------------------------------
// Approach 2: Optimal (Two BST Iterators) - O(H) Space
// ----------------------------------------------------------
// - Idea: Avoid storing entire inorder array.
// - Simulate two-pointer method directly on BST:
//     -> Use one iterator for ascending order (inorder).
//     -> Use one iterator for descending order (reverse inorder).
// - Initialize left = smallest element, right = largest element.
// - While (left < right):
//     sum = left + right
//     if sum == k → return true
//     if sum < k → move left iterator (next bigger element)
//     if sum > k → move right iterator (next smaller element)
// - Complexity:
//     Time: O(N) (each node visited at most once)
//     Space: O(H), stack height of iterators
//
// ----------------------------------------------------------

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
    bool reverse; // false = inorder (asc), true = reverse inorder (desc)

    void pushAll(Node* node) {
        while (node) {
            st.push(node);
            node = (reverse ? node->right : node->left);
        }
    }

public:
    BSTIterator(Node* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // Return next element (smallest if inorder, largest if reverse)
    int next() {
        Node* topNode = st.top();
        st.pop();
        if (!reverse) {
            if (topNode->right) pushAll(topNode->right);
        } else {
            if (topNode->left) pushAll(topNode->left);
        }
        return topNode->data;
    }

    // Check if more elements exist
    bool hasNext() {
        return !st.empty();
    }
};

// ---------------------------
// Two Sum in BST Function
// ---------------------------
bool twoSumInBST(Node* root, int k) {
    if (!root) return false;

    BSTIterator leftIt(root, false);   // ascending
    BSTIterator rightIt(root, true);   // descending

    int i = leftIt.next();
    int j = rightIt.next();

    while (i < j) {
        int sum = i + j;
        if (sum == k) return true;
        else if (sum < k) {
            if (leftIt.hasNext()) i = leftIt.next();
            else break;
        } else {
            if (rightIt.hasNext()) j = rightIt.next();
            else break;
        }
    }
    return false;
}

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
    vector<int> values = {5,3,6,2,4,7};
    for (int v : values) root = insert(root, v);

    int k = 9;
    cout << "Does BST have two nodes with sum " << k << "? ";
    cout << (twoSumInBST(root, k) ? "Yes" : "No") << endl;

    k = 28;
    cout << "Does BST have two nodes with sum " << k << "? ";
    cout << (twoSumInBST(root, k) ? "Yes" : "No") << endl;

    return 0;
}

/*
================================================================================
Final Notes:
================================================================================
- Brute Force Method:
  -> Inorder traversal + store in array + two-pointer.
  -> Time: O(N), Space: O(N).

- Optimal Method (Two Iterators):
  -> Use two iterators (inorder + reverse inorder).
  -> Simulates two-pointer directly on BST.
  -> Time: O(N) overall, each node processed once.
  -> Space: O(H) stack, where H is tree height.

- Edge Cases:
  -> Empty tree → return false.
  -> Single node → false (need 2 distinct nodes).
  -> Target smaller than min+min or larger than max+max → false.
================================================================================
*/
