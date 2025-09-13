# Euler Path and Euler Circuit in a Graph

## Overview

This C++ code determines whether a given undirected graph contains an **Euler Circuit** or an **Euler Path**. An Euler Circuit is a path that visits every edge exactly once and returns to the starting vertex, while an Euler Path visits every edge exactly once but doesn't necessarily return to the starting point.

**Real-life Applications:**
- **Mail delivery routes**: Postal workers need to traverse every street exactly once
- **Snow plow routes**: City planning for efficient snow removal
- **Circuit board design**: Designing paths that visit all connections
- **Tourist route planning**: Visiting all attractions with minimal backtracking

## Key Concepts

### Euler's Theorems:
1. **Euler Circuit exists** if and only if:
   - All vertices have even degree
   - All vertices with non-zero degree are connected

2. **Euler Path exists** if and only if:
   - Exactly 0 or 2 vertices have odd degree
   - All vertices with non-zero degree are connected

## Code Breakdown

### 1. DFS Function
```cpp
void DFS(int node, vector<int>adj[], vector<bool>&visited){
    visited[node] = 1;  // Mark current node as visited
    
    // Visit all adjacent unvisited nodes
    for(int i=0; i<adj[node].size(); i++){
        if(!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited);
    }
}
```

**Purpose**: Performs Depth-First Search to check connectivity of the graph.

### 2. Main Algorithm - isEulerCircuit Function

#### Step 1: Calculate Degrees
```cpp
vector<int>Deg(V,0);
int odd_deg = 0;
for(int i=0; i<V; i++){
    Deg[i] = adj[i].size();  // Count edges for each vertex
    
    if(Deg[i]%2)
        odd_deg++;  // Count vertices with odd degree
}
```

#### Step 2: Check Degree Condition
```cpp
if(odd_deg!=2 && odd_deg!=0)
    return 0;  // Neither Euler Circuit nor Path exists
```

#### Step 3: Check Connectivity
```cpp
vector<bool>visited(V,0);
for(int i=0; i<V; i++){
    if(Deg[i]){ // Start DFS from first vertex with non-zero degree
        DFS(i, adj, visited);
        break;
    }
}

// Check if all vertices with edges are connected
for(int i=0; i<V; i++){
    if(Deg[i] && !visited[i])
        return 0;  // Graph is not connected
}
```

#### Step 4: Determine Result
```cpp
if(odd_deg==0)
    return 2;  // Euler Circuit exists
else
    return 1;  // Euler Path exists
```

## Return Values
- **0**: Neither Euler Circuit nor Euler Path exists
- **1**: Euler Path exists (but not Euler Circuit)
- **2**: Euler Circuit exists

## Example Walkthrough

### Example 1: Euler Circuit
```
Graph with 4 vertices:
0 -- 1
|    |
3 -- 2

Adjacency List:
0: [1, 3]
1: [0, 2] 
2: [1, 3]
3: [0, 2]
```

**Step-by-step execution:**

1. **Calculate degrees:**
   - Vertex 0: degree = 2 (even)
   - Vertex 1: degree = 2 (even)
   - Vertex 2: degree = 2 (even)
   - Vertex 3: degree = 2 (even)
   - `odd_deg = 0`

2. **Check degree condition:**
   - `odd_deg = 0` ✓ (satisfies condition)

3. **Check connectivity:**
   - Start DFS from vertex 0
   - Visit: 0 → 1 → 2 → 3
   - All vertices with edges are visited ✓

4. **Result:** Return 2 (Euler Circuit exists)

### Example 2: Euler Path
```
Graph with 4 vertices:
0 -- 1 -- 2
     |
     3

Adjacency List:
0: [1]
1: [0, 2, 3]
2: [1]
3: [1]
```

**Step-by-step execution:**

1. **Calculate degrees:**
   - Vertex 0: degree = 1 (odd)
   - Vertex 1: degree = 3 (odd)
   - Vertex 2: degree = 1 (odd) 
   - Vertex 3: degree = 1 (odd)
   - `odd_deg = 4`

2. **Check degree condition:**
   - `odd_deg = 4` ≠ 0 and ≠ 2
   - Return 0 (Neither exists)

### Example 3: Valid Euler Path
```
Graph with 3 vertices:
0 -- 1 -- 2

Adjacency List:
0: [1]
1: [0, 2]
2: [1]
```

**Step-by-step execution:**

1. **Calculate degrees:**
   - Vertex 0: degree = 1 (odd)
   - Vertex 1: degree = 2 (even)
   - Vertex 2: degree = 1 (odd)
   - `odd_deg = 2`

2. **Check degree condition:**
   - `odd_deg = 2` ✓ (satisfies condition)

3. **Check connectivity:**
   - Start DFS from vertex 0
   - Visit: 0 → 1 → 2
   - All vertices with edges are visited ✓

4. **Result:** Return 1 (Euler Path exists)

## Visual Representation

```
Degree Analysis Table:
┌────────┬────────────┬─────────────┬──────────────────┐
│ Odd    │ Connected  │ Result      │ Interpretation   │
│ Degree │ Component  │ Code        │                  │
├────────┼────────────┼─────────────┼──────────────────┤
│   0    │    Yes     │     2       │ Euler Circuit    │
│   2    │    Yes     │     1       │ Euler Path       │
│  Other │    Any     │     0       │ Neither          │
│  Any   │    No      │     0       │ Neither          │
└────────┴────────────┴─────────────┴──────────────────┘
```

## Algorithm Flow Chart

```
Start
  ↓
Calculate degree of each vertex
  ↓
Count odd degree vertices
  ↓
odd_deg ≠ 0 and odd_deg ≠ 2? → Yes → Return 0
  ↓ No
Perform DFS from first non-zero degree vertex
  ↓
All non-zero degree vertices visited? → No → Return 0
  ↓ Yes
odd_deg == 0? → Yes → Return 2 (Euler Circuit)
  ↓ No
Return 1 (Euler Path)
```

## Time and Space Complexity

- **Time Complexity:** O(V + E)
  - O(V) for calculating degrees
  - O(V + E) for DFS traversal
  
- **Space Complexity:** O(V)
  - O(V) for visited array
  - O(V) for degree array
  - O(V) for recursion stack in worst case

## Real-World Examples

### 1. **Seven Bridges of Königsberg**
The classic problem that inspired Euler's work:
- **Scenario**: Can you cross all 7 bridges exactly once?
- **Answer**: No, because there are 4 vertices with odd degree

### 2. **Mail Delivery Route**
- **Scenario**: Postman wants to traverse every street exactly once
- **Solution**: Check if Euler Path/Circuit exists in the street network

### 3. **House Drawing Puzzle**
- **Scenario**: Draw a house without lifting the pen and without retracing lines
- **Solution**: The house graph must have 0 or 2 odd-degree vertices

## Summary

This algorithm efficiently determines the existence of Euler Paths and Circuits by:

1. **Checking degree conditions** based on Euler's theorems
2. **Verifying graph connectivity** using DFS
3. **Returning appropriate codes** based on the analysis

The solution handles the fundamental graph theory problem with optimal time complexity and provides a solid foundation for solving routing and traversal problems in various domains.