/*  
Selection Sort is a simple comparison-based sorting algorithm.
It divides the array into two parts: the sorted part at the beginning, and the unsorted part at the end.
In every iteration, it selects the smallest (or largest) element from the unsorted part and places it at the beginning of the unsorted part.

Working Principle:
- Start from the first element.
- Assume it as the minimum and compare with the rest of the array.
- Find the actual minimum element in the remaining unsorted part.
- Swap it with the first element of the unsorted part.
- Repeat the process for the rest of the array.

Time Complexity:
    - Best Case: O(N^2)
    - Average Case: O(N^2)
    - Worst Case: O(N^2)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: No (Because equal elements may be swapped)
Adaptive: No (Performs the same regardless of input)
*/

#include <iostream>
#include <vector>
using namespace std;

// Selection Sort function
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume current element is minimum

        // Find the minimum element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    selectionSort(arr);

    cout << "Sorted array using Selection Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
