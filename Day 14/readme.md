Here’s your **updated Day 14 notes**, now including **Factorial of Large Number** along with **Roman to Integer** in a **GitHub README style** with **clear explanations, well-commented code, and examples**.

---

# **Day 14: Factorial of Large Number || Roman to Integer**

## **1️⃣ Roman to Integer** (LeetCode **Easy** – #13)

### **Problem Statement**
Given a **Roman numeral** as input, convert it into an **integer**.

📌 **Roman numeral rules:**
- `I (1)`, `V (5)`, `X (10)`, `L (50)`, `C (100)`, `D (500)`, `M (1000)`.
- If a **smaller numeral** comes before a **larger numeral**, subtract it.
- Otherwise, add the numeral values.

🔹 **Example Inputs & Outputs**
```cpp
Input:  "III"
Output: 3

Input:  "IV"
Output: 4  // I before V means 5 - 1 = 4

Input:  "IX"
Output: 9  // I before X means 10 - 1 = 9

Input:  "LVIII"
Output: 58  // L(50) + V(5) + III(3)

Input:  "MCMXCIV"
Output: 1994 // M(1000) + CM(900) + XC(90) + IV(4)
```

---

### **Code Implementation**
```cpp
#include <iostream>
using namespace std;

// Function to map Roman characters to integer values
int num(char c) {
    if (c == 'I') return 1;
    else if (c == 'V') return 5;
    else if (c == 'X') return 10;
    else if (c == 'L') return 50;
    else if (c == 'C') return 100;
    else if (c == 'D') return 500;
    else return 1000; // Case for 'M'
}

// Function to convert Roman numeral to integer
int romanToInt(string s) {
    int sum = 0, index = 0;

    // Loop through the string
    while (index < s.size() - 1) {
        // If current character's value < next character, subtract it
        if (num(s[index]) < num(s[index + 1])) 
            sum -= num(s[index]);
        else 
            sum += num(s[index]);
        index++; // Move to the next character
    }

    // Add the last character value (not compared in loop)
    sum += num(s[index]);

    return sum;
}

// Example usage
int main() {
    string roman = "MCMXCIV";
    cout << "Integer value: " << romanToInt(roman) << endl;
    return 0;
}
```

✅ **Time Complexity:** `O(N)`, where `N` is the length of the Roman numeral.  
✅ **Space Complexity:** `O(1)`, as we use only a few variables.

---

## **2️⃣ Factorial of Large Number** (GFG **Medium**)

### **Problem Statement**
Compute the factorial of a large number **n!** efficiently without built-in functions, handling **large values (up to 100!)**.

📌 **Example Inputs & Outputs**
```cpp
Input: n = 5
Output: 120

Input: n = 10
Output: 3628800

Input: n = 25
Output: 15511210043330985984000000
```

---

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute large factorial
vector<int> factorial(int n) {
    vector<int> ans(1, 1); // Initialize result array with 1

    while (n > 1) {
        int carry = 0, res, size = ans.size();

        // Multiply each digit with n
        for (int i = 0; i < size; i++) {
            res = ans[i] * n + carry;
            ans[i] = res % 10;  // Store last digit
            carry = res / 10;   // Carry forward remaining digits
        }

        // Append remaining carry digits
        while (carry) {
            ans.push_back(carry % 10);
            carry /= 10;
        }

        n--; // Decrement n
    }

    // Reverse to get the correct order
    reverse(ans.begin(), ans.end());
    return ans;
}

// Example usage
int main() {
    int n = 10;
    vector<int> result = factorial(n);

    cout << "Factorial of " << n << " is: ";
    for (int digit : result) cout << digit;
    cout << endl;

    return 0;
}
```

✅ **Time Complexity:** `O(N * log N)` due to multiplication and carry handling.  
✅ **Space Complexity:** `O(N)`, since we store all digits in an array.

---

### **Summary of Day 14**
| Problem | Difficulty | Concept |
|----------|------------|----------|
| **Roman to Integer** | Easy | String processing, mapping values, subtraction rule |
| **Factorial of Large Number** | Medium | Array-based multiplication, carry handling |

---
