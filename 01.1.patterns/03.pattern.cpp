#include<iostream>
using namespace std;

void pattern3(int n){
    for ( int i=0 ; i<n ; i++){
        for( int j=0 ; j<=i ; j++ )
            cout << j+1 << " ";
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter number of rows:";
    cin >> n;

    pattern3(n);

    return 0;
}