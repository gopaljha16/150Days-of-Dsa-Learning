# Recursion: Factorial, Sum of N Numbers, Power of a Number, and Sum of Squares

## 1. Factorial of a Number using Recursion

### Code:

```cpp
#include <iostream>
using namespace std;

int fact(int n) {
    // Base case: Factorial of 0 or 1 is 1
    if(n == 1 || n == 0) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * fact(n - 1);
}

int main() {
    int n;
    cout << "Enter your factorial Number: ";
    cin >> n;
    
    // Handling negative input
    if(n < 0) {
        cout << "Factorial of negative number is not possible";
        return 0;
    }
    
    cout << fact(n) << endl;
    return 0;
}
```

### Explanation:

- The function calls itself recursively until it reaches the base case (`n == 0` or `n == 1`).
- If the user enters a negative number, the function handles it gracefully.
- **Recursion Tree for **``**:**
  ```
  fact(5) = 5 * fact(4)
              4 * fact(3)
                  3 * fact(2)
                      2 * fact(1)
                          1 (Base case)
  ```

## 2. Power of a Number using Recursion

### Code:

```cpp
#include <iostream>
using namespace std;

int Pow(int num, int n) {
    // Base case: Any number raised to power 0 is 1
    if(n == 0) return 1;
    if(n == 1) return num;
    
    return num * Pow(num, n - 1);
}

int main() {
    int power, num;
    cout << "Enter the base number: ";
    cin >> num;
    cout << "Enter the exponent: ";
    cin >> power;
    
    cout << Pow(num, power);
}
```

### Explanation:

- If `n == 0`, return `1` (base case).
- If `n == 1`, return `num`.
- Otherwise, multiply `num` by `Pow(num, n-1)`.
- **Recursion Tree for **``**:**
  ```
  Pow(2,3) = 2 * Pow(2,2)
                 2 * Pow(2,1)
                     2 (Base case)
  ```

## 3. Sum of N Natural Numbers using Recursion

### Code:

```cpp
#include <iostream>
using namespace std;

int sum(int n) {
    if(n == 1) return 1;
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    cout << sum(n);
}
```

### Explanation:

- Base case: `sum(1) = 1`.
- Recursive case: `sum(n) = n + sum(n-1)`.
- **Recursion Tree for **``**:**
  ```
  sum(4) = 4 + sum(3)
              3 + sum(2)
                  2 + sum(1)
                      1 (Base case)
  ```

## 4. Sum of Squares of N Natural Numbers using Recursion

### Code:

```cpp
#include <iostream>
using namespace std;

int Sq(int n) {
    if(n == 1) return 1;
    return n * n + Sq(n - 1);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    if(n < 1) return 0;
    cout << Sq(n);
}
```

### Explanation:

- Base case: `Sq(1) = 1`.
- Recursive case: `Sq(n) = n^2 + Sq(n-1)`.
- **Recursion Tree for **``**:**
  ```
  Sq(3) = 3^2 + Sq(2)
             2^2 + Sq(1)
                 1 (Base case)
  ```

## Homework Questions:

### 1. Sum of Cubes of N Natural Numbers using Recursion

#### Code:

```cpp
#include <iostream>
using namespace std;

int cube(int n) {
    if(n == 1) return 1;
    return n * n * n + cube(n - 1);
}

int main() {
    int n;
    cout << "Enter the n value: ";
    cin >> n;
    cout << cube(n);
}
```

### Explanation:

- Base case: `cube(1) = 1`.
- Recursive case: `cube(n) = n^3 + cube(n-1)`.
- **Recursion Tree for **``**:**
  ```
  cube(3) = 3^3 + cube(2)
               2^3 + cube(1)
                   1 (Base case)
  ```

## Summary:

| Function         | Base Case         | Recursive Case                      |
| ---------------- | ----------------- | ----------------------------------- |
| Factorial        | `fact(0) = 1`     | `fact(n) = n * fact(n-1)`           |
| Power            | `Pow(num, 0) = 1` | `Pow(num, n) = num * Pow(num, n-1)` |
| Sum of N Numbers | `sum(1) = 1`      | `sum(n) = n + sum(n-1)`             |
| Sum of Squares   | `Sq(1) = 1`       | `Sq(n) = n^2 + Sq(n-1)`             |
| Sum of Cubes     | `cube(1) = 1`     | `cube(n) = n^3 + cube(n-1)`         |



