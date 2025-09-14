# Circle of Strings - Eulerian Cycle Detection

## Overview

This C++ solution determines whether a given array of strings can be arranged in a circle such that the last character of each string matches the first character of the next string. This is essentially checking for the existence of an **Eulerian cycle** in a directed graph where:
- Each character (a-z) represents a vertex
- Each string represents a directed edge from its first character to its last character

The algorithm uses graph theory concepts to solve this problem efficiently in O(n) time complexity.

---

## Algorithm Components

### 1. Graph Construction
```cpp
vector<int>adj[26]; // Adjacency list for 26 letters (a-z)
vector<int>Indeg(26,0);   // In-degree of each vertex
vector<int>outDeg(26,0);  // Out-degree of each vertex

for(int i=0 ; i<n ; i++){
    string temp = arr[i];
    int u = temp[0]-'a';              // First character as source vertex
    int v = temp[temp.size()-1]-'a';  // Last character as destination vertex
    adj[u].push_back(v);              // Add directed edge u → v
    outDeg[u]++;                      // Increment out-degree of source
    Indeg[v]++;                       // Increment in-degree of destination
}
```

**Purpose**: Creates a directed graph where each string becomes an edge between two character vertices.

### 2. Eulerian Cycle Condition Check
```cpp
for(int i=0 ; i<26 ; i++){
    if(Indeg[i]!=outDeg[i])
        return 0;  // No Eulerian cycle possible
}
```

**Purpose**: For an Eulerian cycle to exist, every vertex must have equal in-degree and out-degree.

### 3. Connected Component Verification
```cpp
void DFS(int node, vector<int>adj[], vector<bool>&visited){
    visited[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
        if(!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited);
    }
}

// Check connectivity
vector<bool>visited(26,0);
int node = arr[0][0] - 'a';
DFS(node, adj, visited);

for(int i=0; i<26; i++){
    if(Indeg[i] && !visited[i])
        return 0;  // Disconnected component found
}
```

**Purpose**: Ensures all vertices with non-zero degree are part of a single connected component.

---

## Step-by-Step Algorithm

1. **Build Graph**: Convert strings to directed edges in a character graph
2. **Check Degree Equality**: Verify in-degree equals out-degree for all vertices
3. **Check Connectivity**: Use DFS to ensure all relevant vertices are connected
4. **Return Result**: 1 if circle possible, 0 otherwise

---

## Example Walkthrough

### Input: `["abc", "cab", "bca"]`

#### Step 1: Graph Construction
```
Strings Analysis:
- "abc": a → c (edge from 'a' to 'c')
- "cab": c → b (edge from 'c' to 'b')  
- "bca": b → a (edge from 'b' to 'a')

Adjacency List:
adj[0] = [2]     // a → c
adj[1] = [0]     // b → a  
adj[2] = [1]     // c → b

Degrees:
        a(0)  b(1)  c(2)
InDeg:   1     1     1
OutDeg:  1     1     1
```

#### Step 2: Degree Check
```
For i = 0 (a): InDeg[0] = 1, OutDeg[0] = 1 ✓
For i = 1 (b): InDeg[1] = 1, OutDeg[1] = 1 ✓  
For i = 2 (c): InDeg[2] = 1, OutDeg[2] = 1 ✓
```
All degrees are equal - Eulerian cycle condition satisfied!

#### Step 3: Connectivity Check
```
Starting DFS from node 0 (character 'a'):
- Visit node 0 (a)
- From a, visit node 2 (c) 
- From c, visit node 1 (b)
- From b, back to node 0 (already visited)

Visited array: [true, true, true, false, false, ...]

Check unvisited vertices with non-zero degree:
- All vertices with InDeg[i] > 0 are visited ✓
```

#### Step 4: Result
**Return 1** - Circle formation is possible!

**Possible Circle**: "abc" → "cab" → "bca" → (back to start)

---

## Visual Representation

### Graph Diagram
```
    a ----→ c
    ↑       ↓
    |       |
    b ←-----+

Circle: a → c → b → a
Strings: abc → cab → bca
```

### Degree Table
| Vertex | Character | In-Degree | Out-Degree | Equal? |
|--------|-----------|-----------|------------|---------|
| 0      | a         | 1         | 1          | ✅      |
| 1      | b         | 1         | 1          | ✅      |
| 2      | c         | 1         | 1          | ✅      |

---

## Time & Space Complexity

- **Time Complexity**: O(n + E) where n is number of strings and E is total edges
- **Space Complexity**: O(26) = O(1) for the adjacency list and degree arrays

---

## Example Test Cases

### Test Case 1: Valid Circle
**Input**: `["abc", "cab", "bca"]`
**Output**: `1`
**Explanation**: Forms cycle a→c→b→a

### Test Case 2: Invalid Circle (Degree Mismatch)  
**Input**: `["abc", "def"]`
**Output**: `0`
**Explanation**: No vertex has equal in-degree and out-degree

### Test Case 3: Invalid Circle (Disconnected)
**Input**: `["abc", "cba", "def", "fed"]`
**Output**: `0`  
**Explanation**: Two separate components exist

---

## Key Insights

1. **Eulerian Cycle Theory**: The problem is equivalent to finding an Eulerian cycle in a directed graph
2. **Necessary Conditions**: 
   - All vertices must have equal in-degree and out-degree
   - All vertices with non-zero degree must be in the same connected component
3. **Efficiency**: The algorithm runs in linear time by leveraging graph theory principles

## Summary

This solution elegantly transforms a string arrangement problem into a classic graph theory problem. By representing each string as a directed edge between character vertices, it uses Eulerian cycle conditions to determine if a valid circle arrangement exists. The algorithm's efficiency comes from checking only the necessary mathematical conditions rather than trying all possible arrangements.