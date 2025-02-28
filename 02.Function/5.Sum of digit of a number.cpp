// Problem: Given a positive integer, calculate the sum of all its digits using recursion.
// Implement a function int sum(int num) that returns the sum of digits.
// In the main function, prompt the user to input a number and then output the sum of its digits.

#include <iostream>
using namespace std;

int sum(int num) {
    if(num == 0)
        return 0;
    return (num % 10) + sum(num / 10); // recursion
}

int main() {
    int num;
    cout << "Enter any number: ";
    cin >> num;
    cout << sum(num) << endl;
    return 0;
}
