#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& l, const string& message) {
    cout << message << ": ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    list<int> myList = {1, 5, 10, 20, 30};

    // Iterating using iterator
    cout << "\nIterating using iterator: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Checking properties of the list
    cout << "\nSize of the list: " << myList.size() << endl;
    cout << "Is the list empty? " << (myList.empty() ? "Yes" : "No") << endl;

    // Removing elements

    // Removes the last element (30)
    myList.pop_back();
    printList(myList, "List after pop_back()");

    // Removes the first element (1)
    myList.pop_front();
    printList(myList, "List after pop_front()");

    // Clearing the list
    myList.clear();
    printList(myList, "List after clear()");
    cout << "Is the list empty after clearing? " << (myList.empty() ? "Yes" : "No") << endl;

    return 0;
}
