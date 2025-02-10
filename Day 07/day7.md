Here are your **Day 7** notes on **Matrix Rotation Problems**, including **Rotate by 90°, Rotate by 180°, and Rotate Matrix Element Clockwise**, with detailed explanations and code snippets. 🚀  

---

# **Day 7: Rotate Image & Matrix Rotation Problems**  

## **1️⃣ Rotate a Matrix by 90°**  
### **Concept**  
To rotate a matrix **90 degrees clockwise**, we follow these steps:  
1. **Transpose the matrix** → Convert rows into columns.  
2. **Reverse each row** → Swap elements from left to right.  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotateby90(vector<vector<int>>& mat) {
    int n = mat.size();
    
    // Step 1: Transpose the matrix
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while (start < end) {
            swap(mat[i][start], mat[i][end]);
            start++;
            end--;
        }
    }
}

// Function to print the matrix
void printMatrix(vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Driver Code
int main() {
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    
    rotateby90(mat);
    printMatrix(mat);
}
```
### **Time Complexity:**  
- **O(N²)** due to matrix traversal.  

---

## **2️⃣ Rotate a Matrix by 180°**  
### **Concept**  
To rotate a matrix **180 degrees**, we can follow two approaches:  
1. **Apply 90° rotation twice.**  
2. **Reverse rows and then reverse columns.**  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix180(vector<vector<int>>& mat) {
    int n = mat.size();
    
    // Step 1: Reverse columns
    for (int j = 0; j < n; j++) {
        int start = 0, end = n - 1;
        while (start < end) {
            swap(mat[start][j], mat[end][j]);
            start++;
            end--;
        }
    }

    // Step 2: Reverse rows
    for (int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while (start < end) {
            swap(mat[i][start], mat[i][end]);
            start++;
            end--;
        }
    }
}

// Function to print the matrix
void printMatrix(vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Driver Code
int main() {
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    
    rotateMatrix180(mat);
    printMatrix(mat);
}
```
### **Time Complexity:**  
- **O(N²)** for both column and row reversal.  

---

## **3️⃣ Rotate a Matrix k Times by 90° (Dynamic Rotation)**  
### **Concept**  
If we need to rotate a matrix **k times** by 90°, we use modulo arithmetic:  
- Since 4 rotations (90° × 4 = 360°) bring the matrix back to its original form, we do `k = k % 4`.  
- Apply **Rotate by 90°** method `k` times.  

### **Code Implementation**
```cpp
#include <iostream>
using namespace std;

void Rotate90(int mat[][4], int row, int col) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < row; i++) {
        int start = 0, end = col - 1;
        while (start < end) {
            swap(mat[i][start], mat[i][end]);
            start++;
            end--;
        }
    }
}

// Function to print the matrix
void printMatrix(int mat[][4], int row, int col) {
    cout << "Final Rotated Matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Driver Code
int main() {
    int k;
    cout << "Enter the number of 90° rotations: ";
    cin >> k;

    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    k = k % 4; // Optimize unnecessary full rotations
    while (k--) {
        Rotate90(mat, 4, 4);
    }

    printMatrix(mat, 4, 4);
}
```
### **Time Complexity:**  
- **O(N²) for each rotation**, so **O(K * N²)** in the worst case.  

---

## **Summary of Day 7**  
| **Problem**       | **Concept**                                      | **Time Complexity** |
|-------------------|--------------------------------------------------|--------------------|
| **Rotate by 90°**  | Transpose + Row-wise Reverse                    | O(N²) |
| **Rotate by 180°** | Reverse columns + Reverse rows                   | O(N²) |
| **Rotate k times** | Apply Rotate by 90° method k times (mod 4)       | O(K * N²) |

---

This concludes **Day 7** on **Matrix Rotation Problems**! 🚀  
