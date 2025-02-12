
---

# **Day 11: String Interview Questions**  

This document contains solutions and explanations for commonly asked string-based interview questions.

---

## **1. Defanging an IP Address (Leetcode - Easy)**  
**Problem Statement:**  
Given a valid IP address, replace every `"."` with `"[.]"`.  

### **Code:**
```cpp
string defangIPaddr(string address) {
    int index = 0;
    string ans;
    while (index < address.size()) {
        if (address[index] == '.')
            ans = ans + "[.]"; // Replace '.' with "[.]"
        else
            ans = ans + address[index]; // Copy other characters as is
        index++;
    }
    return ans;
}
```
### **Explanation:**
1. Initialize `index = 0` and an empty string `ans`.
2. Iterate through the string:
   - If the character is `"."`, append `"[.]"` to `ans`.
   - Otherwise, append the character as is.
3. Return the modified string.

⏩ **Time Complexity:** O(N), where N is the length of the input string.

---

## **2. String Rotated by 2 Places (GFG - Easy)**  
**Problem Statement:**  
Check if a given string can be obtained by rotating another string by exactly **2 places** in either direction.  

### **Code:**
```cpp
void rotateClockwise(string &s) {
    char c = s[s.size() - 1]; // Store last character
    int index = s.size() - 2;
    while (index >= 0) {
        s[index + 1] = s[index]; // Shift characters right
        index--;
    }
    s[0] = c; // Place last character at the start
}

void rotateAntiClockwise(string &s) {
    char c = s[0]; // Store first character
    int index = 1;
    while (index < s.size()) {
        s[index - 1] = s[index]; // Shift characters left
        index++;
    }
    s[s.size() - 1] = c; // Place first character at the end
}

bool isRotated(string &s1, string &s2) {
    if (s1.size() != s2.size())
        return false;

    string clockwise = s1;
    rotateClockwise(clockwise);
    rotateClockwise(clockwise);

    if (clockwise == s2)
        return true;

    string antiClockwise = s1;
    rotateAntiClockwise(antiClockwise);
    rotateAntiClockwise(antiClockwise);

    return antiClockwise == s2;
}
```
### **Explanation:**
1. **Rotate Clockwise**: Move the last character to the front, shifting others right.
2. **Rotate Anti-clockwise**: Move the first character to the end, shifting others left.
3. **Check both rotations**:
   - Rotate `s1` **twice** in both directions and compare with `s2`.

⏩ **Time Complexity:** O(N)  
⏩ **Space Complexity:** O(1)  

---

## **3. Check if a Sentence is a Pangram (Leetcode 1832 - Easy)**  
**Problem Statement:**  
A **pangram** is a sentence containing every letter of the alphabet at least once. Given a string, check if it is a pangram.  

### **Code:**
```cpp
bool checkIfPangram(string sentence) {
    vector<bool> alphabet(26, false); // Track occurrence of each letter

    for (int i = 0; i < sentence.size(); i++) {
        alphabet[sentence[i] - 'a'] = true; // Mark letter as seen
    }

    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) // If any letter is missing, return false
            return false;
    }

    return true; // If all letters exist, return true
}
```
### **Explanation:**
1. Create a **boolean vector** to track the occurrence of **26 letters**.
2. Iterate through the input string, marking each character.
3. Finally, check if all 26 letters are marked **true**.

⏩ **Time Complexity:** O(N)  
⏩ **Space Complexity:** O(1)  

---

## **4. Sort a String (GFG - Basic)**  
**Problem Statement:**  
Given a string, sort the characters in **lexicographical order**.  

### **Code:**
```cpp
string sortString(string s) {
    vector<int> alphabet(26, 0); // Frequency array for 'a' to 'z'
    
    for (int i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'a']++; // Count occurrences of each character
    }
    
    string ans;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        while (alphabet[i]--) {
            ans += c; // Append character based on frequency
        }
    }
    
    return ans;
}
```
### **Explanation:**
1. **Count occurrences** of each character.
2. **Append characters** in sorted order.

⏩ **Time Complexity:** O(N)  
⏩ **Space Complexity:** O(1)  

---

### **📌 Summary Table**
| **Problem** | **Concept** | **Time Complexity** |
|------------|------------|--------------------|
| Defanging an IP Address | String manipulation | O(N) |
| String Rotated by 2 Places | String rotation | O(N) |
| Pangram Check | Frequency array | O(N) |
| Sorting a String | Counting sort | O(N) |

---

### **🔗 Additional Resources**
- [Leetcode: Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)
- [Leetcode: Check if Sentence is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)
- [GFG: String Rotation](https://www.geeksforgeeks.org/check-if-a-string-can-be-obtained-by-rotating-another-string-2-places/)
- [GFG: Sort a String](https://www.geeksforgeeks.org/sort-a-string/)

---

### **💡 Tips for Interviews**
1. **String operations are costly** in some cases—optimize using in-place modifications if possible.
2. **Use frequency arrays** to efficiently track occurrences of characters in `O(1)` space.
3. **Know basic operations** like `reverse()`, `substr()`, `find()`, and `sort()`.
4. **Edge Cases:** Always check for empty strings, special characters, and uppercase letters.

---