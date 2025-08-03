/*  
Bubble Sort is a simple comparison-based sorting algorithm.
It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
This process is repeated until the list is sorted.

Working Principle:
- Start from the beginning of the array.
- Compare each pair of adjacent elements.
- Swap them if the first element is greater than the second.
- After each pass, the largest element "bubbles up" to its correct position at the end.
- Repeat the process for the remaining unsorted part.

Time Complexity:
    - Best Case: O(N) (When the array is already sorted, using an optimized version)
    - Average Case: O(N^2)
    - Worst Case: O(N^2)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: Yes (Because equal elements are not swapped unnecessarily)
Adaptive: Yes (If no swaps occur in a pass, the array is already sorted)
*/

#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort Function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Last i elements are already sorted
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    bubbleSort(arr);

    cout << "Sorted array using Bubble Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
/*  
Bubble Sort is a simple comparison-based sorting algorithm.
It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
This process is repeated until the list is sorted.

Working Principle:
- Start from the beginning of the array.
- Compare each pair of adjacent elements.
- Swap them if the first element is greater than the second.
- After each pass, the largest element "bubbles up" to its correct position at the end.
- Repeat the process for the remaining unsorted part.

Time Complexity:
    - Best Case: O(N) (When the array is already sorted, using an optimized version)
    - Average Case: O(N^2)
    - Worst Case: O(N^2)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: Yes (Because equal elements are not swapped unnecessarily)
Adaptive: Yes (If no swaps occur in a pass, the array is already sorted)
*/

#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort Function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Last i elements are already sorted
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    bubbleSort(arr);

    cout << "Sorted array using Bubble Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
