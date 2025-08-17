/*  
Problem: Sort Employee Ages Using Bubble Sort

You are given a list of employee ages in an unordered format. Your task is to sort
these ages in ascending order using the Bubble Sort algorithm and understand each
pass of the algorithm as it progresses toward a sorted list.

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

// Bubble Sort Function with Pass Tracking
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        cout << "Pass " << i + 1 << ": ";

        // Compare adjacent elements and swap if needed
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Display the array after each pass
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;

        // Optimization: Stop if already sorted
        if (!swapped) break;
    }
}

int main() {
    // Problem Input: Unordered employee ages
    vector<int> employeeAges = {45, 22, 31, 27, 50, 29};

    cout << "Original Employee Ages:\n";
    for (int age : employeeAges) {
        cout << age << " ";
    }
    cout << "\n\n";

    // Sort using Bubble Sort
    bubbleSort(employeeAges);

    cout << "\nSorted Employee Ages using Bubble Sort:\n";
    for (int age : employeeAges) {
        cout << age << " ";
    }
    cout << endl;

    return 0;
}
