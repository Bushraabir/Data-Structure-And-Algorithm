/*
    A Linked List is a **linear data structure** where each element (called a node) points to the next.
    - Unlike arrays, elements are NOT stored in contiguous memory.
    - Each node has two parts: 
        1. `data` — the actual value to store.
        2. `next` — a pointer to the next node.

    Why use Linked List over Arrays?
    - Arrays have fixed size and occupy contiguous memory.
    - Inserting or deleting elements in arrays is costly (O(n) time).
    - Linked lists allow **dynamic memory allocation** and **efficient insertions/deletions** (mostly O(1) time).

    Real-life Analogy:
    - Think of linked list nodes like train compartments — each one knows who’s next but doesn't care about exact memory address.
    - Or imagine your browser history: each page knows the next one.

    Basic Operations:
    - Convert an array to linked list
    - Traverse the list and print values
    - Find the length of the list
    - Search for an element


    - the first element is called head of the linked list and the last element is called tail of the liked list.
    - The last node's next pointer is set to `nullptr` to indicate the end of the list.
*/

#include <iostream>
using namespace std;

// Definition of a Node in the Linked List 
struct Node { //Node is the self defined data type

    int data;       // Value stored in this node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node
  
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

/*
    Both Struct and class are data user definer dqta types in C++.
    The main difference is that members of a struct are public by default, while members of a class are private by default.
*/


/*
    node is an actual object of type Node, while Node* nodePtr is a pointer to an object of type Node.
    - node.next is accessing the next pointer of the node object.
    - nodePtr->next is accessing the next pointer of the Node object that nodePtr points to.
    - The arrow operator (->) is used to access members of a class or struct through a pointer.
    - The dot operator (.) is used to access members of a class or struct through an
*/
/*
    node.next is a pointer to the next node in the linked list.
    nodePtr->next is a pointer to an object of type Node, which is the next node in the linked list.

    . is used for normal objects, while -> is used for pointers to objects.
    In this case, nodePtr is a pointer to a Node object, so we use ->
*/

// Convert an array to a linked list
Node* convertArrayToLinkedList(int arr[], int n) {
     if (n == 0) return nullptr;

    // First element becomes the head of the list
    Node* head = new Node(arr[0], nullptr);
    Node* mover = head; // Used to add more nodes (like a tail pointer)

    // Loop through remaining elements
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], nullptr);  // Create a new node
        mover->next = temp;             // Link current node to new node (link to arr[0] and arr[1]))
        mover = temp;                   // Move the tail forward (mover now points to the new node)
    }

    return head;  // Return the starting node of the list
}
/*

In C++, variables can live in two main places:

    -- Stack memory -> Automatically managed, temporary storage.

    -- Heap memory -> Manually managed, long-lived storage.



Stack memory;

Created automatically when a function runs.
Destroyed automatically when the function ends.
Fast, but short-lived.

Example:
    int x = 5; // x lives on the stack
    void func() {
        int y = 10; // y lives on the stack, destroyed when func() ends
    }

Heap memory:

Created manually using new.
Stays alive until you manually delete it.
Slower to allocate, but long-lived and flexible.

Example:
    Node* node = new Node(5); // node lives on the heap
    delete node; //  must delete it to free memory


    
    ***When you create a linked list node inside a function, you want it to still exist after the function ends.
        If you store it in the stack, it will be destroyed immediately when the function returns.

*/

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert array to linked list
    Node* head = convertArrayToLinkedList(arr, n);
    cout << "Linked List created from array.\n";

    return 0;
}


// Note: Remember to free the allocated memory for nodes in a real application to avoid memory leaks.
// This can be done by implementing a function to delete the linked list nodes after use.
