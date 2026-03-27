/*
Use recursion to print numbers from N to 1.
You are given an integer N. You need to print all the numbers from 1 to N
*/

#include <iostream>
using namespace std;

int printUpto1(int n) {
    if (n == 0) return 0; // Base case: if n is 0, return 0
    cout << n << " ";
    printUpto1(n - 1); // Recursive call with n-1   
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Numbers from 1 to " << n << ": ";
    printUpto1(n); // Call the function 
    cout << endl;

    return 0;
}


// Time Complexity: O(n) — Each number from N to 1 is printed once, and the function is called recursively N times until it reaches the base case (n == 0).
// Space Complexity: O(n) — The maximum depth of the recursion is N, 
// which means there will be N function calls on the call stack at the worst case before it starts returning back up.
