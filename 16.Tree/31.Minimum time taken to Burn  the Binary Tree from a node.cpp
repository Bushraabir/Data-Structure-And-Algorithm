#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Given a Binary Tree, a target node, and an integer K, print all the nodes that
are exactly at distance K from the target node.

Definition:
- Distance between two nodes = number of edges on the shortest path between them.
- Nodes at distance K can lie:
    -> in the subtree of target (downwards traversal)
    -> in ancestors or their subtrees (upwards traversal)

Example Tree:
                3
               / \
              5   1
             / \  / \
            6  2 0   8
              / \
             7   4

Target = 5, K = 2
Answer = {7, 4, 1}
================================================================================
Intuition:
================================================================================
- Moving downward from a target node is easy (using left/right pointers).
- But moving upward requires parent references.
- So we first store each node’s parent using BFS.
- Then, starting BFS from the target node, we explore in 3 directions:
      -> left child
      -> right child
      -> parent
- Continue BFS until distance K is reached.
- At that level, all nodes in the queue are exactly distance K from target.

================================================================================
Approach:
================================================================================
1. Mark parents of all nodes using BFS and store in a map.
2. Use another BFS starting from the target node:
   - Maintain a visited map to avoid revisits.
   - For each level, push left, right, and parent (if not visited).
   - Stop when we reach level K.
3. All nodes in the queue at that point are the answer.

================================================================================
Time and Space Complexity:
================================================================================
Time Complexity: O(N)
- Marking parents takes O(N).
- BFS from target takes O(N).
- Total = O(N).

Space Complexity: O(N)
- Parent map = O(N)
- Visited map = O(N)
- Queue in BFS = O(N)
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
        left = right = nullptr;
    }
};

// ---------------------------
// Step 1: Mark Parents
// ---------------------------
void markParents(Node* root, unordered_map<Node*, Node*>& parent_track) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

// ---------------------------
// Step 2: BFS from Target
// ---------------------------
vector<int> distanceK(Node* root, Node* target, int k) {
    unordered_map<Node*, Node*> parent_track;  
    markParents(root, parent_track);

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;

    int curr_level = 0;

    while (!q.empty()) {
        int size = q.size();
        if (curr_level == k) break;

        curr_level++;

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            // left child
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            // right child
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            // parent
            if (parent_track.find(current) != parent_track.end() &&
                !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);
    }
    return result;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    /*
        Constructing Example Tree:

                3
               / \
              5   1
             / \  / \
            6  2 0   8
              / \
             7   4

        Target = 5, K = 2
        Expected Output = {7, 4, 1}
    */

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* target = root->left;  // Node with value 5

    int k = 2;
    vector<int> ans = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target->data << ": ";
    for (int val : ans) cout << val << " ";
    cout << endl;

    return 0;
}
