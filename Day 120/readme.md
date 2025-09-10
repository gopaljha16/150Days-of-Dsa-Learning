# Bellman-Ford Algorithm | Shortest Distance from Source

## Overview

The **Bellman-Ford Algorithm** is a single-source shortest path algorithm that finds the shortest distances from a source vertex to all other vertices in a weighted directed graph. Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with **negative edge weights** and can also **detect negative cycles**.

**Key Features:**
- Works with negative edge weights
- Detects negative cycles
- Time Complexity: O(V × E)
- Space Complexity: O(V)

---

## Code Explanation

### Header and Class Structure
```cpp
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
```

**English:** This defines a class `Solution` with a public method `bellmanFord` that takes:
- `V`: Number of vertices in the graph
- `edges`: 2D vector containing edge information [source, destination, weight]
- `src`: Source vertex from which to find shortest paths

**Hinglish:** Ye ek class hai `Solution` jisme ek public method `bellmanFord` hai jo ye parameters leta hai:
- `V`: Graph mein kitne vertices hain
- `edges`: 2D vector jisme edge ki information hai [source, destination, weight]
- `src`: Source vertex jisse shortest paths nikalne hain

### Step 1: Initialize Distance Array
```cpp
vector<int>dist(V , 1e8); //1e8 is 10^8 
dist[src] = 0; //source 
int e = edges.size(); //number of edges
```

**English:** 
- Create a distance array of size V, initialized with infinity (1e8 = 100,000,000)
- Set distance to source vertex as 0
- Store the number of edges for iteration

**Hinglish:**
- Size V ka distance array banaya, infinity (1e8 = 100,000,000) se initialize kiya
- Source vertex ka distance 0 set kiya
- Edges ki count store ki iteration ke liye

### Step 2: Main Bellman-Ford Loop (V-1 iterations)
```cpp
//v-1 time it should iterate
for(int i=0 ; i<V-1 ; i++){
    //relax alll the edges
    bool flag = 0; //for optimizing the approach
```

**English:** Run the main loop V-1 times. The `flag` variable is used for optimization - if no distance updates happen in an iteration, we can terminate early.

**Hinglish:** Main loop V-1 baar chalana hai. `flag` variable optimization ke liye hai - agar kisi iteration mein distance update nahi hota, toh early terminate kar sakte hain.

### Step 3: Edge Relaxation
```cpp
for(int j=0 ; j<e ; j++){
    int u = edges[j][0];  // source vertex
    int v = edges[j][1];  // destination vertex
    int wt = edges[j][2]; // weight
    
    //edge case if there it can't reach to that vertex
    if(dist[u]==1e8)
        continue; // then skip the iteration 
    
    //now update distance if possible
    if(dist[u]+wt<dist[v]){
        dist[v] = dist[u]+wt; //update the distance if it's smaller
        flag = 1;
    }
}
```

**English:** 
- For each edge, extract source (u), destination (v), and weight (wt)
- Skip if source vertex is unreachable (distance = infinity)
- If path through current edge gives shorter distance, update it
- Set flag=1 to indicate an update happened

**Hinglish:**
- Har edge ke liye source (u), destination (v), aur weight (wt) nikalo
- Agar source vertex unreachable hai (distance = infinity) toh skip karo
- Agar current edge se shorter distance mil raha hai, toh update karo
- flag=1 set karo ki update hua hai

### Step 4: Early Termination Optimization
```cpp
if(!flag) //optimized if the distance is not updating return the dist
    return dist;
```

**English:** If no updates happened in this iteration, return the result as optimal distances are found.

**Hinglish:** Agar is iteration mein koi update nahi hua, toh result return kar do kyunki optimal distances mil gaye.

### Step 5: Negative Cycle Detection
```cpp
//one more time for detecting if cycle is present
for(int j=0 ; j<e ; j++){
    int u = edges[j][0];
    int v = edges[j][1];
    int wt = edges[j][2];
    
    if(dist[u]==1e8)
        continue;
    
    //if updated then we have negative cycle
    if(dist[u]+wt<dist[v]){
        vector<int>ans;
        ans.push_back(-1);
        return ans;
    }
}

return dist;
```

**English:** 
- Run one more iteration to detect negative cycles
- If any distance can still be updated, it means there's a negative cycle
- Return [-1] to indicate negative cycle presence
- Otherwise, return the distance array

**Hinglish:**
- Ek aur iteration chalao negative cycle detect karne ke liye
- Agar abhi bhi koi distance update ho sakta hai, matlab negative cycle hai
- [-1] return karo negative cycle indicate karne ke liye
- Warna distance array return karo

---

## Example Walkthrough

### Example Input:
```
V = 4 (vertices: 0, 1, 2, 3)
edges = [[0,1,4], [0,2,3], [1,2,-2], [1,3,6], [2,3,2]]
src = 0
```

### Graph Visualization:
```
    0
   /|\
  4 | 3
 /  |  \
1---2---3
 \  |  /
  -2|2 6
    |/
```

### Step-by-Step Dry Run:

#### Initial State:
```
dist = [0, ∞, ∞, ∞]
```

#### Iteration 1:
**Processing edges:**
- Edge [0,1,4]: dist[0]+4 = 0+4 = 4 < ∞ → dist[1] = 4
- Edge [0,2,3]: dist[0]+3 = 0+3 = 3 < ∞ → dist[2] = 3
- Edge [1,2,-2]: dist[1]+(-2) = 4-2 = 2 < 3 → dist[2] = 2
- Edge [1,3,6]: dist[1]+6 = 4+6 = 10 < ∞ → dist[3] = 10
- Edge [2,3,2]: dist[2]+2 = 2+2 = 4 < 10 → dist[3] = 4

**After Iteration 1:**
```
dist = [0, 4, 2, 4]
```

#### Iteration 2:
**Processing edges:**
- Edge [0,1,4]: 0+4 = 4, not less than 4 → no update
- Edge [0,2,3]: 0+3 = 3, not less than 2 → no update
- Edge [1,2,-2]: 4-2 = 2, not less than 2 → no update
- Edge [1,3,6]: 4+6 = 10, not less than 4 → no update
- Edge [2,3,2]: 2+2 = 4, not less than 4 → no update

**After Iteration 2:**
```
dist = [0, 4, 2, 4] (no changes, flag = 0)
```

#### Early Termination:
Since flag = 0, algorithm terminates early.

#### Negative Cycle Check:
Run one more iteration - no updates possible, so no negative cycle.

#### Final Result:
```
dist = [0, 4, 2, 4]
```

**Meaning:**
- Distance from 0 to 0: 0
- Distance from 0 to 1: 4
- Distance from 0 to 2: 2
- Distance from 0 to 3: 4

---

## Visual Algorithm Flow

```
Start
  ↓
Initialize dist[src] = 0, others = ∞
  ↓
For i = 0 to V-2:
  ↓
  For each edge (u,v,wt):
    ↓
    if dist[u] + wt < dist[v]:
      ↓
      dist[v] = dist[u] + wt
      flag = 1
  ↓
  if flag == 0: return dist (optimization)
  ↓
Check for negative cycle:
For each edge (u,v,wt):
  ↓
  if dist[u] + wt < dist[v]:
    ↓
    return [-1] (negative cycle found)
  ↓
return dist
```

---

## When to Use Bellman-Ford vs Dijkstra

### Bellman-Ford Algorithm
**Use When:**
- Graph has **negative edge weights**
- Need to **detect negative cycles**
- Graph is relatively small (due to O(VE) complexity)
- Working with **directed graphs** with negative weights

**Examples:**
- Currency exchange rates (can have negative values)
- Network routing with costs that can go negative
- Game theory problems with penalties

### Dijkstra's Algorithm
**Use When:**
- **All edge weights are non-negative**
- Need **faster execution** (O(V log V + E) with priority queue)
- Working with large graphs
- Real-time applications

**Examples:**
- GPS navigation (distances are always positive)
- Network packet routing (delays are positive)
- Social network analysis

---

## Comparison Table

| Feature | Bellman-Ford | Dijkstra |
|---------|--------------|----------|
| Time Complexity | O(V × E) | O(V log V + E) |
| Negative Weights | ✅ Yes | ❌ No |
| Negative Cycle Detection | ✅ Yes | ❌ No |
| Space Complexity | O(V) | O(V) |
| Best for | Small graphs with negative weights | Large graphs with positive weights |

---

## Complete Example with Negative Cycle

### Input with Negative Cycle:
```
V = 3
edges = [[0,1,1], [1,2,-3], [2,0,1]]
src = 0
```

### Graph:
```
0 --1--> 1
^        |
|        -3
1        |
|        v
+-- 1 ---2
```

**Cycle sum:** 1 + (-3) + 1 = -1 (negative cycle)

**Algorithm Output:** [-1] (indicating negative cycle detected)

---

## Key Points to Remember

**English:**
1. Bellman-Ford can handle negative weights, Dijkstra cannot
2. It detects negative cycles which make shortest paths undefined
3. Runs in O(VE) time - slower than Dijkstra but more versatile
4. The V-1 iterations ensure all shortest paths are found
5. One extra iteration detects negative cycles

**Hinglish:**
1. Bellman-Ford negative weights handle kar sakta hai, Dijkstra nahi
2. Ye negative cycles detect karta hai jo shortest paths ko undefined banate hain
3. O(VE) time mein chalta hai - Dijkstra se slow but zyada versatile
4. V-1 iterations ensure karte hain ki sab shortest paths mil jayen
5. Ek extra iteration negative cycles detect karta hai

---

## Summary

The Bellman-Ford algorithm is a robust shortest path algorithm that can handle negative edge weights and detect negative cycles. While slower than Dijkstra's algorithm, it's essential when dealing with graphs that may have negative weights. The algorithm works by relaxing all edges V-1 times, ensuring that all shortest paths are found, followed by one additional iteration to detect negative cycles.

**Time Complexity:** O(V × E)  
**Space Complexity:** O(V)  
**Best Use Case:** Graphs with negative edge weights or when negative cycle detection is required.