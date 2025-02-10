Here are your notes for **Day 6: 2D Arrays Interview Problems** covering **Wave Form, Spiral Form, and Transpose Matrix** with explanations and code snippets. 🚀  

---

# **Day 6: 2D Arrays Interview Problems**  

## **1️⃣ Wave Form Traversal**  
### **Concept**  
In a **Wave Form traversal**, we move column-wise:  
- For **even columns (0, 2, 4, ...)**, traverse **top to bottom**.  
- For **odd columns (1, 3, 5, ...)**, traverse **bottom to top**.  

### **Code Implementation**
```cpp
#include <iostream>
using namespace std;

void WaveForm(int arr[][4], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0) // Even column → Top to bottom
        {
            for (int i = 0; i < row; i++)
                cout << arr[i][j] << " ";
        }
        else // Odd column → Bottom to top
        {
            for (int i = row - 1; i >= 0; i--)
                cout << arr[i][j] << " ";
        }
    }
}

int main()
{
    int arr[3][4] = { {3, 4, 5, 6},
                      {8, 2, 3, 4},
                      {9, 3, 2, 1} };

    WaveForm(arr, 3, 4);
}
```
### **Time Complexity:**  
- **O(N*M)** where N = rows and M = columns.  

---

## **2️⃣ Spiral Form Traversal**  
### **Concept**  
In a **Spiral Order traversal**, we move layer by layer in the following sequence:  
1. **Left to Right** → First row  
2. **Top to Bottom** → Last column  
3. **Right to Left** → Last row  
4. **Bottom to Top** → First column  
5. Repeat for inner layers  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, bottom = row - 1;
    int left = 0, right = col - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // Traverse from right to left (if valid)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        // Traverse from bottom to top (if valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}
```
### **Time Complexity:**  
- **O(N*M)** where N = rows and M = columns.  

---

## **3️⃣ Transpose of a Matrix**  
### **Concept**  
The **Transpose of a Matrix** is obtained by swapping rows with columns.  
- The element at **(i, j) moves to (j, i)**.  

### **Code Implementation**
```cpp
#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>>& mat, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]); // Swap elements
        }
    }
}

// Driver Code
int main() {
    vector<vector<int>> mat = { {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9} };

    transpose(mat, 3);

    // Print the transposed matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
```
### **Time Complexity:**  
- **O(N²)** where N is the matrix size.  

---

## **Summary of Day 6**  
| **Problem**       | **Concept**                                    | **Time Complexity** |
|-------------------|----------------------------------------------|--------------------|
| **Wave Form**     | Traverse matrix in wave pattern (column-wise) | O(N*M) |
| **Spiral Form**   | Traverse matrix in a spiral order (layer-wise) | O(N*M) |
| **Transpose**     | Convert row elements into column elements | O(N²) |

---

This wraps up **Day 6** on **2D Array Interview Problems**! 🚀  
