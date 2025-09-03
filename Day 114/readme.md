# Graph Algorithms - BFS Solutions Collection

## Overview

This collection contains three classic graph problems solved using **Breadth-First Search (BFS)** algorithm:

1. **Covid Spread (Helpaterp)** - Find minimum time for infection to spread
2. **Number of Islands** - Count connected land components  
3. **Replace O's with X's** - Capture regions surrounded by X's

All solutions use BFS traversal with directional arrays for efficient neighbor exploration in 2D grids.

---

## 1. Covid Spread Problem (Helpaterp)

### Problem Description
Given a hospital grid where:
- `0` = Empty cell
- `1` = Uninfected person
- `2` = Infected person (Covid patient)

Find the minimum time required for all people to get infected, or return -1 if impossible.

### Code Explanation

```cpp
class Solution {
  public:
  int r,c;
  int row[4] = {-1,1,0,0};    // Direction vectors for up, down, left, right
  int col[4] = {0,0,-1,1};
  
  bool valid(int i , int j){
      return i>=0&&i<r&&j>=0&&j<c;  // Boundary check
  }
  
    int helpaterp(vector<vector<int>> hospital) {
      
      r = hospital.size();     // Get grid dimensions
      c = hospital[0].size();
      
      queue<pair<int,int>>q;   // BFS queue to store coordinates
      
     // Step 1: Add all initially infected patients to queue
     for(int i=0 ; i<r ; i++)
      for(int j=0 ; j<c ; j++)
      if(hospital[i][j]==2)
        q.push(make_pair(i,j));
      
      int timer = 0;           // Time counter
      
      // Step 2: BFS level-by-level processing
      while(!q.empty()){
          timer++; 
          int curr_patient = q.size();  // Process all patients at current time
          
          while(curr_patient--){
              int i = q.front().first;
              int j = q.front().second;
              q.pop();
              
              // Step 3: Check all 4 directions
              for(int k=0 ; k<4 ; k++){
                  int ni = i+row[k], nj = j+col[k];
                  if(valid(ni, nj) && hospital[ni][nj] == 1){
                      hospital[ni][nj] = 2;      // Infect the person
                      q.push(make_pair(ni, nj)); // Add to queue
                  }
              }
          }
      }
      
      // Step 4: Check if anyone remains uninfected
       for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
         if(hospital[i][j]==1)
          return -1;
       
      if (timer == 0) return 0;  // No one to infect
      return timer-1;            // Subtract extra increment
    }
};
```

### Example Input & Output

**Input:**
```
hospital = [
  [2,1,0,2,1],
  [1,0,1,2,1],  
  [1,0,0,2,1]
]
```

**Expected Output:** `2`

### Step-by-Step Dry Run

**Initial State (Time 0):**
```
Grid:           Queue: [(0,0), (0,3), (1,3), (2,3)]
2 1 0 2 1       Timer: 0
1 0 1 2 1
1 0 0 2 1
```

**Time 1:**
- Process 4 infected patients
- Infect their uninfected neighbors
```
Grid:           Queue: [(0,1), (0,4), (1,0), (1,2), (1,4), (2,4)]
2 2 0 2 2       Timer: 1
2 0 2 2 2
1 0 0 2 2
```

**Time 2:**
- Process 6 newly infected patients
- Continue spreading infection
```
Grid:           Queue: [(2,0)]
2 2 0 2 2       Timer: 2
2 0 2 2 2
2 0 0 2 2
```

**Time 3:**
- Queue becomes empty after processing
- All infectable people are infected
- Return timer-1 = 2

### Visual Flow Diagram
```
Start → Add all initial infected → BFS by levels → Check uninfected → Return time
  ↓           ↓                      ↓               ↓              ↓
Grid     Queue:(2,2,..)        Level by level   Any 1 left?   timer-1
```

---

## 2. Number of Islands Problem

### Problem Description
Count the number of islands in a grid where:
- `'L'` = Land
- `'W'` = Water

Connected lands (8-directionally) form one island.

### Code Explanation

```cpp
class Solution {
  public:
  int r , c;
  // 8-directional movement (including diagonals)
  int row[8] = {-1,-1,-1,1,1,1,0,0};
  int col[8] = {-1,0,1,-1,0,1,-1,1};
  
  bool valid(int i , int j){
      return i>=0&&i<r&&j>=0&&j<c;
  }
  
    int countIslands(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        queue<pair<int , int>>q;
        int count = 0;
        
        // Step 1: Traverse each cell
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c; j++){
                
                if(grid[i][j]=='L'){
                    count++;              // Found new island
                    q.push(make_pair(i,j));
                    grid[i][j] = 'W';     // Mark as visited
                    
                   // Step 2: BFS to mark entire island
                   while(!q.empty()){
                       int new_i = q.front().first;
                       int new_j = q.front().second;
                       q.pop();
                       
                       // Check all 8 directions
                       for(int k=0 ; k<8 ;k++){
                           int ni = new_i+row[k], nj = new_j+col[k];
                           if(valid(ni, nj) && grid[ni][nj] == 'L'){
                                grid[ni][nj] = 'W';     // Mark visited
                                q.push(make_pair(ni, nj));
                           }
                       }
                   }
                }
            }
        }
        
        return count;
    }
};
```

### Example Input & Output

**Input:**
```
grid = [
  ['L','L','W','W','W'],
  ['L','L','W','W','W'],
  ['W','W','L','W','W'],
  ['W','W','W','L','L']
]
```

**Expected Output:** `3`

### Step-by-Step Dry Run

**Initial Grid:**
```
L L W W W
L L W W W  
W W L W W
W W W L L
```

**Step 1:** Find first 'L' at (0,0)
- count = 1
- BFS marks entire connected component:
```
W W W W W    ← Island 1 marked
W W W W W  
W W L W W
W W W L L
```

**Step 2:** Find next 'L' at (2,2)  
- count = 2
- BFS marks this single cell:
```
W W W W W    
W W W W W  
W W W W W    ← Island 2 marked
W W W L L
```

**Step 3:** Find next 'L' at (3,3)
- count = 3  
- BFS marks connected cells:
```
W W W W W    
W W W W W  
W W W W W
W W W W W    ← Island 3 marked
```

**Final count:** `3`

### 8-Direction Movement Diagram
```
(-1,-1) (-1,0) (-1,1)
( 0,-1)   X    ( 0,1)
( 1,-1) ( 1,0) ( 1,1)
```

---

## 3. Replace O's with X's Problem

### Problem Description
Replace all `'O'` with `'X'` that are completely surrounded by `'X'`. 
`'O'` on the border or connected to border `'O'` should remain unchanged.

### Code Explanation

```cpp
class Solution {
  public:
  int r , c;
  int row[4] = {-1 , 1 , 0 , 0};    // 4-directional movement
  int col[4] = {0 , 0 , -1 , 1};
 
  bool valid(int i , int j){
      return i>=0 && i<r && j>=0 && j<c;
  }

  vector<vector<char>> fill(vector<vector<char>>& mat) {
      int n = mat.size();
      int m = mat[0].size();
      
      r = n;
      c = m;
      
      queue<pair<int , int>> q;
      
      // Step 1: Mark all border O's as temporary 'T'
      // First row
      for(int j=0 ; j<c ; j++){
          if(mat[0][j]=='O'){
              q.push({0,j});
              mat[0][j] = 'T';
          }
      }
      
      // First column  
      for(int i=0 ; i<r ; i++){
          if(mat[i][0]=='O'){
              q.push({i,0});
              mat[i][0] = 'T';
          }
      }
      
      // Last row
      for(int j=0 ; j<c ; j++){
          if(mat[r-1][j]=='O'){
              q.push({r-1,j});
              mat[r-1][j] = 'T';
          }
      }
      
      // Last column
      for(int i=0 ; i<r ; i++){
          if(mat[i][c-1]=='O'){
              q.push({i,c-1});
              mat[i][c-1] = 'T';
          }
      }
      
      // Step 2: BFS to mark all connected O's as T
      while(!q.empty()){
          int i = q.front().first;
          int j = q.front().second;
          q.pop();
          
          for(int k=0 ; k<4 ; k++){
              int ni = i + row[k];
              int nj = j + col[k];
              
              if(valid(ni , nj) && mat[ni][nj]=='O'){
                  mat[ni][nj] ='T';
                  q.push({ni, nj});
              }
          }
      }
      
      // Step 3: Replace O with X (surrounded) and T with O (border-connected)
      for(int i=0  ; i<r ; i++){
          for(int j=0 ; j<c ; j++){
              if(mat[i][j]=='O')
                  mat[i][j]='X';        // Surrounded O becomes X
              else if(mat[i][j]=='T')
                  mat[i][j]='O';        // Border-connected remains O
          }
      }
      
      return mat;
  }
};
```

### Example Input & Output

**Input:**
```
mat = [
  ['X','X','X','X'],
  ['X','O','O','X'],
  ['X','X','O','X'],
  ['X','O','X','X']
]
```

**Expected Output:**
```
[
  ['X','X','X','X'],
  ['X','X','X','X'],
  ['X','X','X','X'], 
  ['X','O','X','X']
]
```

### Step-by-Step Dry Run

**Initial Grid:**
```
X X X X
X O O X
X X O X  
X O X X
```

**Step 1:** Mark border O's as T
```
X X X X
X O O X
X X O X  
X T X X  ← (3,1) is on border, marked as T
```

**Step 2:** BFS from border O's - none connected internally in this case

**Step 3:** Final replacement
- All remaining `O` → `X` (they were surrounded)  
- All `T` → `O` (they were border-connected)

```
X X X X
X X X X  ← O's became X (surrounded)
X X X X  ← O became X (surrounded)
X O X X  ← T became O (was border-connected)
```

### Algorithm Flow Diagram
```
Input Grid → Mark Border O's → BFS Mark Connected → Replace O→X, T→O → Output
     ↓              ↓                ↓                    ↓          ↓
   X O X        X T X          X T X             X O X    Result
   O O O   →    T T T     →    T T T       →     O O O
   X O X        X T X          X T X             X O X
```

---

## Summary

### Key Concepts Used

| Problem | Grid Type | Movement | Key Technique |
|---------|-----------|----------|---------------|
| Covid Spread | 2D Integer | 4-directional | Level-by-level BFS |
| Islands | 2D Character | 8-directional | Component marking |  
| Replace O's | 2D Character | 4-directional | Reverse thinking |

### Time & Space Complexity

- **Time Complexity:** O(m×n) for all problems - each cell visited once
- **Space Complexity:** O(m×n) for queue storage in worst case

### Common BFS Pattern

1. **Initialize:** Set up direction arrays, queue, visited marking
2. **Process:** Add starting points to queue  
3. **Traverse:** BFS level-by-level or component-wise
4. **Mark:** Update grid state during traversal
5. **Result:** Return count, time, or modified grid

All three problems demonstrate the power of BFS for 2D grid traversal with different applications and slight variations in implementation strategy.