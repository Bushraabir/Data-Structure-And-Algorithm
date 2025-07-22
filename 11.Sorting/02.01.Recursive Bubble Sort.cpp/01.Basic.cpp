/*  
Problem: Organize Sales Data Using Merge Sort

You are given the monthly sales figures (in thousands of dollars) of a company stored in an array.
Your task is to sort these figures in ascending order using the Merge Sort algorithm. This problem
will help you understand the divide-and-conquer strategy and recursive merging.

Working Principle:
- Divide the array into two halves.
- Recursively sort each half.
- Merge the sorted halves into a single sorted array.

Time Complexity:
    - Best Case: O(N log N)
    - Average Case: O(N log N)
    - Worst Case: O(N log N)

Space Complexity:
    - O(N) (Uses extra space for merging)

Stable Sort: Yes
Adaptive: No
*/

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort Function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    // Monthly sales figures in thousands
    vector<int> sales = {120, 95, 140, 85, 170, 110, 105};

    cout << "Original Sales Data (in thousands):\n";
    for (int val : sales) {
        cout << val << " ";
    }
    cout << "\n\n";

    mergeSort(sales, 0, sales.size() - 1);

    cout << "Sorted Sales Data using Merge Sort:\n";
    for (int val : sales) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
