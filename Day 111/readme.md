# Topological Sort Implementation in C++

## Overview

This code implements **Topological Sorting** using two different algorithms:
1. **DFS-based approach** using a stack
2. **Kahn's Algorithm** using BFS with in-degree calculation

Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) where for every directed edge (u, v), vertex u comes before vertex v in the ordering. It's commonly used in scheduling tasks, course prerequisites, and dependency resolution.

## Algorithm 1: DFS-Based Topological Sort

### Code Explanation

```cpp
class Solution {
  public:
     void DFS(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s){
         // Mark current node as visited
         visited[node] = 1;
         
         // Visit all unvisited neighbors
         for(int i=0; i<adj[node].size(); i++){
             if(!visited[adj[node][i]])
              DFS(adj[node][i], adj, visited, s);
         }
         
         // Push node to stack after visiting all neighbors
         s.push(node);
     }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
      // Build adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
          int u = e[0];
          int v = e[1];
          adj[u].push_back(v); 
      }
      
      vector<bool>visited(V, 0);
      stack<int>s;
      
      // Visit all unvisited nodes
      for(int i = 0; i < V; i++){
          if(!visited[i])  
           DFS(i, adj, visited, s);
      }
        
      // Pop from stack to get topological order
      vector<int>ans;
      while(!s.empty()){
          ans.push_back(s.top());
          s.pop();
      }
      
      return ans;
    }
};
```

**Line-by-Line Breakdown:**

**DFS Function:**
- **Line 3**: Mark current node as visited to avoid cycles
- **Lines 6-9**: Iterate through all neighbors and recursively call DFS on unvisited ones
- **Line 12**: **Key step** - Push node to stack AFTER visiting all its neighbors (post-order)

**topoSort Function:**
- **Lines 16-21**: Convert edge list to adjacency list representation
- **Lines 23-24**: Initialize visited array and result stack
- **Lines 27-30**: Start DFS from all unvisited nodes (handles disconnected components)
- **Lines 33-37**: Pop elements from stack to get final topological order

## Algorithm 2: Kahn's Algorithm (BFS-Based)

### Code Explanation

```cpp
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       // Build adjacency list
       vector<vector<int>>adj(V);
       for(auto e:edges){
           int u = e[0];
           int v = e[1];
           adj[u].push_back(v);
       }
      
      vector<int>ans;
      vector<int>inDegree(V, 0);
      
      // Calculate in-degree for each vertex
      for(int i=0; i<V; i++){
          for(int j=0; j<adj[i].size(); j++){
              inDegree[adj[i][j]]++;
          }
      }
      
      // Add all vertices with in-degree 0 to queue
      queue<int>q;
      for(int i=0; i<V; i++){
          if(!inDegree[i])
           q.push(i);
      }
      
      // Process vertices
      while(!q.empty()){
         int node = q.front();
         q.pop();
         ans.push_back(node);
         
         // Reduce in-degree of neighbors
         for(int j=0; j<adj[node].size(); j++){
             inDegree[adj[node][j]]--;
             if(inDegree[adj[node][j]] == 0)
              q.push(adj[node][j]);
         }
      }
      
      return ans;
    }
};
```

**Line-by-Line Breakdown:**

- **Lines 4-9**: Build adjacency list from edges
- **Line 13**: Initialize in-degree array to track incoming edges
- **Lines 16-20**: Calculate in-degree for each vertex by counting incoming edges
- **Lines 23-27**: Add all vertices with 0 in-degree to queue (no prerequisites)
- **Lines 30-40**: Process queue: remove vertex, add to result, decrease neighbors' in-degrees, add new 0 in-degree vertices to queue

## Example Input and Expected Output

### Input:
```
V = 6 (vertices: 0, 1, 2, 3, 4, 5)
edges = [[5,2], [5,0], [4,0], [4,1], [2,3], [3,1]]
```

### Graph Visualization:
```
    5 ────→ 2 ────→ 3 ────→ 1
    │               ↑       ↑
    │               │       │
    └────→ 0        └───────┘
           ↑
           │
    4 ─────┴────────────────┘
```

### Expected Output:
- **DFS**: `[4, 5, 2, 3, 0, 1]` or `[5, 4, 2, 3, 0, 1]`
- **Kahn's**: `[4, 5, 0, 2, 3, 1]`

## Step-by-Step Walkthrough: DFS Algorithm## Step-by-Step Walkthrough: Kahn's Algorithm

### Initial Setup:
```
adj[0] = []
adj[1] = []  
adj[2] = [3]
adj[3] = [1]
adj[4] = [0, 1]
adj[5] = [2, 0]

inDegree[0] = 2  (edges from 5→0, 4→0)
inDegree[1] = 2  (edges from 4→1, 3→1)
inDegree[2] = 1  (edge from 5→2)
inDegree[3] = 1  (edge from 2→3)
inDegree[4] = 0  (no incoming edges)
inDegree[5] = 0  (no incoming edges)
```

### Processing Steps:

| Step | Queue | Current | Result | InDegree Updates |
|------|-------|---------|---------|------------------|
| 0 | [4,5] | - | [] | Initial: nodes 4,5 have inDegree=0 |
| 1 | [5] | 4 | [4] | Decrease inDegree[0] to 1, inDegree[1] to 1 |
| 2 | [] | 5 | [4,5] | Decrease inDegree[2] to 0, inDegree[0] to 0, add 0,2 to queue |
| 3 | [0,2] | - | [4,5] | Queue now has [0,2] |
| 4 | [2] | 0 | [4,5,0] | No outgoing edges from 0 |
| 5 | [] | 2 | [4,5,0,2] | Decrease inDegree[3] to 0, add 3 to queue |
| 6 | [3] | - | [4,5,0,2] | Queue has [3] |
| 7 | [] | 3 | [4,5,0,2,3] | Decrease inDegree[1] to 0, add 1 to queue |
| 8 | [1] | - | [4,5,0,2,3] | Queue has [1] |
| 9 | [] | 1 | [4,5,0,2,3,1] | No outgoing edges from 1, queue empty |

**Final Result**: `[4, 5, 0, 2, 3, 1]`

## Visual Algorithm Comparison

### DFS Approach:
```
1. Go deep into graph using recursion
2. Push nodes to stack AFTER visiting all children
3. Stack naturally gives reverse topological order
4. Time: O(V + E), Space: O(V)

Flow: Start → DFS(deep) → Stack(post-order) → Pop(reverse)
```

### Kahn's Algorithm:
```
1. Calculate in-degrees for all vertices
2. Start with 0 in-degree vertices (no dependencies)
3. Remove vertices and decrease neighbors' in-degrees
4. Continue until all vertices processed
5. Time: O(V + E), Space: O(V)

Flow: InDegree → Queue(0-degree) → Process → Update → Repeat
```

## Key Differences

| Aspect | DFS Approach | Kahn's Algorithm |
|--------|--------------|------------------|
| **Data Structure** | Stack (implicit recursion + explicit) | Queue |
| **Processing Order** | Post-order (children first) | Level-order (dependencies first) |
| **Cycle Detection** | No built-in detection | Can detect cycles (final result size < V) |
| **Memory Usage** | Recursion stack + explicit stack | Queue + in-degree array |
| **Intuition** | "Finish children before parent" | "Process nodes with no dependencies" |

## Applications

- **Task Scheduling**: Execute tasks in dependency order
- **Course Prerequisites**: Take courses in correct sequence
- **Build Systems**: Compile modules in dependency order
- **Git Commit History**: Linearize branched history
- **Package Management**: Install dependencies first

## Summary

Both algorithms solve topological sorting with O(V + E) time complexity:

1. **DFS-based**: Uses recursion and stack, processes nodes in post-order
2. **Kahn's Algorithm**: Uses BFS with in-degree tracking, processes nodes with no dependencies first

The choice between them depends on specific requirements:
- Use **DFS** for simpler implementation and when recursion is acceptable
- Use **Kahn's** when you need explicit cycle detection or prefer iterative approaches


## DFS Algorithm Step-by-Step Walkthrough

**Input**: V = 6, edges = [[5,2], [5,0], [4,0], [4,1], [2,3], [3,1]]

### Step 1: Build Adjacency List
```
adj[0] = []
adj[1] = []
adj[2] = [3]
adj[3] = [1]
adj[4] = [0, 1]
adj[5] = [2, 0]
```

### Step 2: Initialize
- `visited = [false, false, false, false, false, false]`
- `stack = []` (empty)

### Step 3: Start DFS from Node 0
- Node 0: visited[0] = true, no neighbors, push 0 to stack
- `stack = [0]`
- `visited = [true, false, false, false, false, false]`

### Step 4: Start DFS from Node 1
- Node 1: visited[1] = true, no neighbors, push 1 to stack
- `stack = [0, 1]`
- `visited = [true, true, false, false, false, false]`

### Step 5: Start DFS from Node 2
- Node 2: visited[2] = true
- Visit neighbor 3:
  - Node 3: visited[3] = true
  - Visit neighbor 1: already visited
  - Push 3 to stack: `stack = [0, 1, 3]`
- Push 2 to stack: `stack = [0, 1, 3, 2]`
- `visited = [true, true, true, true, false, false]`

### Step 6: Start DFS from Node 4
- Node 4: visited[4] = true
- Visit neighbor 0: already visited
- Visit neighbor 1: already visited
- Push 4 to stack: `stack = [0, 1, 3, 2, 4]`
- `visited = [true, true, true, true, true, false]`

### Step 7: Start DFS from Node 5
- Node 5: visited[5] = true
- Visit neighbor 2: already visited
- Visit neighbor 0: already visited
- Push 5 to stack: `stack = [0, 1, 3, 2, 4, 5]`
- `visited = [true, true, true, true, true, true]`

### Step 8: Pop from Stack to Get Result
```
Pop 5 → ans = [5]
Pop 4 → ans = [5, 4]
Pop 2 → ans = [5, 4, 2]
Pop 3 → ans = [5, 4, 2, 3]
Pop 1 → ans = [5, 4, 2, 3, 1]
Pop 0 → ans = [5, 4, 2, 3, 1, 0]
```

**Final Result**: `[5, 4, 2, 3, 1, 0]`

### Visual Stack Operations
```
Step    Stack           Action
----    -----           ------
Start   []              Empty
After 0 [0]             Push 0
After 1 [0,1]           Push 1
After 3 [0,1,3]         Push 3 (from node 2's DFS)
After 2 [0,1,3,2]       Push 2
After 4 [0,1,3,2,4]     Push 4
After 5 [0,1,3,2,4,5]   Push 5
Pop     [0,1,3,2,4]     Pop 5 → result[0]
Pop     [0,1,3,2]       Pop 4 → result[1]
Pop     [0,1,3]         Pop 2 → result[2]
Pop     [0,1]           Pop 3 → result[3]
Pop     [0]             Pop 1 → result[4]
Pop     []              Pop 0 → result[5]
```

Both produce valid topological orderings, though the exact order may differ depending on the traversal sequence.

