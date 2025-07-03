/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,


    F(0) = 0, F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1.


Given n, calculate F(n).

*/

#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case

    int prev2 = 0; // F(0)
    int prev1 = 1; // F(1)
    int current;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2; // F(n) = F(n-1) + F(n-2)
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci number F(" << n << ") = " << fib(n) << endl;

    return 0;
}
// Time complexity: O(n) (linear time due to the loop)
// Space complexity: O(1) (constant space since we only use a few variables)