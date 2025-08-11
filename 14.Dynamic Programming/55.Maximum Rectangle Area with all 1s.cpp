#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
Helper Function: largestRectangleInHistogram
-----------------------------------------------------
Purpose:
Given an array `heights` representing the height of histogram bars,
this function returns the largest rectangular area that can be formed.

Approach:
- We use a monotonic increasing stack to store indices of histogram bars.
- Whenever we find a bar shorter than the bar at the top of the stack,
  we pop from the stack and calculate the area for the popped bar.
- This ensures we find the largest rectangle possible for each bar height.
- Time Complexity: O(M) for M bars.
*/
int largestRectangleInHistogram(vector<int> &heights) {
    int n = heights.size();
    stack<int> st; // stack to store indices of bars
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        // Current height (0 for the sentinel at the end)
        int h = (i == n ? 0 : heights[i]);

        // If current bar is shorter, process previous bars
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int rightBoundary = i; 
            int leftBoundary = st.empty() ? 0 : st.top() + 1;
            int width = rightBoundary - leftBoundary;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

/*
-----------------------------------------------------
Main Function: maximalRectangle
-----------------------------------------------------
Purpose:
Find the maximum area rectangle consisting entirely of 1's in a binary matrix.

Approach:
1. Treat each row as the base of a histogram.
2. The "height" of each column increases if the cell is '1', 
   otherwise it's reset to 0.
3. For each row, after updating the heights array, 
   compute the largest rectangle in that histogram using 
   `largestRectangleInHistogram`.
4. Keep track of the maximum area found.

Time Complexity:
- O(N * M): For each of the N rows, 
  we update the heights in O(M) and compute histogram max area in O(M).

Space Complexity:
- O(M): For storing heights + O(M) for the stack in LRIH.
*/
int maximalRectangle(vector<vector<int>> &matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> heights(m, 0); // Histogram heights
    int maxArea = 0;

    // Process row by row
    for (int i = 0; i < n; i++) {
        // Update heights for the histogram
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                heights[j] += 1; // Extend the height from the row above
            } else {
                heights[j] = 0; // Reset height if we encounter a 0
            }
        }
        // Compute largest area for this histogram
        int area = largestRectangleInHistogram(heights);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Maximum rectangle area with all 1's: " 
         << maximalRectangle(matrix) << endl;

    return 0;
}

/*
-----------------------------------------------------
Dry Run Example:
-----------------------------------------------------
Matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Row 0 heights: 1 0 1 0 0 → LRIH = 1
Row 1 heights: 2 0 2 1 1 → LRIH = 3
Row 2 heights: 3 1 3 2 2 → LRIH = 6
Row 3 heights: 4 0 0 3 0 → LRIH = 4

Answer = max(1, 3, 6, 4) = 6
-----------------------------------------------------
*/
