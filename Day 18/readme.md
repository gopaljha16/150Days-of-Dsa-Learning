# Day 18: String Hard Questions

## 1. Min Chars to Add for Palindrome (GFG Hard Question)

### Problem Statement:
Given a string, determine the minimum number of characters that need to be added at the beginning of the string to make it a palindrome.

### Approach:
This problem can be solved using the **KMP (Knuth-Morris-Pratt) algorithm** to find the **Longest Prefix Suffix (LPS)**. The key idea is to:
- Create a new string: `original + '$' + reversed(original)`
- Compute the **LPS array** of this new string.
- The answer is `length_of_original - LPS[last_index]`.

### Code with Explanation:
```cpp
int minChar(string& s) {
    // Step 1: Create the reversed string
    string rev = s;
    reverse(rev.begin(), rev.end()); // Reverse the string
    int size = s.size(); // Store original size
     
    // Step 2: Create a new string with a separator ($) to distinguish
    s += '$';  // '$' is a separator to avoid overlap issues
    s += rev;  // Append the reversed string
    
    // Step 3: Compute the LPS array
    int n = s.size(); // New string length
    vector<int> lps(n, 0); // Initialize LPS array with 0
    int pre = 0, suf = 1; // Prefix and suffix pointers
    
    while (suf < n) {
        // If characters match, extend prefix
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1; // Store prefix length
            pre++, suf++; // Move both pointers
        } else {
            // If no match, move prefix back based on previous LPS
            if (pre == 0) {
                lps[suf] = 0; // No match, set to 0
                suf++; // Move suffix forward
            } else {
                pre = lps[pre - 1]; // Move prefix back
            }
        }
    }
    
    // Step 4: Answer is length_of_original - last value in LPS array
    return size - lps[n - 1];
}
```

### Example Walkthrough:
#### Input:
```cpp
string s = "aacecaaa";
```
#### Execution:
1. Reverse the string: `rev = "aaacecaa"`
2. Create new string: `s = "aacecaaa$aaacecaa"`
3. Compute LPS:
   - LPS array: `[0,1,0,0,1,2,3,4,0,1,2,3,4,5,6,7]`
   - LPS[last_index] = `7`
4. Answer: `size - lps[n-1] = 8 - 7 = 1`

#### Output:
```cpp
1 // One character "a" needs to be added at the beginning
```

---

## 2. Repeated String Match (Leetcode Medium #686)

### Problem Statement:
Given two strings **a** and **b**, find the minimum number of times **a** needs to be repeated so that **b** is a substring of the repeated string.

### Approach:
1. If `a == b`, return `1`.
2. Keep appending `a` to itself until its length becomes greater than or equal to `b`.
3. Use **KMP Algorithm** to check if `b` exists as a substring.
4. If not found, append `a` once more and check again.
5. If `b` is still not found, return `-1`.

### Code with Explanation:
```cpp
// Function to compute LPS array for KMP algorithm
void lpsFind(vector<int>& lps, string& s) {
    int pre = 0, suf = 1; // Prefix and suffix pointers
    while (suf < s.size()) {
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1; // Store prefix length
            pre++, suf++; // Move both pointers
        } else {
            if (pre == 0) {
                lps[suf] = 0; // No match, set to 0
                suf++; // Move suffix forward
            } else {
                pre = lps[pre - 1]; // Move prefix back
            }
        }
    }
}

// Function to check if 'b' is a substring of 'haystack' using KMP search
int kmp_match(string haystack, string needle) {
    vector<int> lps(needle.size(), 0); // Initialize LPS array
    lpsFind(lps, needle); // Compute LPS for needle
    
    int first = 0, second = 0; // Pointers for haystack and needle
    while (first < haystack.size()) {
        if (needle[second] == haystack[first]) {
            second++, first++; // Move both pointers forward
        } else {
            if (second == 0) first++; // Move haystack pointer if no match
            else second = lps[second - 1]; // Move needle pointer back
        }
        if (second == needle.size()) return 1; // Found substring
    }
    return 0; // Not found
}

int repeatedStringMatch(string a, string b) {
    if (a == b) return 1; // Direct match case
    
    int repeat = 1;
    string temp = a; // Store repeated string
    
    // Step 1: Keep repeating 'a' until its length is >= 'b'
    while (temp.size() < b.size()) {
        temp += a;
        repeat++;
    }
    
    // Step 2: Check if 'b' is a substring of 'temp' using KMP
    if (kmp_match(temp, b)) return repeat;
    
    // Step 3: Try one more repetition
    temp += a;
    if (kmp_match(temp, b)) return repeat + 1;
    
    return -1; // Not found
}
```

### Example Walkthrough:
#### Input:
```cpp
string a = "abcd";
string b = "cdabcdab";
```
#### Execution:
1. Repeat `a` until its length ≥ `b`: `temp = "abcdabcd"` (`repeat = 2`)
2. `b` is still not a substring.
3. Append `a` once more: `temp = "abcdabcdabcd"` (`repeat = 3`)
4. `b` now exists as a substring → return `3`.

#### Output:
```cpp
3 // "abcd" repeated 3 times contains "cdabcdab"
```

---

## Summary:
- **Min Chars to Add for Palindrome** uses **KMP LPS array** to determine the minimum prefix addition.
- **Repeated String Match** utilizes **string concatenation** and **KMP substring search** to determine how many repetitions are needed.
- **Both problems leverage KMP algorithm** to optimize search efficiency.

---



