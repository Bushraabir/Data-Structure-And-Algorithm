#include <bits/stdc++.h>
using namespace std;

/*
=========================================================
BIT MANIPULATION TRICKS
=========================================================

This program demonstrates several fundamental bit manipulation 
techniques with clear explanations. 

Covered Topics:
1. Swapping numbers without a third variable (using XOR).
2. Checking if the i-th bit is set.
3. Setting the i-th bit.
4. Clearing the i-th bit.
5. Toggling the i-th bit.
6. Removing the last set bit.
7. Checking if a number is a power of two.
8. Counting the number of set bits.
=========================================================
*/

// ------------------------------
// 1. Swap two numbers using XOR
// ------------------------------
// Logic: 
// A = A ^ B
// B = A ^ B  -> gives original A
// A = A ^ B  -> gives original B
void swapNumbers(int &A, int &B) {
    A = A ^ B;
    B = A ^ B;
    A = A ^ B;
}

// ------------------------------
// 2. Check if i-th bit is set
// ------------------------------
// Two methods:
// a) Left shift mask: (n & (1 << i))
// b) Right shift n:   ((n >> i) & 1)
bool isBitSet_LeftShift(int n, int i) {
    return (n & (1 << i)) != 0;
}

bool isBitSet_RightShift(int n, int i) {
    return ((n >> i) & 1) != 0;
}

// ------------------------------
// 3. Set the i-th bit
// ------------------------------
// Logic: n | (1 << i)
int setBit(int n, int i) {
    return n | (1 << i);
}

// ------------------------------
// 4. Clear the i-th bit
// ------------------------------
// Logic: n & (~(1 << i))
int clearBit(int n, int i) {
    return n & (~(1 << i));
}

// ------------------------------
// 5. Toggle the i-th bit
// ------------------------------
// Logic: n ^ (1 << i)
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

// ------------------------------
// 6. Remove the last set bit
// ------------------------------
// Logic: n & (n - 1)
int removeLastSetBit(int n) {
    return n & (n - 1);
}

// ------------------------------
// 7. Check if number is power of two
// ------------------------------
// Property: Only powers of two have exactly one set bit.
// Logic: (n > 0) && ((n & (n - 1)) == 0)
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// ------------------------------
// 8. Count set bits
// ------------------------------

// Method A: Simple bit check with n & 1
int countSetBits_Shift(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) count++; // check last bit
        n >>= 1;            // right shift by 1 (divide by 2)
    }
    return count;
}

// Method B: Brian Kernighan’s Algorithm
// Logic: Each step removes the rightmost set bit.
int countSetBits_BK(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // remove one set bit
        count++;
    }
    return count;
}

// Method C: Built-in function (fastest, uses CPU instruction)
int countSetBits_Builtin(int n) {
    return __builtin_popcount(n); 
}

// =========================================================
// Driver Function to Demonstrate All Methods
// =========================================================
int main() {
    int a = 13, b = 7;

    cout << "================= Bit Manipulation Demo =================\n\n";

    // 1. Swap numbers
    cout << "1. Swapping numbers without third variable:\n";
    cout << "Before: a = " << a << ", b = " << b << "\n";
    swapNumbers(a, b);
    cout << "After:  a = " << a << ", b = " << b << "\n\n";

    // 2. Check if i-th bit is set
    int n = 13; // binary = 1101
    int i = 2;
    cout << "2. Checking if the " << i << "-th bit is set in " << n << " (1101):\n";
    cout << "Using Left Shift: " << isBitSet_LeftShift(n, i) << "\n";
    cout << "Using Right Shift: " << isBitSet_RightShift(n, i) << "\n\n";

    // 3. Set i-th bit
    n = 9; // binary = 1001
    i = 2;
    cout << "3. Setting the " << i << "-th bit in " << n << " (1001):\n";
    cout << "Result: " << setBit(n, i) << " (binary 1101)\n\n";

    // 4. Clear i-th bit
    n = 13; // binary = 1101
    i = 2;
    cout << "4. Clearing the " << i << "-th bit in " << n << " (1101):\n";
    cout << "Result: " << clearBit(n, i) << " (binary 1001)\n\n";

    // 5. Toggle i-th bit
    n = 13; // binary = 1101
    i = 1;
    cout << "5. Toggling the " << i << "-th bit in " << n << " (1101):\n";
    cout << "Result: " << toggleBit(n, i) << " (binary 1111)\n\n";

    // 6. Remove last set bit
    n = 12; // binary = 1100
    cout << "6. Removing last set bit of " << n << " (1100):\n";
    cout << "Result: " << removeLastSetBit(n) << " (binary 1000)\n\n";

    // 7. Check if power of two
    n = 16;
    cout << "7. Checking if " << n << " is power of two:\n";
    cout << (isPowerOfTwo(n) ? "Yes" : "No") << "\n\n";

    // 8. Count set bits
    n = 13; // binary = 1101
    cout << "8. Counting set bits in " << n << " (1101):\n";
    cout << "Method A (Shift): " << countSetBits_Shift(n) << "\n";
    cout << "Method B (Brian Kernighan): " << countSetBits_BK(n) << "\n";
    cout << "Method C (Builtin): " << countSetBits_Builtin(n) << "\n";

    cout << "\n=========================================================\n";

    return 0;
}
