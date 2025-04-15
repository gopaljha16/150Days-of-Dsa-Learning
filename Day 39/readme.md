---

# 🧠 Day 39: Recursion – Permutation with Repetition & Ways to Sum to N

---

## ✅ Problem 1: Leetcode – Permutation II (With Duplicates)

> **Goal**: Generate all unique permutations of an array that may contain duplicates.

### 🔁 Code:
```cpp
void permute2(vector<int> &arr , vector<vector<int>> &ans , int index ){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    vector<bool> visited(21, 0);  // tracks duplicates per level

    for(int i = index; i < arr.size(); i++){
        if(!visited[arr[i] + 10]){
            swap(arr[index], arr[i]);            // pick element
            permute2(arr, ans, index + 1);       // recur
            swap(arr[index], arr[i]);            // backtrack
            visited[arr[i] + 10] = 1;             // mark visited
        }
    }
}
```

### ✅ Explanation (Step-by-step):
- **visited[arr[i] + 10]** is used to skip duplicates on the same level.
- **swap and backtrack** ensure all unique permutations are generated.
- Recursive function places an element at current index and generates further permutations.

### 🌳 Recursion Tree:
Example: `arr = [1, 1, 2]`
```
Level 0: [1,1,2]
    → Level 1: [1,1,2] (skip 2nd 1)
        → Level 2: [1,1,2]
        → Level 2: [1,2,1]
    → Level 1: [2,1,1]
```

### 🧠 Output:
```
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
```

### ⏱ Time Complexity:
- Worst-case (no duplicates): `O(n! × n)`
- With duplicates (optimized): `< O(n! × n)`

### 🧠 Space Complexity:
- Stack space: `O(n)`
- Output storage: `O(n × n!)`

---

## ✅ Problem 2: GFG – Ways to Sum to N (Repetition Allowed)

> **Goal**: Count number of ways to sum to `N` using elements of the array. Repetition allowed.

### 🔁 Code:
```cpp
int waystoSum(int arr[], int m, int sum) {
    if(sum == 0) return 1;           // valid combination
    if(sum < 0) return 0;            // invalid path

    long long ans = 0;
    for(int i = 0; i < m; i++) {
        ans += waystoSum(arr, m, sum - arr[i]);
    }
    return ans % 1000000007;
}
```

### ✅ Explanation:
- You start with `sum` and try all elements.
- For each element `arr[i]`, recursively subtract it from `sum`.
- If `sum == 0`, you’ve found a valid combination.

### 🌳 Recursion Tree:
Example: `arr = [2,3], sum = 4`
```
sum=4
├── 2 → sum=2
│   ├── 2 → sum=0 ✅
│   └── 3 → sum=-1 ❌
└── 3 → sum=1
    └── 2 → sum=-1 ❌
    └── 3 → sum=-2 ❌
```
→ Total Valid Paths = 1

### 🧠 Output:
```
Input: arr = [2,3], sum = 4 → Output: 1
```

### ⏱ Time Complexity:
- Worst-case: `O(M^S)`
  - `M = size of array`, `S = sum`
- For each value of sum, trying `M` options.

### 🧠 Space Complexity:
- Stack depth: `O(S)`

---

✅ Optimized version (with DP) will reduce time to `O(S × M)` and space to `O(S)`.

---

Here’s the **detailed time and space complexity analysis** for both problems from **Day 39**:

---

## ✅ 1. **Leetcode Permutation II (With Duplicates)**
> Generates all **unique permutations** of an array possibly containing **duplicates**.

### 🔁 Code Overview:
```cpp
void permute2(vector<int> &arr , vector<vector<int>> &ans , int index ){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    vector<bool> visited(21, 0);  // tracks duplicates per level

    for(int i = index; i < arr.size(); i++){
        if(!visited[arr[i] + 10]){
            swap(arr[index], arr[i]);
            permute2(arr, ans, index + 1);
            swap(arr[index], arr[i]);
            visited[arr[i] + 10] = 1;
        }
    }
}
```

---

### ⏱ **Time Complexity:**

- In worst case (if all elements are **unique**), it behaves like **n!**.
- If duplicates exist, due to `visited[]`, it skips repeated branches, reducing total calls.

So,

- **Worst-case Time**: `O(n! × n)`
  - `n!` permutations
  - `O(n)` to copy current permutation to `ans`

- **Optimized-case Time**: `< O(n! × n)` due to pruning with `visited`

---

### 🧠 **Space Complexity:**

- **Auxiliary Stack Space**: `O(n)` – recursion depth
- **Visited array**: `O(21)` – constant
- **Result vector (`ans`)**: stores up to `n!` vectors of length `n` → `O(n × n!)` in worst-case

**Total Space:**
- `O(n × n!)` (for output) + `O(n)` (recursion) → dominated by output size

---

## ✅ 2. **GFG: Ways to Sum to N (With Repetition)**

> Given a set of numbers, count total number of **ways to sum up to N** where each element can be used **unlimited times**.

### 🔁 Code:
```cpp
int waystoSum(int arr[], int m, int sum) {
    if(sum == 0) return 1;
    if(sum < 0) return 0;

    long long ans = 0;
    for(int i = 0; i < m; i++) {
        ans += waystoSum(arr, m, sum - arr[i]);
    }
    return ans % 1000000007;
}
```

---

### ⏱ **Time Complexity:**

- Let `S = sum`, `M = number of array elements`
- In each call, we can branch to `M` further calls
- So total calls: **`O(M^S)`**

> Very slow for large `S` — needs **DP or memoization** to be efficient.

---

### 🧠 **Space Complexity:**

- **Recursion stack** can go as deep as `S` → `O(S)`
- No memoization used → purely recursive

**Total Space:** `O(S)` (stack depth)

> ⚠️ If you add **memoization** (like `dp[sum]`), time improves to `O(S × M)` and space to `O(S)`

---

### ✅ Summary Table:

| Problem                         | Time Complexity         | Space Complexity              |
|-------------------------------|--------------------------|-------------------------------|
| Permutation II (Unique)       | `O(n! × n)`              | `O(n × n!) + O(n)`            |
| Ways to Sum (Repetition)      | `O(M