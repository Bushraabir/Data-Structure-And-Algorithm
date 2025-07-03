/*
You are given two integers n1 and n2. You need to find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.
*/

#include <bits/stdc++.h>
using namespace std;

// Euclidean algorithm to find GCD (GCD(a, b) = GCD(b, a % b))
int gcd(int n1, int n2) {
    if (n2 == 0) return n1; // Base case: if n2 is 0, return n1
    return gcd(n2, n1 % n2); // Recursive call with n2 and the remainder of n1 divided by n2
}

int main() {
    int n1, n2;
    cout << "Enter two integers: ";
    cin >> n1 >> n2;

    // Handle negative inputs to ensure GCD is always positive
    n1 = abs(n1);
    n2 = abs(n2);

    int result = gcd(n1, n2);
    cout << "GCD of " << n1 << " and " << n2 << " is: " << result << endl;

    return 0;
}

// Time complexity: O(log(min(n1, n2))) 
// (since the problem size is reduced logarithmically with each recursive call)
// Space complexity: O(log(min(n1, n2))) 
// (due to the recursion stack, though small; iterative implementation would be O(1))
// Note: The GCD function can also be implemented iteratively using a loop, which would have the same time complexity but O(1) space complexity.