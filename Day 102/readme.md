# Heap-Based Algorithms: Smallest Range and Target Array Construction

## Overview

This document explains two advanced heap-based algorithms implemented in C++:

1. **Smallest Range Covering Elements from K Lists** - Finds the smallest range that includes at least one number from each of K sorted lists
2. **Construct Target Array With Multiple Sums** - Determines if a target array can be constructed using a specific sum-based transformation process

Both algorithms utilize priority queues (heaps) to efficiently solve complex optimization problems.

## Problem 1: Smallest Range Covering Elements from K Lists

### Algorithm Description

Given K sorted lists of integers, find the smallest range [a,b] such that each list has at least one number in this range.

### Code Breakdown

```cpp
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min heap to store {value, {row, col}}
        priority_queue<pair<int, pair<int,int>>, 
                      vector<pair<int, pair<int,int>>>, 
                      greater<pair<int, pair<int,int>>>> p;
        
        // Track minimum and maximum values
        int minimum, maximum = INT_MIN;
        
        // Initialize heap with first element from each list
        for(int i = 0; i < nums.size(); i++){
            p.push(make_pair(nums[i][0], make_pair(i, 0)));
            maximum = max(maximum, nums[i][0]);
        }
        
        // Get initial minimum from heap top
        minimum = p.top().first;
        vector<int> ans = {0, INT_MAX}; // Store best range found
        
        int row, col, element;
        pair<int, pair<int, int>> temp;
        
        // Process while heap contains elements from all lists
        while(p.size() == nums.size()){
            temp = p.top();
            p.pop();
            
            // Extract element details
            element = temp.first;
            row = temp.second.first;
            col = temp.second.second;
            minimum = element;
            
            // Update answer if current range is smaller
            if ((long long)maximum - minimum < (long long)ans[1] - ans[0] ||
                ((long long)maximum - minimum == (long long)ans[1] - ans[0] && minimum < ans[0])) {
                ans[0] = minimum;
                ans[1] = maximum;
            }
            
            // Add next element from same row if available
            if(col + 1 < nums[row].size()){
                col++;
                p.push(make_pair(nums[row][col], make_pair(row, col)));
                maximum = max(maximum, nums[row][col]);
            }
        }
        
        return ans;
    }
};
```

### Step-by-Step Explanation

1. **Heap Initialization**: Create a min-heap storing tuples of (value, row, column)
2. **Initial Setup**: Add the first element from each list to the heap and track the maximum
3. **Range Processing**: 
   - Extract minimum element from heap
   - Calculate current range [minimum, maximum]
   - Update best answer if current range is smaller
   - Add next element from the same row to maintain K elements in heap
4. **Termination**: Stop when we can't maintain elements from all K lists

### Example Walkthrough

**Input**: `nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]`

**Initial State**:
```
Heap: [(4,0,0), (0,1,0), (5,2,0)]
Maximum: 5
Minimum: 0 (from heap top)
Current range: [0, 5] (length = 5)
```

**Iteration 1**:
- Pop (0,1,0), add next element (9,1,1)
- Heap: [(4,0,0), (5,2,0), (9,1,1)]
- Maximum: 9, Minimum: 4
- Range: [4, 9] (length = 5)

**Iteration 2**:
- Pop (4,0,0), add next element (10,0,1)
- Heap: [(5,2,0), (9,1,1), (10,0,1)]
- Maximum: 10, Minimum: 5
- Range: [5, 10] (length = 5)

**Final Answer**: [4, 9] or [5, 10] (both have length 5)

### Visual Representation

```
Lists:    [4, 10, 15, 24, 26]
          [0,  9, 12, 20    ]
          [5, 18, 22, 30    ]
          ^   ^   ^
     Pointers start here

Range: [min_in_window, max_in_window]
Goal: Minimize (max - min) while covering all lists
```

### Time & Space Complexity

- **Time Complexity**: O(N log K) where N is total elements and K is number of lists
- **Space Complexity**: O(K) for the heap

---

## Problem 2: Construct Target Array With Multiple Sums

### Algorithm Description

Given a target array, determine if it can be constructed starting from an array of all 1's using the operation: replace the largest element with (sum of all elements - largest element).

### Code Breakdown

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Max heap to always get the largest element
        priority_queue<long long> p; 
        long long sum = 0;
        
        // Initialize heap with target values
        for(int i = 0; i < target.size(); i++){
            p.push(target[i]);
            sum += target[i];
        }
        
        long long maxElement, remSum, newElement;
        
        // Reverse the construction process
        while(p.top() != 1){
            maxElement = p.top();
            p.pop();
            
            remSum = sum - maxElement; // Sum of other elements
            
            // Edge case: impossible configurations
            if(remSum <= 0 || remSum >= maxElement){
                return false;
            }
            
            // Calculate what the previous value was
            newElement = maxElement % remSum;
            
            // Handle special cases
            if(newElement == 0){
                if(remSum != 1){
                    return false;
                } else {
                    return true;
                }
            }
            
            // Update sum and add new element
            sum = remSum + newElement;
            p.push(newElement);
        }
        
        return true;
    }
};
```

### Step-by-Step Explanation

1. **Reverse Engineering**: Work backwards from target to [1,1,...,1]
2. **Max Heap Usage**: Always process the largest element first
3. **Sum Calculation**: For each step, calculate what the previous largest element was
4. **Validation**: Check if the reverse operation is valid
5. **Modulo Optimization**: Use modulo to handle large numbers efficiently

### Example Walkthrough

**Input**: `target = [9, 3, 5]`

**Step 1**: 
```
Heap: [9, 5, 3]
sum = 17, maxElement = 9
remSum = 17 - 9 = 8
newElement = 9 % 8 = 1
New state: [1, 5, 3], sum = 9
```

**Step 2**:
```
Heap: [5, 3, 1]  
sum = 9, maxElement = 5
remSum = 9 - 5 = 4
newElement = 5 % 4 = 1
New state: [1, 1, 3], sum = 5
```

**Step 3**:
```
Heap: [3, 1, 1]
sum = 5, maxElement = 3
remSum = 5 - 3 = 2  
newElement = 3 % 2 = 1
Final state: [1, 1, 1], sum = 3
```

**Result**: `true` (successfully reduced to all 1's)

### Construction Process Visualization

```
Forward Construction:
[1, 1, 1] → [1, 1, 3] → [1, 5, 3] → [9, 3, 5]
    ↓           ↓           ↓           ↓
  sum=3      sum=5       sum=9      sum=17

Reverse Validation:  
[9, 3, 5] → [1, 5, 3] → [1, 1, 3] → [1, 1, 1]
```

### Algorithm Flow Diagram

```
START
  ↓
Initialize max heap with target values
  ↓
While top ≠ 1:
  ↓
Extract max element
  ↓
Calculate remaining sum
  ↓
Check validity (remSum > 0 and remSum < maxElement)
  ↓
Calculate previous value using modulo
  ↓
Handle edge cases
  ↓
Update sum and push new element
  ↓
END → Return true if all elements become 1
```

### Time & Space Complexity

- **Time Complexity**: O(log(max_value) × log(n)) where n is array length
- **Space Complexity**: O(n) for the heap

---

## Key Algorithmic Patterns

### Pattern 1: Multi-List Range Problems
- Use min-heap to track smallest elements across lists
- Maintain sliding window concept with heap operations
- Update range bounds as elements are processed

### Pattern 2: Reverse Construction Validation  
- Use max-heap to always process largest elements
- Apply inverse operations to validate construction
- Use modulo arithmetic for optimization

## Summary

Both algorithms demonstrate sophisticated heap usage:

1. **Smallest Range**: Uses min-heap with coordinate tracking to find optimal ranges across multiple sorted lists
2. **Target Array Construction**: Uses max-heap with reverse engineering to validate array construction possibility

The key insights are:
- Heaps provide efficient access to extrema (min/max)
- Coordinate tracking enables multi-dimensional problem solving
- Reverse validation can be more efficient than forward construction
- Modulo arithmetic prevents overflow in iterative processes

These patterns are applicable to many optimization problems involving multiple data sources or construction validation scenarios.