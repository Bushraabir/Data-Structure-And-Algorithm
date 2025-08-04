/*
 * Problem Statement: Palindrome Partitioning
 *
 * You are given a string s. Your task is to partition s into substrings such that
 * every substring is a palindrome. Return all possible palindrome partitionings.
 *
 * Conditions:
 * - A palindrome reads the same backward and forward (e.g., "aba", "racecar").
 * - You must find every way to split s into palindromic substrings.
 *
 * Approach: Backtracking with Recursion
 * - We build partitions by choosing a palindromic prefix at each step.
 * - Recurse on the remaining suffix.
 * - Use an isPalindrome helper to prune invalid prefixes.
 * - Backtrack by removing the last chosen substring and trying a longer prefix.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Check if s[l..r] is a palindrome in O(length) time.
bool isPalindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) 
            return false;
    }
    return true;
}

// Backtracking helper:
//  • idx: the current start index in s to partition
//  • path: the substrings chosen so far
//  • result: collects all full partitions
void dfs(const string &s, int idx, vector<string> &path, vector<vector<string>> &result) {
    int n = s.size();
    // Base case: reached end of string → one complete partition
    if (idx == n) {
        result.push_back(path);
        return;
    }
    // Try every end position for the next substring
    for (int end = idx; end < n; ++end) {
        // Only proceed if s[idx..end] is a palindrome
        if (isPalindrome(s, idx, end)) {
            // Choose this palindrome substring
            path.push_back(s.substr(idx, end - idx + 1));
            // Recurse on the remaining suffix
            dfs(s, end + 1, path, result);
            // Backtrack: remove the last choice and try a longer substring
            path.pop_back();
        }
    }
}

// Public API:
//  • Calls dfs starting at index 0 and returns all palindrome partitions.
vector<vector<string>> partition(const string &s) {
    vector<vector<string>> result;
    vector<string> path;
    dfs(s, 0, path, result);
    return result;
}

int main() {
    string s = "aabb";
    auto partitions = partition(s);

    cout << "All palindrome partitions of \"" << s << "\":\n";
    for (auto &list : partitions) {
        cout << "[ ";
        for (auto &seg : list) {
            cout << "\"" << seg << "\" ";
        }
        cout << "]\n";
    }
    return 0;
}
