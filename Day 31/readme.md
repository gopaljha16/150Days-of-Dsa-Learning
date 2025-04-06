Here's a complete and clear **GitHub-style note** for **Day 31: Binary Search in Recursion (including Linear Search)** with **code explanations, recursive trees, and base case reasoning**.

---

# 📘 Day 31: Recursion in Searching (Linear & Binary Search)

---

## 🔍 1. Linear Search Using Recursion

### ✅ Problem
Check if a given element `x` is present in an unsorted array using **recursive linear search**.

### 🧠 Logic
- Base Case: If `index == n`, element not found.
- If `arr[index] == x`, return `true`.
- Else, search in the rest of the array: `index + 1`.

### 📦 Code:
```cpp
#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int x, int index, int n) {
    // Base Case: reached end of array
    if (index == n)
        return false;

    // Match Found
    if (arr[index] == x)
        return true;

    // Recursive Call
    return LinearSearch(arr, x, index + 1, n);
}

int main() {
    int arr[] = {2, 4, 7, 3, 11, 8, 12};
    int x = 0;
    int n = 7;
    cout << LinearSearch(arr, x, 0, n);  // Output: 0
}
```

### 🌲 Recursive Tree Example
Searching `x = 8`:
```
LinearSearch(0) → arr[0] = 2 → Not Match → call LinearSearch(1)
LinearSearch(1) → arr[1] = 4 → Not Match → call LinearSearch(2)
LinearSearch(2) → arr[2] = 7 → Not Match → call LinearSearch(3)
LinearSearch(3) → arr[3] = 3 → Not Match → call LinearSearch(4)
LinearSearch(4) → arr[4] = 11 → Not Match → call LinearSearch(5)
LinearSearch(5) → arr[5] = 8 → ✅ Match → Return true
```

---

## 🚀 2. Binary Search Using Recursion

### ✅ Problem
Given a sorted (non-decreasing) array, use recursion to check whether an element exists.

### 🧠 Logic
- Base Case: If `start > end`, element is not found.
- Mid = `start + (end - start)/2`
  - If `arr[mid] == x`: return true.
  - If `arr[mid] > x`: search left sub-array.
  - Else: search right sub-array.

### 📦 Code:
```cpp
#include <iostream>
using namespace std;

bool Binarysearch(int arr[], int start, int end, int x) {
    // Base Case
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == x)
        return true;

    else if (arr[mid] > x)
        return Binarysearch(arr, start, mid - 1, x);
    else
        return Binarysearch(arr, mid + 1, end, x);
}

int main() {
    int arr[] = {3, 8, 11, 15, 20, 22};
    cout << Binarysearch(arr, 0, 5, 30);  // Output: 0
}
```

### 🌲 Recursive Tree Example
Searching for `x = 15`:
```
Binarysearch(0, 5) → mid = 2 → arr[2] = 11 < 15 → go right
Binarysearch(3, 5) → mid = 4 → arr[4] = 20 > 15 → go left
Binarysearch(3, 3) → mid = 3 → arr[3] = 15 ✅ Match
```

Searching for `x = 30`:
```
Binarysearch(0, 5) → mid = 2 → arr[2] = 11 < 30 → go right
Binarysearch(3, 5) → mid = 4 → arr[4] = 20 < 30 → go right
Binarysearch(5, 5) → mid = 5 → arr[5] = 22 < 30 → go right
Binarysearch(6, 5) → start > end → ❌ Return false
```

---

## 📌 Key Takeaways

| Topic           | Time Complexity | Notes                          |
|----------------|------------------|--------------------------------|
| Linear Search   | O(n)             | Works on unsorted arrays       |
| Binary Search   | O(log n)         | Requires sorted arrays         |

---
