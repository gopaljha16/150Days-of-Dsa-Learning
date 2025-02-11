# Day 10: Introduction to Strings in C++

## Character Arrays vs Strings

### 1. Creating a Character Array
```cpp
#include <iostream>
using namespace std;

int main(){
    char arr[] = {'a','b','c','d','e'};
    for(int i=0; i<5; i++)
        cout << arr[i];
    return 0;
}
```
**Explanation:**
- Character arrays store individual characters.
- Printing the character array requires looping through elements.

### 2. Using `char` Array with `cin`
```cpp
char chart[20]; // Array of size 20
cin >> chart;
cout << chart;
```
**Issue:**
- `cin` stops reading input when it encounters a space, tab, or newline.

### 3. Null Character (`\0`)
```cpp
char arr[20];
cin >> arr;
arr[2] = '\0';
cout << arr;
```
**Explanation:**
- `\0` marks the end of a string in a character array.
- The string will print only up to the null character.

---

## Strings in C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s;
    getline(cin, s); // Reads full line including spaces
    cout << s;
}
```
**Advantages over `char[]`:**
- Can store space-separated words.
- Supports built-in functions like `.size()`, `.append()`, `.push_back()`, etc.

### 1. String Size
```cpp
cout << s.size();
```
- Returns the length of the string.

### 2. Concatenation
```cpp
string s1 = "Gopal";
string s2 = "Jha";
string s3 = s1 + s2; // GopalJha
cout << s3;
```
**Alternative:**
```cpp
string s3 = s1.append(s2);
cout << s3;
```

### 3. Insert and Delete Characters
```cpp
string s = "Gopal";
s.push_back('p');
cout << s << endl; // Gopalp
s.pop_back();
cout << s << endl; // Gopal
```

### 4. Escape Characters
```cpp
string s = "Gopal jha is a \"good\" boy";
cout << s;
```
**Output:** `Gopal jha is a "good" boy`

```cpp
string st = "\\"; // Prints a single backslash
cout << st;
```
**Output:** `\`

---

## String Manipulation

### 1. Reverse a String
```cpp
#include <iostream>
using namespace std;

int main(){
    string s = "Gopal";
    int start = 0, end = s.size() - 1;
    while(start < end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    cout << s;
    return 0;
}
```
**Explanation:**
- Uses two-pointer technique to swap elements until reaching the middle.

### 2. Calculate String Size Manually
```cpp
#include <iostream>
using namespace std;

int main(){
    string s = "Gopal";
    int size = 0;
    while(s[size] != '\0'){
        size++;
    }
    cout << size;
    return 0;
}
```
**Explanation:**
- Uses a loop to count characters until the null character is found.

### 3. Check for Palindrome
```cpp
#include <iostream>
using namespace std;

int main(){
    string s = "naman";
    int start = 0, end = s.size() - 1;
    while(start < end){
        if(s[start] != s[end]){
            cout << "Not a Palindrome";
            return 0;
        }
        start++;
        end--;
    }
    cout << "The String is a palindrome";
    return 0;
}
```
**Explanation:**
- Compares characters from both ends until they meet in the middle.
- If any mismatch is found, it's not a palindrome.

---
### Summary
| Concept | Code Example | Description |
|---------|-------------|-------------|
| Character Array | `char arr[] = {'a','b','c','d','e'};` | Stores characters as an array |
| String Input | `getline(cin, s);` | Reads space-separated words |
| String Size | `s.size();` | Returns string length |
| Concatenation | `s1 + s2` or `s1.append(s2)` | Joins two strings |
| Insert/Delete | `s.push_back('p'); s.pop_back();` | Add or remove characters at the end |
| Escape Characters | `"Gopal jha is a \"good\" boy"` | Prints `"` inside string |
| Reverse String | `swap(s[start], s[end]);` | Reverses characters in place |
| String Size Manually | `while(s[size] != '\0')` | Counts characters manually |
| Palindrome Check | `s[start] != s[end]` | Compares characters from both ends |

These concepts form the foundation for string handling in C++. 🚀

