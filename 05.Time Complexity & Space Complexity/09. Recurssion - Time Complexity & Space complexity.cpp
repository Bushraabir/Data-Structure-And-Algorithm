// O(n) --> here the time increases linearly with the input size due to n recursive calls
// O(n) --> here the space increases linearly due to the recursive call stack depth

//Example:

// Recursive factorial calculation

#include <iostream>
using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative number: ";
    cin >> n;

    // Check for valid input
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    long long result = factorial(n);
    cout << "Factorial: " << result << endl;

    return 0;
}

// Time Complexity:
// The function makes n recursive calls, one for each value from n down to 1.
// Each call performs a constant-time multiplication (O(1)).
// Recurrence relation: T(n) = T(n-1) + O(1), with base case T(1) = O(1).
// Solving: T(n) = O(1) + O(1) + ... + O(1) (n times) = O(n).
// Thus, the time complexity is O(n), linear in the input size.

// Space Complexity:
// Each recursive call adds a frame to the call stack, storing the parameter n and return address.
// Maximum stack depth is n (when n reaches 1 before unwinding).
// Each frame uses O(1) space, so total space is n * O(1) = O(n).
// No additional data structures are used beyond the call stack.
// Thus, the space complexity is O(n), linear in the input size.

// more examples:
// Recursive Fibonacci
// Binary Tree Traversal