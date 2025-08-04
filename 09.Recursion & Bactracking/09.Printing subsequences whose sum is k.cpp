/*
You are given an array of integers and a target sum `K`. Your task is to explore the three most common recursive patterns using the "take or not take" approach:

1. Print **all subsequences** whose sum is equal to K.
2. Print **only one** such subsequence.
3. **Count** all subsequences whose sum is equal to K.

Example:
Input: arr = {1, 2, 1}, k = 2
Output:
1. All subsequences with sum 2:
   {1, 1}
   {2}

2. One subsequence with sum 2:
   {1, 1}   (or {2}, depending on order)

3. Count:
   2

Approach: Recursion with "Take or Not Take" strategy
*/

#include <iostream>
#include <vector>
using namespace std;

/*
I. Print All Subsequences with Sum = K
- Carry along the current sum `s` and current subsequence `ds`
- Base case: if index == n and sum == K, print `ds`
- Recursively explore both choices: take or not take current element
*/

void printAllSubsequences(int index, vector<int>& ds, int s, int k, vector<int>& arr, int n) {
    if (index == n) {
        if (s == k) {
            // print the current subsequence
            cout << "{ ";
            for (int num : ds) cout << num << " ";// printing all num of ds
            cout << "}" << endl;
        }
        return;
    }

    // Take current element
    ds.push_back(arr[index]);
    s += arr[index];
    printAllSubsequences(index + 1, ds, s, k, arr, n);
    
    // Backtrack
    ds.pop_back();
    s -= arr[index];

    // Not take current element
    printAllSubsequences(index + 1, ds, s, k, arr, n);
}

/*
II. Print Only One Subsequence with Sum = K
- Instead of printing all, we return `true` from the first successful path
- Use function return value as flag to stop further recursive calls
*/

bool printOneSubsequence(int index, vector<int>& ds, int s, int k, vector<int>& arr, int n) {
    if (index == n) {
        if (s == k) {
            cout << "One subsequence with sum = " << k << " is: { ";
            for (int num : ds) cout << num << " ";
            cout << "}" << endl;
            return true;
        }
        return false;
    }

    // Take current element
    ds.push_back(arr[index]);
    s += arr[index];
    if (printOneSubsequence(index + 1, ds, s, k, arr, n)) return true;

    // Backtrack
    ds.pop_back();
    s -= arr[index];

    // Not take current element
    if (printOneSubsequence(index + 1, ds, s, k, arr, n)) return true;

    return false;
}

/*
III. Count All Subsequences with Sum = K
- We no longer need to store or print the subsequence
- Just return 1 when base case hits sum == k, else return 0
*/

int countSubsequences(int index, int s, int k, vector<int>& arr, int n) {
    if (index == n) {
        return s == k ? 1 : 0;
    }

    // Take current element
    s += arr[index];
    int leftCount = countSubsequences(index + 1, s, k, arr, n);
    s -= arr[index]; // backtrack

    // Not take current element
    int rightCount = countSubsequences(index + 1, s, k, arr, n);

    return leftCount + rightCount;
}

int main() {
    vector<int> arr = {1, 2, 1};
    int k = 2;
    int n = arr.size();
    vector<int> ds;

    cout << "I. All Subsequences with Sum = " << k << ":\n";
    printAllSubsequences(0, ds, 0, k, arr, n);
    cout << endl;

    cout << "II. One Subsequence with Sum = " << k << ":\n";
    printOneSubsequence(0, ds, 0, k, arr, n);
    cout << endl;

    cout << "III. Count of Subsequences with Sum = " << k << ": ";
    int total = countSubsequences(0, 0, k, arr, n);
    cout << total << endl;

    return 0;
}
