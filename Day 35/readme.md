Here's your detailed **Day 35: Recursion on Subsequence** notes, explained deeply with recursion tree, code explanation, examples, and debugging insights.

---

# 🧠 Day 35: Recursion on Subsequence  
**Topics:**
- Generating all subsequences of an array
- Generating all subsequences of a string
- Generating valid parentheses (Leetcode #22)

---

## 🔁 1. Print All Subsequences of an Array

### ✅ Code:
```cpp
void Subseq(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> temp) {
    if (index == n) {
        ans.push_back(temp);
        return;
    }
    // Exclude
    Subseq(arr, index + 1, n, ans, temp);
    // Include
    temp.push_back(arr[index]);
    Subseq(arr, index + 1, n, ans, temp);
}
```

### 🌳 Recursion Tree Example for arr = {1, 2}:
```
Subseq(index = 0, temp = [])
|
├── Exclude 1 → Subseq(index = 1, temp = [])
|    ├── Exclude 2 → Subseq(index = 2, temp = []) → []
|    └── Include 2 → Subseq(index = 2, temp = [2]) → [2]
|
└── Include 1 → Subseq(index = 1, temp = [1])
     ├── Exclude 2 → Subseq(index = 2, temp = [1]) → [1]
     └── Include 2 → Subseq(index = 2, temp = [1,2]) → [1,2]
```

### 🔍 Output:
```
[]
[2]
[1]
[1, 2]
```

### 🧠 Time Complexity:
- **O(2ⁿ)** → Each element has two choices: include or not.

### 💾 Space Complexity:
- **O(n)** → At max depth, temp vector can be of size `n`.

---

## 🔡 2. Print All Subsequences of a String

### ✅ Code:
```cpp
void StringSub(string str, int index, int n, vector<string> &ans, string &temp) {
    if (index == n) {
        ans.push_back(temp);
        return;
    }
    StringSub(str, index + 1, n, ans, temp); // Exclude
    temp.push_back(str[index]);              // Include
    StringSub(str, index + 1, n, ans, temp);
    temp.pop_back();                         // Backtrack
}
```

### 🌳 Recursion Tree Example for "ab":
```
StringSub(index = 0, temp = "")
|
├── Exclude 'a' → index = 1, temp = ""
|    ├── Exclude 'b' → index = 2 → ""
|    └── Include 'b' → index = 2 → "b"
|
└── Include 'a' → index = 1, temp = "a"
     ├── Exclude 'b' → index = 2 → "a"
     └── Include 'b' → index = 2 → "ab"
```

### 🔍 Output:
```
""
"b"
"a"
"ab"
```

### 🔁 Time & Space:
- **Time:** O(2ⁿ)
- **Space:** O(n)

---

## 🧬 3. Generate Parentheses (Leetcode 22)

### ✅ Code:
```cpp
void Parentheses(int n, int left, int right, vector<string> &ans, string &temp) {
    if (left + right == 2 * n) {
        ans.push_back(temp);
        return;
    }
    if (left < n) {
        temp.push_back('(');
        Parentheses(n, left + 1, right, ans, temp);
        temp.pop_back(); // backtrack
    }
    if (right < left) {
        temp.push_back(')');
        Parentheses(n, left, right + 1, ans, temp);
        temp.pop_back(); // backtrack
    }
}
```

### 🌳 Tree for n = 2:
```
(
  ((
    (()
      (())
    (()
  ()
    ()(
      ()()
```

### 🧠 Logic:
- Only add '(' if `left < n`
- Only add ')' if `right < left`

### 🔍 Output:
```
(()) 
()()
```

### 💡 Time Complexity:
- **O(2ⁿ)** worst case  
- But total valid combinations = **Catalan(n)** ≈ `O(4ⁿ / sqrt(n))`

### 💾 Space Complexity:
- **O(n)** per call stack

---

## 🧪 Debugging Tips:
- Use `cout << index << " " << temp << endl;` to debug
- Backtracking (like `temp.pop_back()`) is essential to reset state

---

## 📘 Summary Table:

| Problem                  | Time Complexity | Space Complexity | Notes                         |
|--------------------------|------------------|-------------------|-------------------------------|
| Array Subsequence        | O(2ⁿ)           | O(n)              | Choose/Not-choose recursion   |
| String Subsequence       | O(2ⁿ)           | O(n)              | Backtracking essential        |
| Generate Parentheses     | Catalan(n)      | O(n)              | Valid paren rules + backtrack |

---

If you'd like, I can generate visual recursion trees or flowcharts for each — just say the word!