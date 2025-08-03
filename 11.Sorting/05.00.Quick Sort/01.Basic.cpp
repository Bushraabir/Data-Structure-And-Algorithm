/*  
Quick Sort is a popular divide-and-conquer sorting algorithm.
It selects a "pivot" element and partitions the array such that elements less than the pivot are on the left, and elements greater than the pivot are on the right.
Then, it recursively applies the same logic to the subarrays on the left and right of the pivot.

Working Principle:
- Choose a pivot element from the array (commonly the last element).
- Rearrange the array by placing all elements smaller than the pivot to its left and all greater elements to its right (partitioning).
- Recursively apply the above steps to the left and right subarrays.
- Repeat until the entire array is sorted.

Time Complexity:
    - Best Case: O(N log N) (Balanced partitions)
    - Average Case: O(N log N)
    - Worst Case: O(N^2) (Occurs when pivot choices are poor, e.g., already sorted array with last element as pivot)

Space Complexity:
    - O(log N) (Due to recursion stack in average case)

Stable Sort: No (Because swapping may change the relative order of equal elements)
Adaptive: No (Does not take advantage of existing order in the input)
*/

#include <iostream>
#include <vector>
using namespace std;

// Partition function to place pivot at correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot after the last smaller element
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return pivot position
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array using Quick Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
