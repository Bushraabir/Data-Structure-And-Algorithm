// Problem: Given two numbers, find the minimum of the two numbers.
// Write a function named 'min' that takes two integers as arguments and returns the smaller value.
// In the main function, prompt the user to input two numbers, then call the 'min' function and output the result.

#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "The minimum is: " << min(num1, num2) << endl;
    return 0;
}
