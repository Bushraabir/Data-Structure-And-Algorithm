// Filename: TrappingRainwater.cpp

/*
 * Problem Statement: Trapping Rainwater
 *
 * You are given an array of non-negative integers where each element represents the height of a building. 
 * When it rains, water can get trapped between these buildings. Your task is to compute how many units of water 
 * can be trapped between the buildings.
 *
 * Conditions for Water Trapping:
 * - Water can only be trapped between buildings if there exists a taller building on the left and a taller one on the right.
 * - For any given position i, if the building at index i is shorter than the tallest to its left and right,
 *   water may be trapped above it.
 * - The amount of water trapped at position i is given by:
 *     water_at_i = min(leftMax, rightMax) - height[i]
 *
 * We'll implement two solutions here:
 *
 * Approach 1: Prefix and Suffix Maximum Arrays (Brute-force optimized)
 * Approach 2: Two-Pointer Technique (Space optimized)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Prefix and Suffix Maximum Arrays
int trapRainwater_PrefixSuffix(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    // Step 1: Create prefix and suffix max arrays
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    // Step 2: Compute prefix max
    prefixMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], height[i]);
    }

    // Step 3: Compute suffix max
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    // Step 4: Calculate water trapped
    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        int minHeight = min(prefixMax[i], suffixMax[i]);
        if (minHeight > height[i]) {
            totalWater += minHeight - height[i];
        }
    }

    return totalWater;
}

/*
 * Approach 2: Two-Pointer Technique
 * 
 * This approach reduces the space complexity to O(1) using two pointers.
 *
 * Logic:
 * - We maintain two pointers, one from the left (L) and one from the right (R).
 * - We also keep track of the maximum height seen so far from the left (leftMax) and right (rightMax).
 * - The side with the smaller height dictates how much water can be trapped because that will overflow first.
 *
 * Why does this work?
 * - If height[L] < height[R], then the maximum trapped water at L depends only on leftMax, not rightMax.
 *   Because height[R] is higher and ensures a boundary from the right.
 * - Conversely, if height[R] < height[L], water trapped at R depends on rightMax only.
 */
int trapRainwater_TwoPointer(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            // We are on the smaller/equal side
            if (height[left] >= leftMax) {
                // Update leftMax if current is greater
                leftMax = height[left];
            } else {
                // Water can be trapped here
                totalWater += leftMax - height[left];
            }
            left++;
        } else {
            // We are on the smaller side from the right
            if (height[right] >= rightMax) {
                // Update rightMax if current is greater
                rightMax = height[right];
            } else {
                // Water can be trapped here
                totalWater += rightMax - height[right];
            }
            right--;
        }
    }

    return totalWater;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Using Prefix/Suffix Approach: " << trapRainwater_PrefixSuffix(height) << endl;
    cout << "Using Two-Pointer Approach: " << trapRainwater_TwoPointer(height) << endl;

    return 0;
}
