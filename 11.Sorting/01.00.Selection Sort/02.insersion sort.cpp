/*  

Problem: Sort a list of student scores using Insertion Sort

You are given an array of student scores (integers) in a random order.
Your task is to sort these scores in ascending order using the Insertion Sort algorithm.

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

// Insertion Sort Function
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];         // Element to be inserted
        int j = i - 1;

        // Move elements greater than key one step ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;         // Insert the key at correct position
    }
}

int main() {
    // Sample problem input: Unsorted student scores
    vector<int> scores = {87, 45, 78, 32, 91, 56};

    cout << "Original scores:\n";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << "\n\n";

    // Sort using insertion sort
    insertionSort(scores);

    cout << "Sorted scores using Insertion Sort:\n";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
// Time Complexity: O(N^2) in average and worst cases
// Space Complexity: O(1) since it sorts in-place
