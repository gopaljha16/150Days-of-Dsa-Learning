# Heap Problems: Find Median in Stream & Kth Smallest in Matrix

## Overview

This document explains two important heap-based algorithms:

1. **Find Median in a Stream**: Dynamically calculates the median as elements are added to a data stream using two heaps (max-heap and min-heap)
2. **Kth Smallest Element in Matrix**: Finds the kth smallest element in a sorted matrix using a min-heap with coordinate tracking

Both problems demonstrate advanced heap usage patterns and are commonly asked in technical interviews.

---

## Problem 1: Find Median in a Stream

### Problem Statement
Given a stream of integers, find the median after each element is added to the stream.

### Algorithm Explanation

#### Data Structures Used
```cpp
priority_queue<int> left;                                    // Max heap (stores smaller half)
priority_queue<int, vector<int>, greater<int>> right;       // Min heap (stores larger half)
vector<double> ans;                                          // Stores medians
```

#### Strategy
- **Left heap (max-heap)**: Stores the smaller half of numbers
- **Right heap (min-heap)**: Stores the larger half of numbers
- **Invariant**: `left.size()` should be equal to `right.size()` or `left.size() = right.size() + 1`

### Line-by-Line Code Explanation

```cpp
class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> left;                            // Max heap for smaller half
        priority_queue<int, vector<int>, greater<int>> right; // Min heap for larger half
        vector<double> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            // Handle first element
            if(left.empty()) {
                left.push(arr[i]);
                ans.push_back(left.top());
                continue;
            }
            
            // Decide which heap to insert into
            if(arr[i] > left.top()) {
                right.push(arr[i]);      // Element goes to larger half
            } else {
                left.push(arr[i]);       // Element goes to smaller half
            }
            
            // Balance the heaps
            if(right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            } else if(right.size() < left.size() - 1) {
                right.push(left.top());
                left.pop();
            }
            
            // Calculate median
            if(left.size() > right.size()) {
                ans.push_back(left.top());           // Odd number of elements
            } else {
                double median = (left.top() + right.top()) / 2.0;  // Even number of elements
                ans.push_back(median);
            }
        }
        return ans;
    }
};
```

### Step-by-Step Dry Run

**Input**: `arr = [5, 15, 1, 3]`

```
Step 1: Insert 5
├─ left = [5], right = []
├─ Median = 5
└─ ans = [5.0]

Step 2: Insert 15
├─ 15 > 5 (left.top()), so push to right
├─ left = [5], right = [15]
├─ Sizes are balanced
├─ Even count: median = (5 + 15) / 2 = 10.0
└─ ans = [5.0, 10.0]

Step 3: Insert 1
├─ 1 <= 5 (left.top()), so push to left
├─ left = [5, 1], right = [15]
├─ left.size() > right.size(), balanced
├─ Odd count: median = left.top() = 5
└─ ans = [5.0, 10.0, 5.0]

Step 4: Insert 3
├─ 3 <= 5 (left.top()), so push to left
├─ left = [5, 3, 1], right = [15]
├─ left.size() = 3, right.size() = 1, need rebalancing
├─ Move left.top() to right: left = [3, 1], right = [5, 15]
├─ Even count: median = (3 + 5) / 2 = 4.0
└─ ans = [5.0, 10.0, 5.0, 4.0]
```

### Heap State Visualization

```
After processing [5, 15, 1, 3]:

Left (Max Heap)     Right (Min Heap)
     3                   5
   /                   /
  1                   15

Median = (3 + 5) / 2 = 4.0
```

### Time and Space Complexity
- **Time Complexity**: O(n log n) - Each insertion and balancing takes O(log n)
- **Space Complexity**: O(n) - For storing elements in heaps

---

## Problem 2: Kth Smallest Element in Matrix

### Problem Statement
Given an n×n matrix where each row and column is sorted in ascending order, find the kth smallest element.

### Algorithm Explanation

#### Data Structure Used
```cpp
priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;
```

This creates a min-heap storing: `{value, {row, col}}`

#### Strategy
1. Insert the first element of each row into the min-heap
2. Extract minimum k times
3. Each time we extract, add the next element from the same row (if exists)

### Line-by-Line Code Explanation

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        
        // Create min heap: {value, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        
        // Insert first element of each row
        for(int i = 0; i < n; i++) {
            pq.push(make_pair(mat[i][0], make_pair(i, 0)));
        }
        
        int ans = -1;
        pair<int, pair<int, int>> element;
        int i, j;
        
        // Extract minimum k times
        while(k--) {
            element = pq.top();
            pq.pop();
            
            ans = element.first;                    // Current minimum value
            i = element.second.first;               // Row index
            j = element.second.second;              // Column index
            
            // Add next element from same row if exists
            if(j + 1 < n) {
                pq.push(make_pair(mat[i][j+1], make_pair(i, j+1)));
            }
        }
        
        return ans;
    }
};
```

### Step-by-Step Dry Run

**Input Matrix**:
```
mat = [
    [1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
]
k = 8
```

**Execution Steps**:

```
Initial Heap: {(1,{0,0}), (10,{1,0}), (12,{2,0})}

Step 1 (k=8): Extract (1,{0,0})
├─ ans = 1
├─ Add mat[0][1] = 5: heap = {(5,{0,1}), (10,{1,0}), (12,{2,0})}
└─ k = 7

Step 2 (k=7): Extract (5,{0,1})
├─ ans = 5
├─ Add mat[0][2] = 9: heap = {(9,{0,2}), (10,{1,0}), (12,{2,0})}
└─ k = 6

Step 3 (k=6): Extract (9,{0,2})
├─ ans = 9
├─ No more elements in row 0: heap = {(10,{1,0}), (12,{2,0})}
└─ k = 5

Step 4 (k=5): Extract (10,{1,0})
├─ ans = 10
├─ Add mat[1][1] = 11: heap = {(11,{1,1}), (12,{2,0})}
└─ k = 4

Step 5 (k=4): Extract (11,{1,1})
├─ ans = 11
├─ Add mat[1][2] = 13: heap = {(12,{2,0}), (13,{1,2})}
└─ k = 3

Step 6 (k=3): Extract (12,{2,0})
├─ ans = 12
├─ Add mat[2][1] = 13: heap = {(13,{1,2}), (13,{2,1})}
└─ k = 2

Step 7 (k=2): Extract (13,{1,2}) or (13,{2,1})
├─ ans = 13
├─ Add next element if available
└─ k = 1

Step 8 (k=1): Extract remaining
├─ ans = 13 (or 15 depending on order)
└─ k = 0, return ans
```

### Matrix Traversal Visualization

```
Matrix:           Processing Order:
[1,  5,  9]       1 → 2 → 3
[10, 11, 13]      4 → 5 → 6
[12, 13, 15]      7 → 8 → 9

Heap extracts in order: 1, 5, 9, 10, 11, 12, 13, 13, 15
For k=8, answer is the 8th smallest = 13
```

### Time and Space Complexity
- **Time Complexity**: O(k log n) - We extract k elements, each operation takes O(log n)
- **Space Complexity**: O(n) - Heap stores at most n elements

---

## Key Insights and Patterns

### Median in Stream Pattern
- **Two-heap approach**: Balance smaller and larger halves
- **Heap invariant**: Maintain size difference ≤ 1
- **Dynamic median**: Recalculate after each insertion

### Matrix Traversal Pattern
- **Coordinate tracking**: Store position with value in heap
- **Row-wise expansion**: Process one row at a time
- **Min-heap extraction**: Always get globally smallest unprocessed element

### Common Applications
1. **Streaming data analysis**: Real-time median calculation
2. **Matrix problems**: Efficient k-smallest/k-largest queries
3. **Merge algorithms**: Combining sorted sequences

## Summary

Both algorithms showcase advanced heap usage:

- **Find Median in Stream** uses dual heaps to maintain balanced partitions for O(log n) insertion and O(1) median retrieval
- **Kth Smallest in Matrix** leverages coordinate tracking with min-heap to efficiently traverse sorted 2D data

These patterns are fundamental for solving streaming data problems and matrix-based queries efficiently.