// Space complexity indicates how the memory usage of an algorithm increases
// as the size of the input data increases. It is an indicator to predict the 
// memory performance and to compare different approaches to solving the same problem.
// Space complexity is expressed using Big O Notation, which describes the upper
// bound of the algorithm's memory usage in the worst-case scenario. It focuses
// on the dominant term that grows the fastest as the input size increases and
// ignores the lower-order terms and constants for simplicity.


// Some common space complexities:

// O(1) --> Constant Space
//      --> uses a fixed amount of memory, regardless of input size
//      --> e.g. Swapping two variables using a single temporary variable
//      --> Highly efficient, as memory usage remains constant even for
//          large inputs


// O(log n) --> Logarithmic Space
//          --> Memory usage grows logarithmically as the input size
//              increases often due to recursive division of the problem.
//          --> e.g. Binary search with recursion, where the recursion
//              stack depth is log n
//          --> Efficient for large inputs, with slow memory growth


// O(n) --> Linear Space
//      --> Memory usage grows linearly with the input size
//      --> e.g. Storing an array of size n
//      --> Acceptable when memory is not a major constraint.



// O(n log n) --> Linearithmic Space
//            --> Memory usage grows proportional to nlogn, 
//            --> often in sorting or divide-and-conquer algorithms.
//            --> e.g. Merge sort requiring extra space for merging
//                arrays
//            --> Common in algorithms balancing time and space efficiency


// O(n^2) --> Quadratic Space
//        --> Memory usage grows with the square of the input size
//        --> typically due to 2D data structures
//        --> e.g.Sorting an nxn matrix
//        --> Can become impractical for large inputs due to rapid memory
//            growth



// O(2^n) --> Exponential Space
//        --> Memory usage doubles with each additional input element
//        --> e.g. Generating all subsets of a set recursively.
//        --> Highly inefficient for large inputs



// Calculation of Time Complexity: ( Using Big O Notation )
// Big O notation simplifies the analysis of algorithms by focusing on
// the term that grows the fastest as the input size increases.
// e.g. if an algorithm's running time is 3n^2 + 2n + 1 bytes of memory;
// then the space complexity will be O(n^2) as n^2 term dominates for
// large n.This approach allows us to compare algorithms based on how
// their memory needs scale, ignoring constants and lower-order terms.




// Types of Space Complexity:

// Auxiliary Space Complexity:       The extra memory used by the 
// algorithm,excluding the input itself. For example, an in-place sorting
// algorithm might have O(1) auxiliary space.

// Total Space Complexity: The sum of auxiliary space and the input space.
// For instance, an algorithm processing an array of size n might have
// O(n) total space complexity even if its auxiliary space is O(1).



// Worst-Case Space Complexity:
// This is the maximum memory an algorithm will use for any input of size 
// n. It’s the most commonly analyzed measure because it provides an
// upper-bound guarantee on memory usage, ensuring the algorithm won’t
// exceed this limit.

// Average-Case Space Complexity:
// This represents the expected memory usage over all possible inputs of
// size n. It’s harder to calculate but useful when worst-case scenarios
// are rare.

// Best-Case Space Complexity:
// This is the minimum memory used for a specific input. While informative,
// it’s less practical since it doesn’t guarantee performance for all
// inputs.




#include <iostream>
using namespace std;

int main() {
    int n = 10;  

    // O(1) - Constant space operation
    // Only a single integer variable is used, regardless of n
    int x = 5;
    cout << "Value of x: " << x << endl;

    // O(n) - Linear space operation
    // An array of size n is allocated, so memory grows linearly with n
    int* arr = new int[n];
    cout << "Array elements initialized to 0: ";
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; // Free the allocated memory

    // O(n^2) - Quadratic space operation
    // A 2D array of size n x n is allocated, so memory grows with n^2
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    cout << "Matrix initialized to 0:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}