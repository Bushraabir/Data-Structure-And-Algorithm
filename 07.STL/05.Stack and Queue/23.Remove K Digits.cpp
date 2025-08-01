/*
 * Problem Statement: Remove K Digits
 *
 * You are given a non-negative integer represented as a string `num`, and an integer `k`.
 * Task: Remove `k` digits from the number so that the resulting number is the smallest possible.
 *
 * Example:
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation:
 * Removing 4, 3, and 2 results in "1219" which is the smallest number achievable.
 *
 * Key Observations:
 * - To get the smallest possible number, we want smaller digits to appear earlier.
 * - If a digit is greater than the next digit, we remove it.
 * - Stack is used to efficiently keep track of increasing sequence of digits.
 *
 * Intuition:
 * - Use a greedy strategy with a stack.
 * - While traversing the string, remove digits from the stack that are greater than the current digit.
 * - This ensures smaller digits appear earlier in the result.
 *
 * Edge Cases:
 * - If k == num.size(), return "0" (remove all digits).
 * - After removal, leading zeros must be trimmed.
 * - If final result is empty after trimming zeros, return "0".
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    string st;  // acts like a stack

    for (char digit : num) {
        // Remove digits from the "stack" if they are larger than current digit and k > 0
        while (!st.empty() && k > 0 && st.back() > digit) {
            st.pop_back();
            k--;
        }
        st.push_back(digit);
    }

    // If any digits are still left to remove, remove from the end
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    // Remove leading zeros
    int index = 0;
    while (index < st.size() && st[index] == '0') {
        index++;
    }

    string result = st.substr(index);

    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;

    cout << "Smallest Number after Removing " << k << " digits: " << removeKdigits(num, k) << endl;

    return 0;
}
