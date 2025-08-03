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
        mover->next = temp;             // Link current node to new node
        mover = temp;                   // Move the tail forward
    }

    return head;  // Return the starting node of the list
}

// Traverse the list and print each node’s value
void traverseLinkedList(Node* head) {
    cout << "Traversing Linked List: ";
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";  // Marks the end of the list
}

// Count the number of nodes in the linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Search for a value in the linked list
bool searchElement(Node* head, int target) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == target) {
            return true;  // Found the target
        }
        temp = temp->next;
    }

    return false;  // Target not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert array to linked list
    Node* head = convertArrayToLinkedList(arr, n);
    cout << "Linked List created from array.\n";

    // Traverse and display the list
    traverseLinkedList(head);

    // Print the length of the list
    cout << "Length of Linked List: " << getLength(head) << endl;

    // Search for a few elements
    int searchVal = 30;
    cout << "Is " << searchVal << " in the list? " << (searchElement(head, searchVal) ? "Yes" : "No") << endl;

    searchVal = 100;
    cout << "Is " << searchVal << " in the list? " << (searchElement(head, searchVal) ? "Yes" : "No") << endl;

    return 0;
}


// Note: Remember to free the allocated memory for nodes in a real application to avoid memory leaks.
// This can be done by implementing a function to delete the linked list nodes after use.
