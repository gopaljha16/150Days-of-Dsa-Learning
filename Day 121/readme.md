# Floyd-Warshall Algorithm | Multi-Source Shortest Path Algorithm

## Overview

The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths between **all pairs of vertices** in a weighted graph. Unlike single-source shortest path algorithms (Dijkstra, Bellman-Ford), Floyd-Warshall computes the shortest distance from every vertex to every other vertex in one execution.

**Time Complexity:** O(V³)  
**Space Complexity:** O(V²)  
**Use Case:** Dense graphs, all-pairs shortest path problems

---

## Code Explanation

### Line-by-Line Analysis

```cpp
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
       int n = dist.size();                              // Line 1
        for(int k=0; k<n; k++){                          // Line 2
            for(int j =0; j<n; j++){                     // Line 3
                for(int i=0; i<n; i++){                  // Line 4
                    if(dist[j][k] != 1e8 && dist[k][i] != 1e8)  // Line 5
                    dist[j][i] = min(dist[j][i], dist[j][k]+dist[k][i]);  // Line 6
                }
            }
        }
    }
};
```

### Detailed Breakdown

- **Line 1:** `int n = dist.size();`
  - Gets the number of vertices in the graph
  - `dist` is a 2D adjacency matrix where `dist[i][j]` represents the distance from vertex `i` to vertex `j`

- **Line 2:** `for(int k=0; k<n; k++)`
  - **Outer loop:** Iterates through each vertex `k` as an **intermediate vertex**
  - This is the key insight: we try each vertex as a "stepping stone" between other vertices

- **Line 3:** `for(int j=0; j<n; j++)`
  - **Middle loop:** Iterates through each **source vertex** `j`

- **Line 4:** `for(int i=0; i<n; i++)`
  - **Inner loop:** Iterates through each **destination vertex** `i`

- **Line 5:** `if(dist[j][k] != 1e8 && dist[k][i] != 1e8)`
  - **Safety check:** Ensures both path segments exist (aren't infinity)
  - `1e8` represents infinity (unreachable vertices)

- **Line 6:** `dist[j][i] = min(dist[j][i], dist[j][k]+dist[k][i]);`
  - **Core logic:** Updates shortest path from `j` to `i` by comparing:
    - Direct path: `dist[j][i]`
    - Path via intermediate vertex `k`: `dist[j][k] + dist[k][i]`

---

## Algorithm Logic

The Floyd-Warshall algorithm works on this principle:

> **"If there's a shorter path from vertex A to vertex B through an intermediate vertex C, update the direct path A→B"**

### Mathematical Formula
```
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

Where `k` is the intermediate vertex being considered.

---

## Example Input and Expected Output

### Input Graph
```
    2
  A───→B
  │    │
4 │    │ 1
  │    │
  ↓    ↓
  C───→D
    3
```

### Initial Distance Matrix
```cpp
vector<vector<int>> dist = {
    {0,   2,   4,   1e8},  // From A: A→A=0, A→B=2, A→C=4, A→D=∞
    {1e8, 0,   1e8, 1  },  // From B: B→A=∞, B→B=0, B→C=∞, B→D=1
    {1e8, 1e8, 0,   3  },  // From C: C→A=∞, C→B=∞, C→C=0, C→D=3
    {1e8, 1e8, 1e8, 0  }   // From D: D→A=∞, D→B=∞, D→C=∞, D→D=0
};
```

### Expected Output (Final Distance Matrix)
```cpp
{
    {0, 2, 4, 3},  // A→A=0, A→B=2, A→C=4, A→D=3 (via B)
    {∞, 0, ∞, 1},  // B→A=∞, B→B=0, B→C=∞, B→D=1
    {∞, ∞, 0, 3},  // C→A=∞, C→B=∞, C→C=0, C→D=3
    {∞, ∞, ∞, 0}   // D→A=∞, D→B=∞, D→C=∞, D→D=0
}
```

---

## Step-by-Step Dry Run

Let's trace through the algorithm execution:

### Initial State
```
      A    B    C    D
  A [ 0    2    4    ∞ ]
  B [ ∞    0    ∞    1 ]
  C [ ∞    ∞    0    3 ]
  D [ ∞    ∞    ∞    0 ]
```

### Iteration k=0 (Using A as intermediate)
```
Checking paths via vertex A (index 0):
- B→D via A: dist[1][0] + dist[0][3] = ∞ + ∞ = ∞ (no change)
- C→B via A: dist[2][0] + dist[0][1] = ∞ + 2 = ∞ (no change)
- C→D via A: dist[2][0] + dist[0][3] = ∞ + ∞ = ∞ (no change)
- D→B via A: dist[3][0] + dist[0][1] = ∞ + 2 = ∞ (no change)
- D→C via A: dist[3][0] + dist[0][2] = ∞ + 4 = ∞ (no change)

Matrix after k=0: [No changes]
```

### Iteration k=1 (Using B as intermediate)
```
Checking paths via vertex B (index 1):
- A→D via B: dist[0][1] + dist[1][3] = 2 + 1 = 3
  Current A→D = ∞, New path = 3, Update: dist[0][3] = 3 ✓

Matrix after k=1:
      A    B    C    D
  A [ 0    2    4    3 ]  ← A→D updated!
  B [ ∞    0    ∞    1 ]
  C [ ∞    ∞    0    3 ]
  D [ ∞    ∞    ∞    0 ]
```

### Iteration k=2 (Using C as intermediate)
```
Checking paths via vertex C (index 2):
- No improvements possible since no vertices can reach C
Matrix after k=2: [No changes]
```

### Iteration k=3 (Using D as intermediate)
```
Checking paths via vertex D (index 3):
- No improvements possible since no vertices can reach other vertices via D
Matrix after k=3: [No changes]
```

### Final Result
```
      A    B    C    D
  A [ 0    2    4    3 ]
  B [ ∞    0    ∞    1 ]
  C [ ∞    ∞    0    3 ]
  D [ ∞    ∞    ∞    0 ]
```

---

## Visual Algorithm Flow

```
┌─────────────────────────────────────┐
│         Floyd-Warshall              │
│                                     │
│  For each intermediate vertex k:    │
│  ┌─────────────────────────────┐    │
│  │ For each source vertex j:   │    │
│  │ ┌─────────────────────────┐ │    │
│  │ │ For each dest vertex i: │ │    │
│  │ │                         │ │    │
│  │ │ Is j→k→i < j→i ?       │ │    │
│  │ │      │                  │ │    │
│  │ │      ├─YES─→ Update     │ │    │
│  │ │      └─NO──→ Keep old   │ │    │
│  │ └─────────────────────────┘ │    │
│  └─────────────────────────────┘    │
└─────────────────────────────────────┘
```

---

## Why Not Use Other Algorithms?

### vs. Dijkstra's Algorithm

| Aspect | Dijkstra | Floyd-Warshall |
|--------|----------|----------------|
| **Problem Type** | Single-source shortest path | All-pairs shortest path |
| **Time Complexity** | O((V+E) log V) with priority queue | O(V³) |
| **Edge Weights** | Non-negative only | Can handle negative (no negative cycles) |
| **Use Case** | When you need shortest paths from one vertex | When you need shortest paths between all pairs |

**Why not Dijkstra for all-pairs?**
- Running Dijkstra V times: O(V × (V+E) log V) = O(V³ log V) for dense graphs
- Floyd-Warshall: O(V³) - simpler and faster for dense graphs

### vs. Bellman-Ford Algorithm

| Aspect | Bellman-Ford | Floyd-Warshall |
|--------|--------------|----------------|
| **Problem Type** | Single-source shortest path | All-pairs shortest path |
| **Time Complexity** | O(VE) | O(V³) |
| **Negative Cycles** | Detects negative cycles | Assumes no negative cycles |
| **Edge Weights** | Handles negative weights | Handles negative weights |

**Why not Bellman-Ford for all-pairs?**
- Running Bellman-Ford V times: O(V × VE) = O(V²E)
- For dense graphs where E ≈ V², this becomes O(V⁴)
- Floyd-Warshall is O(V³) - more efficient

---

## Dense vs Sparse Graphs

### Dense Graphs (E ≈ V²)
- **Definition:** Graph with many edges relative to vertices
- **Edge count:** Close to maximum possible edges V(V-1)/2
- **Floyd-Warshall advantage:** O(V³) is optimal since we need to check all pairs anyway

```
Dense Graph Example (4 vertices, 6 edges):
A───B
│╲ ╱│
│ ╳ │
│╱ ╲│
C───D
```

### Sparse Graphs (E << V²)
- **Definition:** Graph with few edges relative to vertices
- **Edge count:** Much less than V²
- **Better alternatives:** Dijkstra run V times might be better: O(V × (V+E) log V)

```
Sparse Graph Example (4 vertices, 2 edges):
A───B

C───D
```

### When to Use Floyd-Warshall
✅ **Use when:**
- Dense graphs (many edges)
- Need all-pairs shortest paths
- Graph fits in memory
- Preprocessing for multiple queries

❌ **Don't use when:**
- Sparse graphs with specific source/destination queries
- Memory is limited (O(V²) space)
- Only need single-source shortest paths

---

## Real-World Example: Network Routing Table

### Scenario: Internet Router Network

Imagine a network of 4 routers that need to maintain routing tables:

```cpp
// Router network topology
//     10ms
//  R1 ───→ R2
//  │       │
//5ms│       │2ms
//  │       │
//  ↓       ↓
//  R3 ───→ R4
//     8ms

vector<vector<int>> routingTable = {
//   R1  R2  R3  R4
    {0,  10, 5,  ∞},   // From R1
    {∞,  0,  ∞, 2},    // From R2  
    {∞,  ∞,  0, 8},    // From R3
    {∞,  ∞,  ∞, 0}     // From R4
};
```

### After Floyd-Warshall Processing

```cpp
// Optimized routing table with best paths
vector<vector<int>> finalTable = {
//   R1  R2  R3  R4
    {0,  10, 5,  12},  // R1: R1→R4 via R2 (10+2=12ms)
    {∞,  0,  ∞, 2},   // R2: Direct paths only
    {∞,  ∞,  0, 8},   // R3: Direct paths only  
    {∞,  ∞,  ∞, 0}    // R4: Direct paths only
};
```

### Implementation for Routing Table

```cpp
class NetworkRouter {
private:
    vector<vector<int>> routingTable;
    vector<string> routerNames;
    
public:
    void updateRoutingTable() {
        floydWarshall(routingTable);
    }
    
    void printOptimalRoute(int source, int destination) {
        if (routingTable[source][destination] == 1e8) {
            cout << "No route available from " << routerNames[source] 
                 << " to " << routerNames[destination] << endl;
        } else {
            cout << "Optimal latency from " << routerNames[source] 
                 << " to " << routerNames[destination] << ": " 
                 << routingTable[source][destination] << "ms" << endl;
        }
    }
    
    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; j++) {
                for(int i = 0; i < n; i++) {
                    if(dist[j][k] != 1e8 && dist[k][i] != 1e8) {
                        dist[j][i] = min(dist[j][i], dist[j][k] + dist[k][i]);
                    }
                }
            }
        }
    }
};
```

---

## Summary

The Floyd-Warshall algorithm is a powerful dynamic programming solution for the all-pairs shortest path problem. Here are the key takeaways:

### ✅ Advantages
- Computes shortest paths between **all pairs** of vertices
- Handles **negative edge weights** (no negative cycles)
- Simple implementation with **O(V³)** time complexity
- Perfect for **dense graphs** and **preprocessing** scenarios
- Excellent for **routing tables** and **network analysis**

### ❌ Limitations  
- **O(V³)** can be slow for very large graphs
- **O(V²)** space complexity
- Cannot detect **negative cycles**
- Overkill for **single-source** problems

### 🎯 Best Use Cases
- **Dense graphs** where E ≈ V²
- **Network routing** and telecommunications
- **Game pathfinding** with multiple agents
- **Social network analysis**
- When you need **multiple shortest path queries**

### 🔄 Algorithm Variants
- **Path reconstruction:** Store predecessor matrix to rebuild actual paths
- **Negative cycle detection:** Check if dist[i][i] < 0 after algorithm
- **Transitive closure:** Use boolean matrix to find reachability

The Floyd-Warshall algorithm exemplifies the power of dynamic programming in graph theory, providing an elegant solution to a complex problem through systematic exploration of intermediate vertices.