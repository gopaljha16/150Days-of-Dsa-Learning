# Day 68: Celebrity Problem - DSA Study Notes

## 📋 Problem Statement

**Platform**: GeeksforGeeks  
**Difficulty**: Medium  
**Topic**: Stack, Matrix, Graph Theory

In a party of N people, a celebrity is a person who:
1. **Knows no one** (doesn't know any other person)
2. **Is known by everyone** (every other person knows the celebrity)

Given a square matrix `mat[][]` where `mat[i][j] = 1` means person `i` knows person `j`, find the celebrity. If no celebrity exists, return -1.

### Example:
```
Input: mat[][] = {{0, 0, 1, 0},
                  {0, 0, 1, 0},
                  {0, 0, 0, 0},
                  {0, 0, 1, 0}}
Output: 2
Explanation: Person 2 knows no one and everyone knows person 2.
```

---

## 🎯 Problem Analysis

### Key Insights:
- **Celebrity Property**: If person A knows person B, then A cannot be a celebrity
- **Elimination Strategy**: We can eliminate n-1 people using n-1 comparisons
- **Validation Required**: The remaining candidate must be verified

---

## 🚀 Approach Explanation

### Strategy: **Stack-based Elimination + Verification**

1. **Initial Assumption**: Everyone could potentially be a celebrity
2. **Pairwise Elimination**: Compare two people at a time and eliminate one
3. **Final Validation**: Check if the remaining candidate satisfies celebrity conditions

### Why This Works:
- In each comparison, we can definitively eliminate exactly one person
- After n-1 eliminations, only one candidate remains
- This candidate needs verification since our elimination was based on partial information

---

## 💻 Code Implementation

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> st;
        int n = mat.size();

        // Step 1: Push all people into stack
        for(int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: Eliminate non-celebrities
        while(st.size() > 1) {
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();

            if(mat[first][second] == 1) {
                st.push(second); // first knows second, so first ≠ celebrity
            } else {
                st.push(first);  // first doesn't know second, so second ≠ celebrity
            }
        }

        // Step 3: Handle edge case
        if(st.empty()) return -1;

        // Step 4: Validate candidate
        int candidate = st.top();
        
        for(int i = 0; i < n; i++) {
            if(i != candidate) {
                if(mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};
```

---

## 🔄 Algorithm Flow Chart

```
START
  ↓
Initialize Stack with all people [0, 1, 2, ..., n-1]
  ↓
┌─────────────────────────────────┐
│ While stack.size() > 1          │
│  ┌─────────────────────────────┐│
│  │ Pop two people (A, B)       ││
│  │          ↓                  ││
│  │ Does A know B?              ││
│  │    ↙         ↘              ││
│  │  YES          NO             ││
│  │   ↓            ↓             ││
│  │Push B      Push A            ││
│  │(A eliminated) (B eliminated) ││
│  └─────────────────────────────┘│
└─────────────────────────────────┘
  ↓
Is stack empty?
  ↙         ↘
YES          NO
 ↓            ↓
Return -1   Get candidate = stack.top()
             ↓
        ┌─────────────────────────────┐
        │ For each person i:          │
        │ Check if candidate knows i  │
        │ Check if i knows candidate  │
        │      ↓                      │
        │ Any condition fails?        │
        │   ↙            ↘            │
        │ YES             NO          │
        │  ↓              ↓           │
        │Return -1    Return candidate│
        └─────────────────────────────┘
          ↓
        END
```

---

## 📝 Pseudocode

```
ALGORITHM CelebrityProblem(mat):
    INPUT: 2D matrix mat[n][n] where mat[i][j] = 1 if i knows j
    OUTPUT: Celebrity index or -1

    1. CREATE empty stack
    2. FOR i = 0 to n-1:
           PUSH i into stack
    
    3. WHILE stack.size() > 1:
           first = POP from stack
           second = POP from stack
           
           IF mat[first][second] == 1:
               PUSH second back to stack
           ELSE:
               PUSH first back to stack
    
    4. IF stack is empty:
           RETURN -1
    
    5. candidate = POP from stack
    
    6. FOR i = 0 to n-1:
           IF i != candidate:
               IF mat[candidate][i] == 1 OR mat[i][candidate] == 0:
                   RETURN -1
    
    7. RETURN candidate
```

---

## 🔍 Code Walkthrough with Example

Let's trace through with matrix:
```
mat = [[0,0,1,0],
       [0,0,1,0], 
       [0,0,0,0],
       [0,0,1,0]]
```

### Step-by-Step Execution:

**Initial State:**
```
Stack: [3, 2, 1, 0] (top to bottom)
n = 4
```

**Iteration 1:**
```
first = 3, second = 2
mat[3][2] = 1 → Person 3 knows Person 2
Action: Push 2 back (Person 3 eliminated)
Stack: [2, 1, 0]
```

**Iteration 2:**
```
first = 2, second = 1  
mat[2][1] = 0 → Person 2 doesn't know Person 1
Action: Push 2 back (Person 1 eliminated)
Stack: [2, 0]
```

**Iteration 3:**
```
first = 2, second = 0
mat[2][0] = 0 → Person 2 doesn't know Person 0  
Action: Push 2 back (Person 0 eliminated)
Stack: [2]
```

**Validation Phase:**
```
candidate = 2
Check i = 0: mat[2][0] = 0 ✓, mat[0][2] = 1 ✓
Check i = 1: mat[2][1] = 0 ✓, mat[1][2] = 1 ✓  
Check i = 3: mat[2][3] = 0 ✓, mat[3][2] = 1 ✓
```

**Result:** Return 2 (Person 2 is the celebrity)

---

## 🎨 Visual Representation

### Matrix Interpretation:
```
    0  1  2  3
0 [ 0  0  1  0 ]  → Person 0 knows Person 2
1 [ 0  0  1  0 ]  → Person 1 knows Person 2  
2 [ 0  0  0  0 ]  → Person 2 knows nobody
3 [ 0  0  1  0 ]  → Person 3 knows Person 2
```

### Elimination Process:
```
Round 1: Compare 3 vs 2
   3 knows 2 → Eliminate 3
   
Round 2: Compare 2 vs 1  
   2 doesn't know 1 → Eliminate 1
   
Round 3: Compare 2 vs 0
   2 doesn't know 0 → Eliminate 0
   
Final: Person 2 remains
```

---

## ⏱️ Time Complexity Analysis

### **Time Complexity: O(n)**

**Breakdown:**
1. **Initialization**: O(n) - Pushing n elements to stack
2. **Elimination Phase**: O(n) - Exactly (n-1) comparisons to eliminate (n-1) people
3. **Validation Phase**: O(n) - Check candidate against all other people

**Total**: O(n) + O(n) + O(n) = O(n)

### **Why O(n) and not O(n²)?**
- We're NOT checking every pair of people
- Each person is eliminated in exactly one comparison
- Validation requires only n checks, not n² checks

---

## 💾 Space Complexity Analysis

### **Space Complexity: O(n)**

**Space Usage:**
- **Stack Storage**: O(n) - In worst case, stack holds all n people
- **Variables**: O(1) - Only a few integer variables
- **No additional data structures** needed

**Total**: O(n)

### **Can we optimize to O(1)?**
Yes! We can use two pointers instead of a stack:
```cpp
// Space-optimized version
int left = 0, right = n-1;
while(left < right) {
    if(mat[left][right] == 1) left++;
    else right--;
}
// left is the candidate
```

---

## 🐛 Common Debugging Scenarios

### **Issue 1: Stack becomes empty**
```cpp
// Problem: What if no celebrity exists?
if(st.empty()) return -1; // Handle this case!
```

### **Issue 2: Validation logic error**
```cpp
// Wrong validation:
if(mat[candidate][i] == 1 && mat[i][candidate] == 0)

// Correct validation:  
if(mat[candidate][i] == 1 || mat[i][candidate] == 0)
// Celebrity should know NO ONE AND be known by EVERYONE
```

### **Issue 3: Self-comparison in validation**
```cpp
// Always skip self-comparison:
if(i != candidate) {
    // Only then check conditions
}
```

---

## 🧪 Test Cases

### **Test Case 1: Celebrity exists**
```cpp
Input: [[0,0,1,0],
        [0,0,1,0],
        [0,0,0,0],
        [0,0,1,0]]
Expected: 2
Explanation: Person 2 is known by all, knows none
```

### **Test Case 2: No celebrity**
```cpp
Input: [[0,1,0],
        [0,0,0], 
        [1,1,0]]
Expected: -1
Explanation: No one satisfies celebrity condition
```

### **Test Case 3: Single person**
```cpp
Input: [[0]]
Expected: 0
Explanation: Only person, trivially a celebrity
```

### **Test Case 4: Everyone knows everyone**
```cpp
Input: [[0,1,1],
        [1,0,1],
        [1,1,0]]
Expected: -1
Explanation: No celebrity possible
```

---

## 🎓 Key Takeaways

### **Problem-Solving Insights:**
1. **Elimination Strategy**: Sometimes we can eliminate candidates efficiently
2. **Two-Phase Approach**: Candidate selection + validation is a common pattern
3. **Stack Usage**: Stack naturally handles the elimination process

### **Optimization Lessons:**
1. **Space Optimization**: Stack can be replaced with two pointers
2. **Time Optimization**: Avoid O(n²) by smart elimination
3. **Edge Cases**: Always handle empty results and single elements

### **Related Problems:**
- Find the majority element
- Leader in an array  
- Peak element finding

---

## 📚 Alternative Solutions

### **Approach 2: Two Pointers (Space Optimized)**
```cpp
int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int candidate = 0;
    
    // Find candidate
    for(int i = 1; i < n; i++) {
        if(mat[candidate][i] == 1) {
            candidate = i;
        }
    }
    
    // Validate candidate
    for(int i = 0; i < n; i++) {
        if(i != candidate) {
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }
    }
    return candidate;
}
```

**Trade-offs:**
- **Space**: O(1) vs O(n)
- **Readability**: Stack version is more intuitive
- **Time**: Both are O(n)

---

