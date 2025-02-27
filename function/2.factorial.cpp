//  Problem: Given a positive integer n, calculate its factorial. The factorial of 
// a number n, denoted as n!, is the product of all positive integers less 
// than or equal to n. Implement a function int fac(int n) that computes
//  n! using an iterative approach, and output the result.

#include<iostream>
using namespace std;
int fac(int n){
    int fac=1;
    for(int i=1;i<=n;i++){
        fac=fac*i;
    }
    return fac;
}


int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    cout<<fac(n);

    return 0;
}