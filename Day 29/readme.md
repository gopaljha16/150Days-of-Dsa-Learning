Here are your detailed notes for **Day 29 - Recursion in Arrays**, including code explanations and recursive trees for all problems.

---

## 1. Print an Array Using Recursion  

### Code:
```cpp
#include <iostream>
using namespace std;

int PrintArray(int arr[], int index, int n) {
    // Base case: If index reaches n, stop recursion
    if (index == n)
        return 0;

    // Print current element
    cout << arr[index] << " ";

    // Recursive call for next index
    return PrintArray(arr, index + 1, n);
}

int main() {
    int arr[] = {3, 7, 6, 2, 8};
    PrintArray(arr, 0, 5);
}
```
### Recursive Tree:
```
PrintArray(0) → Prints: 3 → Calls PrintArray(1)
    PrintArray(1) → Prints: 7 → Calls PrintArray(2)
        PrintArray(2) → Prints: 6 → Calls PrintArray(3)
            PrintArray(3) → Prints: 2 → Calls PrintArray(4)
                PrintArray(4) → Prints: 8 → Calls PrintArray(5)
                    PrintArray(5) → Stops (Base Case)
```

---

## 2. Reverse Print an Array Using Recursion  

### Code:
```cpp
#include <iostream>
using namespace std;

int ParticularIndex(int arr[], int index) {
    if (index == -1)
        return 0;

    // Print current element
    cout << arr[index] << " ";

    return ParticularIndex(arr, index - 1);
}

int main() {
    int arr[] = {3, 7, 6, 2, 8};
    ParticularIndex(arr, 4);
}
```
### Recursive Tree:
```
ParticularIndex(4) → Prints: 8 → Calls ParticularIndex(3)
    ParticularIndex(3) → Prints: 2 → Calls ParticularIndex(2)
        ParticularIndex(2) → Prints: 6 → Calls ParticularIndex(1)
            ParticularIndex(1) → Prints: 7 → Calls ParticularIndex(0)
                ParticularIndex(0) → Prints: 3 → Calls ParticularIndex(-1)
                    ParticularIndex(-1) → Stops (Base Case)
```

---

## 3. Sum of All Elements in an Array Using Recursion  

### Code:
```cpp
#include <iostream>
using namespace std;

int sum(int arr[], int index, int n) {
    if (index == n)
        return 0;

    return arr[index] + sum(arr, index + 1, n);
}

int main() {
    int arr[] = {3, 4, 5, 8, 2};
    cout << sum(arr, 0, 5);
}
```
### Recursive Tree:
```
sum(0) → Returns: 3 + sum(1)
    sum(1) → Returns: 4 + sum(2)
        sum(2) → Returns: 5 + sum(3)
            sum(3) → Returns: 8 + sum(4)
                sum(4) → Returns: 2 + sum(5)
                    sum(5) → Returns: 0 (Base Case)
Total: 3 + 4 + 5 + 8 + 2 = 22
```

---

## 4. Sum of Squares of N Natural Numbers  

### Code:
```cpp
#include <iostream>
using namespace std;

int Sq(int n) {
    // Base case
    if (n == 1)
        return 1;

    return n * n + Sq(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 1)
        return 0;

    cout << Sq(n);
}
```
### Recursive Tree:
```
Sq(3) → Returns: 3*3 + Sq(2)
    Sq(2) → Returns: 2*2 + Sq(1)
        Sq(1) → Returns: 1*1 (Base Case)
Total: 9 + 4 + 1 = 14
```

---

## 5. Minimum Element in an Array  

### Code:
```cpp
#include <iostream>
using namespace std;

int MinEle(int arr[], int index, int n) {
    if (index == n - 1)
        return arr[index];

    return min(arr[index], MinEle(arr, index + 1, n));
}

int main() {
    int arr[] = {7, 2, 4, 1, 6};
    cout << MinEle(arr, 0, 5);
}
```
### Recursive Tree:
```
MinEle(0) → Compares 7 with MinEle(1)
    MinEle(1) → Compares 2 with MinEle(2)
        MinEle(2) → Compares 4 with MinEle(3)
            MinEle(3) → Compares 1 with MinEle(4)
                MinEle(4) → Returns 6 (Base Case)
            Returns min(1, 6) = 1
        Returns min(4, 1) = 1
    Returns min(2, 1) = 1
Returns min(7, 1) = 1
```

---

## 6. Maximum Element in an Array  

### Code:
```cpp
#include <iostream>
using namespace std;

int MaxElem(int arr[], int index, int n) {
    if (index == n - 1)
        return arr[index];

    return max(arr[index], MaxElem(arr, index + 1, n));
}

int main() {
    int arr[] = {7, 2, 5, 22, 1};
    cout << MaxElem(arr, 0, 5);
}
```
### Recursive Tree:
```
MaxElem(0) → Compares 7 with MaxElem(1)
    MaxElem(1) → Compares 2 with MaxElem(2)
        MaxElem(2) → Compares 5 with MaxElem(3)
            MaxElem(3) → Compares 22 with MaxElem(4)
                MaxElem(4) → Returns 1 (Base Case)
            Returns max(22, 1) = 22
        Returns max(5, 22) = 22
    Returns max(2, 22) = 22
Returns max(7, 22) = 22
```

---

## 7. Product of All Elements in an Array  

### Code:
```cpp
#include <iostream>
using namespace std;

int Product(int arr[], int index, int n) {
    if (index == n - 1)
        return arr[index];

    return arr[index] * Product(arr, index + 1, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << Product(arr, 0, 5);
}
```
### Recursive Tree:
```
Product(0) → Returns 1 * Product(1)
    Product(1) → Returns 2 * Product(2)
        Product(2) → Returns 3 * Product(3)
            Product(3) → Returns 4 * Product(4)
                Product(4) → Returns 5 (Base Case)
Total: 1 * 2 * 3 * 4 * 5 = 120
```

---

## 8. Find Even Elements in an Array  

### Code:
```cpp
#include <iostream>
using namespace std;

void EvenElem(int arr[], int index, int n) {
    if (index == n)
        return;

    if (arr[index] % 2 == 0)
        cout << arr[index] << " ";

    EvenElem(arr, index + 1, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    EvenElem(arr, 0, 5);
}
```
### Output:
```
2 4
```

---

### ✅ These notes include:
✔ **Code with comments**  
✔ **Recursive tree breakdown**  
✔ **Detailed explanations of how recursion works in each problem**  

