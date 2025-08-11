#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007; // Problem may require modulo due to large numbers

/*
    Problem: Count the number of ways to parenthesize a boolean expression
    so that it evaluates to TRUE.
    
    Expression contains:
      - 'T' for true
      - 'F' for false
      - '&', '|', '^' as boolean operators
      
    This is a classic PARTITION DP problem, similar to Matrix Chain Multiplication.

    Core idea:
      We break the expression into sub-expressions at each operator, recursively
      calculating:
        - number of ways left part can be TRUE
        - number of ways left part can be FALSE
        - number of ways right part can be TRUE
        - number of ways right part can be FALSE
      and combine according to operator rules.

    DP State:
      dp[i][j][isTrue] = number of ways to evaluate expression[i..j] to TRUE (if isTrue = 1)
                         or to FALSE (if isTrue = 0)

    Why isTrue dimension?
      Because when calculating ways for a sub-expression, we need both TRUE and FALSE counts
      to combine results depending on the operator.
*/

// dp[i][j][isTrue] = memoization table
int dp[205][205][2];

// Recursive + Memoization function
long long solve(int i, int j, bool isTrue, string &expr) {
    // Base case 1: empty range
    if (i > j) return 0;

    // Base case 2: single character (T or F)
    if (i == j) {
        if (isTrue) {
            return expr[i] == 'T' ? 1 : 0;
        } else {
            return expr[i] == 'F' ? 1 : 0;
        }
    }

    // Memoization check
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;

    /*
        Partition at every operator.
        Operators are always at odd indices if operands are at even indices.
        So we increment k by 2.
    */
    for (int k = i + 1; k <= j - 1; k += 2) {
        char op = expr[k];

        // Recursively calculate for left and right sub-expressions
        long long leftTrue  = solve(i, k - 1, true, expr);
        long long leftFalse = solve(i, k - 1, false, expr);
        long long rightTrue  = solve(k + 1, j, true, expr);
        long long rightFalse = solve(k + 1, j, false, expr);

        if (op == '&') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightTrue) % MOD) % MOD;
            } else {
                ways = (ways + (leftTrue * rightFalse) % MOD
                             + (leftFalse * rightTrue) % MOD
                             + (leftFalse * rightFalse) % MOD) % MOD;
            }
        }
        else if (op == '|') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightTrue) % MOD
                             + (leftTrue * rightFalse) % MOD
                             + (leftFalse * rightTrue) % MOD) % MOD;
            } else {
                ways = (ways + (leftFalse * rightFalse) % MOD) % MOD;
            }
        }
        else if (op == '^') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightFalse) % MOD
                             + (leftFalse * rightTrue) % MOD) % MOD;
            } else {
                ways = (ways + (leftTrue * rightTrue) % MOD
                             + (leftFalse * rightFalse) % MOD) % MOD;
            }
        }
    }

    // Store and return
    return dp[i][j][isTrue] = ways % MOD;
}

int countWays(string expr) {
    memset(dp, -1, sizeof(dp));
    int n = expr.size();
    // Initial call: entire expression, we want TRUE
    return solve(0, n - 1, true, expr);
}

int main() {
    string expr = "T|F&T^T";  // Example
    cout << countWays(expr) << "\n";
    return 0;
}

/*
------------------------------------
Explanation with Example: "T|F&T"

Step 1:
  We call solve(0, 4, true)
  i = 0, j = 4, isTrue = 1

Step 2:
  Possible partitions: k = 1 ('|'), k = 3 ('&')

Partition at k=1 ('|'):
  left = solve(0,0,true)  => 1 way  (T)
  left = solve(0,0,false) => 0 ways
  rightTrue  = solve(2,4,true)
  rightFalse = solve(2,4,false)

Partition at k=3 ('&'):
  Similar breakdown...

At each partition, apply operator truth table logic:
  & : True if both True
  | : True if at least one True
  ^ : True if one True and one False

The recursion explores all parenthesizations, counts the ways
each evaluates to True, and memoizes results to avoid recomputation.
------------------------------------
Time Complexity: O(N^3)
Space Complexity: O(N^2) for dp + recursion stack
------------------------------------
*/
