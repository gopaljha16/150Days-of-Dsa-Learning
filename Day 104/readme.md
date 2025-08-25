# Day 104: Sliding Window Subarray Problems

This repository contains solutions for two important sliding window problems:
1. **Subarray Sum Divisible by K** (LeetCode Medium)
2. **Subarray Product Less Than K** (LeetCode/GFG Medium)

## Overview

Both problems demonstrate the power of the sliding window technique for solving subarray-related problems efficiently:

- **Subarray Sum Divisible by K**: Uses prefix sum with hashing to find subarrays whose sum is divisible by K
- **Subarray Product Less Than K**: Uses a two-pointer sliding window approach to count subarrays with product less than K

---

## Problem 1: Subarray Sum Divisible by K

### Problem Statement
Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.

### Algorithm Overview
- **Technique**: Prefix Sum + Hash Map
- **Time Complexity**: O(n)
- **Space Complexity**: O(k) - at most k different remainders

### Code Implementation

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1; // initially 
        int prefixSum = 0, rem, total = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // remainder
            rem = prefixSum % k;
             
            if(rem < 0) // for negative we can make positive
                rem = k + rem;
            
            if(m.count(rem)) {
                total += m[rem]; // increase total
                m[rem]++;
            } else { // if rem doesn't exist
                m[rem] = 1;
            }
        }

        return total;
    }
};
```

### Line-by-Line Explanation

1. **`unordered_map<int, int> m;`**: Hash map to store remainder frequencies
2. **`m[0] = 1;`**: Initialize with remainder 0 (empty prefix) having frequency 1
3. **`int prefixSum = 0, rem, total = 0;`**: Initialize variables
4. **`for(int i = 0; i < nums.size(); i++)`**: Iterate through array
5. **`prefixSum += nums[i];`**: Calculate running prefix sum
6. **`rem = prefixSum % k;`**: Get remainder when divided by k
7. **`if(rem < 0) rem = k + rem;`**: Handle negative remainders (C++ modulo quirk)
8. **`if(m.count(rem))`**: Check if this remainder was seen before
9. **`total += m[rem];`**: Add count of previous occurrences (forms subarrays)
10. **`m[rem]++;`**: Increment frequency of current remainder

### Example Input/Output

**Input**: `nums = [4, 5, 0, -2, -3, 1]`, `k = 5`
**Output**: `7`

### Step-by-Step Dry Run

```
Array: [4, 5, 0, -2, -3, 1], k = 5
Initial: m = {0: 1}, prefixSum = 0, total = 0

i=0: nums[0]=4
├─ prefixSum = 0 + 4 = 4
├─ rem = 4 % 5 = 4
├─ m doesn't contain 4
└─ m = {0: 1, 4: 1}, total = 0

i=1: nums[1]=5
├─ prefixSum = 4 + 5 = 9
├─ rem = 9 % 5 = 4
├─ m contains 4 (count = 1)
├─ total += 1 → total = 1
└─ m = {0: 1, 4: 2}, total = 1

i=2: nums[2]=0
├─ prefixSum = 9 + 0 = 9
├─ rem = 9 % 5 = 4
├─ m contains 4 (count = 2)
├─ total += 2 → total = 3
└─ m = {0: 1, 4: 3}, total = 3

... (continuing pattern)

Final total = 7
```

### Visual Representation

```
Prefix Sums:  4  9  9  7  4  5
Remainders:   4  4  4  2  4  0
              ↑     ↑        ↑
              └─────┴────────┘ (multiple subarrays with same remainder)
```

---

## Problem 2: Subarray Product Less Than K

### Problem Statement
Given an array of positive integers `nums` and an integer `k`, return the number of contiguous subarrays where the product of all elements is strictly less than `k`.

### Algorithm Overview
- **Technique**: Two-Pointer Sliding Window
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### Code Implementation

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, product = 1, start = 0, end = 0;
        if(k <= 1) return 0;
        
        while(end < n) {
            product *= nums[end]; // expand window

            // if product >= k, shrink window
            while(product >= k) {
                product /= nums[start];
                start++; // shrink from left
            }

            // count subarrays ending at 'end'
            count += end - start + 1;
            end++; 
        }

        return count;
    }
};
```

### Line-by-Line Explanation

1. **`int n = nums.size(), count = 0, product = 1, start = 0, end = 0;`**: Initialize variables
2. **`if(k <= 1) return 0;`**: Edge case - no positive product can be less than 1
3. **`while(end < n)`**: Main loop with end pointer
4. **`product *= nums[end];`**: Include current element in window
5. **`while(product >= k)`**: Shrink window while product is too large
6. **`product /= nums[start]; start++;`**: Remove leftmost element and move start
7. **`count += end - start + 1;`**: Add count of valid subarrays ending at current position
8. **`end++;`**: Move to next element

### Example Input/Output

**Input**: `nums = [10, 5, 2, 6]`, `k = 100`
**Output**: `8`

### Step-by-Step Dry Run

```
Array: [10, 5, 2, 6], k = 100
Initial: start=0, end=0, product=1, count=0

Step 1: end=0, nums[0]=10
├─ product = 1 × 10 = 10 (< 100) ✓
├─ count += (0-0+1) = 1 → count = 1
└─ Subarrays: [10]

Step 2: end=1, nums[1]=5
├─ product = 10 × 5 = 50 (< 100) ✓
├─ count += (1-0+1) = 2 → count = 3
└─ Subarrays: [5], [10,5]

Step 3: end=2, nums[2]=2
├─ product = 50 × 2 = 100 (≥ 100) ✗
├─ Shrink: product = 100/10 = 10, start = 1
├─ Now product = 10 (< 100) ✓
├─ count += (2-1+1) = 2 → count = 5
└─ Subarrays: [2], [5,2]

Step 4: end=3, nums[3]=6
├─ product = 10 × 6 = 60 (< 100) ✓
├─ count += (3-1+1) = 3 → count = 8
└─ Subarrays: [6], [2,6], [5,2,6]

Final count = 8
```

### Visual Sliding Window

```
Array: [10, 5, 2, 6], k = 100

Step 1: [10] 5  2  6    product=10,  count=1
         ↑
       start/end

Step 2:  10 [5] 2  6    product=50,  count=3
         ↑   ↑
       start end

Step 3:  10  5 [2] 6    product=100 → shrink
              ↑   ↑
            start end
         
         10 [5  2] 6    product=10,  count=5
             ↑   ↑
           start end

Step 4:  10 [5  2  6]   product=60,  count=8
             ↑      ↑
           start    end
```

### Window Counting Logic

For each valid window `[start...end]`, the number of subarrays ending at `end` is `(end - start + 1)`:
- Subarray `[end]` (length 1)
- Subarray `[end-1, end]` (length 2)
- ...
- Subarray `[start, start+1, ..., end]` (full window)

---

## Key Insights

### Problem 1 (Sum Divisible by K)
- **Mathematical Property**: If `(prefixSum[j] - prefixSum[i]) % k == 0`, then `prefixSum[j] % k == prefixSum[i] % k`
- **Negative Remainders**: C++ can produce negative remainders, so we normalize them
- **Hash Map Usage**: Count frequency of each remainder to find matching pairs

### Problem 2 (Product Less than K)
- **Sliding Window**: Expand right, shrink left when condition violated
- **Counting Strategy**: For each valid window ending at position `end`, count all subarrays ending there
- **Edge Case**: If `k ≤ 1`, no positive product can be less than k

## Complexity Analysis

| Problem | Time Complexity | Space Complexity | Technique |
|---------|----------------|------------------|-----------|
| Sum Divisible by K | O(n) | O(k) | Prefix Sum + Hashing |
| Product Less than K | O(n) | O(1) | Two-Pointer Sliding Window |

## Summary

Both problems showcase efficient subarray counting techniques:

1. **Prefix Sum + Hashing** is ideal when looking for subarrays with specific sum properties
2. **Sliding Window** excels for contiguous subarray problems with monotonic properties (like product constraints)

The key insight is recognizing when to use mathematical properties (remainders) versus when to use window expansion/contraction based on the problem constraints.