# Proper Notes for STL Vector Operations

### Declaration of Vector:
To use vectors, include the header file:
```cpp
#include <vector>
```
Declare a vector:
```cpp
vector<int> v; // Empty vector
vector<int> v1(5, 1); // Vector with 5 elements, all initialized to 1
vector<int> v2 = {1, 2, 3, 4, 5}; // Vector with elements 1, 2, 3, 4, 5
```

### Adding and Removing Elements:
- **Add element to the end**:
```cpp
v.push_back(10); // Adds 10 to the end of the vector
```
- **Remove last element**:
```cpp
v.pop_back(); // Removes the last element
```

### Size and Capacity:
- **Get the number of elements**:
```cpp
cout << "Vector size: " << v.size() << endl;
```
- **Get the current capacity**:
```cpp
cout << "Vector capacity: " << v.capacity() << endl;
```

### Accessing Elements:
- **Using index**:
```cpp
cout << v[0]; // First element
```
- **Using functions**:
```cpp
cout << v.front(); // First element
cout << v.back();  // Last element
cout << v.at(2);   // Element at index 2
```

### Iterating Over a Vector:
- **Using a for loop**:
```cpp
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```
- **Using range-based for loop**:
```cpp
for (auto i : v) {
    cout << i << " ";
}
```
- **Using iterators**:
```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

### Modifying a Vector:
- **Insert element at a specific position**:
```cpp
v.insert(v.begin() + 2, 20); // Inserts 20 at index 2
```
- **Erase an element at a specific position**:
```cpp
v.erase(v.begin() + 2); // Removes the element at index 2
```
- **Clear all elements**:
```cpp
v.clear(); // Removes all elements
```

### Sorting a Vector:
- **Sort in ascending order**:
```cpp
sort(v.begin(), v.end());
```
- **Sort in descending order**:
```cpp
sort(v.rbegin(), v.rend());
```

### Searching in a Vector:
- **Binary search** (vector must be sorted):
```cpp
bool found = binary_search(v.begin(), v.end(), value);
cout << (found ? "Found" : "Not Found");
```
- **Find index of an element**:
```cpp
auto it = find(v.begin(), v.end(), value);
if (it != v.end()) {
    cout << "Found at index: " << (it - v.begin());
} else {
    cout << "Not Found";
}
```

### Counting and Bounds:
- **Count occurrences of an element**:
```cpp
int count_val = count(v.begin(), v.end(), value);
cout << "Count: " << count_val;
```
- **Find maximum and minimum elements**:
```cpp
int max_val = *max_element(v.begin(), v.end());
int min_val = *min_element(v.begin(), v.end());
```
- **Lower bound** (first element >= value):
```cpp
auto lb = lower_bound(v.begin(), v.end(), value);
cout << "Lower Bound Index: " << (lb - v.begin());
```
- **Upper bound** (first element > value):
```cpp
auto ub = upper_bound(v.begin(), v.end(), value);
cout << "Upper Bound Index: " << (ub - v.begin());
```

### Example Code:
Here is an example of how to use vectors:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // Add elements
    v.push_back(60);

    // Print elements
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    // Sort and find
    sort(v.begin(), v.end());
    bool found = binary_search(v.begin(), v.end(), 30);
    cout << (found ? "Found 30" : "30 Not Found") << endl;

    return 0;
}
```
