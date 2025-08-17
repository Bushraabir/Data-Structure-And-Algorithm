/*  
Counting Sort is a non-comparison based sorting algorithm suitable for sorting integers within a known, small range.
It counts the occurrences of each element and uses this information to place elements directly into the sorted output array.

Working Principle:
- Find the maximum value in the input array.
- Create a count array of size (max_value + 1) initialized to zero.
- Count the occurrences of each element in the input array.
- Modify the count array by adding the previous counts (prefix sums) to determine the positions of elements.
- Build the output array by placing elements at their correct positions using the count array.
- Copy the sorted elements back to the original array.

Time Complexity:
    - Best Case: O(N + K)
    - Average Case: O(N + K)
    - Worst Case: O(N + K)
  (Where N is number of elements and K is the range of input)

Space Complexity:
    - O(N + K) (For output and count arrays)

Stable Sort: Yes (Preserves the relative order of equal elements)
Adaptive: No (Performs the same regardless of input order)
*/

#include <iostream>
#include <vector>
using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    // Find the maximum value in arr
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Create count array and initialize with 0
    vector<int> count(maxVal + 1, 0);

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Change count[i] so that count[i] contains actual position of this element in output array
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    vector<int> output(n);

    // Build the output array by placing elements at their correct positions
    // Traverse the original array from the end to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    countingSort(arr);

    cout << "Sorted array using Counting Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
