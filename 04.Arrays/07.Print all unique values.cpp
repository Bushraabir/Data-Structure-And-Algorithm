
// The programme prints all unique values in an array using an unordered_map.
// Instead of using nested loops (O(n^2) complexity), we count the frequency of each element in O(n) time,
// and then print the elements that appear exactly once.

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int a[] = {1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    unordered_map<int, int> freq;

    // Count frequency of each element in the array
    for (int i = 0; i < size; i++) {
        freq[a[i]]++;
    }

    cout << "Unique values in the array: ";
    // Iterate through the frequency map to print unique elements
    for (auto &pair : freq) {
        if (pair.second == 1)
            cout << pair.first << " ";
    }
    cout << endl;
    
    return 0;
}
