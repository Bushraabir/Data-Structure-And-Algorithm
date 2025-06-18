#include<iostream>
using namespace std;

void pattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << (i + j) % 2;
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter number of rows: ";
    int n;
    cin >> n;
    pattern(n);
    return 0;
}