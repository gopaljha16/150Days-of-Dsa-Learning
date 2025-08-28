# Cycle Detection in a Directed Graph

## Overview

This code provides two different approaches to detect cycles in a directed graph:

1. **DFS-based approach** using recursion with path tracking
2. **BFS-based approach** using Kahn's Algorithm (Topological Sorting)

Both methods solve the problem of determining whether a directed graph contains at least one cycle. A cycle exists when you can start from a vertex and follow directed edges to eventually return to the same vertex.

## Table of Contents

- [Method 1: DFS with Path Tracking](#method-1-dfs-with-path-tracking)
- [Method 2: Kahn's Algorithm (BFS)](#method-2-kahns-algorithm-bfs)
- [Example Walkthrough](#example-walkthrough)
- [Visual Diagrams](#visual-diagrams)
- [Complexity Analysis](#complexity-analysis)
- [Summary](#summary)

## Method 1: DFS with Path Tracking

### Code Explanation

```cpp
class Solution {
  public:
 
    bool cycle(int node, vector<vector<int>>&adj, vector<bool>&path, vector<bool>&visited) {
       
       visited[node] = 1;    // Mark current node as visited
       path[node] = 1;       // Mark current node in current DFS path
       
       // Check all neighbors of current node
       for(int i = 0; i < adj[node].size(); i++) {
           // If neighbor is already in current path, cycle detected
           if(path[adj[node][i]])
             return 1;
           
           // If neighbor already visited (but not in current path), skip
           if(visited[adj[node][i]])
            continue;
           
           // Recursively check neighbor
           if(cycle(adj[node][i], adj, path, visited))
            return 1;
       }
       
       // Backtrack: remove current node from path
       path[node] = 0;
       return 0; // No cycle detected from this node
    }
 
    bool isCyclic(int V, vector<vector<int>> &edges) {
     
       // Build adjacency list from edge list
       vector<vector<int>>adj(V);
       for(auto e : edges) {
          int u = e[0];
          int v = e[1];
          adj[u].push_back(v);  // Directed edge u -> v
       }
       
       vector<bool>visited(V, 0);  // Track visited nodes
       vector<bool>path(V, 0);     // Track nodes in current DFS path
       
       // Check each unvisited node (handles disconnected components)
       for(int i = 0; i < V; i++) {
           if(!visited[i] && cycle(i, adj, path, visited))
             return 1;  // Cycle found
       }
       
       return 0;  // No cycle found
    }
};
```

### Line-by-Line Breakdown

1. **Lines 5-6**: Mark the current node as visited and add it to the current DFS path
2. **Lines 9-11**: Check each neighbor - if any neighbor is already in the current path, we found a back edge (cycle)
3. **Lines 14-15**: Skip neighbors that are already visited but not in current path (optimization)
4. **Lines 17-18**: Recursively explore unvisited neighbors
5. **Line 22**: **Backtracking step** - remove node from current path when done exploring
6. **Lines 29-33**: Build adjacency list representation from edge list
7. **Lines 38-41**: Check all nodes to handle disconnected graph components

## Method 2: Kahn's Algorithm (BFS)

### Code Explanation

```cpp
class Solution {
  public:
 
    bool isCyclic(int V, vector<vector<int>> &edges) {
     
       // Build adjacency list
       vector<vector<int>>adj(V);
       for(auto e : edges) {
          int u = e[0];
          int v = e[1];
          adj[u].push_back(v);
       }
       
       // Calculate in-degree for each vertex
       vector<int>inDegree(V, 0);
       for(int i = 0; i < V; i++) {
           for(int j = 0; j < adj[i].size(); j++) {
               inDegree[adj[i][j]]++;  // Increment in-degree of target vertex
           }
       }
       
       // Initialize queue with vertices having 0 in-degree
       queue<int>q;
       for(int i = 0; i < V; i++) {
           if(!inDegree[i])  // If in-degree is 0
              q.push(i);
       }
       
       int count = 0;  // Count of processed vertices
       while(!q.empty()) {
           int node = q.front();
           q.pop();
           count++;
           
           // Process all neighbors of current node
           for(int i = 0; i < adj[node].size(); i++) {
               inDegree[adj[node][i]]--;  // Decrease in-degree
               
               // If in-degree becomes 0, add to queue
               if(!inDegree[adj[node][i]])
                q.push(adj[node][i]);
           }
       }
       
       return count != V;  // If count < V, cycle exists
    }
};
```

### Line-by-Line Breakdown

1. **Lines 15-20**: Calculate in-degree for each vertex (number of incoming edges)
2. **Lines 23-27**: Add all vertices with 0 in-degree to queue (starting points)
3. **Lines 29-42**: Process vertices in topological order, reducing in-degrees
4. **Line 44**: If we can't process all vertices, a cycle exists

## Example Walkthrough

Let's trace through both algorithms with this example:

### Input Graph
```
Vertices: 4 (0, 1, 2, 3)
Edges: [[0,1], [1,2], [2,3], [3,1]]
```

### Graph Visualization
```
0 → 1 → 2
    ↑   ↓
    ← 3 ←
```

### Method 1: DFS Walkthrough

**Initial State:**
- `visited = [0, 0, 0, 0]`
- `path = [0, 0, 0, 0]`
- `adj = [[1], [2], [3], [1]]`

**Step-by-Step Execution:**

1. **Start DFS from node 0:**
   - `visited[0] = 1, path[0] = 1`
   - Explore neighbor 1

2. **DFS at node 1:**
   - `visited[1] = 1, path[1] = 1`
   - Explore neighbor 2

3. **DFS at node 2:**
   - `visited[2] = 1, path[2] = 1`
   - Explore neighbor 3

4. **DFS at node 3:**
   - `visited[3] = 1, path[3] = 1`
   - Check neighbor 1: `path[1] = 1` ✓ **CYCLE DETECTED!**

### Method 2: Kahn's Algorithm Walkthrough

**Step 1: Calculate In-degrees**
```
Node | In-degree
-----|----------
  0  |    0
  1  |    2     (from 0 and 3)
  2  |    1     (from 1)
  3  |    1     (from 2)
```

**Step 2: Initialize Queue**
- Only node 0 has in-degree 0, so `queue = [0]`

**Step 3: Process Queue**
1. **Process node 0:**
   - `count = 1`
   - Reduce in-degree of node 1: `inDegree[1] = 1`
   - Queue remains: `[]`

2. **Queue is empty, but count = 1 ≠ 4**
   - **CYCLE DETECTED!**

## Visual Diagrams

### DFS Path Tracking Visualization

```
Step 1: Start at 0          Step 2: Move to 1          Step 3: Move to 2
Path: [0]                   Path: [0,1]                Path: [0,1,2]
   0*                         0* → 1*                    0* → 1* → 2*
   ↓                              ↓                          ↓
   1 → 2                          2                          3
   ↑   ↓                      ↑   ↓                      ↑
   ← 3 ←                      ← 3 ←                      ← 3 ←

Step 4: Move to 3          Step 5: Check 1 (CYCLE!)
Path: [0,1,2,3]           Path contains 1 already!
   0* → 1* → 2*              0* → 1* ← 3*
        ↑     ↓                   ↑     ↓
        ← 3* ←                    ← 2* ←
```

### Kahn's Algorithm Visualization

```
Initial In-degrees:        After processing node 0:
   0(0) → 1(2) → 2(1)        0(✓) → 1(1) → 2(1)
          ↑      ↓                  ↑      ↓
          ← 3(1) ←                  ← 3(1) ←

Queue: [0]                 Queue: [] (empty!)
Count: 0                   Count: 1

Since count(1) ≠ V(4), cycle detected!
```

## Test Cases

### Example 1: Graph with Cycle
```cpp
Input: V = 4, edges = [[0,1], [1,2], [2,3], [3,1]]
Output: true (cycle exists: 1→2→3→1)
```

### Example 2: Graph without Cycle (DAG)
```cpp
Input: V = 4, edges = [[0,1], [1,2], [0,3], [3,2]]
Output: false (no cycle)

Graph: 0 → 1 → 2
       ↓     ↗
       3 ────
```

### Example 3: Disconnected Graph with Cycle
```cpp
Input: V = 5, edges = [[0,1], [2,3], [3,4], [4,2]]
Output: true (cycle in component: 2→3→4→2)
```

## Complexity Analysis

| Algorithm | Time Complexity | Space Complexity | Notes |
|-----------|----------------|------------------|--------|
| DFS Method | O(V + E) | O(V) | Recursive stack + arrays |
| Kahn's Algorithm | O(V + E) | O(V) | Queue + in-degree array |

Where:
- V = number of vertices
- E = number of edges

## Key Insights

### DFS Method Advantages:
- ✅ More intuitive for cycle detection
- ✅ Direct cycle detection via back edges
- ✅ Works well for sparse graphs

### Kahn's Algorithm Advantages:
- ✅ Also produces topological ordering
- ✅ Iterative approach (no recursion)
- ✅ Easy to understand conceptually

### When to Use Which:
- **Use DFS** when you need to find the actual cycle path
- **Use Kahn's** when you also need topological sorting
- **Both** have similar performance characteristics

## Summary

This code demonstrates two fundamental approaches to cycle detection in directed graphs:

1. **DFS with Path Tracking**: Uses recursion to detect back edges, which indicate cycles. The key insight is maintaining both `visited` and `path` arrays to distinguish between nodes visited in previous DFS calls vs. the current path.

2. **Kahn's Algorithm**: Uses the principle that a DAG (Directed Acyclic Graph) can be topologically sorted. If we can't process all vertices during topological sorting, a cycle must exist.

Both algorithms have O(V + E) time complexity and are equally valid solutions. The choice between them often depends on whether you need additional information (like the topological order) or have constraints on recursion depth.