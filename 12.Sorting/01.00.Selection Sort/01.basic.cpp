/*
 * Selection Sort Algorithm
 *
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Intuition:
 * ----------
 * Selection Sort divides the array into two parts:
 * - The sorted part at the beginning.
 * - The unsorted part at the end.
 *
 * In every iteration:
 * - Find the smallest element in the unsorted part.
 * - Swap it with the first element of the unsorted part.
 *
 * Example (array = [29, 10, 14, 37, 13]):
 * - Pass 1: Minimum is 10 → swap with 29 → [10, 29, 14, 37, 13]
 * - Pass 2: Minimum in [29,14,37,13] is 13 → swap with 29 → [10, 13, 14, 37, 29]
 * - Pass 3: Minimum in [14,37,29] is 14 → already at correct position → [10, 13, 14, 37, 29]
 * - Pass 4: Minimum in [37,29] is 29 → swap with 37 → [10, 13, 14, 29, 37]
 * - Now array is sorted.
 *
 * At the end of i-th pass, the first i+1 elements are sorted.
 */

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Outer loop traverses all positions one by one
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index has the minimum element

        /*
         * Inner loop: Find the index of the minimum element
         * in the remaining unsorted part of the array.
         */
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        /*
         * Swap the found minimum element with the first element
         * of the unsorted part (if needed).
         */
        swap(arr[i], arr[minIndex]); // O(1) operation
    }
}

int main() {
    // Initial unsorted array
    vector<int> arr = {9, 5, 1, 4, 3};

    // Print the original array
    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    // Perform selection sort
    selectionSort(arr);

    // Print the sorted array
    cout << "Sorted array using Selection Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Selection Sort Algorithm
 *
 * Time Complexity:
 * - Best Case: O(N^2) → Even if the array is already sorted, it still scans the rest of the array to find the minimum.
 * - Average Case: O(N^2) → On average, every pass requires scanning the remaining unsorted part.
 * - Worst Case (Reversely Sorted): O(N^2)
 *
 * Space Complexity:
 * - O(1) → It is an in-place sorting algorithm; no extra space is used.
 *
 * Stability:
 * - Not stable (because it swaps elements, which may break the relative order of equal elements).
 *
 * Adaptability:
 * - Not adaptive (it always performs O(N^2) comparisons, even if the array is already sorted).
 */