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
