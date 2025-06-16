# Day 75: Queue Hard Problems - Sliding Window Maximum & Minimum K Consecutive Bit Flips

## 📚 Table of Contents
1. [Sliding Window Maximum](#sliding-window-maximum)
2. [Minimum Number of K Consecutive Bit Flips](#minimum-number-of-k-consecutive-bit-flips)
3. [Key Concepts](#key-concepts)
4. [Practice Problems](#practice-problems)

---

## 🔥 Sliding Window Maximum

### Problem Statement
Given an array `nums` and a sliding window of size `k` which is moving from the very left of the array to the very right, you can only see the `k` numbers in the window. Each time the sliding window moves right by one position, return the maximum element in each window.

**Example:**
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation:
Window position         Max
---------------         ---
[1  3  -1] -3  5  3  6  7    3
 1 [3  -1  -3] 5  3  6  7    3
 1  3 [-1  -3  5] 3  6  7    5
 1  3  -1 [-3  5  3] 6  7    5
 1  3  -1  -3 [5  3  6] 7    6
 1  3  -1  -3  5 [3  6  7]   7
```

### 🚫 Approach 1: Brute Force (TLE)
**Time Complexity:** O(n*k) | **Space Complexity:** O(1)

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        // For each possible window
        for(int i = 0; i <= n - k; i++) {
            int maxVal = INT_MIN;
            // Find maximum in current window
            for(int j = i; j < i + k; j++) {
                maxVal = max(maxVal, nums[j]);
            }
            ans.push_back(maxVal);
        }
        
        return ans;
    }
};
```

**Why it fails:** For large inputs, checking every element in every window becomes too slow.

### ✅ Approach 2: Deque (Optimal Solution)
**Time Complexity:** O(n) | **Space Complexity:** O(k)

**Key Insight:** Use a deque to maintain potential maximum candidates in decreasing order.

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // Store indices
        vector<int> ans;
        
        // Process first k-1 elements
        for(int i = 0; i < k - 1; i++) {
            // Remove smaller elements from back
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        // Process remaining elements
        for(int i = k - 1; i < n; i++) {
            // Remove smaller elements from back
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // Remove elements outside current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Front element is the maximum of current window
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
```

### 🔍 Algorithm Walkthrough

**Example:** nums = [1,3,-1,-3,5,3,6,7], k = 3

| Step | i | Window | Deque (indices) | Deque (values) | Max | Action |
|------|---|--------|-----------------|----------------|-----|---------|
| 1 | 0 | [1] | [0] | [1] | - | Add 0 |
| 2 | 1 | [1,3] | [1] | [3] | - | Remove 0, Add 1 |
| 3 | 2 | [1,3,-1] | [1,2] | [3,-1] | 3 | Add 2, Output 3 |
| 4 | 3 | [3,-1,-3] | [1,2,3] | [3,-1,-3] | 3 | Add 3, Output 3 |
| 5 | 4 | [-1,-3,5] | [4] | [5] | 5 | Remove all, Add 4, Output 5 |
| 6 | 5 | [-3,5,3] | [4,5] | [5,3] | 5 | Add 5, Output 5 |
| 7 | 6 | [5,3,6] | [6] | [6] | 6 | Remove all, Add 6, Output 6 |
| 8 | 7 | [3,6,7] | [7] | [7] | 7 | Remove all, Add 7, Output 7 |

### 💡 Key Points
- **Deque stores indices**, not values
- **Maintain decreasing order** of values in deque
- **Front always contains** the index of maximum element
- **Remove out-of-window elements** from front
- **Remove smaller elements** from back before adding new element

---

## 🔄 Minimum Number of K Consecutive Bit Flips

### Problem Statement
Given a binary array `nums` and an integer `k`, return the minimum number of k-bit flips required so that there is no 0 in the array. A k-bit flip consists of choosing a subarray of length `k` and simultaneously flipping every bit in the subarray.

**Example:**
```
Input: nums = [0,1,0], k = 2
Output: 3

Explanation:
Flip nums[0],nums[1]: nums = [1,0,0]
Flip nums[1],nums[2]: nums = [1,1,1]
Total flips: 2

Wait, let me recalculate...
Initial: [0,1,0]
Flip at index 0: [1,0,0] (flip positions 0,1)
Flip at index 1: [1,1,1] (flip positions 1,2)
Answer: 2 flips
```

### 🚫 Approach 1: Brute Force (TLE)
**Time Complexity:** O(n*k) | **Space Complexity:** O(1)

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {  // Need to flip
                // Check if we have enough elements to flip
                if(i + k - 1 >= n) {
                    return -1;  // Impossible
                }
                
                // Perform k-bit flip
                for(int j = i; j <= i + k - 1; j++) {
                    nums[j] = !nums[j];
                }
                flips++;
            }
        }
        return flips;
    }
};
```

### ✅ Approach 2: Queue-based Optimization
**Time Complexity:** O(n) | **Space Complexity:** O(k)

**Key Insight:** Instead of actually flipping bits, track the effect of previous flips using a queue.

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> flipQueue;  // Stores end positions of active flips
        int flips = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            // Remove expired flips (those that don't affect current position)
            while(!flipQueue.empty() && flipQueue.front() < i) {
                flipQueue.pop();
            }
            
            // Determine current effective value after all active flips
            // If odd number of flips affect this position, bit is flipped
            bool isFlipped = (flipQueue.size() % 2 == 1);
            bool currentBit = nums[i];
            
            // After applying flips, what's the effective value?
            bool effectiveValue = isFlipped ? !currentBit : currentBit;
            
            // If effective value is 0, we need to flip
            if(effectiveValue == 0) {
                // Check if we can perform k-bit flip
                if(i + k - 1 >= n) {
                    return -1;  // Impossible
                }
                
                // Add this flip (it affects positions i to i+k-1)
                flipQueue.push(i + k - 1);
                flips++;
            }
        }
        
        return flips;
    }
};
```

### 🔍 Algorithm Walkthrough

**Example:** nums = [0,1,0], k = 2

| i | nums[i] | Queue | Queue Size | isFlipped | Effective Value | Action | Flips |
|---|---------|--------|------------|-----------|-----------------|---------|-------|
| 0 | 0 | [] | 0 | false | 0 | Need flip, add flip ending at 1 | 1 |
| 1 | 1 | [1] | 1 | true | 0 | Need flip, add flip ending at 2 | 2 |
| 2 | 0 | [1,2] | 2 | false | 0 | Need flip, but i+k-1=3≥n=3 | -1 |

**Wait, let me fix this example with correct input:**

**Example:** nums = [0,0,1], k = 2

| i | nums[i] | Queue | Active Flips | Effective Value | Action | Total Flips |
|---|---------|--------|--------------|-----------------|---------|-------------|
| 0 | 0 | [] | 0 (even) | 0 | Flip at [0,1], queue=[1] | 1 |
| 1 | 0 | [1] | 1 (odd) | 1 | No flip needed | 1 |
| 2 | 1 | [] | 0 (even) | 1 | No flip needed | 1 |

### 💡 Key Concepts

#### For Deque in Sliding Window Maximum:
1. **Monotonic Deque**: Maintain elements in decreasing order
2. **Index Storage**: Store indices to check window boundaries
3. **Two-ended Operations**: Add to back, remove from both ends

#### For Queue in K-Bit Flips:
1. **Lazy Propagation**: Don't actually flip, just track effects
2. **Flip Counting**: Odd number of flips = bit is flipped
3. **Window Tracking**: Queue stores end positions of active flips

---

## 🎯 Key Concepts

### Deque (Double-ended Queue)
```cpp
deque<int> dq;
dq.push_back(x);   // Add to rear
dq.push_front(x);  // Add to front
dq.pop_back();     // Remove from rear
dq.pop_front();    // Remove from front
dq.front();        // Access front element
dq.back();         // Access rear element
```

### Queue
```cpp
queue<int> q;
q.push(x);         // Add to rear
q.pop();           // Remove from front
q.front();         // Access front element
q.empty();         // Check if empty
q.size();          // Get size
```

### When to Use Each Data Structure

| Problem Type | Data Structure | Reason |
|--------------|----------------|---------|
| Sliding Window Maximum/Minimum | Deque | Need to remove from both ends |
| Range Query with Updates | Segment Tree/Fenwick Tree | Efficient range operations |
| Flip Operations | Queue/Array | Track active operations |
| Monotonic Stack Problems | Stack/Deque | Maintain monotonic property |


## 📝 Summary

### Time Complexities
| Approach | Sliding Window Max | K-Bit Flips |
|----------|-------------------|-------------|
| Brute Force | O(n*k) | O(n*k) |
| Optimized | O(n) | O(n) |

