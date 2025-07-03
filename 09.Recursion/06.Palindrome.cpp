/*
Given a string s, return true if the string is palindrome, otherwise false.


A string is called palindrome if it reads the same forward and backward.
*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }

    return true; // All characters matched
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
// Time complexity: O(n) where n is the length of the string (we check each character once)
// Space complexity: O(1) (we use a constant amount of space for the left and right pointers)
