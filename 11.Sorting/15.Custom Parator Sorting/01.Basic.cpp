/*  
Custom Comparator Sorting allows you to define your own rules for comparing elements  
instead of relying on the default `<` operator.  
It is widely used when:  
- Sorting in descending order  
- Sorting based on multiple fields (e.g., sort by age, then by name)  
- Sorting complex data types (structures, classes)  
- Applying domain-specific ordering rules  

Definition:
A comparator is a function (or lambda) that takes two elements as input and returns:
    - `true` if the first should come before the second in the sorted order
    - `false` otherwise  

Example:
Given an array of people `{name, age}`,  
- Default sort: alphabetical by name (if `<` defined)  
- Custom comparator: sort by age descending, and if equal, by name ascending  

Working Principle:
1. Define a comparison function (either a separate function, lambda, or functor).
2. Pass it as the third argument to `std::sort` (or any sorting algorithm that supports comparators).
3. The sorting algorithm will use this comparator to determine ordering instead of the default `<`.

Time Complexity:
    - Same as the sorting algorithm used (e.g., `std::sort` → O(N log N)).
Space Complexity:
    - O(1) for in-place sort (not counting input storage).

Stable Sort:
    - Use `std::stable_sort` if stability (preserving relative order of equal elements) is required.
Adaptive: No

Constraints:
- Comparator must define a **strict weak ordering** to avoid undefined behavior.
- Should not cause side effects (modifying elements while comparing).
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int age;
};

// Custom comparator: Sort by age descending, then name ascending
bool customCompare(const Person &a, const Person &b) {
    if (a.age != b.age)
        return a.age > b.age;  // Higher age comes first
    return a.name < b.name;    // If age equal → sort by name ascending
}

int main() {
    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 30},
        {"Dave", 25},
        {"Eve", 35}
    };

    cout << "Original list:\n";
    for (auto &p : people) {
        cout << p.name << " (" << p.age << ")\n";
    }
    cout << "\n";

    // Sort using custom comparator
    sort(people.begin(), people.end(), customCompare);

    cout << "Sorted list (Age Desc, Name Asc):\n";
    for (auto &p : people) {
        cout << p.name << " (" << p.age << ")\n";
    }

    return 0;
}

/*
Example Dry Run:
----------------
Original list:
Alice (30)
Bob (25)
Charlie (30)
Dave (25)
Eve (35)

Step 1: Sort by age descending
    Eve (35)
    Alice (30)
    Charlie (30)
    Bob (25)
    Dave (25)

Step 2: If ages are equal → sort by name ascending
    Eve (35)
    Alice (30)
    Charlie (30)
    Bob (25)
    Dave (25)

Final order:
Eve (35)
Alice (30)
Charlie (30)
Bob (25)
Dave (25)
*/
