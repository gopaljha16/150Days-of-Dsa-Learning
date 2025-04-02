# Day 28: Recursion Problems on LeetCode & GFG

## Fibonacci Sequence - LeetCode (Easy Level)

### Problem Statement
The Fibonacci sequence is defined as follows:
- `fib(0) = 0`
- `fib(1) = 1`
- `fib(n) = fib(n-1) + fib(n-2)` for `n >= 2`

### Recursive Solution
```cpp
class Solution {
public:
    int fib(int n) {
        if (n <= 1) // Base condition: if n is 0 or 1, return n
            return n;
        
        return fib(n - 1) + fib(n - 2); // Recursive call to calculate Fibonacci
    }
};
```

### Explanation
1. **Base Case:** If `n` is `0` or `1`, we return `n` directly.
2. **Recursive Case:** We call `fib(n-1)` and `fib(n-2)`, summing up their results to get `fib(n)`.

#### Example 1:
**Input:** `fib(5)`

**Recursive Calls:**
```
                fib(5)
               /      \
          fib(4)    fib(3)
          /    \      /    \
     fib(3)  fib(2) fib(2) fib(1)
     /   \     /  \    /  \
fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
 /   \  
fib(1) fib(0) 
```

**Output:** `5`

### Recursive Tree for fib(5):
```
              fib(5)
             /      \
        fib(4)    fib(3)
       /    \      /    \
   fib(3)  fib(2) fib(2) fib(1)
   /   \     /  \    /  \
fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
 /   \  
fib(1) fib(0) 
```

### Time Complexity
- The recursion has a **time complexity of O(2^n)**, as it makes two recursive calls at each step.

## Climbing Stairs (Fibonacci Pattern) - LeetCode
### Problem Statement
A person is climbing `n` stairs. They can climb either `1` or `2` steps at a time. Find the number of ways they can reach the top.

### Iterative Dynamic Programming Solution
```cpp
int climbStairs(int n) {
    if (n <= 1) // Base case
        return 1;
    
    double last = 1, prev = 1, curr;
    for (int i = 2; i <= n; i++) {
        curr = prev + last; // The current step count is the sum of the last two steps
        last = prev;  // Update last to previous
        prev = curr;  // Move previous to current
    }
    return curr;
}
```

### Explanation
1. If `n <= 1`, return `1` (only one way to climb zero or one stairs).
2. Use iteration to update `curr` as the sum of the last two values.
3. This method avoids recursion and **runs in O(n) time complexity**.

#### Example 1:
**Input:** `n = 4`

**Calculation:**
```
Step 1: last = 1, prev = 1, curr = prev + last (2)
Step 2: last = 1, prev = 2, curr = prev + last (3)
Step 3: last = 2, prev = 3, curr = prev + last (5)
```
**Output:** `5` (ways to climb 4 stairs)

---

## GCD (Greatest Common Divisor) - GFG
### Problem Statement
Find the greatest common divisor (GCD) of two numbers using recursion.

### Recursive Solution
```cpp
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) // Base case: If b is 0, return a
            return a;
        return gcd(b, a % b); // Recursive call with (b, remainder of a/b)
    }
};
```

### Explanation
1. **Base Case:** If `b == 0`, return `a`.
2. **Recursive Case:** Call `gcd(b, a % b)` (Euclidean Algorithm).

#### Example 1:
**Input:** `gcd(48, 18)`

**Recursive Calls:**
```
gcd(48, 18) → gcd(18, 48 % 18 = 12)
gcd(18, 12) → gcd(12, 18 % 12 = 6)
gcd(12, 6)  → gcd(6, 12 % 6 = 0)
gcd(6, 0)   → return 6
```

**Output:** `6`

### Recursive Tree for gcd(48,18):
```
gcd(48,18)
    ↓
gcd(18,12)
    ↓
gcd(12,6)
    ↓
gcd(6,0) → return 6
```

### Time Complexity
- The time complexity is **O(log(min(a, b)))**, since we reduce the number at each step.

---

## Summary Table
| Problem | Approach | Time Complexity | Space Complexity |
|---------|----------|----------------|------------------|
| Fibonacci | Recursion | O(2^n) | O(n) |
| Climbing Stairs | Iteration (DP) | O(n) | O(1) |
| GCD | Recursion (Euclidean Algorithm) | O(log n) | O(log n) |

These recursion problems demonstrate different approaches:
1. **Fibonacci** - Shows the exponential growth of recursive calls.
2. **Climbing Stairs** - Uses an iterative approach to optimize.
3. **GCD** - Efficient recursion with the Euclidean algorithm.

