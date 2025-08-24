#include <iostream>
#include <utility> // for pair
using namespace std;

int main() {
    /*

        - A pair is a container that stores two heterogeneous objects as a single unit.
        - Syntax: pair<T1, T2> p;
    */
    pair<int, int> p1 = {1, 3};

    // Access elements of the pair using .first and .second
    cout << "First element of p1: " << p1.first << endl;   // O(1) time, O(1) space
    cout << "Second element of p1: " << p1.second << endl; // O(1) time, O(1) space


    pair<string, int> student_info = {"Alice", 20};
    cout << "Student Name: " << student_info.first 
         << ", Age: " << student_info.second << endl; // O(1) time, O(1) space

    cout << endl;

    /*
        Nested Pairs
    */
    pair<int, pair<int, int>> p_nested = {1, {3, 4}};
    cout << "First element of p_nested: " << p_nested.first << endl;               // O(1)
    cout << "Second pair's first element (3): " << p_nested.second.first << endl;  // O(1)
    cout << "Second pair's second element (4): " << p_nested.second.second << endl;// O(1)

    // Store 3D coordinates (x, y, z) as (x, (y, z))
    pair<int, pair<int, int>> coordinates = {10, {20, 30}};
    cout << "X coordinate: " << coordinates.first << endl;          // O(1)
    cout << "Y coordinate: " << coordinates.second.first << endl;   // O(1)
    cout << "Z coordinate: " << coordinates.second.second << endl;  // O(1)

    cout << endl;

    /*
        
        Array of Pairs
    */
    pair<int, int> pair_array[] = { {10, 20}, {30, 40}, {50, 60} }; // size = 3

    // Accessing elements from the array of pairs
    pair<int, int> specific_pair = pair_array[1]; // Copying pair at index 1
    cout << "Pair at index 1: (" 
         << specific_pair.first << ", " << specific_pair.second << ")" << endl; // O(1)

    // Directly access the second element of pair at index 2
    cout << "Second element of pair at index 2: " 
         << pair_array[2].second << endl; // O(1)

    // Directly access the first element of pair at index 0
    cout << "First element of pair at index 0: " 
         << pair_array[0].first << endl; // O(1)

    cout << endl;

    /*
        Time Complexity Analysis
                - Pair creation: O(1)
                - Accessing elements (first, second): O(1)
                - Accessing nested pair elements: O(1)
                - Array of pairs access: O(1) per access
                    => Overall: O(1) operations throughout
        Space Complexity Analysis
                - pair<int,int>: stores 2 integers → O(1)
                - pair<string,int>: depends on string length (but string pointer is O(1) in pair)
                - nested pairs: still O(1), since constant number of integers
                - array of pairs (size = n): O(n), since stores 2n integers
                    => Overall space: O(n) (if array size = n), otherwise O(1) for individual pairs
    */

    return 0;
}
