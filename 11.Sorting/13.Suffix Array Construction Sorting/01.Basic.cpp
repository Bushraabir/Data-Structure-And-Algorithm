/*  
Suffix Array is a sorted array of all suffixes of a given string.  
It is a fundamental data structure in string processing, often used in:  
- Pattern matching (like substring search)  
- Longest repeated substring problems  
- Data compression algorithms (e.g., BWT in bzip2)  

Definition:
For a string S of length N, the suffix array stores indices of all suffixes sorted in lexicographical order.  
Example:  
S = "banana"  
Suffixes:  
0: banana  
1: anana  
2: nana  
3: ana  
4: na  
5: a  
Sorted suffixes:  
5: a  
3: ana  
1: anana  
0: banana  
4: na  
2: nana  
Suffix array: [5, 3, 1, 0, 4, 2]  

Working Principle (Naive Sorting Method):
1. Generate all suffixes of the string with their starting indices.
2. Sort the suffixes lexicographically (using comparison of substrings).
3. Store only the starting indices of sorted suffixes → This is the suffix array.

Time Complexity:
    - O(N^2 log N) → N suffixes, each comparison may take O(N), sorted in O(N log N).
    - Not efficient for large strings (better algorithms exist: O(N log N) or O(N)).
Space Complexity:
    - O(N) for storing suffix array and temporary suffixes.

Stable Sort: Not required (sorting based on lexicographic order of suffixes)
Adaptive: No
Constraints:
- Works for any string
- Slower than optimized suffix array algorithms for large inputs
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to store suffix and its original index
struct Suffix {
    string suffix;
    int index;
};

// Comparator to sort suffixes lexicographically
bool compareSuffix(const Suffix& a, const Suffix& b) {
    return a.suffix < b.suffix;
}

// Function to build suffix array using sorting
vector<int> buildSuffixArray(const string& text) {
    int n = text.size();
    vector<Suffix> suffixes(n);

    // Step 1: Create all suffixes
    for (int i = 0; i < n; i++) {
        suffixes[i].suffix = text.substr(i);
        suffixes[i].index = i;
    }

    // Step 2: Sort suffixes lexicographically
    sort(suffixes.begin(), suffixes.end(), compareSuffix);

    // Step 3: Extract and return starting indices
    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}

int main() {
    string text = "banana";

    cout << "Original string: " << text << "\n\n";

    vector<int> suffixArray = buildSuffixArray(text);

    cout << "Suffix Array:\n";
    for (int idx : suffixArray) {
        cout << idx << " ";
    }
    cout << "\n\n";

    cout << "Sorted Suffixes:\n";
    for (int idx : suffixArray) {
        cout << idx << ": " << text.substr(idx) << "\n";
    }

    return 0;
}

/*
Example Dry Run:
----------------
Input: "banana"
All suffixes:
0: banana
1: anana
2: nana
3: ana
4: na
5: a

Sorted suffixes:
5: a
3: ana
1: anana
0: banana
4: na
2: nana

Suffix Array = [5, 3, 1, 0, 4, 2]
*/
