# Kth Element Solutions using Priority Queue and Heap

## Overview

This document contains three C++ solutions that utilize priority queues (heaps) to solve different variations of finding the Kth element in arrays:

1. **Kth Smallest Element**: Find the Kth smallest element in an unsorted array
2. **Kth Largest Element**: Find the Kth largest element in an unsorted array  
3. **Sum Between Two Kth Elements**: Calculate the sum of elements between the K1'th and K2'th smallest elements

All solutions use the heap data structure through C++'s `priority_queue` to efficiently maintain and extract the required elements with optimal time complexity.

---

## 1. Kth Smallest Element

### Code Explanation

```cpp
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
      priority_queue<int>p; //max heap
      
      //inserting element in max heap
      for(int i=0 ; i<k ; i++){
          p.push(arr[i]);
      }
      
      //now from k to array end comparing and inserting.
      for(int i=k ; i<arr.size() ; i++){
          if(arr[i]<p.top()){ 
              p.pop();
              p.push(arr[i]);
          }
      }
      
      return p.top();
    }
};
```

### Line-by-Line Breakdown

- **Line 3**: `priority_queue<int>p;` - Creates a max heap (largest element at top)
- **Lines 5-7**: Insert first `k` elements from array into the max heap
- **Lines 9-14**: For remaining elements, compare with heap's top (largest among k elements):
  - If current element is smaller than heap top, remove the largest and add current element
  - This maintains only the k smallest elements seen so far
- **Line 16**: Return the top element, which is the largest among k smallest = Kth smallest

### Algorithm Strategy

The algorithm uses a **max heap of size k** to track the k smallest elements:

```
Max Heap Properties:
┌─────────────────┐
│   Largest       │ ← Top (will be removed if we find smaller)
│   element       │
│   among k       │
│   smallest      │
└─────────────────┘
```

### Example Walkthrough

**Input**: `arr = [7, 10, 4, 3, 20, 15]`, `k = 3`

**Step-by-step execution**:

1. **Initialize max heap, insert first 3 elements**:
   ```
   Heap: [10, 7, 4]  (max heap representation)
   Top: 10
   ```

2. **Process arr[3] = 3**:
   - `3 < 10` (top), so pop 10 and push 3
   ```
   Heap: [7, 4, 3]
   Top: 7
   ```

3. **Process arr[4] = 20**:
   - `20 > 7` (top), so no change
   ```
   Heap: [7, 4, 3]
   Top: 7
   ```

4. **Process arr[5] = 15**:
   - `15 > 7` (top), so no change
   ```
   Heap: [7, 4, 3]
   Top: 7
   ```

5. **Result**: `p.top() = 7` (3rd smallest element)

**Expected Output**: `7`

---

## 2. Kth Largest Element

### Code Explanation

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //minheap 
        priority_queue<int,vector<int>, greater<int>>p;

        //insert k elements in queue
        for(int i=0 ; i<k ; i++)
            p.push(nums[i]);

        //now other elements comparing 
        for(int i=k ; i<nums.size() ; i++){
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }

        return p.top();
    }
};
```

### Line-by-Line Breakdown

- **Line 5**: `priority_queue<int,vector<int>, greater<int>>p;` - Creates a min heap (smallest element at top)
- **Lines 7-9**: Insert first `k` elements into the min heap
- **Lines 11-17**: For remaining elements, compare with heap's top (smallest among k elements):
  - If current element is larger than heap top, remove the smallest and add current element
  - This maintains only the k largest elements seen so far
- **Line 19**: Return the top element, which is the smallest among k largest = Kth largest

### Algorithm Strategy

The algorithm uses a **min heap of size k** to track the k largest elements:

```
Min Heap Properties:
┌─────────────────┐
│   Smallest      │ ← Top (will be removed if we find larger)
│   element       │
│   among k       │
│   largest       │
└─────────────────┘
```

### Example Walkthrough

**Input**: `nums = [3, 2, 1, 5, 6, 4]`, `k = 2`

**Step-by-step execution**:

1. **Initialize min heap, insert first 2 elements**:
   ```
   Heap: [2, 3]  (min heap representation)
   Top: 2
   ```

2. **Process nums[2] = 1**:
   - `1 < 2` (top), so no change
   ```
   Heap: [2, 3]
   Top: 2
   ```

3. **Process nums[3] = 5**:
   - `5 > 2` (top), so pop 2 and push 5
   ```
   Heap: [3, 5]
   Top: 3
   ```

4. **Process nums[4] = 6**:
   - `6 > 3` (top), so pop 3 and push 6
   ```
   Heap: [5, 6]
   Top: 5
   ```

5. **Process nums[5] = 4**:
   - `4 < 5` (top), so no change
   ```
   Heap: [5, 6]
   Top: 5
   ```

6. **Result**: `p.top() = 5` (2nd largest element)

**Expected Output**: `5`

---

## 3. Sum Between Two Kth Smallest Elements

### Code Explanation

```cpp
class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        //maxheap 
        priority_queue<int>p1; //for storing k1 smallest element
        priority_queue<int>p2; //for k2-1 smallest elements
        
        //inserting element k1
        for(long long i=0 ; i<K1; i++){
            p1.push(A[i]);
        }
        
        //inserting k2 element
        for(long long i=0; i<K2-1; i++){
            p2.push(A[i]);
        }
        
        // element from k1 to n compare and push in p1
        for(long long i=K1 ;i<N ; i++){
            if(A[i]<p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        
        //element from k2-1 to n compare and push in p2
         for(long long i=K2-1 ;i<N ; i++){
            if(A[i]<p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        
        // now we have got the queue 
        long long sum1 = 0 , sum2 = 0;
        //p1 sum
        while(!p1.empty()){
            sum1+=p1.top();
            p1.pop();
        }
        
        //p2 sum
           while(!p2.empty()){
            sum2+=p2.top();
            p2.pop();
        }

        return sum2-sum1;
    }
};
```

### Section-wise Breakdown

#### Setup Phase (Lines 5-6)
- **p1**: Max heap to store K1 smallest elements
- **p2**: Max heap to store (K2-1) smallest elements

#### Initialization Phase (Lines 8-15)
- Fill p1 with first K1 elements
- Fill p2 with first (K2-1) elements

#### Processing Phase (Lines 17-31)
- **p1 processing**: Maintain K1 smallest elements by comparing remaining elements
- **p2 processing**: Maintain (K2-1) smallest elements by comparing remaining elements

#### Calculation Phase (Lines 33-46)
- Calculate sum of all elements in p1 (sum of K1 smallest)
- Calculate sum of all elements in p2 (sum of K2-1 smallest)
- Return `sum2 - sum1` = sum of elements between K1'th and K2'th smallest

### Algorithm Logic

```
Original Array: [a, b, c, d, e, f, g]
Sorted View:    [1, 2, 3, 4, 5, 6, 7]

K1 = 2, K2 = 5

K1 smallest: [1, 2] → sum1
K2-1 smallest: [1, 2, 3, 4] → sum2
Elements between K1 and K2: [3, 4] → sum2 - sum1
```

### Example Walkthrough

**Input**: `A = [20, 8, 22, 4, 12, 10, 14]`, `N = 7`, `K1 = 3`, `K2 = 6`

**Sorted array for reference**: `[4, 8, 10, 12, 14, 20, 22]`

**Step-by-step execution**:

1. **Initialize heaps**:
   ```
   p1: [22, 20, 8]     (K1=3 elements)
   p2: [20, 12, 8, 4, 22]  (K2-1=5 elements)
   ```

2. **Process remaining elements for p1**:
   - A[3]=4: `4 < 22`, so pop 22, push 4 → `[20, 8, 4]`
   - A[4]=12: `12 < 20`, so pop 20, push 12 → `[12, 8, 4]`
   - A[5]=10: `10 < 12`, so pop 12, push 10 → `[10, 8, 4]`
   - A[6]=14: `14 > 10`, no change → `[10, 8, 4]`

3. **Process remaining elements for p2**:
   - A[5]=10: `10 < 22`, so pop 22, push 10 → `[20, 12, 10, 8, 4]`
   - A[6]=14: `14 < 20`, so pop 20, push 14 → `[14, 12, 10, 8, 4]`

4. **Calculate sums**:
   - sum1 = 10 + 8 + 4 = 22 (sum of 3 smallest)
   - sum2 = 14 + 12 + 10 + 8 + 4 = 48 (sum of 5 smallest)

5. **Result**: `sum2 - sum1 = 48 - 22 = 26`

**Expected Output**: `26` (sum of elements 12 and 14, which are between 3rd and 6th smallest)

---

## Visual Representation

### Heap Operations Flow

```
Kth Smallest (Max Heap):
┌─────────────────────────────────────────┐
│  [7,10,4,3,20,15], k=3                  │
└─────────────────────────────────────────┘
           │
           ▼
┌─────────────────────────────────────────┐
│  Initial: [10,7,4]                      │
│  After 3: [7,4,3]                       │
│  After 20: [7,4,3] (no change)          │
│  After 15: [7,4,3] (no change)          │
│  Result: 7 (top of heap)                │
└─────────────────────────────────────────┘

Kth Largest (Min Heap):
┌─────────────────────────────────────────┐
│  [3,2,1,5,6,4], k=2                     │
└─────────────────────────────────────────┘
           │
           ▼
┌─────────────────────────────────────────┐
│  Initial: [2,3]                         │
│  After 1: [2,3] (no change)             │
│  After 5: [3,5]                         │
│  After 6: [5,6]                         │
│  After 4: [5,6] (no change)             │
│  Result: 5 (top of heap)                │
└─────────────────────────────────────────┘
```

---

## Time and Space Complexity

| Solution | Time Complexity | Space Complexity | Description |
|----------|----------------|------------------|-------------|
| Kth Smallest | O(N log K) | O(K) | N insertions with log K heap operations |
| Kth Largest | O(N log K) | O(K) | N insertions with log K heap operations |
| Sum Between | O(N log K) | O(K1 + K2) | Two heaps with separate processing |

---

## Key Insights

### Heap Selection Strategy

```
Problem Type          │ Heap Type │ Heap Size │ Reasoning
─────────────────────────────────────────────────────────
Kth Smallest         │ Max Heap  │ K         │ Remove largest when smaller found
Kth Largest          │ Min Heap  │ K         │ Remove smallest when larger found
Sum Between K1,K2    │ Max Heap  │ K1,K2-1   │ Track multiple ranges separately
```

### Why These Heap Choices Work

1. **Kth Smallest with Max Heap**: Keep k smallest elements, with largest of these k at top for easy removal
2. **Kth Largest with Min Heap**: Keep k largest elements, with smallest of these k at top for easy removal
3. **Sum Between**: Use two separate heaps to track different ranges of smallest elements

---

## Common Test Cases

### Test Case 1: Kth Smallest
```cpp
Input: arr = [7, 10, 4, 3, 20, 15], k = 3
Expected: 7
Sorted: [3, 4, 7, 10, 15, 20]
        ↑  ↑  ↑ (3rd smallest)
```

### Test Case 2: Kth Largest  
```cpp
Input: nums = [3, 2, 1, 5, 6, 4], k = 2
Expected: 5
Sorted: [1, 2, 3, 4, 5, 6]
                    ↑  ↑ (2nd largest)
```

### Test Case 3: Sum Between
```cpp
Input: A = [20, 8, 22, 4, 12, 10, 14], K1 = 3, K2 = 6
Expected: 26
Sorted: [4, 8, 10, 12, 14, 20, 22]
         ↑  ↑  ↑   ↑   ↑   ↑
         1  2  3   4   5   6
Elements between 3rd and 6th: 12 + 14 = 26
```

---

## Alternative Approaches

### Quick Select Algorithm
- **Time**: O(N) average, O(N²) worst case
- **Space**: O(1)
- **Use when**: Single query, in-place modification allowed

### Full Sorting
- **Time**: O(N log N)
- **Space**: O(1) with in-place sort
- **Use when**: Multiple queries on same array

### Heap Approach (Current)
- **Time**: O(N log K)
- **Space**: O(K)
- **Use when**: K << N, multiple different arrays

---

## Summary

These three solutions demonstrate the versatility of heap data structures for solving Kth element problems:

- **Kth Smallest**: Uses max heap to efficiently track and update the k smallest elements
- **Kth Largest**: Uses min heap to efficiently track and update the k largest elements  
- **Sum Between**: Combines two max heaps to calculate sums in specific ranges of sorted elements

The heap-based approach is particularly efficient when K is much smaller than N, providing O(N log K) time complexity compared to O(N log N) for full sorting. The key insight is choosing the right heap type (max vs min) based on what elements need to be easily accessible and removable.