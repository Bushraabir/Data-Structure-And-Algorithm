/*
 * Problem Statement: Largest Rectangle in Histogram
 *
 * You are given an array of integers where each element represents the height of a bar in a histogram.
 * - The width of every bar is always 1.
 *
 * Task: Find the area of the largest rectangle that can be formed in the histogram.
 *
 * Key Observations:
 * - Any potential largest rectangle must use one of the bars as its height.
 * - For a given bar, we can extend the rectangle as far left and right as the bars are >= to it.
 *
 * Intuition:
 * - Use a stack to keep track of indices of bars in increasing order of height.
 * - When we encounter a shorter bar, it means we've found the Next Smaller Element (NSE) for the bar at the top of the stack.
 * - At this point, we pop from the stack, calculate the area using:
 *     height * (current_index - previous_smaller_index - 1)
 *   and update the max area.
 * - After the loop, we handle any remaining bars in the stack similarly using N = heights.size() as their NSE.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st; // stack to store indices
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

    // Process remaining elements in the stack
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

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;

    return 0;
}
