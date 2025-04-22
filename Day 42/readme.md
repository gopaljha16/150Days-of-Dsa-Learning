# Day 42: Recursion - Rat in a Maze Problem (GFG Medium)

## 🔄 Problem Statement:
Given a square matrix **`mat[n][n]`** where `1` represents a valid cell and `0` represents a blocked cell, the rat starts at **(0,0)** and needs to reach **(n-1,n-1)**. It can move **Up, Down, Left, Right (UDLR)**.

Return all paths in **lexicographic order**.

---

## ✨ Approach Summary:
This is a classic **Backtracking** + **DFS** recursion problem:
- At every cell, try 4 directions (U, D, L, R)
- Mark cells as visited while exploring
- Backtrack when needed (unmark the cell and remove the last move from the path)

---

## ✅ Code:
```cpp
class Solution {
  public:
    int row[4] = {-1, 1, 0, 0};  // U, D, L, R rows
    int col[4] = {0, 0, -1, 1};  // U, D, L, R cols
    string dir = "UDLR";

    // Utility function to check boundaries
    bool valid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    // Recursive function to explore all paths
    void Total(vector<vector<int>>& matrix, int i, int j, int n, string &path,
               vector<string>& ans, vector<vector<bool>>& visited) {

        // Base case: destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[i][j] = 1; // Mark as visited

        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];

            // Valid and unvisited path
            if (valid(ni, nj, n) && matrix[ni][nj] && !visited[ni][nj]) {
                path.push_back(dir[k]);
                Total(matrix, ni, nj, n, path, ans, visited);
                path.pop_back(); // Backtrack
            }
        }

        visited[i][j] = 0; // Backtrack unvisit
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        vector<string> ans;
        string path;

        // Edge case: start or end blocked
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
            return ans;

        Total(mat, 0, 0, n, path, ans, visited);
        return ans;
    }
};
```

---

## 🧠 Code Explanation:

### `valid(i, j, n)`
Checks if the index is within the grid bounds.

### `Total(...)`
This is the recursive function that:
- Marks the cell as visited.
- Tries all 4 directions in `UDLR` using `row[]`, `col[]`, and `dir[]` arrays.
- For each valid direction, appends that direction to `path`, and recurses.
- After recursion, **backtracks** by removing the last direction and unmarking the cell.

### `findPath(...)`
- Prepares visited matrix and initial path.
- Edge case: if start or end is 0, return empty answer.
- Calls recursive function `Total`.

---

## 🔢 Example
```cpp
mat = [
 [1, 0, 0],
 [1, 1, 0],
 [0, 1, 1]
]
```

### Output:
```cpp
["DDRDR", "DRDDR"]
```

### Dry Run:
```
Start at (0,0)
- Move Down to (1,0) -> path = "D"
  - Move Down to (2,0) -> blocked
  - Move Right to (1,1) -> path = "DR"
    - Move Down to (2,1) -> path = "DRD"
      - Move Right to (2,2) -> path = "DRDR" ✅ Reached end
    - Backtrack
  - Backtrack
- Backtrack
```

---

## ⏲️ Time & Space Complexity:
### Time Complexity:
- Worst case: **`O(4^(n*n))`**, each cell has 4 directions to explore.
- With pruning (visited check), this is reduced in practice.

### Space Complexity:
- Recursion depth: **`O(n^2)`** in worst case
- Visited matrix: **`O(n^2)`**
- Path string: at most `2n` length -> negligible

---

## 🔄 Flowchart-style Steps:
```
Start -> Is (0,0) and (n-1,n-1) != 0? -> YES
  |
  v
Mark visited[0][0] = 1
  |
  v
Try all directions from (0,0)
  |
  v
If valid and not visited:
  - Append direction to path
  - Move to that cell
  - Recursively call
  - On return: pop direction, unmark visited
  |
  v
If reached (n-1,n-1) -> store path
```


Here's the **time and space complexity analysis** for the **"Rat in a Maze"** problem (Day 42) with repetition not allowed:

---

### 🧠 **Time Complexity: `O(4^(n*n))` (Worst Case)**

#### 📌 Why 4^(n*n)?
- For each cell `(i, j)`, there are **4 possible directions** to move (U, D, L, R).
- In the **worst case**, the rat can visit every cell once (if all are open `1`) and try all 4 directions.
- So for an **n x n grid**, the number of **function calls** in worst case is `4^(n^2)`.

> ⚠️ This is **exponential** due to branching factor `4` at each of the `n^2` positions.

---

### 🧠 **Space Complexity: `O(n^2)`**

#### Breakdown:
- **Visited matrix**: `O(n^2)` for marking visited cells.
- **Recursive call stack**: Maximum recursion depth is `O(n^2)` if the path is very long (grid with all 1s and deep DFS).
- **Path string**: In the worst case, it can be of length `2n` (if path goes diagonally in square grid).
- **Answer vector**: Depends on the number of valid paths; in worst case it could store all valid paths.

---

### 💡 Final Complexities:

| Component              | Complexity        |
|------------------------|-------------------|
| **Time Complexity**     | `O(4^(n^2))`      |
| **Space Complexity**    | `O(n^2)`          |

---

Would you like me to add this analysis into your GitHub-style notes directly as well?
---
