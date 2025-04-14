Here are your **Day 37: Recursion Notes** on:

---

# 🧠 **Perfect Sum Problem & Target Sum with Repetition**

---

## ✅ 1. **Perfect Sum Problem (Without Repetition)**

### 🔸 Problem:
> Count the number of subsets of an array whose sum equals a given value.

---

### 🔸 Code:
```cpp
int PfSum(int arr[], int index, int n, int sum) {
    // Base Case: If we've gone through all elements
    if (index == n)
        return sum == 0;

    // Either we include the current element or we don't
    return PfSum(arr, index + 1, n, sum) +
           PfSum(arr, index + 1, n, sum - arr[index]);
}
```

### 🔹 Example:
```cpp
arr = {2,5,6,1}, sum = 9
Output: 2
Explanation: Valid subsets are [2,6,1] and [5, 2, 1] (but [2,6,1] is counted in both orders due to recursion)
```

---

### 🔸 Recursive Tree (Simplified):

```
PfSum(i=0, sum=9)
├── Not Take  → PfSum(i=1, sum=9)
│   ├── Not Take → ...
│   └── Take 5 → PfSum(i=2, sum=4)
└── Take 2 → PfSum(i=1, sum=7)
    ├── Not Take → ...
    └── Take 5 → PfSum(i=2, sum=2)
```

---

### 🔸 Flowchart:

```
         ┌─────────────┐
         │ index == n? │
         └─────┬───────┘
               │ No
               ▼
        ┌────────────────┐
        │ Return:        │
        │ PfSum(i+1, sum)│
        │  + PfSum(i+1, sum - arr[i]) │
        └────────────────┘
               │
               ▼
       If index == n && sum == 0 => return 1
```

---

### 🔸 Time and Space Complexity:

| Type           | Complexity |
|----------------|------------|
| Time           | O(2^n)     |
| Space (stack)  | O(n)       |

---

## ✅ 2. **Target Sum with Repetition Allowed**

### 🔸 Problem:
> Count number of ways to get target sum using elements **multiple times**.

---

### 🔸 Code:
```cpp
int SumRepetition(int arr[], int index, int n, int sum) {
    if (sum == 0) return 1;
    if (index == n || sum < 0) return 0;

    // Include element (stay at same index)
    // or exclude (move to next index)
    return SumRepetition(arr, index + 1, n, sum) +
           SumRepetition(arr, index, n, sum - arr[index]);
}
```

---

### 🔹 Example:
```cpp
arr = {2,3,4}, sum = 8
Output: 3
Explanation:
- [2,2,2,2]
- [2,2,4]
- [4,4]
```

---

### 🔸 Recursive Tree (Simplified):
```
SumRep(i=0, sum=8)
├── Not Take (i=1, sum=8)
│   ├── Not Take (i=2, sum=8)
│   └── Take 4 (i=2, sum=4) → Take 4 again → sum=0 ✅
└── Take 2 (i=0, sum=6)
    ├── Take 2 (i=0, sum=4)
        ├── Take 2 (i=0, sum=2)
            └── Take 2 (i=0, sum=0) ✅
```

---

### 🔸 Flowchart:

```
         ┌────────────┐
         │ sum == 0 ? │─► Yes → return 1
         └────┬───────┘
              │ No
        ┌──────────────┐
        │ sum < 0 or   │
        │ index == n ? │─► Yes → return 0
        └────┬─────────┘
             ▼
   ┌──────────────────────────┐
   │ return:                  │
   │ SumRep(i+1, sum) +       │
   │ SumRep(i, sum - arr[i])  │
   └──────────────────────────┘
```

---

### 🔸 Time and Space Complexity:

| Type           | Complexity |
|----------------|------------|
| Time           | O(2^target) (Exponential due to repeated calls) |
| Space (stack)  | O(target) |

---

## 📌 Key Differences:

| Feature                     | Perfect Sum          | Target Sum with Repetition |
|----------------------------|----------------------|-----------------------------|
| Elements reused?           | ❌ No                | ✅ Yes                       |
| Move to next index always? | ✅ Yes               | ❌ Only in "No" case         |
| Suitable for               | Subset selection     | Unbounded Knapsack-like     |

---

Absolutely! Let’s dive deep into the **Time and Space Complexity** of the **Target Sum with Repetition Allowed** problem. 👇

---

## ✅ Problem Recap
We want to count **how many ways** we can reach a **target sum** using elements from the array where **each element can be chosen multiple times**.

```cpp
int SumRepetition(int arr[], int index, int n, int sum) {
    if (sum == 0) return 1;
    if (index == n || sum < 0) return 0;

    return SumRepetition(arr, index + 1, n, sum) +
           SumRepetition(arr, index, n, sum - arr[index]);
}
```

---

## 🔍 Let's Understand the Calls

You have two choices at every step:
1. **Not Take** → go to the next index
2. **Take** → stay at the same index, subtract current element from sum

So for every call:
- You **either** move forward in the index,
- **Or** reduce the sum while staying at the same index.

---

## 🔸 Time Complexity (Brute-force Recursion)

Let’s say:
- `n = number of elements in the array`
- `target = the value we want to reach`

At worst, from each index we could:
- Stay at the **same index** (`index`) and reduce the `sum`
- Move to the **next index** (`index + 1`) without reducing the sum

This means for each possible `index` and `sum`, we make **2 recursive calls**.

### 🔹 So Time Complexity is:  
```
T(n, sum) = O(2^sum)
```

Why?
- Because the branching only happens based on `sum`, not really on `n`, due to the ability to stay on the same index.
- The number of paths depends heavily on how many ways we can reduce `sum` using combinations.

✅ It’s **exponential**, since each sum may be reduced by different paths.

---

## 🔸 Space Complexity

### 🔹 Space = Maximum Depth of Recursion Tree

Each recursive call adds a new function call to the **call stack**.

Let’s see the worst-case scenario:
- Suppose we **always take** the element (i.e., call with same index)
- The sum keeps decreasing until it becomes 0
- So, maximum depth of recursion = `sum`

### 🔹 So Space Complexity is:
```
Space = O(sum)
```

Because:
- In worst case, we keep reducing `sum` in each call.
- Stack holds `sum` levels deep before reaching the base case.

---

## 📦 Summary

| Metric           | Value         | Reasoning |
|------------------|---------------|-----------|
| **Time Complexity** | O(2^sum)       | Due to branching on "take" and "not take" for each sum |
| **Space Complexity**| O(sum)         | Because max recursion depth is sum (in "take" path) |

---

