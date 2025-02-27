// Problem : Given a positive integer n, determine whether it is a prime number or not.
// Implement a function named primeornot that checks if n is prime.
// The main function should prompt the user for a number, call primeornot,
// and output the result.

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

    if(primeornot(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}
