/*
Use recursion to print numbers from 1 to N.
You are given an integer N. You need to print all the numbers from 1 to N
*/

#include <iostream>
using namespace std;

int printUptoN(int n) {
    if (n == 0) return 0; // Base case: if n is 0, return 0
    printUptoN(n - 1); // Recursive call with n-1
    cout << n << " "; 
   
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Numbers from 1 to " << n << ": ";
    printUptoN(n); // Call the function 
    cout << endl;

    return 0;
}


// Time Complexity: O(n) — Each number from 1 to N is printed once, and the function is called recursively N times until it reaches the base case (n == 0).
// Space Complexity: O(n) — The maximum depth of the recursion is N, which means there will be N function calls on the call stack at the worst case before it starts returning back up.


// we use recursion in the following way:
// 1. We check if n is 0, which is our base case. If n is 0, we return from the function, which stops the recursion.
// 2. If n is not 0, we make a recursive call to printUptoN with n-1. This means we are asking the function to print numbers from 1 to n-1 first.
// 3. After the recursive call returns (which means it has printed numbers from 1 to n-1), we print the current value of n. 
// This way, we ensure that numbers are printed in the correct order from 1 to N.      
