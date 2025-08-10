// Pairs in C++ are part of the utility library in the Standard Template Library (STL).
// They store two values together. This example demonstrates basic pair usage including
// creation, access, nesting, and using arrays of pairs.

#include <iostream>
#include <utility>
using namespace std;

int main() {
    // Pair Declaration 
    pair<int, int> p1 = {1, 3};

    // Pair access
    cout << "First element of p1: " << p1.first << endl;
    cout << "Second element of p1: " << p1.second << endl;

    // pair to store a student's name and age
    pair<string, int> student_info = {"Alice", 20};
    cout << "Student Name: " << student_info.first << ", Age: " << student_info.second << endl;

    cout << endl;

    // Nested Pairs
    pair<int, pair<int, int>> p_nested = {1, {3, 4}};

    // Access and print elements of the nested pair
    cout << "First element of p_nested: " << p_nested.first << endl;
    cout << "Second pair's first element (3): " << p_nested.second.first << endl;
    cout << "Second pair's second element (4): " << p_nested.second.second << endl;

    // Store 3D coordinates using nested pairs: (x, (y, z))
    pair<int, pair<int, int>> coordinates = {10, {20, 30}};
    cout << "X coordinate: " << coordinates.first << endl;
    cout << "Y coordinate: " << coordinates.second.first << endl;
    cout << "Z coordinate: " << coordinates.second.second << endl;

    cout << endl;

    // Pair Array Example
    // Declare and initialize an array of pairs
     pair<int, int> pair_array[] = { {10, 20}, {30, 40}, {50, 60} };

    // Access a specific pair from the array
    pair<int, int> specific_pair = pair_array[1];
    cout << "Pair at index 1: (" << specific_pair.first << ", " << specific_pair.second << ")" << endl;

    // Access second element of the pair at index 2 directly
    cout << "Second element of pair at index 2: " << pair_array[2].second << endl;

    // Access first element of the pair at index 0
    cout << "First element of pair at index 0: " << pair_array[0].first << endl;

    cout << endl;

    return 0;
}
