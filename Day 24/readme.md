# Day 23: Memory Allocation (Static & Dynamic)

## 📌 Memory Allocation in C++
Memory allocation refers to reserving memory for variables and data structures. It can be **static** or **dynamic**, each with different behaviors.

---

## 🔹 Static Memory Allocation
- Memory is allocated **at compile time**.
- Stored in the **stack**.
- Memory is **automatically** deallocated at the end of scope.
- Efficient but **not flexible** (size cannot change during runtime).

### ✅ Example: Static Allocation
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10; // Memory allocated in stack
    float b = 5.5; // Stored in stack
    int arr[5] = {1, 2, 3, 4, 5}; // Fixed size array in stack

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    return 0;
}
```

---

## 🔹 Dynamic Memory Allocation
- Memory is allocated **at runtime** using the `new` keyword.
- Allocated memory exists **until explicitly deallocated** using `delete`.
- Stored in the **heap**.
- Allows for **flexible memory usage**.

### ✅ Example: Dynamic Allocation
```cpp
#include <iostream>
using namespace std;

int main() {
    int *ptr = new int; // Allocating memory in heap
    *ptr = 5; // Storing value
    cout << "Value stored in heap: " << *ptr << endl;
    cout << "Address in heap: " << ptr << endl;
    
    delete ptr; // Freeing memory
    return 0;
}
```

---

## 🔹 Heap vs. Stack Memory
| Feature | Stack Memory | Heap Memory |
|---------|-------------|------------|
| **Allocation Time** | Compile-time | Runtime |
| **Access Speed** | Faster | Slower |
| **Flexibility** | Fixed size | Can resize dynamically |
| **Memory Deallocation** | Automatic | Manual (`delete`) |
| **Storage** | Local variables | Dynamically allocated variables |

---

## 🔹 Dynamic Memory Allocation Examples

### ✅ Allocating a Single Variable
```cpp
int *ptr = new int; // Allocating memory
*ptr = 10; // Assigning value
cout << "Dynamically allocated value: " << *ptr << endl;
delete ptr; // Freeing memory
```

### ✅ Allocating a Dynamic Array
```cpp
int n;
cout << "Enter array size: ";
cin >> n;

int *arr = new int[n]; // Allocating array dynamically

// Assigning values
for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
}

// Printing values
cout << "Array elements: ";
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}

// Deallocate memory
delete[] arr;
```

---

## 🔹 Memory Deallocation (Releasing Heap Memory)
Dynamically allocated memory must be manually released using:
- `delete` for a **single variable**.
- `delete[]` for a **dynamically allocated array**.

### ✅ Example: Correct memory deletion
```cpp
int *ptr = new int(10);
delete ptr; // Freeing memory

int *arr = new int[5];
delete[] arr; // Freeing array memory
```

---

## 🔹 Common Mistakes in Memory Management
❌ **Forgetting to use `delete`** → leads to **memory leaks**.
❌ **Using `delete` on an uninitialized pointer** → undefined behavior.
❌ **Using `delete[]` for a single variable** → causes errors.

---

## 🔹 Debugging Memory Allocation
### ✅ Common Debugging Techniques
1. **Check for memory leaks** using **Valgrind** or sanitizers (`g++ -fsanitize=address`).
2. **Check for uninitialized pointers**.
3. **Use Smart Pointers (`std::unique_ptr`, `std::shared_ptr`)**.

### ✅ Example: Using `std::unique_ptr`
```cpp
#include <iostream>
#include <memory> // Include smart pointers

int main() {
    unique_ptr<int> ptr(new int(5));
    cout << "Value: " << *ptr << endl;
    return 0; // Memory is automatically deallocated
}
```

---

## 🔹 Key Takeaways
✔ **Static memory allocation is simpler but less flexible.**  
✔ **Dynamic memory allocation provides flexibility but requires manual deallocation.**  
✔ **Use `delete` and `delete[]` properly to avoid memory leaks.**  
✔ **Heap memory is manually managed, while stack memory is automatic.**  
✔ **Use smart pointers (`unique_ptr`, `shared_ptr`) to avoid manual deletion.**  

---

