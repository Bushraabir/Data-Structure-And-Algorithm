// Hashing in C++ demonstrates efficient frequency counting and lookups
// using simple arrays for small ranges, character hashing via ASCII mapping,
// and flexible key-value storage with std::map and std::unordered_map.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // 1. Number Hashing with an Array (for small max values)
    // Suppose we know all values in arr1 are in [0, 100].
    vector<int> arr1 = {1, 4, 2, 1, 3, 4, 1};
    const int MAX_VAL = 100;
    vector<int> freqNum(MAX_VAL + 1, 0);  // frequency array initialized to 0

    // Pre-computation: count each occurrence in O(N)
    for (int x : arr1) {
        freqNum[x]++;
    }

    // Fetching: O(1) per query
    int query1 = 1;
    cout << "Frequency of " << query1 << " is " << freqNum[query1] << endl;  
    // Output: Frequency of 1 is 3

    cout << endl;

    // 2. Character Hashing with an Array (ASCII-based)
    string s = "Hello, World!";
    vector<int> freqChar(256, 0);  // covers all ASCII characters

    // Pre-computation
    for (char c : s) {
        freqChar[static_cast<unsigned char>(c)]++;
    }

    // Fetching: direct access by ASCII code
    char queryChar = 'o';
    cout << "Frequency of '" << queryChar << "' is " 
         << freqChar[static_cast<unsigned char>(queryChar)] << endl;
    // Output: Frequency of 'o' is 2

    cout << endl;

    // 3. Hashing with std::unordered_map (for large or sparse keys)
    // Handles keys up to 1e12 or arbitrary types (e.g., string).
    vector<long long> arr2 = {1000000001LL, 42LL, 1000000001LL, 7LL};
    unordered_map<long long, int> umap;

    // Pre-computation in average O(N)
    for (long long x : arr2) {
        umap[x]++;
    }

    // Fetching average O(1)
    long long query2 = 1000000001LL;
    cout << "Frequency of " << query2 << " is " << umap[query2] << endl;
    // Output: Frequency of 1000000001 is 2

    cout << endl;

    // 4. Sorted-Key Storage with std::map (logarithmic operations, keeps keys ordered)
    map<string, int> sortedMap;
    sortedMap["apple"] = 3;
    sortedMap["banana"] = 2;
    sortedMap["cherry"] = 5;

    // Accessing elements in O(log N)
    cout << "Apple count: " << sortedMap["apple"] << endl;
    cout << "Banana count: " << sortedMap["banana"] << endl;

    cout << "\nIterating in sorted order:\n";
    for (const auto& kv : sortedMap) {
        cout << kv.first << " -> " << kv.second << endl;
    }
    // Outputs keys in alphabetical order: apple, banana, cherry

    cout << endl;
    return 0;
}
