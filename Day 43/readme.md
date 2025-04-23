Great! Here's a detailed GitHub-style note for **Day 43: Recursion - Print N-bit Binary Numbers Having More 1s than 0s**, including:

- 🔍 Code Explanation (Line-by-line)
- 🧠 Logic + Flow
- 🧪 Dry Run with Example
- 🔁 Recursion Tree Visualization
- 📈 Time and Space Complexity Analysis

---

# 📘 Day 43: Recursion - N-Bit Binary Numbers (More 1s than 0s)

### ❓ Problem Statement
Generate all **N-bit binary numbers** such that at every prefix of the number, the number of `1`s is **greater than or equal** to the number of `0`s.

> Example for N = 3:
```
111
110
101
```

---

## 🧠 Core Idea

- We use **backtracking** to build valid strings.
- We can always place `1`.
- We can only place `0` **if number of 0s < number of 1s**.

---

## 🔍 Code with Explanation

```cpp
class Solution {
public:	
    void printBit(int n, vector<string> &ans, string &temp, int zero, int one) {
        // ✅ Base case: If length of string = n, add to answer
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        // 🔁 Always try to add '1'
        temp.push_back('1');
        printBit(n, ans, temp, zero, one + 1);
        temp.pop_back(); // 🔙 backtrack

        // 🔁 Add '0' only if zero < one
        if(zero < one) {
            temp.push_back('0');
            printBit(n, ans, temp, zero + 1, one);
            temp.pop_back(); // 🔙 backtrack
        }
    }

    vector<string> NBitBinary(int n) {
        vector<string> ans;
        string temp;
        printBit(n, ans, temp, 0, 0);
        return ans;
    }
};
```

---

## 📊 Dry Run Example

Let's take `n = 3`

```
Start: temp="", zero=0, one=0

→ Add '1' → temp="1", zero=0, one=1
  → Add '1' → temp="11", zero=0, one=2
    → Add '1' → temp="111", zero=0, one=3 ✅ added
    → Backtrack
    → Add '0' → temp="110", zero=1, one=2 ✅ added
  → Backtrack
  → Add '0' → temp="10", zero=1, one=1
    → Add '1' → temp="101", zero=1, one=2 ✅ added
    → '0' not allowed (zero == one)
```

✅ Output:
```
111
110
101
```

---

## 🌳 Recursion Tree (Visual)

Here's a text-style tree. You can visualize it or ask me for an image!

```
Start("")
 └── 1
     └── 11
         └── 111 ✅
         └── 110 ✅
     └── 10
         └── 101 ✅
```

---

## 🧮 Time and Space Complexity

### ⏱️ Time Complexity

- **Worst-case:** Each level has up to 2 calls.
- But due to the **zero < one** restriction, many branches are pruned.
- Hence, total outputs = `Fibonacci-like` growth → **O(2^n)** (upper bound)

### 🧠 Space Complexity

- **Recursive stack:** O(n) (height of recursion tree)
- **Output space:** O(k × n) where `k` is number of valid strings

---

## ✅ Key Concepts

- **Backtracking:** Add, explore, backtrack
- **Constraints in recursion:** Use conditions to prune invalid paths
- **Prefix rule:** Ensure at any point, number of 1s ≥ number of 0s

---
