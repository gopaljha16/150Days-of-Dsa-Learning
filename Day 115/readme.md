# Graph Algorithms - Topological Sorting Solutions

## Overview

This document contains four graph-based problems that all use **Kahn's Algorithm** (topological sorting using BFS and in-degree) to solve different scenarios:

1. **Alien Dictionary** - Determines the order of characters in an alien language
2. **Prerequisite Tasks** - Checks if all tasks can be completed given prerequisites
3. **Course Schedule** - Returns the order in which courses should be taken
4. **Parallel Courses 3** - Finds minimum time to complete all courses with prerequisites

All solutions use the same core algorithm but apply it to different problem domains.

---

## 1. Alien Dictionary

### Problem Description
Given a list of words from an alien dictionary sorted lexicographically, determine the order of characters in the alien alphabet.

### Code Explanation

```cpp
class Solution {
public:
    string findOrder(vector<string> &words) {
        int N = words.size();  // number of words

        // Step 1: Find all unique characters to determine K
        unordered_set<char> uniqueChars;
        for (string &w : words) {
            for (char c : w) {
                uniqueChars.insert(c);
            }
        }
        int K = uniqueChars.size(); // number of unique characters

        // Step 2: Create adjacency list and in-degree array
        vector<int> adj[26];        // adjacency list for 26 letters
        vector<int> Indeg(26, 0);   // in-degree array

        // Step 3: Build the graph by comparing adjacent words
        for(int i = 0; i < N-1; i++){
            string str1 = words[i], str2 = words[i+1];
            int j = 0, k = 0; 
            bool foundMismatch = false;
            
            // Compare until first mismatch
            while (j < str1.size() && k < str2.size() && str1[j] == str2[k]) {
                j++; k++;
            }
             
            // If mismatch found, create edge str1[j] -> str2[k]
            if (j < str1.size() && k < str2.size()) {
                adj[str1[j] - 'a'].push_back(str2[k] - 'a');
                Indeg[str2[k] - 'a']++;
                foundMismatch = true;
            }

            // Invalid case: str1 is prefix of str2 but longer
            if (!foundMismatch && str1.size() > str2.size()) {
                return "";
            }
        }

        // Step 4: Apply Kahn's algorithm
        queue<int> q;
        for (char c : uniqueChars) {
            if (Indeg[c - 'a'] == 0)
                q.push(c - 'a');
        }
        
        string ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // Add character to result
            char c = 'a' + node;
            ans += c;
            
            // Process all adjacent nodes
            for(int j = 0; j < adj[node].size(); j++){
                Indeg[adj[node][j]]--;
                if(!Indeg[adj[node][j]]) 
                    q.push(adj[node][j]);
            }
        }
        
        // Check if all characters are included (no cycle)
        if (ans.size() < K) return "";
        return ans;
    }
};
```

### Example Input and Output

**Input:** `words = ["wrt", "wrf", "er", "ett", "rftt"]`

**Expected Output:** `"wertf"`

### Step-by-Step Dry Run

1. **Find unique characters:** {w, r, t, f, e} → K = 5

2. **Build graph by comparing adjacent words:**
   - "wrt" vs "wrf": First difference at index 2: 't' → 'f'
   - "wrf" vs "er": First difference at index 0: 'w' → 'e' 
   - "er" vs "ett": First difference at index 1: 'r' → 't'
   - "ett" vs "rftt": First difference at index 0: 'e' → 'r'

3. **Graph edges:** w→e, t→f, r→t, e→r

4. **In-degrees:** w=0, e=1, r=1, t=1, f=1

5. **Kahn's Algorithm:**
   - Queue starts with: [w] (in-degree 0)
   - Process w: result="w", e's in-degree becomes 0, queue=[e]
   - Process e: result="we", r's in-degree becomes 0, queue=[r] 
   - Process r: result="wer", t's in-degree becomes 0, queue=[t]
   - Process t: result="wert", f's in-degree becomes 0, queue=[f]
   - Process f: result="wertf", queue=[]

**Final Result:** "wertf"

### Visual Diagram

```
Graph Structure:
w → e → r → t → f

Kahn's Algorithm Flow:
Step 1: w(0) → queue=[w]
Step 2: e(0) → queue=[e] 
Step 3: r(0) → queue=[r]
Step 4: t(0) → queue=[t]
Step 5: f(0) → queue=[f]
```

---

## 2. Prerequisite Tasks

### Problem Description
Given N tasks and P prerequisites, determine if it's possible to complete all tasks.

### Code Explanation

```cpp
class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        // Step 1: Create adjacency list and in-degree array
        vector<int> adj[N];
        vector<int> Indegree(N, 0);
        
        // Build graph: prerequisite.second → prerequisite.first
        for(int i = 0; i < P; i++){
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            Indegree[prerequisites[i].first]++;
        }
        
        // Step 2: Apply Kahn's algorithm
        queue<int> q;
        int count = 0; // Count of processed tasks
        
        // Find all tasks with no prerequisites
        for(int i = 0; i < N; i++){
            if(!Indegree[i]) 
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++; // Process current task
            
            // Update all dependent tasks
            for(int j = 0; j < adj[node].size(); j++){
                Indegree[adj[node][j]]--; 
                if(!Indegree[adj[node][j]]){
                    q.push(adj[node][j]);
                }
            }
        }
        
        return count == N; // True if all tasks can be completed
    }
};
```

### Example Input and Output

**Input:** `N = 4, prerequisites = {{1,0}, {2,1}, {3,2}}`

**Expected Output:** `true`

### Step-by-Step Dry Run

1. **Build graph:** 0→1, 1→2, 2→3
2. **In-degrees:** [0, 1, 1, 1]
3. **Kahn's Algorithm:**
   - Queue starts with: [0] (in-degree 0)
   - Process 0: count=1, queue=[1]
   - Process 1: count=2, queue=[2]
   - Process 2: count=3, queue=[3]
   - Process 3: count=4, queue=[]

**Result:** count(4) == N(4) → true

---

## 3. Course Schedule

### Problem Description
Return the order in which courses should be taken given prerequisites.

### Code Explanation

```cpp
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>> prerequisites) {
        int P = prerequisites.size();
        
        // Step 1: Build adjacency list and in-degree array
        vector<int> adj[N];
        vector<int> Indegree(N, 0);
        
        // Build graph: prerequisites[i][1] → prerequisites[i][0]
        for(int i = 0; i < P; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            Indegree[prerequisites[i][0]]++;
        }
        
        // Step 2: Apply Kahn's algorithm
        queue<int> q;
        vector<int> ans; // Store the course order
        
        for(int i = 0; i < N; i++){
            if(!Indegree[i]) 
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node); // Add to result
            
            for(int j = 0; j < adj[node].size(); j++){
                Indegree[adj[node][j]]--;
                if(!Indegree[adj[node][j]]){
                    q.push(adj[node][j]);
                }
            }
        }
        
        vector<int> temp;
        return ans.size() == N ? ans : temp; // Return empty if cycle exists
    }
};
```

### Example Input and Output

**Input:** `N = 4, prerequisites = [[1,0], [2,0], [3,1], [3,2]]`

**Expected Output:** `[0, 1, 2, 3]` or `[0, 2, 1, 3]`

---

## 4. Parallel Courses 3

### Problem Description
Find the minimum time to complete all courses where each course has a duration and prerequisites.

### Code Explanation

```cpp
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Step 1: Create adjacency list (1-indexed to 0-indexed)
        vector<vector<int>> adj(n);
        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }

        // Step 2: Calculate in-degrees
        vector<int> Indeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                Indeg[adj[i][j]]++; 
            }
        }

        // Step 3: Apply modified Kahn's algorithm
        queue<int> q;
        vector<int> CourseTime(n, 0); // Earliest completion time for each course

        // Start with courses having no prerequisites
        for (int i = 0; i < n; i++) {
            if (!Indeg[i])
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Process all dependent courses
            for (int j = 0; j < adj[node].size(); j++) {
                Indeg[adj[node][j]]--;

                // Update earliest start time for dependent course
                CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]], 
                                               CourseTime[node] + time[node]);

                if (!Indeg[adj[node][j]])
                    q.push(adj[node][j]);
            }
        }

        // Step 4: Find maximum completion time
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, CourseTime[i] + time[i]);
        }

        return ans;
    }
};
```

### Example Input and Output

**Input:** `n = 3, relations = [[1,3], [2,3]], time = [3,2,5]`

**Expected Output:** `8`

### Step-by-Step Dry Run

1. **Graph:** 0→2, 1→2 (after converting to 0-indexed)
2. **In-degrees:** [0, 0, 2]
3. **Initial CourseTime:** [0, 0, 0]
4. **Kahn's Algorithm:**
   - Queue starts with: [0, 1] (both have in-degree 0)
   - Process 0: CourseTime[2] = max(0, 0+3) = 3, queue=[1]
   - Process 1: CourseTime[2] = max(3, 0+2) = 3, queue=[2]
   - Process 2: queue=[]
5. **Final completion times:** [0+3, 0+2, 3+5] = [3, 2, 8]

**Result:** max(3, 2, 8) = 8

### Visual Diagram

```
Timeline:
Time 0-3: Course 0 (duration 3)
Time 0-2: Course 1 (duration 2)  
Time 3-8: Course 2 (duration 5, starts after courses 0 and 1)

Total time: 8
```

---

## Algorithm Summary

### Kahn's Algorithm (Topological Sort)

All four problems use the same core algorithm:

1. **Build Graph:** Create adjacency list and calculate in-degrees
2. **Initialize Queue:** Add all nodes with in-degree 0
3. **Process Nodes:** 
   - Remove node from queue
   - Process the node (add to result, update times, etc.)
   - Decrease in-degree of all adjacent nodes
   - Add nodes with in-degree 0 to queue
4. **Check Result:** Verify all nodes were processed (no cycles)

### Time Complexity
- **Building Graph:** O(E) where E is number of edges
- **Kahn's Algorithm:** O(V + E) where V is vertices, E is edges
- **Overall:** O(V + E)

### Space Complexity
- **Adjacency List:** O(V + E)
- **Additional Arrays:** O(V)
- **Overall:** O(V + E)

### Key Differences Between Problems

| Problem | Input Format | Output | Special Logic |
|---------|-------------|---------|---------------|
| Alien Dictionary | List of words | Character order string | Compare adjacent words to build edges |
| Prerequisite Tasks | Task pairs | Boolean (possible/not) | Simple cycle detection |
| Course Schedule | Course pairs | Course order array | Same as topological sort |
| Parallel Courses 3 | Course pairs + times | Minimum completion time | Track earliest completion time per course |

All problems demonstrate the versatility of topological sorting in solving different types of dependency and ordering problems.