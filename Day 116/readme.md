# Shortest Path in Undirected Graph using BFS

## Overview

This code demonstrates two different approaches to finding shortest paths in unweighted, undirected graphs using **Breadth-First Search (BFS)**:

1. **Solution 1**: Finds shortest distances from a source node to all other nodes
2. **Solution 2**: Finds the actual shortest path between two specific nodes (source to destination)

Both solutions leverage the property that BFS explores nodes level by level, guaranteeing that the first time we reach any node, we've found the shortest path to it.

---

## Solution 1: Shortest Distance to All Nodes

### Code Explanation

```cpp
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();        // Number of nodes in the graph
        int m = adj[0].size();     // Note: This line seems incorrect for adjacency list
        
        vector<int> dist(n, -1);     // Distance array, -1 means unreachable
        vector<int> visited(n, 0);   // Visited array, 0 = unvisited, 1 = visited
        
        queue<int> q;               // BFS queue
        q.push(src);               // Start from source node
        dist[src] = 0;             // Distance from source to itself is 0
        visited[src] = 1;          // Mark source as visited
        
        while(!q.empty()) {
            int node = q.front();   // Get front node from queue
            q.pop();               // Remove it from queue
            
            // Explore all adjacent nodes
            for(int j = 0; j < adj[node].size(); j++) {
                if(visited[adj[node][j]])  // Skip if already visited
                    continue;
                
                visited[adj[node][j]] = 1;           // Mark as visited
                q.push(adj[node][j]);               // Add to queue
                dist[adj[node][j]] = dist[node] + 1; // Update distance
            }
        }
        
        return dist;
    }
};
```

### Key Points:
- **Time Complexity**: O(V + E) where V = vertices, E = edges
- **Space Complexity**: O(V) for queue, visited array, and distance array
- Returns `-1` for unreachable nodes

---

## Solution 2: Shortest Path Between Two Specific Nodes

### Code Explanation

```cpp
vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int src, int dest) {
    // Build adjacency list from edge list
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        // Convert to 0-based indexing and add bidirectional edges
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
        adj[edges[i].second - 1].push_back(edges[i].first - 1);
    }

    src--; dest--;  // Convert to 0-based indexing
    
    vector<int> visited(n, 0);    // Visited tracking
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    
    vector<int> parent(n, -1);    // Parent tracking for path reconstruction
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++) {
            if(visited[adj[node][i]]) 
                continue;
            
            visited[adj[node][i]] = 1;
            q.push(adj[node][i]);
            parent[adj[node][i]] = node;  // Set parent for path reconstruction
        }
    }
    
    // Reconstruct path from dest to src using parent array
    vector<int> path;
    while(dest != -1) {
        path.push_back(dest + 1);  // Convert back to 1-based indexing
        dest = parent[dest];
    }
    
    reverse(path.begin(), path.end());  // Reverse to get src→dest path
    return path;
}
```

---

## Example Input and Output

### Example 1 (Solution 1):
```
Graph representation (adjacency list):
0: [1, 2]
1: [0, 3]
2: [0, 3]
3: [1, 2]

Source: 0
```

**Expected Output**: `[0, 1, 1, 2]`
- Distance from 0 to 0: 0
- Distance from 0 to 1: 1
- Distance from 0 to 2: 1  
- Distance from 0 to 3: 2

### Example 2 (Solution 2):
```
Edges: [(1,2), (2,3), (1,4), (4,5)]
n = 5, m = 4
Source: 1, Destination: 3
```

**Expected Output**: `[1, 2, 3]`

---

## Step-by-Step Dry Run (Solution 1)

Let's trace through Example 1:

### Initial State:
```
Graph:    0 --- 1
          |     |
          2 --- 3

dist = [-1, -1, -1, -1]
visited = [0, 0, 0, 0]
queue = [0]
src = 0
```

### Step-by-step execution:

| Step | Queue | Current Node | Adjacent Nodes | Updates | dist | visited |
|------|-------|--------------|----------------|---------|------|---------|
| 1 | [0] | - | - | dist[0]=0, visited[0]=1 | [0,-1,-1,-1] | [1,0,0,0] |
| 2 | [] | 0 | [1,2] | Process node 1,2 | [0,1,1,-1] | [1,1,1,0] |
| 3 | [1,2] | 1 | [0,3] | Skip 0, process 3 | [0,1,1,2] | [1,1,1,1] |
| 4 | [2,3] | 2 | [0,3] | Skip both (visited) | [0,1,1,2] | [1,1,1,1] |
| 5 | [3] | 3 | [1,2] | Skip both (visited) | [0,1,1,2] | [1,1,1,1] |
| 6 | [] | - | - | Queue empty, done | [0,1,1,2] | [1,1,1,1] |

### Visual Representation:
```
Level 0: [0] (distance 0)
Level 1: [1, 2] (distance 1)  
Level 2: [3] (distance 2)
```

---

## Algorithm Flow Diagram

```
START
  ↓
Initialize: dist[], visited[], queue
  ↓
Add source to queue, mark visited
  ↓
┌─────────────────────┐
│   Queue empty?      │ ──YES──→ RETURN dist[]
└─────────────────────┘
  ↓ NO
┌─────────────────────┐
│ current = queue.pop │
└─────────────────────┘
  ↓
┌─────────────────────────┐
│ For each neighbor of    │
│ current:                │
│   if not visited:       │
│     mark visited        │
│     add to queue        │
│     update distance     │
└─────────────────────────┘
  ↓
Go back to "Queue empty?" check
```

---

## Key Differences Between Solutions

| Aspect | Solution 1 | Solution 2 |
|--------|------------|------------|
| **Input Format** | Adjacency list | Edge list |
| **Output** | Distance to all nodes | Actual path |
| **Extra Data Structure** | Distance array | Parent array |
| **Path Reconstruction** | Not needed | Backtrack using parent array |
| **Use Case** | Single-source shortest distances | Point-to-point path finding |

---

## Time and Space Complexity

| Solution | Time Complexity | Space Complexity |
|----------|----------------|------------------|
| Solution 1 | O(V + E) | O(V) |
| Solution 2 | O(V + E) | O(V) |

Where:
- V = number of vertices
- E = number of edges

---

## Summary

Both solutions implement **BFS-based shortest path algorithms** for unweighted, undirected graphs:

- **Solution 1** efficiently computes shortest distances from a source to all reachable nodes
- **Solution 2** finds the actual shortest path between two specific nodes by maintaining parent pointers

The key insight is that BFS naturally finds shortest paths in unweighted graphs because it explores nodes in order of increasing distance from the source. Both solutions are optimal for their respective use cases and demonstrate fundamental graph traversal techniques.

**Note**: There's a minor issue in Solution 1 where `int m = adj[0].size()` should be removed as it's not used and could cause errors for empty adjacency lists.