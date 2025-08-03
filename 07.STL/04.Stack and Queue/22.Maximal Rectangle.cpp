/*
 * Problem Statement: Maximal Rectangle
 *
 * You are given a 2D binary matrix of size N x M filled with only 0s and 1s.
 * Task: Find the area of the largest rectangle containing only 1s.
 *
 * Example:
 * Input:
 *  [
 *    {'1', '0', '1', '0', '0'},
 *    {'1', '0', '1', '1', '1'},
 *    {'1', '1', '1', '1', '1'},
 *    {'1', '0', '0', '1', '0'}
 *  ]
 * Output: 6
 * Explanation:
 * The largest rectangle with all 1s has area 6 (2 rows x 3 columns).
 *
 * Key Observations:
 * - This problem builds directly on "Largest Rectangle in Histogram".
 * - We treat each row of the matrix as the base of a histogram.
 * - For each row, we calculate heights of histogram bars using consecutive 1s upwards.
 * - Then, we apply the "Largest Rectangle in Histogram" algorithm to each histogram.
 * - The maximum area obtained across all rows is our result.
 *
 * Intuition:
 * - For each cell (i, j), maintain the height of the column: number of consecutive 1s above (including) this row.
 * - If matrix[i][j] == '1' => height[i][j] = height[i-1][j] + 1
 * - If matrix[i][j] == '0' => height[i][j] = 0
 * - Apply largestRectangleArea() on height[i] (current row’s histogram) and update max area.
 *
 * Time Complexity: O(N * M)
 * Space Complexity: O(M)
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate largest rectangle in a histogram (same as previous problem)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int right = i;
            int left = st.empty() ? -1 : st.top();
            int width = right - left - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = heights[st.top()];
        st.pop();
        int right = n;
        int left = st.empty() ? -1 : st.top();
        int width = right - left - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

// Main function to solve Maximal Rectangle in 2D binary matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int n = matrix.size(), m = matrix[0].size();
    vector<int> height(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        // Build histogram heights for the current row
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '1') {
                height[j] += 1;
            } else {
                height[j] = 0;
            }
        }

        // Apply histogram solution to current row
        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;

    return 0;
}
/*
 * This code defines a function to find the area of the largest rectangle containing only 1s in a binary matrix.
 * It uses a histogram approach where each row is treated as a base for a histogram, and the heights are calculated
 * based on consecutive 1s. The largest rectangle area is then computed using a stack-based method similar to the
 * "Largest Rectangle in Histogram" problem.
 */