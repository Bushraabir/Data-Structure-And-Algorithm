/*
You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.


A number which completely divides another number is called it's divisor.
*/


#include<bits/stdc++.h>
using namespace std;    

vector<int> divisors(int n){
    vector<int> result;
    for(int i=1; i*i <=n; i++) {
        if (n % i == 0) { // If i is a divisor
            result.push_back(i); // Add i to the result
            if (i != n / i) { // Check to avoid adding the square root twice
                result.push_back(n / i); // Add the corresponding divisor
            }
        }
    }


    sort(result.begin(), result.end()); // Sort the result in ascending order
    return result; 
}   

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    vector<int> result = divisors(n);
    
    cout << "Divisors of " << n << " are: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}   