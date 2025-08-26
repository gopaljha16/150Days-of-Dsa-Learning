# Minimum Window Substring - LeetCode Hard Problem

## Overview

This code solves the "Minimum Window Substring" problem, which finds the smallest substring in string `s` that contains all characters from string `t`. The algorithm uses the **sliding window technique** with two approaches: using an `unordered_map` and using a `vector` for character frequency counting.

## Problem Statement

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such window, return an empty string.

## Approach 1: Using `unordered_map`

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int total = t.size();
        
        // Create frequency map for characters in t
        unordered_map<char, int> m;
        for(int i = 0; i < t.size(); i++)
            m[t[i]]++;
        
        int start = 0, end = 0, ans = INT_MAX, index = -1;
        
        while(end < s.size()) {
            // Expand window by including s[end]
            m[s[end]]--;
            
            // If character is needed (was positive), decrease total
            if(m[s[end]] >= 0) {
                total--;
            }
            
            // Try to contract window when all characters are found
            while(!total && start <= end) {
                // Update minimum window if current is smaller
                if(ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }
                
                // Contract window from left
                m[s[start]]++;
                if(m[s[start]] > 0) {
                    total++;
                }
                start++;
            }
            end++;
        }
        
        // Return result
        if(index == -1) return "";
        
        string str = "";
        for(int i = index; i < index + ans; i++) {
            str += s[i];
        }
        return str;
    }
};
```

## Approach 2: Using `vector` (ASCII array)

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int total = t.size();
        
        // Use vector of size 256 for all ASCII characters
        vector<int> m(256, 0);
        for(int i = 0; i < t.size(); i++)
            m[t[i]]++;
        
        int start = 0, end = 0, ans = INT_MAX, index = -1;
        
        while(end < s.size()) {
            m[s[end]]--;
            
            if(m[s[end]] >= 0) {
                total--;
            }
            
            while(!total && start <= end) {
                if(ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }
                
                m[s[start]]++;
                if(m[s[start]] > 0) {
                    total++;
                }
                start++;
            }
            end++;
        }
        
        if(index == -1) return "";
        
        string str = "";
        for(int i = index; i < index + ans; i++) {
            str += s[i];
        }
        return str;
    }
};
```

## Step-by-Step Algorithm Breakdown

### 1. Initialization Phase
```cpp
int total = t.size();                    // Characters needed to form valid window
unordered_map<char, int> m;              // Frequency map
for(int i = 0; i < t.size(); i++)
    m[t[i]]++;                           // Count frequencies of chars in t
```

### 2. Sliding Window Expansion
```cpp
while(end < s.size()) {
    m[s[end]]--;                         // Decrease frequency of current char
    
    if(m[s[end]] >= 0) {                 // If char was needed
        total--;                         // Decrease remaining count
    }
```

### 3. Window Contraction
```cpp
while(!total && start <= end) {          // Valid window found
    if(ans > end - start + 1) {          // Update minimum window
        ans = end - start + 1;
        index = start;
    }
    
    m[s[start]]++;                       // Remove char from left
    if(m[s[start]] > 0) {               // If removing needed char
        total++;                         // Increase remaining count
    }
    start++;                            // Move left pointer
}
```

## Example Walkthrough

### Input: `s = "ADOBECODEBANC"`, `t = "ABC"`

**Initial State:**
- `total = 3` (need A, B, C)
- `m = {A: 1, B: 1, C: 1}`
- `start = 0, end = 0, ans = INT_MAX, index = -1`

**Step-by-step execution:**

| Step | end | s[end] | m after-- | m[s[end]] | total | Window | Action |
|------|-----|--------|-----------|-----------|-------|---------|---------|
| 1 | 0 | A | {A:0, B:1, C:1} | 0 | 2 | "A" | Continue expanding |
| 2 | 1 | D | {A:0, B:1, C:1, D:-1} | -1 | 2 | "AD" | Continue expanding |
| 3 | 2 | O | {A:0, B:1, C:1, D:-1, O:-1} | -1 | 2 | "ADO" | Continue expanding |
| 4 | 3 | B | {A:0, B:0, C:1, D:-1, O:-1} | 0 | 1 | "ADOB" | Continue expanding |
| 5 | 4 | E | {A:0, B:0, C:1, D:-1, O:-1, E:-1} | -1 | 1 | "ADOBE" | Continue expanding |
| 6 | 5 | C | {A:0, B:0, C:0, D:-1, O:-1, E:-1} | 0 | 0 | "ADOBEC" | Valid window! Contract |

**Contraction phase (total = 0):**

| start | s[start] | Window | Length | Update ans? |
|-------|----------|---------|---------|-------------|
| 0 | A | "ADOBEC" | 6 | Yes, ans=6, index=0 |
| 1 | D | "DOBEC" | 5 | Yes, ans=5, index=1 |
| 2 | O | "OBEC" | 4 | Yes, ans=4, index=2 |
| 3 | B | "BEC" | 3 | total becomes 1, stop |

**Continue expanding from end=6...**

The algorithm continues until it finds the minimum window "BANC" with length 4.

## Visual Representation

```
String s: A D O B E C O D E B A N C
          ↑                       ↑
        start                   end

Phase 1: Expand end until valid window
A D O B E C
↑         ↑
start    end    (valid window found)

Phase 2: Contract start while maintaining validity
  D O B E C
  ↑       ↑
start    end

Phase 3: Continue until end reaches string end
Final result: B A N C (minimum window)
```

## Complexity Analysis

### Time Complexity: O(|s| + |t|)
- Each character in `s` is visited at most twice (once by `end` pointer, once by `start` pointer)
- Building frequency map takes O(|t|) time

### Space Complexity:
- **Approach 1 (unordered_map)**: O(|t|) - stores unique characters from `t`
- **Approach 2 (vector)**: O(1) - fixed size array of 256 elements

## Key Insights

1. **Frequency Tracking**: The algorithm tracks how many of each required character we still need
2. **Two-Phase Approach**: 
   - **Expansion**: Grow window until it contains all required characters
   - **Contraction**: Shrink window while maintaining validity to find minimum
3. **Negative Counts**: Characters not in `t` will have negative counts, which helps distinguish needed vs extra characters

## Edge Cases Handled

- Empty result when no valid window exists (`index == -1`)
- Duplicate characters in `t` are properly counted
- Extra occurrences of characters don't affect the validity

## Comparison: unordered_map vs vector

| Aspect | unordered_map | vector |
|--------|---------------|---------|
| Space | O(unique chars in t) | O(256) constant |
| Access Time | Average O(1) | O(1) guaranteed |
| Memory Usage | Lower for small character sets | Higher but predictable |
| Performance | Good for Unicode | Better for ASCII only |

## Summary

This sliding window solution efficiently finds the minimum window substring by:
1. Using a frequency map to track required characters
2. Expanding the window until all characters are found
3. Contracting the window to find the minimum valid size
4. Repeating until the entire string is processed

The algorithm achieves optimal O(n) time complexity and handles all edge cases including duplicate characters and impossible scenarios.