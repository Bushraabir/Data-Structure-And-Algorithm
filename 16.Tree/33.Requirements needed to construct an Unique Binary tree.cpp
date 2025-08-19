#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
Problem Statement:
================================================================================
Determine the traversal requirements needed to **uniquely construct a Binary Tree**.

Definition:
- A binary tree can be represented using different traversals:
  - Preorder: Root → Left → Right
  - Inorder: Left → Root → Right
  - Postorder: Left → Right → Root

Goal:
- Identify which traversal combinations are sufficient to uniquely reconstruct 
  a binary tree.

================================================================================
Key Insights:
================================================================================
1. Preorder + Postorder:
   - NOT sufficient to construct a unique binary tree.
   - Example:
        Preorder = [1, 2, 3]
        Postorder = [2, 3, 1]

     Two possible trees can be formed:
        Tree 1:   1
                 / \
                2   3

        Tree 2:   1
                 /
                2
               /
              3

     Hence, Preorder + Postorder → Multiple possibilities (NOT unique).

--------------------------------------------------------------------------------
2. Preorder + Inorder:
   - SUFFICIENT to uniquely construct a binary tree.
   - Reason:
       - Preorder gives root (first element).
       - Inorder splits nodes into left and right subtrees.
       - Apply recursively to build tree.

--------------------------------------------------------------------------------
3. Postorder + Inorder:
   - SUFFICIENT to uniquely construct a binary tree.
   - Reason:
       - Postorder gives root (last element).
       - Inorder splits nodes into left and right subtrees.
       - Apply recursively to build tree.

================================================================================
Summary:
================================================================================
- Preorder + Postorder → NOT unique.
- Preorder + Inorder → Unique.
- Postorder + Inorder → Unique.

Inorder traversal is **indispensable** for unique construction because it defines 
the boundary between left and right subtrees.
================================================================================
*/

// ---------------------------
// Example Demonstration
// ---------------------------

void demo() {
    // Example where Preorder + Postorder fails
    vector<int> preorder = {1, 2, 3};
    vector<int> postorder = {2, 3, 1};

    cout << "Preorder:  ";
    for (int x : preorder) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : postorder) cout << x << " ";
    cout << endl;

    cout << "\nObservation: With only Preorder and Postorder, "
         << "multiple trees are possible → NOT unique.\n";

    cout << "\nBut with Inorder added, tree can be uniquely reconstructed." << endl;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    demo();

    /*
    Valid Cases:
    - Preorder + Inorder → Unique Binary Tree
    - Postorder + Inorder → Unique Binary Tree

    Invalid Case:
    - Preorder + Postorder → Multiple trees possible → NOT unique
    */
    return 0;
}

/*
================================================================================
Final Note:
================================================================================
- Inorder is the key traversal that ensures uniqueness.
- It separates left and right subtrees once the root is known 
  (from Preorder or Postorder).
- Without Inorder, uniqueness cannot be guaranteed.
================================================================================
*/
