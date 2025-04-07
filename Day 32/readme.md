Great! Here's your **Day 32: Time and Space Complexity in Recursion** notes with full explanations, recursive trees, stack visualization, and T.C/S.C analysis.

---

# 🧠 Day 32: Time and Space Complexity in Recursion

---

## 📌 1. Print Numbers from `n` to `1`

```cpp
void print(int n) {
    if(n == 0) return;
    cout << n << " ";
    print(n - 1);
}
```

### 🔁 Recursive Tree for `print(3)`
```
print(3)
 |
 --> 3 → print(2)
           |
           --> 2 → print(1)
                     |
                     --> 1 → print(0)
                               |
                               --> return
```

### 🧮 Time & Space Complexity:
- **Time Complexity**: O(n) — One call per value from `n` to 1.
- **Space Complexity**: O(n) — `n` calls on the call stack.

---

## 📌 2. Print Array Elements Recursively

```cpp
int printArray(int arr[], int index, int n) {
    if(index == n) return 0;
    cout << arr[index] << " ";
    return printArray(arr, index + 1, n);
}
```

### 🔁 Recursive Tree for `arr = [1, 2, 3], index = 0`
```
printArray(0)
 |
 --> print 1 → printArray(1)
                 |
                 --> print 2 → printArray(2)
                                 |
                                 --> print 3 → printArray(3)
                                                 |
                                                 --> return
```

### 🧮 T.C & S.C:
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

---

## 📌 3. Sum of Array Elements (Passing Vector by Value)

```cpp
int sum(vector<int> v) {
    if(v.size() == 0) return 0;
    int last = v.back();
    v.pop_back(); // creates copy due to pass by value
    return last + sum(v);
}
```

### 🔁 Recursive Tree for `v = [1,2,3]`
```
sum([1,2,3]) → 3 + sum([1,2])
               → 2 + sum([1])
                     → 1 + sum([])
                            → 0
```

### 🧮 T.C & S.C:
- **Time Complexity**: O(n)
- **Space Complexity**: O(n^2)
  - Because at each level, a **copy** of the vector is created (O(n) for each call × n levels)

---

## 📌 4. Binary Search Recursively

```cpp
bool BinarySearch(int arr[], int start, int end, int x) {
    if(start > end) return false;
    int mid = start + (end - start) / 2;

    if(arr[mid] == x) return true;
    else if(arr[mid] > x) return BinarySearch(arr, start, mid-1, x);
    else return BinarySearch(arr, mid+1, end, x);
}
```

### 🔁 Recursive Tree for `arr = [3,8,11,15,20,22], x = 15`
```
BinarySearch(0,5)
 |
 → mid = 2 → arr[2]=11 → x > 11 → BinarySearch(3,5)
                      |
                      → mid = 4 → arr[4]=20 → x < 20 → BinarySearch(3,3)
                                                       |
                                                       → mid = 3 → arr[3]=15 ✔️
```

### 🧮 T.C & S.C:
- **Time Complexity**: O(log n) — Array is halved in every call
- **Space Complexity**: O(log n) — Recursive call stack height

---

## 📌 5. Fibonacci Number Recursively

```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

### 🔁 Recursive Tree for `fib(4)`
```
fib(4)
 |
 --> fib(3) + fib(2)
       |         |
    fib(2)+fib(1)  fib(1)+fib(0)
     |     |          |     |
  fib(1)+fib(0)      1       0
   |     |
   1     0
```

### 🧮 T.C & S.C:
- **Time Complexity**: O(2^n) — Each call spawns two more
- **Space Complexity**: O(n) — Stack height = n (deepest branch)

---

## 🧠 Summary Table:

| Problem                    | Time Complexity | Space Complexity | Notes |
|---------------------------|------------------|------------------|-------|
| Print n to 1              | O(n)             | O(n)             | Simple linear recursion |
| Print Array               | O(n)             | O(n)             | One call per element |
| Sum with Vector by Value  | O(n)             | O(n²)            | Each call copies vector |
| Binary Search Recursively | O(log n)         | O(log n)         | Halving array |
| Fibonacci Recursion       | O(2ⁿ)            | O(n)             | Exponential calls |

---

