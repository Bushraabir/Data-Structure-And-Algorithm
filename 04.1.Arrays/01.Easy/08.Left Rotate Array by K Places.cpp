/*
Given an integer array nums and a non-negative integer k,
rotate the array to the left by k steps.
*/

#include <iostream>
using namespace std;

// Reverse part of the array from index 'start' to 'end'
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Rotate the array to the left by k steps
void rotateArray(int arr[], int n, int k) {
    if (n <= 1 || k == 0) return;

    k = k % n; // Handle k > n

    // Step 1: Reverse first k elements
    reverse(arr, 0, k - 1);
    // Step 2: Reverse remaining n-k elements
    reverse(arr, k, n - 1);
    // Step 3: Reverse the entire array
    reverse(arr, 0, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    rotateArray(arr, n, k);

    cout << "Array after left rotation by " << k << " steps: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
// time complexity: O(n)
// space complexity: O(1)