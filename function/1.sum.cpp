// Problem: Given a positive integer n, compute the sum of all natural numbers 
// from 1 to n. Implement a function int sum(int n) that calculates this 
// sum using an iterative approach. Your program should then output the 
// result.

#include<iostream>
using namespace std;
int sum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    return sum;
}


int main(){
    int n;
    cout<<"Enter the last number: ";
    cin>>n;

    cout<<sum(n);

    return 0;
}