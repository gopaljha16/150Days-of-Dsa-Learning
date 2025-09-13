# Shortest Source to Destination Path - BFS Solution

## Code Structure

### Approach 1: With Visited Array
```cpp
class Solution {
public:
    int row[4] = {1,-1,0,0};     // Direction arrays for down, up, right, left
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // Edge cases
        if(X==0 && Y==0) return 0;           // Already at destination
        if(!A[0][0]) return -1;              // Source is blocked
          
        queue<pair<int,pair<int, int>>> q;   // {row, {col, step}}
        q.push({0, {0,0}});
        
        vector<vector<bool>> visited(N, vector<bool>(M,0));
        visited[0][0] = 1;
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();
            
            // Check all 4 directions
            for(int k=0; k<4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];
                
                if(valid(new_i, new_j, N, M) && A[new_i][new_j] && !visited[new_i][new_j]) {
                    if(new_i==X && new_j==Y) return step+1;
                    
                    visited[new_i][new_j] = 1;
                    q.push({new_i, {new_j, step+1}});
                }
            }
        }
        return -1;
    }
};
```

### Approach 2: Space-Optimized (Modify Original Array)
```cpp
class Solution {
public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(X==0 && Y==0) return 0;
        if(!A[0][0]) return -1;
          
        queue<pair<int,pair<int, int>>> q;
        q.push({0, {0,0}});
        A[0][0] = 0;  // Mark as visited by setting to 0
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();
            
            for(int k=0; k<4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];
                
                if(valid(new_i, new_j, N, M) && A[new_i][new_j]) {
                    if(new_i==X && new_j==Y) return step+1;
                    
                    A[new_i][new_j] = 0;  // Mark as visited
                    q.push({new_i, {new_j, step+1}});
                }
            }
        }
        return -1;
    }
};
```

### Approach 3: Level-wise BFS
```cpp
class Solution {
public:
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(X==0 && Y==0) return 0;
        if(!A[0][0]) return -1;
         
        int step = 0; 
        queue<pair<int,int>> q;
        q.push({0,0});
        A[0][0] = 0;
        
        while(!q.empty()) {
            int count = q.size();  // Process all nodes at current level
            
            while(count--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
            
                for(int k=0; k<4; k++) {
                    int new_i = i + row[k];
                    int new_j = j + col[k];
                    
                    if(valid(new_i, new_j, N, M) && A[new_i][new_j]) {
                        if(new_i==X && new_j==Y) return step+1;
                        
                        A[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;  // Increment step after processing current level
        }
        return -1;
    }
};
```

## Algorithm Explanation

### Key Components:

1. **Direction Arrays**: `row[]` and `col[]` arrays represent movement in 4 directions
2. **Valid Function**: Checks if coordinates are within bounds
3. **BFS Queue**: Stores coordinates and optionally step count
4. **Visited Tracking**: Either separate array or modify original matrix

### Step-by-Step Process:

1. **Initialize**: Start from (0,0) and add to queue
2. **Process Queue**: For each position, explore 4 adjacent cells
3. **Check Validity**: Ensure new position is valid and walkable
4. **Target Check**: If destination reached, return step count
5. **Mark Visited**: Prevent revisiting same cell
6. **Continue**: Add new valid positions to queue

## Example Walkthrough

### Input:
```
Matrix A:
1 0 1 1 1
1 0 1 0 1  
1 1 1 0 1
0 0 0 0 1
Target: X=3, Y=4
```

### Visualization:
```
Step 0: Start at (0,0)
S 0 1 1 1
1 0 1 0 1  
1 1 1 0 1
0 0 0 0 T

Step 1: From (0,0) → (1,0)
X 0 1 1 1
1 0 1 0 1  
1 1 1 0 1
0 0 0 0 T

Step 2: From (1,0) → (2,0), (2,1)
X 0 1 1 1
X 0 1 0 1  
1 1 1 0 1
0 0 0 0 T

... continue until reaching target
```

### Dry Run:

| Step | Queue State | Current Position | Valid Neighbors | Action |
|------|-------------|------------------|-----------------|---------|
| 0 | [(0,0)] | (0,0) | (1,0) | Add (1,0) to queue |
| 1 | [(1,0)] | (1,0) | (2,0) | Add (2,0) to queue |
| 2 | [(2,0)] | (2,0) | (2,1) | Add (2,1) to queue |
| ... | ... | ... | ... | ... |
| n | ... | (2,4) | (3,4) | Target found! Return step+1 |

**Expected Output**: `8` (minimum steps to reach destination)

## Time & Space Complexity

- **Time Complexity**: O(N×M) - Each cell visited at most once
- **Space Complexity**: 
  - Approach 1: O(N×M) for visited array + O(N×M) for queue
  - Approach 2 & 3: O(N×M) for queue only (modifies input)

## Key Insights

1. **BFS Guarantees Shortest Path** in unweighted graphs
2. **Level-wise Processing** naturally tracks step count
3. **Space Optimization** possible by modifying input array
4. **Early Termination** when target is found


# Knight Walk - BFS Solution

## Problem Description
Given a knight's position and target position on an N×N chessboard, find minimum moves to reach the target.

## Code Analysis

```cpp
class Solution {
public:
    // Knight's 8 possible moves (L-shaped)
    int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};
  
    bool valid(int i, int j, int n) {
        return i>=0 && j>=0 && i<n && j<n;
    }
    
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Convert to 0-based indexing
        KnightPos[0]--; KnightPos[1]--;
        TargetPos[0]--; TargetPos[1]--;
        
        // Base case: already at target
        if(TargetPos[0]==KnightPos[0] && TargetPos[1]==KnightPos[1])
            return 0;
         
        queue<pair<int,int>> q;
        vector<vector<bool>> chess(N, vector<bool>(N,0));
        
        q.push({KnightPos[0], KnightPos[1]});
        chess[KnightPos[0]][KnightPos[1]] = 1;
        
        int step = 0;
        while(!q.empty()) {
            int count = q.size();  // Level-wise processing
        
            while(count--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                // Try all 8 possible knight moves
                for(int k=0; k<8; k++) {
                    int new_i = i + row[k];
                    int new_j = j + col[k];
                    
                    if(valid(new_i, new_j, N) && !chess[new_i][new_j]) {
                        // Check if target reached
                        if(new_i == TargetPos[0] && new_j == TargetPos[1]) {
                            return step + 1;
                        }
                       
                        chess[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;
        }
        return -1;  // Target unreachable
    }
};
```

## Knight Movement Pattern

### ASCII Diagram of Knight Moves:
```
    0 1 2 3 4
0   . X . X .
1   X . . . X  
2   . . K . .   (K = Knight position)
3   X . . . X
4   . X . X .

Knight at (2,2) can move to:
- (0,1), (0,3) - up 2, left/right 1
- (1,0), (1,4) - up 1, left/right 2  
- (3,0), (3,4) - down 1, left/right 2
- (4,1), (4,3) - down 2, left/right 1
```

### Direction Arrays Explanation:
```cpp
int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};
```

| Index | Row Change | Col Change | Movement Description |
|-------|------------|------------|---------------------|
| 0 | +2 | +1 | Down 2, Right 1 |
| 1 | +2 | -1 | Down 2, Left 1 |
| 2 | -2 | +1 | Up 2, Right 1 |
| 3 | -2 | -1 | Up 2, Left 1 |
| 4 | +1 | +2 | Down 1, Right 2 |
| 5 | +1 | -2 | Down 1, Left 2 |
| 6 | -1 | +2 | Up 1, Right 2 |
| 7 | -1 | -2 | Up 1, Left 2 |

## Example Walkthrough

### Input:
- Knight Position: [4, 5] (1-indexed) → [3, 4] (0-indexed)
- Target Position: [1, 1] (1-indexed) → [0, 0] (0-indexed)  
- Board Size: N = 6

### Visual Representation:
```
Initial State (0-indexed):
T . . . . .  (T = Target at (0,0))
. . . . . .
. . . . . .
. . . . K .  (K = Knight at (3,4))
. . . . . .
. . . . . .
```

### Step-by-Step BFS:

**Step 0**: Start at (3,4)
- Queue: [(3,4)]
- Visited: (3,4)

**Step 1**: From (3,4), knight can move to:
- (1,3), (1,5), (2,2), (2,6-invalid), (4,2), (4,6-invalid), (5,3), (5,5)
- Valid moves: (1,3), (1,5), (2,2), (4,2), (5,3), (5,5)

```
. . . K . K  
. . . . . .
. . K . . .
. . . . X .  (X = current position)
. . K . . .
. . . K . K
```

**Step 2**: Process all positions from step 1
- From (1,3): can reach (0,1), (0,5), (2,1), (2,5), (3,2), etc.
- From (2,2): can reach (0,1), (0,3), (1,0), (1,4), (3,0), (3,4-visited), (4,1), (4,3)

**Step 3**: Continue BFS...
- Eventually reach (0,0) from some position

### Dry Run Table:

| Step | Queue Size | Current Processing | New Valid Positions | Target Found? |
|------|------------|-------------------|---------------------|---------------|
| 0 | 1 | (3,4) | (1,3),(1,5),(2,2),(4,2),(5,3),(5,5) | No |
| 1 | 6 | All step 1 positions | Multiple new positions | No |
| 2 | ~12 | All step 2 positions | More positions including near (0,0) | No |
| 3 | ~18 | All step 3 positions | Including (0,0) | **Yes! Return 3** |

**Expected Output**: `3`

## Algorithm Analysis

### Time Complexity: O(N²)
- Each cell visited at most once
- Maximum N² cells on the board

### Space Complexity: O(N²)  
- Visited array: N² space
- Queue: O(N²) in worst case

## Key Insights

1. **Knight moves in L-shape**: 2 squares in one direction, 1 square perpendicular
2. **BFS guarantees minimum moves**: First time we reach target is optimal
3. **8 possible moves**: Knight is more flexible than rook/bishop
4. **Level-wise processing**: Natural step counting without storing steps in queue

# Find Whether Path Exists - BFS Solution

## Problem Description
Given a grid where:
- `1` = Source
- `2` = Destination  
- `3` = Walkable path
- `0` = Blocked cell

Determine if a path exists from source to destination.

## Code Analysis

```cpp
class Solution {
public:
    // 4-directional movement
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
      
    bool valid(int i, int j, int n) {
        return i>=0 && j>=0 && i<n && j<n;
    }
    
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        int src_i = -1, src_j = -1;

        // Find the source cell (value = 1)
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    src_i = i;
                    src_j = j;
                    break;
                }
            }
        }
       
        queue<pair<int,int>> q;
        q.push({src_i, src_j});
        grid[src_i][src_j] = 0;  // Mark source as visited
       
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            // Check if current cell is destination
            if(grid[i][j] == 2) return true;

            // Explore 4 directions
            for(int k=0; k<4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];
               
                if(valid(new_i, new_j, n) && grid[new_i][new_j] != 0) {
                    // If destination found
                    if(grid[new_i][new_j] == 2)
                        return true;
                   
                    grid[new_i][new_j] = 0;  // Mark as visited
                    q.push({new_i, new_j});
                }
            }
        }
        return false;  // Path not found
    }
};
```

## Algorithm Breakdown

### Step-by-Step Process:

1. **Find Source**: Locate cell with value `1`
2. **Initialize BFS**: Add source to queue, mark as visited
3. **Process Queue**: For each cell, check if it's destination
4. **Explore Neighbors**: Add valid unvisited neighbors to queue
5. **Mark Visited**: Set cell to `0` to avoid cycles
6. **Return Result**: `true` if destination found, `false` otherwise

## Example Walkthrough

### Input Grid:
```
1 3 0 2
3 3 0 3  
3 3 3 3
0 3 3 3
```

Where:
- `1` at (0,0) = Source
- `2` at (0,3) = Destination  
- `3` = Walkable cells
- `0` = Blocked cells

### Visual Trace:

**Initial State:**
```
S 3 X D   (S=Source, D=Destination, X=Blocked)
3 3 X 3  
3 3 3 3
X 3 3 3
```

**Step 0**: Start BFS from (0,0)
- Queue: [(0,0)]
- Mark (0,0) as visited

**Step 1**: From (0,0), explore neighbors
- Check (1,0): value=3, valid → add to queue
- Check (0,1): value=3, valid → add to queue
- Other directions invalid/blocked

```
V 3 X D   (V=Visited)
3 3 X 3  
3 3 3 3
X 3 3 3

Queue: [(1,0), (0,1)]
```

**Step 2**: Process (1,0)
- Check neighbors: (2,0), (1,1) are valid
- Add to queue

**Step 3**: Process (0,1)  
- Check neighbors: (0,2) is blocked, (1,1) already in queue

**Continue BFS**: Eventually explore all reachable cells
- Path exists: (0,0) → (0,1) → ... → (0,3)? NO, (0,2) is blocked!
- Alternative: (0,0) → (1,0) → (2,0) → (2,1) → (2,2) → (2,3) → (1,3) → (0,3)? Let's trace...

### Detailed BFS Trace:

| Step | Current | Queue After Processing | Action |
|------|---------|----------------------|--------|
| 0 | - | [(0,0)] | Initialize |
| 1 | (0,0) | [(1,0), (0,1)] | Add valid neighbors |
| 2 | (1,0) | [(0,1), (2,0), (1,1)] | Add (2,0), (1,1) |
| 3 | (0,1) | [(2,0), (1,1)] | No new valid neighbors |
| 4 | (2,0) | [(1,1), (2,1)] | Add (2,1) |
| 5 | (1,1) | [(2,1), (2,2)] | Add (2,2) |
| 6 | (2,1) | [(2,2), (2,3)] | Add (2,3) |
| 7 | (2,2) | [(2,3), (1,3)] | Add (1,3) |
| 8 | (2,3) | [(1,3), (0,3)] | Add (1,3), **destination found!** |

**Result**: `true` - Path exists!

### Alternative Example (No Path):

```
1 3 0 2
3 0 0 3  
0 0 0 3
3 3 3 3
```

In this case, destination (0,3) is isolated by blocked cells, so BFS cannot reach it.

**Result**: `false`

## Key Features

### Grid Cell Values:
- `0`: Blocked/Visited (impassable)
- `1`: Source (starting point)
- `2`: Destination (target)
- `3`: Walkable path

### Space Optimization:
- **No extra visited array** needed
- **Modify original grid** by setting visited cells to `0`
- **Prevents cycles** and reduces memory usage

### Early Termination:
- **Return immediately** when destination found
- **No need to explore further** once path confirmed

## Complexity Analysis

### Time Complexity: O(N²)
- Each cell visited at most once
- Finding source: O(N²) in worst case
- BFS traversal: O(N²)

### Space Complexity: O(N²)
- Queue space in worst case (all cells reachable)
- No additional visited array needed

## Algorithm Variants

### Alternative Implementation (With Visited Array):
```cpp
bool is_Possible(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    // Find source and use visited array instead of modifying grid
    // Rest of the algorithm remains similar
}
```

### DFS Alternative:
```cpp
bool dfs(vector<vector<int>>& grid, int i, int j, int n) {
    if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0) return false;
    if(grid[i][j] == 2) return true;
    
    grid[i][j] = 0;  // Mark visited
    return dfs(grid,i+1,j,n) || dfs(grid,i-1,j,n) || 
           dfs(grid,i,j+1,n) || dfs(grid,i,j-1,n);
}
```

## Summary

This BFS solution efficiently determines path existence by:
1. **Finding source** through grid scan
2. **Using BFS** for systematic exploration  
3. **Optimizing space** by modifying original grid
4. **Early termination** for efficiency
5. **Handling edge cases** gracefully

# Graph Traversal Problems - Summary & Comparison

## Problems Overview

| Problem | Input | Output | Key Challenge |
|---------|-------|--------|---------------|
| **Shortest Path** | Binary matrix, destination | Minimum steps | Find shortest path in 4-connected grid |
| **Knight Walk** | Knight position, target, board size | Minimum moves | Knight's L-shaped movement constraint |
| **Path Exists** | Grid with source/destination/obstacles | Boolean | Simple reachability check |

## Algorithm Comparison

### Common Elements:
- **BFS Traversal**: All use breadth-first search
- **Direction Arrays**: Define valid movements  
- **Visited Tracking**: Prevent infinite loops
- **Queue Processing**: Level-wise exploration

### Key Differences:

| Aspect | Shortest Path | Knight Walk | Path Exists |
|--------|---------------|-------------|-------------|
| **Movement** | 4-directional | 8 L-shaped moves | 4-directional |
| **Goal** | Find minimum distance | Find minimum moves | Check if path exists |
| **Return Type** | int (steps) | int (moves) | bool (exists) |
| **Cell Values** | 0,1 (blocked,open) | All open | 0,1,2,3 (blocked,src,dest,path) |
| **Optimization** | Multiple approaches | Standard BFS | Space-optimized |

## Implementation Strategies

### 1. Step Counting Methods:

#### A. Store Steps in Queue:
```cpp
queue<pair<int,pair<int,int>>> q;  // {row, {col, step}}
q.push({0, {0, 0}});  // step = 0 initially
return step + 1;  // when target found
```

#### B. Level-wise Processing:
```cpp
int step = 0;
while(!q.empty()) {
    int count = q.size();  // Process entire level
    while(count--) {
        // Process current level nodes
    }
    step++;  // Increment after level completion
}
```

### 2. Visited Tracking Methods:

#### A. Separate Visited Array:
```cpp
vector<vector<bool>> visited(N, vector<bool>(M, false));
visited[i][j] = true;  // Mark as visited
```

#### B. Modify Original Array:
```cpp
A[i][j] = 0;  // Mark as visited (blocked)
```

### 3. Direction Array Patterns:

#### 4-Directional (Up, Down, Left, Right):
```cpp
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};
```

#### 8-Directional Knight Moves:
```cpp
int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};
```

## Performance Analysis

### Time Complexity: **O(N×M)** or **O(N²)**
- Each cell/position visited at most once
- BFS guarantees optimal solution

### Space Complexity:
| Method | Space | Trade-off |
|--------|-------|-----------|
| **With Visited Array** | O(N×M) | Preserves original input |
| **Modify Original** | O(1) extra | Destroys input data |
| **Queue Space** | O(N×M) | Unavoidable for BFS |

## When to Use Each Approach

### Shortest Path Problem:
- **Use when**: Need minimum distance in grid
- **Applications**: Robot navigation, maze solving, shortest route
- **Variants**: Weighted graphs (use Dijkstra), obstacles, multiple destinations

### Knight Walk Problem:
- **Use when**: Piece movement with specific constraints
- **Applications**: Chess programming, puzzle games, pathfinding with custom moves
- **Variants**: Other chess pieces, different board shapes, obstacles

### Path Exists Problem:
- **Use when**: Only need to know if connection exists
- **Applications**: Network connectivity, maze solvability, component checking
- **Variants**: Multiple sources/destinations, directed graphs, weighted paths

## Common BFS Template

```cpp
// Generic BFS template for grid problems
bool/int solveBFS(grid, start, end) {
    queue<coordinates> q;
    visited_structure vis;
    
    q.push(start);
    mark_visited(start, vis);
    
    int steps = 0;  // if counting needed
    
    while(!q.empty()) {
        int size = q.size();  // level-wise processing
        
        while(size--) {
            auto curr = q.front();
            q.pop();
            
            if(reached_target(curr, end)) {
                return steps;  // or true for existence
            }
            
            for(each direction) {
                auto next = get_next_position(curr, direction);
                if(is_valid(next) && !is_visited(next, vis)) {
                    mark_visited(next, vis);
                    q.push(next);
                }
            }
        }
        steps++;  // increment after processing level
    }
    
    return -1;  // or false for not found
}
```

## Advanced Optimizations

### 1. Bidirectional BFS
```cpp
// For shortest path problems - search from both ends
queue<pair<int,int>> q1, q2;  // from start and end
unordered_set<string> vis1, vis2;

while(!q1.empty() && !q2.empty()) {
    // Expand smaller frontier first
    if(q1.size() <= q2.size()) {
        expand(q1, vis1, vis2);  // if intersection found, return
    } else {
        expand(q2, vis2, vis1);
    }
}
```

### 2. A* Algorithm Enhancement
```cpp
// For shortest path with heuristic
priority_queue<Node> pq;  // ordered by f(n) = g(n) + h(n)

struct Node {
    int x, y, g_cost, f_cost;
    bool operator<(const Node& other) const {
        return f_cost > other.f_cost;  // min-heap
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);  // Manhattan distance
}
```

### 3. Memory-Optimized Knight Walk
```cpp
// Use coordinate encoding for large boards
int encode(int x, int y, int N) { return x * N + y; }
pair<int,int> decode(int pos, int N) { return {pos/N, pos%N}; }

unordered_set<int> visited;  // instead of 2D array
```

## Edge Cases and Error Handling

### Common Edge Cases:
1. **Source equals destination** → Return 0
2. **Source is blocked** → Return -1/false
3. **Destination is blocked** → Return -1/false
4. **Empty grid** → Handle gracefully
5. **Single cell grid** → Check if source=destination

### Boundary Validation:
```cpp
bool valid(int i, int j, int rows, int cols) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

// Enhanced validation with obstacle check
bool valid_and_passable(int i, int j, int rows, int cols, vector<vector<int>>& grid) {
    return valid(i, j, rows, cols) && grid[i][j] != 0;
}
```

## Problem Variations and Extensions

### 1. Multi-Source BFS
```cpp
// Multiple starting points (useful for island problems)
queue<pair<int,int>> q;
for(auto& source : sources) {
    q.push(source);
    visited[source.first][source.second] = true;
}
// Continue with standard BFS
```

### 2. Weighted Graph Shortest Path
```cpp
// Use Dijkstra instead of BFS
priority_queue<pair<int,pair<int,int>>> pq;  // {-weight, {x,y}}
pq.push({0, {start_x, start_y}});

while(!pq.empty()) {
    int weight = -pq.top().first;
    auto [x, y] = pq.top().second;
    pq.pop();
    
    if(visited[x][y]) continue;
    visited[x][y] = true;
    
    if(x == end_x && y == end_y) return weight;
    
    // Add neighbors with their weights
}
```

### 3. Path Reconstruction
```cpp
// Store parent information to reconstruct actual path
map<pair<int,int>, pair<int,int>> parent;
parent[{start_x, start_y}] = {-1, -1};

// During BFS:
parent[{new_x, new_y}] = {curr_x, curr_y};

// Reconstruct path:
vector<pair<int,int>> path;
auto curr = make_pair(end_x, end_y);
while(curr.first != -1) {
    path.push_back(curr);
    curr = parent[curr];
}
reverse(path.begin(), path.end());
```

## Testing and Debugging Tips

### 1. Visualization Helper:
```cpp
void print_grid(vector<vector<int>>& grid) {
    for(auto& row : grid) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
}

void print_path(vector<pair<int,int>>& path) {
    for(auto [x, y] : path) {
        cout << "(" << x << "," << y << ") -> ";
    }
    cout << "END\n";
}
```

### 2. Step-by-Step Debugger:
```cpp
void debug_bfs_step(queue<pair<int,int>>& q, int step) {
    cout << "Step " << step << ": Queue size = " << q.size() << "\n";
    queue<pair<int,int>> temp = q;
    while(!temp.empty()) {
        cout << "(" << temp.front().first << "," << temp.front().second << ") ";
        temp.pop();
    }
    cout << "\n";
}
```

### 3. Test Cases:
```cpp
// Comprehensive test suite
vector<TestCase> tests = {
    {{1,0,1,1}, {0,0}, {0,3}, -1},      // No path
    {{1,1,1,1}, {0,0}, {0,3}, 3},       // Simple path
    {{1,0,0,1}, {0,0}, {3,3}, -1},      // Blocked destination
    {{1}, {0,0}, {0,0}, 0},             // Same start/end
    // Add more edge cases...
};
```

## Real-World Applications

### 1. **Game Development**
- **Pathfinding**: NPC movement, player navigation
- **Level Design**: Ensuring all areas are reachable
- **Puzzle Games**: Validating solvable configurations

### 2. **Robotics**
- **Navigation**: Mobile robot path planning
- **Obstacle Avoidance**: Dynamic pathfinding
- **Coverage**: Ensuring all areas can be reached

### 3. **Network Analysis**
- **Connectivity**: Checking if nodes can communicate
- **Shortest Routes**: Network packet routing
- **Redundancy**: Finding alternative paths

### 4. **Geographic Information Systems (GIS)**
- **Route Planning**: GPS navigation systems
- **Accessibility**: Wheelchair-accessible routes
- **Emergency Response**: Optimal emergency vehicle routing

## Conclusion

These three BFS problems demonstrate fundamental graph traversal concepts:

- **Shortest Path**: Optimal distance finding
- **Knight Walk**: Constrained movement patterns  
- **Path Exists**: Basic connectivity checking

Key takeaways:
1. **BFS guarantees shortest path** in unweighted graphs
2. **Direction arrays** simplify movement logic
3. **Space-time trade-offs** exist in visited tracking
4. **Level-wise processing** enables natural step counting
5. **Early termination** improves efficiency

Master these patterns and you can solve most grid-based pathfinding problems efficiently!