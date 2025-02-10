Here are your **Day 8** notes on **Binary Search in a 2D Array & Searching in a Sorted Row-Column Matrix**, with detailed explanations and code snippets. 🚀  

---

# **Day 8: Binary Search in 2D Arrays & Searching in Sorted Matrices**  

## **1️⃣ Binary Search in a 2D Matrix**  
### **Problem Statement**  
Given an `n x m` matrix where:  
1. Each row is **sorted in ascending order**.  
2. The first integer of each row is **greater than the last integer of the previous row**.  

We need to find a **target element** efficiently.  

### **Approach: Applying Binary Search in a 1D Mapped Index**  
- Instead of treating the matrix as a **2D grid**, consider it as a **1D array** with indices ranging from `0` to `n*m-1`.  
- **Formula to map 1D index to 2D coordinates**:  
  - `row_index = mid / m`
  - `col_index = mid % m`
- **Binary search logic**:  
  - If `matrix[row_index][col_index] == target`, return `true`.  
  - If `matrix[row_index][col_index] > target`, move **left (end = mid - 1)**.  
  - If `matrix[row_index][col_index] < target`, move **right (start = mid + 1)**.  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0, end = n * m - 1, mid, row_index, col_index;

    // Binary Search
    while (start <= end) {
        mid = (start + end) / 2;
        row_index = mid / m;
        col_index = mid % m;

        if (matrix[row_index][col_index] == target)
            return true;
        else if (matrix[row_index][col_index] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}

// Driver Code
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (searchMatrix(matrix, target))
        cout << "Element found!" << endl;
    else
        cout << "Element not found!" << endl;
}
```
### **Time Complexity:**  
- **O(log(N * M))** → Since we perform **binary search** on a **flattened array** of `N*M` elements.  
- **Space Complexity: O(1)** → No extra space used.  

---

## **2️⃣ Search in a Sorted Row-Column Matrix**  
### **Problem Statement**  
Given an `n x m` matrix where:  
1. Each **row is sorted in ascending order**.  
2. Each **column is sorted in ascending order**.  

Find if a **target element** exists efficiently.  

### **Approach: Start from the Top-Right Corner**  
- Since **rows and columns** are **sorted**:
  - If we start at the **top-right corner (`mat[0][m-1]`)**:
    - If `mat[i][j] == target`, return `true`.
    - If `mat[i][j] < target`, move **down** (increase `i`).
    - If `mat[i][j] > target`, move **left** (decrease `j`).  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool searchSortedMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m - 1; // Start from top-right corner

    while (i < n && j >= 0) {
        if (mat[i][j] == x)
            return true;
        else if (mat[i][j] < x)
            i++; // Move down
        else
            j--; // Move left
    }

    return false;
}

// Driver Code
int main() {
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;

    if (searchSortedMatrix(mat, target))
        cout << "Element found!" << endl;
    else
        cout << "Element not found!" << endl;
}
```
### **Time Complexity:**  
- **O(N + M)** → We either move **down** (`N` steps) or **left** (`M` steps) in the worst case.  
- **Space Complexity: O(1)** → No extra space used.  

---

## **Summary of Day 8**  
| **Problem**                              | **Approach**                                      | **Time Complexity** |
|------------------------------------------|--------------------------------------------------|--------------------|
| **Binary Search in 2D Matrix**            | Treat the matrix as **1D**, apply **binary search** | O(log(N * M)) |
| **Search in Row-Column Sorted Matrix**    | **Start at top-right**, move **left/down**        | O(N + M) |

---

This concludes **Day 8** on **Binary Search in 2D Arrays & Searching in Sorted Matrices**! 🚀  
