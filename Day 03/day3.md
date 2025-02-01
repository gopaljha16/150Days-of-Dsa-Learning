# Day 3: Prefix Sum, Kadane's Algorithm & Maximum Difference

## 1. **Prefix Sum**
### **Concept:**
The prefix sum is a technique used to preprocess an array for efficient range sum queries. The sum of any subarray can be quickly found using prefix sums.

### **Problem: Find if an array can be divided into two equal sum subarrays**
#### **Approach:**
- Compute the total sum of the array.
- Iterate through the array and keep track of the prefix sum.
- If at any index, `prefix sum * 2 == total sum`, then we can divide the array into two equal halves.

#### **Code:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool Divide(vector<int> &arr) {
    int prefix = 0, total_sum = 0, n = arr.size();
    
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        if (total_sum == 2 * prefix)
            return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> v(n);
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << (Divide(v) ? "Yes, it can be divided." : "No, it cannot be divided.") << endl;
}
```

## 2. **Kadane's Algorithm (Maximum Subarray Sum)**
### **Concept:**
Kadane's Algorithm efficiently finds the maximum sum of any contiguous subarray.

### **Approach:**
- Initialize `prefix = 0` and `maxi = INT_MIN`.
- Traverse the array, adding each element to `prefix`.
- Update `maxi` if `prefix` is greater.
- If `prefix` becomes negative, reset it to zero.

#### **Code:**
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int prefix = 0, maxi = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        maxi = max(maxi, prefix);
        if (prefix < 0) prefix = 0;
    }
    
    return maxi;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> v(n);
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << "Maximum subarray sum: " << maxSubarraySum(v) << endl;
    return 0;
}
```

## 3. **Maximum Difference Between Two Elements**
### **Concept:**
Find the maximum difference `arr[j] - arr[i]` such that `j > i`.

### **Approach:**
- Traverse the array while keeping track of the **minimum element so far**.
- Calculate the difference `arr[i] - min_element` and update the `max_diff` accordingly.

#### **Code:**
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxDifference(vector<int> &arr) {
    int min_element = INT_MAX;
    int max_diff = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        min_element = min(min_element, arr[i]);
        max_diff = max(max_diff, arr[i] - min_element);
    }
    return max_diff;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Maximum difference: " << maxDifference(v) << endl;
    return 0;
}
```

---
### **Summary:**
- **Prefix Sum** is useful for subarray sum calculations.
- **Kadane’s Algorithm** finds the maximum subarray sum in O(n).
- **Maximum Difference** keeps track of the minimum element and finds the best possible difference in O(n).

These techniques are fundamental for solving array-based problems efficiently. 🚀
