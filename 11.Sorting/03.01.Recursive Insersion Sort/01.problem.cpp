/*  
You are given a list of customer ratings for a product collected over a week.  
Your task is to sort these ratings in ascending order using Recursive Insertion Sort.  
This problem will help you understand how recursion can be used to sort data by gradually  
building a sorted sublist and inserting the current element into the correct position.

Working Principle:
- Recursively sort the first n-1 ratings.
- Insert the nth rating into its correct position in the sorted sublist.

Time Complexity:
    - Best Case (Already Sorted): O(N)
    - Average Case: O(N^2)
    - Worst Case (Reversely Sorted): O(N^2)

Space Complexity:
    - O(N) due to recursion stack

Stable Sort: Yes
Adaptive: Yes
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to insert an element into a sorted subarray
void insertIntoSorted(vector<int>& arr, int n) {
    int key = arr[n];
    int j = n - 1;

    // Move elements greater than key to one position ahead
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// Recursive Insertion Sort Function
void recursiveInsertionSort(vector<int>& arr, int n) {
    if (n <= 0) return;

    // Recursively sort first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert nth element into sorted sublist
    insertIntoSorted(arr, n);
}

int main() {
    // Customer ratings collected over a week
    vector<int> ratings = {4, 5, 3, 2, 5, 1, 4};

    cout << "Original customer ratings:\n";
    for (int rate : ratings) {
        cout << rate << " ";
    }
    cout << "\n\n";

    recursiveInsertionSort(ratings, ratings.size() - 1);

    cout << "Sorted customer ratings using Recursive Insertion Sort:\n";
    for (int rate : ratings) {
        cout << rate << " ";
    }
    cout << endl;

    return 0;
}
