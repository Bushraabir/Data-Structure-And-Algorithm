#include <bits/stdc++.h>
using namespace std;

/* 
---------------------------------------
BASIC MATHS FOR DSA
---------------------------------------
Covers:
1. Digit Extraction
2. Counting Digits
3. Reversing a Number
4. Palindrome Check
5. Armstrong Number Check
6. Printing All Divisors
7. Prime Number Check
8. GCD (Brute Force + Euclidean Algorithm)
---------------------------------------
*/

// DIGIT EXTRACTION
void digitExtraction(int n) {
    cout << "Digits of " << n << ": ";
    while (n > 0) {
        int last_digit = n % 10; // Extract last digit
        cout << last_digit << " "; 
        n = n / 10; // Remove last digit
    }
    cout << endl;
}

// COUNTING DIGITS
int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Alternative using log10
int countDigitsLog(int n) {
    return (n == 0) ? 1 : (int)log10(n) + 1;
}

// REVERSING A NUMBER
int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        int last_digit = n % 10;
        rev = rev * 10 + last_digit; // Shift left and add digit
        n /= 10;
    }
    return rev;
}

// PALINDROME CHECK
bool isPalindrome(int n) {
    int original = n;
    int rev = reverseNumber(n);
    return (original == rev);
}

// ARMSTRONG NUMBER CHECK
bool isArmstrong(int n) {
    int original = n;
    int digits = countDigits(n);
    int sum = 0;
    while (n > 0) {
        int last_digit = n % 10;
        sum += pow(last_digit, digits); // Raise to power of digit count
        n /= 10;
    }
    return (sum == original);
}

// PRINTING ALL DIVISORS
void printDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) { // Loop till sqrt(n)
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i); // Avoid duplicates for perfect squares
        }
    }
    sort(divisors.begin(), divisors.end());
    cout << "Divisors: ";
    for (auto d : divisors) cout << d << " ";
    cout << endl;
}

// PRIME NUMBER CHECK
bool isPrime(int n) {
    if (n <= 1) return false; // 0, 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// GCD (BRUTE FORCE)
int gcdBrute(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) gcd = i;
    }
    return gcd;
}

// GCD (EUCLIDEAN ALGORITHM)
int gcdEuclid(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b; // Remainder
        a = temp;
    }
    return a;
}

// LCM using GCD
int lcm(int a, int b) {
    return (a / gcdEuclid(a, b)) * b; // Avoid overflow
}

int main() {
    int n = 7789;

    // 1. Digit Extraction
    digitExtraction(n);

    // 2. Counting Digits
    cout << "Digit Count (Loop): " << countDigits(n) << endl;
    cout << "Digit Count (Log): " << countDigitsLog(n) << endl;

    // 3. Reverse a Number
    cout << "Reverse of " << n << ": " << reverseNumber(n) << endl;

    // 4. Palindrome Check
    cout << "Is 121 Palindrome? " << (isPalindrome(121) ? "Yes" : "No") << endl;

    // 5. Armstrong Check
    cout << "Is 371 Armstrong? " << (isArmstrong(371) ? "Yes" : "No") << endl;

    // 6. Print Divisors
    printDivisors(36);

    // 7. Prime Check
    cout << "Is 37 Prime? " << (isPrime(37) ? "Yes" : "No") << endl;

    // 8. GCD
    cout << "GCD Brute (20, 40): " << gcdBrute(20, 40) << endl;
    cout << "GCD Euclid (20, 40): " << gcdEuclid(20, 40) << endl;

    // 9. LCM
    cout << "LCM (12, 15): " << lcm(12, 15) << endl;

    return 0;
}
