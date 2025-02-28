// We can reverse an array of integers in-place using the function reverseArray.
// The function uses two indices (start and end) to swap the 
// elements until the array is reversed. We are basically using the two pointers method.


#include <iostream>
using namespace std;

// Function to reverse an array in-place
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = 10;

    cout << "Initial array:\n";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    reverseArray(a, size);

    cout << "\n\nReversed array:\n";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
