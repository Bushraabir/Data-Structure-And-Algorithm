#include <iostream>
#include <list>

using namespace std;

// A function to print the contents of the list
void printList(const list<int>& l, const string& message) {
    cout << message << ": ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Declaring a list of integers
    list<int> myList;
    cout << "Initial list created." << endl;
    printList(myList, "List after declaration");

    // Adding elements to the list

    // Adds to the end of the list
    myList.push_back(10);
    myList.push_back(20);
    printList(myList, "List after push_back(10) and push_back(20)");

    // Faster than push_back for objects (constructs in place)
    myList.emplace_back(30);
    printList(myList, "List after emplace_back(30)");

    // Adds to the beginning of the list
    myList.push_front(5);
    printList(myList, "List after push_front(5)");

    // Faster than push_front for objects (constructs in place)
    myList.emplace_front(1);
    printList(myList, "List after emplace_front(1)");

    return 0;
}

/*
Arrays, vectors, and lists differ mainly in memory layout and performance.

1. Array:
   - Fixed-size, contiguous block of memory.
   - Random access is fast → O(1).
   - Insertion or deletion in the middle is costly → O(N), since elements must be shifted.

2. Vector (std::vector):
   - Dynamic array (can grow/shrink).
   - Also contiguous in memory.
   - Random access is O(1).
   - Insertions/deletions at the end are efficient → amortized O(1).
   - Insertions/deletions in the middle are costly → O(N).

3. List (std::list):
   - Implemented as a doubly linked list (non-contiguous memory).
   - Random access is slow → O(N).
   - Insertions/deletions at any position (with an iterator) are fast → O(1).

Summary:
- Use arrays when the size is fixed and you need very fast random access.
- Use vectors when you need dynamic resizing with fast random access.
- Use lists when frequent insertions or deletions in the middle are required.
*/
