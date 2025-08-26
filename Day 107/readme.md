# Graph Data Structure - Complete Guide

## Overview

A **Graph** is a non-linear data structure that consists of vertices (nodes) connected by edges. Unlike linear data structures (arrays, linked lists) or hierarchical structures (trees), graphs can represent complex relationships between entities, making them essential for modeling real-world scenarios like social networks, transportation systems, and computer networks.

## Table of Contents

- [Real-World Applications](#real-world-applications)
- [Graph Definition](#graph-definition)
- [Graph Components](#graph-components)
- [Types of Graphs](#types-of-graphs)
- [Graph Representations](#graph-representations)
- [Implementation Examples](#implementation-examples)
- [Time and Space Complexity](#time-and-space-complexity)
- [Summary](#summary)

## Real-World Applications

### 1. Railway Network System
```
Delhi -------- Mumbai
  |              |
  |              |
Jaipur ----- Bangalore
```
- **Vertices**: Cities (Delhi, Mumbai, Jaipur, Bangalore)
- **Edges**: Railway connections between cities
- **Use Case**: Finding shortest route, connectivity analysis

### 2. Social Networks (Facebook)
```
Alice --- Bob
  |       |
  |       |
Carol --- David
  |
  |
Emma
```
- **Vertices**: Users (Alice, Bob, Carol, David, Emma)
- **Edges**: Friendship connections
- **Use Case**: Friend recommendations, community detection

### 3. Professional Networks (LinkedIn)
```
Manager
   |
   |--- Developer1
   |--- Developer2
   |--- Designer
```
- **Vertices**: Professionals
- **Edges**: Professional connections, reporting relationships
- **Use Case**: Career networking, skill matching

### 4. Other Applications
- **Computer Networks**: Routers and connections
- **Web Pages**: Pages and hyperlinks
- **GPS Navigation**: Intersections and roads
- **Dependency Management**: Software packages and dependencies

## Graph Definition

**Graph G = (V, E)** where:
- **V**: Set of vertices (nodes)
- **E**: Set of edges connecting vertices

### Mathematical Representation
- **Vertex Set**: V = {v₁, v₂, v₃, ..., vₙ}
- **Edge Set**: E = {(vᵢ, vⱼ) | vᵢ, vⱼ ∈ V}

## Graph Components

### 1. Vertices (Nodes)
- Individual entities in the graph
- Can store data/information
- Represented as circles or points

### 2. Edges (Links)
- Connections between vertices
- Can be directed or undirected
- May have weights (costs, distances)

```
Example Graph:
    A ---- B
    |      |
    |      |
    C ---- D

Vertices: {A, B, C, D}
Edges: {(A,B), (A,C), (B,D), (C,D)}
```

## Types of Graphs

### 1. Undirected Graph
Edges have no direction - connection is bidirectional.

```
    A ---- B
    |      |
    |      |
    C ---- D

Edge (A,B) means A connects to B AND B connects to A
```

**Example**: Facebook friendships (mutual connections)

### 2. Directed Graph (Digraph)
Edges have direction - connection is unidirectional.

```
    A ----> B
    ^       |
    |       |
    |       v
    C <---- D

A → B, B → D, D → C, C → A
```

**Example**: Twitter following (A follows B doesn't mean B follows A)

### 3. Cyclic Graph
Contains at least one cycle (path that starts and ends at same vertex).

```
Cycle Example:
    A ----> B
    ^       |
    |       |
    |       v
    C <---- D

Cycle: A → B → D → C → A
```

### 4. Acyclic Graph
Contains no cycles.

```
Acyclic Example:
    A ----> B
    |       |
    |       |
    v       v
    C ----> D

No path returns to starting vertex
```

**Special Case**: **DAG (Directed Acyclic Graph)** - Used in task scheduling

### 5. Connected Graph
Every vertex is reachable from every other vertex.

```
Connected:
    A ---- B
    |      |
    |      |
    C ---- D

Path exists between any two vertices
```

### 6. Disconnected Graph
Some vertices are not reachable from others.

```
Disconnected:
    A ---- B    E ---- F
    |      |
    |      |
    C ---- D

Two separate components
```

### 7. Complete Graph
Every vertex is connected to every other vertex.

```
Complete Graph K₄:
    A ---- B
    |\    /|
    | \  / |
    |  \/  |
    |  /\  |
    | /  \ |
    |/    \|
    C ---- D

All possible edges exist
```

**Formula**: For n vertices, complete graph has n(n-1)/2 edges

### 8. Weighted Graph
Edges have associated weights/costs.

```
Weighted Graph:
    A --5-- B
    |       |
    3       2
    |       |
    C --4-- D

Edge weights: (A,B)=5, (A,C)=3, (B,D)=2, (C,D)=4
```

**Example**: Road network with distances

### 9. Unweighted Graph
All edges are considered equal (weight = 1 or unspecified).

```
Unweighted Graph:
    A ---- B
    |      |
    |      |
    C ---- D

All edges have same importance
```

## Graph Representations

### 1. Adjacency Matrix

2D array where matrix[i][j] = 1 if edge exists between vertex i and j.

```
Graph:     A ---- B
           |      |
           |      |
           C ---- D

Adjacency Matrix:
     A  B  C  D
A  [ 0  1  1  0 ]
B  [ 1  0  0  1 ]
C  [ 1  0  0  1 ]
D  [ 0  1  1  0 ]
```

**Advantages**:
- O(1) edge lookup
- Simple implementation

**Disadvantages**:
- O(V²) space complexity
- Inefficient for sparse graphs

### 2. Adjacency List

Array of lists where each index represents a vertex and contains its neighbors.

```
Graph:     A ---- B
           |      |
           |      |
           C ---- D

Adjacency List:
A: [B, C]
B: [A, D]
C: [A, D]
D: [B, C]
```

**Advantages**:
- O(V + E) space complexity
- Efficient for sparse graphs

**Disadvantages**:
- O(V) edge lookup time

### 3. Edge List

Simple list of all edges.

```
Graph:     A ---- B
           |      |
           |      |
           C ---- D

Edge List:
[(A,B), (A,C), (B,D), (C,D)]
```

## Visual Comparison Table

| Graph Type | Example | Edges | Use Case |
|------------|---------|-------|----------|
| **Undirected** | A—B—C | Bidirectional | Social networks |
| **Directed** | A→B→C | Unidirectional | Web pages, dependencies |
| **Weighted** | A—5—B—3—C | Has costs | Shortest path algorithms |
| **Complete** | All connected | n(n-1)/2 edges | Tournament scheduling |
| **Cyclic** | A→B→C→A | Contains loops | Deadlock detection |
| **Acyclic** | A→B→C | No loops | Task scheduling |


## Summary
Graphs are versatile data structures essential for modeling complex relationships in real-world applications. Key takeaways:

### **Core Concepts**
- **Vertices**: Individual entities or nodes
- **Edges**: Connections between vertices
- **Non-linear**: No hierarchical structure like trees

### **Types Summary**
- **Direction**: Directed vs Undirected
- **Cycles**: Cyclic vs Acyclic
- **Connectivity**: Connected vs Disconnected
- **Completeness**: Complete vs Incomplete
- **Weights**: Weighted vs Unweighted


### **Applications**
- Social networks (Facebook, LinkedIn)
- Transportation (Railways, GPS)
- Computer networks and web
- Dependency resolution
- Game development and AI

Understanding graphs is crucial for solving complex problems involving relationships, connectivity, and optimization in computer science and real-world applications.