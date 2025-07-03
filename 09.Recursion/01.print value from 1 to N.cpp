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