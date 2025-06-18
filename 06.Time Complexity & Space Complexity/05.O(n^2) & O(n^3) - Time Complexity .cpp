// O(n^2) --> here the time increases squared with the input size
// O(n^3) --> here the time increases cubic with the input size

// optimised with early exit

//Example:

// Bubble Sort:

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // Outer loop for the number of passes
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to optimize by checking if any swaps occurred
        
        // Inner loop to compare and swap adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        // If no swaps occurred in this pass, array is sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Check for valid input size
    if (n <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 1;
    }
    
    int* arr = new int[n]; // Dynamically allocate array
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// inner loop: Number of comparisons decreases with each
// pass (n−1,n−2, . . .  ,1).
// Outer loop: Controls how many times the inner loop runs.
// Total comparison = {n(n-1)}/2

// Worst/Average: {n(n-1)}/2 --> O(n^2) <--(dropping lower terms
//                                           and constants)

// Worst Case: O(n²) – Reverse order, maximum comparisons and swaps.
// Average Case: O(n²) – Random order, quadratic growth on average.

// Best: n-1 --> O(n)
// Best Case: O(n) – Already sorted, one pass with no swaps.

// more examples:
// selection sort
// insertion sort