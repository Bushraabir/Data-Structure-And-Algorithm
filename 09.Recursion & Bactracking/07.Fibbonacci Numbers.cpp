/*
Multiple Recursive Calls

The Fibonacci numbers, commonly denoted F(n), form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is:

    F(0) = 0
    F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1

Given n, calculate F(n) using recursion.
*/

#include <iostream>
using namespace std;

int fib(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci number F(" << n << ") = " << fib(n) << endl;

    return 0;
}


//time complexity: O(2^n) (exponential due to overlapping subproblems)
//space complexity: O(n) (due to recursion stack depth)
// Note: This is a naive recursive solution. For larger n, consider using memoization or dynamic programming to optimize.
