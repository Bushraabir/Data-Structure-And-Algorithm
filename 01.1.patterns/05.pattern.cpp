#include<iostream>
using namespace std;

void pattern(int n){
    for ( int i=0 ; i<n ; i++){
        for( int j=0 ; j<n-i ; j++ )
            cout << "*" ;
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter number of rows:";
    cin >> n;

    pattern(n);

    return 0;
}