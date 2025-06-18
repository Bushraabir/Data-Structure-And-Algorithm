// O(1) --> here the time does not increase with the input size


// Example:
// Sum of numbers from 1 to N

#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = n*(n+1)/2;

    cout<<ans<<endl;

    return 0;
}

// the input size does not effec the runtime;
// that means the run time is a constant(k);
// so in case of constant runtime we say the time complexity is O(k);
// but we ignore the constants in case of time complexity;
// so the final time complexity will be O(1)


// more examples: finding a value in an array
// finding the largest valuee in srted array
// hash table