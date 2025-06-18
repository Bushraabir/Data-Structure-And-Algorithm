//Complete the function printNumber which takes an integer input from the user and prints it on the screen.

#include <iostream>
using namespace std;

class Solution {
public:
    void printNumber() {
        int a;
        cin >> a;
        cout << a << endl;
    }
};

int main() {
    Solution obj;
    cout << "Enter a number: ";
    obj.printNumber();
    return 0;
}
