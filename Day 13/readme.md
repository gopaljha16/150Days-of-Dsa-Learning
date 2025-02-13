Here are your **Day 13: String Interview Problems** notes in a **GitHub README** style, with detailed **line-by-line explanations**, **comments**, and **example inputs/outputs**.

---

# **Day 13: String Interview Problems (Leetcode)**  

This document contains solutions and explanations for two **string manipulation problems** from **LeetCode**.

---

## **1️⃣ Sort Vowels in a String** (Leetcode **Medium** - #2785)

### **Problem Statement**
Given a string `s`, sort only the vowels (`a, e, i, o, u, A, E, I, O, U`) in **ascending order** and return the updated string.

### **Example Input & Output**
```cpp
string s = "lEetcOde";
cout << sortVowels(s); 
// Output: "lEOtcede"
```
**Explanation:**  
- Vowels in `"lEetcOde"`: **E, e, O, o**  
- Sorted order: **E, O, e, o**  
- Replace vowels in the same positions → **"lEOtcede"**

---

### **Code Implementation**
```cpp
string sortVowels(string s) {
    vector<int> lower(26, 0); // Frequency count for lowercase vowels
    vector<int> upper(26, 0); // Frequency count for uppercase vowels

    // Step 1: Count vowels and mark them as '#'
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || 
            s[i] == 'o' || s[i] == 'u') {
            lower[s[i] - 'a']++; // Count lowercase vowels
            s[i] = '#'; // Mark vowel positions
        } 
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || 
                 s[i] == 'O' || s[i] == 'U') {
            upper[s[i] - 'A']++; // Count uppercase vowels
            s[i] = '#'; // Mark vowel positions
        }
    }

    // Step 2: Sort the vowels
    string sortedVowels;
    
    // Add uppercase vowels first (A-Z)
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;  // Convert index to character
        while (upper[i]--) {
            sortedVowels += c; // Append vowel to sorted list
        }
    }
    
    // Add lowercase vowels (a-z)
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        while (lower[i]--) {
            sortedVowels += c;
        }
    }

    // Step 3: Replace '#' with sorted vowels
    int vowelIndex = 0; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            s[i] = sortedVowels[vowelIndex++]; // Replace '#' with next vowel
        }
    }

    return s;
}
```

---

### **Explanation (Step-by-Step)**
1. **Count vowels & mark them with `#`**  
   - Store **frequency** of vowels in `lower[]` (for `a-z`) and `upper[]` (for `A-Z`).
   - Replace vowels in `s` with `#` to keep track of positions.

2. **Sort the vowels**  
   - Append **uppercase vowels first**, then **lowercase vowels** in sorted order.

3. **Replace `#` with sorted vowels**  
   - Traverse `s` again and replace `#` with vowels in sorted order.

---

### **Complexity Analysis**
- **Time Complexity:** `O(N + 26 + 26) ≈ O(N)`  
- **Space Complexity:** `O(N)`

---

## **2️⃣ Add Strings** (Leetcode **Easy** - #415)

### **Problem Statement**
Given two **non-negative** integers `num1` and `num2` represented as **strings**, return the **sum** as a string **without converting to an integer**.

### **Example Input & Output**
```cpp
string num1 = "456", num2 = "77";
cout << addStrings(num1, num2); 
// Output: "533"
```

---

### **Code Implementation**
```cpp
string add(string num1, string num2) {
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int carry = 0, sum;
    string ans;

    // Step 1: Add digits from the end
    while (index2 >= 0) {
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
        carry = sum / 10; // Extract carry
        char c = '0' + sum % 10; // Extract last digit
        ans += c;
        index1--; index2--; // Move to the next digits
    }

    // Step 2: Add remaining digits from the longer number
    while (index1 >= 0) {
        sum = (num1[index1] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--;
    }

    // Step 3: If there’s a carry left, add '1' at the end
    if (carry) {
        ans += '1';
    }

    // Step 4: Reverse the result since we added digits from the end
    reverse(ans.begin(), ans.end());
    return ans;
}

string addStrings(string num1, string num2) {
    // Ensure `num1` is always the larger number
    if (num1.size() < num2.size()) 
        return add(num2, num1);
    else
        return add(num1, num2);
}
```

---

### **Explanation (Step-by-Step)**
1. **Start adding from the last digits**  
   - Convert character digits (`'0'` to `'9'`) to integers using `- '0'`.
   - Keep track of **carry**.

2. **Continue with remaining digits of the longer number**  
   - If one number is shorter, continue adding the leftover digits from the longer number.

3. **Handle the final carry**  
   - If `carry > 0` after processing all digits, append `'1'` to the result.

4. **Reverse the result**  
   - Since we built the string from **right to left**, reverse it before returning.

---

### **Example Walkthrough**
#### **Example 1**
```cpp
num1 = "456", num2 = "77"
```
**Step-by-Step Addition**
```
  456
+  77
------
  533
```
- **6 + 7 = 13** → carry `1`, add `3`
- **5 + 7 + 1 = 13** → carry `1`, add `3`
- **4 + 1 = 5** → add `5`

⏩ **Final Output:** `"533"`

---

### **Complexity Analysis**
- **Time Complexity:** `O(max(N, M))`
- **Space Complexity:** `O(max(N, M))`

---

### **📌 Summary Table**
| **Problem** | **Concept** | **Time Complexity** |
|------------|------------|--------------------|
| Sort Vowels in a String | String manipulation, sorting | O(N) |
| Add Strings | Character arithmetic, reverse traversal | O(N) |

---

### **🔗 Additional Resources**
- [Leetcode: Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/)
- [Leetcode: Add Strings](https://leetcode.com/problems/add-strings/)

---

### **💡 Key Takeaways**
1. **Character frequency counting** is useful for **sorting vowels**.
2. **Simulating arithmetic** on character strings avoids integer conversion.
3. **Edge Cases:**  
   - Empty strings (`""`)  
   - Carry-over handling in addition (`999 + 1 = 1000`)  

---
