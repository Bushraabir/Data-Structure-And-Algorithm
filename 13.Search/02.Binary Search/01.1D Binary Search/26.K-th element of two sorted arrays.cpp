// 1. Problem Introduction
// -----------------------
//
// Goal: Find the **K-th element** from the merged version of two sorted arrays
// without actually merging them.
//
// Examples:
// array1 = [2, 3, 4, 10, 12]
// array2 = [1, 5, 7, 8, 18, 19]
// K = 5
// Combined = [1,2,3,4,5,7,8,10,12,18,19]
// 5th element = 5
//
// Constraints:
// - 0 ≤ n1, n2 ≤ 10^5
// - -10^6 ≤ arr[i] ≤ 10^6
// - Arrays are sorted
//
// Equivalent Problems:
// - Find kth element of two sorted arrays
// - Median of Two Sorted Arrays (special case: K = (n1+n2)/2)


// 2. Brute Force (Merge then Find K-th)
// -------------------------------------
//
// Idea:
// - Merge both arrays into one sorted array
// - Directly return merged[k-1] (1-based index)
//
// Steps:
// - Use two pointers i, j to merge
// - Store merged result in array3
// - Return array3[k-1]
//
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n1 + n2)


#include <bits/stdc++.h>
using namespace std;

int kthBrute(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    vector<int> merged;
    int i = 0, j = 0;

    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while(i < n1) merged.push_back(a[i++]);
    while(j < n2) merged.push_back(b[j++]);

    return merged[k-1]; // 1-based index
}


// 3. Optimized (Space O(1), Simulated Merge)
// -------------------------------------------
//
// Key Insight:
// - We don’t need full merged array
// - Only need the k-th element
//
// Steps:
// - Simulate merge with two pointers
// - Count how many elements have been "merged"
// - Stop when we reach the k-th element
//
// Time Complexity: O(k)
// Space Complexity: O(1)


int kthOptimized(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0, count = 0;

    while(i < n1 && j < n2) {
        int val;
        if(a[i] <= b[j]) val = a[i++];
        else val = b[j++];

        count++;
        if(count == k) return val;
    }

    while(i < n1) {
        int val = a[i++];
        count++;
        if(count == k) return val;
    }

    while(j < n2) {
        int val = b[j++];
        count++;
        if(count == k) return val;
    }

    return -1; // should not reach here
}


// 4. Most Optimal (Binary Search O(log(min(n1, n2))))
// ---------------------------------------------------
//
// Key Insight (Advanced):
// - Similar to "Median of Two Sorted Arrays"
// - Partition both arrays such that total left = k
// - Ensure max(leftA, leftB) <= min(rightA, rightB)
// - Answer is max(leftA, leftB)
//
// Steps:
// - Binary search on smaller array
// - mid1 = elements taken from array1
// - mid2 = k - mid1 (from array2)
// - Adjust based on partition validity
//
// Time Complexity: O(log(min(n1, n2)))
// Space Complexity: O(1)


int kthBinarySearch(vector<int>& a, vector<int>& b, int k) {
    if(a.size() > b.size()) return kthBinarySearch(b, a, k);

    int n1 = a.size(), n2 = b.size();
    int low = max(0, k - n2), high = min(k, n1);

    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if(l1 > r2) high = cut1 - 1;
        else low = cut1 + 1;
    }

    return -1; // should not reach here
}


// 5. Example Usage
// ----------------
int main() {
    vector<int> a = {2, 3, 4, 10, 12};
    vector<int> b = {1, 5, 7, 8, 18, 19};
    int k = 5;

    cout << "Brute: " << kthBrute(a, b, k) << endl;        // 5
    cout << "Optimized: " << kthOptimized(a, b, k) << endl;// 5
    cout << "Binary Search: " << kthBinarySearch(a, b, k) << endl; // 5

    return 0;
}
