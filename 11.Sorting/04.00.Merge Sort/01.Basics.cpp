/*  

( divide & Merge )


Merge Sort is a classic divide-and-conquer sorting algorithm.
It divides the array into two halves, recursively sorts each half, and then merges the two sorted halves to produce the sorted array.

Working Principle:
- Divide the array into two halves until each sub-array contains a single element.
- Recursively sort the two halves.
- Merge the two sorted halves into a single sorted array.
- Repeat the process until the whole array is sorted.

Time Complexity:
    - Best Case: O(N log N)
    - Average Case: O(N log N)
    - Worst Case: O(N log N)

Space Complexity:
    - O(N) (Requires extra space for merging)

Stable Sort: Yes (Because merging maintains the relative order of equal elements)
Adaptive: No (Does not take advantage of existing order in the input)
*/

#include <iostream>
#include <vector>
using namespace std;

// Merge function to merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array using Merge Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
