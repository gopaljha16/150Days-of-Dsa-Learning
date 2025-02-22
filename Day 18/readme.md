# **Day 18: Hard String Problems**  

## **1️⃣ Min Chars to Add for Palindrome (GFG - Hard)**  

### **🔷 Problem Statement**
Given a string `s`, find the **minimum number of characters that need to be added at the front** of the string to make it a **palindrome**.

### **🔹 Example Inputs & Outputs**
```cpp
Input: s = "abc"
Output: 2  
// Adding "ba" at the front makes "bacab" which is a palindrome.

Input: s = "aacecaaa"
Output: 1  
// Adding "a" at the front makes "aaacecaaa" which is a palindrome.
```

---

## **🔷 Approach: KMP Algorithm (Efficient)**
Instead of brute-force checking (`O(N^2)`), we use **KMP’s LPS (Longest Prefix Suffix) array** to determine the minimum number of characters required.

---

## **🔷 Code Implementation**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minChar(string& s) {
    string rev = s;  
    reverse(rev.begin(), rev.end());  // Reverse the string
    
    int size = s.size();

    s += '$';  // Separator for differentiation
    s += rev;  // Append the reversed string
    
    int n = s.size();
    vector<int> lps(n, 0);  // LPS array
    int pre = 0, suf = 1;
    
    while (suf < n) {
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            pre++, suf++;
        } 
        else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } 
            else {
                pre = lps[pre - 1];
            }
        }
    }

    return size - lps[n - 1];  // Minimum chars to add
}

// Driver Code
int main() {
    string s = "abc";
    cout << "Minimum characters to add: " << minChar(s) << endl;
    return 0;
}
```

---

## **🔷 Explanation of Code**
1. **Reverse the string** and concatenate with original string using a `$` separator.  
   - `s = "abc"` → `"abc$cba"`
2. **Compute LPS array** for this new string to find the longest prefix which is also a suffix.
3. **Formula**: `size - lps[n-1]` gives the minimum characters to add at the front.

### **🔹 Dry Run**
#### **Example:** `"abc"`
```
Original: "abc"
Reversed: "cba"
New String: "abc$cba"
LPS Array: [0, 0, 0, 0, 1, 2, 3]
Min chars to add: size - lps[6] = 3 - 1 = 2
```
✅ Output: `2`

---

## **2️⃣ Repeated String Match (LeetCode - Medium)**
### **🔷 Problem Statement**
Given two strings **a** and **b**, return the **minimum number of times** `a` needs to be **repeated** such that `b` is a **substring** of the repeated string. If not possible, return `-1`.

### **🔹 Example Inputs & Outputs**
```cpp
Input: a = "abcd", b = "cdabcdab"
Output: 3  
// "abcd" is repeated 3 times → "abcdabcdabcd" contains "cdabcdab".

Input: a = "a", b = "aa"
Output: 2  
// "a" needs to be repeated 2 times: "aa"
```

---

## **🔷 Approach: KMP Algorithm (Efficient)**
Instead of brute-force checking (`O(N*M)`), we use **KMP’s LPS array** to efficiently find `b` in the repeated `a`.

---

## **🔷 Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Compute LPS Array for KMP Algorithm
void lpsFind(vector<int>& lps, string &s) {
    int pre = 0, suf = 1;
    while (suf < s.size()) {
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            pre++, suf++;
        } 
        else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } 
            else {
                pre = lps[pre - 1];
            }
        }
    }
}

// KMP Search Algorithm
bool kmp_match(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    lpsFind(lps, needle);

    int first = 0, second = 0;
    while (first < haystack.size()) {
        if (needle[second] == haystack[first]) {
            second++;
            first++;
        } 
        else {
            if (second == 0) {
                first++;
            } 
            else {
                second = lps[second - 1];
            }
        }
        
        if (second == needle.size()) 
            return true;
    }
    return false;
}

// Main Function to Find Minimum Repeats
int repeatedStringMatch(string a, string b) {
    if (a == b) return 1; // Direct match

    int repeat = 1;
    string temp = a; 

    while (temp.size() < b.size()) {
        temp += a;
        repeat++;
    }

    if (kmp_match(temp, b)) return repeat;
    if (kmp_match(temp + a, b)) return repeat + 1;

    return -1;
}

// Driver Code
int main() {
    string a = "abcd", b = "cdabcdab";
    cout << "Minimum repetitions: " << repeatedStringMatch(a, b) << endl;
    return 0;
}
```

---

## **🔷 Explanation of Code**
1. **Compute LPS array** using `lpsFind()`.
2. **Search for `b` inside repeated `a`** using `kmp_match()`.
3. **Keep repeating `a`** until it contains `b`.
   - If `b` is found after `repeat` times → return `repeat`.
   - If `b` is found after one more repeat (`repeat+1`) → return `repeat+1`.
   - If not found → return `-1`.

---

### **🔹 Dry Run**
#### **Example:** `a = "abcd"`, `b = "cdabcdab"`
```
1. temp = "abcd" (not a substring of "cdabcdab")
2. temp = "abcdabcd" (not a substring of "cdabcdab")
3. temp = "abcdabcdabcd" (✅ contains "cdabcdab")
✅ Output: 3
```

---

## **🔷 Time & Space Complexity**
✅ **Time Complexity:** `O(N + M)`, where `N` = length of `a`, `M` = length of `b`  
✅ **Space Complexity:** `O(M)`, for storing the LPS array

---

## **🔷 Summary of Day 18**
| **Topic** | **Concept** |
|--------|---------|
| **Min Chars to Add for Palindrome** | Use **KMP LPS array** to find the longest palindromic prefix |
| **Repeated String Match** | Use **KMP LPS array** to find substring efficiently |

---

This **Day 18 note** provides a **clear explanation and code for two hard string problems**, making it **easy for revision**. 🚀 Let me know if you need any **debugging or further explanations**! 😊