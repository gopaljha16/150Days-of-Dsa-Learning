# Day 26: How to Solve Recursion Problems in 4 Different Methods

## 📌 Introduction to Recursion
Recursion is a technique where a function calls itself to solve smaller subproblems of the original problem. Every recursive function must have a **base case** to terminate the recursion and avoid infinite loops.

---

## 🔹 Printing Even Numbers using Recursion
### ✅ Forward Order
```cpp
#include <iostream>
using namespace std;

void printEven(int num, int n) {
    // Base condition
    if (num > n)
        return;
    
    cout << num << " ";
    printEven(num + 2, n);
}

int main() {
    int n = 10; // Upper limit
    printEven(2, n); // Starts from 2
    return 0;
}
```
#### 📌 Explanation:
- Function `printEven(num, n)` prints even numbers up to `n`.
- **Base Case**: If `num > n`, return (stops recursion).
- **Recursive Case**: Print `num`, then call `printEven(num+2, n)`.
- **Output**: `2 4 6 8 10`

### ✅ Reverse Order
```cpp
#include <iostream>
using namespace std;

void printEven(int n) {
    // Base case
    if (n == 2) {
        cout << 2 << " ";
        return;
    }
    
    printEven(n - 2); // First recursive call
    cout << n << " "; // Print after recursion
}

int main() {
    int n = 11;
    if (n % 2 == 1) n--; // Ensure `n` is even
    printEven(n);
    return 0;
}
```
#### 📌 Explanation:
- **Base Case**: If `n == 2`, print `2` and stop.
- **Recursive Case**: Call `printEven(n-2)`, then print `n`.
- **Output**: `2 4 6 8 10`

---

## 🔹 Printing Numbers from 1 to n using Recursion
### ✅ Forward Order
```cpp
#include <iostream>
using namespace std;

void print1_to_n(int num, int n) {
    // Base case
    if (num == n) {
        cout << num;
        return;
    }
    
    cout << num << " ";
    print1_to_n(num + 1, n);
}

int main() {
    int n = 5;
    print1_to_n(1, n);
    return 0;
}
```
#### 📌 Explanation:
- **Base Case**: If `num == n`, print `n` and stop.
- **Recursive Case**: Print `num`, then call `print1_to_n(num+1, n)`.
- **Output**: `1 2 3 4 5`

### ✅ Reverse Order
```cpp
#include <iostream>
using namespace std;

void print1_to_n(int num) {
    if (num == 1) {
        cout << 1 << " ";
        return;
    }
    
    print1_to_n(num - 1);
    cout << num << " ";
}

int main() {
    int n = 5;
    print1_to_n(n);
    return 0;
}
```
#### 📌 Explanation:
- **Base Case**: If `num == 1`, print `1` and stop.
- **Recursive Case**: Call `print1_to_n(num-1)`, then print `num`.
- **Output**: `1 2 3 4 5`

### 🛠 Recursive Tree:
```
print1_to_n(5)  
├── print1_to_n(4)  
│    ├── print1_to_n(3)  
│    │    ├── print1_to_n(2)  
│    │    │    ├── print1_to_n(1) → Prints: "1 "  
│    │    │    └── Returns, prints: "2 "  
│    │    ├── Returns, prints: "3 "  
│    ├── Returns, prints: "4 "  
├── Returns, prints: "5 "  
```

---

## 🔹 Homework Questions

### ✅ 1: Print all Odd Numbers from 1 to n
```cpp
#include <iostream>
using namespace std;

void printOdd(int n) {
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    
    printOdd(n - 2);
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter your n value: ";
    cin >> n;
    if (n % 2 == 0) n++;
    printOdd(n);
    return 0;
}
```
#### 📌 Recursive Tree:
```
printOdd(9)
├── printOdd(7)
│    ├── printOdd(5)
│    │    ├── printOdd(3)
│    │    │    ├── printOdd(1) → Prints: "1 "
│    │    │    └── Returns, prints: "3 "
│    │    ├── Returns, prints: "5 "
│    ├── Returns, prints: "7 "
├── Returns, prints: "9 "
```

---

### ✅ 2: Print all Numbers from 10 to n
```cpp
#include <iostream>
using namespace std;

void printNum(int num, int n) {
    if (num == n) {
        cout << num << " ";
        return;
    }
    
    cout << num << " ";
    printNum(num + 1, n);
}

int main() {
    int n;
    cout << "Enter n value: ";
    cin >> n;
    printNum(10, n);
    return 0;
}
```

---

### ✅ 3: Print Multiplication Table using Recursion
```cpp
#include <iostream>
using namespace std;

void printTable(int num, int n) {
    if (num == 1) {
        cout << num * n << endl;
        return;
    }
    
    printTable(num - 1, n);
    cout << num * n << endl;
}

int main() {
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    printTable(10, n);
    return 0;
}
```

---

## 🔹 Key Takeaways
✔ Always define a **base case** to prevent infinite recursion.  
✔ Recursion can be written in **two ways**: forward and reverse.  
✔ **Recursive tree** helps understand function calls.  
✔ Use recursion for problems with repeated patterns.  
✔ Avoid unnecessary recursive calls for better performance.  


