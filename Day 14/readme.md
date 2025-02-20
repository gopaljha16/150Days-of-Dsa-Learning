
---

# **Day 14: Factorial of Large Number || Integer to Roman || Roman to Integer**

## **1️⃣ Roman to Integer** (LeetCode **Easy** – #13)

### **Problem Statement**
Given a **Roman numeral**, convert it into an **integer**.

📌 **Rules:**
- `I (1)`, `V (5)`, `X (10)`, `L (50)`, `C (100)`, `D (500)`, `M (1000)`.
- If a **smaller numeral** comes before a **larger numeral**, subtract it.
- Otherwise, add the numeral values.

🔹 **Example Inputs & Outputs**
```cpp
Input:  "III"
Output: 3

Input:  "IV"
Output: 4  // I before V means 5 - 1 = 4

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

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(1)`

---

## **2️⃣ Integer to Roman** (LeetCode **Medium** – #12)

### **Problem Statement**
Convert an **integer** to its **Roman numeral** representation.

📌 **Rules:**
- `1 → I, 4 → IV, 5 → V, 9 → IX, 10 → X, 40 → XL, 50 → L, 90 → XC, 100 → C, 400 → CD, 500 → D, 900 → CM, 1000 → M`
- Start from the largest possible value and keep subtracting.

🔹 **Example Inputs & Outputs**
```cpp
Input:  3
Output: "III"

Input:  58
Output: "LVIII"

Input:  1994
Output: "MCMXCIV"
```

---

### **Code Implementation**
```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to return the correct Roman numeral symbol
    string roman(int num) {
        if (num >= 1000) return "M";
        else if (num >= 900) return "CM";
        else if (num >= 500) return "D";
        else if (num >= 400) return "CD";
        else if (num >= 100) return "C";
        else if (num >= 90) return "XC";
        else if (num >= 50) return "L";
        else if (num >= 40) return "XL";
        else if (num >= 10) return "X";
        else if (num >= 9) return "IX";
        else if (num >= 5) return "V";
        else if (num >= 4) return "IV";
        else return "I";
    }

    // Function to get the integer value of a Roman numeral symbol
    int getValue(string s) {
        if (s == "M") return 1000;
        if (s == "CM") return 900;
        if (s == "D") return 500;
        if (s == "CD") return 400;
        if (s == "C") return 100;
        if (s == "XC") return 90;
        if (s == "L") return 50;
        if (s == "XL") return 40;
        if (s == "X") return 10;
        if (s == "IX") return 9;
        if (s == "V") return 5;
        if (s == "IV") return 4;
        return 1;
    }

    // Function to convert integer to Roman numeral
    string intToRoman(int num) {
        string result = "";

        while (num > 0) {
            string symbol = roman(num); // Get the highest possible Roman numeral
            result += symbol; // Append it to the result
            num -= getValue(symbol); // Subtract the value from num
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    int num = 1994;
    cout << "Roman numeral: " << sol.intToRoman(num) << endl;
    return 0;
}
```

✅ **Time Complexity:** `O(1)` (constant time, as the max iterations are fixed)  
✅ **Space Complexity:** `O(1)`

---

## **3️⃣ Factorial of Large Number** (GFG **Medium**)

### **Problem Statement**
Compute the factorial of a **large number (up to 100!)** without overflow.

🔹 **Example Inputs & Outputs**
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

✅ **Time Complexity:** `O(N * log N)`  
✅ **Space Complexity:** `O(N)`

---

### **📌 Summary of Day 14**
| Problem | Difficulty | Concept |
|----------|------------|----------|
| **Roman to Integer** | Easy | String processing, mapping values, subtraction rule |
| **Integer to Roman** | Medium | Greedy approach, mapping values |
| **Factorial of Large Number** | Medium | Array-based multiplication, carry handling |

---

