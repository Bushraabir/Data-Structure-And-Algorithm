#include <iostream> 
#include <list>     // To use the list container

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
    // 1️⃣ Declaring a list of integers
    list<int> myList;
    cout << "Initial list created." << endl;
    printList(myList, "List after declaration");

    // 2️⃣ Adding elements to the list

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
