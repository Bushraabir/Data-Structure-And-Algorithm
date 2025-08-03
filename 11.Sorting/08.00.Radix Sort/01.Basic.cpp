/*  
Radix Sort is a non-comparison based sorting algorithm used to sort integers.
It sorts the numbers digit by digit starting from the least significant digit to the most significant digit using a stable sorting algorithm (commonly Counting Sort).

Working Principle:
- Find the maximum number to know the number of digits.
- Starting from the least significant digit (LSD), sort the array based on that digit using a stable sort.
- Move to the next significant digit and repeat the sorting process.
- Continue until all digits are processed.
- The array becomes fully sorted after processing all digits.

Time Complexity:
    - Best Case: O(d * (N + K))
    - Average Case: O(d * (N + K))
    - Worst Case: O(d * (N + K))
  (Where N is number of elements, K is range of digits [0-9], and d is number of digits in the max number)

Space Complexity:
    - O(N + K) (For temporary arrays used in counting sort for each digit)

Stable Sort: Yes (Relies on stable sorting for each digit)
Adaptive: No (Performs the same regardless of input order)
*/

#include <iostream>
#include <vector>
using namespace std;

// A utility function to get the digit at a specific place value
int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

// Counting Sort based on the digit represented by exp
void countingSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0}; // Since digits range from 0 to 9

    // Count occurrences of each digit at exp place
    for (int i = 0; i < n; i++) {
        int digit = getDigit(arr[i], exp);
        count[digit]++;
    }

    // Change count[i] so that it contains actual position of this digit in output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array from the end to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], exp);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to determine the number of digits
    int maxVal = arr[0];
    for (int val : arr) {
        if (val > maxVal) maxVal = val;
    }

    // Apply counting sort for every digit starting from LSD to MSD
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n\n";

    radixSort(arr);

    cout << "Sorted array using Radix Sort:\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
