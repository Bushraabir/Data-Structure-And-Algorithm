/*   
Quick Sort is a highly efficient sorting algorithm based on the divide-and-conquer principle.  
It picks an element as pivot and partitions the array around the pivot, such that elements smaller  
than the pivot come before it and elements greater come after it. This process is recursively applied  
to the subarrays formed by partitioning.

Working Principle:
- Choose a pivot element (commonly the last element).
- Partition the array so that elements less than pivot are on the left, greater on the right.
- Recursively apply quick sort to left and right subarrays.

Time Complexity:
    - Best Case: O(N log N)
    - Average Case: O(N log N)
    - Worst Case (already sorted or all equal): O(N^2)

Space Complexity:
    - O(log N) due to recursion stack (in-place partitioning)

Stable Sort: No  
Adaptive: No  
*/

#include <iostream>
#include <vector>
using namespace std;

// Partition function using Lomuto partition scheme
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // pivot element
    int i = low - 1;        // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  // place pivot at correct position
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

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
