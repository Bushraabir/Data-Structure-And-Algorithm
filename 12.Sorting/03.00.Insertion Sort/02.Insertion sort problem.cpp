/*  
You are given a list of exam marks scored by students in a random order. Your task is to sort
these marks in ascending order using the Insertion Sort algorithm. This problem will help
you understand how insertion sort builds the sorted array one element at a time.

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

// Insertion Sort Function with Step Display
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Display array after each pass
        cout << "After inserting element at index " << i << ": ";
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Problem Input: Unordered exam marks
    vector<int> marks = {72, 88, 43, 65, 91, 55};

    cout << "Original Exam Marks:\n";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << "\n\n";

    // Sort the marks using insertion sort
    insertionSort(marks);

    cout << "\nSorted Exam Marks using Insertion Sort:\n";
    for (int mark : marks) {
        cout << mark << " ";
    }
    cout << endl;

    return 0;
}
