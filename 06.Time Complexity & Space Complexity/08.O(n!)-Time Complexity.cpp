// O(n!) --> here the time increases factorially with the input size
// extremely poor time complexity even for moderate inputs
// not so common 
//Example:

// Generating all permutations of a set

#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to generate permutations recursively
void generatePermutations(int arr[], int start, int n) {
    // Base case: if start reaches n, print the permutation
    if (start == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    
    // Recursively generate permutations by swapping elements
    for (int i = start; i < n; i++) {
        swap(arr[start], arr[i]);           // Swap current position with i
        generatePermutations(arr, start + 1, n); // Recurse for next position
        swap(arr[start], arr[i]);           // Backtrack to restore original order
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Check for valid input
    if (n <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 1;
    }

    int* arr = new int[n]; // Dynamically allocate array
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "All permutations:" << endl;
    generatePermutations(arr, 0, n);
    
    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// here the function generates n! permutations recursively
// for each level, it makes recursive calls that decrease the problem size by 1
// the total number of operations is proportional to n * (n-1) * ... * 1 = n!
// so the time complexity is ultimately O(n!)

// more examples:
// Traveling Salesman Problem (brute force with permutations)
// Solving the n-Queens problem (naive approach)