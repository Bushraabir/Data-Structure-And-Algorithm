// O(log n) --> here the time increases logarithmically with the exponent n
// good time complexity due to binary exponentiation

//Example:

// find the value of x^n using binary exponentiation

#include <iostream>
using namespace std;

// Function to calculate x^n using binary exponentiation
long long power(int x, int n) {
    // Handle negative exponents (not in this basic version, assume n >= 0)
    if (n < 0) {
        cout << "Error: This implementation assumes non-negative exponents." << endl;
        return -1; // Error code
    }
    
    // Base cases
    if (n == 0) return 1;
    if (n == 1) return x;
    
    long long result = 1; // Initialize result
    long long base = x;   // Current base to multiply
    
    // Process n in binary form implicitly by checking its bits
    while (n > 0) {
        // If current bit is 1, multiply result with base
        if (n & 1) { // n % 2 == 1 (least significant bit check)
            result *= base;
        }
        // Square the base for the next bit
        base *= base;
        // Right shift n by 1 (divide n by 2)
        n >>= 1; // n /= 2
    }
    
    return result;
}

int main() {
    int x, n;
    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    // Check for valid input
    if (n < 0) {
        cout << "Error: Exponent must be non-negative for this implementation." << endl;
        return 1;
    }

    long long result = power(x, n);
    if (result != -1) { // Check for error code
        cout << x << "^" << n << " = " << result << endl;
    }

    return 0;
}

// Binary Exponentiation Explanation:
// To find x^n (e.g., 2^8), instead of multiplying x by itself n times (O(n)),
// we convert n to binary (e.g., 8 = 1000 in binary, 4 bits).
// Number of bits in n is floor(log2(n)) + 1.
// We process each bit: if bit is 1, multiply result with current base; then square the base.
// For 2^8: 8 = (1000)_2, steps are:
//   - Bit 0: result = 1, base = 2
//   - Bit 1: result = 1, base = 4
//   - Bit 2: result = 1, base = 16
//   - Bit 3: result = 16, base = 256
// Total multiplications = number of bits = O(log n).
// Time complexity: O(log n) as we iterate through log2(n) bits.
// Space complexity: O(1) as we only use a few variables.

