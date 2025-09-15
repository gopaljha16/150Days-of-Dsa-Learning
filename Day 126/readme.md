# Kruskal's Algorithm Implementation Guide

## Complete Implementation with Union by Rank

```cpp
class Solution {
public:
    // Find operation with Path Compression
    int FindParent(int u, vector<int>& parent) {
        if (u == parent[u]) {  // Base case: u is its own parent
            return u;
        }
        
        // Path compression: make u directly point to root
        return parent[u] = FindParent(parent[u], parent);
    }
    
    // Union by Rank operation
    void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
        // Find ultimate parents
        int pu = FindParent(u, parent);
        int pv = FindParent(v, parent);
        
        // Merge smaller rank tree under larger rank tree
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;  // Make pu parent of pv
        }
        else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;  // Make pv parent of pu  
        }
        else {
            // Equal ranks: make one parent and increment rank
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Initialize DSU
        vector<int> parent(V);
        vector<int> rank(V, 0);
        
        for (int i = 0; i < V; i++) {
            parent[i] = i;  // Each node is its own parent initially
        }
        
        // Step 2: Create edge list with weights
        vector<pair<int, pair<int, int>>> edgeList;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1]; 
            int wt = edges[i][2];
            edgeList.push_back({wt, {u, v}});
        }
        
        // Step 3: Sort edges by weight
        sort(edgeList.begin(), edgeList.end());
        
        // Step 4: Process edges in sorted order
        int cost = 0, edgeCount = 0;
        
        for (auto& edge : edgeList) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            // Check if adding this edge creates a cycle
            if (FindParent(u, parent) != FindParent(v, parent)) {
                cost += wt;  // Add to MST cost
                unionByRank(u, v, parent, rank);  // Merge components
                edgeCount++;
                
                // MST complete when we have V-1 edges
                if (edgeCount == V - 1) break;
            }
        }
        
        return cost;
    }
};
```

## Alternative Implementation: Union by Size

```cpp
class Solution {
public:
    int FindParent(int u, vector<int>& parent) {
        if (u == parent[u]) return u;
        return parent[u] = FindParent(parent[u], parent);
    }
    
    // Union by Size - attach smaller tree under larger tree
    void unionBySize(int u, int v, vector<int>& parent, vector<int>& size) {
        int pu = FindParent(u, parent);
        int pv = FindParent(v, parent);
        
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];  // Update size
        }
        else {
            parent[pu] = pv;
            size[pv] += size[pu];  // Update size
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int> parent(V);
        vector<int> size(V, 1);  // Initialize size to 1
        
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        // Create and sort edge list
        vector<pair<int, pair<int, int>>> edgeList;
        for (auto& edge : edges) {
            edgeList.push_back({edge[2], {edge[0], edge[1]}});
        }
        sort(edgeList.begin(), edgeList.end());
        
        int cost = 0, edgeCount = 0;
        
        for (auto& edge : edgeList) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if (FindParent(u, parent) != FindParent(v, parent)) {
                cost += wt;
                unionBySize(u, v, parent, size);
                edgeCount++;
                
                if (edgeCount == V - 1) break;
            }
        }
        
        return cost;
    }
};
```

## Step-by-Step Algorithm

### 1. **Initialize Disjoint Set Union**
```cpp
vector<int> parent(V);
vector<int> rank(V, 0);
for (int i = 0; i < V; i++) {
    parent[i] = i;  // Each node is its own parent
}
```

### 2. **Create Edge List**
```cpp
// Convert adjacency representation to edge list
vector<pair<int, pair<int, int>>> edgeList;
// Format: {weight, {u, v}}
```

### 3. **Sort Edges by Weight**
```cpp
sort(edgeList.begin(), edgeList.end());
// Greedy approach: process cheapest edges first
```

### 4. **Process Edges**
```cpp
for (each edge in sorted order) {
    if (u and v are in different components) {
        add edge to MST;
        merge components;
        increment edge count;
    }
    if (edge count == V-1) break;  // MST complete
}
```

## Example Walkthrough

### Input Graph
```
Vertices: 4 (0, 1, 2, 3)
Edges: [[0,1,10], [0,2,6], [0,3,5], [1,3,15], [2,3,4]]

Graph visualization:
    0
   /|\
 10/ |6\5
  /  |  \
 1   2---3
  \  |  /
 15\ |4/
    \|/
```

### Step-by-Step Execution

**Initial State:**
```
Parent: [0, 1, 2, 3]
Rank:   [0, 0, 0, 0]
Cost:   0
Edges:  []
```

**Sorted Edges:**
```
[(4, {2,3}), (5, {0,3}), (6, {0,2}), (10, {0,1}), (15, {1,3})]
```

**Iteration 1: Edge (2,3) with weight 4**
- FindParent(2) = 2, FindParent(3) = 3
- Different components → Add edge
- Union(2,3): parent[3] = 2
- Cost = 4, Edges = 1

```
Parent: [0, 1, 2, 2]
Components: {0}, {1}, {2,3}
MST edges: [(2,3,4)]
```

**Iteration 2: Edge (0,3) with weight 5**
- FindParent(0) = 0, FindParent(3) = 2
- Different components → Add edge  
- Union(0,3): parent[2] = 0
- Cost = 9, Edges = 2

```
Parent: [0, 1, 0, 2]
After path compression: [0, 1, 0, 0]
Components: {0,2,3}, {1}
MST edges: [(2,3,4), (0,3,5)]
```

**Iteration 3: Edge (0,2) with weight 6**
- FindParent(0) = 0, FindParent(2) = 0
- Same component → Skip (would create cycle)

**Iteration 4: Edge (0,1) with weight 10**
- FindParent(0) = 0, FindParent(1) = 1
- Different components → Add edge
- Union(0,1): parent[1] = 0
- Cost = 19, Edges = 3

```
Parent: [0, 0, 0, 0]
Components: {0,1,2,3}
MST edges: [(2,3,4), (0,3,5), (0,1,10)]
```

**Final MST:**
```
Total Cost: 19
Edges: (2,3), (0,3), (0,1)

MST Tree:
    0
   /|
 10/ |5
  /  |
 1   3
     |
     |4
     2
```

## Complexity Analysis

### Time Complexity: **O(E log E)**
- Sorting edges: O(E log E)
- Processing edges: O(E × α(V))
- α(V) is inverse Ackermann function ≈ constant for practical purposes

### Space Complexity: **O(V)**
- Parent array: O(V)
- Rank/Size array: O(V)
- Edge list: O(E) (temporary)

## Union by Rank vs Union by Size

| Aspect | Union by Rank | Union by Size |
|--------|--------------|---------------|
| **Metric** | Tree height/depth | Number of nodes |
| **Update Rule** | Increment rank only when equal | Always update size |
| **Space** | O(V) for rank array | O(V) for size array |
| **Practical Performance** | Slightly better | Marginally slower |
| **Implementation** | Standard approach | Alternative approach |

## Key Optimizations

### 1. **Path Compression**
```cpp
return parent[u] = FindParent(parent[u], parent);
```
- Flattens tree structure
- Makes future finds O(1) amortized

### 2. **Union by Rank/Size**
```cpp
if (rank[pu] > rank[pv]) {
    parent[pv] = pu;  // Attach smaller to larger
}
```
- Keeps trees balanced
- Prevents degenerate chains

### 3. **Early Termination**
```cpp
if (edgeCount == V - 1) break;
```
- Stop when MST is complete
- Avoid processing unnecessary edges

## Common Mistakes to Avoid

1. **Not sorting edges** - Algorithm becomes incorrect
2. **Missing cycle detection** - Results in non-tree structure  
3. **Forgetting path compression** - Poor time complexity
4. **Wrong union logic** - Unbalanced trees
5. **Off-by-one in edge count** - MST has exactly V-1 edges

## Applications

- **Network Design**: Minimum cost to connect all nodes
- **Circuit Design**: Minimum wire length in PCB routing
- **Transportation**: Cheapest road network connecting cities
- **Clustering**: Group similar data points with minimum cost
- **Image Segmentation**: Partition image into regions

## Summary

Kruskal's algorithm efficiently finds the minimum spanning tree by:

1. **Sorting all edges** by weight (greedy approach)
2. **Using DSU** to detect cycles and merge components
3. **Processing edges** in order until MST is complete
4. **Optimizing with path compression and union by rank**

The algorithm guarantees finding the MST with **O(E log E)** time complexity, making it ideal for sparse graphs where edge sorting cost is manageable.