#include <bits/stdc++.h>
using namespace std;

/*
Problem: Divide two integers without using *, /, or % operators.
Given a dividend and a divisor, return the quotient after dividing.
Constraints:
    - Both dividend and divisor are 32-bit integers.
    - Divisor is non-zero.
    - If overflow occurs (dividend = INT_MIN and divisor = -1), return INT_MAX.
Approach: Bit Manipulation using powers of two.
Time Complexity: O((log N)^2), Space Complexity: O(1)
*/

int divide(int dividend, int divisor) {
    // Handle the overflow case explicitly
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the final sign of the result
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Use long to handle overflow for INT_MIN
    long n = abs((long)dividend); // absolute dividend
    long d = abs((long)divisor);  // absolute divisor

    long answer = 0;

    // Repeat until the remaining dividend is less than divisor
    while (n >= d) {
        long temp = d;   // temp will store d * 2^k
        long multiple = 1; // multiple represents 2^k

        // Find the largest multiple such that (d * 2^k) <= n
        while ((temp << 1) <= n) {
            temp <<= 1;       // equivalent to temp *= 2
            multiple <<= 1;   // equivalent to multiple *= 2
        }

        // Subtract the largest multiple of divisor from dividend
        n -= temp;

        // Add the corresponding multiple to answer
        answer += multiple;
    }

    // Apply the sign
    if (negative) answer = -answer;

    return (int)answer;
}

int main() {
    int dividend = 22, divisor = 3;
    cout << "Dividend: " << dividend << ", Divisor: " << divisor << endl;
    cout << "Quotient: " << divide(dividend, divisor) << endl; // Expected output: 7

    dividend = -2147483648;
    divisor = -1;
    cout << "Dividend: " << dividend << ", Divisor: " << divisor << endl;
    cout << "Quotient: " << divide(dividend, divisor) << endl; // Expected output: INT_MAX

    return 0;
}
