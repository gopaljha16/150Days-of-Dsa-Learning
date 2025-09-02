# Bipartite Graph Detection Algorithm

## Overview

A **Bipartite Graph** is a graph whose vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. In other words, all edges connect vertices from one set to vertices in the other set. This code implements two approaches (BFS and DFS) to determine if a given graph is bipartite by using a 2-coloring technique.

**Key Concept**: A graph is bipartite if and only if it can be colored using exactly 2 colors such that no two adjacent vertices have the same color.

---

## Algorithm Approaches

### 1. BFS (Breadth-First Search) Approach

```cpp
class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list from edge list
        vector<vector<int>>adj(V);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Step 2: Initialize color array (-1 = uncolored)
        vector<int>color(V , -1);
        queue<int>q; 
        
        // Step 3: Handle disconnected components
        for(int i=0 ; i<V ; i++){
            if(color[i]==-1){ // If vertex is uncolored
                q.push(i);
                color[i] = 0; // Start coloring with 0
                
                // BFS traversal
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    // Check all adjacent vertices
                    for(int j=0 ; j<adj[node].size() ; j++){
                        
                        // If neighbor is uncolored
                        if(color[adj[node][j]]==-1){
                            color[adj[node][j]] = (color[node]+1)%2; // Alternate color
                            q.push(adj[node][j]);
                        }
                        else{ // If neighbor is already colored
                            // Check if same color as current node
                            if(color[node]==color[adj[node][j]]){
                                return 0; // Not bipartite
                            }
                        }
                    }
                }
            }
        }
        return 1; // Bipartite
    }
};
```

### 2. DFS (Depth-First Search) Approach

```cpp
class Solution {
public:
    bool DFS(int node, vector<vector<int>>&adj, vector<int>&color){
        // Check all adjacent vertices
        for(int j=0; j<adj[node].size(); j++){
            // If neighbor is uncolored
            if(color[adj[node][j]]==-1){
                color[adj[node][j]] = (color[node]+1)%2; // Alternate color
                
                // Recursive call
                if(!DFS(adj[node][j], adj, color))
                    return false;
            }
            else{
                // If neighbor has same color
                if(color[node]==color[adj[node][j]])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>>adj(V);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(V, -1);
        
        // Handle disconnected components
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                color[i] = 0; // Start with color 0
                if(!DFS(i, adj, color))
                    return 0;
            }
        }
        return 1;
    }
};
```

---

## Step-by-Step Code Explanation

### BFS Approach Breakdown:

1. **Adjacency List Construction**:
   - Convert edge list to adjacency list representation
   - Each edge `(u,v)` adds `v` to `adj[u]` and `u` to `adj[v]`

2. **Color Initialization**:
   - `color[i] = -1`: Uncolored
   - `color[i] = 0`: Color 0 (e.g., Red)
   - `color[i] = 1`: Color 1 (e.g., Blue)

3. **Component Iteration**:
   - Loop through all vertices to handle disconnected graphs
   - For each uncolored vertex, start BFS

4. **BFS Coloring**:
   - Color starting vertex with 0
   - For each neighbor: assign opposite color using `(color[node]+1)%2`
   - If neighbor already colored, check for conflict

5. **Conflict Detection**:
   - If adjacent vertices have same color → Not bipartite

---

## Example Input and Expected Output

### Example 1: Bipartite Graph
```
Input: V = 4, edges = [[0,1], [1,2], [2,3], [3,0]]
Output: 1 (True - is bipartite)
```

### Example 2: Non-Bipartite Graph  
```
Input: V = 3, edges = [[0,1], [1,2], [2,0]]
Output: 0 (False - not bipartite)
```

---

## Dry Run Walkthrough

Let's trace through **Example 1** using BFS:

**Input**: V = 4, edges = [[0,1], [1,2], [2,3], [3,0]]

### Step 1: Build Adjacency List
```
adj[0] = [1, 3]
adj[1] = [0, 2] 
adj[2] = [1, 3]
adj[3] = [2, 0]
```

### Step 2: Initialize
```
color = [-1, -1, -1, -1]
queue = empty
```

### Step 3: Start BFS from vertex 0
```
i = 0, color[0] = -1 (uncolored)
queue.push(0)
color[0] = 0
```

### Step 4: BFS Iteration

| Iteration | Queue | Current Node | Action | Color Array |
|-----------|--------|--------------|---------|-------------|
| 1 | [0] | 0 | Color neighbors 1,3 | [0, 1, -1, 1] |
| 2 | [1, 3] | 1 | Color neighbor 2 | [0, 1, 0, 1] |
| 3 | [3, 2] | 3 | Check neighbors (no conflicts) | [0, 1, 0, 1] |
| 4 | [2] | 2 | Check neighbors (no conflicts) | [0, 1, 0, 1] |

### Visual Representation
```
    0 (Color 0) ---- 1 (Color 1)
    |                |
    |                |
    3 (Color 1) ---- 2 (Color 0)
```

**Result**: No conflicts found → Graph is bipartite ✅

---

## Time and Space Complexity

| Approach | Time Complexity | Space Complexity |
|----------|----------------|------------------|
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |

Where:
- V = Number of vertices
- E = Number of edges

---

## Algorithm Flowchart

```
    Start
      |
   Build Adj List
      |
   Initialize Colors
      |
   For each vertex i
      |
   Is color[i] == -1?
    /             \
  Yes              No
   |               |
Start BFS/DFS   Continue
   |
Color vertex i = 0
   |
Process neighbors
   |
Neighbor uncolored?
  /              \
Yes               No
 |                |
Color opposite    Same color?
 |               /           \
Continue        Yes           No
                 |            |
              Return False  Continue
                            |
                      All processed?
                       /         \
                     Yes          No
                      |           |
                Return True    Continue
```

---

## Real-World Applications

### 1. Recommendation Systems

**Problem**: Separate users and items into two distinct sets.

**Example**: Movie recommendation system
- Set A: Users {Alice, Bob, Charlie}
- Set B: Movies {Titanic, Avatar, Inception}
- Edges: User-Movie preferences

**Bipartite Nature**: Users only connect to movies, never to other users directly.

```
Alice ---- Titanic
  |          |
  |        Avatar  
Bob --------  |
  |          |
Charlie -- Inception
```

**Applications**:
- Netflix user-movie recommendations
- Amazon customer-product suggestions
- LinkedIn job-candidate matching

### 2. Stable Marriage Problem

**Problem**: Match two groups optimally (e.g., medical students to hospitals).

**Bipartite Structure**:
- Set A: Medical students
- Set B: Hospitals
- Edges: Preference rankings

**Algorithm Usage**:
1. Model as bipartite graph
2. Apply matching algorithms (Hungarian, Gale-Shapley)
3. Find stable marriages/assignments

**Real Examples**:
- Medical residency matching (NRMP)
- College admissions
- Job placement systems

### 3. Other Applications

| Domain | Set A | Set B | Use Case |
|--------|-------|-------|----------|
| Social Networks | Users | Groups | Group membership |
| Scheduling | Tasks | Time Slots | Resource allocation |
| Biology | Genes | Diseases | Gene-disease associations |
| Web | Web pages | Keywords | SEO optimization |

---

## Key Insights

1. **2-Coloring Property**: A graph is bipartite iff it's 2-colorable
2. **Odd Cycles**: Graphs with odd-length cycles are NOT bipartite
3. **Even Cycles**: All even-length cycles are bipartite
4. **Trees**: All trees are bipartite (no cycles)
5. **Complete Graphs**: Only K₁ and K₂ are bipartite

---

## Summary

This implementation provides two efficient algorithms to detect bipartite graphs:

- **BFS Approach**: Level-by-level traversal with queue
- **DFS Approach**: Recursive depth exploration

Both algorithms use the 2-coloring technique with O(V + E) time complexity. The key insight is that a graph is bipartite if and only if it contains no odd-length cycles, which is detected by attempting to color the graph with exactly two colors.

**When to use**:
- BFS: When you need level-by-level processing
- DFS: When you prefer recursive solutions or have space constraints

The algorithm handles disconnected graphs by checking all components, making it robust for real-world applications like recommendation systems and matching problems.