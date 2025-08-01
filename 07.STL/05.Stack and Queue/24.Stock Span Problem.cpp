/*
 * Problem 5: Stock Span Problem
 *
 * Problem Statement:
 * -------------------
 * You are given the daily price of a stock for N days.
 * For each day, you need to find the span of stock price,
 * i.e., the number of consecutive previous days (including the current day)
 * the price of the stock was less than or equal to today’s price.
 *
 * Example:
 * Input: prices = [7, 2, 1, 3, 3, 1, 8]
 * Output: spans = [1, 1, 1, 3, 4, 1, 7]
 *
 * Explanation:
 * Day 1: 7 -> span = 1 (only itself)
 * Day 2: 2 -> span = 1
 * Day 3: 1 -> span = 1
 * Day 4: 3 -> span = 3 (3 >= 1, 2, 7 from the left)
 * Day 5: 3 -> span = 4
 * Day 6: 1 -> span = 1
 * Day 7: 8 -> span = 7 (8 >= all previous)
 *
 * Intuition:
 * ----------
 * - Use a stack to maintain a decreasing sequence of prices along with their indices.
 * - For each price, pop all elements from the stack that are less than or equal to it.
 * - If the stack becomes empty, it means this price is the highest so far → span = index + 1
 * - Otherwise, span = current index - index of previous greater element (top of the stack).
 *
 * Why Stack Works?
 * -----------------
 * - We only care about the nearest previous greater price.
 * - By maintaining a monotonic decreasing stack, we ensure efficient lookup and update.
 *
 * Time Complexity: O(N)  [Each element pushed and popped at most once]
 * Space Complexity: O(N) [Stack stores prices and indices]
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 5.1 Brute Force Approach
// ------------------------
class StockSpannerBrute {
private:
    vector<int> prices;

public:
    int next(int price) {
        prices.push_back(price);
        int count = 1;
        for (int i = prices.size() - 2; i >= 0; --i) {
            if (prices[i] <= price)
                count++;
            else
                break;
        }
        return count;
    }
};
// Time Complexity: O(N^2) total
// Space Complexity: O(N)


// 5.2 Optimized Stack-Based Approach
// ----------------------------------
class StockSpanner {
private:
    stack<pair<int, int>> st; // pair<price, index>
    int index;

public:
    StockSpanner() {
        index = -1;
    }

    int next(int price) {
        index++;

        // Pop all elements less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int span;
        if (st.empty()) {
            span = index + 1;
        } else {
            span = index - st.top().second;
        }

        st.push({price, index});
        return span;
    }
};
// Time Complexity: O(1) amortized per next()
// Space Complexity: O(N)


// 5.3 Example Usage
// -----------------
int main() {
    cout << "Using Brute Force Approach:\n";
    StockSpannerBrute s1;
    vector<int> prices = {7, 2, 1, 3, 3, 1, 8};
    for (int price : prices) {
        cout << "Price: " << price << " -> Span: " << s1.next(price) << endl;
    }

    cout << "\nUsing Optimized Stack Approach:\n";
    StockSpanner s2;
    for (int price : prices) {
        cout << "Price: " << price << " -> Span: " << s2.next(price) << endl;
    }

    return 0;
}
