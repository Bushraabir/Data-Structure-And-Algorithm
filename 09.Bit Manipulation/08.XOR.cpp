#include <bits/stdc++.h>
using namespace std;

// Function to calculate XOR of numbers from 1 to n
int xor_1_to_n(int n) {
    // Pattern based on n % 4
    // 1. If n % 4 == 0 => result = n
    // 2. If n % 4 == 1 => result = 1
    // 3. If n % 4 == 2 => result = n + 1
    // 4. If n % 4 == 3 => result = 0
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else return 0; // n % 4 == 3
}

// Function to calculate XOR of numbers from L to R
int xor_L_to_R(int L, int R) {
    // XOR(L to R) = XOR(1 to R) ^ XOR(1 to L-1)
    return xor_1_to_n(R) ^ xor_1_to_n(L - 1);
}

int main() {
    int n = 9;
    cout << "XOR of numbers from 1 to " << n << " = " << xor_1_to_n(n) << endl;

    int L = 4, R = 7;
    cout << "XOR of numbers from " << L << " to " << R << " = " << xor_L_to_R(L, R) << endl;

    return 0;
}
