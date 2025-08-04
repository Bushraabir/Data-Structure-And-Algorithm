/*
Given an integer N, return the factorial of first N natural numbers. Try to solve this using recursion.
*/

#include <iostream>
using namespace std;    

int Fct(int n) {
    if (n == 0) return 1; // Base case: if n is 0, return 1
    return n * Fct(n - 1); // Recursive call with n-1
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int result = Fct(n); // Call the function 
    cout << "Sum of first " << n << " natural numbers is: " << result << endl;

    return 0;
}