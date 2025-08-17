#include <bits/stdc++.h>
using namespace std;

// ------------------------------
// Decimal to Binary Conversion
// ------------------------------
// Function that converts an integer to its binary representation (string).
// Time Complexity: O(log2(N))
// Space Complexity: O(log2(N))
string convertToBinary(int x) {
    if (x == 0) return "0";
    string result = "";
    while (x > 0) {
        result += (x % 2 == 0 ? "0" : "1"); // store remainder (0 or 1)
        x /= 2;                             // divide by 2
    }
    reverse(result.begin(), result.end());  // reverse string for correct order
    return result;
}

// ------------------------------
// Binary to Decimal Conversion
// ------------------------------
// Function that converts a binary string to its decimal integer.
// Time Complexity: O(length of string)
// Space Complexity: O(1)
int convertToDecimal(string bin) {
    int number = 0;
    int power_of_two = 1; // represents 2^0
    for (int i = bin.size() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            number += power_of_two;
        }
        power_of_two *= 2; // move to next power of two
    }
    return number;
}

// ------------------------------
// One's Complement
// ------------------------------
// Flip all bits of a binary string
string onesComplement(string bin) {
    for (char &c : bin) {
        c = (c == '0' ? '1' : '0');
    }
    return bin;
}

// ------------------------------
// Two's Complement
// ------------------------------
// One's complement + 1
string twosComplement(string bin) {
    bin = onesComplement(bin);
    // Add 1 from the rightmost side
    int carry = 1;
    for (int i = bin.size() - 1; i >= 0; i--) {
        int sum = (bin[i] - '0') + carry;
        bin[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    if (carry) bin = '1' + bin; // handle overflow
    return bin;
}

// ------------------------------
// Driver Function
// ------------------------------
int main() {
    int a = 13, b = 7;

    cout << "Decimal to Binary Conversion:\n";
    cout << a << " in binary = " << convertToBinary(a) << "\n";
    cout << b << " in binary = " << convertToBinary(b) << "\n\n";

    cout << "Binary to Decimal Conversion:\n";
    cout << "1101 in decimal = " << convertToDecimal("1101") << "\n";
    cout << "111 in decimal = " << convertToDecimal("111") << "\n\n";

    cout << "One's and Two's Complement of " << a << ":\n";
    string binA = convertToBinary(a);
    cout << "Binary: " << binA << "\n";
    cout << "One's Complement: " << onesComplement(binA) << "\n";
    cout << "Two's Complement: " << twosComplement(binA) << "\n\n";

    // ------------------------------
    // Bitwise Operators
    // ------------------------------
    cout << "Bitwise Operators:\n";

    cout << a << " & " << b << " = " << (a & b) << " (AND)\n";
    cout << a << " | " << b << " = " << (a | b) << " (OR)\n";
    cout << a << " ^ " << b << " = " << (a ^ b) << " (XOR)\n";

    cout << a << " >> 1 = " << (a >> 1) << " (Right Shift by 1, equivalent to a/2)\n";
    cout << a << " >> 2 = " << (a >> 2) << " (Right Shift by 2, equivalent to a/4)\n";

    cout << a << " << 1 = " << (a << 1) << " (Left Shift by 1, equivalent to a*2)\n";
    cout << a << " << 2 = " << (a << 2) << " (Left Shift by 2, equivalent to a*4)\n";

    cout << "~" << a << " = " << (~a) << " (NOT)\n";
    cout << "~" << -6 << " = " << (~(-6)) << " (NOT)\n";

    return 0;
}
