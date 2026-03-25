/*
Given an integer array nums, move all the 0's to the end of the array.
The relative order of the other elements must remain the same.
*/

#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int j = 0; // Pointer for the position of non-zero elements

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j++] = arr[i]; // Move non-zero element to the front
        }
    }

    // Fill the remaining positions with zeroes
    while (j < n) {
        arr[j++] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 4, 0, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    moveZeroes(arr, n);

    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
// time complexity: O(n)
// space complexity: O(1)



/*


Intuition:
    Instead of swapping elements many times, we use a two-pointer idea.

    Think of the array as having two regions:
        1. The front part where we will store all non-zero elements.
        2. The remaining part where zeroes will eventually go.

    Steps:
        1. Traverse the array once.
        2. Every time we see a non-zero element, place it at the current
           position of pointer 'j' (which tracks the next free spot for
            non-zero elements).
        3. Increment 'j' after placing the element.

            After this traversal:
                - All non-zero elements are compacted at the beginning.
                - Their relative order is preserved.
                - 'j' points to the first index where a zero should be placed.

        4. Fill the rest of the array (from j to n-1) with zeroes.

    Key idea:
        We do not move zeroes explicitly.  
        We only move non-zero elements forward and then fill the rest with zeros.


*/