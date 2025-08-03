/*  
Bucket Sort is a comparison-based sorting algorithm mainly used for sorting floating-point numbers or integers uniformly distributed over a range.
It distributes the elements into several "buckets," sorts each bucket individually (using another sorting algorithm or recursively), and then concatenates all buckets to form the sorted array.

Working Principle:
- Create a fixed number of empty buckets.
- Scatter all elements of the input array into these buckets based on their value.
- Sort each non-empty bucket individually.
- Concatenate all sorted buckets to get the final sorted array.

Time Complexity:
    - Best Case: O(N + K) (When elements are uniformly distributed and buckets are evenly filled)
    - Average Case: O(N + K + N log(N/K)) (Where K is number of buckets)
    - Worst Case: O(N^2) (When all elements go into one bucket)

Space Complexity:
    - O(N + K) (Extra space for buckets)

Stable Sort: Yes (If the sorting used within buckets is stable)
Adaptive: Yes (Efficient when input is uniformly distributed)

Note:
- Bucket sort is most efficient when input is uniformly distributed over a range.
- Commonly used for sorting floating-point numbers between 0 and 1.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

// Bucket Sort function
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 1) Create empty buckets
    vector<vector<float>> buckets(n);

    // 2) Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Assuming arr[i] in range [0,1)
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};

    cout << "Original array:\n";
    for (float val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    bucketSort(arr);

    cout << "Sorted array using Bucket Sort:\n";
    for (float val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
