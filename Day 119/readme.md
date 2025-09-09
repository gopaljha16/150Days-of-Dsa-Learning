# Day119 Shortest Path in Weighted Undirected Graph

## Overview

This C++ code implements **Dijkstra's Algorithm** to find the shortest path between two nodes in a weighted undirected graph. The algorithm not only calculates the minimum distance but also returns the complete path from source node (1) to destination node (n).

**What it does:**
- Takes a weighted undirected graph as input
- Finds shortest path from node 1 to node n using Dijkstra's algorithm
- Returns the path along with the total weight/distance

**Key Features:**
- Uses priority queue (min-heap) for efficient node selection
- Tracks parent nodes to reconstruct the path
- Handles unreachable destinations
- Time Complexity: O((V + E) log V)

---

## Code Breakdown

### 1. Function Signature
```cpp
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges)
```
- **n**: Number of nodes (vertices)
- **m**: Number of edges
- **edges**: 2D vector where each row contains [u, v, weight]
- **Returns**: Vector containing the shortest path with distance

### 2. Adjacency List Creation
```cpp
int V = n;
vector<pair<int , int>>adj[V+1];
for(int i=0 ; i<m ; i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];
    //undirected graph 
    adj[v].push_back({u , weight});
    adj[u].push_back({v , weight});
}
```

**Explanation (English):** Creates an adjacency list representation where each node stores its neighbors with corresponding weights.

**Explanation (Hinglish):** Har node ke liye ek list banate hain jisme uske neighbors aur unke weights store karte hain. Undirected graph hai toh dono directions mein edges add karte hain.

### 3. Dijkstra's Algorithm Setup
```cpp
vector<bool>explored(V+1 ,0);      // Track visited nodes
vector<int>dist(V+1 , INT_MAX);    // Distance from source
vector<int>parent(V+1 , -1);       // Parent tracking for path reconstruction

priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>p;
p.push({0,1}); // source is 1
dist[1] = 0;
```

**Explanation (English):** Initialize data structures for Dijkstra's algorithm - distance array, parent array for path tracking, and a min-heap priority queue.

**Explanation (Hinglish):** Dijkstra ke liye zaroori arrays banate hain - distance track karne ke liye, parent track karne ke liye path reconstruct karne ke liye, aur min-heap priority queue.

### 4. Main Dijkstra Loop
```cpp
while(!p.empty()){
    int node = p.top().second;
    p.pop();
    
    if(explored[node]) //already explored
     continue;
     
    explored[node] = 1; //mark as explored
    
    //look at all the neighbors
    for(int j=0 ; j<adj[node].size() ; j++){
        int neighbour = adj[node][j].first;
        int weight = adj[node][j].second;
        
        if(!explored[neighbour] && dist[node]+weight<dist[neighbour]){
            dist[neighbour] = dist[node]+weight;
            p.push({dist[neighbour] , neighbour});
            parent[neighbour] = node; //parent updated
        }
    }
}
```

**Explanation (English):** The core Dijkstra logic - repeatedly extract the minimum distance node, explore its neighbors, and update distances if a shorter path is found.

**Explanation (Hinglish):** Main Dijkstra ka logic - sabse kam distance wala node nikaalte hain, uske neighbors check karte hain, agar koi shorter path milta hai toh distance update kar dete hain aur parent bhi set karte hain.

### 5. Path Reconstruction
```cpp
vector<int>path;
// If can't reach destination 
if(parent[V]==-1){
    path.push_back(-1);
    return path;
}

// if it can reach destination 
int dest = V;
while(dest!=-1){
    path.push_back(dest);
    dest = parent[dest]; //go to parent
}

//first value will be total distance
path.push_back(dist[V]);
reverse(path.begin() , path.end());
return path;
```

**Explanation (English):** Reconstruct the shortest path by backtracking through parent pointers from destination to source.

**Explanation (Hinglish):** Parent pointers use karte hue destination se source tak ka path banate hain. Agar destination tak pohunch nahi sakte toh -1 return karte hain.

---

## Example Input and Output

### Example 1:
**Input:**
- n = 5 (nodes: 1, 2, 3, 4, 5)
- m = 6 (edges)
- edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1], [4,3,3], [3,5,1]]

**Expected Output:**
- [1, 4, 3, 5] with total distance 5

### Example 2 (Unreachable):
**Input:**
- n = 4
- m = 2  
- edges = [[1,2,3], [3,4,2]]

**Expected Output:**
- [-1] (node 4 is unreachable from node 1)

---

## Step-by-Step Dry Run

Let's trace through Example 1:

### Initial Graph:
```
    1 ----2---- 2 ----5---- 5
    |           |           |
    1           4           1
    |           |           |
    4 ----3---- 3 ----------+
```

### Step 1: Initialize
```
dist:      [∞, 0, ∞, ∞, ∞, ∞]
parent:    [-1, -1, -1, -1, -1, -1]
explored:  [F, F, F, F, F, F]
pq: [(0,1)]
```

### Step 2: Process Node 1
```
Current node: 1
Neighbors: (2,2), (4,1)
Update dist[2] = 2, parent[2] = 1
Update dist[4] = 1, parent[4] = 1
pq: [(1,4), (2,2)]
explored[1] = true
```

### Step 3: Process Node 4 (minimum distance = 1)
```
Current node: 4
Neighbors: (1,1), (3,3)
dist[1] already optimal
Update dist[3] = 4, parent[3] = 4
pq: [(2,2), (4,3)]
explored[4] = true
```

### Step 4: Process Node 2 (minimum distance = 2)
```
Current node: 2
Neighbors: (1,2), (5,5), (3,4)
dist[1] already optimal
Update dist[5] = 7, parent[5] = 2
dist[3]: 4 < 6, so no update
pq: [(4,3), (7,5)]
explored[2] = true
```

### Step 5: Process Node 3 (minimum distance = 4)
```
Current node: 3
Neighbors: (2,4), (4,3), (5,1)
Update dist[5] = 5 (4+1 < 7), parent[5] = 3
pq: [(5,5), (7,5)]
explored[3] = true
```

### Step 6: Process Node 5 (minimum distance = 5)
```
Final distances: [∞, 0, 2, 4, 1, 5]
Final parents: [-1, -1, 1, 4, 1, 3]
```

### Path Reconstruction:
```
Start from node 5: parent[5] = 3
Go to node 3: parent[3] = 4  
Go to node 4: parent[4] = 1
Go to node 1: parent[1] = -1 (source)

Path: [5, 3, 4, 1] → reverse → [1, 4, 3, 5]
Add total distance: [5, 1, 4, 3, 5]
```

---

## Visual Algorithm Flow

```
┌─────────────────┐
│   Input Graph   │
└─────┬───────────┘
      │
      ▼
┌─────────────────┐
│ Create Adj List │
└─────┬───────────┘
      │
      ▼
┌─────────────────┐
│ Initialize      │
│ - dist[]        │
│ - parent[]      │
│ - priority_queue│
└─────┬───────────┘
      │
      ▼
┌─────────────────┐
│ While PQ not    │
│ empty:          │
│ 1. Extract min  │
│ 2. Mark visited │ 
│ 3. Update       │
│    neighbors    │
└─────┬───────────┘
      │
      ▼
┌─────────────────┐
│ Check if dest   │
│ reachable       │
└─────┬───────────┘
      │
      ▼
┌─────────────────┐
│ Reconstruct     │
│ Path using      │
│ parent[]        │
└─────┬───────────┘
      │
      ▼
┌─────────────────┐
│ Return Path     │
│ with Distance   │
└─────────────────┘
```

---

## Data Structures Used

| Structure | Purpose | Space Complexity |
|-----------|---------|------------------|
| `adj[]` | Store graph as adjacency list | O(V + E) |
| `dist[]` | Track shortest distances | O(V) |
| `parent[]` | Track parent for path reconstruction | O(V) |
| `explored[]` | Mark visited nodes | O(V) |
| `priority_queue` | Extract minimum distance node | O(V) |

---

## Time and Space Complexity

- **Time Complexity:** O((V + E) log V)
  - Each vertex is extracted once: O(V log V)
  - Each edge is relaxed once: O(E log V)
  
- **Space Complexity:** O(V + E)
  - Adjacency list: O(V + E)
  - Arrays: O(V)
  - Priority queue: O(V)

---

## Key Points (English & Hinglish)

1. **Source is always node 1** - Algorithm starts from node 1
   - **Hinglish**: Hamesha node 1 se start karte hain

2. **Destination is node n** - We want shortest path to the last node
   - **Hinglish**: Node n tak ka shortest path chahiye

3. **Undirected graph** - Edges work both ways
   - **Hinglish**: Graph undirected hai, dono taraf ja sakte hain

4. **Priority queue uses min-heap** - Always processes smallest distance first
   - **Hinglish**: Min-heap use karte hain taaki sabse chota distance pehle mile

5. **Parent tracking** - Essential for path reconstruction
   - **Hinglish**: Parent track karna zaroori hai path banane ke liye

---

## Summary

This implementation of Dijkstra's algorithm efficiently finds the shortest path in a weighted undirected graph. It returns both the path and the total distance, handling unreachable destinations gracefully. The algorithm uses a min-heap priority queue for optimal performance and parent tracking for path reconstruction.

**Key Benefits:**
- Optimal solution for shortest path problems
- Efficient implementation with good time complexity
- Returns complete path, not just distance
- Handles edge cases (unreachable nodes)

**Use Cases:**
- GPS navigation systems
- Network routing protocols  
- Game pathfinding
- Social network analysis