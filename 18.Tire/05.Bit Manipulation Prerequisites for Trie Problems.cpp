// 1. Problem Introduction
// -----------------------
//
// Goal: Understand **bit manipulation basics** that are prerequisites for Trie problems 
//       involving XOR and binary representations.
//
// Bit Manipulation Concepts:
// - Numbers are stored as full bitsets (32 bits for int, 64 bits for long long)
// - Rightmost bit is index 0, leftmost is highest index
// - Bits represent powers of 2: bit at index k → 2^k
//
// Key Operations:
// 1. Check if a bit is set
// 2. Turn on (set) a specific bit
// 3. XOR operations for maximizing/minimizing values
//
// Example:
// Number: 9 (binary 000...001001)
// - Bit at index 0 → 1
// - Bit at index 3 → 1
//
// Constraints:
// - Applicable for integers and long long
// - Useful in XOR-based Trie problems

#include <bits/stdc++.h>
using namespace std;

// 2. Bit Manipulation Functions
// -----------------------------

// Function to check if bit at 'index' is set (1)
bool isBitSet(int num, int index) {
    return (num >> index) & 1; // Shift right by index and AND with 1
}

// Function to turn on bit at 'index'
int setBit(int num, int index) {
    return num | (1 << index); // OR with mask where only index-th bit is 1
}

// Function to perform XOR of two numbers
int xorOperation(int a, int b) {
    return a ^ b; // XOR: different bits → 1, same bits → 0
}

// 3. Example Usage
// ----------------
int main() {
    int num = 9; // Binary: 1001
    cout << "Bit at index 0: " << isBitSet(num, 0) << endl; // 1
    cout << "Bit at index 1: " << isBitSet(num, 1) << endl; // 0
    cout << "Bit at index 3: " << isBitSet(num, 3) << endl; // 1

    int newNum = setBit(num, 1); // Turn on bit 1 → Binary: 1011
    cout << "After setting bit 1: " << newNum << endl; // 11

    int a = 6; // 0110
    int b = 3; // 0011
    cout << "XOR of 6 and 3: " << xorOperation(a, b) << endl; // 5 (0101)

    return 0;
}
