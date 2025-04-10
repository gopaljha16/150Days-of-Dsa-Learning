Here are the detailed notes for **Day 34: Quick Sort Algorithm** with full explanation, recursive tree, flowcharts, and time/space complexity:

---

# 📘 Day 34: Quick Sort Algorithm

---

## 🔥 What is Quick Sort?

Quick Sort is a **divide-and-conquer** algorithm.  
It selects a **pivot element** and partitions the array such that:
- Elements less than or equal to pivot → left side
- Elements greater than pivot → right side  
Then it recursively sorts the left and right subarrays.

---

## 🧠 Partition Logic Explained

### 🔧 Code:
```cpp
int Partition(int arr[] , int start , int end){
    int pos = start;
    for(int i = start; i <= end; i++){
        if(arr[i] <= arr[end]){ // end is pivot
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos - 1; // final position of pivot
}
```

### 📝 Explanation:
- `arr[end]` is considered as pivot.
- Traverse from `start` to `end`:
  - If element ≤ pivot → swap with element at `pos`, then increment `pos`.
- After loop, `pos-1` is the index where pivot is finally placed correctly.

---

## 🔁 Recursive Quick Sort

```cpp
void QuickSort(int arr[], int start, int end){
    if(start >= end) return; // base case

    int pivot = Partition(arr, start, end); // partition the array
    QuickSort(arr, start, pivot - 1); // left side
    QuickSort(arr, pivot + 1, end);   // right side
}
```

---

## 🧩 Flowchart of Quick Sort Process

```plaintext
               QuickSort(arr, 0, n-1)
                      |
                 Partition (pivot at end)
                  /               \
      QuickSort(left)       QuickSort(right)
         |                         |
   Partition(left)           Partition(right)
       ...                        ...
```

---

## 🌲 Recursive Tree Example

Let’s take: `arr = [6, 2, 5, 2, 7, 4, 1, 3]`

### Step-by-step Tree

```
QuickSort(0, 7) - pivot = 3
[2 2 1] 3 [6 5 7 4]

Left: QuickSort(0, 2) - pivot = 1
[1] 2 2

Right: QuickSort(4, 7) - pivot = 4
[3] 4 [5 7 6]
```

Then recurse again on smaller subarrays until base condition (`start >= end`) is met.

---

## ⏱️ Time Complexity

| Case | Explanation | Time |
|------|-------------|------|
| **Best** | Pivot divides array evenly | O(n log n) |
| **Average** | Random pivots | O(n log n) |
| **Worst** | Pivot is smallest/largest element (like sorted array) | O(n²) |

> **Note**: Worst case can be avoided using **randomized pivot selection**.

---

## 💾 Space Complexity

- **O(log n)** in the best and average case due to recursion stack.
- **O(n)** in the worst case (if recursion goes deep, like left-skewed or right-skewed).

✅ *Quick Sort is an in-place sort*, so no extra arrays are used.

---

## ✅ Output Example:

For `arr = {6, 2, 5, 2, 7, 4, 1, 3}`  
**Sorted Output:**
```
1 2 2 3 4 5 6 7
```

---

## 💡 Key Points

- Efficient for large datasets.
- Not stable (doesn't preserve order of equal elements).
- Can be optimized with random pivot or median-of-three.

---

