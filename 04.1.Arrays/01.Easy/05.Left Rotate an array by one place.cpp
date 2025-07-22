/*
Left Rotate an array by one place.
*/

#include <iostream>
using namespace std;

void leftRotateByOne(int arr[], int n) {
    if (n <= 1) return; // No need to rotate if array has 0 or 1 element

    int first = arr[0]; // Store the first element
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[n - 1] = first; // Place the first element at the end
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    leftRotateByOne(arr, n);

    cout << "Array after left rotation by one: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// time complexity: O(n)
// space complexity: O(1)