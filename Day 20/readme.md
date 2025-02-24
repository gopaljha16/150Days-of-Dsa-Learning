# **Day 20: Pointers Relationship with Arrays & Pointer Arithmetic**

## **Introduction to Pointers and Arrays**

### **What is a Pointer?**
A pointer is a variable that stores the memory address of another variable. Instead of storing actual values, pointers hold addresses that point to a location in memory where a value is stored.

### **Memory Allocation and Address Representation**
Each variable in memory is stored at a unique address. Pointers help in accessing these addresses and manipulating the values stored at them.

---

## **Pointers and Arrays Relationship**
Arrays and pointers share a close relationship in C++. The name of an array (`arr`) acts as a pointer to its first element. This means `arr` is equivalent to `&arr[0]`.

### **Code Example**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {11, 10, 9, 2, 1};

    // Printing memory addresses of array elements
    cout << "Memory addresses of array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Address of arr[" << i << "]: " << arr + i << endl;
    }

    // Printing values using pointers
    cout << "Values using pointers:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Value at address " << arr + i << ": " << *(arr + i) << endl;
    }
    return 0;
}
```

### **Explanation:**
- `arr` holds the address of `arr[0]`.
- `arr + i` gives the address of `arr[i]`.
- `*(arr + i)` gives the value stored at `arr[i]`.

---

## **Pointer Arithmetic**
Pointer arithmetic is based on the size of the data type. If an integer pointer (`int *ptr`) is incremented, it moves to the next integer in memory (usually 4 bytes ahead on a 32-bit system).

### **Arithmetic Operations on Pointers**
1. **Increment (`ptr++`)**: Moves pointer to the next element.
2. **Decrement (`ptr--`)**: Moves pointer to the previous element.
3. **Addition (`ptr + n`)**: Moves pointer `n` elements forward.
4. **Subtraction (`ptr - n`)**: Moves pointer `n` elements backward.

### **Code Example**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;  // Pointer to first element

    // Printing addresses
    cout << "Memory addresses using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Address: " << ptr + i << " Value: " << *(ptr + i) << endl;
    }

    // Incrementing pointer
    ptr += 2;
    cout << "Pointer moved 2 steps forward: " << *ptr << endl;

    // Decrementing pointer
    ptr -= 1;
    cout << "Pointer moved 1 step backward: " << *ptr << endl;
    
    return 0;
}
```

### **Explanation:**
- `ptr + i` moves the pointer to the `i`-th element.
- `*(ptr + i)` accesses the value at that memory address.
- `ptr += 2` moves the pointer two positions ahead.
- `ptr -= 1` moves it back one position.

---

## **Symbol Table & Memory Representation**
### **Example:**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
```
**Memory Representation:**
| Index  | Address    | Value |
|--------|-----------|-------|
| arr[0] | 0x1000    | 1     |
| arr[1] | 0x1004    | 2     |
| arr[2] | 0x1008    | 3     |
| arr[3] | 0x100C    | 4     |
| arr[4] | 0x1010    | 5     |

- `arr` and `ptr` both initially point to `0x1000` (address of `arr[0]`).
- `ptr + 1` moves to `0x1004`, which stores `arr[1]`.

---

## **Why Can't We Do `arr = arr + 2`?**
### **Understanding Immutable Array Name**
The name of an array (`arr`) acts as a constant pointer, meaning it cannot be modified.

```cpp
int arr[5] = {1, 2, 3, 4, 5};
arr = arr + 2;  // ❌ ERROR: assignment of read-only variable
```
**Reason:**
- `arr` is a fixed address that cannot be changed.
- `ptr` is a pointer that **can** be incremented (`ptr++` is allowed).

### **Workaround:**
If you want to manipulate the address, use a pointer:
```cpp
int *ptr = arr;
ptr = ptr + 2;  // ✅ Allowed
```
Now, `ptr` points to `arr[2]`.

---

## **Conclusion**
1. **Arrays and pointers are closely related**, but an array name (`arr`) cannot be modified, unlike a pointer.
2. **Pointer arithmetic allows easy traversal of arrays** using `ptr + n`.
3. **Understanding memory layout** helps in debugging pointer-related issues.
4. **Using pointers efficiently** avoids errors like accessing out-of-bound memory.

Mastering pointers and array relationships is crucial for efficient memory handling in C++! 🚀

