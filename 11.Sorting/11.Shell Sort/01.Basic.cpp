/*  
Shell Sort is an in-place comparison-based sorting algorithm that generalizes Insertion Sort.
It allows the exchange of far-apart elements to move them closer to their final position faster.

Working Principle:
- Choose an initial large gap (usually n/2), then keep reducing the gap by a certain sequence (e.g., gap /= 2) until it becomes 1.
- For each gap, perform a "gapped" insertion sort:
    - Compare elements that are 'gap' distance apart.
    - Swap if needed, moving elements closer to their correct position.
- As the gap reduces, the list becomes more and more sorted.
- Finally, when gap = 1, a standard insertion sort is performed on an almost-sorted array, making it efficient.

Time Complexity:
    - Best Case: O(N log N) (depends on gap sequence)
    - Average Case: O(N^(3/2)) or better (depends on gap sequence)
    - Worst Case: O(N^2) (with simple gap sequence like N/2, N/4, ...)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: No (Because elements may be swapped far apart, changing relative order)
Adaptive: Yes (Performs better on partially sorted data compared to regular Insertion Sort)
*/

#include <iostream>
#include <vector>
using namespace std;

// Shell Sort function
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Store current element
            int j = i;

            // Shift earlier gap-sorted elements until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place temp at its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    shellSort(arr);

    cout << "Sorted array using Shell Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
Example Dry Run:
----------------
Initial array: 9 5 1 4 3
Gap = 2:
    Compare and sort elements 2 apart
    → 1 4 9 5 3
Gap = 1:
    Standard insertion sort
    → 1 3 4 5 9

Final sorted array: 1 3 4 5 9
*/
