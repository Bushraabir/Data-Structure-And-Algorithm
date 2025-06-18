#include<iostream>
using namespace std;

void pattern(int n) {
    for (int i = 0; i < n; i++) {
        
        for (int j = 1; j <= i + 1; j++) {
            cout << j;
        }
        // Print spaces: 2 * (n - i - 1)
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << " ";
        }
        
        for (int j = i + 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    pattern(n);
    return 0;
}