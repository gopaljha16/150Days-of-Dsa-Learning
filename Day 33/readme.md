Great! Here's your detailed **Day 33: Merge Sort in Recursion** 📘 with full explanations, code walkthrough, recursive tree, flowchart-style breakdown, and time/space complexity.

---

# 📅 Day 33 - Merge Sort using Recursion

## ✅ What is Merge Sort?

**Merge Sort** is a **Divide and Conquer** algorithm that:
- Divides the array into two halves.
- Recursively sorts them.
- Merges the sorted halves into one sorted array.

---

## 🧠 Step-by-Step Code Explanation

### 🔹 `MergeSort` Function - Dividing Phase
```cpp
void MergeSort(int arr[] , int start , int end){
    if(start == end) return; // base case: one element

    int mid = start + (end - start)/2;

    MergeSort(arr , start , mid);     // left half
    MergeSort(arr , mid + 1 , end);   // right half
    Merge(arr , start , mid , end);   // merge sorted halves
}
```

- Recursively divides the array into subarrays until one element.
- Calls `Merge()` to sort and combine.

---

### 🔹 `Merge` Function - Merging Phase
```cpp
void Merge(int arr[] , int start , int mid , int end){
    vector<int> temp(end - start + 1);
    int index = 0, left = start, right = mid + 1;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp[index++] = arr[left++];
        } else {
            temp[index++] = arr[right++];
        }
    }

    // Copy remaining elements
    while(left <= mid) temp[index++] = arr[left++];
    while(right <= end) temp[index++] = arr[right++];

    // Copy back to original array
    for(int i = 0; i < temp.size(); i++) arr[start + i] = temp[i];
}
```

- Compares elements from both halves.
- Puts the smaller one into a temporary array.
- Merges them back into the original array in sorted order.

---

## 🔁 Recursion Tree

For input: `[9, 10, 22, 4, 1, 6, 7, 11, 2, 3]`

```
MergeSort(0, 9)
├── MergeSort(0, 4)
│   ├── MergeSort(0, 2)
│   │   ├── MergeSort(0,1)
│   │   │   ├── MergeSort(0,0) ✅
│   │   │   └── MergeSort(1,1) ✅
│   │   │   └── Merge(0,0,1)
│   │   └── MergeSort(2,2) ✅
│   │   └── Merge(0,1,2)
│   └── MergeSort(3,4)
│       ├── MergeSort(3,3) ✅
│       └── MergeSort(4,4) ✅
│       └── Merge(3,3,4)
│   └── Merge(0,2,4)
└── MergeSort(5, 9)
    ├── MergeSort(5, 7)
    │   ├── MergeSort(5,6)
    │   │   ├── MergeSort(5,5) ✅
    │   │   └── MergeSort(6,6) ✅
    │   │   └── Merge(5,5,6)
    │   └── MergeSort(7,7) ✅
    │   └── Merge(5,6,7)
    └── MergeSort(8,9)
        ├── MergeSort(8,8) ✅
        └── MergeSort(9,9) ✅
        └── Merge(8,8,9)
    └── Merge(5,7,9)
└── Merge(0,4,9)
```

✅ = Base Case

---

## 🔄 Flowchart of Merge Sort

```
       MergeSort(0, 9)
         /         \
   MergeSort     MergeSort
   (0,4)           (5,9)
   /   \            /   \
...     ...      ...    ...
        \________/       ← Merges recursively
            ↓
        Final Sorted Array
```

---

## ⏱️ Time Complexity Analysis

| Step               | Cost                    |
|--------------------|--------------------------|
| Divide             | `O(log n)`               |
| Merge (combine)    | `O(n)` at each level     |
| Total Time         | `O(n log n)`             |

- The array is divided `log n` times.
- Each level merges all `n` elements → total `O(n log n)`.

---

## 📦 Space Complexity

- `O(n)` auxiliary space for the temporary vector.
- Stack space (recursive calls): `O(log n)`.

**Total: `O(n + log n)` ≈ `O(n)`**

---

## 📌 Example Walkthrough

Input: `[9, 10, 22, 4]`

1. Split → `[9,10]` and `[22,4]`
2. Split → `[9]` `[10]` and `[22]` `[4]`
3. Merge → `[9,10]` and `[4,22]`
4. Merge → `[4,9,10,22]`

---

## 🧪 Dry Run

```cpp
arr[] = {9, 10, 22, 4}

Step 1: Divide → [9,10] | [22,4]
Step 2: Merge [9,10] → sorted
Step 3: Merge [4,22] → sorted
Step 4: Merge [9,10] + [4,22] → [4,9,10,22]
```

---

## ✅ Summary

| Concept           | Description |
|-------------------|-------------|
| Type              | Divide and Conquer |
| Time Complexity   | `O(n log n)` |
| Space Complexity  | `O(n)` (temp array) |
| Stable Sort       | ✅ Yes |
| In-place Sort     | ❌ No (uses extra space) |
| Recursive Tree    | Shows how subarrays split & merge |

---

