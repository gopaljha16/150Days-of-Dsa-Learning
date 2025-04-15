# Day 38: Recursion - Permutations (Array & String)

---

## 🔍 Problem Statement
> Generate all permutations of a given array or string using recursion.

---

## ✅ Brute Force: Permutations Using Visited Array

```cpp
void Permutation(int arr[], vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited) {
    // Base case: if temp has same size as arr, we have one permutation
    if (visited.size() == temp.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(arr[i]);
            Permutation(arr, ans, temp, visited);
            temp.pop_back();           // backtrack
            visited[i] = false;        // unmark
        }
    }
}
```

### 🧩 Dry Run Example
Input: `arr[] = {1, 2}`

Recursion Tree:
```
                 []
               /    \
            [1]     [2]
           /           \
        [1,2]         [2,1]
```

### ⚠️ Time and Space Complexity:
- **Time**: O(N!) permutations * O(N) copying each = **O(N * N!)**
- **Space**: O(N) recursion + O(N) temp + O(N) visited = **O(N)**

---

## 🌟 Optimized Approach (In-place Swapping)

```cpp
void permutation(vector<int> &arr, vector<vector<int>> &ans, int index) {
    // Base case: one permutation ready
    if (index == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        permutation(arr, ans, index + 1);
        swap(arr[index], arr[i]); // backtrack
    }
}
```

### 🔎 Dry Run for [1,2,3]
Recursion Tree (partial):
```
[1,2,3] -> swap(1,1)
   [1,2,3] -> swap(2,2)
      [1,2,3]
   [1,3,2] -> swap(2,2)
      [1,3,2]
[2,1,3] -> swap(1,1)...
```

### ⏱ Complexity:
- **Time**: O(N!)
- **Space**: O(1) extra (in-place) + recursion O(N) ⇒ **O(N)**

---

## 👤 String Permutation (will be added soon)
```cpp
void permuteString(string &s, int index, vector<string> &ans) {
    if(index == s.length()) {
        ans.push_back(s);
        return;
    }

    for(int i = index; i < s.length(); i++) {
        swap(s[i], s[index]);
        permuteString(s, index+1, ans);
        swap(s[i], s[index]); // backtrack
    }
}
```

---

## 🔄 Debugging Tips:
- Use print statements in recursion to log temp/visited state.
- Ensure you **backtrack correctly** (undo swap or pop_back).

---

## ✨ Final Thoughts:
- Start with brute-force + visited for clarity
- Move to in-place optimized version for better performance
- Always analyze recursion tree to understand behavior

