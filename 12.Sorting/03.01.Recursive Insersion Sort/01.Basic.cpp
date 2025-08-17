/*   
Recursive Insertion Sort is a variation of the classic insertion sort algorithm  
where the sorting is performed using recursion instead of iteration.

Working Principle:
- Recursively sort the first n-1 elements.
- Insert the nth element into its correct position in the sorted part.

Time Complexity:
    - Best Case (Already Sorted): O(N)
    - Average Case: O(N^2)
    - Worst Case (Reversely Sorted): O(N^2)

Space Complexity:
    - O(N) due to recursion stack

Stable Sort: Yes
Adaptive: Yes
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to insert an element at its correct position in a sorted subarray
void insertIntoSorted(vector<int>& arr, int n) {
    int key = arr[n];
    int j = n - 1;

    // Move elements greater than key one position ahead
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// Recursive Insertion Sort Function
void recursiveInsertionSort(vector<int>& arr, int n) {
    // Base case: If array has one or zero elements, it's sorted
    if (n <= 0) return;

    // Recursively sort first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert nth element into sorted subarray
    insertIntoSorted(arr, n);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    recursiveInsertionSort(arr, arr.size() - 1);

    cout << "Sorted array using Recursive Insertion Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
