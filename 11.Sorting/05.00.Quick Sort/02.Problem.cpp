/*  
Problem: Sort Student Heights Using Quick Sort

You are given a list of student heights (in centimeters) in random order.  
Your task is to sort these heights in ascending order using the Quick Sort algorithm.  
This problem will help you understand how partitioning and recursive sorting work in Quick Sort.

Working Principle:
- Choose a pivot element (commonly the last element).
- Partition the array such that elements less than pivot come before it and greater come after.
- Recursively apply quick sort to the partitions.

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
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Student heights in centimeters
    vector<int> heights = {160, 150, 170, 165, 155, 180, 175};

    cout << "Original student heights:\n";
    for (int h : heights) {
        cout << h << " ";
    }
    cout << "\n\n";

    quickSort(heights, 0, heights.size() - 1);

    cout << "Sorted student heights using Quick Sort:\n";
    for (int h : heights) {
        cout << h << " ";
    }
    cout << endl;

    return 0;
}
