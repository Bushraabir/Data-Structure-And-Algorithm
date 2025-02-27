#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number of lines: ";
    cin >> n;
    int top, bottom;
    if(n % 2 == 0){
        top = n / 2;
        bottom = top;
    } else{
        top = (n + 1) / 2;
        bottom = top - 1;
    }
    for(int i = 1; i <= top; i++){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for(int j = 1; j <= 2 * (top - i); j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i = bottom; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for(int j = 1; j <= 2 * (top - i); j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
