// Problem: Given a positive integer n, print the nth Fibonacci number.
// The Fibonacci sequence is defined as follows:
//   fibonacci(0) = 0, fibonacci(1) = 1,
//   fibonacci(n) = fibonacci(n-1) + fibonacci(n-2) for n >= 2.
// Implement a function named nthFibonacci that computes the nth Fibonacci number using an iterative approach,
// and call it in the main function.

#include <iostream>
using namespace std;


int Fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << "The " << n << "th Fibonacci number is: " << Fibonacci(n) << endl;
    return 0;
}
