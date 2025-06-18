// Vectors in C++ are dynamic arrays provided by the Standard Template Library (STL).
// This example demonstrates various vector operations: creation, modification, iteration, and advanced uses.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    // Section 1: Basic Vector Declaration and Initialization
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    cout << "Vector v1 elements: ";
    for (int i = 0; i < v1.size(); ++i) cout << v1[i] << " ";
    cout << endl;

    vector<int> v2;
    v2.emplace_back(100);
    v2.emplace_back(200);

    cout << "Vector v2 elements: ";
    for (int x : v2) cout << x << " ";
    cout << endl << endl;

    // Section 2: Vector with Size and Values
    vector<int> v3(5);
    vector<int> v4(5, 100);

    cout << "v3: "; for (int x : v3) cout << x << " "; cout << endl;
    cout << "v4: "; for (int x : v4) cout << x << " "; cout << endl;

    vector<int> myVec(3);
    myVec.push_back(50);
    cout << "myVec: "; for (int x : myVec) cout << x << " "; cout << " (size: " << myVec.size() << ")\n\n";

    // Section 3: Copy Vectors
    vector<int> v5(v4);
    cout << "v5: "; for (int x : v5) cout << x << " "; cout << endl << endl;

    // Section 4: Iterators
    vector<int> v_iter = {10, 20, 30, 40, 50};
    auto it = v_iter.begin();
    cout << "*(it): " << *it << endl;
    it++;
    cout << "*(it++): " << *it << endl;
    it = it + 2;
    cout << "*(it + 2): " << *it << endl;

    cout << "v_iter: ";
    for (auto current_it = v_iter.begin(); current_it != v_iter.end(); current_it++) cout << *current_it << " ";
    cout << endl;

    cout << "*(v_iter.begin() + 4): " << *(v_iter.begin() + 4) << endl << endl;

    // Section 5: Deletion
    vector<int> v_del = {10, 20, 30, 40, 50};
    v_del.erase(v_del.begin() + 1);
    v_del.erase(v_del.begin() + 1, v_del.begin() + 3);

    cout << "v_del: "; for (int x : v_del) cout << x << " "; cout << endl;

    vector<int> v_pop = {1, 2, 3, 4, 5};
    v_pop.pop_back();
    cout << "v_pop: "; for (int x : v_pop) cout << x << " "; cout << endl << endl;

    // Section 6: Insertion
    vector<int> v_ins = {10, 20, 30, 40};
    v_ins.insert(v_ins.begin(), 5);
    v_ins.insert(v_ins.begin() + 1, 2, 100);

    vector<int> copy_vec = {500, 600};
    v_ins.insert(v_ins.end(), copy_vec.begin(), copy_vec.end());

    cout << "v_ins: "; for (int x : v_ins) cout << x << " "; cout << endl;

    vector<int> data = {1, 2, 3};
    data.insert(data.begin() + 1, 99);
    cout << "data: "; for (int x : data) cout << x << " "; cout << endl << endl;

    // Section 7: Other Functions
    vector<int> v_misc = {1, 2, 3, 4, 5};
    vector<int> v_other = {10, 20, 30};

    cout << "Size: " << v_misc.size() << endl;
    cout << "Back: " << v_misc.back() << endl;
    cout << "Front: " << v_misc.front() << endl;

    v_misc.swap(v_other);
    cout << "After swap, v_misc: "; for (int x : v_misc) cout << x << " "; cout << endl;
    cout << "v_other: "; for (int x : v_other) cout << x << " "; cout << endl;

    v_misc.clear();
    cout << "v_misc size after clear(): " << v_misc.size() << endl;
    cout << "Is v_misc empty? " << (v_misc.empty() ? "Yes" : "No") << endl;
    cout << "Is v_other empty? " << (v_other.empty() ? "Yes" : "No") << endl << endl;

    // Section 8: Vector of Pairs
    vector<pair<int, string>> vp;
    vp.push_back({1, "apple"});
    vp.push_back({2, "banana"});
    vp.emplace_back(3, "cherry");

    cout << "Vector of pairs: ";
    for (const auto& p : vp) cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;

    return 0;
}