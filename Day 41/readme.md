---

# 🧠 Day 41: Recursion - Josephus Problem | Predict the Winner

## 🔍 Problem Statement
Given `n` people numbered from 1 to `n`, standing in a circle. Every `k`th person is eliminated from the circle. Find the winner.

Leetcode Problem: [1823. Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

---

## ✅ Approach 1: Brute Force using Recursion + Boolean Array

```cpp
class Solution {
public:
    int winner(vector<bool>& person, int n, int index, int person_left, int k) {
        // Base Case: Only one person is left
        if (person_left == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == 0)
                    return i;  // return the index of the last remaining person
            }
        }

        // Calculate the person to kill (0-based index)
        int kill = (k - 1) % person_left;

        // Move `kill` steps forward to find the k-th alive person
        while (kill--) {
            index = (index + 1) % n;
            while (person[index] == 1) {
                index = (index + 1) % n;
            }
        }

        // Kill the person
        person[index] = 1;

        // Move to next alive person
        while (person[index] == 1) {
            index = (index + 1) % n;
        }

        // Recursive call with updated state
        return winner(person, n, index, person_left - 1, k);
    }

    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0);  // initially all are alive
        return winner(person, n, 0, n, k) + 1;  // convert 0-based to 1-based
    }
};
```

### 📌 Explanation
- We use a `vector<bool>` to track who is alive (`0`) or dead (`1`).
- We simulate each round of elimination.
- `kill = (k - 1) % person_left` determines how many people we skip.
- We keep moving forward in the circle to find the `k-th` alive person.
- Once eliminated, the recursion continues with `person_left - 1`.

### 💡 Example:
```
n = 5, k = 2
People = [1, 2, 3, 4, 5] (0-indexed internally)
Elimination Order:
- Remove person 2 (index 1)
- Remove person 4 (index 3)
- Remove person 1 (index 0)
- Remove person 5 (index 4)
Winner = person 3
```

---

## ⚡ Optimized Approach: Mathematical Recursion (Josephus Formula)

```cpp
class Solution {
public:
    int winner(int n, int k) {
        if (n == 1)
            return 0; // base case
        return (winner(n - 1, k) + k) % n; // Josephus recursive formula
    }

    int findTheWinner(int n, int k) {
        return winner(n, k) + 1; // convert 0-based to 1-based
    }
};
```

### 🧠 Josephus Formula
- Let `f(n, k)` be the safe position when `n` people and every `k`th person is eliminated.
- `f(n, k) = (f(n - 1, k) + k) % n` with base `f(1, k) = 0`

### 🌳 Recursion Tree for Example: `n=5, k=2`
```
f(5) = (f(4) + 2) % 5
     = ((f(3) + 2) % 4 + 2) % 5
     = (( (f(2) + 2) % 3 + 2) % 4 + 2) % 5
     = (( ((f(1) + 2) % 2 + 2) % 3 + 2) % 4 + 2) % 5
     = winner index = 2 (so winner is person 3)
```

---

## 🧠 Time and Space Complexity

### ✅ Brute Force
- **Time Complexity:** O(n * k)  
  For each person removed, we may iterate through k persons to find the next.
- **Space Complexity:** O(n)  
  Due to the boolean vector and recursive stack.

### ⚡ Optimized (Josephus)
- **Time Complexity:** O(n)  
  We solve `f(n)` by computing all values down to `f(1)` recursively.
- **Space Complexity:** O(n)  
  Due to recursion stack (can be reduced with tail recursion or iteration).

---

## 🧪 Output Example:
```cpp
n = 5, k = 2
Output: 3

n = 6, k = 5
Output: 1

n = 1, k = 1
Output: 1
```

---

## 🔁 Visualization: Flowchart & Elimination Order

### Flow of Brute Force:
1. Count k people clockwise.
2. Eliminate the k-th person.
3. Move to next alive person.
4. Repeat until one remains.

### Flow of Optimized:
- Use Josephus formula recursively.
- Apply modulo to rotate positions.

🧾 Result: Predictable, efficient circular elimination.

---

