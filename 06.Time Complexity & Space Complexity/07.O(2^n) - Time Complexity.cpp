// O(2^n) --> here the time increases exponentially with the input size
// poor time complexity for large inputs

//Example:

// Generating all subsets of a set

#include<iostream>
using namespace std;

void generateSubsets(int arr[], int n) {
    // Total number of subsets is 2^n
    int total = 1 << n; // 2^n using bitwise left shift
    
    // Iterate through all possible combinations (0 to 2^n - 1)
    for (int i = 0; i < total; i++) {
        cout << "{ ";
        // Check each bit of i to decide whether to include arr[j]
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // If jth bit is set, include arr[j]
                cout << arr[j] << " ";
            }
        }
        cout << "}" << endl;
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
    
    cout << "All subsets:" << endl;
    generateSubsets(arr, n);
    
    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

// here the outer loop runs 2^n times, depending on the input size n
// in running the inner loop once, it requires n time to check all bits
// and print elements. so it becomes O(2^n * n),
// here we will ignore the linear factor n. the time complexity
// is ultimately O(2^n)

// more examples:
// Recursive Fibonacci
// Traveling Salesman Problem (naive)