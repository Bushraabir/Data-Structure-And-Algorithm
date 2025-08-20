// 1. Problem Introduction
// -----------------------
//
// Goal: Find the **median of two sorted arrays** (arrays may be of different sizes).
//
// Definition of Median:
// - If total elements (n1 + n2) is odd → median is the middle element
// - If total elements (n1 + n2) is even → median is average of the two middle elements
//
// Examples:
// array1 = [1, 3, 5, 7, 9, 11]
// array2 = [2, 4, 6, 8]
// Combined = [1,2,3,4,5,6,7,8,9,11] → median = (5+6)/2 = 5.5
//
// array1 = [1, 2]
// array2 = [3, 4, 5]
// Combined = [1,2,3,4,5] → median = 3
//
// Constraints:
// - 0 ≤ n1, n2 ≤ 10^5
// - -10^6 ≤ arr[i] ≤ 10^6
// - Arrays are sorted
//
// Equivalent Problems:
// - Median of Two Sorted Arrays
// - Find kth element of two sorted arrays


// 2. Brute Force (Merge then Find Median)
// ---------------------------------------
//
// Idea:
// - Merge both arrays into one sorted array
// - Directly find the median element(s)
//
// Steps:
// - Use two pointers i, j to merge
// - Store merged result in array3
// - If total n is odd → return array3[n/2]
// - If even → return (array3[n/2] + array3[n/2 - 1]) / 2.0
//
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n1 + n2)


#include <bits/stdc++.h>
using namespace std;

double findMedianBrute(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    vector<int> merged;
    int i = 0, j = 0;

    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while(i < n1) merged.push_back(a[i++]);
    while(j < n2) merged.push_back(b[j++]);

    int n = merged.size();
    if(n % 2 == 1) return merged[n/2];
    else return (merged[n/2] + merged[n/2 - 1]) / 2.0;
}


// 3. Optimized (Space O(1), Simulated Merge)
// -------------------------------------------
//
// Key Insight:
// - We don’t need the full merged array
// - Only need the middle one/two elements
//
// Steps:
// - Simulate merge with pointers (i, j)
// - Track count of merged elements
// - When count == index1 → store element1
// - When count == index2 → store element2
// - Stop once median elements found
//
// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)


double findMedianOptimized(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2;
    int idx1 = (n - 1) / 2;
    int idx2 = n / 2;

    int i = 0, j = 0, count = 0;
    int ele1 = -1, ele2 = -1;

    while(i < n1 && j < n2) {
        int val;
        if(a[i] <= b[j]) val = a[i++];
        else val = b[j++];

        if(count == idx1) ele1 = val;
        if(count == idx2) { ele2 = val; break; }
        count++;
    }

    while(i < n1) {
        int val = a[i++];
        if(count == idx1) ele1 = val;
        if(count == idx2) { ele2 = val; break; }
        count++;
    }

    while(j < n2) {
        int val = b[j++];
        if(count == idx1) ele1 = val;
        if(count == idx2) { ele2 = val; break; }
        count++;
    }

    if(n % 2 == 1) return ele2;
    return (ele1 + ele2) / 2.0;
}


// 4. Most Optimal (Binary Search O(log(min(n1, n2))))
// ---------------------------------------------------
//
// Key Insight (Advanced):
// - Median divides combined array into 2 halves
// - Use binary search on partition index of smaller array
//
// Steps:
// - Partition arrays such that:
//   leftA + leftB = rightA + rightB
// - Ensure max(leftA, leftB) <= min(rightA, rightB)
// - Then median = average of max(left) & min(right)
// - Works in logarithmic time
//
// Time Complexity: O(log(min(n1, n2)))
// Space Complexity: O(1)


double findMedianBinarySearch(vector<int>& a, vector<int>& b) {
    if(a.size() > b.size()) return findMedianBinarySearch(b, a);
    int n1 = a.size(), n2 = b.size();
    int low = 0, high = n1;

    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

        if(l1 <= r2 && l2 <= r1) {
            if((n1 + n2) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }
        else if(l1 > r2) high = cut1 - 1;
        else low = cut1 + 1;
    }
    return 0.0;
}


// 5. Example Usage
// ----------------
int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    vector<int> b = {2, 4, 6, 8};

    cout << fixed << setprecision(5);
    cout << "Brute: " << findMedianBrute(a, b) << endl;        // 5.50000
    cout << "Optimized: " << findMedianOptimized(a, b) << endl;// 5.50000
    cout << "Binary Search: " << findMedianBinarySearch(a, b) << endl; // 5.50000

    return 0;
}
