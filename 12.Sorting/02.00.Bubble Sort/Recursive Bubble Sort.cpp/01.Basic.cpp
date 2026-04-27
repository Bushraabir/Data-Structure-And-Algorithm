/* 
Problem: Sort an Array Using Bubble Sort

You are given a list of elements represented as an array.  
Your task is to sort the array in ascending order using the Bubble Sort algorithm.  
This problem helps you understand one of the simplest sorting techniques where  
larger elements gradually "bubble up" to their correct positions.

Working Principle:
- Repeatedly traverse the array.
- Compare adjacent elements and swap them if they are in the wrong order.
- After each pass, the largest unsorted element moves to the end.
- Reduce the range of comparison after each iteration.
- Stop early if no swaps occur (optimization).

Time Complexity:
    - Best Case (Already Sorted): O(N)  [with optimization]
    - Average Case: O(N^2)
    - Worst Case (Reversely Sorted): O(N^2)

Space Complexity:
    - O(1) (in-place sorting)

Stable Sort: Yes
Adaptive: Yes (with swapped flag optimization)
*/

#include <iostream>
#include <vector>
using namespace std;

// Iterative Bubble Sort Function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps happened, array is already sorted
        if (!swapped) break;
    }
}

int main() {
    // Example array (e.g., product prices)
    vector<int> arr = {150, 99, 120, 75, 180, 110};

    cout << "Original array:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\n";

    bubbleSort(arr);

    cout << "Sorted array using Bubble Sort:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}