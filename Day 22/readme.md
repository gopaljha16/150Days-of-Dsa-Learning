# Day 22: Double Pointers, Multiple Pointers, and Problems

## Introduction to Double Pointers
A **double pointer** is a pointer that stores the address of another pointer. This concept extends to **triple pointers** and beyond, creating multiple levels of indirection.

### Understanding Pointer Levels
- **Single Pointer (`int *p`)** → Points to an integer value.
- **Double Pointer (`int **p1`)** → Points to a pointer (`p`), which in turn points to an integer.
- **Triple Pointer (`int ***p2`)** → Points to a double pointer (`p1`), which points to a pointer (`p`), which points to an integer.
- **Quadruple Pointer (`int ****p3`)** → Extends the concept further.

```cpp
#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int *p = &n;   // Single Pointer - Points to 'n'
    int **p1 = &p; // Double Pointer - Points to 'p'
    int ***p2 = &p1; // Triple Pointer - Points to 'p1'
    int ****p3 = &p2; // Quadruple Pointer - Points to 'p2'
    
    // Modifying Value using Different Levels of Pointers
    *p = *p +5;   // Single Pointer
    cout<<n<<endl; // Output: 15

    **p1 = **p1 + 5; // Double Pointer
    cout<<n<<endl; // Output: 20

    ***p2 = ***p2 + 5; // Triple Pointer
    cout<<n<<endl; // Output: 25

    ****p3 = ****p3 + 5; // Quadruple Pointer
    cout<<n<<endl; // Output: 30
}
```

## Modifying Pointer Address using Double Pointer
A double pointer can also modify the address stored in a pointer.

```cpp
#include <iostream>
using namespace std;

void fun(int **p1){
    *p1 = *p1 + 1; // Moves pointer by 1 unit (4 bytes in case of int)
}

int main(){
    int n = 10;
    int *p = &n;
    int **ptr = &p;
    fun(ptr);
    cout<<ptr; // Address will be incremented
}
```
### Explanation:
- Initially, `ptr` stores the address of `p`.
- `fun(ptr)` modifies `p` by incrementing its address.
- If `p` was at 100, after incrementing by 4 (size of `int`), it moves to 104.

---

## Pointer-based Problem Solving

### 1. Pointer Manipulation
```cpp
#include <iostream>
using namespace std;

void second(int *p1 , int *p2){
    p1 = p2; // Assign p1 to p2
    *p2 = 2;
}

int main(){
    int i = 0, j = 1;
    second(&i, &j);
    cout << i << " " << j; // Output: 0 2
}
```

### 2. Pointer Dereferencing
```cpp
int *ptr;
int x = 0;
ptr = &x;
int y = *ptr;
*ptr = 1;
cout << x << " " << y; // Output: 1 0
```

### 3. Reference vs Pointer
```cpp
int a = 5, b = 10;
int &name = a;
int *ptr = &a;
(*ptr)++;
ptr = &b;
*ptr = *ptr + 5;
name += 5;
cout << a << " " << b; // Output: 11 15
```

### 4. Multi-level Pointer Function
```cpp
int fifth(int x, int *py, int **ppz){
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

int main(){
    int c, *b, **a;
    c = 4, b = &c, a = &b;
    cout << fifth(c, b, a); // Output: 19
}
```

### 5. String Copy Using Pointers
```cpp
void sixth(char *str1, char *str2){
    while((*str1 = *str2)){
        str1++, str2++;
    }
}

int main(){
    char first[] = "Rohit";
    char second[] = "Gopal";
    sixth(first, second);
    cout << first; // Output: Gopal
}
```

---

## Key Takeaways
1. **Double Pointers**: Store addresses of other pointers and allow multi-level memory access.
2. **Triple & Quadruple Pointers**: Extend the indirection further for complex memory manipulations.
3. **Pointer Arithmetic**: Incrementing a pointer moves it based on data type size (e.g., `int*` moves by 4 bytes).
4. **Pointer Address Modification**: Using a double pointer, we can modify the address stored in a pointer.
5. **String Copy via Pointers**: Instead of `strcpy()`, pointer-based iteration can be used for copying.
6. **Reference vs Pointer**: References remain fixed, while pointers can be reassigned.

