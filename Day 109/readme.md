# Graph Traversal Algorithms - BFS & DFS

## Overview

This code implements two fundamental graph traversal algorithms:
1. **Breadth-First Search (BFS)** - Explores nodes level by level using a queue
2. **Depth-First Search (DFS)** - Explores nodes by going as deep as possible using recursion

Both algorithms traverse an undirected graph represented as an adjacency list and return the order in which vertices are visited, starting from vertex 0.

## Data Structures Used

- **Adjacency List**: `vector<vector<int>>` where `adj[i]` contains all neighbors of vertex `i`
- **Queue**: For BFS to maintain FIFO order
- **Visited Array**: `vector<bool>` to track visited vertices
- **Result Vector**: `vector<int>` to store traversal order

## BFS Implementation

### Code Structure

```cpp
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) { 
        queue<int> q;
        int v = adj.size();                    // Number of vertices
        vector<bool> visited(v, 0);            // Track visited nodes
        
        q.push(0);                             // Start from vertex 0
        visited[0] = 1;                        // Mark 0 as visited
        
        vector<int> ans;                       // Result array
        int node;
        
        while(!q.empty()) {                    // Process until queue is empty
            node = q.front();                  // Get front element
            q.pop();                           // Remove from queue
            ans.push_back(node);               // Add to result
           
            // Visit all unvisited neighbors
            for(int i = 0; i < adj[node].size(); i++) {
                if(!visited[adj[node][i]]) {   // If neighbor not visited
                    visited[adj[node][i]] = 1; // Mark as visited
                    q.push(adj[node][i]);      // Add to queue
                }
            }
        }
        
        return ans;
    }
};
```

### Line-by-Line Explanation

1. **Line 4**: `int v = adj.size()` - Get total number of vertices
2. **Line 5**: `vector<bool> visited(v, 0)` - Initialize all vertices as unvisited
3. **Lines 7-8**: Start BFS from vertex 0 by adding it to queue and marking as visited
4. **Line 10**: `vector<int> ans` - Result vector to store traversal order
5. **Line 13**: Main BFS loop - continues until queue is empty
6. **Lines 14-16**: Process current node (front of queue), remove it, and add to result
7. **Lines 19-24**: Check all neighbors of current node, add unvisited ones to queue

## DFS Implementation

### Code Structure

```cpp
class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited) {
        visited[node] = 1;                     // Mark current node as visited
        ans.push_back(node);                   // Add to result
        
        // Recursively visit all unvisited neighbors
        for(int i = 0; i < adj[node].size(); i++) {
            if(!visited[adj[node][i]]) {       // If neighbor not visited
                DFS(adj[node][i], adj, ans, visited); // Recursive call
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int v = adj.size();                    // Number of vertices
        vector<bool> visited(v, 0);            // Initialize visited array
        vector<int> ans;                       // Result array
       
        DFS(0, adj, ans, visited);             // Start DFS from vertex 0
        return ans;
    }
};
```

### Line-by-Line Explanation

**DFS Helper Function:**
1. **Line 3**: Mark current node as visited
2. **Line 4**: Add current node to result
3. **Lines 7-11**: For each neighbor, if unvisited, recursively call DFS

**Main DFS Function:**
1. **Lines 15-17**: Initialize data structures
2. **Line 19**: Start DFS traversal from vertex 0
3. **Line 20**: Return the traversal result

## Example Input and Expected Output

### Graph Representation
```
Graph:
    0
   / \
  1   2
 /   / \
3   4   5

Adjacency List:
adj[0] = [1, 2]
adj[1] = [0, 3]
adj[2] = [0, 4, 5]
adj[3] = [1]
adj[4] = [2]
adj[5] = [2]
```

### Expected Outputs
- **BFS**: `[0, 1, 2, 3, 4, 5]` (level-order traversal)
- **DFS**: `[0, 1, 3, 2, 4, 5]` (depth-first traversal)

## Step-by-Step Dry Run

### BFS Walkthrough

```
Initial State:
Queue: [0]
Visited: [T, F, F, F, F, F]
Result: []

Step 1: Process node 0
- Pop 0 from queue
- Add 0 to result: [0]
- Check neighbors of 0: [1, 2]
- Add unvisited neighbors to queue
Queue: [1, 2]
Visited: [T, T, T, F, F, F]

Step 2: Process node 1
- Pop 1 from queue
- Add 1 to result: [0, 1]
- Check neighbors of 1: [0, 3]
- 0 already visited, add 3 to queue
Queue: [2, 3]
Visited: [T, T, T, T, F, F]

Step 3: Process node 2
- Pop 2 from queue
- Add 2 to result: [0, 1, 2]
- Check neighbors of 2: [0, 4, 5]
- 0 already visited, add 4, 5 to queue
Queue: [3, 4, 5]
Visited: [T, T, T, T, T, T]

Step 4: Process node 3
- Pop 3 from queue
- Add 3 to result: [0, 1, 2, 3]
- Check neighbors of 3: [1]
- 1 already visited
Queue: [4, 5]

Step 5: Process node 4
- Pop 4 from queue
- Add 4 to result: [0, 1, 2, 3, 4]
- Check neighbors of 4: [2]
- 2 already visited
Queue: [5]

Step 6: Process node 5
- Pop 5 from queue
- Add 5 to result: [0, 1, 2, 3, 4, 5]
- Check neighbors of 5: [2]
- 2 already visited
Queue: []

Final Result: [0, 1, 2, 3, 4, 5]
```

### DFS Walkthrough

```
DFS Call Stack and Execution:

DFS(0):
- Mark 0 as visited: [T, F, F, F, F, F]
- Add 0 to result: [0]
- Check neighbors: [1, 2]
  
  DFS(1):
  - Mark 1 as visited: [T, T, F, F, F, F]
  - Add 1 to result: [0, 1]
  - Check neighbors: [0, 3]
  - 0 already visited
    
    DFS(3):
    - Mark 3 as visited: [T, T, F, T, F, F]
    - Add 3 to result: [0, 1, 3]
    - Check neighbors: [1]
    - 1 already visited
    - Return
  
  - Return from DFS(1)
  
  DFS(2):
  - Mark 2 as visited: [T, T, T, T, F, F]
  - Add 2 to result: [0, 1, 3, 2]
  - Check neighbors: [0, 4, 5]
  - 0 already visited
    
    DFS(4):
    - Mark 4 as visited: [T, T, T, T, T, F]
    - Add 4 to result: [0, 1, 3, 2, 4]
    - Check neighbors: [2]
    - 2 already visited
    - Return
    
    DFS(5):
    - Mark 5 as visited: [T, T, T, T, T, T]
    - Add 5 to result: [0, 1, 3, 2, 4, 5]
    - Check neighbors: [2]
    - 2 already visited
    - Return
  
  - Return from DFS(2)

Final Result: [0, 1, 3, 2, 4, 5]
```

## Visual Comparison

```
BFS Traversal (Level-by-level):
Level 0: 0
Level 1: 1, 2
Level 2: 3, 4, 5
Result: [0, 1, 2, 3, 4, 5]

DFS Traversal (Depth-first):
Path: 0 → 1 → 3 (backtrack) → 2 → 4 (backtrack) → 5
Result: [0, 1, 3, 2, 4, 5]
```

## Algorithm Comparison Table

| Aspect | BFS | DFS |
|--------|-----|-----|
| **Data Structure** | Queue (FIFO) | Stack/Recursion (LIFO) |
| **Space Complexity** | O(V) | O(V) |
| **Time Complexity** | O(V + E) | O(V + E) |
| **Traversal Order** | Level by level | Depth first |
| **Use Cases** | Shortest path, Level-order | Topological sort, Cycle detection |

## Complexity Analysis

### Time Complexity
- **Both BFS and DFS**: O(V + E)
  - V: Number of vertices (each visited once)
  - E: Number of edges (each edge explored once)

### Space Complexity
- **BFS**: O(V) for queue and visited array
- **DFS**: O(V) for recursion stack and visited array

## Key Points

- Both algorithms ensure each vertex is visited exactly once
- BFS uses a queue for level-order traversal
- DFS uses recursion (implicit stack) for depth-first traversal
- The visited array prevents infinite loops in cyclic graphs
- Starting vertex is assumed to be 0 in both implementations

## Summary

This code provides efficient implementations of two fundamental graph traversal algorithms. BFS explores nodes level by level using a queue, making it ideal for finding shortest paths in unweighted graphs. DFS explores nodes by going as deep as possible using recursion, making it suitable for applications like topological sorting and cycle detection. Both algorithms have O(V + E) time complexity and are essential building blocks for more complex graph algorithms.