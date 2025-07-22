/*  
This program demonstrates the bubble sort algorithm step by step.
It repeatedly compares adjacent elements and swaps them if they are in the wrong order.
After each pass, the largest element among the unsorted part is placed at the end.

Time Complexity:
    - Best Case (Already Sorted): O(N)
    - Average Case: O(N^2)
    - Worst Case (Reversely Sorted): O(N^2)

Space Complexity:
    - O(1) (In-place sorting, no extra memory used)
*/

#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort Function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Compare adjacent elements and swap if necessary
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped, the array is sorted
        if (!swapped) break;
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    bubbleSort(arr); // Sorting the array

    cout << "Sorted array using Bubble Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
