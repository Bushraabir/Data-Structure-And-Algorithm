#include <bits/stdc++.h>
using namespace std;

// Function to calculate X raised to the power N
// Handles both positive and negative exponents efficiently
double power(double x, int n) {
    // Store original exponent for later (to handle negative powers)
    int originalN = n;

    // Convert negative exponent to positive for calculation
    // We'll adjust the result at the end if needed
    if (n < 0) {
        n = -n;
    }

    double ans = 1.0; // Initial answer (anything ^ 0 = 1)

    // Loop until exponent becomes 0
    while (n > 0) {
        if (n % 2 == 1) {
            // If exponent is odd:
            // Take one factor of x into the answer
            ans = ans * x;
            n = n - 1; // Make exponent even
        } else {
            // If exponent is even:
            // Square the base and halve the exponent
            x = x * x;
            n = n / 2;
        }
    }

    // If original exponent was negative, take reciprocal
    if (originalN < 0) {
        ans = 1.0 / ans;
    }

    return ans;
}

int main() {
    double x;
    int n;

    // Example usage:
    // Input base and exponent
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    // Calculate power using optimized method
    double result = power(x, n);

    // Output result
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
