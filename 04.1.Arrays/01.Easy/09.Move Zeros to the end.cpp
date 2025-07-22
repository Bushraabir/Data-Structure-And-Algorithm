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