#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    int top, bottom;
    if (n % 2 == 0) {
        top = n / 2;
        bottom = top;
    } else {
        top = (n + 1) / 2;
        bottom = top - 1;
    }

    for (int i = 1; i <= top; i++) {
        for (int j = 1; j <= (top - i); j++) {
            cout << " ";
        }
        cout << "*";
        if (i > 1) {
            for (int j = 1; j <= (2 * i - 3); j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    for (int i = bottom; i >= 1; i--) {
        for (int j = 1; j <= (top - i); j++) {
            cout << " ";
        }
        cout << "*";
        if (i > 1) {
            for (int j = 1; j <= (2 * i - 3); j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
