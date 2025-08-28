# Cycle Detection in Undirected Graph using DFS and BFS

## Overview

This code implements two different algorithms to detect cycles in an undirected graph:
1. **Depth-First Search (DFS)** approach using recursion
2. **Breadth-First Search (BFS)** approach using a queue

Both algorithms traverse the graph while keeping track of visited nodes and their parent nodes. A cycle is detected when we encounter a visited node that is not the parent of the current node.

## Table of Contents

- [DFS Solution](#dfs-solution)
- [BFS Solution](#bfs-solution)
- [Example Usage](#example-usage)
- [Step-by-Step Walkthrough](#step-by-step-walkthrough)
- [Visual Diagrams](#visual-diagrams)
- [Time and Space Complexity](#time-and-space-complexity)
- [Summary](#summary)

## DFS Solution

### Code Structure

```cpp
class Solution {
public:
    bool CycleDetect(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = 1;  // Mark current node as visited
        
        // Check all neighbors of the current node
        for(int i = 0; i < adj[node].size(); i++) {
            // Skip if neighbor is the parent (came from this node)
            if(parent == adj[node][i])
                continue;
            
            // If neighbor is already visited and not parent, cycle found
            if(visited[adj[node][i]]) {
                return 1;  // Cycle detected
            }
            
            // Recursively check the neighbor
            if(CycleDetect(adj[node][i], node, adj, visited))
                return 1;
        }
        
        return 0;  // No cycle found in this path
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }
        
        vector<bool> visited(V, 0);  // Initialize all as unvisited
        
        // Check each unvisited node (handles disconnected components)
        for(int i = 0; i < V; i++) {
            if(!visited[i] && CycleDetect(i, -1, adj, visited))
                return 1;  // Cycle found
        }
        
        return 0;  // No cycle in entire graph
    }
};
```

### DFS Algorithm Explanation

1. **Graph Construction**: Build adjacency list from edge list
2. **Initialization**: Create visited array, all nodes initially unvisited
3. **Component Traversal**: For each unvisited node, start DFS
4. **DFS Logic**:
   - Mark current node as visited
   - For each neighbor:
     - Skip if it's the parent node
     - If neighbor is visited (and not parent), cycle detected
     - Otherwise, recursively check the neighbor

## BFS Solution

### Code Structure

```cpp
class Solution {
public:
    bool BFS(int vertex, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q;  // Store (node, parent) pairs
        visited[vertex] = 1;      // Mark starting node as visited
        q.push(make_pair(vertex, -1));  // Push with no parent (-1)
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            // Check all neighbors of current node
            for(int i = 0; i < adj[node].size(); i++) {
                // Skip if neighbor is the parent
                if(parent == adj[node][i])
                    continue;
                
                // If neighbor already visited, cycle detected
                if(visited[adj[node][i]])
                    return 1;
                
                // Mark neighbor as visited and add to queue
                visited[adj[node][i]] = 1;
                q.push(make_pair(adj[node][i], node));
            }
        }
        
        return 0;  // No cycle found
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, 0);
        
        // Check each unvisited component
        for(int i = 0; i < V; i++) {
            if(!visited[i] && BFS(i, adj, visited))
                return 1;
        }
        
        return 0;
    }
};
```

### BFS Algorithm Explanation

1. **Queue-based Traversal**: Use queue to store (node, parent) pairs
2. **Level-by-level Processing**: Process all neighbors before moving deeper
3. **Cycle Detection**: Same logic as DFS - visited neighbor that's not parent indicates cycle

## Example Usage

### Input Format
```cpp
// Example 1: Graph with cycle
int V = 4;  // 4 vertices (0, 1, 2, 3)
vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

// Example 2: Graph without cycle (tree)
int V = 4;  // 4 vertices (0, 1, 2, 3)
vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
```

### Expected Output
```cpp
// Example 1: true (cycle exists: 0 -> 1 -> 2 -> 3 -> 0)
// Example 2: false (no cycle, it's a tree)
```

## Step-by-Step Walkthrough

Let's trace through **Example 1** using **DFS**:

### Initial State
```
Graph: 0 - 1 - 2 - 3 - 0 (forms a square)
Adjacency List:
0: [1, 3]
1: [0, 2]  
2: [1, 3]
3: [2, 0]

visited = [false, false, false, false]
```

### DFS Execution

| Step | Current Node | Parent | Action | visited Array | Notes |
|------|--------------|--------|---------|---------------|-------|
| 1 | 0 | -1 | Mark 0 visited | [T, F, F, F] | Start DFS from node 0 |
| 2 | 0 | -1 | Check neighbor 1 | [T, F, F, F] | 1 not visited, recurse |
| 3 | 1 | 0 | Mark 1 visited | [T, T, F, F] | Now at node 1 |
| 4 | 1 | 0 | Skip neighbor 0 | [T, T, F, F] | 0 is parent, skip |
| 5 | 1 | 0 | Check neighbor 2 | [T, T, F, F] | 2 not visited, recurse |
| 6 | 2 | 1 | Mark 2 visited | [T, T, T, F] | Now at node 2 |
| 7 | 2 | 1 | Skip neighbor 1 | [T, T, T, F] | 1 is parent, skip |
| 8 | 2 | 1 | Check neighbor 3 | [T, T, T, F] | 3 not visited, recurse |
| 9 | 3 | 2 | Mark 3 visited | [T, T, T, T] | Now at node 3 |
| 10 | 3 | 2 | Skip neighbor 2 | [T, T, T, T] | 2 is parent, skip |
| 11 | 3 | 2 | Check neighbor 0 | [T, T, T, T] | **0 is visited but not parent!** |
| 12 | - | - | **CYCLE DETECTED** | [T, T, T, T] | Return true |

## Visual Diagrams

### Graph Structure (Example 1)
```
    0 ———————— 1
    |          |
    |          |
    |          |
    3 ———————— 2

Cycle path: 0 → 1 → 2 → 3 → 0
```

### DFS Traversal Tree
```
    0 (start)
    │
    1 (from 0)
    │
    2 (from 1)
    │
    3 (from 2)
    │
    0 (already visited!) ← CYCLE DETECTED
```

### BFS Level-by-Level Processing
```
Level 0: [0] (parent: -1)
Level 1: [1, 3] (parent: 0)
Level 2: [2] (from 1, parent: 1)
         When processing 3's neighbors: 0 is already visited! ← CYCLE
```

### Algorithm Flow Chart

```
┌─────────────┐
│   START     │
└─────┬───────┘
      │
┌─────▼───────┐
│Build Adj List│
└─────┬───────┘
      │
┌─────▼───────┐
│Initialize   │
│visited[]    │
└─────┬───────┘
      │
┌─────▼───────┐
│For each     │
│unvisited    │
│vertex       │
└─────┬───────┘
      │
┌─────▼───────┐
│Start DFS/BFS│
│from vertex  │
└─────┬───────┘
      │
┌─────▼───────┐    YES   ┌─────────────┐
│Visited      │────────▶│Return TRUE  │
│neighbor     │         │(Cycle Found)│
│!= parent?   │         └─────────────┘
└─────┬───────┘
      │ NO
┌─────▼───────┐
│Continue     │
│traversal    │
└─────┬───────┘
      │
┌─────▼───────┐
│All vertices │
│checked?     │
└─────┬───────┘
      │ YES
┌─────▼───────┐
│Return FALSE │
│(No Cycle)   │
└─────────────┘
```

## Time and Space Complexity

### Time Complexity
- **DFS**: O(V + E)
  - Visit each vertex once: O(V)
  - Examine each edge twice (once from each endpoint): O(E)
- **BFS**: O(V + E)
  - Same reasoning as DFS

### Space Complexity
- **DFS**: O(V)
  - Adjacency list: O(V + E)
  - Visited array: O(V)
  - Recursion stack: O(V) in worst case
- **BFS**: O(V)
  - Adjacency list: O(V + E)
  - Visited array: O(V)  
  - Queue: O(V) in worst case

Where V = number of vertices, E = number of edges

## Key Insights

### Why Track Parent?
In undirected graphs, if we go from A to B, then B will have A as a neighbor. Without tracking the parent, we'd immediately detect a "false cycle" when we see that A is visited.

### Example of Parent Tracking:
```
Path: 0 → 1 → 2
At node 1: neighbors are [0, 2]
- Skip 0 (it's the parent)
- Process 2 (not visited yet)
```

### Handling Disconnected Components
Both algorithms use a loop to check all vertices because the graph might have multiple disconnected components:

```
Component 1: 0 - 1    Component 2: 2 - 3 - 4
                                   └─────┘
                                   (cycle)
```

## Summary

Both DFS and BFS approaches effectively detect cycles in undirected graphs with the same time complexity O(V + E). 

**Key Points:**
- **DFS**: Uses recursion, more intuitive for tree-like thinking
- **BFS**: Uses queue, processes level by level
- **Parent Tracking**: Essential to avoid false positives in undirected graphs
- **Component Handling**: Loop through all vertices to handle disconnected graphs
- **Cycle Detection**: Occurs when we visit a node that's already visited but isn't our parent

The choice between DFS and BFS often comes down to preference, though DFS might be slightly more memory-efficient due to not storing parent information explicitly in the recursion (it's implicit in the call stack).