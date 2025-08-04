/*
 * Insertion Sort Algorithm
 *
 * Time Complexity:
 * - Best Case (Already Sorted): O(N)
 * - Average Case: O(N^2)
 * - Worst Case (Reversely Sorted): O(N^2)
 *
 * Space Complexity:
 * - O(1) → It is an in-place sorting algorithm; no extra space is used.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Intuition:
 * ----------
 * Insertion Sort works like the way you sort playing cards in your hands.
 * - You start with the second element (index 1) assuming the first element is already sorted.
 * - You pick the current element (called 'key') and compare it with all the elements to its left.
 * - If an element is greater than 'key', you shift it one position to the right.
 * - You continue this until you find the correct position for the key.
 * - Insert the key at that position.
 * - Repeat this for all elements in the array.
 *
 * The left side of the array is always sorted, and you're expanding this sorted region one element at a time.
 */

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Loop starts from 1 because the element at index 0 is already considered sorted
    for (int i = 1; i < n; i++) {
        int key = arr[i];       // Key is the element we want to insert into the sorted portion
        int j = i - 1;

        /*
         * Move elements that are greater than 'key' to one position ahead
         * of their current position to make space for 'key'.
         */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the element to the right
            j--;                 // Move to the previous element
        }

        // At this point, 'j' is at the position where arr[j] <= key (or -1 if key is smallest)
        arr[j + 1] = key;        // Insert 'key' at its correct sorted position
    }
}

int main() {
    // Initial unsorted array
    vector<int> arr = {5, 3, 4, 1, 2};

    // Print the original array
    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    // Perform insertion sort
    insertionSort(arr);

    // Print the sorted array
    cout << "Sorted array using Insertion Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
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
Adaptive: No (Performs the same regardless of the input)
*/

#include <iostream>
#include <vector>
using namespace std;

// Selection Sort Function
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current i is the index of the minimum element

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update the index if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]); // Swap function is used outside the loop just to make it more efficient 
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
