# Day 4 - Sum-based Problems

## 1. Trapping Rain Water (LeetCode)
This problem calculates the total water trapped between the heights of bars after rainfall.

### Approach:
1. Identify the highest bar (`maxHeight`) and its index (`index`).
2. Traverse left from `0` to `index` using `leftMax` to track max height and compute trapped water.
3. Traverse right from `n-1` to `index` using `rightMax` and compute trapped water.

### Code:
```cpp
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int leftMax = 0, rightMax = 0, water = 0, maxHeight = height[0], index = 0;

    // Find the highest bar
    for (int i = 1; i < n; i++) {
        if (height[i] > maxHeight) {
            maxHeight = height[i];
            index = i;
        }
    }

    // Compute left side trapped water
    for (int i = 0; i < index; i++) {
        if (leftMax > height[i])
            water += leftMax - height[i];
        else
            leftMax = height[i];
    }

    // Compute right side trapped water
    for (int i = n - 1; i > index; i--) {
        if (rightMax > height[i])
            water += rightMax - height[i];
        else
            rightMax = height[i];
    }

    return water;
}
```

---

## 2. Triplet Sum in Array
Finds if there exist three numbers in an array that sum to a given target.

### Approach:
1. Sort the array.
2. Fix one element and use the **two-pointer technique** to find if there is a valid pair that sums up to `target - arr[i]`.

### Code:
```cpp
#include <vector>
#include <algorithm>
using namespace std;

bool hasTripletSum(vector<int>& arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 2; i++) {
        int ans = target - arr[i];
        int start = i + 1, end = n - 1;
        
        while (start < end) {
            if (arr[start] + arr[end] == ans)
                return true;
            else if (arr[start] + arr[end] > ans)
                end--;
            else
                start++;
        }
    }
    return false;
}
```

---

## 3. 4-Sum Problem
 i will add soon
```

---

These solutions efficiently solve sum-related problems using sorting and the two-pointer technique. 🚀