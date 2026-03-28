/*
Problem: Generate All Subsequences of an Array Using Recursion

You are given an array of integers. Your task is to print **all possible subsequences**
(including the empty one) by using recursion.

A subsequence:
- Follows the original order of elements (you cannot rearrange)
- Can be contiguous or non-contiguous
- Total number of subsequences for size n = 2^n

Example:
Input: arr = [3, 1, 2]
Output:
        {}
        {2}
        {1}
        {1 2}
        {3}
        {3 2}
        {3 1}
        {3 1 2}
                    (Printed in recursive order)

Time Complexity: O(2^n * n)
Space Complexity: O(n) recursion depth
*/

#include <iostream>
#include <vector>
using namespace std;

/*

- We recursively decide for each element whether to include it or not.
- Each decision forms a branch in the recursion tree.
- To backtrack after "taking" an element, we pop it from the current path.
- Passing the 'ds' (data structure) by reference avoids unnecessary copies.

    tree structure for arr = [3, 1, 2]:

                             []
                          /     \
                        3        []
                      / \      / \
                    1   []    1  []
                   / \       / \
                 2    []    2  []
                / \        / \
              []   []     [] []

*/

void printSubsequences(int index, vector<int>& ds, vector<int>& arr, int n) { // -> index: current index in arr, ds: current subsequence, arr: input array, n: size of arr
    if (index == n) { // Base case: if we've considered all elements

        if (ds.size() == 0)
            cout << "{}"; // print empty subsequence
        else {
            for (int num : ds) {
                cout << num << " ";
            }
        }
        cout << endl;
        return;
    }

    // Take the current element
    ds.push_back(arr[index]);
    printSubsequences(index + 1, ds, arr, n);

    // Not take the current element (backtrack)
    ds.pop_back();

    // Move to the next element without including the current one
    printSubsequences(index + 1, ds, arr, n);
}

int main() {
    vector<int> arr = {3, 1, 2};
    int n = arr.size();
    vector<int> ds;

    cout << "All Subsequences of the Array:" << endl;
    printSubsequences(0, ds, arr, n);

    return 0;
}
// Time Complexity: O(2^n * n) (2^n for subsequences, n for printing each subsequence)
// Space Complexity: O(n) (due to recursion stack and temporary storage for subsequences)

// u can also solve this problem using bit manipulation
// but this is a more intuitive recursive approach that clearly shows the decision-making process.  
// u can also use powerset concept to solve this problem