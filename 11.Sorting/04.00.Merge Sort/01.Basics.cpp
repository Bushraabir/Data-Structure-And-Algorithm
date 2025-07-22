/*  
Merge Sort is a classic divide-and-conquer algorithm. It recursively divides the array into two halves,
sorts each half, and then merges them back together in sorted order.

Working Principle:
- Divide the array into two halves.
- Recursively sort each half.
- Merge the sorted halves into a single sorted array.

Time Complexity:
    - Best Case: O(N log N)
    - Average Case: O(N log N)
    - Worst Case: O(N log N)

Space Complexity:
    - O(N) (Uses extra space for merging)

Stable Sort: Yes
Adaptive: No
*/

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort Function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

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
