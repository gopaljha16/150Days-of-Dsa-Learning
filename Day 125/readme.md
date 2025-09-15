# Prim's Algorithm - Minimum Spanning Tree Implementation

## Overview

This C++ code implements **Prim's Algorithm** to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. A Minimum Spanning Tree is a subset of edges that connects all vertices in the graph with the minimum possible total edge weight, without forming any cycles.

The algorithm uses a **greedy approach** with a **priority queue (min-heap)** to always select the edge with the smallest weight that connects a vertex not yet in the MST to a vertex already in the MST.

---

## Code Structure and Line-by-Line Explanation

### Function Signature
```cpp
int spanningTree(int V, vector<vector<int>>& edges)
```
- **Input**: `V` = number of vertices, `edges` = list of edges where each edge is `[u, v, weight]`
- **Output**: Total weight of the Minimum Spanning Tree

### Step 1: Build Adjacency List
```cpp
int n = edges.size();
vector<pair<int,int>>adj[V];
for(int i=0 ; i<n ; i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    
    adj[u].push_back({v , wt});
    adj[v].push_back({u , wt});
}
```
- **Purpose**: Convert edge list to adjacency list representation
- **Details**:
  - `adj[V]` creates an array of vectors (adjacency list for each vertex)
  - For each edge `[u, v, weight]`, we add bidirectional connections:
    - `adj[u]` gets `{v, weight}`
    - `adj[v]` gets `{u, weight}`

### Step 2: Initialize Data Structures
```cpp
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>p;
```
- **Min-Heap**: Stores `{weight, {node, parent}}` with smallest weight at top
- **Structure**: `pair<weight, pair<node, parent>>`

```cpp
vector<bool>IsMST(V ,0);
vector<int>parent(V);
int cost = 0;
```
- `IsMST[]`: Tracks which vertices are already in the MST
- `parent[]`: Stores the parent of each vertex in the MST
- `cost`: Accumulates total weight of MST

### Step 3: Start Algorithm
```cpp
p.push({0,{0,-1}});
```
- **Initial Push**: Start with vertex 0, weight 0, parent -1
- This makes vertex 0 the root of our MST

### Step 4: Main Algorithm Loop
```cpp
while(!p.empty()){
    int wt = p.top().first;
    int node = p.top().second.first;
    int par = p.top().second.second;
    p.pop();
    
    if(!IsMST[node]){
        IsMST[node] = 1;
        cost+=wt;
        parent[node] = par;
        
        // Add adjacent edges to priority queue
        for(int j=0 ; j<adj[node].size() ; j++){
            if(!IsMST[adj[node][j].first]){
                p.push({adj[node][j].second , {adj[node][j].first , node}});
            }
        }
    }
}
```

**Loop Breakdown**:
1. **Extract minimum**: Get the edge with minimum weight from priority queue
2. **Check if valid**: If the destination node is not in MST yet
3. **Add to MST**: Mark node as visited, add weight to cost, set parent
4. **Explore neighbors**: Add all edges from this node to unvisited nodes to priority queue

---

## Example Input and Expected Output

### Example 1
```cpp
V = 4
edges = {{0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}}
```

**Graph Representation**:
```
    0
   /|\
  / | \
 /  |  \
10  6   5
/   |    \
1---15----3
     \   /
      \ /
       4
      / \
     2---
```

**Expected Output**: `19` (edges: 0-3 weight 5, 2-3 weight 4, 0-1 weight 10)

---

## Step-by-Step Dry Run

Let's trace through the algorithm with the example above:

### Initial State
```
IsMST = [false, false, false, false]
cost = 0
Priority Queue: {0, {0, -1}}
```

### Iteration 1
- **Pop**: `{0, {0, -1}}`
- **Process**: Node 0, weight 0, parent -1
- **Action**: Add node 0 to MST
- **Update**: `IsMST[0] = true`, `cost = 0`, `parent[0] = -1`
- **Add neighbors**: 
  - `{10, {1, 0}}` (edge 0→1, weight 10)
  - `{6, {2, 0}}` (edge 0→2, weight 6) 
  - `{5, {3, 0}}` (edge 0→3, weight 5)

```
Priority Queue: {5, {3, 0}}, {6, {2, 0}}, {10, {1, 0}}
IsMST = [true, false, false, false]
```

### Iteration 2
- **Pop**: `{5, {3, 0}}` (minimum weight)
- **Process**: Node 3, weight 5, parent 0
- **Action**: Add node 3 to MST
- **Update**: `IsMST[3] = true`, `cost = 5`, `parent[3] = 0`
- **Add neighbors**: 
  - `{15, {1, 3}}` (edge 3→1, weight 15)
  - `{4, {2, 3}}` (edge 3→2, weight 4)

```
Priority Queue: {4, {2, 3}}, {6, {2, 0}}, {10, {1, 0}}, {15, {1, 3}}
IsMST = [true, false, false, true]
```

### Iteration 3
- **Pop**: `{4, {2, 3}}` (minimum weight)
- **Process**: Node 2, weight 4, parent 3
- **Action**: Add node 2 to MST
- **Update**: `IsMST[2] = true`, `cost = 9`, `parent[2] = 3`

```
Priority Queue: {6, {2, 0}}, {10, {1, 0}}, {15, {1, 3}}
IsMST = [true, false, true, true]
```

### Iteration 4
- **Pop**: `{6, {2, 0}}` 
- **Skip**: Node 2 already in MST (`IsMST[2] = true`)

### Iteration 5
- **Pop**: `{10, {1, 0}}`
- **Process**: Node 1, weight 10, parent 0
- **Action**: Add node 1 to MST
- **Update**: `IsMST[1] = true`, `cost = 19`, `parent[1] = 0`

```
Final: IsMST = [true, true, true, true]
Total Cost = 19
```

---

## Visual Diagram

### Algorithm Flow
```
Start → Choose arbitrary vertex (0)
  ↓
Add vertex 0 to MST
  ↓
Add all edges from vertex 0 to priority queue
  ↓
┌─────────────────────────────────────┐
│ While priority queue is not empty:  │
│  1. Pop minimum weight edge         │
│  2. If destination not in MST:      │
│     - Add to MST                    │
│     - Add cost to total             │
│     - Add adjacent edges to queue   │
└─────────────────────────────────────┘
  ↓
Return total cost
```

### MST Construction Process
```
Step 1: Start with vertex 0
  0
  
Step 2: Add cheapest edge (0→3, weight 5)
  0---5---3
  
Step 3: Add cheapest available edge (3→2, weight 4)
  0---5---3
          |
          4
          |
          2
          
Step 4: Add cheapest available edge (0→1, weight 10)
     1
     |
    10
     |
  0---5---3
          |
          4
          |
          2
```

---

## Time and Space Complexity

### Time Complexity: O(E log V)
- **Building adjacency list**: O(E)
- **Priority queue operations**: O(E log V)
- **Total**: O(E log V)

### Space Complexity: O(V + E)
- **Adjacency list**: O(V + E)
- **Priority queue**: O(E) in worst case
- **Additional arrays**: O(V)

---

## Key Points and Edge Cases

### Algorithm Properties
- **Greedy**: Always picks the minimum weight edge
- **Safe**: Never creates cycles
- **Optimal**: Produces minimum spanning tree

### Edge Cases Handled
1. **Disconnected Graph**: Algorithm handles only the connected component containing vertex 0
2. **Self-loops**: Ignored naturally since we check `!IsMST[node]`
3. **Duplicate Edges**: Priority queue may contain multiple paths to same node, but only first (cheapest) is processed

### Potential Issues in Code
1. **Graph connectivity**: Assumes graph is connected
2. **Vertex numbering**: Assumes vertices are numbered 0 to V-1
3. **Input validation**: No checks for invalid edge formats

---

## Summary

This implementation of Prim's Algorithm efficiently finds the Minimum Spanning Tree using a greedy approach with a priority queue. The algorithm:

1. **Starts** with an arbitrary vertex (vertex 0)
2. **Maintains** a priority queue of edges ordered by weight
3. **Iteratively** adds the minimum weight edge that connects an unvisited vertex
4. **Ensures** no cycles are formed by checking if vertices are already in the MST
5. **Returns** the total weight of the minimum spanning tree

The algorithm is particularly useful for network design problems, clustering, and finding the cheapest way to connect all nodes in a network.

**Final Result**: For the given example, the MST has edges (0-3), (3-2), and (0-1) with total weight **19**.