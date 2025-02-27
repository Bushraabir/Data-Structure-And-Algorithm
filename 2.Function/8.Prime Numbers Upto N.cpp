// Problem: Given a positive integer n, print all the prime numbers up to n.
// Implement a function named primeornot that checks if a number is prime.
// The main function should prompt the user for a number, call primeornot for each number from 2 to n,
// and output the prime numbers.

#include <iostream>
using namespace std;

bool primeornot(int n) {
    if(n <= 1)
        return false; 

    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false; 
    }
    return true; 
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Prime numbers up to " << n << " are:" << endl;
    for (int i = 2; i <= n; i++) {
        if(primeornot(i))
            cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
