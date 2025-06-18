// Time complexity indecates how the running time of an algorithm increases
// as the size of the input data increases. It is an indecator  to predict the 
// performance and to compare different approaches to solving the same problem.
// Time complexity is expressed using Big O Notation; which describes the upper
// bond of the algorithm's growth rate in the worst case senario. It focuses
// on the dominant term that grows the fastest as the input size increases and
// ignores the low-order terms and constants for simplicity.


// Some common time complexities:

// O(1) --> constant time
//      --> takes the same amount of time regardless of the input size.
//      --> e.g. Accessing an element in an array by its index
//      --> Extremely efficient, as the time does not grow with input size.


// O(log n) --> Logarithmic Time
//          --> time grows logarithmically as the input size increases
//          --> common in algorithms that repeatedly divide the problem in half
//          --> e.g. Binary Search in sorted array
//          --> Efficient for large inputs, as the time increases slowly


// O(n) --> Linear Time
//      --> Time grows linearly with the input size
//      --> Iterating through an array to find a specific element.
//      --> acceptable when the input size is not too large



// O(n log n) --> Linearithmic Time
//            --> The time grows in proportion to nlogn
//            --> faster than quadratic time but slower than linear time.
//            --> e.g. merge sort, heap sort
//            --> Often the best achievable time for comparison-based sorting algorithms


// O(n^2) --> Quadratic Time
//        --> time grows with the square of the input size
//        --> e.g.Bubble sort, Inserstion sort, nested loops
//        --> Inefficient for large inputs



// O(2^n) --> Exponential Time
//        --> Time doubles with each additional element in the input
//        --> Recursive algorithms that solve problems by checking all possible subsets,
//            such as the naive solution to the traveling salesman problem.
//        --> Highly inefficient for large inputs

// ***
// O(1) > O(log n) > O(n) > O(nlogn) > O(x^2) > O(x^3) > O(2^x) > O(n!)
// ***




// Calculation of Time Complexity: ( Using Big O Notation )
// Big O notation simplifies the analysis of algorithms by focusing on
// the term that grows the fastest as the input size increases.
// e.g. if an algorithm's running time is 3n^2 + 2n + 1 ; then the time
// complexity will be O(n^2) as n^2 term dominates for large n.
// It allows us to compare algorithms based on their scalability rather
// than getting bogged down by constants or lower-order terms.



// Worst-Case Time Complexity:   The maximum time the algorithm will take
// for any input of size n. This is the most commonly used measure
// because it provides a guarantee that the algorithm will not perform
// worse than this bound.

// Average-Case Time Complexity:     The expected time the algorithm takes over
// all possible inputs of size n. This can be more difficult to analyze
// but is useful when the worst case is rare.

// Best-Case Time Complexity:   The minimum time the algorithm takes for a 
// specific input. While this can be informative, it is less commonly used
// because it does not provide guarantees for general inputs.






// hash table --> unordered map --> O(1) -->ammotized(average)


#include <iostream>
using namespace std;

int main() {
    int n = 10;  

    // O(1) - Constant time operation
    // Printing a single message takes the same time regardless of n
    cout << "Hello, World!" << endl;

    // O(n) - Linear time operation
    // This loop runs n times, so the time grows linearly with n
    cout << "Numbers from 0 to " << n-1 << ": ";
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;

    // O(n^2) - Quadratic time operation
    // Nested loops run n * n times, so the time grows with the square of n
    cout << "All pairs of numbers from 0 to " << n-1 << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;
    }

    return 0;
}