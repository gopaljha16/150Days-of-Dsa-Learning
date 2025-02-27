# Day 24: Memory Allocation in 2D & 3D Arrays

## 📌 Understanding Dynamic Memory Allocation in Multi-Dimensional Arrays
In this section, we will explore how to allocate memory dynamically for **2D and 3D arrays** using pointers.

---

## 🔹 Dynamic Allocation of a 2D Array
### ✅ Steps to Allocate a 2D Array
1. **Create an array of pointers** to store row addresses.
2. **Allocate memory for each row dynamically.**
3. **Assign values and access elements dynamically.**
4. **Deallocate memory to prevent leaks.**

### ✅ Example: Dynamic 2D Array Allocation
```cpp
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    // Step 1: Create an array of pointers
    int **ptr = new int*[n];

    // Step 2: Allocate memory for each row
    for(int i = 0; i < n; i++){
        ptr[i] = new int[m];
    }

    // Step 3: Assigning values
    cout << "Enter values for the 2D array: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ptr[i][j];
        }
    }

    // Step 4: Printing the array
    cout << "The values in the 2D array are: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    // Step 5: Deallocate memory
    for(int i = 0; i < n; i++){
        delete[] ptr[i];
    }
    delete[] ptr;
    return 0;
}
```

### 🔍 Explanation:
- `new int*[n]`: Allocates memory for `n` rows.
- `new int[m]`: Allocates memory for `m` columns in each row.
- `delete[] ptr[i]`: Frees each row.
- `delete[] ptr`: Frees the array of pointers.

---

## 🔹 Dynamic Allocation of a 3D Array
### ✅ Steps to Allocate a 3D Array
1. **Create a pointer to a pointer to a pointer (`int ***ptr`).**
2. **Allocate memory for each 2D array (L layers).**
3. **Allocate memory for each row in each layer.**
4. **Allocate memory for each column in each row.**
5. **Assign values, print, and deallocate memory.**

### ✅ Example: Dynamic 3D Array Allocation
```cpp
#include <iostream>
using namespace std;

int main(){
    int L, B, H;
    cout << "Enter dimensions (L B H): ";
    cin >> L >> B >> H;

    // Step 1: Create an array of pointers to pointers
    int ***ptr = new int**[L];

    // Step 2: Allocate memory for each 2D array
    for(int i = 0; i < L; i++){
        ptr[i] = new int*[B];
        for(int j = 0; j < B; j++){
            ptr[i][j] = new int[H];
        }
    }

    // Step 3: Assign values
    for(int i = 0; i < L; i++){
        for(int j = 0; j < B; j++){
            for(int k = 0; k < H; k++){
                ptr[i][j][k] = i + j + k;
            }
        }
    }

    // Step 4: Print the values
    cout << "The 3D array values are: " << endl;
    for(int i = 0; i < L; i++){
        for(int j = 0; j < B; j++){
            for(int k = 0; k < H; k++){
                cout << ptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Step 5: Deallocate memory
    for(int i = 0; i < L; i++){
        for(int j = 0; j < B; j++){
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;

    return 0;
}
```

### 🔍 Explanation:
- `new int**[L]`: Creates an array of pointers to store addresses of 2D arrays.
- `new int*[B]`: Creates an array of pointers for rows.
- `new int[H]`: Allocates memory for columns.
- `delete[] ptr[i][j]`: Deletes each row in each layer.
- `delete[] ptr[i]`: Deletes each 2D array.
- `delete[] ptr`: Deletes the 3D array.

---

## 🔹 Visual Representation
### **2D Array Allocation**
```
ptr → [ * ] → [1 2 3]
      [ * ] → [4 5 6]
      [ * ] → [7 8 9]
```

### **3D Array Allocation**
```
ptr → [ * ] → [ * ] → [1 2 3]
               [ * ] → [4 5 6]
      [ * ] → [ * ] → [7 8 9]
               [ * ] → [10 11 12]
```

---

## 🔹 Key Takeaways
✔ **2D arrays use `int** ptr`, while 3D arrays use `int*** ptr`.**  
✔ **Memory must be deallocated properly to prevent leaks.**  
✔ **Heap memory provides flexibility over static arrays.**  
✔ **Use `delete[]` carefully to free memory.**  
✔ **Always allocate memory in steps (layers → rows → columns).**  

---
