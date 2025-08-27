# Graph Representation in Data Structures

A comprehensive guide to implementing graphs using Adjacency Matrix and Adjacency List representations in C++.

## Overview

This code demonstrates two fundamental ways to represent graphs in computer science:

1. **Adjacency Matrix**: A 2D array where `matrix[i][j]` represents the connection between vertices `i` and `j`
2. **Adjacency List**: An array of lists where each index represents a vertex and contains a list of its connected vertices

The implementation covers four types of graphs:
- Undirected Unweighted
- Undirected Weighted  
- Directed Unweighted
- Directed Weighted

---

## Part 1: Adjacency Matrix Implementation

### Code Structure Overview

The adjacency matrix implementation uses a 2D vector to represent graph connections:

```cpp
vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));
```

### Active Implementation: Directed Weighted Graph

```cpp
int main(){
    int vertex , edge;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edge;

    // Create adjacency matrix initialized with zeros
    vector<vector<int> >AdjMat(vertex , vector<int>(vertex, 0));

    int u , v , weight; 
    for(int i=0 ; i<edge; i++){
        cin>>u>>v>>weight; // Input: source, destination, weight
        AdjMat[u][v] = weight; // One-directional edge for directed graph
    }

    // Print the adjacency matrix
    for(int i=0 ; i<vertex ; i++){
        for(int j=0 ; j<vertex ; j++)
         cout<<AdjMat[i][j]<<" ";
         cout<<endl;
    }
}
```

### Line-by-Line Explanation

1. **Input Phase**:
   - `cin>>vertex>>edge;` - Gets number of vertices and edges
   - Creates a `vertex × vertex` matrix initialized with zeros

2. **Edge Input Loop**:
   - For each edge, reads source vertex `u`, destination vertex `v`, and `weight`
   - `AdjMat[u][v] = weight;` - Sets the weight in matrix (directed graph)
   - Note: Only sets `AdjMat[u][v]`, not `AdjMat[v][u]` (directional)

3. **Output Phase**:
   - Prints the complete adjacency matrix row by row

---

## Part 2: Adjacency List Implementation

### Code Structure Overview

The adjacency list uses an array of vectors containing pairs for weighted graphs:

```cpp
vector<pair<int,int>> AdjList[vertex];
```

### Active Implementation: Directed Weighted Graph

```cpp
int main(){
    int vertex, edges;
    cout<<"Enter your vertex and edges :- ";
    cin>>vertex>>edges;
    
    // Array of vectors containing pairs (destination, weight)
    vector<pair<int,int> >AdjList[vertex];

    int u,v, weight;
    for(int i=0 ;i<edges; i++){
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v , weight));
    }

    // Print adjacency list
    for(int i=0 ; i<vertex ; i++){
        cout<<i<<" -> ";
        for(int j=0 ; j<AdjList[i].size() ; j++)
           cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" "; 
        cout<<endl;
    }
}
```

### Line-by-Line Explanation

1. **Data Structure Setup**:
   - `vector<pair<int,int>> AdjList[vertex];` - Array of vectors, each storing pairs
   - Each pair contains `(destination_vertex, weight)`

2. **Edge Input**:
   - `AdjList[u].push_back(make_pair(v, weight));` - Adds edge from u to v with given weight
   - Only adds one direction (directed graph)

3. **Output**:
   - `AdjList[i][j].first` - Destination vertex
   - `AdjList[i][j].second` - Edge weight

---

## Example Walkthrough

### Input Example
```
Vertices: 4
Edges: 5
Edge connections:
0 1 10
0 2 5
1 3 15
2 3 20
3 0 8
```

### Step-by-Step Execution (Adjacency Matrix)

#### Step 1: Initialization
```
Initial Matrix (4×4):
  0 1 2 3
0 0 0 0 0
1 0 0 0 0
2 0 0 0 0
3 0 0 0 0
```

#### Step 2: Adding Edges
- **Edge 0→1 (weight=10)**: `AdjMat[0][1] = 10`
- **Edge 0→2 (weight=5)**: `AdjMat[0][2] = 5`
- **Edge 1→3 (weight=15)**: `AdjMat[1][3] = 15`
- **Edge 2→3 (weight=20)**: `AdjMat[2][3] = 20`
- **Edge 3→0 (weight=8)**: `AdjMat[3][0] = 8`

#### Step 3: Final Matrix
```
Final Adjacency Matrix:
  0  1  2  3
0 0 10  5  0
1 0  0  0 15
2 0  0  0 20
3 8  0  0  0
```

### Step-by-Step Execution (Adjacency List)

#### Step 1: Initialization
```
AdjList[0]: empty
AdjList[1]: empty
AdjList[2]: empty
AdjList[3]: empty
```

#### Step 2: Adding Edges
- **Edge 0→1 (weight=10)**: `AdjList[0].push_back({1, 10})`
- **Edge 0→2 (weight=5)**: `AdjList[0].push_back({2, 5})`
- **Edge 1→3 (weight=15)**: `AdjList[1].push_back({3, 15})`
- **Edge 2→3 (weight=20)**: `AdjList[2].push_back({3, 20})`
- **Edge 3→0 (weight=8)**: `AdjList[3].push_back({0, 8})`

#### Step 3: Final List
```
Final Adjacency List:
0 -> 1 10 2 5
1 -> 3 15
2 -> 3 20
3 -> 0 8
```

---

## Visual Representation

### Graph Structure
```
    10      15
0 -----> 1 -----> 3
|                 ^
|5               /20
v               /
2 -------------/
     8
3 ---------> 0
```

### Adjacency Matrix vs Adjacency List

```
ADJACENCY MATRIX              ADJACENCY LIST
  0  1  2  3                  0 -> [(1,10), (2,5)]
0 0 10  5  0                  1 -> [(3,15)]
1 0  0  0 15                  2 -> [(3,20)]
2 0  0  0 20                  3 -> [(0,8)]
3 8  0  0  0
```

---

## Comparison: Adjacency Matrix vs Adjacency List

| Aspect | Adjacency Matrix | Adjacency List |
|--------|------------------|----------------|
| **Space Complexity** | O(V²) | O(V + E) |
| **Time: Add Edge** | O(1) | O(1) |
| **Time: Check Edge** | O(1) | O(V) worst case |
| **Time: Get All Adjacent** | O(V) | O(degree) |
| **Memory Usage** | High (sparse graphs wasteful) | Efficient |
| **Best For** | Dense graphs, frequent edge queries | Sparse graphs, traversal algorithms |

### When to Use Each:

**Adjacency Matrix**:
- Dense graphs (many edges)
- Frequent edge existence queries
- Weighted graphs with matrix operations
- Small graphs

**Adjacency List**:
- Sparse graphs (few edges)
- Graph traversal algorithms (DFS, BFS)
- Memory-constrained environments
- Large graphs

---

## Trees vs Graphs

### Key Differences

| Property | Tree | Graph |
|----------|------|-------|
| **Cycles** | No cycles (acyclic) | Can have cycles |
| **Connectivity** | Always connected | May be disconnected |
| **Edges** | V-1 edges (V vertices) | Can have any number of edges |
| **Root** | Has a root node | No specific root |
| **Hierarchy** | Hierarchical structure | Non-hierarchical |
| **Parent-Child** | Each node has one parent | Nodes can have multiple connections |

### Examples

#### Tree Structure:
```
       A
      / \
     B   C
    / \   \
   D   E   F
```
- 6 vertices, 5 edges
- No cycles
- Hierarchical
- Connected

#### Graph Structure:
```
   A --- B
   |   / |
   |  /  |
   | /   |
   C --- D
```
- 4 vertices, 5 edges
- Has cycles (A-B-D-C-A)
- Non-hierarchical
- Connected

### Tree Representations:
- **Array representation** (for complete trees)
- **Linked representation** (parent pointers)
- **Adjacency list** (treating as special graph)

### Graph Representations:
- **Adjacency Matrix** (as shown above)
- **Adjacency List** (as shown above)
- **Edge List** (list of all edges)

---

## Complete Code Variations

### All Four Matrix Types:

1. **Undirected Unweighted**: Uses `vector<vector<bool>>`, sets both `[u][v]` and `[v][u]` to 1
2. **Undirected Weighted**: Uses `vector<vector<int>>`, sets both `[u][v]` and `[v][u]` to weight
3. **Directed Unweighted**: Uses `vector<vector<bool>>`, sets only `[u][v]` to 1
4. **Directed Weighted**: Uses `vector<vector<int>>`, sets only `[u][v]` to weight

### All Four List Types:

1. **Undirected Unweighted**: `vector<int>`, pushes to both u and v lists
2. **Undirected Weighted**: `vector<pair<int,int>>`, pushes pairs to both u and v lists
3. **Directed Unweighted**: `vector<int>`, pushes only to u list
4. **Directed Weighted**: `vector<pair<int,int>>`, pushes pair only to u list

---

## Summary

This implementation demonstrates fundamental graph representation techniques:

- **Adjacency Matrix** provides O(1) edge lookup but uses O(V²) space
- **Adjacency List** is space-efficient O(V+E) and better for sparse graphs
- **Directed graphs** store edges in one direction only
- **Weighted graphs** store additional weight information
- **Trees are special graphs** with no cycles and exactly V-1 edges

Choose the representation based on your specific use case: dense vs sparse graphs, memory constraints, and required operations. For most graph algorithms like DFS/BFS, adjacency lists are preferred due to their efficiency in traversing neighbors.