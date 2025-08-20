// 1. Problem Introduction
// -----------------------
//
// Goal: Find the least capacity of a ship such that all packages are shipped within D days.
//
// Constraints:
// - One ship runs once per day
// - Packages must be shipped in order (no reordering)
// - Answer lies between: 
//      max(weights) -> because capacity must fit the heaviest package
//      sum(weights) -> because with that capacity, all packages fit in one day


// 2. Brute Force (Linear Search)
// ------------------------------
//
// - Range of capacity = [max(weights), sum(weights)]
// - For each capacity in range, calculate daysRequired()
// - The first capacity that requires <= D days is our answer
//
// Time Complexity: O((sum - max) * n) -> Inefficient


// 3. Optimized Solution (Binary Search on Answer)
// -----------------------------------------------
//
// Monotonic Property:
// - If capacity = X works (can ship in <= D days), then any capacity > X will also work
// - If capacity = X does not work, any capacity < X will also not work
//
// So, we can binary search for the minimum valid capacity.
//
// Binary Search Steps:
// 1. low = max(weights)
// 2. high = sum(weights)
// 3. while(low <= high):
//      mid = (low + high) / 2
//      if daysRequired(mid) <= D -> possible, search left (high = mid - 1)
//      else -> not possible, search right (low = mid + 1)
// 4. Answer = low


// 4. Helper Function
// ------------------
//
// daysRequired(weights, capacity):
// - Iterate through all packages
// - Keep a running load sum
// - If adding current package exceeds capacity:
//      increment days, reset load = current package
// - Else add package to load
// - Return total days used
//
// Time Complexity: O(n)
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate days required for a given capacity
int daysRequired(vector<int>& weights, int capacity) {
    int days = 1, load = 0;
    for(int w : weights) {
        if(load + w > capacity) {
            days++;          // new day
            load = w;        // start with current package
        } else {
            load += w;       // add to today's load
        }
    }
    return days;
}

// Main function: Binary Search on capacity
int shipWithinDays(vector<int>& weights, int D) {
    int low = *max_element(weights.begin(), weights.end());  // min capacity
    int high = accumulate(weights.begin(), weights.end(), 0); // max capacity

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(daysRequired(weights, mid) <= D) {
            high = mid - 1;   // try smaller capacity
        } else {
            low = mid + 1;    // need larger capacity
        }
    }
    return low; // minimum capacity that works
}

// Time Complexity: O(n * log(sum(weights) - max(weights)))
// Space Complexity: O(1)


// 5. Example Usage
// ----------------
int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int D = 5;

    cout << "Least capacity required: " << shipWithinDays(weights, D) << endl;
    // Expected Output: 15
    return 0;
}
