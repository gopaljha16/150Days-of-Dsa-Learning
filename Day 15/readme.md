
---

# **Day 15: Longest Substring Without Repeating Characters & Smallest Distinct Window**

## **1️⃣ Longest Substring Without Repeating Characters** (LeetCode **Medium** – #3)

### **Problem Statement**
Given a string `s`, find the **length of the longest substring** that contains **only unique characters** (no repeating characters).  

🔹 **Example Inputs & Outputs**
```cpp
Input:  "abcabcbb"
Output: 3   // "abc" is the longest unique substring

Input:  "bbbbb"
Output: 1   // "b" is the longest unique substring

Input:  "pwwkew"
Output: 3   // "wke" is the longest unique substring
```

---

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> count(256, 0); // Array to track character presence
        int first = 0, second = 0, len = 0;

        // Traverse the string using two pointers
        while (second < s.size()) {
            // If a duplicate character is found, move the left pointer
            while (count[s[second]]) {
                count[s[first]] = 0; // Remove the character from tracking
                first++; // Move left pointer
            }

            // Mark the current character as visited
            count[s[second]] = 1;

            // Update max length of unique substring
            len = max(len, second - first + 1);

            // Move the right pointer
            second++;
        }
        return len;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "pwwkew";
    cout << "Longest substring length: " << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
```

✅ **Time Complexity:** `O(N)` (Each character is processed at most twice)  
✅ **Space Complexity:** `O(1)` (Constant space for tracking 256 ASCII characters)

---

## **2️⃣ Smallest Distinct Window** (GFG **Medium**)

### **Problem Statement**
Find the **smallest substring** of `s` that contains **all distinct characters** of `s`.

🔹 **Example Inputs & Outputs**
```cpp
Input:  "aabcbcdbca"
Output: 4   // "dbca" is the smallest window containing all unique chars

Input:  "aaab"
Output: 2   // "ab" contains all unique characters
```

---

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findSubString(string &s) {
    vector<int> count(256, 0); // To count occurrences of characters
    int first = 0, second = 0, len = s.size(), diff = 0;

    // Find number of unique characters in the string
    while (first < s.size()) {
        if (count[s[first]] == 0) 
            diff++;  // Increment count of unique characters
        count[s[first]]++;
        first++;
    }

    // Reset count array
    fill(count.begin(), count.end(), 0);
    first = 0;

    // Sliding window approach
    while (second < s.size()) {
        // Expand window until all distinct characters are included
        while (diff && second < s.size()) {
            if (count[s[second]] == 0) 
                diff--;
            count[s[second]]++;
            second++;
        }

        // Update minimum window length
        len = min(len, second - first);

        // Shrink window from the left
        while (diff != 1) {
            len = min(len, second - first);
            count[s[first]]--;

            if (count[s[first]] == 0) 
                diff++; // A distinct character is removed, so increase diff
            
            first++; // Move the left pointer
        }
    }
    
    return len;
}

// Example usage
int main() {
    string s = "aabcbcdbca";
    cout << "Smallest distinct window length: " << findSubString(s) << endl;
    return 0;
}
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(1)`

---

### **📌 Summary of Day 15**
| Problem | Difficulty | Concept |
|----------|------------|----------|
| **Longest Substring Without Repeating Characters** | Medium | Sliding window, Hashing (ASCII tracking) |
| **Smallest Distinct Window** | Medium | Sliding window, Character frequency |

---

