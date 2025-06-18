// O(n) --> here the time increases linearly with the input size
// good time complexity for small inputs

//Example:

// finding n factorial

#include<iostream>
using namespace std;

int main(){
    int n;
    long long factorial = 1; // Use long long to handle larger factorials
    cout << "Enter a non-negative number: ";
    cin >> n;

    // Check for valid input
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    cout << factorial << endl;

    return 0;
}

// here the loop runs depending on the value of input n
// in running the loop once, it requires k time to complete
// the operations inside the loop. so it becomes O(n*k),
// here we will ignore the constant k. the time complexity
// is ultimately O(n)

// more examples:
// Kadane's Algorithm
// nth Fibonacci (iterative)