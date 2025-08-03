/*  
Insertion Sort is a simple comparison-based sorting algorithm.
It builds the sorted array one element at a time by repeatedly taking the next element from the unsorted part and inserting it into the correct position in the sorted part.

Working Principle:
- Start from the second element (index 1).
- Compare the current element with the elements before it.
- Shift all elements that are greater than the current element one position to the right.
- Insert the current element into its correct position.
- Repeat the process for all elements.

Time Complexity:
    - Best Case: O(N) (When the array is already sorted)
    - Average Case: O(N^2)
    - Worst Case: O(N^2)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: Yes (Because equal elements do not change their relative order)
Adaptive: Yes (Faster when the array is already mostly sorted)
*/

#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort Function
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert key at correct position
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    insertionSort(arr);

    cout << "Sorted array using Insertion Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
