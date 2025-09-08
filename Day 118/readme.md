# Dijkstra's Shortest Path Algorithm | Complete Guide with Implementation

## Overview

Dijkstra's algorithm is a **graph traversal algorithm** used to find the **shortest path** from a source vertex to all other vertices in a **weighted graph**. The algorithm works only with **non-negative edge weights** and uses a **greedy approach** to always select the vertex with the minimum distance that hasn't been processed yet.

**Key Features:**
- Time Complexity: O((V + E) log V) where V = vertices, E = edges
- Space Complexity: O(V)
- Works with: Weighted, directed/undirected graphs with non-negative weights
- Uses: Min-heap (priority queue) for optimal performance

---

## Algorithm Intuition

The core idea behind Dijkstra's algorithm:

1. **Start** from the source vertex with distance 0
2. **Always pick** the unvisited vertex with minimum distance
3. **Update distances** to all its neighbors if a shorter path is found
4. **Mark** the current vertex as visited
5. **Repeat** until all vertices are processed

Think of it like finding the shortest route in a city map - you always take the shortest known path to reach unexplored areas.

---

## Code Implementation

```cpp
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list representation
        vector<vector<pair<int,int>>> adj(V);  // {neighbor_node, edge_weight}
        for (auto &edge : edges) {
            int u = edge[0];        // source vertex of edge
            int v = edge[1];        // destination vertex of edge  
            int w = edge[2];        // weight of edge

            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // for undirected graph
        }

        // Step 2: Initialize data structures
        vector<bool> explored(V, false);    // tracks visited vertices
        vector<int> dist(V, INT_MAX);       // shortest distances from source
        dist[src] = 0;                      // distance to source = 0
        
        // Step 3: Create min-heap priority queue
        // pair<distance, vertex> - min-heap based on distance
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src}); // {distance, vertex}
       
        // Step 4: Main algorithm loop
        while(!pq.empty()) {
            int node = pq.top().second; // get vertex with minimum distance
            pq.pop();
            
            // Skip if already processed (handles duplicate entries)
            if(explored[node] == true)
                continue;
                
            // Mark current vertex as explored
            explored[node] = true;
        
            // Step 5: Relax all edges from current vertex
            for(int j = 0; j < adj[node].size(); j++) {
                int neighbor = adj[node][j].first;   // adjacent vertex
                int weight = adj[node][j].second;    // edge weight
            
                // Relaxation: check if shorter path found
                if (dist[node] != INT_MAX && dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }   
            }  
        }
        
        return dist; // return shortest distances array
    }
};
```

---

## Line-by-Line Explanation

### Phase 1: Graph Representation (Lines 4-12)
```cpp
vector<vector<pair<int,int>>> adj(V);
```
- Creates adjacency list where `adj[i]` contains all neighbors of vertex `i`
- Each neighbor is stored as `{vertex, weight}` pair

```cpp
for (auto &edge : edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // for undirected graph
}
```
- Converts edge list to adjacency list representation
- For undirected graphs, adds edge in both directions

### Phase 2: Initialization (Lines 14-17)
```cpp
vector<bool> explored(V, false);
vector<int> dist(V, INT_MAX);
dist[src] = 0;
```
- `explored[]`: Tracks which vertices have been processed
- `dist[]`: Stores shortest distance from source to each vertex
- Initialize source distance to 0, others to infinity

### Phase 3: Priority Queue Setup (Lines 19-21)
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({0, src});
```
- Creates min-heap priority queue based on distance
- Pushes source vertex with distance 0

### Phase 4: Main Algorithm (Lines 23-40)
```cpp
while(!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    
    if(explored[node] == true) continue;
    explored[node] = true;
```
- Extract vertex with minimum distance
- Skip if already processed (avoids reprocessing)
- Mark current vertex as explored

```cpp
for(int j = 0; j < adj[node].size(); j++) {
    int neighbor = adj[node][j].first;
    int weight = adj[node][j].second;
    
    if (dist[node] != INT_MAX && dist[node] + weight < dist[neighbor]) {
        dist[neighbor] = dist[node] + weight;
        pq.push({dist[neighbor], neighbor});
    }
}
```
- **Edge Relaxation**: Check all neighbors of current vertex
- If `dist[current] + edge_weight < dist[neighbor]`, update shorter distance
- Add updated neighbor to priority queue for future processing

---

## Example Input and Expected Output

### Input:
```cpp
V = 5 (vertices: 0, 1, 2, 3, 4)
edges = {{0,1,2}, {0,4,1}, {1,2,3}, {1,3,2}, {1,4,2}, {2,3,1}, {3,4,5}}
src = 0
```

### Graph Visualization:
```
    2     3
0 -----> 1 -----> 2
|        |        |
|1      2|        |1
|        |        |
v        v        v
4 <----- 3 <------+
    5
```

### Expected Output:
```cpp
dist = [0, 2, 5, 4, 1]
```
- Distance from 0 to 0: 0
- Distance from 0 to 1: 2
- Distance from 0 to 2: 5
- Distance from 0 to 3: 4  
- Distance from 0 to 4: 1

---

## Step-by-Step Dry Run

Let's trace through the algorithm with the above example:

### Initial State:
```
explored = [false, false, false, false, false]
dist = [0, ∞, ∞, ∞, ∞]
pq = [(0,0)]  // (distance, vertex)
```

### Iteration 1: Process vertex 0
```
Current vertex: 0
explored[0] = true
explored = [true, false, false, false, false]

Neighbors of 0: (1,2), (4,1)
- Update dist[1]: 0 + 2 = 2 < ∞ ✓
- Update dist[4]: 0 + 1 = 1 < ∞ ✓

dist = [0, 2, ∞, ∞, 1]
pq = [(1,4), (2,1)]
```

### Iteration 2: Process vertex 4
```
Current vertex: 4 (minimum distance = 1)
explored[4] = true
explored = [true, false, false, false, true]

Neighbors of 4: (0,1), (1,2), (3,5)
- dist[0]: 1 + 1 = 2 > 0 ✗ (no update)
- dist[1]: 1 + 2 = 3 > 2 ✗ (no update) 
- dist[3]: 1 + 5 = 6 < ∞ ✓

dist = [0, 2, ∞, 6, 1]
pq = [(2,1), (6,3)]
```

### Iteration 3: Process vertex 1
```
Current vertex: 1 (minimum distance = 2)
explored[1] = true
explored = [true, true, false, false, true]

Neighbors of 1: (0,2), (2,3), (3,2), (4,2)
- dist[0]: 2 + 2 = 4 > 0 ✗
- dist[2]: 2 + 3 = 5 < ∞ ✓
- dist[3]: 2 + 2 = 4 < 6 ✓ (better path found!)
- dist[4]: 2 + 2 = 4 > 1 ✗

dist = [0, 2, 5, 4, 1]
pq = [(4,3), (5,2), (6,3)]
```

### Iteration 4: Process vertex 3
```
Current vertex: 3 (minimum distance = 4)
explored[3] = true
explored = [true, true, false, true, true]

Neighbors of 3: (1,2), (2,1), (4,5)
- dist[1]: 4 + 2 = 6 > 2 ✗
- dist[2]: 4 + 1 = 5 = 5 ✗ (no improvement)
- dist[4]: 4 + 5 = 9 > 1 ✗

dist = [0, 2, 5, 4, 1] (no changes)
pq = [(5,2), (6,3)]
```

### Iteration 5: Process vertex 2
```
Current vertex: 2 (minimum distance = 5)
explored[2] = true
explored = [true, true, true, true, true]

All vertices processed!
Final result: [0, 2, 5, 4, 1]
```

---

## Visual Algorithm Flow

```
┌─────────────────┐
│   Start with    │
│   source = 0    │
│   dist[0] = 0   │
└─────┬───────────┘
      │
      v
┌─────────────────┐
│ Add source to   │
│ priority queue  │
│   pq = [(0,0)]  │
└─────┬───────────┘
      │
      v
┌─────────────────┐
│ While pq not    │
│     empty       │
└─────┬───────────┘
      │
      v
┌─────────────────┐
│ Extract min     │
│ distance vertex │
└─────┬───────────┘
      │
      v
┌─────────────────┐
│ Already         │
│ explored?       │ ─Yes─┐
└─────┬───────────┘      │
      │No                │
      v                  │
┌─────────────────┐      │
│ Mark as         │      │
│ explored        │      │
└─────┬───────────┘      │
      │                  │
      v                  │
┌─────────────────┐      │
│ For each        │      │
│ neighbor        │      │
└─────┬───────────┘      │
      │                  │
      v                  │
┌─────────────────┐      │
│ Can relax       │      │
│ edge?           │ ─No─┐│
└─────┬───────────┘     ││
      │Yes              ││
      v                 ││
┌─────────────────┐     ││
│ Update distance │     ││
│ Add to pq       │     ││
└─────┬───────────┘     ││
      │                 ││
      └─────────────────┘│
                         │
      ┌──────────────────┘
      │
      v
┌─────────────────┐
│ Return distance │
│     array       │
└─────────────────┘
```

---

## Time and Space Complexity Analysis

### Time Complexity: **O((V + E) log V)**
- **V iterations** of while loop (each vertex processed once)
- **Each iteration**: O(log V) for priority queue operations
- **Total edge relaxations**: E (each edge considered once)
- **Each relaxation**: O(log V) for priority queue insertion
- **Overall**: O(V log V + E log V) = O((V + E) log V)

### Space Complexity: **O(V + E)**
- **Adjacency list**: O(V + E) space
- **Distance array**: O(V) space  
- **Explored array**: O(V) space
- **Priority queue**: O(V) space in worst case
- **Total**: O(V + E)

---

## Key Concepts in Hinglish

### Main Idea samjhiye:
**Dijkstra ka algorithm** shortest path find karne ke liye use hota hai. Ye **greedy approach** ka use karta hai - matlab hamesha best available option choose karta hai.

### Kaise kaam karta hai step-by-step:
1. **Start** karte hain source vertex se (distance = 0 rakhte hain)
2. **Hamesha** sabse kam distance wala unvisited vertex pick karte hain  
3. Uske sare **neighbors ka distance check** karte hain - agar shorter path mile to update kar dete hain
4. Us vertex ko **visited mark** kar dete hain (taaki dobara process na kare)
5. **Tab tak repeat** karte hain jab tak sare vertices process na ho jaaye

### Priority Queue ka use kyun karte hain:
- **Min-heap** hamesha minimum distance wala vertex top pe rakhta hai
- Ye **greedy choice** efficiently implement karta hai  
- Time complexity ko **optimize** karta hai - O(V²) se O((V+E)logV) tak

### Edge Relaxation ka matlab:
```cpp
agar dist[current] + edge_weight < dist[neighbor]:
    to dist[neighbor] ko update karo
```
Ye check karta hai ki kya current vertex se jaake neighbor tak ka **shorter path mil sakta hai** ya nahi.

### Example se samjhiye:
Suppose aap **Gurgaon se Delhi** ja rahe ho. Dijkstra algorithm ye karta hai:
- Pehle **sabse paas wala point** check karta hai
- Phir us point se **aage ke sare routes** check karta hai  
- Agar **koi shorter route** mile to distance update kar deta hai
- Aise gradually **sabse short path** find kar leta hai

---

## Why Negative Weights Don't Work? 🚫

### Problem with Negative Weights:
Dijkstra algorithm **negative weights** ke saath fail ho jata hai. Kyun?

#### Example of Failure:
```
Graph with negative edge:
A ---(+5)--- B
|           /
|          /(-10)  
+1        /
|        /
C -------

Path A→B: distance = 5
Path A→C→B: distance = 1 + (-10) = -9  (shorter!)
```

**Problem**: Dijkstra ek baar vertex ko **process kar dene ke baad dubara check nahi karta**. Agar negative edge se **better path mil jaaye** to algorithm miss kar deta hai.

### Real Example:
```
Mumbai → Delhi flight: ₹8000
Mumbai → Bangalore: ₹3000  
Bangalore → Delhi: -₹2000 (cashback/reward points)

Total via Bangalore: ₹3000 + (-₹2000) = ₹1000
```

Dijkstra pehle **direct Mumbai→Delhi (₹8000)** process kar dega aur **Bangalore wala shorter path miss** kar dega!

### Solution for Negative Weights:
**Bellman-Ford Algorithm** use karo - wo negative weights handle kar sakta hai.

---

## Real-World Examples 🌍

### 1. **Google Maps / GPS Navigation**
```cpp
// Real scenario
Vertices = Cities/Intersections  
Edges = Roads
Weights = Travel time/Distance/Traffic
```
**Example**: Mumbai se Pune jane ke liye:
- **Multiple routes**: Express Highway, Old Mumbai-Pune road, via Lonavala
- **Dynamic weights**: Traffic conditions, toll charges, road quality
- **Result**: Fastest/shortest route recommendation

### 2. **Internet Routing (OSPF Protocol)**
```cpp
// Network routing
Vertices = Routers/Servers
Edges = Network connections  
Weights = Latency/Bandwidth cost
```
**Example**: Data packet Delhi se Bangalore bhejne ke liye:
- **Multiple hops**: Delhi→Mumbai→Bangalore vs Delhi→Chennai→Bangalore  
- **Weight factors**: Network congestion, bandwidth capacity
- **Result**: Fastest data transmission path

### 3. **Airline Route Planning**
```cpp
// Flight connections
Vertices = Airports (DEL, BOM, BLR, MAA)
Edges = Flight routes
Weights = Flight time + layover time + cost
```
**Example**: Delhi se Kochi jane ke liye:
- **Direct flight**: DEL→COK (3 hours, ₹8000)
- **Via Mumbai**: DEL→BOM→COK (4.5 hours, ₹5000)  
- **Via Bangalore**: DEL→BLR→COK (5 hours, ₹4500)
- **Algorithm finds**: Minimum cost/time combination

### 4. **Delivery Services (Zomato/Swiggy)**
```cpp
// Food delivery optimization
Vertices = Restaurant, Customer, Delivery boy location
Edges = Roads/Routes  
Weights = Distance + Traffic + Delivery time
```
**Example**: Delivery boy Connaught Place me hai:
- **Order 1**: Karol Bagh restaurant se Dwarka deliver karna hai
- **Order 2**: India Gate restaurant se Gurgaon deliver karna hai
- **Algorithm optimizes**: Shortest delivery route for multiple orders

### 5. **Social Networks (Friend Suggestions)**
```cpp
// Social connections
Vertices = Users/People
Edges = Friendships/Connections
Weights = Common interests/Mutual friends
```
**Example**: LinkedIn me job connections:
- **Direct connection**: You → Target Person (if connected)
- **2nd degree**: You → Mutual Friend → Target Person
- **Algorithm finds**: Shortest professional network path

### 6. **Gaming (Pathfinding)**
```cpp
// Game world navigation  
Vertices = Game map positions
Edges = Possible moves
Weights = Movement cost/Time/Energy
```
**Example**: PUBG me safe zone jane ke liye:
- **Current position**: Pochinki
- **Safe zone**: Military Base  
- **Obstacles**: Buildings, water, enemies
- **Algorithm finds**: Safest/fastest route to safe zone

### 7. **Financial Trading (Arbitrage)**
```cpp
// Currency exchange
Vertices = Different currencies (USD, EUR, INR)
Edges = Exchange rates  
Weights = Conversion rates + transaction fees
```
**Example**: Currency arbitrage opportunity:
- **INR → USD → EUR → INR** path me profit possible hai ya nahi
- **Algorithm detects**: Profitable exchange sequences

### 8. **Supply Chain Management**
```cpp
// Logistics optimization
Vertices = Warehouses, Distribution centers, Stores
Edges = Transportation routes
Weights = Shipping cost + Time + Distance
```
**Example**: Amazon delivery network:
- **Product**: Bangalore warehouse se Delhi customer tak
- **Routes**: Direct delivery vs Regional hub distribution  
- **Optimization**: Minimum cost delivery path

### Time Complexity in Real World:
- **Small city navigation**: ~1000 intersections → Very fast
- **Google Maps global**: Millions of points → Advanced optimizations needed
- **Internet routing**: Thousands of routers → Real-time updates required

---

## Common Pitfalls and Important Notes

### ⚠️ **Important Considerations:**

1. **Non-negative weights only**: Dijkstra doesn't work with negative edge weights
2. **Duplicate entries in PQ**: The `explored[]` check handles this efficiently
3. **INT_MAX check**: Prevents integer overflow during distance calculations
4. **Undirected vs Directed**: Add edges in both directions for undirected graphs

### 🐛 **Common Mistakes:**
- Forgetting to mark vertices as explored
- Not handling duplicate entries in priority queue
- Using max-heap instead of min-heap
- Missing the INT_MAX check during relaxation

---

## Alternative Implementation (Using Set)

```cpp
// Alternative using set instead of priority queue
vector<int> dijkstra_set(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    for (auto &edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    
    vector<int> dist(V, INT_MAX);
    set<pair<int,int>> s; // {distance, vertex}
    
    dist[src] = 0;
    s.insert({0, src});
    
    while (!s.empty()) {
        auto it = s.begin();
        int u = it->second;
        s.erase(it);
        
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] + weight < dist[v]) {
                s.erase({dist[v], v}); // Remove old entry
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v}); // Insert new entry
            }
        }
    }
    
    return dist;
}
```

---

## Summary

**Dijkstra's Algorithm** is a fundamental graph algorithm that efficiently finds shortest paths from a source vertex to all other vertices in a weighted graph. The key insights are:

- **Greedy Strategy**: Always process the vertex with minimum known distance
- **Priority Queue**: Efficiently maintains vertices sorted by distance  
- **Edge Relaxation**: Updates distances when shorter paths are discovered
- **Optimal Substructure**: Shortest path to any vertex contains shortest paths to intermediate vertices

The algorithm is widely used in:
- **Navigation systems** (GPS routing)
- **Network routing protocols** 
- **Social network analysis**
- **Game pathfinding**

**Time Complexity**: O((V + E) log V)  
**Space Complexity**: O(V + E)  
**Limitation**: Only works with non-negative edge weights

This implementation using a min-heap priority queue provides optimal performance and is the standard approach for solving shortest path problems in competitive programming and real-world applications.