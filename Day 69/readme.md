# Day 69: Stack Problems - DSA Study Notes

## 📋 Problems Covered

1. **Get Minimum From Stack** (GFG Medium)
2. **Max of Min for Every Window Size** (GFG Hard)

---

# Problem 1: Get Minimum From Stack

## 🎯 Problem Statement

Design a stack that supports the following operations in **O(1)** time:
- `push(x)` - Push element x onto stack
- `pop()` - Remove top element and return it
- `peek()` - Return top element without removing
- `getMin()` - Return minimum element in the stack

### Key Constraint: All operations must be O(1)

---

## 🚀 Solution Approaches

## Method 1: Two Stack Approach

### Approach:
- **Stack 1**: Stores actual values
- **Stack 2**: Stores minimum values at each level

### Code Implementation:

```cpp
class Solution {
private:
    stack<int> st1;  // Original values stack
    stack<int> st2;  // Minimum values stack
    
public:
    Solution() {
        // Constructor - stacks are automatically empty
    }

    // Add element to top of stack - O(1)
    void push(int x) {
        if(st1.empty()) {           // If stack is empty
            st1.push(x);            // Push value to main stack
            st2.push(x);            // Push same value as first minimum
        } else {                    // Stack has elements
            st1.push(x);            // Push value to main stack
            // Push minimum of current element and previous minimum
            st2.push(min(x, st2.top()));
        }
    }

    // Remove top element - O(1)
    int pop() {
        if(st1.empty()) {           // Check if stack is empty
            return -1;              // Return -1 for empty stack
        } else {                    // Stack has elements
            int element = st1.top(); // Get top element
            st1.pop();              // Remove from main stack
            st2.pop();              // Remove corresponding minimum
            return element;         // Return the popped element
        }
    }

    // Get top element without removing - O(1)
    int peek() {
        if(st1.empty()) {           // Check if stack is empty
            return -1;              // Return -1 for empty stack
        } else {                    // Stack has elements
            return st1.top();       // Return top element
        }
    }

    // Get minimum element - O(1)
    int getMin() {
        if(st2.empty()) {           // Check if stack is empty
            return -1;              // Return -1 for empty stack
        } else {                    // Stack has elements
            return st2.top();       // Return current minimum
        }
    }
};
```

### 🔍 Dry Run Example:

```
Operations: push(3), push(5), push(2), push(1), getMin(), pop(), getMin()

Initial State:
st1: []     st2: []

Step 1: push(3)
st1: [3]    st2: [3]    (3 is first element, so minimum is 3)

Step 2: push(5) 
st1: [3,5]  st2: [3,3]  (min(5,3) = 3, so minimum remains 3)

Step 3: push(2)
st1: [3,5,2] st2: [3,3,2] (min(2,3) = 2, so new minimum is 2)

Step 4: push(1)
st1: [3,5,2,1] st2: [3,3,2,1] (min(1,2) = 1, so new minimum is 1)

Step 5: getMin()
Returns: st2.top() = 1

Step 6: pop()
st1: [3,5,2] st2: [3,3,2] (Remove both tops)
Returns: 1

Step 7: getMin()
Returns: st2.top() = 2
```

---

## Method 2: Single Stack with Encoding

### Approach:
Use mathematical encoding to store both value and minimum in single number.

### Formula:
- **Encoded Value** = `value * MULT + minimum`
- **Extract Value** = `encoded / MULT`
- **Extract Minimum** = `encoded % MULT`

### Code Implementation:

```cpp
class Solution {
private:
    stack<long long> st1;           // Single stack for both value and minimum
    const long long MULT = 1e9 + 1; // Multiplier (larger than max possible value)
    
public:
    Solution() {
        // Constructor - stack is automatically empty
    }

    // Add element to stack - O(1)
    void push(int x) {
        if(st1.empty()) {                    // If stack is empty
            // Encode: value * MULT + minimum (here minimum = value itself)
            st1.push(1LL * x * MULT + x);
        } else {                             // Stack has elements
            int currMin = st1.top() % MULT;  // Extract current minimum
            // Encode: value * MULT + min(new_value, current_minimum)
            st1.push(1LL * x * MULT + min(x, currMin));
        }
    }

    // Remove top element - O(1)  
    int pop() {
        if(st1.empty()) {                    // Check if stack is empty
            return -1;                       // Return -1 for empty stack
        } else {                             // Stack has elements
            int element = st1.top() / MULT;  // Extract original value
            st1.pop();                       // Remove encoded element
            return element;                  // Return original value
        }
    }

    // Get top element - O(1)
    int peek() {
        if(st1.empty()) {                    // Check if stack is empty
            return -1;                       // Return -1 for empty stack  
        } else {                             // Stack has elements
            return st1.top() / MULT;         // Extract and return original value
        }
    }

    // Get minimum element - O(1)
    int getMin() {
        if(st1.empty()) {                    // Check if stack is empty
            return -1;                       // Return -1 for empty stack
        } else {                             // Stack has elements  
            return st1.top() % MULT;         // Extract and return minimum
        }
    }
};
```

### 🔍 Dry Run Example:

```
MULT = 1000000001
Operations: push(3), push(5), push(2), getMin(), peek()

Step 1: push(3)
Encoded = 3 * 1000000001 + 3 = 3000000006
st1: [3000000006]

Step 2: push(5)
currMin = 3000000006 % 1000000001 = 3
min(5, 3) = 3
Encoded = 5 * 1000000001 + 3 = 5000000008  
st1: [3000000006, 5000000008]

Step 3: push(2)
currMin = 5000000008 % 1000000001 = 3
min(2, 3) = 2
Encoded = 2 * 1000000001 + 2 = 2000000004
st1: [3000000006, 5000000008, 2000000004]

Step 4: getMin()
Returns: 2000000004 % 1000000001 = 2

Step 5: peek()  
Returns: 2000000004 / 1000000001 = 2
```

### 📊 Comparison:

| Aspect | Two Stack | Single Stack |
|--------|-----------|--------------|
| Time Complexity | O(1) all ops | O(1) all ops |
| Space Complexity | O(2n) | O(n) |
| Code Complexity | Simple | Moderate |
| Integer Overflow | No risk | Possible risk |

---

# Problem 2: Max of Min for Every Window Size

## 🎯 Problem Statement

Given an array, find the maximum of minimum elements for every possible window size.

### Example:
```
Input: arr = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10]

Explanation:
Window size 1: max of [10,20,30,50,10,70,30] = 70
Window size 2: max of [min(10,20), min(20,30), ...] = 30  
Window size 3: max of [min(10,20,30), min(20,30,50), ...] = 20
...and so on
```

---

## 🚀 Solution Approaches

## Method 1: Brute Force (TLE)

### Approach:
Check all possible windows of all sizes and find minimum of each window.

### Code:
```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);              // Result array initialized to 0
        
        // For each window size (i+1)
        for(int i = 0; i < n; i++) {
            // For each starting position
            for(int j = 0; j < n - i; j++) {
                int num = INT_MAX;           // Initialize minimum finder
                
                // Find minimum in current window [j, j+i]
                for(int k = j; k < i + 1 + j; k++) {
                    num = min(arr[k], num);  // Update minimum
                }
                
                // Update maximum of minimums for this window size
                ans[i] = max(ans[i], num);
            }
        }
        
        return ans;
    }
};
```

**Time Complexity:** O(n³)  
**Space Complexity:** O(n)  
**Result:** Time Limit Exceeded for large inputs

---

## Method 2: Stack-Based Optimal Solution

### 🧠 Key Insight:
For each element, find the **maximum window size** where it can be the minimum element.

### Algorithm Steps:
1. **Find Range**: For each element, determine the largest window where it's minimum
2. **Update Answer**: For that window size, update the maximum value
3. **Fill Gaps**: Propagate values for unfilled window sizes

### Code Implementation:

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);               // Result array initialized to 0
        stack<int> st;                       // Stack to store indices
        
        // Process each element to find their maximum window size
        for(int i = 0; i < n; i++) {
            
            // While stack not empty AND current element is smaller than stack top
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int index = st.top();        // Get the index of larger element
                st.pop();                    // Remove it from stack
                
                // Calculate the range where arr[index] was minimum
                int range;
                if(st.empty()) {             // No smaller element on left
                    range = i;               // Range from start to current position
                } else {                     // Smaller element exists on left
                    range = i - st.top() - 1; // Range between left smaller and right smaller
                }
                
                // Update maximum for this window size
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            
            st.push(i);                      // Push current index to stack
        }
        
        // Process remaining elements in stack (no smaller element on right)
        while(!st.empty()) {
            int index = st.top();            // Get index
            st.pop();                        // Remove from stack
            
            int range;
            if(st.empty()) {                 // No smaller element on left
                range = n;                   // Range is entire array
            } else {                         // Smaller element exists on left  
                range = n - st.top() - 1;    // Range from left smaller to end
            }
            
            // Update maximum for this window size
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        
        // Fill remaining positions with maximum of next larger window
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i + 1]); // Propagate maximum values
        }
        
        return ans;                          // Return final result
    }
};
```

---

## 🔍 Detailed Dry Run

### Input: `arr = [10, 20, 30, 50, 10, 70, 30]`

### Initial State:
```
ans = [0, 0, 0, 0, 0, 0, 0]
st = []
i = 0
```

### Step-by-Step Execution:

**i = 0, arr[0] = 10:**
```
Stack empty, push 0
st = [0]
ans = [0, 0, 0, 0, 0, 0, 0]
```

**i = 1, arr[1] = 20:**
```
arr[0] = 10 < arr[1] = 20, no popping needed
Push 1
st = [0, 1] 
ans = [0, 0, 0, 0, 0, 0, 0]
```

**i = 2, arr[2] = 30:**
```
arr[1] = 20 < arr[2] = 30, no popping needed
Push 2
st = [0, 1, 2]
ans = [0, 0, 0, 0, 0, 0, 0]
```

**i = 3, arr[3] = 50:**
```
arr[2] = 30 < arr[3] = 50, no popping needed
Push 3
st = [0, 1, 2, 3]
ans = [0, 0, 0, 0, 0, 0, 0]
```

**i = 4, arr[4] = 10:**
```
arr[3] = 50 > arr[4] = 10, start popping:

Pop index 3 (value 50):
- st after pop = [0, 1, 2]
- range = 4 - 2 - 1 = 1 (window size 1)
- ans[0] = max(0, 50) = 50

arr[2] = 30 > arr[4] = 10, continue popping:

Pop index 2 (value 30):  
- st after pop = [0, 1]
- range = 4 - 1 - 1 = 2 (window size 2)
- ans[1] = max(0, 30) = 30

arr[1] = 20 > arr[4] = 10, continue popping:

Pop index 1 (value 20):
- st after pop = [0] 
- range = 4 - 0 - 1 = 3 (window size 3)
- ans[2] = max(0, 20) = 20

arr[0] = 10 = arr[4] = 10, stop popping
Push 4
st = [0, 4]
ans = [50, 30, 20, 0, 0, 0, 0]
```

**i = 5, arr[5] = 70:**
```
arr[4] = 10 < arr[5] = 70, no popping needed
Push 5
st = [0, 4, 5]
ans = [50, 30, 20, 0, 0, 0, 0]
```

**i = 6, arr[6] = 30:**
```
arr[5] = 70 > arr[6] = 30, start popping:

Pop index 5 (value 70):
- st after pop = [0, 4]
- range = 6 - 4 - 1 = 1 (window size 1) 
- ans[0] = max(50, 70) = 70

arr[4] = 10 < arr[6] = 30, stop popping
Push 6
st = [0, 4, 6]
ans = [70, 30, 20, 0, 0, 0, 0]
```

### Processing Remaining Stack:

**Pop index 6 (value 30):**
```
st after pop = [0, 4]
range = 7 - 4 - 1 = 2 (window size 2)
ans[1] = max(30, 30) = 30
```

**Pop index 4 (value 10):**
```
st after pop = [0]
range = 7 - 0 - 1 = 6 (window size 6)
ans[5] = max(0, 10) = 10
```

**Pop index 0 (value 10):**
```
st after pop = []
range = 7 (window size 7)
ans[6] = max(0, 10) = 10
```

**After processing stack:**
```
ans = [70, 30, 20, 0, 0, 10, 10]
```

### Fill Missing Values:

```cpp
for(int i = n-2; i >= 0; i--) {
    ans[i] = max(ans[i], ans[i+1]);
}
```

**i = 5:** `ans[5] = max(10, 10) = 10`  
**i = 4:** `ans[4] = max(0, 10) = 10`  
**i = 3:** `ans[3] = max(0, 10) = 10`  
**i = 2:** `ans[2] = max(20, 10) = 20`  
**i = 1:** `ans[1] = max(30, 20) = 30`  
**i = 0:** `ans[0] = max(70, 30) = 70`

### Final Result:
```
ans = [70, 30, 20, 10, 10, 10, 10]
```

---

## 📊 Complexity Analysis

### Problem 1: Get Minimum From Stack

| Method | Time Complexity | Space Complexity | Pros | Cons |
|--------|----------------|------------------|------|------|
| Two Stack | O(1) all ops | O(2n) | Simple, No overflow | Extra space |
| Single Stack | O(1) all ops | O(n) | Space efficient | Complex encoding |

### Problem 2: Max of Min Windows  

| Method | Time Complexity | Space Complexity | Result |
|--------|----------------|------------------|---------|
| Brute Force | O(n³) | O(n) | TLE |
| Stack-based | O(n) | O(n) | Optimal |

---

## 🎓 Key Takeaways

### Stack Applications:
1. **Monotonic Stack**: Useful for finding next/previous smaller/larger elements
2. **Range Queries**: Stack helps find maximum range where an element satisfies conditions
3. **Optimization**: Stack-based solutions often reduce O(n²) or O(n³) to O(n)

### Problem-Solving Patterns:
1. **Auxiliary Data Structure**: Sometimes using extra space gives O(1) operations
2. **Mathematical Encoding**: Combine multiple values in single number
3. **Two-Phase Processing**: Process + Post-process for complete solution

### Common Pitfalls:
1. **Integer Overflow**: Be careful with mathematical encoding
2. **Edge Cases**: Handle empty stacks properly
3. **Range Calculation**: Off-by-one errors in window size calculation

---

## 🔗 Related Problems

1. **Largest Rectangle in Histogram**
2. **Trapping Rain Water**  
3. **Next Greater Element**
4. **Stock Span Problem**
5. **Maximum Area Rectangle in Binary Matrix**

---

*Happy Coding! 🚀*