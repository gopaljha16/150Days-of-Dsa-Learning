# **Day 16: KMP Algorithm & Longest Prefix Suffix (LPS)**  

In this lesson, we will first **understand the KMP (Knuth-Morris-Pratt) Algorithm** and then **solve the "Longest Prefix Suffix" problem** using it.  

---

## **🔷 KMP (Knuth-Morris-Pratt) Algorithm**
The **KMP algorithm** is used for **pattern searching** in a given text. It improves the brute-force approach by **avoiding unnecessary re-checks** of already matched characters.  

### **🔹 Why use KMP?**
- Unlike the brute-force method (`O(N*M)`), KMP works in **O(N + M)** time.
- It avoids redundant comparisons by using the **LPS (Longest Prefix Suffix) array**.

---

## **🔹 Understanding LPS (Longest Prefix Suffix) Array**
The **LPS array** is the key to KMP. It stores the length of the **longest proper prefix** of the pattern that is also a **suffix**.  

### **Example of LPS Array Calculation**
For the pattern:  
**`A B A B A C`**  

We construct the **LPS array** step by step:

| Pattern | A | B | A | B | A | C |
|----------|----|----|----|----|----|----|
| LPS Value | 0  | 0  | 1  | 2  | 3  | 0 |

🔹 **How is LPS calculated?**
1. `A` has no prefix = `0`
2. `AB` has no matching prefix & suffix = `0`
3. `ABA` → Prefix: `A`, Suffix: `A` → LPS = `1`
4. `ABAB` → Prefix: `AB`, Suffix: `AB` → LPS = `2`
5. `ABABA` → Prefix: `ABA`, Suffix: `ABA` → LPS = `3`
6. `ABABAC` → No match → `0`

**LPS helps in KMP**: Instead of restarting the search, we use the LPS array to **skip redundant comparisons**.

---

## **🔷 Problem: Longest Prefix Suffix (GFG - Hard Level)**  
### **🔹 Problem Statement**
Find the **length of the longest proper prefix** of a given string **which is also a suffix**.  
- A **proper prefix** means **not equal** to the full string.  
- A **proper suffix** means **not equal** to the full string.

### **🔹 Example Inputs & Outputs**
```cpp
Input:  "abab"
Output: 2  // "ab" is the longest prefix which is also a suffix

Input:  "aaaa"
Output: 3  // "aaa" is the longest prefix which is also a suffix

Input:  "abc"
Output: 0  // No prefix and suffix are equal
```

---

## **🔷 Code Implementation (Using LPS Concept)**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int longestPrefixSuffix(string &s) {
    vector<int> lps(s.size(), 0); // Create LPS array initialized to 0
    int pre = 0, suf = 1; // Prefix & Suffix pointers

    // Construct the LPS array
    while (suf < s.size()) {
        // If characters match, update LPS value
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1; // LPS at suffix position is prefix length +1
            pre++; // Move prefix pointer
            suf++; // Move suffix pointer
        }
        // If characters do not match
        else {
            if (pre == 0) { // No previous match, so LPS[suf] = 0
                lps[suf] = 0;
                suf++; // Move suffix pointer
            } 
            else { // Backtrack prefix to the previous LPS value
                pre = lps[pre - 1];
            }
        }
    }

    // The last value in the LPS array gives the longest prefix-suffix length
    return lps[s.size() - 1];
}

// Example usage
int main() {
    string s = "abab";
    cout << "Longest Prefix-Suffix Length: " << longestPrefixSuffix(s) << endl;
    return 0;
}
```

---

## **🔷 Explanation of Code (Line-by-Line)**
1. **Initialize the LPS array** to store the length of the longest prefix that is also a suffix.
2. **Use two pointers (`pre` & `suf`)**:
   - `pre` (prefix pointer)
   - `suf` (suffix pointer, moves through the string)
3. **Matching case:**  
   - If `s[pre] == s[suf]`, update `LPS[suf] = pre + 1`
   - Move both `pre` & `suf` forward
4. **Non-matching case:**  
   - If `pre == 0`, set `LPS[suf] = 0` and move `suf` ahead
   - Otherwise, backtrack `pre` to `LPS[pre - 1]` (jump back to the previous prefix length)
5. **Return the last value of the LPS array** (which gives the required prefix-suffix length).

---

## **🔷 Time & Space Complexity**
✅ **Time Complexity:** `O(N)` (We traverse the string once)  
✅ **Space Complexity:** `O(N)` (For the LPS array)

---

## **🔷 Summary of Day 16**
| Topic | Concept |
|--------|---------|
| **KMP Algorithm** | Used for **pattern searching** in `O(N+M)` |
| **LPS Array** | Helps in efficient **string matching** |
| **Longest Prefix-Suffix** | Uses LPS to find **longest prefix matching suffix** |

---
