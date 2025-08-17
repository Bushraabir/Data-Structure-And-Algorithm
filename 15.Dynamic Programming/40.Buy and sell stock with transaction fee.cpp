#include <bits/stdc++.h>
using namespace std;

/*
     Buy and Sell Stocks with Transaction Fee
    ------------------------------------------------
    Problem:
      - You may complete as many transactions as you want (buy/sell multiple times).
      - A transaction fee is charged every time you complete a transaction.
      - A transaction is "complete" when you BUY and then SELL once.
      - You want to maximize profit after accounting for the fee.

    Example:
      prices = [1,3,2,8,4,9], fee = 2
      Without fee: Best profit = 13
      With fee (2 each transaction): Best profit = 8

    ------------------------------------------------
    1. RECURSIVE THINKING
       State: f(index, buy)
       - index = current day (0..n-1)
       - buy = 1 → allowed to buy today
       - buy = 0 → must sell today (already holding a stock)
       Base case: if index == n → return 0 (no more days)

       If buy == 1:
          Option 1: Buy today  → -prices[index] + f(index+1, 0)
          Option 2: Skip today → 0 + f(index+1, 1)
          ans = max(Option 1, Option 2)

       If buy == 0:
          Option 1: Sell today (deduct fee) → prices[index] - fee + f(index+1, 1)
          Option 2: Skip today              → 0 + f(index+1, 0)
          ans = max(Option 1, Option 2)

       Initial call: f(0, 1)

    ------------------------------------------------
    2. MEMOIZATION
       - Store results in dp[index][buy] to avoid recomputation.
       - Time: O(n), Space: O(n) for dp + recursion stack.

    ------------------------------------------------
    3. TABULATION
       - Build dp table iteratively from back to front.
       - dp[index][buy] depends on dp[index+1][..].
       - Base case: dp[n][0] = dp[n][1] = 0

    ------------------------------------------------
    4. SPACE OPTIMIZATION
       - Notice: We only ever need dp[index+1] to compute dp[index].
       - So store:
            front[buy] → dp[index+1][buy]
            curr[buy]  → dp[index][buy]
       - Time: O(n), Space: O(1).

    ------------------------------------------------
    IMPORTANT: Fee can be deducted at buy or sell step — both work if done once per transaction.
               Here, we deduct at SELL step for clarity.
*/

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    // front[0] = profit if we must sell at index+1
    // front[1] = profit if we can buy at index+1
    vector<int> front(2, 0), curr(2, 0);

    // Base case at index = n → profit = 0
    front[0] = front[1] = 0;

    // Iterate backwards (tabulation + space optimization)
    for (int index = n - 1; index >= 0; index--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 1) {
                // Can buy now
                int buyToday = -prices[index] + front[0]; // move to sell state
                int skipBuy  = 0 + front[1];               // stay in buy state
                curr[buy] = max(buyToday, skipBuy);
            } else {
                // Must sell now
                int sellToday = prices[index] - fee + front[1]; // pay fee once per transaction
                int skipSell  = 0 + front[0];
                curr[buy] = max(sellToday, skipSell);
            }
        }
        // Shift for next iteration
        front = curr;
    }

    // Answer: starting at day 0 with ability to buy
    return front[1];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Maximum Profit: " << maxProfit(prices, fee) << endl;
    return 0;
}
