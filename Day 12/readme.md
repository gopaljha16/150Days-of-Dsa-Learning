
---

# **Day 12: String 2 Problems Questions**  

This document contains solutions and explanations for commonly asked string-based interview questions.

---

## **1. Longest Palindrome (Leetcode - Easy)**  
**Problem Statement:**  
Given a string `s` consisting of lowercase and uppercase English letters, return the **length of the longest palindrome** that can be built using the letters in `s`.

### **Code:**
```cpp
int longestPalindrome(string s) {
    vector<int> lower(26, 0); // Array to count lowercase letters
    vector<int> upper(26, 0); // Array to count uppercase letters

    // Count occurrences of each letter
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a') 
            lower[s[i] - 'a']++;  // Store frequency for lowercase letters
        else 
            upper[s[i] - 'A']++;  // Store frequency for uppercase letters
    }

    int count = 0; // Length of the longest palindrome
    bool odd = false; // To check if any character has an odd frequency

    // Process both lowercase and uppercase letters
    for (int i = 0; i < 26; i++) {
        // If frequency is even, add all occurrences
        if (lower[i] % 2 == 0) 
            count += lower[i];
        else { 
            count += lower[i] - 1; // Use only even occurrences
            odd = true; // Mark that we have at least one odd character
        }

        if (upper[i] % 2 == 0) 
            count += upper[i];
        else { 
            count += upper[i] - 1; 
            odd = true; 
        }
    }

    count += odd; // If any odd character exists, one can be placed in the middle
    return count;
}
```

### **Explanation:**
1. **Count frequency of characters:**  
   - Use two arrays `lower[26]` and `upper[26]` to store the frequency of lowercase and uppercase letters.
2. **Iterate over frequency arrays:**  
   - If a character appears an **even** number of times, use all occurrences.
   - If a character appears an **odd** number of times, use one less (to keep it even), and mark `odd = true`.
3. **Add one extra character if needed:**  
   - If any odd frequency exists, we can place one odd character in the middle of the palindrome.

### **Example Input & Output:**
```cpp
string s = "abccccdd";
cout << longestPalindrome(s); // Output: 7
```
**Explanation:**  
- We can use `"dccaccd"` as the longest palindrome (7 characters long).

⏩ **Time Complexity:** O(N)  
⏩ **Space Complexity:** O(1)  

---

## **2. Sorting the Sentence (Leetcode - Easy)**  
**Problem Statement:**  
Given a sentence `s` containing words with numbers (indicating their position in the sentence), return the sentence in **correct order** after sorting.

### **Code:**
```cpp
class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10); // Array to store words at correct positions
        string temp; // Temporary string to store each word
        int count = 0, index = 0;
        int n = s.size();

        while (index < n) {
            if (s[index] == ' ') {
                int pos = temp[temp.size() - 1] - '0'; // Extract position digit
                temp.pop_back(); // Remove position number from the word
                ans[pos] = temp; // Store the word at the correct position
                temp.clear(); // Clear temp for the next word
                count++; // Count words
            } else {
                temp += s[index]; // Build word character by character
            }
            index++;
        }

        // Handle the last word (not followed by a space)
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        count++;

        // Construct the final sorted sentence
        for (int i = 1; i <= count; i++) {
            temp += ans[i]; // Append sorted words
            temp += ' '; // Add space
        }

        temp.pop_back(); // Remove the last extra space
        return temp;
    }
};
```

### **Explanation:**
1. **Initialize an array `ans[10]`** to store words in their correct positions.
2. **Extract words from the sentence:**  
   - Whenever a space is encountered, extract the **position** from the last character and store the word at the correct index.
3. **Handle the last word:**  
   - Since the loop stops before the last word is processed, manually store it.
4. **Construct the final sentence:**  
   - Iterate through `ans` and build the final sorted sentence.

### **Example Input & Output:**
```cpp
string s = "is2 sentence4 This1 a3";
cout << sortSentence(s); // Output: "This is a sentence"
```
**Explanation:**  
- The given sentence `"is2 sentence4 This1 a3"` gets sorted as:
  - `"This1"` → **Position 1** → `"This"`
  - `"is2"` → **Position 2** → `"is"`
  - `"a3"` → **Position 3** → `"a"`
  - `"sentence4"` → **Position 4** → `"sentence"`
- The final sorted sentence: `"This is a sentence"`

⏩ **Time Complexity:** O(N)  
⏩ **Space Complexity:** O(N)  

---

### **📌 Summary Table**
| **Problem** | **Concept** | **Time Complexity** |
|------------|------------|--------------------|
| Longest Palindrome | Frequency counting | O(N) |
| Sorting the Sentence | String parsing & sorting | O(N) |

---

### **🔗 Additional Resources**
- [Leetcode: Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)
- [Leetcode: Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence/)

---

### **💡 Tips for Interviews**
1. **Frequency counting** is useful for palindrome problems.
2. **String parsing** is common in sentence-based problems—use `substr()`, `find()`, and loops effectively.
3. **Edge Cases:** Always check for empty strings, single-character strings, and case sensitivity.

---

