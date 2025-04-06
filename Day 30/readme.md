Here's your **Day 30: Recursion in Strings** notes with full code explanation, line-by-line breakdown, and recursive logic. Let’s go through each problem with a deep dive:

---

## 🚀 Day 30: Recursion in Strings

---

### 🧮 1. Count Vowels in a String (Recursive)

#### ✅ Problem:
Count how many vowels (`a, e, i, o, u`) are present in a string using recursion.

#### 🧾 Code:
```cpp
#include <iostream>
using namespace std;

int CountVowels(string str , int index){
    // Base case: If index is less than 0, stop
    if(index==-1)
        return 0;

    // Check if current char is a vowel
    if(str[index]=='a' || str[index]=='e' || str[index]=='i' || str[index]=='o' || str[index]=='u'){
        return 1 + CountVowels(str , index-1); // Add 1 and check rest
    } else {
        return CountVowels(str , index-1); // Just move on
    }
}

int main(){
    string str = "geiou";
    cout << CountVowels(str , 4);  // Output: 5
}
```

#### 🔄 Recursive Tree for `"geiou"`:
```
Index 4 ('u') → Vowel → 1 + CountVowels(3)
Index 3 ('o') → Vowel → 1 + CountVowels(2)
Index 2 ('i') → Vowel → 1 + CountVowels(1)
Index 1 ('e') → Vowel → 1 + CountVowels(0)
Index 0 ('g') → Not vowel → CountVowels(-1)
Returns: 1+1+1+1+0 = 4 vowels
```

---

### 🔠 2. Convert Lowercase to Uppercase (Recursive)

#### ✅ Problem:
Convert all lowercase characters of a string to uppercase using recursion.

#### 🧾 Code:
```cpp
#include <iostream>
using namespace std;

void LowToUp(string &str , int index){
    // Base case
    if(index==-1)
        return;
    
    // ASCII conversion logic: 'A' + (str[index] - 'a')
    str[index] = 'A' + str[index] - 'a';

    LowToUp(str ,index-1);
} 

int main(){
    string str = "gopal";
    LowToUp(str , 4);   // Calls LowToUp for each index from 4 to 0
    cout << str;        // Output: GOPAL
}
```

#### 🔄 How it works:
```
'g' → 'G'
'o' → 'O'
'p' → 'P'
'a' → 'A'
'l' → 'L'
```
We are using **pass-by-reference** (`string &str`) to reflect changes outside the function.

---

### 🔁 3. Check if a String is Palindrome (Recursive)

#### ✅ Problem:
Check whether a string is a palindrome using recursion.

#### 🧾 Code:
```cpp
#include <iostream>
using namespace std;

bool CheckPalindrome(string str , int start , int end){
    // Base case: if start >= end, it's a palindrome
    if(start >= end)
        return true;

    // If chars don’t match, return false
    if(str[start] != str[end])
        return false;

    // Otherwise, continue checking inside characters
    return CheckPalindrome(str , start+1, end-1);
}

int main(){
    string str = "mom";
    cout << CheckPalindrome(str , 0 , 2);  // Output: 1 (true)
}
```

#### 🔄 Recursive Tree for `"mom"`:
```
start=0, end=2: str[0] == str[2] → m == m → valid → call next
start=1, end=1: str[1] == str[1] → o == o → valid → base case met
```
✅ Output is `true` → It’s a palindrome!

---

### 🔄 4. Reverse a String (Recursive)

#### ✅ Problem:
Reverse the string in-place using recursion and pass-by-reference.

#### 🧾 Code:
```cpp
#include <iostream>
using namespace std;

void reverse(string &str , int start , int end){
    // Base case
    if(start >= end){
       return;
    }

    // Swapping characters at start and end
    char c = str[start];
    str[start] = str[end];
    str[end] = c;

    reverse(str , start+1 , end-1); // Go towards middle
}

int main(){
    string str = "gopal";
    reverse(str , 0 , 4);  // Swaps g↔l, o↔a
    cout << str;           // Output: lapog
}
```

#### 🔄 Swap Steps:
```
start=0, end=4 → g <-> l → lopal
start=1, end=3 → o <-> a → lapog
start=2, end=2 → middle reached → stop
```

---

## 🔚 Summary

| Problem               | Base Case                | Operation                  | Key Idea                        |
|-----------------------|--------------------------|----------------------------|----------------------------------|
| Count Vowels          | index == -1              | Check if vowel, add 1      | Linear recursion from end       |
| To Uppercase          | index == -1              | Use ASCII trick            | Convert char recursively        |
| Check Palindrome      | start >= end             | Compare start & end chars  | Compare from outside in         |
| Reverse String        | start >= end             | Swap and recurse inwards   | In-place 2-pointer recursion    |

---

