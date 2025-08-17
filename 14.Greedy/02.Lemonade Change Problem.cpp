/*
Greedy Algorithm – Lemonade Change Problem

Intuition & Logic:
- Each lemonade costs $5.
- Customers pay with $5, $10, or $20 bills.
- We start with zero bills of any denomination.
- Goal: Determine if we can give correct change to every customer in the order they arrive.
- Greedy choice:
    - Always give change using the largest denominations possible to save smaller bills for future customers.
    - Specifically, for a $20 bill, prefer giving one $10 and one $5 as change over three $5 bills.
- Track counts of $5 and $10 bills as we process each customer.
- If unable to give correct change at any point, return false.

Problem Example:
- Customers pay: 5, 5, 5, 10, 20

Processing:
- $5: just take it (five=1)
- $5: five=2
- $5: five=3
- $10: give $5 change (five=2, ten=1)
- $20: give $10 + $5 change (five=1, ten=0)

All customers served successfully → return true

Algorithm:
- Initialize counters five=0, ten=0.
- Iterate through payments array:
    - If $5 received, increment five.
    - If $10 received, decrement five by 1 (if possible), increment ten.
    - If $20 received, try to give one $10 and one $5 if possible,
      else give three $5 bills.
    - If change cannot be given at any step, return false.
- If all processed, return true.

TIME & SPACE COMPLEXITY:
- Time: O(N), N = number of customers (one pass)
- Space: O(1) constant space for counters

*/

/* -------------------- LEMONADE CHANGE IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else { // bill == 20
            // Prefer giving one $10 and one $5 as change
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << boolalpha << lemonadeChange(bills1) << "\n"; // Output: true

    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << boolalpha << lemonadeChange(bills2) << "\n"; // Output: false

    return 0;
}
