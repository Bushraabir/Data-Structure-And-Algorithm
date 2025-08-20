// 1. Problem Introduction
// -----------------------
//
// Goal: Allocate `n` books (each with some pages) to `m` students such that
//       the **maximum number of pages assigned to any student** is minimized.
//
// Rules:
// - Each student gets at least one book
// - Each book is assigned to exactly one student
// - Allocation must be contiguous (no skipping books in between)
//
// Example: pages = [12, 34, 67, 90], m = 2
// - Allocation 1: [12, 34] | [67, 90] → max = 157
// - Allocation 2: [12] | [34, 67, 90] → max = 191
// - Allocation 3: [12, 34, 67] | [90] → max = 113
// → Answer = 113
//
// Constraints:
// - 1 ≤ n ≤ 10^5
// - 1 ≤ pages[i] ≤ 10^9
// - 1 ≤ m ≤ n
// - Return -1 if m > n


// 2. Brute Force (Linear Search on Answer)
// ----------------------------------------
//
// Idea:
// - Possible range of "maximum pages per student":
//   * low = max(pages)  (at least the largest single book)
//   * high = sum(pages) (all books to one student)
// - For each candidate X in [low, high]:
//   * Use helper `countStudents` to check how many students needed if
//     no student exceeds X pages
//   * If students_needed <= m → X is a possible answer
//   * Store best minimum
//
// Helper: countStudents(pages, X)
// - Greedily allocate books to students without exceeding X
// - If pages[i] > X → impossible, return large number
// - Return number of students required
//
// Time Complexity: O(N * (Sum - Max))
// Space Complexity: O(1)


#include <bits/stdc++.h>
using namespace std;

// Helper: number of students required if max pages allowed = maxPages
int countStudents(vector<int>& pages, int maxPages) {
    int students = 1;
    long long pagesSum = 0;

    for(int i = 0; i < pages.size(); i++) {
        if(pages[i] > maxPages) return INT_MAX; // impossible
        if(pagesSum + pages[i] <= maxPages) {
            pagesSum += pages[i];
        } else {
            students++;
            pagesSum = pages[i];
        }
    }
    return students;
}

// Brute force
int allocateBooksBrute(vector<int>& pages, int m) {
    int n = pages.size();
    if(m > n) return -1;

    int low = *max_element(pages.begin(), pages.end());
    long long high = accumulate(pages.begin(), pages.end(), 0LL);

    int ans = -1;
    for(long long x = low; x <= high; x++) {
        int students = countStudents(pages, x);
        if(students <= m) {
            ans = x;
            break; // first valid is min
        }
    }
    return ans;
}


// 3. Optimized Solution (Binary Search on Answer)
// ------------------------------------------------
//
// Key Insight:
// - If X pages allowed → k students needed
//   * Any value > X will need ≤ k students
//   * Any value < X will need ≥ k students
// - Monotonic property → Binary search
//
// Steps:
// 1. low = max(pages), high = sum(pages)
// 2. while(low <= high):
//      mid = (low + high) / 2
//      if countStudents(pages, mid) <= m:
//          ans = mid
//          high = mid - 1  // try smaller
//      else
//          low = mid + 1   // need to allow more pages
// 3. Return ans
//
// Time Complexity: O(N log(Sum - Max))
// Space Complexity: O(1)


int allocateBooks(vector<int>& pages, int m) {
    int n = pages.size();
    if(m > n) return -1;

    int low = *max_element(pages.begin(), pages.end());
    long long high = accumulate(pages.begin(), pages.end(), 0LL);
    int ans = -1;

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        int students = countStudents(pages, mid);

        if(students <= m) {
            ans = mid;
            high = mid - 1; // minimize further
        } else {
            low = mid + 1;  // need more pages allowance
        }
    }
    return ans;
}


// 4. Example Usage
// ----------------
int main() {
    vector<int> pages = {12, 34, 67, 90};
    int m = 2;

    cout << "Brute: " << allocateBooksBrute(pages, m) << endl;   // 113
    cout << "Binary Search: " << allocateBooks(pages, m) << endl; // 113

    return 0;
}

