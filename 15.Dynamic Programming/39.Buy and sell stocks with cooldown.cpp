#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Buy and Sell Stocks with Cooldown
    -------------------------------------------
    - You can complete as many transactions as you want (buy/sell multiple times).
    - BUT: after you sell a stock, you must wait 1 day before you can buy again.
    - The cooldown period means: if you sell on day X, you can next buy on day X+2 or later.

    Goal: Maximize total profit.

    Approach Evolution:
    -------------------
    1. Recursion:
       State: f(index, buy)
       - index = current day (0 to n-1)
       - buy = 1 if you can buy now, 0 if you must sell now.
       Transitions:
         If buy == 1:
            Option 1: Buy today → -prices[index] + f(index+1, 0)
            Option 2: Skip buying → 0 + f(index+1, 1)
         If buy == 0:
            Option 1: Sell today → prices[index] + f(index+2, 1) // cooldown applies
            Option 2: Skip selling → 0 + f(index+1, 0)

    2. Memoization:
       - Store results in dp[index][buy] to avoid recomputation.
       - Time: O(N), Space: O(N) for dp + O(N) recursion stack.

    3. Tabulation (Bottom-Up):
       - Reverse order: start from last index → index 0.
       - dp[index][buy] depends on dp[index+1][..] and dp[index+2][..].
       - Size dp as (n+2)×2 to handle index+2 safely.

    4. Space Optimization:
       - Only need dp for (index+1) and (index+2), so store in 3 arrays:
         front1 → dp[index+1]
         front2 → dp[index+2]
         curr   → dp[index]
       - Update in reverse: index from n-1 → 0.
       - Time: O(N), Space: O(1).
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    // front1 = dp[index+1], front2 = dp[index+2]
    vector<int> front1(2, 0), front2(2, 0), curr(2, 0);

    // Base case beyond n: profit = 0
    // front1 and front2 already initialized to 0.

    for (int index = n - 1; index >= 0; index--) {
        // Loop for buy state = 0 (sell) and buy state = 1 (buy)
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 1) {
                // Can buy now
                int buyToday = -prices[index] + front1[0]; // Buy today → go to sell state tomorrow
                int skipBuy = 0 + front1[1];               // Skip today → still can buy tomorrow
                curr[buy] = max(buyToday, skipBuy);
            } else {
                // Must sell now
                int sellToday = prices[index] + front2[1]; // Sell today → cooldown → can buy after 2 days
                int skipSell = 0 + front1[0];              // Skip selling → still must sell tomorrow
                curr[buy] = max(sellToday, skipSell);
            }
        }
        // Shift arrays forward for next iteration
        front2 = front1;
        front1 = curr;
    }

    // Answer: starting at day 0, with the option to buy
    return front1[1];
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}

