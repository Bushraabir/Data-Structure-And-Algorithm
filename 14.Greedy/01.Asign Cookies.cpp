/*
Greedy Algorithm – Assign Cookies Problem

Intuition & Logic:
- We have N children, each with a greed factor (minimum cookie size to be satisfied).
- We have M cookies, each with a certain size.
- Goal: Maximize the number of children satisfied by giving each child at most one cookie.
- Greedy choice:
    - Assign the smallest cookie that can satisfy a child’s greed to that child.
    - This ensures bigger cookies are reserved for greedier children.
- We sort both greed factors and cookie sizes in ascending order.
- Use two pointers to efficiently assign cookies to children.

Problem Example:
- Children greed: 1, 5, 3, 3, 4
- Cookie sizes: 4, 3, 1, 2, 2

Sorted:
- Greed: 1, 3, 3, 4, 5
- Cookies: 1, 2, 2, 3, 4

Algorithm:
- Use pointers i (for children) and j (for cookies).
- If cookie[j] >= greed[i], assign cookie to child i, increment both.
- Else, increment j to try a bigger cookie.
- Continue until all cookies or children are processed.
- Result is the number of children satisfied (i).

TIME & SPACE COMPLEXITY:
- Sorting takes O(N log N + M log M)
- Two-pointer iteration takes O(N + M)
- Overall: O(N log N + M log M)
- Space: O(1) extra space (in-place sorting assumed)

*/

/* -------------------- ASSIGN COOKIES IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& cookies) {
    // Step 1: Sort greed factors and cookie sizes
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    int i = 0; // pointer for children
    int j = 0; // pointer for cookies
    int satisfiedCount = 0;

    // Step 2: Iterate through cookies and children
    while (i < greed.size() && j < cookies.size()) {
        if (cookies[j] >= greed[i]) {
            // Cookie can satisfy the child
            satisfiedCount++;
            i++;  // move to next child
            j++;  // move to next cookie
        } else {
            // Cookie too small, try bigger cookie
            j++;
        }
    }

    // Step 3: Return total children satisfied
    return satisfiedCount;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookies = {4, 3, 1, 2, 2};

    int result = findContentChildren(greed, cookies);
    cout << "Number of children satisfied: " << result << "\n"; // Output: 3

    return 0;
}
