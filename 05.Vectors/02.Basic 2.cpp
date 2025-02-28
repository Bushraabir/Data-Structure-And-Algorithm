// Vectors offer many member functions to manage elements efficiently.
// This example demonstrates different ways of declaring vectors and uses the following functions:
// - size(): Returns the number of elements in the vector.
// - push_back(): Adds an element at the end of the vector.
// - pop_back(): Removes the last element from the vector.
// - front(): Returns the first element of the vector.
// - back(): Returns the last element of the vector.
// - at(): Provides access to an element with bounds checking.



//array--static allocation(during compile time)
//     --size is fixed
//      --stores in stack
//vector--dynamic allocation(during run time)
//      --scalable
//      -- stores in heap

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Declaring an empty vector of integers
    vector<int> vec1;

    // 2. Declaring a vector with a predefined size and initial value (size 5, all elements 0)
    vector<int> vec2(5, 0);

    // 3. Declaring a vector using an initializer list
    vector<int> vec3 = {10, 20, 30, 40, 50};

    // 4. Declaring a vector from an array
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec4(arr, arr + 5);

    // Using push_back() to add elements to vec1
    vec1.push_back(100);
    vec1.push_back(200);
    vec1.push_back(300);

    // Displaying the size of vec1 using size()
    cout << "Size of vec1: " << vec1.size() << endl;

    // Accessing elements using at() which performs bounds checking
    cout << "Element at index 0 in vec1: " << vec1.at(0) << endl;

    // Accessing the first element of vec3 using front()
    cout << "First element in vec3 (front()): " << vec3.front() << endl;

    // Accessing the last element of vec3 using back()
    cout << "Last element in vec3 (back()): " << vec3.back() << endl;

    // Using pop_back() to remove the last element from vec1
    vec1.pop_back();

    // Displaying vec1 after pop_back()
    cout << "vec1 after pop_back(): ";
    for (int num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
