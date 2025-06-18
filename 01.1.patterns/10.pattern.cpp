#include<iostream>
using namespace std;

void pattern(int n) {
    for (int i = 0; i < n; i++) {
        int stars = (i < (n + 1) / 2) ? i + 1 : n - i;
        for (int j = 0; j < stars; j++) {
            cout << "*";
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