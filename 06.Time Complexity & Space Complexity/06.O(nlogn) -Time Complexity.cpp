// O(n^2) --> here the time increases squared with the input size
// O(n log n) --> here the time increases linearly multiplied by the logarithm of the input size

// not optimised

// Example:
// Merge Sort:

#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        mergeSort(arr, left, mid);           // Sort left half
        mergeSort(arr, mid + 1, right);      // Sort right half
        merge(arr, left, mid, right);        // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

// Inner process: The merge function combines two sorted subarrays in O(n) time.
// Outer process: The array is recursively divided into halves log n times.
// Total comparison = n * log n

// Worst/Average: n * log n --> O(n log n) <--(dropping lower terms
//                                             and constants)

// Worst Case: O(n log n) – Reverse order, consistent division and merging.
// Average Case: O(n log n) – Random order, same division and merging process.

// Best: n * log n --> O(n log n)
// Best Case: O(n log n) – Already sorted, still requires full division and merging.

// more examples:
// Quick Sort (average case)
// Heap Sort