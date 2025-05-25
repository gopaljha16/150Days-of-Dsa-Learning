Here are your **Day 66: Stack Problems Notes** in a clean, GitHub-style format with deep explanations, full C++ code, dry runs, and visual logic.

---

# 📚 Day 66: Stack Problems – NGE, NSE, Stock Span

Welcome to Day 66 of DSA! Today we tackle **stack-based problems** that appear frequently in interviews:

* ✅ Next Greater Element (NGE)
* ✅ Next Smaller Element (NSE)
* ✅ Stock Span Problem

---

## 🔄 1. Next Greater Element (NGE)

### ❓ Problem Statement

For each element in an array, find the **next greater element to its right**. If none, store `-1`.

---

### 🧠 Approach: **Monotonic Stack**

* Traverse from **right to left**.
* Use a stack to store **candidates** for the next greater element.
* For current element:

  * Pop from stack until top is **greater**.
  * If stack is not empty → top is the **NGE**.
  * Push current element to stack.

---

### ✅ C++ Code

```cpp
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) res[i] = stk.top();
        stk.push(arr[i]);
    }

    return res;
}
```

---

### 🧪 Dry Run

**Input:** `[4, 5, 2, 10]`

| i | arr\[i] | Stack       | NGE |
| - | ------- | ----------- | --- |
| 3 | 10      | \[10]       | -1  |
| 2 | 2       | \[10, 2]    | 10  |
| 1 | 5       | \[10, 5]    | 10  |
| 0 | 4       | \[10, 5, 4] | 5   |

**Output:** `[5, 10, 10, -1]`

---

### 🧮 Complexity

* **Time:** O(n)
* **Space:** O(n)

---

## ⬇️ 2. Next Smaller Element (NSE)

### ❓ Problem Statement

Find the **next smaller element to the right** of each element in the array.

---

### 🧠 Approach: Similar to NGE

* Traverse **right to left**.
* Use a stack to store **monotonic increasing** elements.
* For current element:

  * Pop from stack while top ≥ current.
  * Top of stack (if any) is the NSE.
  * Push current element.

---

### ✅ C++ Code

```cpp
vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() >= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) res[i] = stk.top();
        stk.push(arr[i]);
    }

    return res;
}
```

---

### 🧪 Dry Run

**Input:** `[4, 8, 5, 2, 25]`

| i | arr\[i] | Stack         | NSE |
| - | ------- | ------------- | --- |
| 4 | 25      | \[25]         | -1  |
| 3 | 2       | \[2]          | -1  |
| 2 | 5       | \[2, 5]       | 2   |
| 1 | 8       | \[2, 5, 8]    | 5   |
| 0 | 4       | \[2, 5, 8, 4] | 2   |

**Output:** `[2, 5, 2, -1, -1]`

---

### 🧮 Complexity

* **Time:** O(n)
* **Space:** O(n)

---

## 📈 3. Stock Span Problem

### ❓ Problem Statement

Given daily stock prices, return an array `span[]` where:

* `span[i]` = **max days before today (inclusive)** the price was **less than or equal** to `price[i]`.

---

### 🧠 Approach: Use stack of **indices**

* For each `i`:

  * Pop while `price[stk.top()] <= price[i]`.
  * If stack empty → span is `i + 1` (all previous prices were smaller).
  * Else → span is `i - stk.top()`.

---

### ✅ C++ Code

```cpp
vector<int> calculateSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && price[stk.top()] <= price[i]) {
            stk.pop();
        }
        span[i] = (stk.empty()) ? (i + 1) : (i - stk.top());
        stk.push(i);
    }

    return span;
}
```

---

### 🧪 Dry Run

**Input:** `[100, 80, 60, 70, 60, 75, 85]`

| Day | Price | Stack         | Span |
| --- | ----- | ------------- | ---- |
| 0   | 100   | \[0]          | 1    |
| 1   | 80    | \[0, 1]       | 1    |
| 2   | 60    | \[0, 1, 2]    | 1    |
| 3   | 70    | \[0, 1, 3]    | 2    |
| 4   | 60    | \[0, 1, 3, 4] | 1    |
| 5   | 75    | \[0, 1, 5]    | 4    |
| 6   | 85    | \[0, 6]       | 6    |

**Output:** `[1, 1, 1, 2, 1, 4, 6]`

---

### 🧮 Complexity

* **Time:** O(n)
* **Space:** O(n)

---

## 📊 Summary Table

| Problem              | Stack Type           | Direction     | Goal                        |
| -------------------- | -------------------- | ------------- | --------------------------- |
| Next Greater Element | Monotonic Decreasing | Right to Left | First greater on right      |
| Next Smaller Element | Monotonic Increasing | Right to Left | First smaller on right      |
| Stock Span           | Index Stack          | Left to Right | Days since price was higher |

---

## 📌 Key Takeaways

* These problems **reduce linear brute force** `O(n²)` into **O(n)** using **monotonic stacks**.
* When finding:

  * **Next Greater**: Stack holds decreasing elements.
  * **Next Smaller**: Stack holds increasing elements.
  * **Stock Span**: Stack holds **indices** and helps calculate span by comparing values.

---

