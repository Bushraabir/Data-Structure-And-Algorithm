// Vectors in C++ maintain two important properties:
//       - size(): The number of elements currently stored in the vector.
//       - capacity(): The total amount of space allocated for the vector, which can be larger than its size.
// Capacity helps avoid frequent reallocations when new elements are added.
// 
// Capacity gets doubled when the vector runs out of space, which is why it can be larger than the size.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    
    cout << "Initial vector size: " << vec.size() << endl;
    cout << "Initial vector capacity: " << vec.capacity() << endl;
    
    // Add elements to the vector and display the size and capacity after each insertion
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
        cout << "After adding " << i << ": size = " << vec.size() 
             << ", capacity = " << vec.capacity() << endl;
    }
    
    return 0;
}
