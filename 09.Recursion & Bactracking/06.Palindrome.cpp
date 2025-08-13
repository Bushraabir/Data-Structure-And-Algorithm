#include <iostream>
#include <string>
using namespace std;

// Recursive helper function to check palindrome
bool isPalindromeRecursive(const string &s, int left, int right) {
    // Base case: If left >= right, we have compared all characters
    // This means the string is a palindrome
    if (left >= right) {
        return true;
    }

    // If characters at current positions don't match, it's not a palindrome
    if (s[left] != s[right]) {
        return false;
    }

    // Move pointers inward and check the remaining substring
    return isPalindromeRecursive(s, left + 1, right - 1);
}

bool isPalindrome(const string &s) {
    // Call the recursive function starting from both ends
    return isPalindromeRecursive(s, 0, s.length() - 1);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s; // Reads input without spaces

    if (isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}

/*
1. Time Complexity: O(n)
   - We compare each character at most once.
   - Each recursive call processes 2 characters (one from each end).
2. Space Complexity: O(n) due to recursive call stack
   - Each call stores parameters and return address.
3. Recursion stops early if a mismatch is found.
4. Works for simple strings without spaces or punctuation.
*/
