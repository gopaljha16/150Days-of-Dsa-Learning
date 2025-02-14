

---

# **Day 14: Roman to Integer  , Factorial of Large Numberb , Integer to Roman**

### **Problem Statement**
Given a Roman numeral as a string `s`, convert it to an integer.

📌 **Rules of Roman Numerals:**  
- `I = 1`, `V = 5`, `X = 10`, `L = 50`, `C = 100`, `D = 500`, `M = 1000`
- If **a smaller numeral appears before a larger one**, subtract it.
  - Example: `"IV" = 5 - 1 = 4`, `"IX" = 10 - 1 = 9`
- Otherwise, just **add** the values.

---

### **Example Input & Output**
```cpp
string s = "MCMXCIV";
cout << romanToInt(s); 
// Output: 1994
```

**Explanation:**
- `M (1000)`
- `CM (900)` → (`C` before `M`, subtract `100`)
- `XC (90)` → (`X` before `C`, subtract `10`)
- `IV (4)` → (`I` before `V`, subtract `1`)
- **Total: `1000 + 900 + 90 + 4 = 1994`**

---

### **Code Implementation**
```cpp
// Function to return integer value of a Roman character
int num(char c) {
    if (c == 'I') return 1;
    else if (c == 'V') return 5;
    else if (c == 'X') return 10;
    else if (c == 'L') return 50;
    else if (c == 'C') return 100;
    else if (c == 'D') return 500;
    else return 1000;  // 'M'
}

// Function to convert Roman numeral to Integer
int romanToInt(string s) {
    int sum = 0, index = 0;

    // Traverse the string till second last character
    while (index < s.size() - 1) {
        // If current numeral is smaller than the next one → subtract it
        if (num(s[index]) < num(s[index + 1]))
            sum -= num(s[index]);
        else
            sum += num(s[index]);

        index++;
    }

    // Add the last numeral (it was not compared in loop)
    sum += num(s[index]);

    return sum;
}
```

---

### **Explanation (Step-by-Step)**
1. **Define a helper function `num(char c)`**  
   - Converts a Roman character to its integer value.

2. **Iterate through the string**
   - If `s[index] < s[index + 1]`, subtract `s[index]` from the sum.
   - Otherwise, add `s[index]` to the sum.

3. **Add the last character manually**  
   - The last numeral is not compared inside the loop, so we **add it separately**.

---

### **Example Walkthrough**
#### **Example 1**
```cpp
string s = "MCMXCIV";
```
| Roman | Value | Action |
|--------|--------|-----------|
| M  | 1000  | Add (sum = **1000**) |
| CM | 900   | Subtract (sum = **100**) |
| XC | 90    | Subtract (sum = **190**) |
| IV | 4     | Subtract (sum = **194**) |
| (Last) V | 5  | Add (sum = **1994**) |

✅ **Final Output:** `1994`

---

### **Complexity Analysis**
| **Time Complexity** | **Space Complexity** |
|--------------------|--------------------|
| `O(N)` (one pass through the string) | `O(1)` (constant extra space) |

---

### **Edge Cases Considered**
✅ **Basic Cases:** `"III" → 3`, `"IX" → 9`, `"LVIII" → 58`  
✅ **Largest Number:** `"MMMCMXCIX"` (3999)  
✅ **Minimal Input:** `"I"` (1)  

---

### **🔗 Additional Resources**
- [Leetcode: Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

---

🚀 This format ensures **clarity** and is **easy to revise**. Let me know if you need any modifications! 😃