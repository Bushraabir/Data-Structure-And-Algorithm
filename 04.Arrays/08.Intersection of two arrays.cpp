// This program prints the intersection of two arrays.
// It finds common elements present in both arrays using
// an unordered_set for efficient look-up.
// Only unique intersection elements are printed.

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr1[] = {1, 2, 2, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 3, 3, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    unordered_set<int> set1;
    // Insert elements from the first array into the set
    for (int i = 0; i < size1; i++) {
        set1.insert(arr1[i]);
    }

    cout << "Intersection of the two arrays: ";
    unordered_set<int> printed; // To ensure uniqueness in the output
    // Check each element of the second array for presence in set1
    for (int i = 0; i < size2; i++) {
        if (set1.find(arr2[i]) != set1.end() && printed.find(arr2[i]) == printed.end()) {
            cout << arr2[i] << " ";
            printed.insert(arr2[i]);
        }
    }
    cout << endl;

    return 0;
}
