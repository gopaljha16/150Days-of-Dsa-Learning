Here are your detailed **Day 65 Notes on Stack** covering multiple stack-based problems with **code explanations, dry runs, and deep logic**.

---

# 🚀 Day 65: Stack Problems – Full Notes

---

## 📘 1. **Reverse a String using Stack** (Leetcode)

### 🔹 Problem:

Given a character array `s`, reverse it **in-place** using a stack.

### ✅ Approach:

1. Push each character into the stack.
2. Pop characters and overwrite the array.

### 🧠 Intuition:

Stacks follow **LIFO**. Last inserted char will come out first → reversed string.

### ✅ Code with Comments:

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        // Step 1: Push each character to the stack
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }

        // Step 2: Pop and overwrite array
        int i = 0;
        while (!st.empty()) {
            s[i] = st.top();  // Assign top element
            st.pop();         // Remove from stack
            i++;
        }
    }
};
```

### 🔁 Dry Run:

Input: `['h','e','l','l','o']`
Stack after push: `['h','e','l','l','o']`
Pop → `o` → `s[0] = o`
Pop → `l` → `s[1] = l` ...
Final output: `['o','l','l','e','h']`

---

## 📘 2. **Insert at Bottom of Stack** (GFG Medium)

### 🔹 Problem:

Insert an element at the **bottom** of the stack.

### ✅ Approach:

1. Pop all elements to a temp stack.
2. Push the new element.
3. Restore elements back from temp.

### ✅ Code with Comments:

```cpp
class Solution {
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> temp;

        // Step 1: Empty original stack into temp
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        // Step 2: Insert new element
        st.push(x);

        // Step 3: Restore back
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return st;
    }
};
```

### 🧠 Dry Run:

Stack = \[1, 2, 3], x = 0
Temp = \[3, 2, 1]
After x → Stack = \[0]
Restore → Stack = \[0, 1, 2, 3]

---

## 📘 3. **Valid Parentheses** (Leetcode #20)

### 🔹 Problem:

Check if string has **valid matching parentheses**.

### ✅ Code with Comments:

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;

                if (s[i] == ')' && st.top() != '(') return false;
                if (s[i] == '}' && st.top() != '{') return false;
                if (s[i] == ']' && st.top() != '[') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
```

### 🧠 Dry Run:

Input: `"{[()]}"`
Stack trace: `{` → `{[` → `{[` `(` → match `)` → `{[` → match `]` → `{` → match `}` → ✅

---

## 📘 4. **Valid Parentheses without Stack**

### ✅ Code with Explanation:

```cpp
bool check(string s) {
    int left = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            left++;
        else {
            if (left == 0) return false;
            left--;
        }
    }
    return left == 0;
}
```

### 🧠 Explanation:

* `left` tracks unmatched `(`.
* If `)` comes without matching `(` → invalid.
* At end, if `left == 0` → all matched.

---

## 📘 5. **Print Bracket Number** (GFG Easy)

### ✅ Code:

```cpp
class Solution {
public:
    vector<int> bracketNumbers(string str) {
        int count = 0;
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                count++;
                st.push(count);
                ans.push_back(count);
            } else if (str[i] == ')') {
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};
```

### 🧠 Dry Run:

Input: `(()())`
Output: `[1,2,2,3,3,1]`

---

## 📘 6. **Minimum Add to Make Parentheses Valid** (Leetcode #921)

### ✅ Without Stack:

```cpp
int minAddToMakeValid(string s) {
    int left = 0, right = 0;
    for (char ch : s) {
        if (ch == '(')
            left++;
        else {
            if (left > 0) left--;
            else right++;
        }
    }
    return left + right;
}
```

### ✅ With Stack:

```cpp
int minAddToMakeValid(string s) {
    stack<char> st;
    int count = 0;

    for (char ch : s) {
        if (ch == '(')
            st.push(ch);
        else {
            if (st.empty()) count++;
            else st.pop();
        }
    }

    return count + st.size();
}
```

---

## 📘 7. **Get Minimum at Pop** (GFG Easy)

### ✅ Code:

```cpp
stack<int> _push(int arr[], int n) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (i == 0)
            st.push(arr[i]);
        else
            st.push(min(arr[i], st.top()));
    }

    return st;
}

void _getMinAtPop(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
```

### 🧠 Dry Run:

Input: \[1, 6, 2, 0]
Stack: \[1, 1, 1, 0]
Output on pop: `0 1 1 1`

---

## 📘 8. **Make Array Beautiful** (GFG Easy)

### ✅ Code:

```cpp
class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> s;

        for (int i = 0; i < arr.size(); i++) {
            if (s.empty()) {
                s.push(arr[i]);
            } else if ((arr[i] >= 0 && s.top() >= 0) || (arr[i] < 0 && s.top() < 0)) {
                s.push(arr[i]);
            } else {
                s.pop();  // opposite sign → remove both
            }
        }

        // Put stack to vector
        vector<int> ans(s.size());
        int i = s.size() - 1;
        while (!s.empty()) {
            ans[i--] = s.top();
            s.pop();
        }

        return ans;
    }
};
```

### 🧠 Dry Run:

Input: `[4, -3, -2, 1, 2, -1]`
Stack Flow:

* Push 4
* -3 → opposite → pop 4
* -2 → push
* 1 → opposite → pop -2
* 2 → push
* -1 → opposite → pop 2
  Final stack: \[]
  Answer: `[]`

---

## 📘 9. **Remove Consecutive Same Strings** (GFG)

### ✅ Code:

```cpp
class Solution {
public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string> s;

        for (string& str : arr) {
            if (s.empty()) s.push(str);
            else if (s.top() == str) s.pop();  // same → remove pair
            else s.push(str);
        }

        return s.size();
    }
};
```

### 🧠 Dry Run:

Input: `[ab, ab, cd, cd, ab]`
Stack: `ab` → pop
`cd` → pop
`ab` → push
Result size: `1`

---

## ✅ Summary Table

| Problem                 | Key Technique        | Extra Space | Time Complexity |
| ----------------------- | -------------------- | ----------- | --------------- |
| Reverse String          | Stack                | O(n)        | O(n)            |
| Insert at Bottom        | Stack (2x)           | O(n)        | O(n)            |
| Valid Parentheses       | Stack / Counter      | O(n)        | O(n)            |
| Bracket Numbers         | Stack + Counter      | O(n)        | O(n)            |
| Min Add to Make Valid   | Stack / Counter      | O(n)        | O(n)            |
| Get Min at Pop          | Stack (Min Tracking) | O(n)        | O(n)            |
| Make Array Beautiful    | Stack                | O(n)        | O(n)            |
| Remove Consecutive Same | Stack                | O(n)        | O(n)            |

---
