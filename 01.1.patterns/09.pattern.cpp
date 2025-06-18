#include<iostream>
using namespace std;

void printDiamond(int n) {
    int rows = (n + 1) / 2; // Number of rows for top half (including middle for odd n)
    
    for (int i = -rows + 1; i < rows; i++) {
        int abs_i = i < 0 ? -i : i; // Absolute value for symmetry
        int spaces = abs_i;
        int stars = n - 2 * abs_i;
        
        // Print spaces
        for (int j = 0; j < spaces; j++) cout << " ";
        // Print stars
        for (int j = 0; j < stars; j++) cout << "*";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    
    printDiamond(n);
    return 0;
}