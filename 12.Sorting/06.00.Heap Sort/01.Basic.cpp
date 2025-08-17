/*  
Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.
It first builds a max heap from the array, then repeatedly extracts the maximum element from the heap and places it at the end of the array, reducing the heap size each time.

Working Principle:
- Build a max heap from the input array.
- The largest element is now at the root of the heap.
- Swap the root with the last element of the heap.
- Reduce the heap size by one and heapify the root element to maintain the max heap property.
- Repeat the above steps until the heap size is reduced to 1.

Time Complexity:
    - Best Case: O(N log N)
    - Average Case: O(N log N)
    - Worst Case: O(N log N)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: No (Because heap operations can change the relative order of equal elements)
Adaptive: No (Performs the same regardless of input order)
*/

#include <iostream>
#include <vector>
using namespace std;

// Heapify function to maintain max heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    heapSort(arr);

    cout << "Sorted array using Heap Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
