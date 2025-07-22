/*  
Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time.
It is much like sorting playing cards in your hands: you pick one card at a time and insert it into its correct position.

Working Principle:
- Start from the second element.
- Compare the current element (key) with the elements before it.
- Move elements one position ahead if they are greater than the key.
- Insert the key at its correct position.

Time Complexity:
    - Best Case (Already Sorted): O(N)
    - Average Case: O(N^2)
    - Worst Case (Reversely Sorted): O(N^2)

Space Complexity:
    - O(1) (In-place sorting)

Stable Sort: Yes
Adaptive: Yes
*/

#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort Function
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    insertionSort(arr);

    cout << "Sorted array using Insertion Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
