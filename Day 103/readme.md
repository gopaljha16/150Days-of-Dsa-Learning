# Subarray Sum Problems: Zero Sum Subarrays & Sum Equals K

## Overview

This code demonstrates two related subarray sum problems solved using the **prefix sum technique** with hash maps:

1. **Zero Sum Subarrays**: Count all subarrays that sum to 0
2. **Subarray Sum Equals K**: Count all subarrays that sum to a target value K

Both solutions use the same core concept: if we know the prefix sum at two positions, the subarray between them has a sum equal to their difference.

---

## Problem 1: Zero Sum Subarrays

### Code Explanation

```cpp
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
      
      int total = 0; // stores the total number of zero-sum subarrays found
      unordered_map<int , int>m; // stores prefixSum -> count mapping
      int prefixSum = 0; // running sum from start to current position
      
      // Edge case: initialize map with 0 sum having count 1
      m[0] = 1; // handles subarrays starting from index 0
      
      // Main operation 
      for(int i = 0; i < arr.size(); i++){
          prefixSum += arr[i]; // calculate prefix sum up to index i
          
          if(m.count(prefixSum)){ // if this prefix sum seen before
              total += m[prefixSum]; // add count of previous occurrences
              m[prefixSum]++; // increment count for this prefix sum
          } else { // first time seeing this prefix sum
              m[prefixSum] = 1; // initialize count to 1
          }
      }
      
      return total;
    }
};
```

### Line-by-Line Breakdown

1. **`int total = 0;`** - Counter for zero-sum subarrays
2. **`unordered_map<int, int> m;`** - Maps prefix sum → frequency count
3. **`int prefixSum = 0;`** - Running sum from array start
4. **`m[0] = 1;`** - Edge case: empty prefix has sum 0
5. **`prefixSum += arr[i];`** - Update running sum
6. **`if(m.count(prefixSum))`** - Check if this sum seen before
7. **`total += m[prefixSum];`** - Add previous occurrences to result
8. **`m[prefixSum]++;`** - Increment frequency count

### Key Concept
If prefix sum at position `j` equals prefix sum at position `i` (where i < j), then the subarray from `i+1` to `j` has sum = 0.

---

## Problem 2: Subarray Sum Equals K

### Code Explanation

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; // prefixSum -> count mapping
        m[0] = 1; // edge case: empty prefix
        int prefixSum = 0; // running sum
        int total = 0; // result counter

        // Main iteration 
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i]; // update prefix sum
            
            if(m.count(prefixSum - k)){ // check if (prefixSum - k) exists
                total += m[prefixSum - k]; // add count of valid prefixes
                m[prefixSum]++; // update current prefix count
            } else {
                m[prefixSum]++; // just update count
            }
      }

      return total;
    }
};
```

### Key Difference
Instead of looking for duplicate prefix sums, we look for `prefixSum - k` in the map. This finds subarrays with sum = k.

---

## Visual Representation

### Zero Sum Subarray Example

```
Array: [4, 2, -3, 1, 6]
Target: Sum = 0

Prefix Sums: [4, 6, 3, 4, 10]
Indices:      0  1  2  3   4

Step-by-step:
Index 0: prefixSum = 4,  map = {0:1, 4:1}
Index 1: prefixSum = 6,  map = {0:1, 4:1, 6:1}  
Index 2: prefixSum = 3,  map = {0:1, 4:1, 6:1, 3:1}
Index 3: prefixSum = 4,  map = {0:1, 4:2, 6:1, 3:1}  ← Found duplicate!
         Subarray [2, -3, 1] has sum 0 (between indices 1 and 3)
```

### Sum Equals K Example

```
Array: [1, 1, 1], K = 2
Prefix Sums: [1, 2, 3]

Index 0: prefixSum = 1, looking for (1-2) = -1 → not found
         map = {0:1, 1:1}
Index 1: prefixSum = 2, looking for (2-2) = 0 → found! count = 1
         map = {0:1, 1:1, 2:1}
Index 2: prefixSum = 3, looking for (3-2) = 1 → found! count = 1  
         map = {0:1, 1:1, 2:1, 3:1}

Result: 2 subarrays ([1,1] at indices 0-1 and [1,1] at indices 1-2)
```

---

## Dry Run Example

### Problem 1: Zero Sum Subarrays
**Input**: `arr = [4, 2, -3, 1, 6]`

| Step | i | arr[i] | prefixSum | Map State | Action | total |
|------|---|--------|-----------|-----------|---------|-------|
| Init | - | - | 0 | {0:1} | Initialize | 0 |
| 1 | 0 | 4 | 4 | {0:1, 4:1} | First occurrence | 0 |
| 2 | 1 | 2 | 6 | {0:1, 4:1, 6:1} | First occurrence | 0 |
| 3 | 2 | -3 | 3 | {0:1, 4:1, 6:1, 3:1} | First occurrence | 0 |
| 4 | 3 | 1 | 4 | {0:1, 4:2, 6:1, 3:1} | Found duplicate! | 1 |
| 5 | 4 | 6 | 10 | {0:1, 4:2, 6:1, 3:1, 10:1} | First occurrence | 1 |

**Output**: `1` (subarray [2, -3, 1] from index 1 to 3)

### Problem 2: Sum Equals K  
**Input**: `nums = [1, 2, 3], k = 3`

| Step | i | nums[i] | prefixSum | Looking for | Found? | Map State | total |
|------|---|---------|-----------|-------------|---------|-----------|-------|
| Init | - | - | 0 | - | - | {0:1} | 0 |
| 1 | 0 | 1 | 1 | 1-3 = -2 | No | {0:1, 1:1} | 0 |
| 2 | 1 | 2 | 3 | 3-3 = 0 | Yes! | {0:1, 1:1, 3:1} | 1 |
| 3 | 2 | 3 | 6 | 6-3 = 3 | Yes! | {0:1, 1:1, 3:1, 6:1} | 2 |

**Output**: `2` (subarrays [1,2] and [3])

---

## Algorithm Flow

```
START
  ↓
Initialize: total=0, prefixSum=0, map={0:1}
  ↓
For each element in array:
  ↓
Update prefixSum += arr[i]
  ↓
Problem 1 (Zero Sum):        Problem 2 (Sum = K):
Check if prefixSum in map    Check if (prefixSum-K) in map
  ↓                           ↓
If found:                    If found:
  total += map[prefixSum]      total += map[prefixSum-K]
  ↓                           ↓
Update map[prefixSum]++      Update map[prefixSum]++
  ↓
Return total
```

---

## Time & Space Complexity

- **Time Complexity**: O(n) - single pass through array
- **Space Complexity**: O(n) - hash map can store up to n different prefix sums

## Key Insights

1. **Prefix Sum**: Running sum from start to current position
2. **Hash Map**: Stores frequency of each prefix sum encountered  
3. **Zero Sum**: Look for duplicate prefix sums
4. **Sum = K**: Look for `prefixSum - K` in previous sums
5. **Edge Case**: `map[0] = 1` handles subarrays starting from index 0

## Summary

Both problems leverage the **prefix sum** technique with hash maps to efficiently count subarrays meeting specific sum criteria. The key insight is that if two positions have the same prefix sum (Problem 1) or differ by K (Problem 2), the subarray between them has the desired sum. This approach reduces the time complexity from O(n²) brute force to O(n) with hash map lookup.