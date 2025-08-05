# Day 89: Binary Search Tree Problems - Complete Study Guide

## Overview

This comprehensive guide covers four important BST problems:
1. **Lowest Common Ancestor (LCA) in BST** - Finding the common ancestor of two nodes
2. **Print BST Elements in Given Range** - Finding nodes within a specified range
3. **Check for Dead End in BST** - Detecting if BST has dead-end leaf nodes
4. **Find Common Nodes in Two BSTs** - Finding intersection of two BSTs

All solutions leverage BST properties for optimal performance.

---

## Problem 1: Lowest Common Ancestor (LCA) in BST
**Difficulty**: Easy | **GeeksforGeeks**

### Problem Statement
Find the Lowest Common Ancestor of two given nodes in a Binary Search Tree.

### Code Implementation
```cpp
class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
       // Base case
       if(!root)
        return NULL;
        
        // Both nodes in left subtree
        if(root->data > n1->data && root->data > n2->data){
            return LCA(root->left, n1, n2);
        }
        // Both nodes in right subtree
        else if(root->data < n1->data && root->data < n2->data){
            return LCA(root->right, n1, n2);
        }
        // Split point - current root is LCA
        else{
            return root;
        }
    }
};
```

### Algorithm Explanation
1. **Base Case**: If root is NULL, return NULL
2. **Left Subtree**: If both nodes are smaller than root, search left
3. **Right Subtree**: If both nodes are greater than root, search right
4. **Split Point**: If nodes are on different sides, current root is LCA

### Visual Example
```
BST:           20
              /  \
             8    22
            / \     \
           4   12    25
              /  \
             10   14

Find LCA of 10 and 14:
Step 1: At 20 → 10<20 and 14<20 → Go left
Step 2: At 8 → 10>8 and 14>8 → Go right  
Step 3: At 12 → 10<12 and 14>12 → Split! LCA = 12
```

### Dry Run Table
| Step | Current Node | n1=10 | n2=14 | Decision | Action |
|------|--------------|-------|-------|----------|--------|
| 1    | 20          | 10<20 | 14<20 | Both left | Go left |
| 2    | 8           | 10>8  | 14>8  | Both right | Go right |
| 3    | 12          | 10<12 | 14>12 | Split | Return 12 |

### Time & Space Complexity
- **Time**: O(h) where h is height of tree
- **Space**: O(h) for recursion stack

---

## Problem 2: Print BST Elements in Given Range
**Difficulty**: Easy | **GeeksforGeeks**

### Problem Statement
Print all nodes of BST that lie in the given range [low, high].

### Code Implementation
```cpp
int n1, n2;  // Global variables for range
class Solution {
  public:
    void find(Node *root, vector<int>&ans){
        // Base case
        if(!root)
         return;
         
        // All nodes greater than range
        if(root->data > n1 && root->data > n2){
            find(root->left, ans);
        }
        // All nodes smaller than range
        else if(root->data < n1 && root->data < n2){
            find(root->right, ans);
        }
        // Node might be in range or split
        else{
            find(root->left, ans);   // Check left
            ans.push_back(root->data); // Add current
            find(root->right, ans);  // Check right
        }
    }
  
    vector<int> printNearNodes(Node *root, int low, int high) {
         vector<int>ans;
         n1 = low, n2 = high;
         find(root, ans);
         return ans;
    }
};
```

### Algorithm Explanation
1. **Pruning**: Skip subtrees entirely outside range
2. **In-order**: When in range zone, do in-order traversal
3. **Result**: Naturally sorted due to in-order traversal

### Visual Example
```
BST:           10
              /  \
             5    15
            / \   / \
           3   7 12  20

Range: [7, 15]
Traversal path: 10 → 5 → 7 → 10 → 15 → 12
Result: [7, 10, 12, 15]
```

### Step-by-Step Execution
```
Start at 10: 7 ≤ 10 ≤ 15 → Explore both sides
├─ Go left to 5: 5 < 7 → Only go right from 5
│  └─ At 7: 7 in range → Add 7
├─ Add 10 (in range)
└─ Go right to 15: 15 in range → Explore both sides
   └─ At 12: 12 in range → Add 12, then add 15
```

---

## Problem 3: Check for Dead End in BST
**Difficulty**: Medium | **GeeksforGeeks**

### Problem Statement
Check whether a BST contains a dead end. A dead end occurs when a leaf node cannot have any children due to BST constraints.

### Code Implementation
```cpp
class Solution {
  public:
    bool Dead(Node *root, int lower, int upper){
        // Base case - no node
        if(!root) 
         return false;
         
        // Check if leaf node
        if(!root->left && !root->right){
            // Dead end condition: no space for children
            if(root->data - lower == 1 && upper - root->data == 1){
                return true; // Dead end found
            } else {
                return false; // Not a dead end
            }
        }
        
        // Recursively check left and right subtrees
        return Dead(root->left, lower, root->data) || 
               Dead(root->right, root->data, upper);
    }
    
    bool isDeadEnd(Node *root) {
        return Dead(root, 0, INT_MAX);
    }
};
```

### Algorithm Explanation
1. **Range Tracking**: Maintain valid range [lower, upper] for each node
2. **Leaf Check**: For leaf nodes, check if range allows children
3. **Dead End**: When `data - lower == 1` and `upper - data == 1`

### Visual Example
```
BST:        8
           / \
          5   11
         / \    \
        2   7    15
       /         /
      1         13

Check leaf node 1:
- Range: [0, 2]
- data = 1
- lower = 0, upper = 2
- 1 - 0 = 1 ✓ and 2 - 1 = 1 ✓
- Dead End Found!
```

### Dead End Analysis Table
| Leaf Node | Range | Lower Gap | Upper Gap | Dead End? |
|-----------|-------|-----------|-----------|-----------|
| 1         | [0,2] | 1-0=1     | 2-1=1     | ✓ Yes     |
| 7         | [5,8] | 7-5=2     | 8-7=1     | ✗ No      |
| 13        | [11,15] | 13-11=2 | 15-13=2   | ✗ No      |

### Time & Space Complexity
- **Time**: O(n) - visit each node once
- **Space**: O(h) - recursion depth

---
# Find Common Nodes in Two BSTs

## Overview

This algorithm finds all common nodes between two Binary Search Trees (BSTs) using an efficient stack-based approach that performs simultaneous in-order traversal of both trees. The solution returns the common elements in sorted order with O(m + n) time complexity and O(h1 + h2) space complexity, where m and n are the number of nodes and h1, h2 are the heights of the trees.

## Algorithm Explanation

### Core Concept
The algorithm uses two stacks to simulate in-order traversal of both BSTs simultaneously. Since in-order traversal of a BST gives elements in sorted order, we can compare elements from both trees efficiently.

### Line-by-Line Code Analysis

```cpp
class Solution {
  public:
    vector<int> findCommon(Node *r1, Node *r2) {
        vector<int>ans;           // Store common elements
        stack<Node *>s1,s2;       // Stacks for both BSTs
```

**Lines 1-4**: Initialize the result vector and two stacks for traversing both BSTs.

```cpp
        // Phase 1: Initialize stacks with leftmost paths
        while(r1){
            s1.push(r1);
            r1 = r1->left;
        }
        while(r2){
            s2.push(r2);
            r2 = r2->left;
        }
```

**Lines 5-12**: Push all nodes from root to leftmost leaf for both trees. This prepares us to get the smallest elements first.

```cpp
        // Phase 2: Main comparison loop
        while(!s1.empty() && !s2.empty()){
            // Case 1: Equal elements found
            if(s1.top()->data==s2.top()->data){
                ans.push_back(s1.top()->data);
                r1 = s1.top()->right;
                s1.pop();
                r2 = s2.top()->right;
                s2.pop();
            }
```

**Lines 13-21**: When top elements are equal, add to result and move to right subtrees.

```cpp
            // Case 2: s1's top > s2's top
            else if(s1.top()->data > s2.top()->data){
                r2 = s2.top()->right;
                s2.pop();
            }
            // Case 3: s2's top > s1's top
            else{
                r1 = s1.top()->right;
                s1.pop();
            }
```

**Lines 22-29**: When elements are not equal, advance the tree with smaller element.

```cpp
            // Phase 3: Replenish stacks with leftmost paths
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
        }
        return ans;
    }
};
```

**Lines 30-40**: After each comparison, rebuild the leftmost paths for the next iteration.

## Visual Example

Let's trace through an example with two BSTs:

### BST 1:
```
       5
      / \
     3   7
    / \   \
   2   4   8
```

### BST 2:
```
       4
      / \
     2   6
    /   / \
   1   5   7
```

### Step-by-Step Dry Run

#### Initial Setup:
```
BST1 Stack: [5, 3, 2]  (bottom to top)
BST2 Stack: [4, 2, 1]  (bottom to top)
Result: []
```

#### Iteration 1:
```
Compare: s1.top()=2, s2.top()=1
Since 2 > 1, advance BST2
```
**Action**: Pop 1 from s2, move to right (NULL)
```
BST1 Stack: [5, 3, 2]
BST2 Stack: [4, 2]
```

#### Iteration 2:
```
Compare: s1.top()=2, s2.top()=2
Since 2 == 2, found common element!
```
**Action**: Add 2 to result, pop both, move to right subtrees
```
BST1 Stack: [5, 3]
BST2 Stack: [4]
Result: [2]
```

#### Iteration 3:
```
Compare: s1.top()=3, s2.top()=4
Since 3 < 4, advance BST1
```
**Action**: Pop 3, move to right (4), push path to leftmost
```
BST1 Stack: [5, 4]
BST2 Stack: [4]
```

#### Iteration 4:
```
Compare: s1.top()=4, s2.top()=4
Since 4 == 4, found common element!
```
**Action**: Add 4 to result, pop both, move to right subtrees
```
BST1 Stack: [5]
BST2 Stack: [6, 5]  (after pushing path 6->5)
Result: [2, 4]
```

#### Iteration 5:
```
Compare: s1.top()=5, s2.top()=5
Since 5 == 5, found common element!
```
**Action**: Add 5 to result
```
Result: [2, 4, 5]
```

### Complete Traversal Visualization

```
Step | BST1 Stack    | BST2 Stack    | Action           | Result
-----|---------------|---------------|------------------|--------
0    | [5,3,2]       | [4,2,1]       | Initialize       | []
1    | [5,3,2]       | [4,2]         | 2>1, pop s2      | []
2    | [5,3]         | [4]           | 2==2, add 2      | [2]
3    | [5,4]         | [4]           | 3<4, pop s1      | [2]
4    | [5]           | [6,5]         | 4==4, add 4      | [2,4]
5    | [7]           | [6]           | 5==5, add 5      | [2,4,5]
6    | [7,8]         | [7]           | 7<6, impossible  | [2,4,5]
7    | []            | []            | 7==7, add 7      | [2,4,5,7]
```

## Algorithm Flow Diagram

```
┌─────────────────┐
│ Initialize      │
│ Stacks with     │
│ Leftmost Paths  │
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│ Both Stacks     │◄────────────┐
│ Not Empty?      │             │
└────────┬────────┘             │
         │ Yes                  │
         ▼                      │
┌─────────────────┐             │
│ Compare Top     │             │
│ Elements        │             │
└────────┬────────┘             │
         │                      │
    ┌────┴────┐                 │
    │ Equal?  │                 │
    └────┬────┘                 │
         │                      │
    ┌────▼────┐                 │
    │   Yes   │                 │
    └────┬────┘                 │
         │                      │
         ▼                      │
┌─────────────────┐             │
│ Add to Result   │             │
│ Pop Both Stacks │             │
│ Move Right      │             │
└────────┬────────┘             │
         │                      │
         ▼                      │
┌─────────────────┐             │
│ Replenish       │─────────────┘
│ Stacks          │
└─────────────────┘
```

## Example Input and Output

### Input:
```cpp
// BST 1:     5
//           / \
//          3   7
//         / \   \
//        2   4   8

// BST 2:     4
//           / \
//          2   6
//         /   / \
//        1   5   7
```

### Expected Output:
```cpp
[2, 4, 5, 7]
```

## Time and Space Complexity

- **Time Complexity**: O(m + n)
  - Each node is visited exactly once
  - m and n are the number of nodes in BST1 and BST2

- **Space Complexity**: O(h1 + h2)
  - Maximum stack size equals tree heights
  - h1 and h2 are heights of BST1 and BST2

## Key Insights

1. **In-order Traversal**: BST in-order traversal gives sorted sequence
2. **Stack Simulation**: Stacks simulate recursive in-order traversal iteratively
3. **Comparison Strategy**: Always advance the tree with smaller current element
4. **Efficiency**: Avoids storing complete traversals in memory

## Alternative Approaches

### Approach 1: Store and Compare (Less Efficient)
```cpp
// Time: O(m + n), Space: O(m + n)
vector<int> inorder1, inorder2;
// Perform complete inorder traversal of both trees
// Use two pointers to find common elements
```

### Approach 2: Hash Set (Different Trade-offs)
```cpp
// Time: O(m + n), Space: O(m)
unordered_set<int> set1;
// Store all elements of BST1 in hash set
// Traverse BST2 and check membership
```

## Summary

The stack-based approach for finding common nodes in two BSTs is optimal because:

- **Memory Efficient**: Uses O(height) space instead of O(nodes)
- **Single Pass**: Each tree is traversed exactly once
- **Sorted Output**: Returns results in ascending order naturally
- **Early Termination**: Stops as soon as one tree is exhausted

This algorithm elegantly combines the properties of BSTs (sorted in-order traversal) with efficient stack-based iteration to solve the problem optimally.

**Difficulty**: Medium | **GeeksforGeeks**

### Problem Statement
Find all common nodes between two BSTs and return them in sorted order.

### Code Implementation
```cpp
class Solution {
  public:
    vector<int> findCommon(Node *r1, Node *r2) {
        vector<int>ans;
        stack<Node *>s1, s2;
        
        // Initialize stacks with leftmost paths
        while(r1){
            s1.push(r1);
            r1 = r1->left;
        }
        while(r2){
            s2.push(r2);
            r2 = r2->left;
        }
        
        // Main comparison loop
        while(!s1.empty() && !s2.empty()){
            // Both top elements are equal 
            if(s1.top()->data == s2.top()->data){
                ans.push_back(s1.top()->data);
                r1 = s1.top()->right;
                s1.pop();
                r2 = s2.top()->right;
                s2.pop();
            }
            // s1 > s2, advance s2
            else if(s1.top()->data > s2.top()->data){
                r2 = s2.top()->right;
                s2.pop();
            }
            // s2 > s1, advance s1
            else {
                r1 = s1.top()->right;
                s1.pop();
            }
            
            // Replenish stacks with leftmost paths
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
        }
        
        return ans;
    }
};
```

### Detailed Algorithm Flow

#### Phase 1: Stack Initialization
```
BST1:    5           BST2:    4
        / \                  / \
       3   7                2   6
      / \   \              /   / \
     2   4   8            1   5   7

Initial Stacks:
s1: [5, 3, 2] (bottom to top)
s2: [4, 2, 1] (bottom to top)
```

#### Phase 2: Comparison Process
```
Iteration 1: Compare 2 vs 1
- 2 > 1, advance BST2
- s2 becomes [4, 2]

Iteration 2: Compare 2 vs 2  
- Equal! Add 2 to result
- Move to right subtrees
- Result: [2]

Iteration 3: Compare 3 vs 4
- 3 < 4, advance BST1
- Push path to 4: s1 becomes [5, 4]

Iteration 4: Compare 4 vs 4
- Equal! Add 4 to result
- Result: [2, 4]
```

### Complete Execution Table
| Step | s1.top() | s2.top() | Action | Result |
|------|----------|----------|--------|---------|
| 1    | 2        | 1        | 2>1, pop s2 | [] |
| 2    | 2        | 2        | Equal, add 2 | [2] |
| 3    | 3        | 4        | 3<4, pop s1 | [2] |
| 4    | 4        | 4        | Equal, add 4 | [2,4] |
| 5    | 5        | 5        | Equal, add 5 | [2,4,5] |
| 6    | 7        | 7        | Equal, add 7 | [2,4,5,7] |

### Stack State Visualization
```
Step 1:     Step 2:     Step 3:     Step 4:
s1: [5,3,2] s1: [5,3]   s1: [5,4]   s1: [5]
s2: [4,2,1] s2: [4]     s2: [4]     s2: [6,5]
```

---

## Key BST Properties Used

### 1. In-Order Traversal Property
- Left → Root → Right gives sorted sequence
- Used in: Range queries, Common nodes

### 2. Search Property  
- Left subtree < Root < Right subtree
- Used in: LCA, Dead end detection

### 3. Range Constraint Property
- Each node has implicit [min, max] range
- Used in: Dead end detection, Range queries

---

## Complexity Summary

| Problem | Time Complexity | Space Complexity | Key Technique |
|---------|----------------|------------------|---------------|
| LCA in BST | O(h) | O(h) | Recursive descent |
| Range Query | O(h + k) | O(h) | Pruned traversal |
| Dead End | O(n) | O(h) | Range tracking |
| Common Nodes | O(m + n) | O(h1 + h2) | Stack simulation |

Where:
- h = height of tree
- k = number of nodes in range  
- n = total nodes
- m, n = nodes in BST1, BST2
- h1, h2 = heights of BST1, BST2

---

## Practice Tips

### 1. LCA Problems
- Always leverage BST property for O(h) solution
- Avoid generic tree LCA approaches for BST

### 2. Range Queries
- Use pruning to avoid unnecessary subtree visits
- Maintain sorted order with in-order traversal

### 3. Dead End Detection
- Track valid ranges for each node
- Check boundary conditions for leaf nodes

### 4. Two BST Problems
- Use iterative in-order with stacks
- Compare elements from both trees simultaneously

---

## Summary

Day 89 covers essential BST algorithms that demonstrate:
- **Property Utilization**: Leveraging BST ordering for efficiency
- **Range Management**: Tracking valid value ranges
- **Traversal Techniques**: Stack-based iterative approaches
- **Optimization**: Pruning unnecessary computations

These problems form the foundation for advanced BST operations and appear frequently in coding interviews.