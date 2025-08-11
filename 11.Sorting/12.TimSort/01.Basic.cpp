/*  
Timsort is a hybrid stable sorting algorithm derived from Merge Sort and Insertion Sort.
It is the default sorting algorithm in Python and Java's Arrays.sort() for non-primitive types.
It takes advantage of runs (already sorted sequences) in real-world data to achieve excellent performance.

Working Principle:
1. Divide the array into small blocks (called "runs"), usually of size 32 or 64.
2. Sort each run individually using Insertion Sort (efficient for small arrays).
3. Merge the runs together using the same approach as Merge Sort until the whole array is sorted.
4. This hybrid approach uses the speed of Insertion Sort on small segments and the power of Merge Sort for combining.

Why it works well:
- Real-world data often contains ordered sequences.
- Detecting and merging these runs minimizes the number of operations.

Time Complexity:
    - Best Case: O(N) (when data is already sorted)
    - Average Case: O(N log N)
    - Worst Case: O(N log N)

Space Complexity:
    - O(N) (due to merging steps)

Stable Sort: Yes (Maintains the relative order of equal elements)
Adaptive: Yes (Performs faster on partially sorted data)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int RUN = 32; // Size of each small segment

// Insertion sort for small runs
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function similar to Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    vector<int> left(len1), right(len2);

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];
}

// Timsort main function
void timSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Sort small runs using Insertion Sort
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min(i + RUN - 1, n - 1));

    // Step 2: Merge runs in size powers of 2
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3, 8, 7, 2, 6};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    timSort(arr);

    cout << "Sorted array using Timsort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
Example Dry Run:
----------------
Initial array: 9 5 1 4 3 8 7 2 6
1. Divide into runs of size RUN = 32 (only one run here since size < 32)
2. Sort run using Insertion Sort
    → 1 3 4 5 8 7 2 6 9
3. Merge runs (like Merge Sort)
    → 1 2 3 4 5 6 7 8 9

Final sorted array: 1 2 3 4 5 6 7 8 9
*/
