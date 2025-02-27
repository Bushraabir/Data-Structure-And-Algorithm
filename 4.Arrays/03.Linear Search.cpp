// Linear search is  used to find a target element in an array.
// It sequentially checks each element until the target is found
// or the array ends. If the target is found, the function returns its
// index; otherwise, it returns -1.

#include <iostream>
using namespace std;

// Function to perform linear search on an array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i; // Return the index if the target is found
    }
    return -1; // Target not found
}

int main() {
    int a[] = {5, 3, 8, 4, 2, 7};
    int size = sizeof(a) / sizeof(a[0]);          // sizeof(a)  returns the total size in bytes of the entire array a.
                                                  // sizeof(a[0]) returns the size in bytes of a single element of the array (in this case, an int).
                                                  // Dividing the total size by the size of one element gives the number of elements in the array. This is a common technique to determine the length of a statically allocated array in C++.
    int target;
    
    cout << "Enter the target value: ";
    cin >> target;
    
    int index = linearSearch(a, size, target);
    
    if(index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;
    
    return 0;
}
