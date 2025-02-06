# Day 5: Introduction to 2D Arrays 🚀

## Overview
Today, I learned about **2D Arrays** in C++. A 2D array is a collection of elements arranged in rows and columns. It allows efficient storage and retrieval of data in a tabular format. Below are the topics covered along with explanations and corresponding C++ implementations.

---

## 1️⃣ Creating and Initializing a 2D Array

A **2D array** is defined using two indices (rows and columns). We can initialize it in multiple ways.

### Code:
```cpp
#include <iostream>
using namespace std;

int main(){
    // Defining a 4x3 matrix
    int arr[4][3]  = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    // Printing the matrix
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
```

---

## 2️⃣ Addition of Two Matrices

Matrix addition is possible only when both matrices have the same dimensions. We simply **add corresponding elements** from both matrices.

### Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 25};
    int ans[3][4];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            ans[i][j] = arr1[i][j] + arr2[i][j];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
}
```

---

## 3️⃣ Column-Wise Printing

Instead of printing row-wise, we can print **column-wise** by fixing a column and iterating over rows.

### Code:
```cpp
#include <iostream>
using namespace std;

void PrintCol(int arr[][4], int row, int col){
    for(int j = 0; j < col; j++){
        for(int i = 0; i < row; i++){
            cout << arr[i][j] << " ";
        }
    }
}

int main(){
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    cout << "Column-wise printing:\n";
    PrintCol(arr, 4, 4);
}
```

---

## 4️⃣ Finding Row with Maximum Sum

We iterate through each row, calculate its sum, and update the maximum sum row index.

### Code:
```cpp
#include <iostream>
using namespace std;

int main(){
    int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int maxSum = INT_MIN, index = -1;
    
    for(int i = 0; i < 4; i++){
        int total = 0;
        for(int j = 0; j < 4; j++){
            total += arr[i][j];
        }
        if(total > maxSum){
            maxSum = total;
            index = i;
        }
    }
    cout << "Row with maximum sum: " << index;
}
```

---

## 5️⃣ Reversing Each Row in a Matrix

Using two-pointer technique, we **swap elements from start and end** to reverse each row.

### Code:
```cpp
#include <iostream>
using namespace std;

void ReverseEachRow(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        int start = 0, end = col - 1;
        while(start < end){
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}

int main(){
    int arr[3][4] = {2,3,4,5,1,2,6,8,4,9,3,2};
    ReverseEachRow(arr, 3, 4);
}
```

---

## 6️⃣ Finding the Sum of Diagonal Elements

A diagonal sum is only possible when **rows = columns**.

### Code:
```cpp
#include <iostream>
using namespace std;

void PrintDiagonal(int arr[][3], int row, int col){
    int first = 0, second = 0;
    for(int i = 0; i < row; i++)
        first += arr[i][i];
    
    for(int i = 0, j = col - 1; j >= 0; i++, j--)
        second += arr[i][j];
    
    cout << "First diagonal sum: " << first << endl;
    cout << "Second diagonal sum: " << second << endl;
    cout << "Total diagonal sum (excluding double-counted middle element): " << first + second - arr[row/2][col/2];
}

int main(){
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    PrintDiagonal(arr, 3, 3);
}
```

---

## Homework Problems ✅

### 1️⃣ Column Sum
Find the sum of each column in a matrix.

### 2️⃣ Matrix Subtraction
Given two matrices **A and B**, print **A - B**.

### 3️⃣ Find Largest and Smallest Element in a Matrix
Determine the **maximum and minimum element** present in the matrix.

---

## Summary 📝
- **2D Arrays** store elements in **rows & columns**.
- **Matrix addition & subtraction** require equal dimensions.
- **Column-wise traversal** is done by fixing a column and iterating over rows.
- **Finding max sum row** helps in analyzing data patterns.
- **Reversing rows** swaps elements within each row.
- **Diagonal sum** includes both primary and secondary diagonals.
- **Homework problems** reinforce concepts and improve logic.

---

