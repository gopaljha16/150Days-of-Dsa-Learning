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
    reverse(rev.begin(), rev.end());
    int size = s.size();
     
    // Step 2: Create a new string with a separator ($) to distinguish
    s += '$';  // '$' is a separator to avoid overlap issues
    s += rev;  // Append the reversed string
    
    // Step 3: Compute the LPS array
    int n = s.size();
    vector<int> lps(n, 0);
    int pre = 0, suf = 1;
    
    while (suf < n) {
        // If characters match, extend prefix
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            pre++, suf++;
        } else {
            // If no match, move prefix back based on previous LPS
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
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
    int pre = 0, suf = 1;
    while (suf < s.size()) {
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            pre++, suf++;
        } else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }
}

// Function to check if 'b' is a substring of 'haystack' using KMP search
int kmp_match(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    lpsFind(lps, needle);
    
    int first = 0, second = 0;
    while (first < haystack.size()) {
        if (needle[second] == haystack[first]) {
            second++, first++;
        } else {
            if (second == 0) first++;
            else second = lps[second - 1];
        }
        if (second == needle.size()) return 1;
    }
    return 0;
}

int repeatedStringMatch(string a, string b) {
    if (a == b) return 1;
    
    int repeat = 1;
    string temp = a;
    
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
    
    return -1;
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

