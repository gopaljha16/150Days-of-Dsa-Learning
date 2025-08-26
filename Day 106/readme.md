# Day 106 : Subarrays with K Different Integers , Count Subarrays Where Max Element Appears at Least K Times , Length of Longest Subarray with At Most K Frequency

## Overview

This document contains three advanced sliding window algorithms implemented in C++. These solutions demonstrate different techniques for counting and finding subarrays with specific properties:

1. **Count Subarrays with Max Element (K Times)** - Counts subarrays where the maximum element appears at least K times
2. **Longest Subarray with At Most K Frequency** - Finds the length of the longest subarray where no element appears more than K times
3. **Count Subarrays with K Distinct Elements** - Counts subarrays containing exactly K distinct elements

All solutions use the sliding window technique with two pointers for optimal O(n) time complexity.

---

## Problem 1: Count Subarrays Where Max Element Appears at Least K Times

### Code Implementation

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long total = 0;
        int n = nums.size(), maxEle = 0;
           
        // Find max element
        for(int i = 0; i < n; i++){
            maxEle = max(maxEle, nums[i]);
        }

        int start = 0, end = 0, count = 0;

        while(end < n){ 
            // Increase the count of max element
            if(nums[end] == maxEle){
                count++;
            }
         
            // If count equals k, shrink window and update total
            while(count == k){
                total += n - end; // Add count of valid subarrays
                if(nums[start] == maxEle){
                    count--;
                }
                start++; // Shrink window
            }
            end++; // Expand window
        }
        return total;
    }
};
```

### Line-by-Line Explanation

**Step 1: Initialize Variables**
```cpp
long long total = 0;           // Store final count of valid subarrays
int n = nums.size(), maxEle = 0;  // Array size and maximum element
```

**Step 2: Find Maximum Element**
```cpp
for(int i = 0; i < n; i++){
    maxEle = max(maxEle, nums[i]);  // Track the largest element in array
}
```

**Step 3: Sliding Window Setup**
```cpp
int start = 0, end = 0, count = 0;  // Two pointers and max element counter
```

**Step 4: Main Sliding Window Logic**
```cpp
while(end < n){
    // Expand window: include nums[end]
    if(nums[end] == maxEle){
        count++;  // Increment count if current element is max
    }
    
    // Shrink window: when we have at least k max elements
    while(count == k){
        total += n - end;  // All subarrays from current position to end are valid
        if(nums[start] == maxEle){
            count--;  // Decrement count when removing max element
        }
        start++;  // Move start pointer right
    }
    end++;  // Move end pointer right
}
```

### Example Input and Expected Output

**Input:** `nums = [1, 3, 2, 3, 3]`, `k = 2`

**Expected Output:** `6`

### Step-by-Step Dry Run

```
Initial: nums = [1, 3, 2, 3, 3], k = 2
Step 1: Find maxEle = 3

Iteration process:
start=0, end=0, count=0, total=0
│
▼
[1, 3, 2, 3, 3]
 ^
 end

end=0: nums[0]=1 ≠ 3, count=0
end=1: nums[1]=3 = 3, count=1
end=2: nums[2]=2 ≠ 3, count=1
end=3: nums[3]=3 = 3, count=2
       count==k, so total += n-end = 5-3 = 2
       nums[start]=1 ≠ 3, start=1
       count still 2, so total += 5-3 = 2 (total=4)
       nums[start]=3 = 3, count=1, start=2
end=4: nums[4]=3 = 3, count=2
       count==k, so total += 5-4 = 1 (total=5)
       nums[start]=2 ≠ 3, start=3
       count still 2, so total += 5-4 = 1 (total=6)
       nums[start]=3 = 3, count=1, start=4

Final total = 6
```

### Visual Representation

```
Valid subarrays with at least 2 occurrences of max element (3):

Array: [1, 3, 2, 3, 3]
Index:  0  1  2  3  4

Subarrays:
1. [3, 2, 3, 3] (index 1-4)
2. [3, 2, 3]    (index 1-3) - extends to end
3. [1, 3, 2, 3, 3] (index 0-4)
4. [1, 3, 2, 3] (index 0-3) - extends to end
5. [3, 3] (index 3-4)
6. [3] (index 3) - extends to end

Total: 6 subarrays
```

---

## Problem 2: Length of Longest Subarray with At Most K Frequency

### Code Implementation

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = 0; // Store max window length
        unordered_map<int, int> count; // Element frequency map
         
        int start = 0, end = 0;
        while(end < nums.size()){
            // Expand window: include nums[end]
            count[nums[end]]++;
            
            // Shrink window: if frequency exceeds k
            while(count[nums[end]] > k){
                count[nums[start]]--; // Decrease frequency
                start++; // Shrink window
            }
            
            // Update maximum length
            len = max(len, end - start + 1);
            end++; // Move end pointer
        }
        return len;
    }
};
```

### Line-by-Line Explanation

**Step 1: Initialize Variables**
```cpp
int len = 0;                    // Maximum valid subarray length
unordered_map<int, int> count;  // Frequency map for elements
int start = 0, end = 0;         // Two pointers for sliding window
```

**Step 2: Sliding Window Process**
```cpp
while(end < nums.size()){
    count[nums[end]]++;  // Add current element to frequency map
    
    // If any element's frequency exceeds k, shrink window
    while(count[nums[end]] > k){
        count[nums[start]]--;  // Remove leftmost element
        start++;               // Move start pointer
    }
    
    len = max(len, end - start + 1);  // Update max length
    end++;  // Expand window
}
```

### Example Input and Expected Output

**Input:** `nums = [1, 2, 3, 1, 2, 3, 1, 2]`, `k = 2`

**Expected Output:** `6`

### Step-by-Step Dry Run

```
nums = [1, 2, 3, 1, 2, 3, 1, 2], k = 2

start=0, end=0: count[1]=1, len=1
start=0, end=1: count[2]=1, len=2  
start=0, end=2: count[3]=1, len=3
start=0, end=3: count[1]=2, len=4
start=0, end=4: count[2]=2, len=5
start=0, end=5: count[3]=2, len=6
start=0, end=6: count[1]=3 > k
    Shrink: count[1]=2, start=1
    len = max(6, 6-1+1) = 6
start=1, end=7: count[2]=3 > k
    Shrink: count[2]=2, start=2
    len = max(6, 7-2+1) = 6

Final answer: 6
```

### Visual Representation

```
Array: [1, 2, 3, 1, 2, 3, 1, 2]
Index:  0  1  2  3  4  5  6  7

Longest valid subarray: [2, 3, 1, 2, 3, 1] (length 6)
                         ^              ^
                      start=1        end=6

Frequency count: {1:2, 2:2, 3:2} - all ≤ k=2
```

---

## Problem 3: Count Subarrays with Exactly K Distinct Elements

### Code Implementation

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total = 0; // Final answer
        unordered_map<int, int> freq; // Frequency map
        
        int start = 0, end = 0, n = nums.size(), count = 0;
        
        // Calculate: atLeast(k) - atLeast(k+1) = exactly(k)
        
        // Part 1: Count subarrays with at least k distinct elements
        while(end < n){
            freq[nums[end]]++;
            if(freq[nums[end]] == 1)
                count++; // New distinct element
            
            while(count == k){
                total += n - end; // Add all valid extensions
                freq[nums[start]]--;
                if(freq[nums[start]] == 0)
                    count--;
                start++;
            }
            end++;
        }
        
        // Part 2: Subtract subarrays with at least (k+1) distinct elements
        start = 0, end = 0, count = 0;
        freq.clear();
        k++;
        
        while(end < n){
            freq[nums[end]]++;
            if(freq[nums[end]] == 1)
                count++;
            
            while(count == k){
                total -= n - end; // Subtract overcounted subarrays
                freq[nums[start]]--;
                if(freq[nums[start]] == 0)
                    count--;
                start++;
            }
            end++;
        }
        return total;      
    }  
};
```

### Algorithm Explanation

This solution uses the mathematical identity:
**exactly(k) = atLeast(k) - atLeast(k+1)**

### Line-by-Line Explanation

**Step 1: Calculate At Least K**
```cpp
// Count subarrays with at least k distinct elements
while(end < n){
    freq[nums[end]]++;           // Add element to frequency map
    if(freq[nums[end]] == 1)     // If it's a new distinct element
        count++;                 // Increment distinct count
    
    while(count == k){           // When we have at least k distinct
        total += n - end;        // All extensions are valid
        freq[nums[start]]--;     // Remove leftmost element
        if(freq[nums[start]] == 0) // If element completely removed
            count--;             // Decrement distinct count
        start++;
    }
    end++;
}
```

**Step 2: Subtract At Least K+1**
```cpp
// Reset and calculate at least (k+1)
start = 0, end = 0, count = 0;
freq.clear();
k++; // Now looking for k+1 distinct elements

// Same logic but subtract from total
while(end < n){
    // ... similar logic ...
    while(count == k){
        total -= n - end; // Subtract overcounted subarrays
        // ... rest similar ...
    }
}
```

### Example Input and Expected Output

**Input:** `nums = [1, 2, 1, 2, 3]`, `k = 2`

**Expected Output:** `7`

### Step-by-Step Dry Run

```
nums = [1, 2, 1, 2, 3], k = 2

Part 1: At least 2 distinct elements
═══════════════════════════════════

end=0: freq[1]=1, count=1
end=1: freq[2]=1, count=2
       count==k, total += 5-1 = 4
       Remove nums[0]=1: freq[1]=0, count=1, start=1
end=2: freq[1]=1, count=2
       count==k, total += 5-2 = 3, total=7
       Remove nums[1]=2: freq[2]=0, count=1, start=2
end=3: freq[2]=1, count=2
       count==k, total += 5-3 = 2, total=9
       Remove nums[2]=1: freq[1]=0, count=1, start=3
end=4: freq[3]=1, count=2
       count==k, total += 5-4 = 1, total=10
       Remove nums[3]=2: freq[2]=0, count=1, start=4

Part 2: At least 3 distinct elements (k+1)
══════════════════════════════════════════

end=0: freq[1]=1, count=1
end=1: freq[2]=1, count=2
end=2: freq[1]=2, count=2
end=3: freq[2]=2, count=2
end=4: freq[3]=1, count=3
       count==k, total -= 5-4 = 1, total=9
       Remove nums[0]=1: freq[1]=1, count=3, start=1
       count==k, total -= 5-4 = 1, total=8
       Remove nums[1]=2: freq[2]=1, count=3, start=2
       count==k, total -= 5-4 = 1, total=7
       Remove nums[2]=1: freq[1]=0, count=2, start=3

Final answer: 7
```

### Visual Diagram

```
Array: [1, 2, 1, 2, 3]
Index:  0  1  2  3  4

Subarrays with exactly 2 distinct elements:
1. [1, 2]       (0,1)
2. [1, 2, 1]    (0,2) 
3. [1, 2, 1, 2] (0,3)
4. [2, 1]       (1,2)
5. [2, 1, 2]    (1,3)
6. [1, 2]       (2,3)
7. [2, 3]       (3,4)

Total: 7 subarrays
```

---

## Time and Space Complexity Analysis

### Problem 1: Count Subarrays with Max Element (K Times)
- **Time Complexity:** O(n) - Each element is visited at most twice
- **Space Complexity:** O(1) - Only using constant extra space

### Problem 2: Longest Subarray with At Most K Frequency  
- **Time Complexity:** O(n) - Single pass with sliding window
- **Space Complexity:** O(min(n, k)) - HashMap stores at most all distinct elements

### Problem 3: Count Subarrays with K Distinct Elements
- **Time Complexity:** O(n) - Two passes through the array
- **Space Complexity:** O(min(n, k)) - HashMap for frequency counting

---

## Key Concepts and Techniques

### Sliding Window Pattern
All three problems use the expanding and contracting window technique:
```cpp
while(end < n){
    // Expand: Include nums[end]
    // ... process current element ...
    
    while(condition_met){
        // Contract: Remove nums[start]
        // ... update result ...
        start++;
    }
    end++;
}
```

### AtLeast Technique (Problem 3)
The mathematical identity `exactly(k) = atLeast(k) - atLeast(k+1)` is crucial for solving the "exactly k" problem efficiently.

### Frequency Counting
Using `unordered_map<int, int>` to track element frequencies is essential for maintaining window validity conditions.

---

## Summary

These three problems demonstrate advanced sliding window techniques for subarray counting and optimization:

1. **Problem 1** shows how to count valid subarrays using the "at least k occurrences" condition
2. **Problem 2** demonstrates the classic sliding window approach for finding maximum length subarrays
3. **Problem 3** illustrates the "atLeast" mathematical technique for solving "exactly k" problems

All solutions achieve optimal O(n) time complexity using the two-pointer sliding window approach, making them efficient for large input arrays. The key insight is recognizing when to expand vs. contract the window based on the specific problem constraints.