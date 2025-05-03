Here are the detailed **Day 50: Exception Handling in C++** notes with complete explanations, code walkthroughs, and flowcharts to help you master the topic.

---

# 📘 Day 50: Exception Handling in C++

---

## 🧠 What is Exception Handling?

Exception handling is a way to **manage runtime errors** gracefully, preventing the program from crashing. Instead of halting, it catches errors and lets the program recover or end cleanly.

### 🔥 Why is it needed?

* Prevents program from abrupt termination.
* Useful for catching **unexpected inputs**, **invalid operations**, **memory issues**, etc.
* Helps maintain clean error reporting and debugging.

---

## ⚙️ Keywords in Exception Handling

| Keyword     | Description                                              |
| ----------- | -------------------------------------------------------- |
| `try`       | Wraps code that might throw an exception.                |
| `catch`     | Catches the thrown exception and handles it.             |
| `throw`     | Throws an exception when an error occurs.                |
| `exception` | A base class in C++ Standard Library for all exceptions. |

---

## 🧪 Try-Catch-Throw Flow

### 📊 Flowchart of Try-Catch Block:

```plaintext
           ┌──────────────┐
           │   try block  │
           └──────┬───────┘
                  │
         Exception thrown?
            /         \
          Yes          No
          /             \
┌─────────────┐      Continue
│   throw     │
└─────┬───────┘
      │
┌─────▼───────────┐
│   Matching catch│
│     block       │
└─────┬───────────┘
      │
Continue Execution
```

---

## 🧾 Example 1: Basic Try-Catch with Division

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    try {
        if (b == 0)
            throw "Can't be divisible by 0";
        cout << "Result: " << a / b << endl;
    } catch (const char* e) {
        cout << "Exception occurred: " << e << endl;
    }
}
```

### 🧠 Key Point:

* We throw a C-style string.
* Catch block captures `const char*`.

---

## 🧾 Example 2: Memory Allocation Failure (bad\_alloc)

```cpp
#include <iostream>
#include <exception>
using namespace std;

int main() {
    try {
        int* p = new int[10000000000000]; // Excessive allocation
        cout << "Memory allocated";
        delete[] p;
    } catch (const bad_alloc& e) {
        cout << "Exception: " << e.what() << endl;
    }
}
```

### 📘 Note:

* `bad_alloc` is a predefined class in `<exception>`.
* `what()` returns the error message.

---

## 🧾 Example 3: Custom Exception using `runtime_error`

```cpp
#include <iostream>
#include <exception>
using namespace std;

class InvalidAmountError : public runtime_error {
public:
    InvalidAmountError(const string &msg) : runtime_error(msg) {}
};

class Customer {
    string name;
    int balance, acc_no;

public:
    Customer(string name, int balance, int acc_no)
        : name(name), balance(balance), acc_no(acc_no) {}

    void deposit(int amount) {
        if (amount <= 0)
            throw runtime_error("Amount should be greater than 0");
        balance += amount;
        cout << amount << " credited successfully\n";
    }

    void withdraw(int amount) {
        if (amount <= 0)
            throw runtime_error("Amount should be greater than 0");
        else if (amount > balance)
            throw runtime_error("Insufficient balance");
        balance -= amount;
        cout << amount << " debited successfully\n";
    }
};
```

```cpp
int main() {
    Customer C1("Gopal", 3000, 123);
    try {
        C1.deposit(100);
        C1.withdraw(3200);  // throws "Insufficient balance"
    } catch (const runtime_error &e) {
        cout << "Exception occurred: " << e.what() << endl;
    }
}
```

---

## 🔂 Multiple Catch Blocks

You can define multiple `catch` blocks to handle different types of exceptions.

```cpp
try {
   // risky code
} catch (const runtime_error& e) {
   // Handle logic errors
} catch (const bad_alloc& e) {
   // Handle memory errors
} catch (...) {
   // Catch-all block
}
```

---

## 📦 Summary Table

| Concept          | Example                           | Explanation                      |
| ---------------- | --------------------------------- | -------------------------------- |
| `try`            | `try { ... }`                     | Code that might fail             |
| `throw`          | `throw "error";`                  | Throws an exception              |
| `catch`          | `catch (const char* e)`           | Handles specific exception       |
| `bad_alloc`      | Catch memory issues               |                                  |
| `runtime_error`  | Standard class for logical errors |                                  |
| Custom Exception | Inherit from `runtime_error`      | Make user-defined error messages |

---

## ✅ Output Examples

### Division Example:

```
Input: 5 0
Output: Exception occurred: Can't be divisible by 0
```

### Customer Banking Example:

```
100 credited successfully
Exception occurred: Insufficient balance
```

---

## 📘 Real-World Usage

* File not found
* Network failure
* Invalid user input
* Buffer overflows
* Memory allocation failure

---

