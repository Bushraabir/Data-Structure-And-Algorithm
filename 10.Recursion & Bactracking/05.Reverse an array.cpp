/*
Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.

*/
#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start , int end){
    if (start >= end) return; // Base case: if start index is greater than or equal to end index, return
    swap(arr[start], arr[end]); // Swap the elements at start and end indices
    reverseArray(arr, start + 1, end - 1); // Recursive call with incremented start and decremented end
     
}


int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input array elements
    }

    reverseArray(arr, 0, n - 1); // Call the function to reverse the array

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output the reversed array
    }
    cout << endl;

    return 0;
}

// Time complexity: O(n/2) ≈ O(n) (Each element is swapped only once in the recursive calls)
// Space complexity: O(n) (Due to recursion stack calls; if implemented iteratively, space would be O(1))


