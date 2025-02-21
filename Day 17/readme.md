# **Day 17: Find the Index of the First Occurrence in a String**  

## **🔷 Problem Statement (LeetCode Medium - "strStr" function)**
Given two strings **haystack** and **needle**, return the **index of the first occurrence** of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.  

### **🔹 Example Inputs & Outputs**
```cpp
Input:  haystack = "hello", needle = "ll"
Output: 2  // "ll" starts at index 2

Input:  haystack = "aaaaa", needle = "bba"
Output: -1  // "bba" is not in "aaaaa"

Input:  haystack = "leetcode", needle = "leeto"
Output: -1  // "leeto" is not present
```

---

## **🔷 Approach: Using KMP Algorithm (Efficient)**
Instead of brute-force checking all substrings (`O(N*M)`), we use the **KMP (Knuth-Morris-Pratt) algorithm**, which works in **O(N+M) time** using the **LPS (Longest Prefix Suffix) array**.

---

## **🔷 Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to compute LPS (Longest Prefix Suffix) array
    void lpsFind(vector<int>& lps, string &s) {
        int pre = 0, suf = 1; // Prefix & Suffix pointers

        while (suf < s.size()) { // Loop till the suffix reaches the end
            if (s[pre] == s[suf]) { // If prefix and suffix match
                lps[suf] = pre + 1; // Store LPS value
                suf++, pre++;  // Move both pointers
            } 
            else {
                if (pre == 0) { // No match and prefix is at start
                    lps[suf] = 0; // Set LPS[suf] to 0
                    suf++; // Move suffix forward
                } 
                else { // Backtrack prefix pointer
                    pre = lps[pre - 1];
                }
            }
        }
    }

    // KMP Algorithm to find the first occurrence of needle in haystack
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: empty needle

        vector<int> lps(needle.size(), 0); // Initialize LPS array
        lpsFind(lps, needle); // Compute LPS array

        int first = 0, second = 0; // Pointers for haystack and needle

        // Loop through haystack
        while (first < haystack.size()) {
            if (needle[second] == haystack[first]) { // Match found
                second++;
                first++;
            } 
            else {
                if (second == 0) { // If needle hasn't matched yet, move first
                    first++;
                } 
                else { // Backtrack second pointer using LPS
                    second = lps[second - 1];
                }
            }

            // If we have matched all characters of the needle
            if (second == needle.size()) 
                return first - second; // Return start index of match
        }

        return -1; // If no match is found
    }
};

// Example usage
int main() {
    Solution sol;
    string haystack = "hello", needle = "ll";
    cout << "First occurrence index: " << sol.strStr(haystack, needle) << endl;
    return 0;
}
```

---

## **🔷 Explanation of Code**
### **Step 1: Compute the LPS Array**
- The **LPS array** helps to skip unnecessary character comparisons in the main search.
- It stores the **longest prefix which is also a suffix**.

### **Step 2: Search Using KMP**
- We maintain **two pointers**:
  - `first` → for `haystack`
  - `second` → for `needle`
- **If characters match**, move both pointers forward.
- **If characters don't match**, we use the LPS array to decide the next step:
  - If `second == 0`, move `first` forward.
  - Otherwise, set `second = lps[second - 1]` (backtrack in the needle).

### **Step 3: Return Result**
- If `second` reaches `needle.size()`, it means the pattern was found.  
  - We return the **starting index** (`first - second`).
- If the loop completes without finding `needle`, return `-1`.

---

## **🔷 Time & Space Complexity**
✅ **Time Complexity:** `O(N+M)`, where `N` = length of `haystack`, `M` = length of `needle`  
✅ **Space Complexity:** `O(M)`, for storing the LPS array

---

## **🔷 Summary of Day 17**
| Topic | Concept |
|--------|---------|
| **strStr function** | Find first occurrence of `needle` in `haystack` |
| **KMP Algorithm** | Used for **efficient pattern searching** |
| **LPS Array** | Helps to **avoid unnecessary comparisons** |

---

