# Day 25: Introduction to Recursion

## 📌 What is Recursion?
Recursion is a programming technique where a function calls itself to solve a problem. It consists of:
- **Base Case**: The stopping condition to prevent infinite recursion.
- **Recursive Case**: The function calling itself to break the problem into smaller subproblems.

### 🔹 Key Points:
✔ Every recursion must have a **base case** to prevent infinite loops.
✔ Recursive functions use the **call stack** for execution.
✔ Some problems are easier to solve using recursion than iteration.
✔ Recursive functions follow the **divide & conquer** approach.

---

## 🔹 Example 1: Countdown to Birthday (Recursive vs Iterative)

### ✅ Iterative Approach
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = n; i >= 0; i--) {
        if (i == 0) {
            cout << "Happy Birthday!";
            return 0;
        }
        cout << i << " Days Left for the birthday" << endl;
    }
}
```
### ✅ Recursive Approach
```cpp
#include <iostream>
using namespace std;

void fun(int n) {
    if (n == 0) {
        cout << "Happy Birthday to me..";
        return;
    }
    cout << n << " Days Left for birthday" << endl;
    fun(n - 1);
}

int main() {
    fun(5); // Call function with 5 days countdown
}
```

### 🔹 Recursive Tree Visualization
```
fun(5) → prints "5 Days Left"
  ↳ fun(4) → prints "4 Days Left"
    ↳ fun(3) → prints "3 Days Left"
      ↳ fun(2) → prints "2 Days Left"
        ↳ fun(1) → prints "1 Day Left"
          ↳ fun(0) → prints "Happy Birthday!"
```
---

## 🔹 Example 2: Print N to 1 using Recursion
```cpp
#include <iostream>
using namespace std;

void print(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    cout << n << " ";
    print(n - 1);
}

int main() {
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    print(n);
}
```
**Recursive Tree:**
```
print(5) → prints 5
  ↳ print(4) → prints 4
    ↳ print(3) → prints 3
      ↳ print(2) → prints 2
        ↳ print(1) → prints 1
```
---

## 🔹 Example 3: Print Even Numbers using Recursion
```cpp
#include <iostream>
using namespace std;

void printEven(int n) {
    if (n == 2) {
        cout << 2;
        return;
    }
    cout << n << " ";
    printEven(n - 2);
}

int main() {
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    printEven(n);
    return 0;
}
```
**Recursive Tree:**
```
printEven(10) → prints 10
  ↳ printEven(8) → prints 8
    ↳ printEven(6) → prints 6
      ↳ printEven(4) → prints 4
        ↳ printEven(2) → prints 2
```
---

## 🏆 Homework Questions

### 1️⃣ Print "Coder Army" N times using Recursion
```cpp
#include <iostream>
using namespace std;

void print(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " : Coder Army" << endl;
    print(n - 1);
}

int main() {
    print(10);
}
```

### 2️⃣ Print All Odd Numbers from N to 1 using Recursion
```cpp
#include <iostream>
using namespace std;

void print(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n % 2 == 1) {
        cout << n << " ";
    }
    print(n - 1);
}

int main() {
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    print(n);
}
```

### 3️⃣ Print Numbers from 1 to N using Recursion
```cpp
#include <iostream>
using namespace std;

void print(int n) {
    if (n == 20) {
        cout << n;
        return;
    }
    cout << n << " ";
    print(n + 1);
}

int main() {
    int n = 1;
    print(n);
}
```
---

## 🔥 Key Takeaways
✔ Recursion is useful for **breaking down problems** into smaller subproblems.  
✔ Always define a **base case** to prevent infinite recursion.  
✔ **Recursive tree** helps in understanding function calls.  
✔ Iterative and recursive methods both **require termination conditions**.  
✔ Recursion can be more **memory-intensive** due to stack usage.  

